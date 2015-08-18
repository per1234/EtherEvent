// EtherEvent - Easy to use password authenticated network communication between Arduinos and EventGhost Network Event Sender/Receiver and TCPEvents plugins: http://github.com/per1234/EtherEvent
#ifndef EtherEvent_h
#define EtherEvent_h

#include <Arduino.h>

#ifndef ARDUINO_ARCH_AVR
#include <avr/dtostrf.h>
#endif  //ARDUINO_ARCH_AVR

#include <Ethernet.h>

#ifndef ETHEREVENT_NO_AUTHENTICATION
#include "MD5.h"
#endif  //ETHEREVENT_NO_AUTHENTICATION


#define ETHEREVENT_DEBUG false  //(false == serial debug output off, true == serial debug output on)The serial debug output will increase memory usage and communication latency so only enable when needed.
#define ETHEREVENT_SERIAL if(ETHEREVENT_DEBUG)Serial  //I have to use a different name for Serial in this file otherwise the debug statement control also affects any other file that includes this file.

#define ETHEREVENT_MAGIC_WORD "quintessence\n\r"  //word used to trigger the cookie send from the receiver. I had to #define this instead of const because find() didn't like the const
#define ETHEREVENT_ACCEPT_MESSAGE "accept\n"  //authentication success message. I had to #define this instead of const because find() didn't like the const


namespace EtherEventNamespace {
static const char payloadSeparator[] = "payload ";  //indicates payload
static const byte payloadSeparatorLength = strlen(EtherEventNamespace::payloadSeparator);  //includes space at the end
static const char payloadWithoutRelease[] = "payload withoutRelease";  //eg sends this every time and EtherEvent filters it out
static const byte payloadWithoutReleaseLength = strlen(EtherEventNamespace::payloadWithoutRelease);
static const char closeMessage[] = "close\n";  //sender sends this message to the receiver to close the connection
static const byte closeMessageLength = strlen(EtherEventNamespace::closeMessage);
}


