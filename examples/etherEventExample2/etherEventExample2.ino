//example script for the EtherEvent library - demonstrates more advanced usage
#include <MD5.h>
#include <SPI.h>
#include <Ethernet.h>
#include <Entropy.h>
#include <utility/w5100.h>  //used to set the timeout for the w5100 module this will not work if you use the ENC28J60 module
#include "EtherEvent.h"  //include the EtherEvent library so its functions can be accessed

EtherEvent etherEvent;  //create an instance of the EtherEvent class called etherEvent

const unsigned int etherEventSendInterval=4000;
unsigned long sendTimeStamp=0;

void setup() {
  Serial.begin(9600);
  //network parameters:
  const IPAddress IPdevice(192, 168, 69, 104);  //pick any unused IP address for a static IP
  byte mac[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05};  //this can be anything but must be unique on your network
  char password[]="password";  //password for event authentication
  etherEvent.begin(mac, IPdevice, password);
  W5100.setRetransmissionTime(0x07D0);  //used to set the timeout for the w5100 module this will not work if you use the ENC28J60 module
  W5100.setRetransmissionCount(1);  //used to set the timeout for the w5100 module this will not work if you use the ENC28J60 module
}

void loop(){
  if(byte length=etherEvent.availableEvent()){  //this checks for a new event and gets the length of the event including the null terminator
    Serial.print(F("Received Event length="));
    Serial.println(length);
    Serial.print(F("Received Event="));
    char event[length];  //declare the event buffer
    etherEvent.readEvent(event);  //read the event into the event buffer
    Serial.println(event);
    length=etherEvent.availablePayload();
    Serial.print(F("Received Payload length="));
    Serial.println(length);
    Serial.print(F("Received Payload="));
    char payload[length];
    etherEvent.readPayload(payload);
    Serial.println(payload);
    Serial.print(F("Received from IP="));
    Serial.println(etherEvent.senderIP());  //this will return 0.0.0.0 if you don't have the modified ethernet library and the flag set in EtherEvent.cpp
  }

  if(millis()>sendTimeStamp+etherEventSendInterval){	//send event
    Serial.println(F("Attempting Event Send"));
    if(etherEvent.send(IPAddress(192,168,69,100), 1024, "123", "test payload")){  //send event to target IP address, port, event, payload
      Serial.println(F("Event Send Successful"));
      sendTimeStamp=millis();
    }
    else{
      Serial.println(F("Event Send Failed"));
    }
  }
} 
  
