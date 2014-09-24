//example script for the EtherEvent library - demonstrates more advanced usage
#include <MD5.h>
#include <SPI.h>
#include <Ethernet.h>  //might not be needed because it is included in the EtherEvent library
#include "EtherEvent.h"  //include the EtherEvent library so its functions can be accessed
#include <Entropy.h>
#include <utility/w5100.h>


//network parameters:
const IPAddress IPdevice(192, 168, 69, 104);  //pick any unused IP address for a static IP
byte mac[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05};  //this can be anything but must be unique on your network
char password[]="password";  //password for event authentication
EtherEvent etherEvent;  //create an instance of the EtherEvent class called etherEvent

const unsigned int etherEventSendInterval=4000;
unsigned long sendTimeStamp=0;

void setup() {
  Serial.begin(9600);
  etherEvent.etherEventStart(mac, IPdevice, password);
  W5100.setRetransmissionTime(0x07D0);
  W5100.setRetransmissionCount(1);  
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
    Serial.println(etherEvent.senderIP());  //this will return 0.0.0.0 if you don't have the modified ethernet library and the flag set in EtherEvent.cpp
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
  
