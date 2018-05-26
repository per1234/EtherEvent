// Used to test EtherEvent send and receive durations
// Use one of the Echo EventGhost trees found in the EtherEvent/extras/tests/EventGhost-trees folder

//#define ETHEREVENT_NO_AUTHENTICATION
//#define ETHEREVENT_FAST_SEND

//These libraries are required by EtherEvent:
#include <SPI.h>  //bundled with Arduino hardware packages
#include <Ethernet.h> //built-in library included with Arduino IDE
#if !defined(__ARDUINO_X86__)
#include <utility/w5100.h>  //Part of built-in Ethernet library included with Arduino IDE. Used for setting the W5x00 retransmission time and count.
#endif  //!defined(__ARDUINO_X86__)
#if !defined(ETHEREVENT_NO_AUTHENTICATION) && !defined(ESP8266)
#include <MD5.h>  //http://github.com/tzikis/ArduinoMD5
#endif  //!defined(ETHEREVENT_NO_AUTHENTICATION) && !defined(ESP8266)
#include <EtherEvent.h> //https://github.com/per1234/EtherEvent

//const char event[]="test";
//char event[]="test";
//long event=1234123;
//int event=1234;
#define event F("test")
//#define event "test

//const char payload[]="test payload";
//char payload[]="test payload";
//long payload=234555;
//int payload=1233;
#define payload F("test payload")
//#define payload "test payload"


//configuration parameters - modify these values to your desired settings
const boolean useDHCP = false;  //true==use DHCP to assign an IP address to the device, this will significantly increase memory usage. false==use static IP address.
static byte MACaddress[] = {0, 1, 2, 3, 4, 4};  //this can be anything you like as long as it's unique on your network
const IPAddress deviceIP = IPAddress(192, 168, 69, 104);  //IP address to use for the device. This can be any valid address on the network as long as it is unique. If you are using DHCP then this doesn't need to be configured.
const char password[] = "password";  //EtherEvent password. This must match the password set in EventGhost.
const unsigned int port = 1024;  //TCP port to receive events.

//timeout values - these can be tuned to your system to provide the most responsive operation. Too high of value will cause a long delay on failed Ethernet operations, too short will cause failed event send or receive.
//The default values used when these timeouts are not set are fairly conservative.
const byte etherEventTimeout = 20;  //(ms)The max time to wait for Ethernet communication.
const unsigned int W5x00timeout = 400;  //(0.1ms)used to set the timeout for the W5x00 module.
const byte W5x00retransmissionCount = 1;  //Retransmission count. 1 is the minimum value.

const unsigned int sendEventInterval = 300;  //(ms)Delay between sending the test events.
const IPAddress sendIP = IPAddress(192, 168, 69, 100);  //The IP address to send the test events to.
const unsigned int sendPort = 1024;  //The port to send the test events to.

EthernetServer ethernetServer(port);  //TCP port to receive on
EthernetClient ethernetClient;  //create the client object for Ethernet communication
static unsigned long sendTimeStamp;  //used by the example to periodically send an event


void setup() {
  Serial.begin(9600);  //the received event and other information will be displayed in your serial monitor while the sketch is running
  if (useDHCP == true) {
    Ethernet.begin(MACaddress);  //let the network assign an IP address
  }
  else {
    Ethernet.begin(MACaddress, deviceIP);  //use static IP address
  }
  ethernetServer.begin();  //begin the server that will be used to receive events
#if !defined(ETHEREVENT_NO_AUTHENTICATION)
  if (EtherEvent.begin() == false || EtherEvent.setPassword(password) == false) {  //set the password, maximum event length, and maximum payload length
#else  //!defined(ETHEREVENT_NO_AUTHENTICATION)
  if (EtherEvent.begin() == false) {  //set the password, maximum event length, and maximum payload length
#endif  //!defined(ETHEREVENT_NO_AUTHENTICATION)
    Serial.println(F("ERROR: Buffer size exceeds available memory, use smaller values."));
    while (true);  //abort execution of the rest of the program
  }

  EtherEvent.setTimeout(etherEventTimeout);  //set timeout duration
#if !defined(__ARDUINO_X86__)
  W5100.setRetransmissionTime(W5x00timeout);  //set the timeout for the W5x00 module.
  W5100.setRetransmissionCount(W5x00retransmissionCount);  //Retransmission Count - 1 is the minimum value
#endif  //!defined(__ARDUINO_X86__)
}


void loop() {
  const unsigned long preReceiveTimestamp = micros();
  if (int availableLength = EtherEvent.availableEvent(ethernetServer)) {  //this checks for a new event and gets the length of the event including the null terminator
    const unsigned long postReceiveTimestamp = micros();
    Serial.print("Event received, availableEvent() call duration: ");
    Serial.println(postReceiveTimestamp - preReceiveTimestamp);
    if (availableLength == -1) {
      Serial.println(F("\nAuthentication failed"));
    }
    else {
      EtherEvent.readEvent(); //test EtherEvent.readEvent()
      EtherEvent.readPayload(); //test EtherEvent.readPayload()

      //clear the receive buffer so more events can be received
      EtherEvent.flushReceiver();
    }
  }

  if (millis() - sendTimeStamp > sendEventInterval) {  //periodically send event
    sendTimeStamp = millis();  //reset the timestamp for the next event send
    Serial.println(F("\nAttempting event send"));
    unsigned long preSendTimestamp = micros();
    if (EtherEvent.send(ethernetClient, sendIP, sendPort, event, payload)) {  //send event to target IP address, port, event, payload
      unsigned long postSendTimestamp = micros();
      Serial.print(F("Event send successful, send() call duration: "));
      Serial.println(postSendTimestamp - preSendTimestamp);
    }
    else {
      Serial.println(F("Event send failed"));
    }
  }
}
