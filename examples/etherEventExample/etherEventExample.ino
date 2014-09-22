//example script for the EtherEvent library - receives events and sends events periodically
#include <MD5.h>
#include <SPI.h>
#include <Ethernet.h>  //might not be needed because it is included in the EtherEvent library
#include "EtherEvent.h"  //include the EtherEvent library so its functions can be accessed
#include <Entropy.h>


//network parameters:
const IPAddress IPdevice(192, 168, 69, 104);  //pick any unused IP address for a static IP
byte mac[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05};  //this can be anything but must be unique on your network
EtherEvent etherEvent;  //create an instance of the EtherEvent class called etherEvent

const unsigned int etherEventSendInterval=7000;
const byte pinEthernetReset=4;

unsigned long sendTimeStamp=0;

void setup() {
  Serial.begin(9600);
  etherEvent.etherEventStart(mac,IPdevice);
}

void loop(){
  if(etherEvent.availableEvent()>0){
    Serial.print(F("Received Event="));
    while(etherEvent.availableEvent()>0){	//event received
      Serial.print(etherEvent.readEvent());
    }
    Serial.println();
    Serial.print(F("Received Payload="));
    while(etherEvent.availablePayload()>0){	//event received
      Serial.print(etherEvent.readPayload());
    }
    Serial.println();
    Serial.print(F("Received from IP="));
    Serial.println(etherEvent.senderIP());
  }

  if(millis()>sendTimeStamp+etherEventSendInterval){	//send event
    Serial.println(F("Attempting Event Send"));
    if(etherEvent.sendEvent(IPAddress(192,168,69,100), 1024, "123", "test payload")){  //send event to target IP address, port, event, payload
      Serial.println(F("Event Send Successful"));
      sendTimeStamp=millis();
    }
    else{
      Serial.println(F("Event Send Failed"));
    }
  }
} 
  
