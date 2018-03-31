// EtherEvent - Easy to use password authenticated network communication between Arduinos and EventGhost Network Event Sender/Receiver and TCPEvents plugins: http://github.com/per1234/EtherEvent
#ifndef EtherEvent_h
#define EtherEvent_h

#include <Arduino.h>

#if defined(ARDUINO_ARCH_SAM) || defined(ARDUINO_ARCH_SAMD)
#include <avr/dtostrf.h>
#endif  //defined(ARDUINO_ARCH_SAM) || defined(ARDUINO_ARCH_SAMD)

#ifdef UIPETHERNET_H
#include <UIPEthernet.h>
#else  //UIPETHERNET_H
#include <Ethernet.h>
#endif  //UIPETHERNET_H

#ifndef ETHEREVENT_NO_AUTHENTICATION
#ifdef ESP8266
//The ESP8266 core library has a file named md5.h, which gets included instead of MD5.h on case insensitive operating systems
#include <MD5Builder.h>
MD5Builder MD5;
#else  //ESP8266
#include <MD5.h>
#endif  //ESP8266
#endif  //ETHEREVENT_NO_AUTHENTICATION


#define ETHEREVENT_DEBUG false  //(false == serial debug output off, true == serial debug output on)The serial debug output will increase memory usage and communication latency so only enable when needed.
#define ETHEREVENT_SERIAL if(ETHEREVENT_DEBUG)Serial  //I have to use a different name for Serial in this file otherwise the debug statement control also affects any other file that includes this file.
#if ETHEREVENT_DEBUG == true
#pragma message "EtherEvent debug output enabled"
#endif  //ETHEREVENT_DEBUG == true


#define ETHEREVENT_MAGIC_WORD "quintessence\n\r"  //word used to trigger the cookie send from the receiver. I had to #define this instead of const because find() didn't like the const
#define ETHEREVENT_ACCEPT_MESSAGE "accept\n"  //authentication success message. I had to #define this instead of const because find() didn't like the const

//these are used as the default password parameter values, which will cause the password set via setPassword() to be used
#define DEFAULT_PASSWORD_STRING "\f"
#define DEFAULT_PASSWORD_CHAR '\f'


// Use of the F() macro with ESP8266 on certain lines is causing the error "__c causes a section type conflict with __c". As a workaround I'm disabling the macro until I can find the cause of the problem.
#ifdef ESP8266
#ifdef F
#undef F
#define F(x) x
#endif  //F
#endif  //ESP8266


#ifndef SIZE_MAX
#define SIZE_MAX (size_t)-1
#endif  //SIZE_MAX


namespace EtherEventNamespace {
const unsigned long debugSerialBaud = 9600;
const char TCPEventsSenderIdentifier[] = "TCPEvents";
const char payloadSeparator[] = "payload ";  //indicates payload
const byte payloadSeparatorLength = strlen(EtherEventNamespace::payloadSeparator);  //includes space at the end
const char payloadWithoutRelease[] = "payload withoutRelease";  //eg sends this every time and EtherEvent filters it out
const byte payloadWithoutReleaseLength = strlen(EtherEventNamespace::payloadWithoutRelease);
const char closeMessage[] = "close\n";  //sender sends this message to the receiver to close the connection
const byte closeMessageLength = strlen(EtherEventNamespace::closeMessage);
}


class EtherEventClass {
  public:
    EtherEventClass() {
      timeout = timeoutDefault;  //set default timeout value, this can be changed by the user via setTimeout()
#ifdef ETHEREVENT_FAST_SEND
      sendDoubleDecimalPlaces = sendDoubleDecimalPlacesDefault;
#else  //ETHEREVENT_FAST_SEND
      payloadSpecified = true;
#endif  //ETHEREVENT_FAST_SEND
    }


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //begin
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    boolean begin(const byte eventLengthMaxInput = 15, const unsigned int payloadLengthMaxInput = 100) {
#if ETHEREVENT_DEBUG == true
      delay(20);  //There needs to be a delay between the calls to serial.begin() in the sketch setup() and here or garbage will be printed to the serial monitor
#endif
      ETHEREVENT_SERIAL.begin(EtherEventNamespace::debugSerialBaud);  //for debugging
      ETHEREVENT_SERIAL.println(F("\n\n\nEtherEvent.begin"));

      eventLengthMax = eventLengthMaxInput;
      payloadLengthMax = payloadLengthMaxInput;
      availableEventSubmessageLengthMax = min(max(max((unsigned int)EtherEventNamespace::payloadWithoutReleaseLength, (unsigned int)(EtherEventNamespace::payloadSeparatorLength + payloadLengthMax + TCPEventsPayloadFormattingLength)), (unsigned int)eventLengthMax), SIZE_MAX - 1);

      receivedEvent = (char*)realloc(receivedEvent, (eventLengthMax + 1) * sizeof(*receivedEvent));
      flushEvent();  //clear buffer - realloc does not zero initialize so the buffer could contain anything
      receivedPayload = (char*)realloc(receivedPayload, (payloadLengthMax + 1) * sizeof(*receivedPayload));
      flushPayload();  //clear buffer - realloc does not zero initialize so the buffer could contain anything
      if (receivedEvent == NULL || receivedPayload == NULL) {
        ETHEREVENT_SERIAL.println(F("memory allocation failed"));
        return false;
      }

      return true;
    }


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //availableEvent - checks for senders, connects, authenticates, reads the event and payload into the buffer and returns the number of bytes of the most recently received event are left in the buffer
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    int availableEvent() {
      return receivedEventLength - readEventLength;
    }


#ifndef ETHEREVENT_NO_AUTHENTICATION
    int availableEvent(EthernetServer &ethernetServer, const __FlashStringHelper* passwordInput) {
      return availableEvent(ethernetServer, false, passwordInput);
    }


    int availableEvent(EthernetServer &ethernetServer, const long cookieInput, const __FlashStringHelper* passwordInput) {
      const byte passwordInputLength = FSHlength(passwordInput);
      char passwordChar[passwordInputLength + 1];
      memcpy_P(passwordChar, passwordInput, passwordInputLength + 1);  //+1 for the null terminator
      return availableEvent(ethernetServer, cookieInput, passwordChar);
    }


