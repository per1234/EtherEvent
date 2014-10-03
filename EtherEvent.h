//EtherEvent - Easy to use password authenticated network communication between Arduinos and EventGhost Network Event Sender/Receiver plugin, EventGhost TCPEvents plugin, Girder, and NetRemote
#ifndef EtherEvent_h
  #define EtherEvent_h
  #include "Arduino.h"
  #include <MD5.h>  //http://github.com/tzikis/ArduinoMD5
  #include <SPI.h>
  #include <Ethernet.h>
  #include <Entropy.h>  

  class EtherEvent{
    public:
      EtherEvent();
      void begin(byte macAdd[], const IPAddress deviceIP, const char pass[]);
      byte availableEvent();
      byte availablePayload();
      void readEvent(char eventBuffer[]);
      void readPayload(char payloadBuffer[]);
      void flushReceiver();
      byte send(const IPAddress sendIP, unsigned int sendPort, const char sendEvent[], const char sendPayload[]);
      IPAddress senderIP();
    private:
      void etherEventStop(EthernetClient &client);
  };
#endif
