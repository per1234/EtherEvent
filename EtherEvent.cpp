#include "Arduino.h"  //not needed?
#include "EtherEvent.h"
#include <MD5.h>
#include <SPI.h>
#include <Ethernet.h>
#include <MemoryFree.h>  //debug only
#include <Math.h>  //added to make it compile

#define DEBUG 0 // flag to turn on/off debugging
#define Serial if(DEBUG)Serial
///#define REMOTEIP //is the ethernet library modified to return the client IP address via the remoteIP function

const char magicWord[] = "quintessence";  //word used to trigger the cookie send from the receiver
const char password[] = "password";  //the password used in the Network Event Sender/Receiver plugin configuration in EventGhost
const char acceptMessage[] = "accept";  //authentication success message
const char payloadFirst[] = "payload withoutRelease";  //eg sends this every time and EtherEvent filters it out
const char payloadSeparator[] = "payload ";  //indicates payload
const char closeMessage[] = "close";  //sender sends this message to the receiver to close the connection
const char TCPEventsMD5separator[]="TCPEvents";  //TCPEvents adds the separator before the MD5
const byte cookieLengthMax=5;  //EtherEvent sends a 5 digit cookie, eg seems to be a 4 digit cookie(socket), but it can be set larger if needed
const byte eventLengthMax=3;  //Maximum event length
const byte payloadLengthMax=60;  //Maximum payload length
const unsigned int timeoutDuration=1300;  //max blocking time of the availableEvent or sendEvent functions
const byte listenTimeoutDuration=1;  //max time to wait for another char to be available from the client.read function - it was getting ahead of the stream and stopping before getting the whole message event though I send the full string all at once
const int receivePort = 1024;  //TCP port to receive on


EthernetServer etherEventServer = EthernetServer(receivePort);
EthernetClient etherEventClient;

char receivedEvent[eventLengthMax+1];  //event buffer
char receivedPayload[payloadLengthMax+1];  //payload buffer
byte readEventCount=0;  //the next char of the received event string to be read
byte readPayloadCount=0;
IPAddress fromIP(0,0,0,0);  //IP address of the last event sender
//byte availableEventFlag=0;  //get rid of this global

EtherEvent::EtherEvent(){
}

void EtherEvent::etherEventStart(byte macAdd[],IPAddress deviceIP){
  Serial.println(F("etherEventStart: start"));
  Ethernet.begin(macAdd,deviceIP);
  etherEventServer.begin();
  Serial.println(F("etherEventStart: finished"));  
}

