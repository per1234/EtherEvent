//EtherEvent - Easy to use password authenticated network communication between Arduinos and EventGhost Network Event Sender/Receiver plugin, EventGhost TCPEvents plugin, Girder, and NetRemote http://github.com/per1234/EtherEvent
#ifndef EtherEvent_h
#define EtherEvent_h

#include <Arduino.h>
#include <SPI.h>
#include "Ethernet.h"
//#include "Flash.h"  //uncomment this line if you have the Flash library installed

class EtherEventClass {
  public:
    EtherEventClass();
    boolean begin(byte eventLengthMaxInput = 15, byte payloadLengthMaxInput = 100);  //these are the default max length values
    byte availableEvent(EthernetServer &ethernetServer);
    byte availablePayload();
    void readEvent(char eventBuffer[]);
    void readPayload(char payloadBuffer[]);
#ifdef ethernetclientwithremoteIP_h  //the include guard from the modified EthernetClient.h
    IPAddress senderIP();
#endif
    void flushReceiver();


    boolean send(EthernetClient &ethernetClient, const IPAddress target, unsigned int port, const char event[], const char payload[] = "");
    boolean send(EthernetClient &ethernetClient, const byte target[], unsigned int port, const char event[], const char payload[] = "");

    //convert event
    template <typename targetType>
    byte send(EthernetClient &ethernetClient, const targetType &target, unsigned int port, int16_t event, const char payload[] = "") {
      char eventChar[int16_tLengthMax + 1];
      itoa(event, eventChar, 10);
      return send(ethernetClient, target, port, eventChar, payload);
    }
    template <typename targetType>
    byte send(EthernetClient &ethernetClient, const targetType &target, unsigned int port, uint16_t event, const char payload[] = "") {
      char eventChar[uint16_tLengthMax + 1];
      sprintf_P(eventChar, PSTR("%u"), event);
      return send(ethernetClient, target, port, eventChar, payload);
    }
    template <typename targetType>
    byte send(EthernetClient &ethernetClient, const targetType &target, unsigned int port, int32_t event, const char payload[] = "") {
      char eventChar[int32_tLengthMax + 1];
      ltoa(event, eventChar, 10);
      return send(ethernetClient, target, port, eventChar, payload);
    }
    template <typename targetType>
    byte send(EthernetClient &ethernetClient, const targetType &target, unsigned int port, uint32_t event, const char payload[] = "") {
      char eventChar[uint32_tLengthMax + 1];
      ultoa(event, eventChar, 10);
      return send(ethernetClient, target, port, eventChar, payload);
    }
    template <typename targetType, typename payloadType>
    byte send(EthernetClient &ethernetClient, const targetType &target, unsigned int port, const __FlashStringHelper* event, byte eventLength, const payloadType payload) {
      char eventChar[eventLength + 1];
      memcpy_P(eventChar, event, eventLength + 1);  //+1 for the null terminator
      return send(ethernetClient, target, port, eventChar, payload);
    }

    //convert payload
    template <typename targetType, typename eventType>
    byte send(EthernetClient &ethernetClient, const targetType &target, unsigned int port, const eventType event, int16_t payload) {
      char payloadChar[int16_tLengthMax + 1];
      itoa(payload, payloadChar, 10);
      return send(ethernetClient, target, port, event, payloadChar);
    }
    template <typename targetType, typename eventType>
    byte send(EthernetClient &ethernetClient, const targetType &target, unsigned int port, const eventType event, uint16_t payload) {
      char payloadChar[uint16_tLengthMax + 1];
      sprintf_P(payloadChar, PSTR("%u"), payload);
      return send(ethernetClient, target, port, event, payloadChar);
    }
    template <typename targetType, typename eventType>
    byte send(EthernetClient &ethernetClient, const targetType &target, unsigned int port, const eventType event, int32_t payload) {
      char payloadChar[int32_tLengthMax + 1];
      ltoa(payload, payloadChar, 10);
      return send(ethernetClient, target, port, event, payloadChar);
    }
    template <typename targetType, typename eventType>
    byte send(EthernetClient &ethernetClient, const targetType &target, unsigned int port, const eventType event, uint32_t payload) {
      char payloadChar[uint32_tLengthMax + 1];
      ultoa(payload, payloadChar, 10);
      return send(ethernetClient, target, port, event, payloadChar);
    }
    template <typename targetType, typename eventType>
    byte send(EthernetClient &ethernetClient, const targetType &target, unsigned int port, eventType event, const __FlashStringHelper* payload, byte payloadLength) {
      char payloadChar[payloadLength + 1];
      memcpy_P(payloadChar, payload, payloadLength + 1);  //+1 for the null terminator
      return send(ethernetClient, target, port, event, payloadChar);
    }


    //convert F() event and payload
    template <typename targetType>
    byte send(EthernetClient &ethernetClient, const targetType &target, unsigned int port, const __FlashStringHelper* event, byte eventLength, const __FlashStringHelper* payload, byte payloadLength) {
      char eventChar[eventLength + 1];
      memcpy_P(eventChar, event, eventLength + 1);  //+1 for the null terminator

      char payloadChar[payloadLength + 1];
      memcpy_P(payloadChar, payload, payloadLength + 1);  //+1 for the null terminator

      return send(ethernetClient, target, port, eventChar, payloadChar);
    }

    //Flash templates
#ifdef __FLASH_H__
    template <typename targetType>
    byte send(EthernetClient &ethernetClient, const targetType &target, unsigned int port, const _FLASH_STRING event, const char payload[] = "") {
      byte stringLength = event.length();
      char eventChar[stringLength + 1];
      event.copy(eventChar, stringLength + 1, 0);  //+1 for null terminator
      return send(ethernetClient, target, port, eventChar, payload);
    }
    template <typename targetType, typename eventType>
    byte send(EthernetClient &ethernetClient, const targetType &target, unsigned int port, const eventType event, const _FLASH_STRING payload) {
      byte stringLength = payload.length();
      char payloadChar[stringLength + 1];
      payload.copy(payloadChar, stringLength + 1, 0);  //+1 for null terminator
      return send(ethernetClient, target, port, event, payloadChar);
    }
#endif


    void setTimeout(unsigned int timeoutNew);
    boolean setPassword(const char passwordInput[]);
    boolean setPassword(const __FlashStringHelper* passwordInput, const byte passwordLengthInput);
#ifdef __FLASH_H__
    boolean setPassword(const _FLASH_STRING passwordInput);
#endif
  private:
    const byte uint16_tLengthMax = 5;  //5 digits
    const byte int16_tLengthMax = 1 + uint16_tLengthMax;  //sign + 5 digits
    const byte uint32_tLengthMax = 10;  //10 digits
    const byte int32_tLengthMax = 1 + uint32_tLengthMax;  //sign + 10 digits

    void etherEventStop(EthernetClient &ethernetClient);

    unsigned int timeout;  //default is set in begin() and the user can change the timeout via setTimeout()
    char* password;
    byte eventLengthMax;
    char* receivedEvent;  //event buffer
    byte receivedEventLength;  //save the length so I don't have to do strlen everytime availableEvent() is called
    byte payloadLengthMax;
    char* receivedPayload;  //payload buffer
    IPAddress fromIP;  //IP address of the last event sender
    byte passwordLength;
    unsigned int availableEventSubmessageLengthMax;  //value set in begin()
};
extern EtherEventClass EtherEvent;  //declare the class so it doesn't have to be done in the sketch
#endif
