// EtherEvent - Easy to use password authenticated network communication between Arduinos and EventGhost Network Event Sender/Receiver and TCPEvents plugins: http://github.com/per1234/EtherEvent
#ifndef EtherEvent_h
#define EtherEvent_h

#include <Arduino.h>

#if defined(ARDUINO_ARCH_SAM) || defined(ARDUINO_ARCH_SAMD)
#include <avr/dtostrf.h>
#endif  //defined(ARDUINO_ARCH_SAM) || defined(ARDUINO_ARCH_SAMD)

#include <Ethernet.h>

#ifndef ETHEREVENT_NO_AUTHENTICATION
#include <MD5.h>
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

#define EVENT_BUFFER_SIZE 42
#define PAYLOAD_BUFFER_SIZE 42


class PrintEvent : public Print {
    friend class EtherEventClass;
  private:
    PrintEvent() {}
    virtual size_t write(uint8_t printChar);
    char eventBuffer[EVENT_BUFFER_SIZE];
    unsigned int writePosition;
};

class PrintPayload : public Print {
    friend class EtherEventClass;
  private:
    PrintPayload() {}
    virtual size_t write(uint8_t printChar);
    char payloadBuffer[PAYLOAD_BUFFER_SIZE];
    unsigned int writePosition;
};


namespace EtherEventNamespace {
const unsigned long debugSerialBaud = 9600;
const char payloadSeparator[] = "payload ";  //indicates payload
const byte payloadSeparatorLength = strlen(EtherEventNamespace::payloadSeparator);  //includes space at the end
const char payloadWithoutRelease[] = "payload withoutRelease";  //eg sends this every time and EtherEvent filters it out
const byte payloadWithoutReleaseLength = strlen(EtherEventNamespace::payloadWithoutRelease);
const char closeMessage[] = "close\n";  //sender sends this message to the receiver to close the connection
const byte closeMessageLength = strlen(EtherEventNamespace::closeMessage);
}


class EtherEventClass {
  public:
    EtherEventClass();
    boolean begin(const byte eventLengthMaxInput = 15, const unsigned int payloadLengthMaxInput = 100);  //these are the default max length values


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