    int availableEvent(EthernetServer &ethernetServer, const char passwordInput[]) {
      return availableEvent(ethernetServer, false, passwordInput);
    }
#endif  //ETHEREVENT_NO_AUTHENTICATION

#ifdef ETHEREVENT_NO_AUTHENTICATION
    int availableEvent(EthernetServer &ethernetServer)
#else  //ETHEREVENT_NO_AUTHENTICATION
    int availableEvent(EthernetServer &ethernetServer, const long cookieInput = false, const char passwordInput[] = DEFAULT_PASSWORD_STRING)
#endif  //ETHEREVENT_NO_AUTHENTICATION
    {
      if (receivedEventLength <= readEventLength) {  ///no event buffered
        flushPayload();
        if (EthernetClient ethernetClient = ethernetServer.available() ) {  //connect to the client
          ETHEREVENT_SERIAL.println(F("EtherEvent.availableEvent: connected"));
          ethernetClient.setTimeout(timeout);  //timeout on Stream fumctions. This needs to be called every time in availableEvent() or it resets to the default of 1000ms because a new EthernetClient object is created every call.

#ifndef ETHEREVENT_NO_AUTHENTICATION
          if (passwordInput[0] != 0) {  //do authentication
            boolean authenticationSuccessful = false;
            if (ethernetClient.find((char*)ETHEREVENT_MAGIC_WORD) == true) {  //magic word correct - the (char*) is to get rid of "warning: deprecated conversion from string constant to char*" compile error
              ETHEREVENT_SERIAL.println(F("EtherEvent.availableEvent: magic word received"));

              //create and send cookie
              long cookie;
              if (cookieInput != false) {  //use user-defined cookie
                ETHEREVENT_SERIAL.print(F("EtherEvent.availableEvent: user defined cookie: "));
                cookie = cookieInput;
              }
              else {
                ETHEREVENT_SERIAL.print(F("EtherEvent.availableEvent: automatically generated cookie: "));
                randomSeed(micros());
                cookie = random((((unsigned long) - 1) / 2));  //make random number to use as cookie
              }
              byte currentPasswordLength = passwordLength;
              if (passwordInput[0] != DEFAULT_PASSWORD_CHAR) {  //the user passed a password string in the function call
                currentPasswordLength = strlen(passwordInput);
              }
              char cookiePassword[cookieLengthMax + 1 + currentPasswordLength + 1];  //create buffer of length sufficient for: cookie  +  password separator  +  Password  +  null terminator
#ifdef __ARDUINO_X86__
              sprintf (cookiePassword, "%li", cookie);
#else  //__ARDUINO_X86__
              ltoa(cookie, cookiePassword, HEX);
#endif  //__ARDUINO_X86__
              char cookieWithNewline[cookieLengthMax + 1 + 1];  //create buffer for the cookie string to send so that the newline can be added without interfering with the cookie/password assembly
              strcpy(cookieWithNewline, cookiePassword);
              strcat(cookieWithNewline, "\n");
              ETHEREVENT_SERIAL.print(cookieWithNewline);
              ethernetClient.print(cookieWithNewline);  //send the cookie

              //calculate the hashword
              strcat(cookiePassword, ":");  //create the hashword to compare to the received one
              if (passwordInput[0] == DEFAULT_PASSWORD_CHAR) {
                strcat(cookiePassword, password);  //use the password set via setPassword()
              }
              else {
                strcat(cookiePassword, passwordInput);  //use the password passed in the function call
              }
              ETHEREVENT_SERIAL.print(F("EtherEvent.availableEvent: cookiePassword: "));
              ETHEREVENT_SERIAL.println(cookiePassword);
#ifdef ESP8266
              MD5.begin();
              MD5.add(cookiePassword);
              MD5.calculate();
              char cookiePasswordMD5[33];
              MD5.getChars(cookiePasswordMD5);
#else  //ESP8266
              unsigned char* cookiePasswordHash = MD5::make_hash(cookiePassword);
              char* cookiePasswordMD5 = MD5::make_digest(cookiePasswordHash, 16);
              free(cookiePasswordHash);
#endif  //ESP8266
              ETHEREVENT_SERIAL.print(F("EtherEvent.availableEvent: cookiePasswordMD5: "));
              ETHEREVENT_SERIAL.println(cookiePasswordMD5);

              //verify the received hashword
#ifdef UIPETHERNET_H
              availableWait(ethernetClient);
#endif  //UIPETHERNET_H
              char receivedMD5[maximumReceivedMD5length + 1];
              byte receivedMD5bytesRead = ethernetClient.readBytesUntil('\n', receivedMD5, maximumReceivedMD5length);  //put the incoming data up to the newline into receivedMessage
              receivedMD5[receivedMD5bytesRead] = 0;  //add null terminator
              ETHEREVENT_SERIAL.print(F("EtherEvent.availableEvent: receivedMD5: "));
              ETHEREVENT_SERIAL.println(receivedMD5);
              if (strstr(receivedMD5, cookiePasswordMD5) != NULL) {
                ethernetClient.flush();  //clear the \n or it will cause a null message in the payload/event message read
                ETHEREVENT_SERIAL.println(F("EtherEvent.availableEvent: authentication successful"));

                if (strstr(receivedMD5, EtherEventNamespace::TCPEventsSenderIdentifier) != NULL) {  //TCPEvents prepends "TCPEvents" to the MD5 to identify the plugin
                  ETHEREVENT_SERIAL.println(F("EtherEvent.availableEvent: TCPEvents type sender detected"));
                  ethernetClient.print(" " ETHEREVENT_ACCEPT_MESSAGE);  //The space indicates the server type is TCPEvents. For some reason I can't use F() on this one.
                }
                else {
                  ethernetClient.print(ETHEREVENT_ACCEPT_MESSAGE);  //The space indicates the server type is TCPEvents. For some reason I can't use F() on this one.
                }
                authenticationSuccessful = true;
              }
#ifndef ESP8266
              free(cookiePasswordMD5);
#endif  //ESP8266
            }
            if (!authenticationSuccessful) {
              ETHEREVENT_SERIAL.println(F("EtherEvent.availableEvent: authentication failed"));
              ethernetClient.print(EtherEventNamespace::closeMessage);  //tell the receiver to close
              ethernetClient.stop();
              ETHEREVENT_SERIAL.println(F("EtherEvent.availableEvent: connection closed"));
              return authenticationFailedCode;
            }
          }
#endif  //ETHEREVENT_NO_AUTHENTICATION

          //Read and process the message
          for (byte count = 0; count < 7; count++) {  //Read and process the count stuff is just to make sure it will never go into an infinite loop. It should never need more than five iterations of the for loop to get event and payload
            ETHEREVENT_SERIAL.println(F("EtherEvent.availableEvent: payload/event for loop"));
#ifdef UIPETHERNET_H
            availableWait(ethernetClient);
#endif  //UIPETHERNET_H
            char receivedMessage[availableEventSubmessageLengthMax + 1];  //initialize the buffer to read into
            unsigned int bytesRead = ethernetClient.readBytesUntil(10, receivedMessage, availableEventSubmessageLengthMax + 1);  //put the incoming data up to the newline into receivedMessage
            if (bytesRead > availableEventSubmessageLengthMax) {  //event or payload exceeds max length
              ETHEREVENT_SERIAL.println(F("EtherEvent.availableEvent: event/payload > max length"));
              char findString[] = "\n";  //I had to do this instead of just ethernetClient.find(10) or ethernetClient.find("\n") because that causes a compile error under Arduino IDE 1.6.0 which also doesn't allow const char
              ethernetClient.find(findString);  //Flush up to the newline. I had to do the "\n" instead of just ethernetClient.find(10) because that causes a compile error under Arduino IDE 1.6.0
              bytesRead--;  //so the null terminator will not be written past the end of the array
            }
            ETHEREVENT_SERIAL.print(F("EtherEvent.availableEvent: bytesRead: "));
            ETHEREVENT_SERIAL.println(bytesRead);
            if (bytesRead == 0) {  //with Arduino 1.5 there is a leading char(10) for some reason(maybe flush() doesn't work and it's still left over from the last message?). This will handle null messages
              continue;
            }
            receivedMessage[bytesRead] = 0;  //add a null terminator

            if (strncmp(receivedMessage, EtherEventNamespace::payloadSeparator, EtherEventNamespace::payloadSeparatorLength) == 0) {  //received message is a payload
              ETHEREVENT_SERIAL.println(F("EtherEvent.availableEvent: payload separator received"));
              if (bytesRead > EtherEventNamespace::payloadSeparatorLength) {  //there is a payload

                if (strncmp(receivedMessage, EtherEventNamespace::payloadWithoutRelease, EtherEventNamespace::payloadWithoutReleaseLength) == 0) {  //"withoutRelease" received
                  ETHEREVENT_SERIAL.println(F("EtherEvent.availableEvent: payloadWithoutRelease"));
                  continue;
                }

                ETHEREVENT_SERIAL.print(F("EtherEvent.availableEvent: payload length: "));
                ETHEREVENT_SERIAL.println(bytesRead - EtherEventNamespace::payloadSeparatorLength);
                receivedPayloadLength = min(bytesRead - EtherEventNamespace::payloadSeparatorLength, payloadLengthMax + TCPEventsPayloadFormattingLength);  //make sure the payload will never be longer than the max length
                ETHEREVENT_SERIAL.print(F("EtherEvent.availableEvent: raw payload: "));
                ETHEREVENT_SERIAL.println(receivedMessage);

                //Strip TCPEvents payload formatting. TCPEvents wraps the payload in [''] if the payload field is used in the Send an Event configuration. If the payload contains the character ' then it's wrapped in [""] instead.
                byte payloadOffset = 0;
                if (receivedMessage[EtherEventNamespace::payloadSeparatorLength] == '[' && (receivedMessage[EtherEventNamespace::payloadSeparatorLength + 1] == '\'' || receivedMessage[EtherEventNamespace::payloadSeparatorLength + 1] == '"')) {
                  payloadOffset = TCPEventsPayloadFormattingLength; //skip the first 2 characters of the payload
                  if (receivedMessage[receivedPayloadLength + EtherEventNamespace::payloadSeparatorLength - 1] == ']' && (receivedMessage[receivedPayloadLength + EtherEventNamespace::payloadSeparatorLength - 2] == '\'' || receivedMessage[receivedPayloadLength + EtherEventNamespace::payloadSeparatorLength - 2] == '"')) {
                    receivedPayloadLength -= 2;
                  }
                  receivedPayloadLength -= payloadOffset;
                }
                else {  //no TCPEvents payload formatting is present
                  receivedPayloadLength = min(receivedPayloadLength, payloadLengthMax);
                }

                //put the payload into the buffer
                for (unsigned int payloadCounter = 0; payloadCounter < receivedPayloadLength; payloadCounter++) {
                  receivedPayload[payloadCounter] = receivedMessage[payloadCounter + payloadOffset + EtherEventNamespace::payloadSeparatorLength];
                }
                receivedPayload[receivedPayloadLength] = 0;  //null terminator
                receivedPayloadLength++;  //receivedEventLength and receivedPayloadLength include the null terminator, this way if the user makes a mistake in the buffer length it will be one byte longer than it needs to be instead of one byte shorter
                ETHEREVENT_SERIAL.print(F("EtherEvent.availableEvent: payload: "));
                ETHEREVENT_SERIAL.println(receivedPayload);
              }
              continue;
            }

            else {  //received message is event
              ETHEREVENT_SERIAL.print(F("EtherEvent.availableEvent: event length: "));
              ETHEREVENT_SERIAL.println(bytesRead);
              if (strncmp(receivedMessage, EtherEventNamespace::closeMessage, EtherEventNamespace::closeMessageLength) == 0) {
                ETHEREVENT_SERIAL.println(F("EtherEvent.availableEvent: close received, no event"));
                break;
              }
              strncpy(receivedEvent, receivedMessage, eventLengthMax);
              receivedEventLength = min(bytesRead, (unsigned int)eventLengthMax) + 1;  //length including null terminator
              receivedEvent[receivedEventLength - 1] = 0;  //-1 because it is zero indexed and the receivedEventLength includes the null terminator
              ETHEREVENT_SERIAL.print(F("EtherEvent.availableEvent: event received: "));
              ETHEREVENT_SERIAL.println(receivedEvent);

              //save the sender IP address
#ifdef ethernetclientwithremoteIP_h  //the include guard from the modified EthernetClient.h
              fromIP = ethernetClient.remoteIP();  //Save the IP address of the sender. Requires modified ethernet library
#endif  //ethernetclientwithremoteIP_h

              break;  //exit the payload/event message handler loop
            }
          }
          ethernetClient.print(EtherEventNamespace::closeMessage);  //tell the receiver to close
          ethernetClient.stop();
          ETHEREVENT_SERIAL.println(F("EtherEvent.availableEvent: connection closed"));
        }
      }
      return availableEvent();
    }


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //availablePayload - returns the number of chars in the payload including the null terminator if there is one
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned int availablePayload() {
      if (receivedPayloadLength > readPayloadLength) {
        return receivedPayloadLength - readPayloadLength;
      }
      return false;
    }


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //readEvent
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void readEvent(char eventBuffer[]) {
      for (byte charCounter = readEventLength; charCounter < receivedEventLength; charCounter++) {
        eventBuffer[charCounter - readEventLength] = receivedEvent[charCounter];
      }
      flushEvent();
    }


