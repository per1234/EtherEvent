//EtherEvent - Easy to use password authenticated network communication between Arduinos and EventGhost Network Event Sender/Receiver plugin, EventGhost TCPEvents plugin, Girder, and NetRemote
#ifndef EtherEvent_h
  #define EtherEvent_h
  #include <Arduino.h> 
  #include <SPI.h> 
  #include <Ethernet.h> 
  #include "MD5.h"

  const byte etherEvent_passwordLengthMax = 20; 
  const byte etherEvent_eventLengthMax = 15;  //Maximum event length
  const byte etherEvent_payloadLengthMax = 60;  //Maximum payload length

  class EtherEventClass{
    public:
      void begin(const char pass[]); 
      byte availableEvent(EthernetServer &ethernetServer); 
      byte availablePayload(); 
      void readEvent(char eventBuffer[]); 
      void readPayload(char payloadBuffer[]); 
      IPAddress senderIP(); 
      void flushReceiver(); 
      boolean send(EthernetClient &ethernetClient, const IPAddress sendIP, unsigned int sendPort, const char sendEvent[], const char sendPayload[]); 
      void setTimeout(unsigned int timeoutDurationNew, unsigned int timeoutListenNew); 
    private:
      void etherEventStop(EthernetClient &ethernetClient); 

      byte availableEventSubmessageLengthMax;  //non - const because I have to use max()(in begin())
      unsigned int timeout; 
      unsigned int listenTimeout; 
      char EEpassword[etherEvent_passwordLengthMax + 1]; 
      char receivedEvent[etherEvent_eventLengthMax + 1];  //event buffer
      char receivedPayload[etherEvent_payloadLengthMax + 1];  //payload buffer
      IPAddress fromIP;  //IP address of the last event sender      
  }; 
  extern EtherEventClass EtherEvent;  //declare the class so it doesn't have to be done in the sketch
#endif
