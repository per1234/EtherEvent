// Use for testing EtherEvent.availableEvent() overloading

//#define ETHEREVENT_NO_AUTHENTICATION  //this line must come before #include <EtherEvent.h>
#define ETHEREVENT_FAST_SEND

#include <SPI.h>
#include <Ethernet.h>
#ifndef __ARDUINO_X86__
#include <utility/w5100.h>  //Used for setting the W5x00 retransmission time and count.
#endif //__ARDUINO_X86__
#if !defined(ETHEREVENT_NO_AUTHENTICATION) && !defined(ESP8266)
#include <MD5.h>
#endif  //!defined(ETHEREVENT_NO_AUTHENTICATION) && !defined(ESP8266)
#include <EtherEvent.h>


//configuration parameters - modify these values to your desired settings
const boolean useDHCP = false;  //true==use DHCP to assign an IP address to the device, this will significantly increase memory usage. false==use static IP address.
byte MACaddress[] = {0, 1, 2, 3, 4, 4};  //this can be anything you like as long as it's unique on your network
const IPAddress deviceIP = IPAddress(192, 168, 69, 104);  //IP address to use for the device. This can be any valid address on the network as long as it is unique. If you are using DHCP then this doesn't need to be configured.
const char password_const_char_array[] = "password";  //EtherEvent password. This must match the password set in EventGhost.
char password_char_array[] = "password";  //EtherEvent password. This must match the password set in EventGhost.
#define password_string_literal "password"
#define password___FlashStringHelper F("password")
const unsigned int port = 1024;  //TCP port to receive events.
const byte maxReceivedEventLength = 12;  //Maximum event length to receive. Longer entries will be truncated to this length. If this parameter is not passed then the default will be used.
const byte maxReceivedPayloadLength = 25;  //Maximum payload length to receive. Longer entries will be truncated to this length. If this parameter is not passed then the default will be used.

//timeout values - these can be tuned to your system to provide the most responsive operation. Too high of value will cause a long delay on failed Ethernet operations, too short will cause failed event send or receive.
//The default values used when these timeouts are not set are fairly conservative.
const byte etherEventTimeout = 20;  //(ms)The max time to wait for Ethernet communication.
const unsigned int W5x00timeout = 400;  //(0.1ms)used to set the timeout for the W5x00 module.
const byte W5x00retransmissionCount = 1;  //Retransmission count. 1 is the minimum value.

const unsigned int sendEventInterval = 4000;  //(ms)Delay between sending the test events.
const IPAddress sendIP = IPAddress(192, 168, 69, 100);  //The IP address to send the test events to.
const unsigned int sendPort = 1024;  //The port to send the test events to.


EthernetServer ethernetServer(port);  //TCP port to receive on
EthernetClient ethernetClient;  //create the client object for Ethernet communication
unsigned long sendTimestamp;  //used by the example to periodically send an event
byte availableEventTest;