    char readEvent() {
      if (receivedEventLength > readEventLength + 1) {
        return receivedEvent[readEventLength++];
      }
      flushEvent();
      return 0;
    }


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //readPayload
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void readPayload(char payloadBuffer[]) {
      for (unsigned int charCounter = readPayloadLength; charCounter < receivedPayloadLength; charCounter++) {
        payloadBuffer[charCounter - readPayloadLength] = receivedPayload[charCounter];
      }
      flushPayload();
    }


    char readPayload() {
      if (receivedPayloadLength > readPayloadLength + 1) {
        return receivedPayload[readPayloadLength++];
      }
      flushPayload();
      return 0;
    }


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //senderIP - returns the ip address the current event was sent from. Requires modified ethernet library, thus the preprocesser direcive system
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef ethernetclientwithremoteIP_h  //the include guard from the modified EthernetClient.h
    IPAddress senderIP() {
      return fromIP;
    }
#endif  //ethernetclientwithremoteIP_h


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //flushReceiver - dump the last message received so another one can be received
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void flushReceiver() {
      ETHEREVENT_SERIAL.println(F("EtherEvent.flushReceiver: start"));
      flushEvent();
      flushPayload();
    }


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //send
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef ETHEREVENT_FAST_SEND
    //The reason for all these annoying event/payload conversion functions in ETHEREVENT_FAST_SEND mode is that using the Arduino Print class for conversions (as done in non-fast send mode) leads to (at least with the Ethernet library and likely others) significantly increased send times for some types due to doing the conversion process in multiple steps, each of which is sent as a separate TCP segment (packet).
    //This inefficiency is most dramatic with __FlashStringHelper, where each character is sent individually, but also occurs with negative numbers (the - is sent separately), and float/double (the . and all numbers that follow it are sent separately). It does not occur for char array, String, positive numbers, char.

    //always handle payload not specified for non-ETHEREVENT_FAST_SEND mode
    template <typename target_t, typename event_t>
    boolean send(EthernetClient &ethernetClient, const target_t target, const unsigned int port, const event_t event) {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(no payload argument, non-ETHEREVENT_FAST_SEND)"));
      payloadSpecified = false;  //In non-ETHEREVENT_FAST_SEND mode, send() has no way to know the type of payload so the best way to detect whether a payload was specified is to set a flag based on the function signature, which allows send() to be more efficient due to not needing to handle the non-existent payload.
#ifdef ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, event, "");
#else  //ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, event, "", DEFAULT_PASSWORD_STRING);
#endif  //ETHEREVENT_NO_AUTHENTICATION
    }
#endif  //ETHEREVENT_FAST_SEND


