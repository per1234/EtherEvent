//EtherEvent - Easy to use password authenticated network communication between Arduinos and EventGhost Network Event Sender/Receiver plugin, EventGhost TCPEvents plugin, Girder, and NetRemote http://github.com/per1234/EtherEvent
#ifndef EtherEvent_h
#define EtherEvent_h
#include <SPI.h>
#include <Ethernet.h>

//user configuration parameters
const byte etherEvent_passwordLengthMax = 20;
const byte etherEvent_eventLengthMax = 15;  //Maximum event length, maximum value is 254
const byte etherEvent_payloadLengthMax = 100;  //Maximum payload length, maximum value is 254

class EtherEventClass {
  public:
    void begin(const char pass[]);
    byte availableEvent(EthernetServer &ethernetServer);
    byte availablePayload();
    void readEvent(char eventBuffer[]);
    void readPayload(char payloadBuffer[]);
    IPAddress senderIP();
    void flushReceiver();
    boolean send(EthernetClient &ethernetClient, const IPAddress sendIP, unsigned int sendPort, const char sendEvent[], const char sendPayload[]);
    void setTimeout(unsigned int timeoutNew);
  private:
    void etherEventStop(EthernetClient &ethernetClient);

    unsigned int timeout;  //default is set in begin() and the user can change the timeout via setTimeout()
    char password[etherEvent_passwordLengthMax + 1];  //password - this is set in begin()
    char receivedEvent[etherEvent_eventLengthMax + 1];  //event buffer
    byte receivedEventLength;  //save the length so I don't have to do strlen everytime availableEvent() is called
    char receivedPayload[etherEvent_payloadLengthMax + 1];  //payload buffer
    IPAddress fromIP;  //IP address of the last event sender
    byte passwordLength;
};
extern EtherEventClass EtherEvent;  //declare the class so it doesn't have to be done in the sketch
#endif
