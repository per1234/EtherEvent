//example script for the EtherEvent library - demonstrates advanced features
#include <MD5.h>  //these libraries are required by EtherEvent
#include <SPI.h>
#include <Ethernet.h>
#include <Entropy.h>
#include "EtherEvent.h"  //include the EtherEvent library so its functions can be accessed
#include <utility/w5100.h>  //for setting the ethernet send connect timeout

EtherEvent etherEvent;  //create an instance of the EtherEvent class called etherEvent

unsigned long sendTimeStamp=0;  //used by the example to periodically send an event

void setup(){
  Serial.begin(9600);  //the received event and other information will be displayed in your serial monitor while the sketch is running
  byte mac[]={0,1,2,3,4,4};  //this can be anything you like, but must be unique on your network
  etherEvent.begin(mac, IPAddress(192, 168, 69, 104), "password");  //initialize EtherEvent with the given network parameters
  W5100.setRetransmissionTime(0x07D0);  //used to set the timeout for the w5100 module this will not work if you are using ENC28J60 instead of W5100
  W5100.setRetransmissionCount(1);  //Retransmission Count 1 is the minimum value
}

void loop(){
  if(byte length=etherEvent.availableEvent()){  //this checks for a new event and gets the length of the event including the null terminator
    Serial.print(F("Received event length="));
    Serial.println(length);
    char event[length];  //create the event buffer of the correct size
    etherEvent.readEvent(event);  //read the event into the event buffer
    Serial.print(F("Received event: "));
    Serial.println(event);  //now the event is in your buffer
    length=etherEvent.availablePayload();  //receiving the payload works the same as the event
    Serial.print(F("Received payload length="));
    Serial.println(length);
    char payload[length];
    etherEvent.readPayload(payload);
    Serial.print(F("Received payload: "));
    Serial.println(payload);
    Serial.print(F("Received from IP: "));
    Serial.println(etherEvent.senderIP());  //this will return 0.0.0.0 if you don't have the modified ethernet library and the flag set in EtherEvent.cpp
  }

  if(millis()>sendTimeStamp+4000){  //periodically send event
    sendTimeStamp=millis();  //reset the timestamp for the next event send
    Serial.println(F("Attempting event send"));
    if(etherEvent.send(IPAddress(192,168,69,100), 1024, "123", "test payload")){  //send event to target IP address, port, event, payload
      Serial.println(F("Event send successful"));
    }
    else{
      Serial.println(F("Event send failed"));
    }
  }
} 
  