    //preparations for conversion from byte array target to IPAddress
#if __cplusplus <= 199711L
#ifdef ETHEREVENT_FAST_SEND
    //only handle payload not specified for ETHEREVENT_FAST_SEND mode when target is byte array and default template arguments are not supported
    template <typename event_t>
    boolean send(EthernetClient &ethernetClient, const byte target[], const unsigned int port, const event_t event) {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(no payload argument, ETHEREVENT_FAST_SEND, non-C++11)"));
#ifdef ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, event, "");
#else  //ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, event, "", DEFAULT_PASSWORD_STRING);
#endif  //ETHEREVENT_NO_AUTHENTICATION
    }
#endif  //ETHEREVENT_FAST_SEND


#ifndef ETHEREVENT_NO_AUTHENTICATION
    //default template arguments require C++11 so the function signature without password parameter must be defined
    template <typename event_t, typename payload_t>
    boolean send(EthernetClient &ethernetClient, const byte target[], const unsigned int port, const event_t event, const payload_t payload) {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(no password argument)"));
      return send(ethernetClient, target, port, event, payload, DEFAULT_PASSWORD_STRING);
    }
#endif  //ETHEREVENT_NO_AUTHENTICATION


    //convert byte array target to IPAddress (this is used for ETHEREVENT_FAST_SEND and regular modes)
#ifdef ETHEREVENT_NO_AUTHENTICATION
    template <typename event_t, typename payload_t>
    boolean send(EthernetClient &ethernetClient, const byte target[], const unsigned int port, const event_t event, const payload_t payload)
#else  //ETHEREVENT_NO_AUTHENTICATION
    template <typename event_t, typename payload_t, typename passwordInput_t>
    boolean send(EthernetClient &ethernetClient, const byte target[], const unsigned int port, const event_t event, const payload_t payload, const passwordInput_t passwordInput)
#endif  //ETHEREVENT_NO_AUTHENTICATION
#else  //__cplusplus <= 199711L
#ifdef ETHEREVENT_NO_AUTHENTICATION
    template <typename event_t, typename payload_t = const char*>
    boolean send(EthernetClient &ethernetClient, const byte target[], const unsigned int port, const event_t event, const payload_t payload = "")
#else  //ETHEREVENT_NO_AUTHENTICATION
    template <typename event_t, typename payload_t = const char*, typename passwordInput_t = const char*>
    boolean send(EthernetClient &ethernetClient, const byte target[], const unsigned int port, const event_t event, const payload_t payload = "", const passwordInput_t passwordInput = DEFAULT_PASSWORD_STRING)
#endif  //ETHEREVENT_NO_AUTHENTICATION
#endif  //__cplusplus <= 199711L
    {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(byte array target)"));
      const IPAddress targetIP = IPAddress(target[0], target[1], target[2], target[3]);
#ifdef ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, targetIP, port, event, payload);
#else  //ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, targetIP, port, event, payload, passwordInput);
#endif  //ETHEREVENT_NO_AUTHENTICATION
    }


#ifndef ETHEREVENT_NO_AUTHENTICATION
    //convert __FlashStringHelper password to char array (this is used for ETHEREVENT_FAST_SEND and regular modes)
    template <typename event_t, typename payload_t>
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const event_t event, const payload_t payload, const __FlashStringHelper* passwordInput) {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(F() password)"));
      const byte passwordInputLength = FSHlength(passwordInput);
      char passwordInputChar[passwordInputLength + 1];
      memcpy_P(passwordInputChar, passwordInput, passwordInputLength + 1);  //+1 for the null terminator
      return send(ethernetClient, target, port, event, payload, passwordInputChar);
    }
#endif  //ETHEREVENT_NO_AUTHENTICATION


#ifdef ETHEREVENT_FAST_SEND
    //payload conversions

    //required to avoid "ISO C++ says that these are ambiguous, even though the worst conversion for the first is better than the worst conversion for the second" warning
#ifdef ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const char event[], char payload[])
#else  //ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const char event[], char payload[], const char passwordInput[] = DEFAULT_PASSWORD_STRING)
#endif  //ETHEREVENT_NO_AUTHENTICATION
    {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(char array payload)"));
#ifdef ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, event, (const char*)payload);
#else  //ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, event, (const char*)payload, passwordInput);
#endif  //ETHEREVENT_NO_AUTHENTICATION
    }


#ifdef ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const char event[], const char payload[]) {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(const char array payload)"));
      if (payload[0] == 0) {
        //don't wrap an empty payload
        return sendStrings(ethernetClient, target, port, event);
      }
      return wrapPayload(ethernetClient, target, port, event, payload, strlen(payload), true);
    }
#endif  //ETHEREVENT_NO_AUTHENTICATION


#ifdef ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const char event[], const int8_t payload)
#else  //ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const char event[], const int8_t payload, const char passwordInput[] = DEFAULT_PASSWORD_STRING)
#endif  //ETHEREVENT_NO_AUTHENTICATION
    {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(int8_t payload)"));
#ifdef ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, event, (const int)payload);
#else  //ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, event, (const int)payload, passwordInput);
#endif  //ETHEREVENT_NO_AUTHENTICATION
    }


#ifdef ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const char event[], const byte payload)
#else  //ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const char event[], const byte payload, const char passwordInput[] = DEFAULT_PASSWORD_STRING)
#endif  //ETHEREVENT_NO_AUTHENTICATION
    {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(byte payload)"));
#ifdef ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, event, (const unsigned int)payload);
#else  //ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, event, (const unsigned int)payload, passwordInput);
#endif  //ETHEREVENT_NO_AUTHENTICATION
    }


#ifdef ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const char event[], const int payload)
#else  //ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const char event[], const int payload, const char passwordInput[] = DEFAULT_PASSWORD_STRING)
#endif  //ETHEREVENT_NO_AUTHENTICATION
    {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(int payload)"));
      char payloadChar[intLengthMax + 1];
#ifdef __ARDUINO_X86__
      sprintf (payloadChar, "%i", payload);
#else  //__ARDUINO_X86__
      itoa(payload, payloadChar, 10);
#endif  //__ARDUINO_X86__
#ifdef ETHEREVENT_NO_AUTHENTICATION
      return wrapPayload(ethernetClient, target, port, event, payloadChar, intLengthMax, false);
#else  //ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, event, (const char*)payloadChar, passwordInput);
#endif  //ETHEREVENT_NO_AUTHENTICATION
    }


#ifdef ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const char event[], const unsigned int payload)
#else  //ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const char event[], const unsigned int payload, const char passwordInput[] = DEFAULT_PASSWORD_STRING)
#endif  //ETHEREVENT_NO_AUTHENTICATION
    {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(unsigned int payload)"));
      char payloadChar[unsignedIntLengthMax + 1];
#ifdef __ARDUINO_X86__
      sprintf (payloadChar, "%u", payload);
#else  //__ARDUINO_X86__
      utoa(payload, payloadChar, 10);
#endif  //__ARDUINO_X86__
#ifdef ETHEREVENT_NO_AUTHENTICATION
      return wrapPayload(ethernetClient, target, port, event, payloadChar, unsignedIntLengthMax, false);
#else  //ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, event, (const char*)payloadChar, passwordInput);
#endif  //ETHEREVENT_NO_AUTHENTICATION
    }


#ifdef ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const char event[], const long payload)
#else  //ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const char event[], const long payload, const char passwordInput[] = DEFAULT_PASSWORD_STRING)
#endif  //ETHEREVENT_NO_AUTHENTICATION
    {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(long payload)"));
      char payloadChar[longLengthMax + 1];
#ifdef __ARDUINO_X86__
      sprintf (payloadChar, "%li", payload);
#else  //__ARDUINO_X86__
      ltoa(payload, payloadChar, 10);
#endif  //__ARDUINO_X86__
#ifdef ETHEREVENT_NO_AUTHENTICATION
      return wrapPayload(ethernetClient, target, port, event, payloadChar, longLengthMax, false);
#else  //ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, event, (const char*)payloadChar, passwordInput);
#endif  //ETHEREVENT_NO_AUTHENTICATION
    }