    int availableEvent(EthernetServer &ethernetServer, const long cookieInput = false, const char passwordInput[] = (char*)DEFAULT_PASSWORD_STRING) {
#else  //ETHEREVENT_NO_AUTHENTICATION
    int availableEvent(EthernetServer &ethernetServer) {
#endif  //ETHEREVENT_NO_AUTHENTICATION
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
              char cookiePassword[8 + 1 + currentPasswordLength + 1];  //create buffer of length sufficient for: cookie(8 hexadecimal digits max)  +  password separator  +  Password  +  null terminator
#ifdef __ARDUINO_X86__
              sprintf (cookiePassword, "%li", cookie);
#else  //__ARDUINO_X86__
              ltoa(cookie, cookiePassword, HEX);
#endif  //__ARDUINO_X86__
              ETHEREVENT_SERIAL.println(cookiePassword);
              ethernetClient.print(cookiePassword);  //send the cookie

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
              unsigned char* cookiePasswordHash = MD5::make_hash(cookiePassword);
              char* cookiePasswordMD5 = MD5::make_digest(cookiePasswordHash, 16);
              free(cookiePasswordHash);
              ETHEREVENT_SERIAL.print(F("EtherEvent.availableEvent: cookiePasswordMD5: "));
              ETHEREVENT_SERIAL.println(cookiePasswordMD5);

              //verify the received hashword
              if (ethernetClient.find(cookiePasswordMD5) == true) {  //authentication successful
                ethernetClient.flush();  //clear the \n or it will cause a null message in the payload/event message read
                ETHEREVENT_SERIAL.println(F("EtherEvent.availableEvent: authentication successful"));
                ethernetClient.print(" " ETHEREVENT_ACCEPT_MESSAGE);  //The space indicates the server type is TCPEvents. For some reason I can't use F() on this one.
                authenticationSuccessful = true;
              }
              free(cookiePasswordMD5);
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

                //Strip TCPEvents payload formatting. TCPEvents wraps the payload in [''] if the payload field is used in the Send an Event configuration.
                byte payloadOffset = 0;
                if (receivedMessage[EtherEventNamespace::payloadSeparatorLength] == '[' && receivedMessage[EtherEventNamespace::payloadSeparatorLength + 1] == 39) {  //39 is apostrophe
                  payloadOffset = TCPEventsPayloadFormattingLength;  //skip the first 2 characters of the payload
                  if (receivedMessage[receivedPayloadLength + EtherEventNamespace::payloadSeparatorLength - 1] == ']') {
                    receivedPayloadLength--;
                  }
                  if (receivedMessage[receivedPayloadLength + EtherEventNamespace::payloadSeparatorLength - 1] == 39) {
                    receivedPayloadLength--;
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
              receivedEventLength = min(bytesRead, eventLengthMax) + 1;  //length including null terminator
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


    unsigned int availablePayload();
    void readEvent(char eventBuffer[]);
    char readEvent();
    void readPayload(char payloadBuffer[]);
    char readPayload();
#ifdef ethernetclientwithremoteIP_h  //the include guard from the modified EthernetClient.h
    IPAddress senderIP();
#endif  //ethernetclientwithremoteIP_h
    void flushReceiver();


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //send
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    template <typename target_t, typename event_t>
    boolean send(EthernetClient &ethernetClient, const target_t target, const unsigned int port, const event_t event) {  //payload must be specified with password even if it's blank
      Serial.println(F("EtherEvent.send(no payload)"));
      noPayload = true;  //set the flag to indicate there is no payload
      return send(ethernetClient, target, port, event, false);
    }

    template <typename event_t, typename payload_t>
    boolean send(EthernetClient &ethernetClient, const byte target[], const unsigned int port, const event_t event, const payload_t payload) {
      IPAddress targetIP = IPAddress(target[0], target[1], target[2], target[3]);
      return send(ethernetClient, targetIP, port, event, payload);
    }

#ifndef ETHEREVENT_NO_AUTHENTICATION
    template <typename event_t, typename payload_t, typename password_t>
    boolean send(EthernetClient &ethernetClient, const byte target[], const unsigned int port, const event_t event, const payload_t payload, const password_t passwordInput) {
      IPAddress targetIP = IPAddress(target[0], target[1], target[2], target[3]);
      return send(ethernetClient, targetIP, port, event, payload, passwordInput);
    }

    template <typename event_t, typename payload_t>
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const event_t event, const payload_t payload, const __FlashStringHelper* passwordInput) {
      const byte passwordInputLength = FSHlength(passwordInput);
      char passwordChar[passwordInputLength + 1];
      memcpy_P(passwordChar, passwordInput, passwordInputLength + 1);  //+1 for the null terminator
      return send(ethernetClient, target, port, event, payload, passwordChar);
    }
#endif  //ETHEREVENT_NO_AUTHENTICATION
#ifndef ETHEREVENT_FAST_SEND
#ifndef ETHEREVENT_NO_AUTHENTICATION
    template <typename event_t, typename payload_t>
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const event_t event, const payload_t payload, const char passwordInput[] = (char*)DEFAULT_PASSWORD_STRING) {
#else //ETHEREVENT_NO_AUTHENTICATION
    template <typename event_t, typename payload_t>
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const event_t event, const payload_t payload) {
#endif  //ETHEREVENT_NO_AUTHENTICATION
#else //ETHEREVENT_FAST_SEND
#ifndef ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const char event[], const char payload[] = "", const char passwordInput[] = (char*)DEFAULT_PASSWORD_STRING) {
#else //ETHEREVENT_NO_AUTHENTICATION
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const char event[], const char payload[] = "") {
#endif  //ETHEREVENT_NO_AUTHENTICATION
#endif  //ETHEREVENT_FAST_SEND

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
        ethernetClient.print(F(ETHEREVENT_MAGIC_WORD));  //send the magic word to the receiver so it will send the cookie

        byte currentPasswordLength = passwordLength;
        if (passwordInput[0] != DEFAULT_PASSWORD_CHAR) {  //the user passed a password string in the function call
          currentPasswordLength = strlen(passwordInput);
        }
        char cookiePassword[cookieLengthMax + 1 + currentPasswordLength + 1];  //cookie, password separator(:), password, null terminator
        boolean authenticationSuccessful = false;
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
          unsigned char* cookiePasswordHash = MD5::make_hash(cookiePassword);
          char* cookiePasswordMD5 = MD5::make_digest(cookiePasswordHash, 16);
          free(cookiePasswordHash);
          ETHEREVENT_SERIAL.print(F("EtherEvent.send: hashWordMD5: "));
          ETHEREVENT_SERIAL.println(cookiePasswordMD5);
          ethernetClient.print(cookiePasswordMD5);  //send the MD5 of the hashword
          ethernetClient.write(10);  //newline
          free(cookiePasswordMD5);

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
      if (noPayload == false) {  //check if there is a payload
#else  //ETHEREVENT_FAST_SEND
      if (payload[0] != 0) {  //check if there is a payload
#endif  //ETHEREVENT_FAST_SEND
        ethernetClient.print(EtherEventNamespace::payloadSeparator);
#ifndef ETHEREVENT_NO_AUTHENTICATION
        if (passwordInput[0] == 0) {  //authentication disabled
#endif
          //adds [''] to the payload in unauthenticated mode otherwise TCPEvents attempts to evaluate the payload as a python expression because the servertype is assumed to be TCPEvents in unauthenticated mode, EtherEvent.availableEvent() will strip these characters from the payload
          ethernetClient.print('[');
          ethernetClient.write(39);
#ifndef ETHEREVENT_NO_AUTHENTICATION
        }
#endif  //ETHEREVENT_NO_AUTHENTICATION
        ethernetClient.print(payload);
#ifndef ETHEREVENT_NO_AUTHENTICATION
        if (passwordInput[0] == 0) {  //authentication disabled
#endif  //ETHEREVENT_NO_AUTHENTICATION
          ethernetClient.write(39);
          ethernetClient.print(']');
#ifndef ETHEREVENT_NO_AUTHENTICATION
        }
#endif  //ETHEREVENT_NO_AUTHENTICATION
        ethernetClient.write(10);  //newline
      }
      ethernetClient.print(event);  //transmit event
      ethernetClient.write(10);  //newline
      ETHEREVENT_SERIAL.println(F("EtherEvent.send: event sent"));

      ethernetClient.print(EtherEventNamespace::closeMessage);  //tell the receiver to close
      ethernetClient.stop();
      ETHEREVENT_SERIAL.println(F("EtherEvent.send: connection closed"));
      return true;
    }


#ifdef ETHEREVENT_FAST_SEND
#ifdef ETHEREVENT_NO_AUTHENTICATION
    template <typename targetType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, char event[], char payload[]) {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(char* event, char* payload)"));
      return send(ethernetClient, target, port, (const char*)event, (const char*)payload);  //Convert char to const char. Needed to fix ambiguous overload warning.
    }

    template <typename targetType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const char event[], char payload[]) {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(char* payload)"));
      return send(ethernetClient, target, port, event, (const char*)payload);
    }

    template <typename targetType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, char event[], const char payload[] = "") {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(char* event)"));
      return send(ethernetClient, target, port, (const char*)event, payload);
    }

