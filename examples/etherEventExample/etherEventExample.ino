//example script for the EtherEvent library
#include <MD5.h>
#include <SPI.h>
#include <Ethernet.h>
#include <Entropy.h>
#include "EtherEvent.h"  //include the EtherEvent library so its functions can be accessed

EtherEvent etherEvent;  //create an instance of the EtherEvent class called etherEvent

unsigned long sendTimeStamp=0;  //used by the example to periodically send an event

void setup() {
  Serial.begin(9600);
  //network parameters:
  IPAddress IPdevice(192, 168, 69, 104);  //pick any unused IP address for a static IP
  byte mac[] = {0x00, 0x01, 0x02, 0x03, 0x04, 4};  //this can be anything but must be unique on your network
  char password[]="password";  //password for event authentication
  etherEvent.begin(mac, IPdevice, password);  //initialize EtherEvent with the given network parameters
}

void loop(){
  if(byte length=etherEvent.availableEvent()){  //this checks for a new event and gets the length of the event including the null terminator
    Serial.print(F("Received Event length="));
    Serial.println(length);
    Serial.print(F("Received Event="));
    char event[length];  //declare the event buffer
    etherEvent.readEvent(event);  //read the event into the event buffer
    Serial.println(event);  //now the event is in your buffer
    length=etherEvent.availablePayload();  //the payload system is the same as the event system
    Serial.print(F("Received Payload length="));
    Serial.println(length);
    Serial.print(F("Received Payload="));
    char payload[length];
    etherEvent.readPayload(payload);
    Serial.println(payload);
  }

  if(millis()>sendTimeStamp+4000){  //periodically send event
    sendTimeStamp=millis();
    Serial.println(F("Attempting Event Send"));
    if(etherEvent.send(IPAddress(192,168,69,104), 1024, "123", "test payload")){  //send event to target IP address, port, event, payload
      Serial.println(F("Event Send Successful"));
    }
    else{
      Serial.println(F("Event Send Failed"));
    }
  }
}