#ifdef ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const char event[], const unsigned long payload)
#else  //ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const char event[], const unsigned long payload, const char passwordInput[] = DEFAULT_PASSWORD_STRING)
#endif  //ETHEREVENT_NO_AUTHENTICATION
    {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(unsigned long payload)"));
      char payloadChar[unsignedLongLengthMax + 1];
#ifdef __ARDUINO_X86__
      sprintf (payloadChar, "%lu", payload);
#else  //__ARDUINO_X86__
      ultoa(payload, payloadChar, 10);
#endif  //__ARDUINO_X86__
#ifdef ETHEREVENT_NO_AUTHENTICATION
      return wrapPayload(ethernetClient, target, port, event, payloadChar, unsignedLongLengthMax, false);
#else  //ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, event, (const char*)payloadChar, passwordInput);
#endif  //ETHEREVENT_NO_AUTHENTICATION
    }


#ifdef ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const char event[], const char payload)
#else  //ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const char event[], const char payload, const char passwordInput[] = DEFAULT_PASSWORD_STRING)
#endif  //ETHEREVENT_NO_AUTHENTICATION
    {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(char payload)"));
      const char payloadChar[] = {payload, 0};
#ifdef ETHEREVENT_NO_AUTHENTICATION
      return wrapPayload(ethernetClient, target, port, event, payloadChar, 1, true);
#else  //ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, event, (const char*)payloadChar, passwordInput);
#endif  //ETHEREVENT_NO_AUTHENTICATION
    }


#ifdef ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const char event[], const __FlashStringHelper* payload)
#else  //ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const char event[], const __FlashStringHelper* payload, const char passwordInput[] = DEFAULT_PASSWORD_STRING)
#endif  //ETHEREVENT_NO_AUTHENTICATION
    {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(__FlashStringHelper payload)"));
      const unsigned int payloadLength = FSHlength(payload);
      char payloadChar[payloadLength + 1];
      memcpy_P(payloadChar, payload, payloadLength + 1);  //+1 for the null terminator
#ifdef ETHEREVENT_NO_AUTHENTICATION
      return wrapPayload(ethernetClient, target, port, event, payloadChar, payloadLength, true);
#else  //ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, event, (const char*)payloadChar, passwordInput);
#endif  //ETHEREVENT_NO_AUTHENTICATION
    }


#ifdef ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const char event[], const String &payload)
#else  //ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const char event[], const String &payload, const char passwordInput[] = DEFAULT_PASSWORD_STRING)
#endif  //ETHEREVENT_NO_AUTHENTICATION
    {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(String payload)"));
#ifdef __ARDUINO_X86__
      //x86 boards don't have c_str()
      const byte payloadLength = payload.length();
      char payloadChar[payloadLength + 1];
      for (byte counter = 0; counter < payloadLength; counter++) {
        payloadChar[counter] = payload[counter];
      }
      payloadChar[payloadLength] = 0;
#ifdef ETHEREVENT_NO_AUTHENTICATION
      return wrapPayload(ethernetClient, target, port, event, payloadChar, payloadLength, true);
#else  //ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, event, (const char*)payloadChar, passwordInput);
#endif  //ETHEREVENT_NO_AUTHENTICATION
#else  //__ARDUINO_X86__
#ifdef ETHEREVENT_NO_AUTHENTICATION
      return wrapPayload(ethernetClient, target, port, event, payload.c_str(), payload.length(), true);
#else  //ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, event, payload.c_str(), passwordInput);
#endif  //ETHEREVENT_NO_AUTHENTICATION
#endif  //__ARDUINO_X86__
    }


#ifdef ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const char event[], const IPAddress &payload)
#else  //ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const char event[], const IPAddress &payload, const char passwordInput[] = DEFAULT_PASSWORD_STRING)
#endif  //ETHEREVENT_NO_AUTHENTICATION
    {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(IPAddress payload)"));
      char payloadChar[IPAddressLengthMax + 1];
      IPtoa(payload, payloadChar);
#ifdef ETHEREVENT_NO_AUTHENTICATION
      return wrapPayload(ethernetClient, target, port, event, payloadChar, IPAddressLengthMax, false);
#else  //ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, event, (const char*)payloadChar, passwordInput);
#endif  //ETHEREVENT_NO_AUTHENTICATION
    }


#ifdef ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const char event[], const float payload)
#else  //ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const char event[], const float payload, const char passwordInput[] = DEFAULT_PASSWORD_STRING)
#endif  //ETHEREVENT_NO_AUTHENTICATION
    {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(float payload)"));
#ifdef ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, event, (const double)payload);
#else  //ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, event, (const double)payload, passwordInput);
#endif  //ETHEREVENT_NO_AUTHENTICATION
    }


#ifdef ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const char event[], const double payload)
#else  //ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const char event[], const double payload, const char passwordInput[] = DEFAULT_PASSWORD_STRING)
#endif  //ETHEREVENT_NO_AUTHENTICATION
    {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(double payload)"));
      const byte payloadLength = doubleIntegerLengthMax + 1 + sendDoubleDecimalPlaces;
      char payloadChar[payloadLength + 1];  //max integer length + decimal point + decimal places setting + null terminator
#ifdef __ARDUINO_X86__
      sprintf (payloadChar, "%.*f", sendDoubleDecimalPlaces, payload);
#else  //__ARDUINO_X86__
      dtostrf(payload, sendDoubleDecimalPlaces + 2, sendDoubleDecimalPlaces, payloadChar);
#endif  //__ARDUINO_X86__
#ifdef ETHEREVENT_NO_AUTHENTICATION
      return wrapPayload(ethernetClient, target, port, event, payloadChar, payloadLength, false);
#else  //ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, event, (const char*)payloadChar, passwordInput);
#endif  //ETHEREVENT_NO_AUTHENTICATION
    }


#if defined(ETHEREVENT_NO_AUTHENTICATION)
    boolean wrapPayload(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const char event[], const char payload[], const unsigned int bufferLength, const bool checkForSingleQuote) {
      char payloadWrapped[payloadWrapperLength + bufferLength + 1];
      char payloadWrapperQuote[] = "'";  //default quote character

      //if the payload string contains a ' then it must be wrapped in [""] instead of the default ['']
      if (checkForSingleQuote == true && strchr(payload, '\'') != NULL) {
        payloadWrapperQuote[0] = '"';
      }

      payloadWrapped[0] = '[';
      payloadWrapped[1] = payloadWrapperQuote[0];
      payloadWrapped[2] = 0; //so strcat() knows where to start
      strcat(payloadWrapped, payload);
      strcat(payloadWrapped, payloadWrapperQuote);
      strcat(payloadWrapped, "]\n");

      return sendStrings(ethernetClient, target, port, event, payloadWrapped);
    }
#endif  //defined(ETHEREVENT_NO_AUTHENTICATION)


    //event conversions

    template <typename event_t>
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const event_t event) {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(no payload)"));
      return send(ethernetClient, target, port, event, "");
    }


    template <typename payload_t>
#ifdef ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const int8_t event, const payload_t payload)
#else  //ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const int8_t event, const payload_t payload, const char passwordInput[] = DEFAULT_PASSWORD_STRING)
#endif  //ETHEREVENT_NO_AUTHENTICATION
    {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(int8_t event)"));
#ifdef ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, (const int)event, payload);
#else  //ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, (const int)event, payload, passwordInput);
#endif  //ETHEREVENT_NO_AUTHENTICATION
    }


    template <typename payload_t>