byte EtherEvent::availableEvent(){  //checks for senders, connects, authenticates, reads the event and payload into the buffer
  byte eventLength=strlen(receivedEvent);
  if(eventLength>0){  //there is already an available event
    if(readEventCount>eventLength){  //avoid negative overflow - this shouldn't be needed
      Serial.println(F("availableEvent: readEventCount>length ----------------------------------------------------------!"));
      return 0;
    }
    return eventLength+1 - readEventCount;
  }    
  if(availablePayload()>0){  //don't get another event until the last is fully read or flushed
    return 0;
  }
  else{  //check for an available event to receive
    if(EthernetClient etherEventClient = etherEventServer.available() ){  //connect to the client
      receivedPayload[0]=0;  //reset so it won't bleed through if there is no payload on subsequent events
      byte availableEventFlag=1;
      Serial.println(F("availableEvent: connected"));
      char cookieChar[6];  //initializing here because it needs to be used in the cookie send if and the hashword verify if and if it's inside the while then it will be reinitialized on every loop
      byte maxInput=strlen(payloadSeparator) + payloadLengthMax;  //payload message length
      byte messageLengthMax=max(maxInput,32);  //32 is the MD5
      maxInput=strlen(payloadFirst);
      messageLengthMax=max(messageLengthMax,maxInput);
      maxInput=strlen(magicWord);
      messageLengthMax=max(messageLengthMax,maxInput);
      maxInput=strlen(closeMessage);
      messageLengthMax=max(messageLengthMax,maxInput);
      char receivedMessage[messageLengthMax+1];  //size for the longest possible message 32 is the MD5 length
      unsigned long timeStamp=millis();
      while(etherEventClient.connected()==1){
        if(millis()>timeStamp+timeoutDuration){  //timeout
          Serial.println(F("availableEvent: timeout---------------------------------------------------------------------"));
          Serial.println(F("availableEventDisconnect"));
          etherEventClient.flush();
          etherEventClient.stop();
          availableEventFlag=0;
          return strlen(receivedEvent);
        }
        Serial.print(F("availableEvent: reading message, etherEventClient.available()="));
        Serial.println(etherEventClient.available()+1);
        byte messageCount=0;
        receivedMessage[messageCount]=0; //reset the value in case the first char of the array is null so the while loop will continue
        byte TCPEventsMD5separatorLength=strlen(TCPEventsMD5separator);
        while(etherEventClient.available()>0){  //(10=ascii code for newline)figure out how to put the number of bytes available in a variable here to be used below instead of calling the available() function twice
          receivedMessage[messageCount]=etherEventClient.read();
          if(messageCount==TCPEventsMD5separatorLength-1 && strncmp(receivedMessage,TCPEventsMD5separator,TCPEventsMD5separatorLength)==0){  //check if the start of the message is the TCPEventsMD5separator
            messageCount=0;  //reset the count so the next part of the message will be written to the start of the buffer
            continue;  //continue reading the message
          }
          if(messageCount==messageLengthMax || receivedMessage[messageCount]==0 || receivedMessage[messageCount]==10 || receivedMessage[messageCount]==13){ //last char of the message reached or newline reached
            receivedMessage[messageCount]=0;	//make sure the last char is always the null terminator
            messageCount++;
            break;
          }
          unsigned long receiveMessageTimeStamp=millis();
          while(etherEventClient.available()==0){ //wait a little bit for more message to come in
            if(millis()>receiveMessageTimeStamp+listenTimeoutDuration){  //timeout
              Serial.println(F("sendEvent: listenTimeout------------------------------------------------------------------------------"));
              break;
            }
          }
          if(etherEventClient.available()==0){
            messageCount++;
            receivedMessage[messageCount]=0;	//make sure the last char is always the null terminator
            break;
          }   
          messageCount++;
        }
        if(messageCount<2){
          Serial.println(F("availableEvent: no message or null message received"));
          continue;
        }
        else{  //there is a message
          Serial.print(F("availableEvent: Message received="));
          Serial.println(receivedMessage);
          Serial.print(F("availableEvent: availableEventFlag="));
          Serial.println(availableEventFlag);
          if(strncmp(receivedMessage,closeMessage,strlen(closeMessage))==0){	//close connection
            Serial.println(F("availableEvent: close message received"));
            etherEventClient.flush();
            etherEventClient.stop();
            availableEventFlag=0;
            return strlen(receivedEvent);
          }
          if(availableEventFlag==1 && strncmp(receivedMessage,magicWord,strlen(magicWord)-1)==0){  //magic word received
            Serial.println(F("availableEvent: magic word received"));
            availableEventFlag=2;
            int availableEventCookie=random(10000,32767);  //make random 5 digit number to use as cookie and send to the sender
            itoa(availableEventCookie,cookieChar,10);
    	    Serial.print(F("availableEvent: cookieChar="));
            Serial.println(cookieChar);
            byte availableEventBytesSent=etherEventClient.print(cookieChar);
            Serial.print(F("availableEvent: cookie bytes sent="));
            Serial.println(availableEventBytesSent);
            continue;
          }
          if(availableEventFlag==2){ //hashword received
            char availableEventCookiePassword[max(cookieLengthMax,5)+1+strlen(password)+1];  //cookie + password separator + Password + null terminator
            strcpy(availableEventCookiePassword,cookieChar); //create the hashword to compare to the received one
            strcat(availableEventCookiePassword,":"); //create the hashword to compare to the received one
            strcat(availableEventCookiePassword,password);
            Serial.print(F("availableEvent: availableEventCookiePassword="));  //it always hangs here
            Serial.println(availableEventCookiePassword);
            unsigned char* availableEventCookiePasswordHash=MD5::make_hash(availableEventCookiePassword);
            char *availableEventCookiePasswordMD5 = MD5::make_digest(availableEventCookiePasswordHash, 16);
            Serial.print(F("availableEvent: availableEventCookiePasswordMD5="));
            Serial.println(availableEventCookiePasswordMD5);
            if(strncmp(availableEventCookiePasswordMD5,receivedMessage,32)==0){  //authentication passed
              free(availableEventCookiePasswordMD5);
              Serial.println(F("availableEvent: authentication successful"));
              availableEventFlag=3;
              byte availableEventSendSuccess=etherEventClient.print(acceptMessage);
              Serial.print(F("availableEvent: accept bytes sent="));
              Serial.println(availableEventSendSuccess);
              continue;
            }
            else{  //authentication failed
              free(availableEventCookiePasswordMD5);
	      Serial.println(F("availableEvent: authentication failed"));
              Serial.println(F("availableEventDisconnect"));
              etherEventClient.flush();
              etherEventClient.stop();
              availableEventFlag=0;
              return 0;
            }
          }
          if(availableEventFlag==3){
            if(strncmp(payloadFirst, receivedMessage, strlen(payloadFirst))==0){  //verification received message is the first payload
              Serial.println(F("availableEvent: without release payload received"));
              continue;  //ignore
            }
            if(strncmp(payloadSeparator, receivedMessage, strlen(payloadSeparator)-1)==0){  //verification received message is the payload
              Serial.println(F("availableEvent: payload verified"));
              if(strlen(receivedMessage)>strlen(payloadSeparator)){ //there is a payload
                Serial.print(F("availableEvent: payload received="));           
                byte payloadCount=0;
                for(payloadCount=0;payloadCount<=strlen(receivedMessage)-strlen(payloadSeparator);payloadCount++){  //copy just the payload portion of the message to the payload variable - I had to change payloadCount< to payloadCount<= to make the payload correct(when a longer length payload was passed and then a shorter one after would have the letter from the previous message appended to the end of the payload) so I don't know if it still works with eventGhost
                  receivedPayload[payloadCount]=receivedMessage[payloadCount+strlen(payloadSeparator)];
                  if(receivedPayload[payloadCount]==0){
                    break;
                  }
                }
                if(receivedPayload[payloadCount]!=0){
                  receivedPayload[payloadCount+1]=0;
                }
                Serial.println(receivedPayload);
              }
              else{  //no payload
                Serial.println(F("availableEvent: no payload"));
              }
              continue;
            }
            else{
              Serial.print(F("availableEvent: event received="));              
              strcpy(receivedEvent,receivedMessage);
              receivedEvent[eventLengthMax]=0;  //make sure there is a null terminator at the end of the string
              #ifdef REMOTEIP
                fromIP=etherEventClient.remoteIP;  //save the IP address of the sender
              #endif
              Serial.println(receivedEvent);
              Serial.print(F("availableEvent: strlen(receivedEvent)="));
              Serial.println(strlen(receivedEvent));
              availableEventFlag=5;
              continue;  //event received successfully, now get the close message
            }
          }
        }
      }
      Serial.println(F("availableEvent: Disconnect"));
      etherEventClient.flush();
      etherEventClient.stop();
    }
  }
}