void setup() {
  Serial.begin(9600);  //the received event and other information will be displayed in your serial monitor while the sketch is running
  if (useDHCP == true) {
    Ethernet.begin(MACaddress);  //let the network assign an IP address
  }
  else {
    Ethernet.begin(MACaddress, deviceIP);  //use static IP address
  }
  ethernetServer.begin();  //begin the server that will be used to receive events
#ifndef ETHEREVENT_NO_AUTHENTICATION
  if (EtherEvent.begin(maxReceivedEventLength, maxReceivedPayloadLength) == false || EtherEvent.setPassword(password_string_literal) == false) {  //set the password, maximum event lenght, and maximum payload length
#else  //ETHEREVENT_NO_AUTHENTICATION
  if (EtherEvent.begin(maxReceivedEventLength, maxReceivedPayloadLength) == false) {  //set the password, maximum event lenght, and maximum payload length
#endif  //ETHEREVENT_NO_AUTHENTICATION
    Serial.println(F("ERROR: Buffer size exceeds available memory, use smaller values."));
    while (true);  //abort execution of the rest of the program
  }

  EtherEvent.setTimeout(etherEventTimeout);  //set timeout duration
#ifndef __ARDUINO_X86__
  W5100.setRetransmissionTime(W5x00timeout);  //set the timeout for the W5x00 module.
  W5100.setRetransmissionCount(W5x00retransmissionCount);  //Retransmission Count - 1 is the minimum value
#endif //__ARDUINO_X86__
}

void printEvent(int8_t availableLength) {
  if (availableLength == -1) {
    Serial.println(F("\nAuthentication failed"));
  }
  else {
    Serial.print(F("Received event length="));
    Serial.println(EtherEvent.availableEvent());  //this tests the use of EtherEvent.availableEvent() with no arguments
    char event[availableLength];  //create the event buffer of the correct size
    EtherEvent.readEvent(event);  //read the event into the event buffer
    Serial.print(F("Received event: "));
    Serial.println(event);  //now the event is in your buffer
    availableLength = EtherEvent.availablePayload();  //receiving the payload works the same as the event
    Serial.print(F("Received payload length="));
    Serial.println(availableLength);
    if (availableLength > 0) {
      char payload[availableLength];
      EtherEvent.readPayload(payload);
      Serial.print(F("Received payload: "));
      Serial.println(payload);
    }
#ifdef ethernetclientwithremoteIP_h  //must have the modified Ethernet library installed for this function to be available
    Serial.print(F("Received from IP: "));
    Serial.println(EtherEvent.senderIP());
#endif  //ethernetclientwithremoteIP_h
  }
}


void loop() {
  // Run availableEvent() tests
  switch (availableEventTest) {
    case 0:
      if (int8_t availableLength = EtherEvent.availableEvent(ethernetServer)) {  //this checks for a new event and gets the length of the event including the null terminator
#ifndef ETHEREVENT_NO_AUTHENTICATION
        ++availableEventTest;
#endif  //ETHEREVENT_NO_AUTHENTICATION
        Serial.print(F("\nEtherEvent.availableEvent(ethernetServer) test"));
        printEvent(availableLength);
      }
      break;
#ifndef ETHEREVENT_NO_AUTHENTICATION
    case 1:
      if (byte availableLength = EtherEvent.availableEvent(ethernetServer, 42)) {  //this checks for a new event and gets the length of the event including the null terminator
        ++availableEventTest;
        Serial.print(F("\nEtherEvent.availableEvent(ethernetServer, cookie) test"));
        printEvent(availableLength);
      }
      break;
    case 2:
      if (byte availableLength = EtherEvent.availableEvent(ethernetServer, 42, password_char_array)) {  //this checks for a new event and gets the length of the event including the null terminator
        ++availableEventTest;
        Serial.print(F("\nEtherEvent.availableEvent(ethernetServer, cookie, password_char_array) test"));
        printEvent(availableLength);
      }
      break;
    case 3:
      if (byte availableLength = EtherEvent.availableEvent(ethernetServer, 42, password_string_literal)) {  //this checks for a new event and gets the length of the event including the null terminator
        ++availableEventTest;
        Serial.print(F("\nEtherEvent.availableEvent(ethernetServer, cookie, password_string_literal) test"));
        printEvent(availableLength);
      }
      break;
    case 4:
      if (byte availableLength = EtherEvent.availableEvent(ethernetServer, 42, password___FlashStringHelper)) {  //this checks for a new event and gets the length of the event including the null terminator
        availableEventTest = 0;
        Serial.print(F("\nEtherEvent.availableEvent(ethernetServer, cookie, password___FlashStringHelper) test"));
        printEvent(availableLength);
      }
      break;
#endif  //ETHEREVENT_NO_AUTHENTICATION
  }


  if (millis() - sendTimestamp > sendEventInterval) {  //periodically send event
    sendTimestamp = millis();  //reset the Timestamp for the next event send
    Serial.println(F("\nAttempting event send"));
    if (EtherEvent.send(ethernetClient, sendIP, sendPort, F("test"), F("test payload"))) {  //send event to target IP address, port, event, payload
      Serial.println(F("Event send successful"));
    }
    else {
      Serial.println(F("Event send failed"));
    }
  }
}