#ifdef ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const byte event, const payload_t payload)
#else  //ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const byte event, const payload_t payload, const char passwordInput[] = DEFAULT_PASSWORD_STRING)
#endif  //ETHEREVENT_NO_AUTHENTICATION
    {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(byte event)"));
#ifdef ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, (const unsigned int)event, payload);
#else  //ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, (const unsigned int)event, payload, passwordInput);
#endif  //ETHEREVENT_NO_AUTHENTICATION
    }


    template <typename payload_t>
#ifdef ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const int event, const payload_t payload)
#else  //ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const int event, const payload_t payload, const char passwordInput[] = DEFAULT_PASSWORD_STRING)
#endif  //ETHEREVENT_NO_AUTHENTICATION
    {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(int event)"));
      char eventChar[intLengthMax + 1];
#ifdef __ARDUINO_X86__
      sprintf (eventChar, "%i", event);
#else  //__ARDUINO_X86__
      itoa(event, eventChar, 10);
#endif  //__ARDUINO_X86__
#ifdef ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, (const char*)eventChar, payload);
#else  //ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, (const char*)eventChar, payload, passwordInput);
#endif  //ETHEREVENT_NO_AUTHENTICATION
    }


    template <typename payload_t>
#ifdef ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const unsigned int event, const payload_t payload)
#else  //ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const unsigned int event, const payload_t payload, const char passwordInput[] = DEFAULT_PASSWORD_STRING)
#endif  //ETHEREVENT_NO_AUTHENTICATION
    {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(unsigned int event)"));
      char eventChar[unsignedIntLengthMax + 1];
#ifdef __ARDUINO_X86__
      sprintf (eventChar, "%u", event);
#else  //__ARDUINO_X86__
      utoa(event, eventChar, 10);
#endif  //__ARDUINO_X86__
#ifdef ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, (const char*)eventChar, payload);
#else  //ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, (const char*)eventChar, payload, passwordInput);
#endif  //ETHEREVENT_NO_AUTHENTICATION
    }


    template <typename payload_t>
#ifdef ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const long event, const payload_t payload)
#else  //ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const long event, const payload_t payload, const char passwordInput[] = DEFAULT_PASSWORD_STRING)
#endif  //ETHEREVENT_NO_AUTHENTICATION
    {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(long event)"));
      char eventChar[longLengthMax + 1];
#ifdef __ARDUINO_X86__
      sprintf (eventChar, "%li", event);
#else  //__ARDUINO_X86__
      ltoa(event, eventChar, 10);
#endif  //__ARDUINO_X86__
#ifdef ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, (const char*)eventChar, payload);
#else  //ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, (const char*)eventChar, payload, passwordInput);
#endif  //ETHEREVENT_NO_AUTHENTICATION
    }


    template <typename payload_t>
#ifdef ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const unsigned long event, const payload_t payload)
#else  //ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const unsigned long event, const payload_t payload, const char passwordInput[] = DEFAULT_PASSWORD_STRING)
#endif  //ETHEREVENT_NO_AUTHENTICATION
    {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(unsigned long event)"));
      char eventChar[unsignedLongLengthMax + 1];
#ifdef __ARDUINO_X86__
      sprintf (eventChar, "%lu", event);
#else  //__ARDUINO_X86__
      ultoa(event, eventChar, 10);
#endif  //__ARDUINO_X86__
#ifdef ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, (const char*)eventChar, payload);
#else  //ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, (const char*)eventChar, payload, passwordInput);
#endif  //ETHEREVENT_NO_AUTHENTICATION
    }


    template <typename payload_t>
#ifdef ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const char event, const payload_t payload)
#else  //ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const char event, const payload_t payload, const char passwordInput[] = DEFAULT_PASSWORD_STRING)
#endif  //ETHEREVENT_NO_AUTHENTICATION
    {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(char event)"));
      const char eventChar[] = {event, 0};
#ifdef ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, (const char*)eventChar, payload);
#else  //ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, (const char*)eventChar, payload, passwordInput);
#endif  //ETHEREVENT_NO_AUTHENTICATION
    }


    template <typename payload_t>
#ifdef ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const __FlashStringHelper* event, const payload_t payload)
#else  //ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const __FlashStringHelper* event, const payload_t payload, const char passwordInput[] = DEFAULT_PASSWORD_STRING)
#endif  //ETHEREVENT_NO_AUTHENTICATION
    {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(__FlashStringHelper event)"));
      const byte eventLength = FSHlength(event);
      char eventChar[eventLength + 1];
      memcpy_P(eventChar, event, eventLength + 1);  //+1 for the null terminator
#ifdef ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, (const char*)eventChar, payload);
#else  //ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, (const char*)eventChar, payload, passwordInput);
#endif  //ETHEREVENT_NO_AUTHENTICATION
    }


    template <typename payload_t>
#ifdef ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const String &event, const payload_t payload)
#else  //ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const String &event, const payload_t payload, const char passwordInput[] = DEFAULT_PASSWORD_STRING)
#endif  //ETHEREVENT_NO_AUTHENTICATION
    {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(String event)"));
#ifdef __ARDUINO_X86__
      //x86 boards don't have c_str()
      const byte stringLength = event.length();
      char eventChar[stringLength + 1];
      for (byte counter = 0; counter < stringLength; counter++) {
        eventChar[counter] = event[counter];
      }
      eventChar[stringLength] = 0;
#ifdef ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, (const char*)eventChar, payload);
#else  //ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, (const char*)eventChar, payload, passwordInput);
#endif  //ETHEREVENT_NO_AUTHENTICATION
#else  //__ARDUINO_X86__
#ifdef ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, (const char*)event.c_str(), payload);
#else  //ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, (const char*)event.c_str(), payload, passwordInput);
#endif  //ETHEREVENT_NO_AUTHENTICATION
#endif  //__ARDUINO_X86__
    }


    template <typename payload_t>
#ifdef ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const IPAddress &event, const payload_t payload)
#else  //ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const IPAddress &event, const payload_t payload, const char passwordInput[] = DEFAULT_PASSWORD_STRING)
#endif  //ETHEREVENT_NO_AUTHENTICATION
    {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(IPAddress event)"));
      char eventChar[IPAddressLengthMax + 1];
      IPtoa(event, eventChar);
#ifdef ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, (const char*)eventChar, payload);
#else  //ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, (const char*)eventChar, payload, passwordInput);
#endif  //ETHEREVENT_NO_AUTHENTICATION
    }


    template <typename payload_t>
#ifdef ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const double event, const payload_t payload)
#else  //ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const double event, const payload_t payload, const char passwordInput[] = DEFAULT_PASSWORD_STRING)
#endif  //ETHEREVENT_NO_AUTHENTICATION
    {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(double event)"));
      char eventChar[doubleIntegerLengthMax + 1 + sendDoubleDecimalPlaces + 1];  //max integer length + decimal point + decimal places setting + null terminator
#ifdef __ARDUINO_X86__
      sprintf (eventChar, "%.*f", sendDoubleDecimalPlaces, event);
#else  //__ARDUINO_X86__
      dtostrf(event, sendDoubleDecimalPlaces + 2, sendDoubleDecimalPlaces, eventChar);
#endif  //__ARDUINO_X86__
#ifdef ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, (const char*)eventChar, payload);
#else  //ETHEREVENT_NO_AUTHENTICATION
      return send(ethernetClient, target, port, (const char*)eventChar, payload, passwordInput);
#endif  //ETHEREVENT_NO_AUTHENTICATION
    }


#ifdef ETHEREVENT_NO_AUTHENTICATION
    boolean sendStrings(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const char event[], const char payload[] = "")
#else  //ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const char event[], const char payload[] = "", const char passwordInput[] = DEFAULT_PASSWORD_STRING)
#endif  //ETHEREVENT_NO_AUTHENTICATION
#else  //ETHEREVENT_FAST_SEND
    //payload will always be defined in non-ETHEREVENT_FAST_SEND mode so the default value does not need to be specified
    template <typename event_t, typename payload_t>