class EtherEventClass {
  public:
    EtherEventClass();
    boolean begin(const byte eventLengthMaxInput = 15, const unsigned int payloadLengthMaxInput = 100);  //these are the default max length values


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //availableEvent - checks for senders, connects, authenticates, reads the event and payload into the buffer and returns the number of bytes of the most recently received event are left in the buffer
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef ETHEREVENT_NO_AUTHENTICATION
    byte availableEvent(EthernetServer &ethernetServer, const long cookieInput = false) {
#else  //ETHEREVENT_NO_AUTHENTICATION
    byte availableEvent(EthernetServer &ethernetServer) {
#endif  //ETHEREVENT_NO_AUTHENTICATION
      if (receivedEventLength == 0) {  //no event buffered
        if (EthernetClient ethernetClient = ethernetServer.available() ) {  //connect to the client
          ETHEREVENT_SERIAL.println(F("EtherEvent.availableEvent: connected"));
          ethernetClient.setTimeout(timeout);  //timeout on Stream fumctions. This needs to be called every time in availableEvent() or it resets to the default of 1000ms because a new EthernetClient object is created every call.

#ifndef ETHEREVENT_NO_AUTHENTICATION
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
            char cookiePassword[8 + 1 + passwordLength + 1];  //create buffer of length sufficient for: cookie(8 hexadecimal digits max)  +  password separator  +  Password  +  null terminator
            ltoa(cookie, cookiePassword, HEX);
            ETHEREVENT_SERIAL.println(cookiePassword);
            ethernetClient.print(cookiePassword);  //send the cookie

            //calculate the hashword
            strcat(cookiePassword, ":");  //create the hashword to compare to the received one
            strcat(cookiePassword, password);
            ETHEREVENT_SERIAL.print(F("EtherEvent.availableEvent: cookiePassword: "));
            ETHEREVENT_SERIAL.println(cookiePassword);
            unsigned char* cookiePasswordHash = MD5::make_hash(cookiePassword);
            char *cookiePasswordMD5 = MD5::make_digest(cookiePasswordHash, 16);
            free(cookiePasswordHash);
            ETHEREVENT_SERIAL.print(F("EtherEvent.availableEvent: cookiePasswordMD5: "));
            ETHEREVENT_SERIAL.println(cookiePasswordMD5);

            //verify the received hashword
            if (ethernetClient.find(cookiePasswordMD5) == true) {  //authentication successful
              ethernetClient.flush();  //clear the \n or it will cause a null message in the payload/event message read
              ETHEREVENT_SERIAL.println(F("EtherEvent.availableEvent: authentication successful"));
              ethernetClient.print(" " ETHEREVENT_ACCEPT_MESSAGE);  //The space indicates the server type is TCPEvents. For some reason I can't use F() on this one.
              free(cookiePasswordMD5);
#endif  //ETHEREVENT_NO_AUTHENTICATION
              //Read and process the message
              for (byte count = 0; count < 7; count++) {  //Read and process the count stuff is just to make sure it will never go into an infinite loop. It should never need more than five iterations of the for loop to get event and payload
                ETHEREVENT_SERIAL.println(F("EtherEvent.availableEvent: payload/event for loop"));
                char receivedMessage[availableEventSubmessageLengthMax + 1];  //initialize the buffer to read into
                unsigned int bytesRead = ethernetClient.readBytesUntil(10, receivedMessage, availableEventSubmessageLengthMax + 1);  //put the incoming data up to the newline into receivedMessage
                if (bytesRead > availableEventSubmessageLengthMax) {  //event or payload exceeds max length
                  ETHEREVENT_SERIAL.println(F("EtherEvent.availableEvent: event/payload > max length"));
                  char findString[] = "\n";  //I had to do this instead of just ethernetClient.find(10) or ethernetClient.find("\n") because that causes a compile error under Arduino IDE 1.6.0 which also doesn't allow const char
                  ethernetClient.find(findString);  //flush up to the newlineI had to do the "\n" instead of just ethernetClient.find(10) because that causes a compile error under Arduino IDE 1.6.0
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
                    unsigned int readPayloadLength = min(bytesRead - EtherEventNamespace::payloadSeparatorLength, payloadLengthMax + TCPEventsPayloadFormattingLength);  //make sure the payload will never be longer than the max length

                    //Strip TCPEvents payload formatting. TCPEvents wraps the payload in [''] if the payload field is used in the Send an Event configuration.
                    byte payloadOffset = 0;
                    if (receivedMessage[EtherEventNamespace::payloadSeparatorLength] == '[' && receivedMessage[EtherEventNamespace::payloadSeparatorLength + 1] == 39) {  //39 is apostrophe
                      payloadOffset = TCPEventsPayloadFormattingLength;  //skip the first 2 characters of the payload
                      if (receivedMessage[readPayloadLength + EtherEventNamespace::payloadSeparatorLength - 1] == ']') {
                        readPayloadLength--;
                      }
                      if (receivedMessage[readPayloadLength + EtherEventNamespace::payloadSeparatorLength - 1] == 39) {
                        readPayloadLength--;
                      }
                      readPayloadLength -= payloadOffset;
                    }
                    else {  //no TCPEvents payload formatting is present
                      readPayloadLength = min(readPayloadLength, payloadLengthMax);
                    }

                    //put the payload into the buffer
                    for (unsigned int payloadCounter = 0; payloadCounter < readPayloadLength; payloadCounter++) {
                      receivedPayload[payloadCounter] = receivedMessage[payloadCounter + payloadOffset + EtherEventNamespace::payloadSeparatorLength];
                    }
                    receivedPayload[readPayloadLength] = 0;  //null terminator
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
#ifndef ETHEREVENT_NO_AUTHENTICATION
            }

            //authentication failed
            else {
              free(cookiePasswordMD5);
              ETHEREVENT_SERIAL.println(F("EtherEvent.availableEvent: authentication failed"));
            }
          }
#endif  //ETHEREVENT_NO_AUTHENTICATION      
          ethernetClient.print(EtherEventNamespace::closeMessage);  //tell the receiver to close
          ethernetClient.stop();
          ETHEREVENT_SERIAL.println(F("EtherEvent.availableEvent: connection closed"));
        }
      }
      return receivedEventLength;
    }


    unsigned int availablePayload();
    void readEvent(char eventBuffer[]);
    void readPayload(char payloadBuffer[]);
#ifdef ethernetclientwithremoteIP_h  //the include guard from the modified EthernetClient.h
    IPAddress senderIP();
#endif
    void flushReceiver();

    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const char event[], const char payload[] = "") {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send: attempting connection"));
      ETHEREVENT_SERIAL.print(F("EtherEvent.send: target: "));
      ETHEREVENT_SERIAL.println(target);
      ETHEREVENT_SERIAL.print(F("EtherEvent.send: port: "));
      ETHEREVENT_SERIAL.println(port);
      ETHEREVENT_SERIAL.print(F("EtherEvent.send: event: "));
      ETHEREVENT_SERIAL.println(event);
      ETHEREVENT_SERIAL.print(F("EtherEvent.send: payload: "));
      ETHEREVENT_SERIAL.println(payload);

      byte eventSuccess = false;
      if (ethernetClient.connect(target, port)) {  //connected to receiver

#ifndef ETHEREVENT_NO_AUTHENTICATION
        ethernetClient.setTimeout(timeout);  //Timeout on Stream functions. I only have to set it once here for the send() timeout but I can't set it in begin() because ethernetClient isn't passed to that function there so it's most efficient to just set it here every time
        ETHEREVENT_SERIAL.println(F("EtherEvent.send: connected, sending magic word"));
        ethernetClient.print(F(ETHEREVENT_MAGIC_WORD));  //send the magic word to the receiver so it will send the cookie

        char cookiePassword[cookieLengthMax + 1 + passwordLength + 1];  //cookie, password separator(:), password, null terminator
        if (byte bytesRead = ethernetClient.readBytesUntil(10, cookiePassword, cookieLengthMax)) {  //get the cookie
          cookiePassword[bytesRead] = 0;
          strcat(cookiePassword, ":");  //add the password separator to the cookie
          strcat(cookiePassword, password);  //add password to the cookie
          ETHEREVENT_SERIAL.print(F("EtherEvent.send: cookiePassword: "));
          ETHEREVENT_SERIAL.println(cookiePassword);
          unsigned char* cookiePasswordHash = MD5::make_hash(cookiePassword);
          char *cookiePasswordMD5 = MD5::make_digest(cookiePasswordHash, 16);
          free(cookiePasswordHash);
          ETHEREVENT_SERIAL.print(F("EtherEvent.send: hashWordMD5: "));
          ETHEREVENT_SERIAL.println(cookiePasswordMD5);
          ethernetClient.print(cookiePasswordMD5);  //send the MD5 of the hashword
          ethernetClient.write(10);  //newline
          free(cookiePasswordMD5);

          if (ethernetClient.find((char*)ETHEREVENT_ACCEPT_MESSAGE) == true) {  //authentication successful - the (char*) thing is to get rid of the "warning: deprecated conversion from string constant to ‘char*’" compiler warning
#endif  //ETHEREVENT_NO_AUTHENTICATION

            if (payload[0] != 0) {  //check if there is a payload
              ethernetClient.print(EtherEventNamespace::payloadSeparator);
#ifdef ETHEREVENT_NO_AUTHENTICATION
              //adds [''] to the payload in unauthenticated mode otherwise TCPEvents attempts to evaluate the payload as a python expression because the servertype is assumed to be TCPEvents in unauthenticated mode, EtherEvent.availableEvent() will strip these characters from the payload
              ethernetClient.print('[');
              ethernetClient.write(39);
#endif  //ETHEREVENT_NO_AUTHENTICATION
              ethernetClient.print(payload);
#ifdef ETHEREVENT_NO_AUTHENTICATION
              ethernetClient.write(39);
              ethernetClient.print(']');
#endif  //ETHEREVENT_NO_AUTHENTICATION
              ethernetClient.write(10);  //newline
            }
            ethernetClient.print(event);  //transmit event
            ethernetClient.write(10);  //newline
            eventSuccess = true;
#ifndef ETHEREVENT_NO_AUTHENTICATION
          }
        }
#endif  //ETHEREVENT_NO_AUTHENTICATION    
        ethernetClient.print(EtherEventNamespace::closeMessage);  //tell the receiver to close
        ethernetClient.stop();
        ETHEREVENT_SERIAL.println(F("EtherEvent.send: connection closed"));
      }
      else {
        ETHEREVENT_SERIAL.println(F("EtherEvent.send: connection failed"));
      }
      return eventSuccess;  //send finished
    }


    boolean send(EthernetClient &ethernetClient, const byte target[], const unsigned int port, const char event[], const char payload[] = "");

    //convert event
    template <typename targetType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, char event[], const char payload[]) {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(char event)"));
      return send(ethernetClient, target, port, (const char*)event, payload);  //Convert char to const char. Needed to fix ambiguous overload warning.
    }
    template <typename targetType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const int8_t event, const char payload[] = "") {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(int8_t event)"));
      return send(ethernetClient, target, port, (const int)event, payload);  //Convert event to int. Needed to fix ambiguous overload warning.
    }
    template <typename targetType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const byte event, const char payload[] = "") {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(byte event)"));
      return send(ethernetClient, target, port, (const int)event, payload);  //Convert event to int. Needed to fix ambiguous overload warning.
    }
    template <typename targetType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const int16_t event, const char payload[] = "") {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(int event)"));
      char eventChar[int16_tLengthMax + 1];
      itoa(event, eventChar, 10);
      return send(ethernetClient, target, port, (const char*)eventChar, payload);
    }
    template <typename targetType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const uint16_t event, const char payload[] = "") {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(unsigned int event)"));
      char eventChar[uint16_tLengthMax + 1];
      utoa(event, eventChar, 10);
      return send(ethernetClient, target, port, (const char*)eventChar, payload);
    }
    template <typename targetType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const int32_t event, const char payload[] = "") {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(long event)"));
      char eventChar[int32_tLengthMax + 1];
      ltoa(event, eventChar, 10);
      return send(ethernetClient, target, port, (const char*)eventChar, payload);
    }
    template <typename targetType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const uint32_t event, const char payload[] = "") {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(unsigned long event)"));
      char eventChar[uint32_tLengthMax + 1];
      ultoa(event, eventChar, 10);
      return send(ethernetClient, target, port, (const char*)eventChar, payload);
    }
    template <typename targetType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const __FlashStringHelper* event, const char payload[] = "") {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(F() event)"));
      byte eventLength = FSHlength(event);
      char eventChar[eventLength + 1];
      memcpy_P(eventChar, event, eventLength + 1);  //+1 for the null terminator
      return send(ethernetClient, target, port, (const char*)eventChar, payload);
    }
    template <typename targetType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const String &event, const char payload[] = "") {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(String event)"));
      byte stringLength = event.length();
      char eventChar[stringLength + 1];
      for (byte counter = 0; counter < stringLength; counter++) {
        eventChar[counter] = event[counter];  //I could probably just use c_str() instead but then I have to deal with the pointer
      }
      eventChar[stringLength] = 0;
      return send(ethernetClient, target, port, (const char*)eventChar, payload);
    }
    template <typename targetType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const IPAddress &event, const char payload[] = "") {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(IPAddress event)"));
      char eventChar[IPAddressLengthMax + 1];
      IPtoa(event, eventChar);
      return send(ethernetClient, target, port, (const char*)eventChar, payload);
    }
    template <typename targetType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const double event, const char payload[] = "") {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(double event)"));
      char eventChar[doubleIntegerLengthMax + 1 + sendDoubleDecimalPlaces + 1];  //max integer length + decimal point + decimal places setting + null terminator
      dtostrf(event, sendDoubleDecimalPlaces + 2, sendDoubleDecimalPlaces, eventChar);
      return send(ethernetClient, target, port, (const char*)eventChar, payload);
    }
    template <typename targetType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const float event, const char payload[] = "") {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(float event)"));
      return send(ethernetClient, target, port, (double)event, payload);  //needed to fix ambiguous compiler warning
    }

    //convert payload
    template <typename targetType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const char event[], char payload[]) {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(char payload)"));
      return send(ethernetClient, target, port, event, (const char*)payload);  //Convert char to const char. Needed to fix ambiguous overload warning.
    }
    template <typename targetType, typename eventType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const eventType event, const int16_t payload) {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(int payload)"));
      char payloadChar[int16_tLengthMax + 1];
      itoa(payload, payloadChar, 10);
      return send(ethernetClient, target, port, event, payloadChar);
    }
    template <typename targetType, typename eventType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const eventType event, const uint16_t payload) {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(unsigned int payload)"));
      char payloadChar[uint16_tLengthMax + 1];
      utoa(payload, payloadChar, 10);
      return send(ethernetClient, target, port, event, payloadChar);
    }
    template <typename targetType, typename eventType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const eventType event, const int32_t payload) {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(long payload)"));
      char payloadChar[int32_tLengthMax + 1];
      ltoa(payload, payloadChar, 10);
      return send(ethernetClient, target, port, event, payloadChar);
    }
    template <typename targetType, typename eventType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const eventType event, const uint32_t payload) {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(unsigned long payload)"));
      char payloadChar[uint32_tLengthMax + 1];
      ultoa(payload, payloadChar, 10);
      return send(ethernetClient, target, port, event, payloadChar);
    }
    template <typename targetType, typename eventType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const eventType event, const __FlashStringHelper* payload) {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(F() payload)"));
      byte payloadLength = FSHlength(payload);
      char payloadChar[payloadLength + 1];
      memcpy_P(payloadChar, payload, payloadLength + 1);  //+1 for the null terminator
      return send(ethernetClient, target, port, event, payloadChar);
    }
    template <typename targetType, typename eventType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const eventType event, const String &payload) {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(String payload)"));
      byte stringLength = payload.length();
      char payloadChar[stringLength + 1];
      for (byte counter = 0; counter < stringLength; counter++) {
        payloadChar[counter] = payload[counter];  //I could probably just use c_str() instead but then I have to deal with the pointer
      }
      payloadChar[stringLength] = 0;
      return send(ethernetClient, target, port, event, payloadChar);
    }
    template <typename targetType, typename eventType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const eventType event, const IPAddress &payload) {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(IPAddress payload)"));
      char payloadChar[IPAddressLengthMax + 1];
      IPtoa(payload, payloadChar);
      return send(ethernetClient, target, port, event, payloadChar);
    }
    template <typename targetType, typename eventType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const eventType event, const double payload) {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(double payload)"));
      char payloadChar[doubleIntegerLengthMax + 1 + sendDoubleDecimalPlaces + 1];  //max integer length + decimal point + decimal places setting + null terminator
      dtostrf(payload, sendDoubleDecimalPlaces + 2, sendDoubleDecimalPlaces, payloadChar);
      return send(ethernetClient, target, port, event, payloadChar);
    }

    //convert event and payload
    template <typename targetType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, char event[], char payload[]) {
      ETHEREVENT_SERIAL.println(F("EtherEvent.send(char event, char payload)"));
      return send(ethernetClient, target, port, (const char*)event, (const char*)payload);  //Convert char to const char. Needed to fix ambiguous overload warning.
    }


    void setTimeout(const unsigned int timeoutInput);
    unsigned int getTimeout();
    boolean setPassword(const char passwordInput[]);
    boolean setPassword(const __FlashStringHelper* passwordInput);
    void setSendDoubleDecimalPlaces(const byte decimalPlaces);
    void IPtoa(const IPAddress &IP, char IPcharBuffer[]);
    byte FSHlength(const __FlashStringHelper * passwordInput);


  private:
    //used for the char array conversions
    static const byte uint16_tLengthMax = 5;  //5 digits
    static const byte int16_tLengthMax = 1 + uint16_tLengthMax;  //sign + 5 digits
    static const byte uint32_tLengthMax = 10;  //10 digits
    static const byte int32_tLengthMax = 1 + uint32_tLengthMax;  //sign + 10 digits
    static const byte IPAddressLengthMax = 3 + 1 + 3 + 1 + 3 + 1 + 3;  //4 x octet + 3 x dot
    static const byte doubleIntegerLengthMax = 40;  //sign + 39 digits max (-1000000000000000000000000000000000000000 gives me "floating constant exceeds range of 'double'" warning)

    static const byte cookieLengthMax = 8;

    const byte TCPEventsPayloadFormattingLength = 2;  //the length of one side of the formatting characters added to payloads entered in the payload field of TCPEvent's "Send an Event" action configuration([''])

    unsigned int timeout;  //default is set in begin() and the user can change the timeout via setTimeout()
    unsigned int availableEventSubmessageLengthMax;  //value set in begin()

    char* password;
    byte passwordLength;

    IPAddress fromIP;  //IP address of the last event sender
    byte eventLengthMax;
    char* receivedEvent;  //event buffer
    byte receivedEventLength;  //save the length so I don't have to do strlen everytime availableEvent() is called
    unsigned int payloadLengthMax;
    char* receivedPayload;  //payload buffer
    byte sendDoubleDecimalPlaces;
};

extern EtherEventClass EtherEvent;  //declare the class so it doesn't have to be done in the sketch
#endif