    template <typename targetType, typename eventType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, eventType event, char payload[]) {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(char* payload)"));
      return send(ethernetClient, target, port, event, (const char*)payload);
    }

    template <typename targetType, typename payloadType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, char event[], payloadType payload) {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(char* event)"));
      return send(ethernetClient, target, port, (const char*)event, payload);
    }

    template <typename targetType, typename eventType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, eventType event, const char payload[] = "") {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(eventType event)"));
      Serial.println("send(eventType, const char*)");
      printEvent.print(event);
      printEvent.eventBuffer[printEvent.writePosition] = 0; //add null terminator.
      printEvent.writePosition = 0; //reset the write position for the next send()
      return send(ethernetClient, target, port, (const char*)printEvent.eventBuffer, payload);
    }

    template <typename targetType, typename payloadType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const char event[], payloadType payload) {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(payloadType payload)"));
      printPayload.print(payload);
      printPayload.payloadBuffer[printPayload.writePosition] = 0; //add null terminator.
      printPayload.writePosition = 0; //reset the write position for the next send()
      return send(ethernetClient, target, port, event, (const char*)printPayload.payloadBuffer);
    }

    template <typename targetType, typename eventType, typename payloadType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, eventType event, payloadType payload) {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(eventType event, payloadType payload)"));
      printEvent.print(event);
      printEvent.eventBuffer[printEvent.writePosition] = 0; //add null terminator.
      printEvent.writePosition = 0;
      return send(ethernetClient, target, port, (const char*)printEvent.eventBuffer, payload);
    }