#ifdef ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const event_t event, const payload_t payload)
#else  //ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const event_t event, const payload_t payload, const char passwordInput[] = DEFAULT_PASSWORD_STRING)
#endif  //ETHEREVENT_NO_AUTHENTICATION
#endif //ETHEREVENT_FAST_SEND
    {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send: attempting connection"));
      ETHEREVENT_SERIAL.print(F("EtherEvent.send: target: "));
      ETHEREVENT_SERIAL.println(target);
      ETHEREVENT_SERIAL.print(F("EtherEvent.send: port: "));
      ETHEREVENT_SERIAL.println(port);
      ETHEREVENT_SERIAL.print(F("EtherEvent.send: event: "));
      ETHEREVENT_SERIAL.println(event);
      ETHEREVENT_SERIAL.print(F("EtherEvent.send: payload: "));
      ETHEREVENT_SERIAL.println(payload);

      if (!ethernetClient.connect(target, port)) {  //connected to receiver
        ETHEREVENT_SERIAL.println(F("EtherEvent.send: connection failed"));
        return false;
      }

#ifndef ETHEREVENT_NO_AUTHENTICATION
      if (passwordInput[0] != 0) {  //do authentication
        ethernetClient.setTimeout(timeout);  //Timeout on Stream functions. I only have to set it once here for the send() timeout but I can't set it in begin() because ethernetClient isn't passed to that function there so it's most efficient to just set it here every time
        ETHEREVENT_SERIAL.println(F("EtherEvent.send: connected, sending magic word"));
        ethernetClient.print(ETHEREVENT_MAGIC_WORD);  //send the magic word to the receiver so it will send the cookie

        byte currentPasswordLength = passwordLength;
        if (passwordInput[0] != DEFAULT_PASSWORD_CHAR) {  //the user passed a password string in the function call
          currentPasswordLength = strlen(passwordInput);
        }
        char cookiePassword[cookieLengthMax + 1 + currentPasswordLength + 1];  //cookie, password separator(:), password, null terminator
        boolean authenticationSuccessful = false;
#ifdef UIPETHERNET_H
        availableWait(ethernetClient);
#endif  //UIPETHERNET_H
        if (byte bytesRead = ethernetClient.readBytesUntil(10, cookiePassword, cookieLengthMax)) {  //get the cookie
          cookiePassword[bytesRead] = 0;
          strcat(cookiePassword, ":");  //add the password separator to the cookie
          if (passwordInput[0] != DEFAULT_PASSWORD_CHAR) {
            strcat(cookiePassword, passwordInput);  //add the password string supplied in the function call to the cookie
          }
          else {
            strcat(cookiePassword, password);  //add the password set via setPassword() to the cookie
          }
          ETHEREVENT_SERIAL.print(F("EtherEvent.send: cookiePassword: "));
          ETHEREVENT_SERIAL.println(cookiePassword);
#ifdef ESP8266
          MD5.begin();
          MD5.add(cookiePassword);
          MD5.calculate();
          char cookiePasswordMD5[33];
          MD5.getChars(cookiePasswordMD5);
#else  //ESP8266
          unsigned char* cookiePasswordHash = MD5::make_hash(cookiePassword);
          char* cookiePasswordMD5 = MD5::make_digest(cookiePasswordHash, 16);
          free(cookiePasswordHash);
#endif  //ESP8266
          ETHEREVENT_SERIAL.print(F("EtherEvent.send: hashWordMD5: "));
          ETHEREVENT_SERIAL.println(cookiePasswordMD5);
          ethernetClient.print(cookiePasswordMD5);  //send the MD5 of the hashword
          ethernetClient.write(10);  //newline
#ifndef ESP8266
          free(cookiePasswordMD5);
#endif  //ESP8266

          if (ethernetClient.find((char*)ETHEREVENT_ACCEPT_MESSAGE) == true) {  //authentication successful - the (char*) thing is to get rid of the "warning: deprecated conversion from string constant to ‘char*’" compiler warning
            authenticationSuccessful = true;
          }
        }
        if (!authenticationSuccessful) {
          ETHEREVENT_SERIAL.println(F("EtherEvent.send: authentication failed"));
          ethernetClient.print(EtherEventNamespace::closeMessage);  //tell the receiver to close
          ethernetClient.stop();
          ETHEREVENT_SERIAL.println(F("EtherEvent.send: connection closed"));
          return false;
        }
      }
#endif  //ETHEREVENT_NO_AUTHENTICATION
#ifndef ETHEREVENT_FAST_SEND
      if (payloadSpecified == true)  //check if there is a payload
#else  //ETHEREVENT_FAST_SEND
      if (payload[0] != 0)  //check if there is a payload
#endif  //ETHEREVENT_FAST_SEND
      {
        ethernetClient.print(EtherEventNamespace::payloadSeparator);
        //the payload needs to be wrapped here if either in ETHEREVENT_NO_AUTHENTICATION, ETHEREVENT_FAST_SEND mode or if password[0]==0 (per-send unauthenticated mode)
        //this was already done in the payload conversion overloads of send() if in unauthenticated, fast send mode
        //The payload must be wrapped with [''] in unauthenticated mode because otherwise TCPEvents attempts to evaluate the payload as a python expression because the servertype is assumed to be TCPEvents in unauthenticated mode.
        //EtherEvent.availableEvent() will strip the wrapper characters from the payload.
#if !defined(ETHEREVENT_NO_AUTHENTICATION)
        if (passwordInput[0] == 0) {  //authentication disabled for this send
          // wrap the payload if in per-event unathenticated mode
          ETHEREVENT_SERIAL.println(F("EtherEvent.send: authentication disabled on a per-event basis"));
          ethernetClient.print("['");
          ethernetClient.print(payload);
          ethernetClient.print("']\n");
        }
        else {
          //don't wrap the payload in authenticated mode
          ethernetClient.print(payload);
          ethernetClient.write('\n');
        }
#elif defined(ETHEREVENT_NO_AUTHENTICATION) && !defined(ETHEREVENT_FAST_SEND)
        //since not in ETHEREVENT_FAST_SEND mode, the payload was not already wrapped so it must be done here
        ethernetClient.print("['");
        ethernetClient.print(payload);
        ethernetClient.print("']\n");
#else //!defined(ETHEREVENT_NO_AUTHENTICATION)
        //payload was already wrapped during the ETHEREVENT_FAST_SEND mode payload conversion process
        ethernetClient.print(payload);
#endif  //!defined(ETHEREVENT_NO_AUTHENTICATION)
        ETHEREVENT_SERIAL.println(F("EtherEvent.send: payload sent"));
      }
#ifndef ETHEREVENT_FAST_SEND
      payloadSpecified = true; //reset value of payloadSpecified for the next send()
#endif  //ETHEREVENT_FAST_SEND
      ethernetClient.print(event);  //transmit event
      ethernetClient.write(10);  //newline
      ETHEREVENT_SERIAL.println(F("EtherEvent.send: event sent"));

      ethernetClient.print(EtherEventNamespace::closeMessage);  //tell the receiver to close
      ethernetClient.stop();
      ETHEREVENT_SERIAL.println(F("EtherEvent.send: connection closed"));
      return true;
    }


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //setTimeout
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void setTimeout(const unsigned int timeoutInput) {
      timeout = timeoutInput;
    }


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //getTimeout
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned int getTimeout() {
      return timeout;
    }


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //setPassword
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef ETHEREVENT_NO_AUTHENTICATION
    boolean setPassword(const char passwordInput[]) {
      ETHEREVENT_SERIAL.println(F("EtherEvent.setPassword(char)"));
      passwordLength = strlen(passwordInput);
      password = (char*)realloc(password, (passwordLength + 1) * sizeof(*password));  //allocate memory for the password
      strcpy(password, passwordInput);  //store the password
      if (password == NULL) {
        ETHEREVENT_SERIAL.println(F("EtherEvent.setPassword: memory allocation failed"));
        return false;
      }
      return true;
    }


    boolean setPassword(const __FlashStringHelper * passwordInput) {
      ETHEREVENT_SERIAL.println(F("EtherEvent.setPassword(F())"));
      passwordLength = FSHlength(passwordInput);
      password = (char*)realloc(password, (passwordLength + 1) * sizeof(*password));  //allocate memory for the password
      if (password == NULL) {
        ETHEREVENT_SERIAL.println(F("EtherEvent.setPassword: memory allocation failed"));
        return false;
      }
      memcpy_P(password, passwordInput, passwordLength + 1);  //+1 for the null terminator
      return true;
    }
