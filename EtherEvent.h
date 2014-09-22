#ifndef EtherEvent_h
  #define EtherEvent_h
  #include "Arduino.h"
  #include <Ethernet.h>
  #include <Entropy.h>  

  class EtherEvent{
    public:
      EtherEvent();
      void etherEventStart(byte macAdd[],IPAddress deviceIP);
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
