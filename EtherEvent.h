//EtherEvent - Easy to use password authenticated network communication between Arduinos and EventGhost Network Event Sender/Receiver plugin, EventGhost TCPEvents plugin, Girder, and NetRemote http://github.com/per1234/EtherEvent
#ifndef EtherEvent_h
#define EtherEvent_h
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
    boolean send(EthernetClient &ethernetClient, const IPAddress sendIP, unsigned int sendPort, const char sendEvent[], const char sendPayload[] = "");
    void setTimeout(unsigned int timeoutNew);
    boolean setPassword(const char passwordInput[]);
    boolean setPassword(const __FlashStringHelper* passwordInput, const byte passwordLengthInput);
#ifdef __FLASH_H__
    boolean setPassword(const _FLASH_STRING passwordInput);
#endif
  private:
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
