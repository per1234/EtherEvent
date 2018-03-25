// Used for testing EtherEvent.send() overloading in ETHEREVENT_FAST_SEND mode
// Use with extras/tests/EventGhost-trees/EchoTCPEventsAuthenticated.egtree or EchoNESR.egtree

//#define ETHEREVENT_NO_AUTHENTICATION  //this line must come before #include <EtherEvent.h> //https://github.com/per1234/EtherEvent
#define ETHEREVENT_FAST_SEND
#define TEST_BATCH 2

#include <SPI.h>  //bundled with Arduino hardware packages
#include <Ethernet.h> //built-in library included with Arduino IDE
#ifndef __ARDUINO_X86__
#include <utility/w5100.h>  //Part of built-in Ethernet library included with Arduino IDE. Used for setting the W5x00 retransmission time and count.
#endif //__ARDUINO_X86__

#if !defined(ETHEREVENT_NO_AUTHENTICATION) && !defined(ESP8266)
#include <MD5.h>  //http://github.com/tzikis/ArduinoMD5
#endif  //!defined(ETHEREVENT_NO_AUTHENTICATION) && !defined(ESP8266)

#include <EtherEvent.h> //https://github.com/per1234/EtherEvent

#ifdef __AVR__
#include <MemoryFree.h> //https://github.com/McNeight/MemoryFree
#endif  //__AVR__
#include <EtherEventTests.h>  //https://github.com/per1234/EtherEvent/tree/master/extras/tests/EtherEventTests

void setup() {
  etherEventTests();
}

void loop() {}