#else //ETHEREVENT_NO_AUTHENTICATION
    template <typename targetType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, char event[], char payload[], const char passwordInput[] = (char*)DEFAULT_PASSWORD_STRING) {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(char* event, char* payload)"));
      return send(ethernetClient, target, port, (const char*)event, (const char*)payload, passwordInput);  //Convert char to const char. Needed to fix ambiguous overload warning.
    }

    template <typename targetType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const char event[], char payload[], const char passwordInput[] = (char*)DEFAULT_PASSWORD_STRING) {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(char* payload)"));
      return send(ethernetClient, target, port, event, (const char*)payload, passwordInput);
    }

    template <typename targetType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, char event[], const char payload[] = "", const char passwordInput[] = (char*)DEFAULT_PASSWORD_STRING) {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(char* event)"));
      return send(ethernetClient, target, port, (const char*)event, payload, passwordInput);
    }

    template <typename targetType, typename eventType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, eventType event, char payload[], const char passwordInput[] = (char*)DEFAULT_PASSWORD_STRING) {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(char* payload)"));
      return send(ethernetClient, target, port, event, (const char*)payload, passwordInput);
    }

    template <typename targetType, typename payloadType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, char event[], payloadType payload, const char passwordInput[] = (char*)DEFAULT_PASSWORD_STRING) {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(char* event)"));
      return send(ethernetClient, target, port, (const char*)event, payload, passwordInput);
    }

    template <typename targetType, typename eventType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, eventType event, const char payload[] = "", const char passwordInput[] = (char*)DEFAULT_PASSWORD_STRING) {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(eventType event)"));
      Serial.println("send(eventType, const char*)");
      printEvent.print(event);
      printEvent.eventBuffer[printEvent.writePosition] = 0; //add null terminator.
      printEvent.writePosition = 0; //reset the write position for the next send()
      return send(ethernetClient, target, port, (const char*)printEvent.eventBuffer, payload, passwordInput);
    }

    template <typename targetType, typename payloadType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const char event[], payloadType payload, const char passwordInput[] = (char*)DEFAULT_PASSWORD_STRING) {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(payloadType payload)"));
      printPayload.print(payload);
      printPayload.payloadBuffer[printPayload.writePosition] = 0; //add null terminator.
      printPayload.writePosition = 0; //reset the write position for the next send()
      return send(ethernetClient, target, port, event, (const char*)printPayload.payloadBuffer, passwordInput);
    }

    template <typename targetType, typename eventType, typename payloadType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, eventType event, payloadType payload, const char passwordInput[] = (char*)DEFAULT_PASSWORD_STRING) {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(eventType event, payloadType payload)"));
      printEvent.print(event);
      printEvent.eventBuffer[printEvent.writePosition] = 0; //add null terminator.
      printEvent.writePosition = 0;
      return send(ethernetClient, target, port, (const char*)printEvent.eventBuffer, payload, passwordInput);
    }
#endif //ETHEREVENT_NO_AUTHENTICATION
#endif  //ETHEREVENT_FAST_SEND


    void setTimeout(const unsigned int timeoutInput);
    unsigned int getTimeout();
    boolean setPassword(const char passwordInput[]);
    boolean setPassword(const __FlashStringHelper* passwordInput);

#ifdef ETHEREVENT_FAST_SEND
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //setSendDoubleDecimalPlaces
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void setSendDoubleDecimalPlaces(const byte decimalPlaces) {
      ETHEREVENT_SERIAL.println(F("EtherEvent.setSendDoubleDecimalPlaces"));
      sendDoubleDecimalPlaces = decimalPlaces;
    }
#endif  //ETHEREVENT_FAST_SEND

    void IPtoa(const IPAddress &IP, char IPcharBuffer[]);
    unsigned int FSHlength(const __FlashStringHelper* FSHinput);


  private:
    PrintEvent printEvent;
    PrintPayload printPayload;

    //used for the FASTSEND char array conversions
    static const byte uint16_tLengthMax = 5;  //5 digits
    static const byte int16_tLengthMax = 1 + uint16_tLengthMax;  //sign + 5 digits
    static const byte uint32_tLengthMax = 10;  //10 digits
    static const byte int32_tLengthMax = 1 + uint32_tLengthMax;  //sign + 10 digits
    static const byte IPAddressLengthMax = 3 + 1 + 3 + 1 + 3 + 1 + 3;  //4 x octet + 3 x dot
    static const byte doubleIntegerLengthMax = 40;  //sign + 39 digits max (-1000000000000000000000000000000000000000 gives me "floating constant exceeds range of 'double'" warning)

    static const byte cookieLengthMax = 8;  //the maximum length of cookie that can be received

    static const byte TCPEventsPayloadFormattingLength = 2;  //the length of one side of the formatting characters added to payloads entered in the payload field of TCPEvent's "Send an Event" action configuration([''])

    static const unsigned int timeoutDefault = 1000;  //(ms)Timeout duration for ethernet stream functions.
    static const byte sendDoubleDecimalPlacesDefault = 3;  //default number of decimal places when sending event/payload of double/float type

    static const int authenticationFailedCode = -1;

    unsigned int timeout;  //default is set in begin() and the user can change the timeout via setTimeout()
    unsigned int availableEventSubmessageLengthMax;  //value set in begin()

    char* password;
    byte passwordLength;

    boolean noPayload;

    IPAddress fromIP;  //IP address of the last event sender
    byte eventLengthMax;
    char* receivedEvent;  //event buffer
    byte receivedEventLength;  //save the length so I don't have to do strlen everytime availableEvent() is called
    byte readEventLength;  //number of characters of the event that have been read
    unsigned int payloadLengthMax;
    char* receivedPayload;  //payload buffer
    unsigned int receivedPayloadLength;
    unsigned int readPayloadLength;  //number of characters of the payload that have been read
    byte sendDoubleDecimalPlaces;

    void flushEvent();
    void flushPayload();
};

extern EtherEventClass EtherEvent;  //declare the class so it doesn't have to be done in the sketch


#endif  //EtherEvent_h