#endif  //ETHEREVENT_NO_AUTHENTICATION


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //setSendDoubleDecimalPlaces
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef ETHEREVENT_FAST_SEND
    void setSendDoubleDecimalPlaces(const byte decimalPlaces) {
      ETHEREVENT_SERIAL.println(F("EtherEvent.setSendDoubleDecimalPlaces"));
      sendDoubleDecimalPlaces = decimalPlaces;
    }
#endif  //ETHEREVENT_FAST_SEND


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //IPtoa - convert IPAddress to char array and put it in the passed buffer
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void IPtoa(const IPAddress & IP, char IPcharBuffer[]) {
#ifdef __ARDUINO_X86__
      sprintf (IPcharBuffer, "%u", IP[0]);
#else  //__ARDUINO_X86__
      utoa(IP[0], IPcharBuffer, 10);  //convert the first octet
#endif  //__ARDUINO_X86__
      for (byte octetCount = 1; octetCount < 4; octetCount++) {  //convert the other 3 octets
        strcat(IPcharBuffer, ".");
        char octetChar[3 + 1];  //3 digit byte + null terminator
#ifdef __ARDUINO_X86__
        sprintf (octetChar, "%u", IP[octetCount]);
#else  //__ARDUINO_X86__
        utoa(IP[octetCount], octetChar, 10);  //convert the octet
#endif  //__ARDUINO_X86__
        strcat(IPcharBuffer, octetChar);
      }
    }


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //FSHlength - determine length of __FlashStringHelper
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned int FSHlength(const __FlashStringHelper * FSHinput) {
      PGM_P FSHinputPointer = reinterpret_cast<PGM_P>(FSHinput);
      unsigned int stringLength = 0;
      while (pgm_read_byte(FSHinputPointer++)) {
        stringLength++;
      }
      return stringLength;
    }


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //private
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
  private:
    //used for the FASTSEND char array conversions
#ifdef ETHEREVENT_FAST_SEND
    static const byte uint8_tLengthMax = 3;  //3 digits (255)
    static const byte int8_tLengthMax = 1 + uint8_tLengthMax;  //sign + 3 digits (-127)
    static const byte uint16_tLengthMax = 5;  //5 digits (65535)
    static const byte int16_tLengthMax = 1 + uint16_tLengthMax;  //sign + 5 digits (-32767)
    static const byte uint32_tLengthMax = 10;  //10 digits (4294967295)
    static const byte int32_tLengthMax = 1 + uint32_tLengthMax;  //sign + 10 digits (-2147483647)
    static const byte byteLengthMax = uint8_tLengthMax;
#if UINT_MAX <= 65535
    static const byte unsignedIntLengthMax = uint16_tLengthMax;
#else  //UINT_MAX <= 65535
    static const byte unsignedIntLengthMax = uint32_tLengthMax;
#endif  //UINT_MAX <= 65535
#if INT_MIN >= -32767
    static const byte intLengthMax = int16_tLengthMax;
#else  //INT_MIN >= -32767
    static const byte intLengthMax = int32_tLengthMax;
#endif  //INT_MIN >= -32767
    static const byte unsignedLongLengthMax = uint32_tLengthMax;
    static const byte longLengthMax = int32_tLengthMax;
    static const byte IPAddressLengthMax = 3 + 1 + 3 + 1 + 3 + 1 + 3;  //4 x octet + 3 x dot
    static const byte doubleIntegerLengthMax = 40;  //sign + 39 digits max (-1000000000000000000000000000000000000000 gives me "floating constant exceeds range of 'double'" warning)

    static const byte sendDoubleDecimalPlacesDefault = 3;  //default number of decimal places when sending event/payload of double/float type

    static const byte payloadWrapperLength = 5; //['']\n
#endif  //ETHEREVENT_FAST_SEND

#ifndef ETHEREVENT_NO_AUTHENTICATION
    static const byte cookieLengthMax = 8;  //the maximum length of cookie that can be received (8 hexadecimal digits)
    static const byte maximumReceivedMD5length = 9 + 32;  // "TCPEvents" + 32 character MD5 hash
    static const int authenticationFailedCode = -1;
#endif  //ETHEREVENT_NO_AUTHENTICATION

    static const byte TCPEventsPayloadFormattingLength = 2;  //the length of one side of the formatting characters added to payloads entered in the payload field of TCPEvent's "Send an Event" action configuration([''])

    static const unsigned int timeoutDefault = 1000;  //(ms)Timeout duration for ethernet stream functions.

    unsigned int timeout;  //default is set in begin() and the user can change the timeout via setTimeout()
    size_t availableEventSubmessageLengthMax;  //value set in begin()

#ifndef ETHEREVENT_NO_AUTHENTICATION
    char* password;
    byte passwordLength;
#endif  //ETHEREVENT_NO_AUTHENTICATION

#ifdef ETHEREVENT_FAST_SEND
    byte sendDoubleDecimalPlaces;
#else  //ETHEREVENT_FAST_SEND
    boolean payloadSpecified;
#endif  //ETHEREVENT_FAST_SEND

    IPAddress fromIP;  //IP address of the last event sender
    byte eventLengthMax;
    char* receivedEvent;  //event buffer
    byte receivedEventLength;  //save the length so I don't have to do strlen everytime availableEvent() is called
    byte readEventLength;  //number of characters of the event that have been read
    unsigned int payloadLengthMax;
    char* receivedPayload;  //payload buffer
    unsigned int receivedPayloadLength;
    unsigned int readPayloadLength;  //number of characters of the payload that have been read


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //availableWait - for some reason the UIPEthernet library adds some null characters to the start of the MD5 if you start readBytesUntil() before there are characters available
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef UIPETHERNET_H
    void availableWait(EthernetClient &ethernetClient) {
      const unsigned long availableWaitTimeStamp = millis();
      while (!ethernetClient.available() && millis() - availableWaitTimeStamp < timeout) {}
    }
#endif  //UIPETHERNET_H


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //flushEvent
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void flushEvent() {
      receivedEvent[0] = 0;  //reset the event buffer
      receivedEventLength = 0;
      readEventLength = 0;
    }


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //flushPayload
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void flushPayload() {
      receivedPayload[0] = 0;  //reset the event buffer
      receivedPayloadLength = 0;
      readPayloadLength = 0;
    }
};

static EtherEventClass EtherEvent;  //This sets up a single global instance of the library so the class doesn't need to be declared in the user sketch and multiple instances are not necessary in this case.

#endif  //EtherEvent_h
