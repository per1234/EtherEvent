// EtherEvent - Easy to use password authenticated network communication between Arduinos and EventGhost Network Event Sender/Receiver plugin, EventGhost TCPEvents plugin, Girder, and NetRemote http://github.com/per1234/EtherEvent
#ifndef EtherEvent_h
#define EtherEvent_h

#include <Arduino.h>
#include <Ethernet.h>
#include "MD5.h"


#define ETHEREVENT_DEBUG false  //(false == serial debug output off,  true == serial debug output on)The serial debug output will increase memory usage and communication latency so only enable when needed.
#define ETHEREVENT_SERIAL if(ETHEREVENT_DEBUG)Serial  //I have to use a different name for Serial in this file otherwise the debug statement control also affects any other file that includes this file.


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

    boolean send(EthernetClient &ethernetClient, const IPAddress &target, const unsigned int port, const char event[], const char payload[] = "");
    boolean send(EthernetClient &ethernetClient, const byte target[], const unsigned int port, const char event[], const char payload[] = "");

    //convert event
    template <typename targetType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, char event[], const char payload[]) {
      return send(ethernetClient, target, port, (const char*)event, payload);  //Convert char to const char. Needed to fix ambiguous overload warning.
    }
    template <typename targetType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const int8_t event, const char payload[] = "") {
      return send(ethernetClient, target, port, (const int)event, payload);  //Convert event to int. Needed to fix ambiguous overload warning.
    }
    template <typename targetType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const byte event, const char payload[] = "") {
      return send(ethernetClient, target, port, (const int)event, payload);  //Convert event to int. Needed to fix ambiguous overload warning.
    }
    template <typename targetType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const int16_t event, const char payload[] = "") {
      char eventChar[int16_tLengthMax + 1];
      itoa(event, eventChar, 10);
      return send(ethernetClient, target, port, (const char*)eventChar, payload);
    }
    template <typename targetType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const uint16_t event, const char payload[] = "") {
      char eventChar[uint16_tLengthMax + 1];
      utoa(event, eventChar, 10);
      return send(ethernetClient, target, port, (const char*)eventChar, payload);
    }
    template <typename targetType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const int32_t event, const char payload[] = "") {
      char eventChar[int32_tLengthMax + 1];
      ltoa(event, eventChar, 10);
      return send(ethernetClient, target, port, (const char*)eventChar, payload);
    }
    template <typename targetType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const uint32_t event, const char payload[] = "") {
      char eventChar[uint32_tLengthMax + 1];
      ultoa(event, eventChar, 10);
      return send(ethernetClient, target, port, (const char*)eventChar, payload);
    }
    template <typename targetType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const __FlashStringHelper* event, const char payload[] = "") {
      byte eventLength = FSHlength(event);
      char eventChar[eventLength + 1];
      memcpy_P(eventChar, event, eventLength + 1);  //+1 for the null terminator
      return send(ethernetClient, target, port, (const char*)eventChar, payload);
    }
    template <typename targetType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const String &event, const char payload[] = "") {
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
      char eventChar[IPAddressLengthMax + 1];
      IPtoa(event, eventChar);
      return send(ethernetClient, target, port, (const char*)eventChar, payload);
    }

    //convert payload
    template <typename targetType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const char event[], char payload[]) {
      return send(ethernetClient, target, port, event, (const char*)payload);  //Convert char to const char. Needed to fix ambiguous overload warning.
    }
    template <typename targetType, typename eventType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const eventType event, const int16_t payload) {
      char payloadChar[int16_tLengthMax + 1];
      itoa(payload, payloadChar, 10);
      return send(ethernetClient, target, port, event, payloadChar);
    }
    template <typename targetType, typename eventType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const eventType event, const uint16_t payload) {
      char payloadChar[uint16_tLengthMax + 1];
      utoa(payload, payloadChar, 10);
      return send(ethernetClient, target, port, event, payloadChar);
    }
    template <typename targetType, typename eventType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const eventType event, const int32_t payload) {
      char payloadChar[int32_tLengthMax + 1];
      ltoa(payload, payloadChar, 10);
      return send(ethernetClient, target, port, event, payloadChar);
    }
    template <typename targetType, typename eventType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const eventType event, const uint32_t payload) {
      char payloadChar[uint32_tLengthMax + 1];
      ultoa(payload, payloadChar, 10);
      return send(ethernetClient, target, port, event, payloadChar);
    }
    template <typename targetType, typename eventType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const eventType event, const __FlashStringHelper* payload) {
      byte payloadLength = FSHlength(payload);
      char payloadChar[payloadLength + 1];
      memcpy_P(payloadChar, payload, payloadLength + 1);  //+1 for the null terminator
      return send(ethernetClient, target, port, event, payloadChar);
    }
    template <typename targetType, typename eventType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, const eventType event, const String &payload) {
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
      char payloadChar[IPAddressLengthMax + 1];
      IPtoa(payload, payloadChar);
      return send(ethernetClient, target, port, event, payloadChar);
    }

    //convert event and payload
    template <typename targetType>
    boolean send(EthernetClient &ethernetClient, const targetType &target, const unsigned int port, char event[], char payload[]) {
      return send(ethernetClient, target, port, (const char*)event, (const char*)payload);  //Convert char to const char. Needed to fix ambiguous overload warning.
    }


    void setTimeout(const unsigned int timeoutInput);
    unsigned int getTimeout();
    boolean setPassword(const char passwordInput[]);
    boolean setPassword(const __FlashStringHelper* passwordInput);
    byte FSHlength(const __FlashStringHelper * passwordInput);
    void IPtoa(const IPAddress & IP, char IPcharBuffer[]);


  private:
    //used for the convesions to char array
    static const byte uint16_tLengthMax = 5;  //5 digits
    static const byte int16_tLengthMax = 1 + uint16_tLengthMax;  //sign + 5 digits
    static const byte uint32_tLengthMax = 10;  //10 digits
    static const byte int32_tLengthMax = 1 + uint32_tLengthMax;  //sign + 10 digits
    static const byte IPAddressLengthMax = 3 + 1 + 3 + 1 + 3 + 1 + 3;  //4 x octet + 3 x dot


    unsigned int timeout;  //default is set in begin() and the user can change the timeout via setTimeout()
    unsigned int availableEventSubmessageLengthMax;  //value set in begin()

    char* password;
    byte passwordLength;

    IPAddress fromIP;  //IP address of the last event sender
    byte eventLengthMax;
    char* receivedEvent;  //event buffer
    byte receivedEventLength;  //save the length so I don't have to do strlen everytime availableEvent() is called
    byte payloadLengthMax;
    char* receivedPayload;  //payload buffer
};

extern EtherEventClass EtherEvent;  //declare the class so it doesn't have to be done in the sketch
#endif