byte EtherEvent::availablePayload(){  //returns the number of chars in the payload if there is one
  byte length=strlen(receivedPayload);
  if(length==0){  //no event
    return 0;
  }
  if(readPayloadCount>length){	//shouldn't be needed but just in case this will prevent the negative overflow of the variable leading to an incorrect return value
    Serial.println(F("availablePayload: readPayloadCount>length ---------------------------------------------------!"));
    return 0;
  }
  return length+1 - readPayloadCount;
}

char EtherEvent::readEvent(){
  if(readEventCount<strlen(receivedEvent)){
    readEventCount++;
    if(receivedEvent[readEventCount-1]==0){  //null terminator reached
      receivedEvent[0]=0;  //reset the event buffer
      readEventCount=0;  //reset the count
      return 0;  //send null terminator at the end of the read
    }
    return receivedEvent[readEventCount-1];
  }
  else{
    receivedEvent[0]=0;  //reset the event buffer
    readEventCount=0;  //reset the count
    return 0;
  }
}

char EtherEvent::readPayload(){
  if(readPayloadCount<strlen(receivedPayload)){
    readPayloadCount++;
    if(receivedPayload[readPayloadCount-1]==0){  //null terminator reached
      receivedPayload[0]=0;  //reset the event buffer
      readPayloadCount=0;  //reset the count
      return 0;  //send null terminator at the end of the read
    }
    return receivedPayload[readPayloadCount-1];
  }
  else{
      receivedPayload[0]=0;  //reset the event buffer
      readPayloadCount=0;  //reset the count
    return 0;  //send null terminator at the end of the read
  }
}

