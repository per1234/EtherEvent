// EtherEvent - Easy to use password authenticated network communication between Arduinos and EventGhost Network Event Sender/Receiver plugin, EventGhost TCPEvents plugin, Girder, and NetRemote http://github.com/per1234/EtherEvent
#ifndef EtherEvent_h
#define EtherEvent_h

#include <Arduino.h>
#include <SPI.h>
#include "Ethernet.h"
#include "MD5.h"

#define ETHEREVENT_DEBUG false  //(false == serial debug output off,  true == serial debug output on)The serial debug output will increase memory usage and communication latency so only enable when needed.
#define ETHEREVENT_SERIAL if(ETHEREVENT_DEBUG)Serial  //I have to use a different name for Serial in this file otherwise the debug statement control also affects any other file that includes this file.

#define ETHEREVENT_MAGIC_WORD "quintessence\n\r"  //word used to trigger the cookie send from the receiver. I had to #define this instead of const because find() didn't like the const
#define ETHEREVENT_ACCEPT_MESSAGE "accept\n"  //authentication success message. I had to #define this instead of const because find() didn't like the const

namespace etherEvent {
const char payloadSeparator[] = "payload ";  //indicates payload
const char closeMessage[] = "close\n";  //sender sends this message to the receiver to close the connection
}

class EtherEventClass {
  public:
    EtherEventClass();
    boolean begin(const byte eventLengthMaxInput = 15, const byte payloadLengthMaxInput = 100);  //these are the default max length values
    byte availableEvent(EthernetServer &ethernetServer, long cookieInput = false);
    byte availablePayload();
    void readEvent(char eventBuffer[]);
    void readPayload(char payloadBuffer[]);
#ifdef ethernetclientwithremoteIP_h  //the include guard from the modified EthernetClient.h
    IPAddress senderIP();
#endif
    void flushReceiver();

    template <typename target_t, typename event_t>
    boolean send(EthernetClient &ethernetClient, const target_t target, const unsigned int port, const event_t event) {
      Serial.println(F("EtherEvent.send(no payload)"));
      noPayload = true;  //set the flag to indicate there is no payload
      return send(ethernetClient, target, port, event, false);
    }
    template <typename event_t, typename payload_t>
    boolean send(EthernetClient &ethernetClient, const byte target[], const unsigned int port, const event_t event, const payload_t payload) {
      Serial.println(F("EtherEvent.send(byte array IP address)"));
      IPAddress targetIP = IPAddress(target[0], target[1], target[2], target[3]);
      return send(ethernetClient, targetIP, port, event, payload);
    }
    template <typename event_t, typename payload_t>
    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const event_t event, const payload_t payload) {
      Serial.println(F("EtherEvent.send: attempting connection"));
      Serial.print(F("EtherEvent.send: target: "));
      Serial.println(target);
      Serial.print(F("EtherEvent.send: port: "));
      Serial.println(port);
      Serial.print(F("EtherEvent.send: event: "));
      Serial.println(event);
      Serial.print(F("EtherEvent.send: payload: "));
      Serial.println(payload);
      ethernetClient.setTimeout(timeout);  //timeout on read/readUntil/find/findUntil/etc
      byte eventSuccess = false;
      if (ethernetClient.connect(target, port)) {  //connected to receiver
        Serial.println(F("EtherEvent.send: connected, sending magic word"));
        ethernetClient.print(F(ETHEREVENT_MAGIC_WORD));  //send the magic word to the receiver so it will send the cookie

        char cookiePassword[cookieLengthMax + 1 + passwordLength + 1];  //cookie,  password separator(:),  password,  null terminator
        if (byte bytesRead = ethernetClient.readBytesUntil(10, cookiePassword, cookieLengthMax)) {  //get the cookie
          cookiePassword[bytesRead] = 0;
          strcat(cookiePassword, ":");  //add the password separator to the cookie
          strcat(cookiePassword, password);  //add password to the cookie
          Serial.print(F("EtherEvent.send: cookiePassword: "));
          Serial.println(cookiePassword);
          unsigned char* cookiePasswordHash = MD5::make_hash(cookiePassword);
          char *cookiePasswordMD5 = MD5::make_digest(cookiePasswordHash,  16);
          free(cookiePasswordHash);
          Serial.print(F("EtherEvent.send: hashWordMD5: "));
          Serial.println(cookiePasswordMD5);
          ethernetClient.print(cookiePasswordMD5);  //send the MD5 of the hashword
          ethernetClient.write(10);  //newline
          free(cookiePasswordMD5);

          if (ethernetClient.find((char*)ETHEREVENT_ACCEPT_MESSAGE) == true) {  //authentication successful - the (char*) thing is to get rid of the "warning: deprecated conversion from string constant to ‘char*’" compiler warning
            if (noPayload == false) {  //check if there is a payload
              ethernetClient.print(etherEvent::payloadSeparator);
              ethernetClient.print(payload);
              ethernetClient.write(10);  //newline
            }
            noPayload = false;  //reset the flag for the next event send
            ethernetClient.print(event);  //transmit event
            ethernetClient.write(10);  //newline
            eventSuccess = true;
          }
        }
        ethernetClient.print(etherEvent::closeMessage);  //tell the receiver to close
        ethernetClient.stop();
        Serial.println(F("EtherEvent.send: connection closed"));
      }
      else {
        Serial.println(F("EtherEvent.send: connection failed"));
      }
      return eventSuccess;  //send finished
    }

    void setTimeout(const unsigned int timeoutInput);
    unsigned int getTimeout();
    boolean setPassword(const char passwordInput[]);
    boolean setPassword(const __FlashStringHelper* passwordInput, const byte passwordLengthInput);
#ifdef __FLASH_H__
    boolean setPassword(const _FLASH_STRING &passwordInput);
#endif
  private:
    //used for the convesions to char array
    static const byte uint16_tLengthMax = 5;  //5 digits
    static const byte int16_tLengthMax = 1 + uint16_tLengthMax;  //sign + 5 digits
    static const byte uint32_tLengthMax = 10;  //10 digits
    static const byte int32_tLengthMax = 1 + uint32_tLengthMax;  //sign + 10 digits

    static const byte cookieLengthMax = 8;  //EtherEvent's cookie is a long sent in hexadecimal which is 8 digits max,  EventGhost's cookie is 4 digits,  but it can be set larger if needed

    unsigned int timeout;  //default is set in begin() and the user can change the timeout via setTimeout()
    unsigned int availableEventSubmessageLengthMax;  //value set in begin()

    char* password;
    byte passwordLength;
    boolean noPayload = false;

    IPAddress fromIP;  //IP address of the last event sender
    byte eventLengthMax;
    char* receivedEvent;  //event buffer
    byte receivedEventLength;  //save the length so I don't have to do strlen everytime availableEvent() is called
    byte payloadLengthMax;
    char* receivedPayload;  //payload buffer
};

extern EtherEventClass EtherEvent;  //declare the class so it doesn't have to be done in the sketch
#endif

