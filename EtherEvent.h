//EtherEvent - Easy to use password authenticated network communication between Arduinos and EventGhost Network Event Sender/Receiver plugin, EventGhost TCPEvents plugin, Girder, and NetRemote
#ifndef EtherEvent_h
  #define EtherEvent_h
  #include "Arduino.h"
  #include <Ethernet.h>
  #include <Entropy.h>  

  class EtherEvent{
    public:
      EtherEvent();
      void etherEventStart(byte macAdd[],IPAddress deviceIP, char password[]);
      byte availableEvent();
      byte availablePayload();
      char readEvent();
      char readPayload();
      void flushReceiver();
      byte sendEvent(IPAddress sendIP, unsigned int sendPort, char sendEvent[],char sendPayload[]);
      IPAddress senderIP();
    private:
      void sendEventStop();
  };
#endif