void EtherEvent::flushReceiver(){  //dump the last message received so another one can be received
  Serial.println(F("flushReceiver: start"));
  receivedEvent[0]=0;  //reset the event buffer
  readEventCount=0;  //reset the count
  receivedPayload[0]=0;  //reset the event buffer
  readPayloadCount=0;  //reset the count
}

IPAddress EtherEvent::senderIP(){  //returns the ip address the current event was sent from. Requires modified ethernet library, thus the preprocesser direcive system
  Serial.println(F("availableEvent: start"));
  return fromIP;
} 
    
byte EtherEvent::sendEvent(IPAddress sendIP, unsigned int sendPort, char sendEvent[], char sendPayload[]){
  Serial.println(F("sendEvent: start"));
  Serial.println(F("sendEvent: attempting connection"));
  if(etherEventClient.connect(sendIP,sendPort)){  //connected to receiver
    byte sendFlag=1;
    Serial.println(F("sendEvent: connected"));
    unsigned long timeStamp=millis();  //reset the timeout now that it has connected to the receiver
    while(etherEventClient.connected()){
      if(millis()>timeStamp+timeoutDuration){
        Serial.println(F("sendEvent: Timeout------------------------------------------------------------------------------"));
        break;
      }
      Serial.println(F("sendEvent: connected loop"));
      byte messageCount=0;
      byte receivedMessageLengthMax=strlen(acceptMessage);
      receivedMessageLengthMax=max(receivedMessageLengthMax,5);  //EtherEvent uses a 5 digit cookie so this is the minimum value for the receivedMessageLengthMax
      receivedMessageLengthMax=max(receivedMessageLengthMax,cookieLengthMax);
      char receivedMessage[receivedMessageLengthMax+1]; //need to size this smarter, right now the 
      if(sendFlag>1){  //it can skip checking for a message the first one because the magic word must be sent first
        Serial.println(F("sendEvent: checking for message from receiver"));
        while(etherEventClient.available()>0){  //figure out how to put the number of bytes available in a variable here to be used below instead of calling the available() function twice
          receivedMessage[messageCount]=etherEventClient.read();
          if(receivedMessage[messageCount]==32 && messageCount==0){  //ignore leading spaces(ascii code 32) for TCPEvents EventGhost plugin compatibility
            continue;
          }
          if(messageCount==receivedMessageLengthMax || receivedMessage[messageCount]==0 || receivedMessage[messageCount]==10 || receivedMessage[messageCount]==13){ //(10=ascii code for newline, 13=return, 0=null)last char of the message reached or newline reached
            receivedMessage[messageCount]=0;	//make sure the last char is always the null terminator
            messageCount++;
            break;
          }
          unsigned long receiveMessageTimeStamp=millis();
          while(etherEventClient.available()==0){ //wait a little bit for more message to come in
            if(millis()>receiveMessageTimeStamp+listenTimeoutDuration){  //timeout
              Serial.println(F("sendEvent: listenTimeout------------------------------------------------------------------------------"));
              break;
            }
          }
          if(etherEventClient.available()==0){
            messageCount++;
            receivedMessage[messageCount]=0;	//make sure the last char is always the null terminator
            break;
          }             
          messageCount++;
        }
        if(messageCount<2){  //no message or if it's only the null terminator then that's not considered a message
          Serial.println(F("sendEvent: no message or null message"));
          continue;
        }
        Serial.print(F("sendEvent: message from receiver="));
        Serial.println(receivedMessage);
      }
      if(sendFlag==1){
        Serial.print(F("sendEvent: sending magic word="));
        Serial.println(magicWord);
        byte sendEventBytesSent=etherEventClient.print(magicWord);  //send the magic word to the receiver so it will send the cookie
        sendEventBytesSent+=etherEventClient.print(F("\n"));
        Serial.print(F("sendEvent: bytes sent="));
        Serial.println(sendEventBytesSent);
        sendFlag=2;
        continue;
      }
      if(sendFlag==2){ //cookie received
        Serial.println(F("sendEvent: md5 received from receiver"));
        char cookiePassword[cookieLengthMax+1+strlen(password)+1];  //cookie, password separator(:), password, null terminator
        strcpy(cookiePassword,receivedMessage);
        strcat(cookiePassword,":");  //add the password separator to the cookie
        strcat(cookiePassword,password); //add password to the cookie
        Serial.print(F("sendEvent cookiePassword="));
        Serial.println(cookiePassword);
        unsigned char* cookiePasswordHash=MD5::make_hash(cookiePassword);
        char *cookiePasswordMD5 = MD5::make_digest(cookiePasswordHash, 16);
        Serial.print(F("sendEvent hashWordMD5="));
        Serial.println(cookiePasswordMD5);
        byte sendEventBytesSent=etherEventClient.print(cookiePasswordMD5);  //send the MD5 of the hashword
        free(cookiePasswordMD5);
        sendEventBytesSent+=etherEventClient.print(F("\n"));
        Serial.print(F("sendEvent: hashWordMD5, bytes sent="));
        Serial.println(sendEventBytesSent);
        sendFlag=3;
        continue;
      }
      if(sendFlag==3){
        if(strncmp(acceptMessage,receivedMessage,strlen(acceptMessage))==0){  //combine this if with the one above authentication successful
          Serial.print(F("sendEvent: Payload="));
          Serial.println(sendPayload);
          Serial.print(F("sendEvent: event="));
          Serial.println(sendEvent);
          if(sendPayload[0]!=0){  //check if there is a payload
            byte sendEventBytesSent=etherEventClient.print(payloadSeparator);
            sendEventBytesSent+=etherEventClient.print(sendPayload);
            sendEventBytesSent+=etherEventClient.print(F("\n"));
            Serial.print(F("sendEvent: payload bytes sent="));
            Serial.println(sendEventBytesSent);
          }
          byte sendEventBytesSent=etherEventClient.print(sendEvent); //this one also works with the ln the events look the same but are not equivalent in eg
          sendEventBytesSent+=etherEventClient.print(F("\n"));
          Serial.print(F("sendEvent: event bytes sent="));
          Serial.println(sendEventBytesSent);
          sendEventStop();
          return 1;  //send successful
        }
        else{  //authentication failed
          Serial.println(F("sendEvent: authentication failed"));
          break;
        }
      }
      Serial.println(F("sendEvent: dead loop"));
    }
    sendEventStop();
  }
  else{
    Serial.println(F("sendEvent connection failed"));
  }
  return 0;  //send fail
}

void EtherEvent::sendEventStop(){
  etherEventClient.flush(); //do this right away in case it delays the stop
  Serial.println(F("sendEventStop: start"));
  byte sendEventBytesSent=etherEventClient.print(closeMessage);  
  sendEventBytesSent+=etherEventClient.print(F("\n"));  //is this needed?
  Serial.print(F("sendEventStop: close bytes sent="));
  Serial.println(sendEventBytesSent);
  etherEventClient.stop();
}
