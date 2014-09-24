//EtherEvent - Easy to use password authenticated network communication between Arduinos and EventGhost Network Event Sender/Receiver plugin, EventGhost TCPEvents plugin, Girder, and NetRemote
#include "Arduino.h"  //not needed?
#include "EtherEvent.h"
#include <MD5.h>  //http://github.com/tzikis/ArduinoMD5
#include <SPI.h>
#include <Ethernet.h>  //change to UIPEthernet.h(http://github.com/ntruchsess/arduino_uip) if using the ENC28J60 ethernet module  
#include <Entropy.h>

#define DEBUG 0 // flag to turn on/off debugging
#define Serial if(DEBUG)Serial
//#define SENDERIP_ENABLE //is the ethernet library modified to return the client IP address via the remoteIP function. Instructions here: http://forum.arduino.cc/index.php?/topic,82416.0.html
//#define RANDOM_COOKIE //use the entropy random function for the cookie instead of the arduino random function for added security. This will increase the time required for the availableEvent() function to receive a new message

const char magicWord[] = "quintessence";  //word used to trigger the cookie send from the receiver
const char acceptMessage[] = "accept";  //authentication success message
const char payloadFirst[] = "payload withoutRelease";  //eg sends this every time and EtherEvent filters it out
const char payloadSeparator[] = "payload ";  //indicates payload
const char closeMessage[] = "close";  //sender sends this message to the receiver to close the connection
const char TCPEventsMD5separator[]="TCPEvents";  //TCPEvents adds the separator before the MD5
const byte cookieLengthMax=6;  //EtherEvent sends a 6 digit cookie(5 digit number and negative sign), eg seems to be a 4 digit cookie(socket), but it can be set larger if needed
const byte eventLengthMax=15;  //Maximum event length
const byte payloadLengthMax=60;  //Maximum payload length
#if DEBUG==0  //the timeout values can be smaller without the serial slowing things down
  const unsigned int timeoutDuration=200;  //(ms)Timeout duration for each step of the availableEvent or sendEvent functions.
  const byte listenTimeout=800;  //(us)max time to wait for another char to be available from the client.read function - it was getting ahead of the stream and stopping before getting the whole message event though I send the full string all at once
#else //use larger timeout values because of the serial slowing things down
  const unsigned int timeoutDuration=1200;  //(ms)Timeout duration for each step of the availableEvent or sendEvent functions.
  const byte listenTimeout=2000;  //(us)max time to wait for another char to be available from the client.read function - it was getting ahead of the stream and stopping before getting the whole message event though I send the full string all at once
#endif
const int receivePort = 1024;  //TCP port to receive on

EthernetServer etherEventServer = EthernetServer(receivePort);
EthernetClient etherEventClient;

char etherEventPassword[21];
char receivedEvent[eventLengthMax+1];  //event buffer
char receivedPayload[payloadLengthMax+1];  //payload buffer
byte readEventCount=0;  //the next char of the received event string to be read
byte readPayloadCount=0;
IPAddress fromIP(0,0,0,0);  //IP address of the last event sender
byte availableEventMessageLengthMax;  //I'm using globals for these 2 so I can just calculate the buffer size in the setup() instead of every time the functions is called
byte sendEventMessageLengthMax;

EtherEvent::EtherEvent(){
}

void EtherEvent::etherEventStart(byte macAdd[],IPAddress deviceIP, char password[]){
  Serial.println(F("etherEventStart: start"));
  Ethernet.begin(macAdd,deviceIP);
  etherEventServer.begin();
  
  strcpy(etherEventPassword,password);
  
  byte maxInput=strlen(payloadSeparator) + payloadLengthMax;  //determine the size of the incoming message buffer for the availableEvent function.
  availableEventMessageLengthMax=max(maxInput,32);  //32 is the length of the MD5
  maxInput=strlen(payloadFirst);
  availableEventMessageLengthMax=max(availableEventMessageLengthMax,maxInput);
  maxInput=strlen(magicWord);
  availableEventMessageLengthMax=max(availableEventMessageLengthMax,maxInput);
  maxInput=strlen(closeMessage);
  availableEventMessageLengthMax=max(availableEventMessageLengthMax,maxInput);
  
  sendEventMessageLengthMax=strlen(acceptMessage);
  sendEventMessageLengthMax=max(sendEventMessageLengthMax,cookieLengthMax);
  
  Entropy.initialize(); //gets a truly random number from the timer jitter
  #ifndef RANDOM_COOKIE //randomSeed is not needed if the entropy random function is used via the MORE_SECURE flag. 
    randomSeed(Entropy.random()); //Initialize the random function with a truly random value from the entropy library
  #endif
  Serial.println(F("etherEventStart: finished"));  
}

byte EtherEvent::availableEvent(){  //checks for senders, connects, authenticates, reads the event and payload into the buffer and returns the number of bytes of the most recently received event are left in the buffer
  if(byte eventLength=strlen(receivedEvent)){  //there are already bytes of an available event in the buffer, it must be read or flushed before another one can be received
    if(readEventCount>eventLength){  //avoid negative overflow - this shouldn't be needed
      Serial.println(F("availableEvent: readEventCount>length"));
      return 0;
    }
    return eventLength+1 - readEventCount;
  }    
  if(availablePayload()>0){  //don't get another event until the last is fully read or flushed
    return 0;
  }
  if(EthernetClient etherEventClient = etherEventServer.available() ){  //connect to the client
    Serial.println(F("availableEvent: connected"));
    char cookieChar[cookieLengthMax+1];  //initializing here because it needs to be used in the cookie send if and the hashword verify if and if it's inside the while then it will be reinitialized on every loop
    for(byte availableEventFlag=1;availableEventFlag<=6 && etherEventClient.connected()==1;availableEventFlag++){
      unsigned long timeStamp=millis(); //for timeout
      byte bytesAvailable;
      for(;;){  //wait for a message
        if(millis()>timeStamp+timeoutDuration){  //timeout
          Serial.println(F("availableEvent: timeout"));
          etherEventClient.flush();
          etherEventClient.stop();
          return strlen(receivedEvent);
        }
        if(bytesAvailable=etherEventClient.available()){
          if(bytesAvailable>1){ //the message must be at least one char not including the null terminator. Couldn't combine this with the if above because it needs to set the bytesAvailable value first
            break;
          }
        }
      }
      unsigned long listenTimeStamp=micros();
      while(micros()<listenTimeStamp+listenTimeout){  //it takes a bit of time for the full message to come through so it has to wait to know how to size the variable
        if(bytesAvailable<etherEventClient.available()){
          listenTimeStamp=micros();
          bytesAvailable=etherEventClient.available();
        }
        if(bytesAvailable>=availableEventMessageLengthMax+1){  //break out of the loop if it has enough
          break;
        }
      }
      Serial.print(F("availableEvent: reading message, etherEventClient.available()="));
      Serial.println(bytesAvailable);
      byte TCPEventsMD5separatorLength=strlen(TCPEventsMD5separator);  //get rid of this, try to just do a strcmp
      char receivedMessage[bytesAvailable];
      for(byte messageCount=0;messageCount<bytesAvailable;messageCount++){  //read the message
        receivedMessage[messageCount]=etherEventClient.read();
        Serial.println(receivedMessage[messageCount]);
        if(messageCount==bytesAvailable || receivedMessage[messageCount]==0 || receivedMessage[messageCount]==10 || receivedMessage[messageCount]==13){ //last char of the message reached or newline reached
          if(messageCount==0){  //null message
            Serial.println(F("availableEvent: null message"));
            messageCount=-1;
            continue;
          }
          receivedMessage[messageCount]=0;	//make sure the last char is always the null terminator
          break;
        }
        if(messageCount==TCPEventsMD5separatorLength-1 && availableEventFlag==2){  //TCPEvents puts "TCPEvents" on the start of the MD5
          Serial.println(F("availableEvent: checking for TCPEvent"));
          if(strncmp(receivedMessage,TCPEventsMD5separator,TCPEventsMD5separatorLength)==0){  //check if the start of the message is the TCPEventsMD5separator
            Serial.println(F("availableEvent: TCPEvent received"));
            messageCount=-1;  //I want it to reset to zero on the next for loop so I have to make it -1
            continue;  //continue reading the message
          }
        }
        if(etherEventClient.available()==0){
          receivedMessage[messageCount]=0;	//make sure the last char is always the null terminator
          break;
        }   
      }
      Serial.print(F("availableEvent: Message received="));
      Serial.println(receivedMessage);
      Serial.print(F("availableEvent: availableEventFlag="));
      Serial.println(availableEventFlag);
      if(strncmp(receivedMessage,closeMessage,strlen(closeMessage))==0){	//close connection
        Serial.println(F("availableEvent: close message received"));
        availableEventFlag=0; //disable everything else in the message handler. It will continue to the end of the for loop and then disconnectavailableEventFlag
      }
      if(availableEventFlag==1 && strncmp(receivedMessage,magicWord,strlen(magicWord)-1)==0){  //magic word received
        Serial.println(F("availableEvent: magic word received"));
        #ifdef RANDOM_COOKIE
          int availableEventCookie=Entropy.random(65536);
        #else  
          int availableEventCookie=random(65536);  //make random 5 digit number to use as cookie and send to the sender
        #endif
        itoa(availableEventCookie,cookieChar,10);
	      Serial.print(F("availableEvent: cookieChar="));
        Serial.println(cookieChar);
        byte availableEventBytesSent=etherEventClient.print(cookieChar);
        Serial.print(F("availableEvent: cookie bytes sent="));
        Serial.println(availableEventBytesSent);
        continue;
      }
      if(availableEventFlag==2){ //hashword received
        char availableEventCookiePassword[max(cookieLengthMax,5)+1+strlen(etherEventPassword)+1];  //cookie + password separator + Password + null terminator
        strcpy(availableEventCookiePassword,cookieChar); //create the hashword to compare to the received one
        strcat(availableEventCookiePassword,":"); //create the hashword to compare to the received one
        strcat(availableEventCookiePassword,etherEventPassword);
        Serial.print(F("availableEvent: availableEventCookiePassword="));  //it always hangs here
        Serial.println(availableEventCookiePassword);
        unsigned char* availableEventCookiePasswordHash=MD5::make_hash(availableEventCookiePassword);
        char *availableEventCookiePasswordMD5 = MD5::make_digest(availableEventCookiePasswordHash, 16);
        Serial.print(F("availableEvent: availableEventCookiePasswordMD5="));
        Serial.println(availableEventCookiePasswordMD5);
        if(strncmp(availableEventCookiePasswordMD5,receivedMessage,32)==0){  //authentication passed
          free(availableEventCookiePasswordMD5);
          Serial.println(F("availableEvent: authentication successful"));
          byte availableEventSendSuccess=etherEventClient.print(acceptMessage);
          Serial.print(F("availableEvent: accept bytes sent="));
          Serial.println(availableEventSendSuccess);
          continue;
        }
        free(availableEventCookiePasswordMD5);
        Serial.println(F("availableEvent: authentication failed"));
        Serial.println(F("availableEventDisconnect"));
        //it will continue to the end of the handler and then disconnect
      }
      if(availableEventFlag>=3){
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
          #ifdef SENDERIP_ENABLE
            byte tempIP[4];
            etherEventClient.getRemoteIP(tempIP);  //save the IP address of the sender
            fromIP=tempIP;
          #endif
          Serial.println(receivedEvent);
          /*I'm trying it out without receiving the close message for faster communication
          availableEventFlag=5;  //this disables everything in the message handler code except the close
          continue;  //event received successfully, now get the close message
          */
        }
      }
      break;  //if it makes it through the handler without hitting a continue then something went wrong so disconnect
    }
    Serial.println(F("availableEvent: Disconnect"));
    //etherEventClient.flush(); //I'm trying without the flush for now to see if it matters
    etherEventClient.stop();
    return strlen(receivedEvent);
  }
  return 0;
}

byte EtherEvent::availablePayload(){  //returns the number of chars in the payload if there is one
  byte length=strlen(receivedPayload);
  if(length==0){  //no event
    return 0;
  }
  if(readPayloadCount>length){	//shouldn't be needed but just in case this will prevent the negative overflow of the variable leading to an incorrect return value
    Serial.println(F("availablePayload: readPayloadCount>length"));
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
  return fromIP;
} 
    
byte EtherEvent::sendEvent(IPAddress sendIP, unsigned int sendPort, char sendEvent[], char sendPayload[]){
  Serial.println(F("sendEvent: start"));
  Serial.println(F("sendEvent: attempting connection"));
  byte sendEventSuccess=0;
  if(etherEventClient.connect(sendIP,sendPort)){  //connected to receiver
    byte sendFlag=1;
    Serial.println(F("sendEvent: connected"));
    Serial.print(F("sendEvent: sending magic word="));
    Serial.println(magicWord);
    byte sendEventBytesSent=etherEventClient.print(magicWord);  //send the magic word to the receiver so it will send the cookie
    sendEventBytesSent+=etherEventClient.print(F("\n"));
    Serial.print(F("sendEvent: bytes sent="));
    Serial.println(sendEventBytesSent);
    for(byte sendEventFlag=1;sendEventFlag<=2 && etherEventClient.connected()==1;sendEventFlag++){
      unsigned long timeStamp=millis();  //for the timeout
      byte bytesAvailable;
      for(;;){  //wait for a message
        if(millis()>timeStamp+timeoutDuration){  //timeout
          Serial.println(F("sendEvent: timeout"));
          etherEventClient.flush();
          etherEventClient.stop();
          return strlen(receivedEvent);
        }
        if(bytesAvailable=etherEventClient.available()){
          if(bytesAvailable>1){ //the message must be at least one char not including the null terminator. Couldn't combine this with the if above because it needs to set the bytesAvailable value first
            break;
          }
        }
      }
      unsigned long listenTimeStamp=micros();
      while(micros()<listenTimeStamp+listenTimeout){  //it takes a bit of time for the full message to come through so it has to wait to know how to size the variable
        if(bytesAvailable<etherEventClient.available()){
          listenTimeStamp=micros();
          bytesAvailable=etherEventClient.available();
        }
        if(bytesAvailable>=sendEventMessageLengthMax+1){  //break out of the loop if it has enough
          break;
        }
      }
      Serial.print(F("sendEvent: reading message, etherEventClient.available()="));
      Serial.println(bytesAvailable);
      char receivedMessage[bytesAvailable];
      for(int messageCount=0;messageCount<bytesAvailable;messageCount++){  //figure out how to put the number of bytes available in a variable here to be used below instead of calling the available() function twice
        receivedMessage[messageCount]=etherEventClient.read();
        if(messageCount==0 && receivedMessage[messageCount]==32){  //ignore leading spaces(ascii code 32) for TCPEvents EventGhost plugin compatibility
          Serial.println(F("sendEvent: leading space ignored"));
          messageCount=-1;  //I want it to reset to zero on the next for loop so I have to make it -1
          continue;
        }
        if(messageCount==bytesAvailable || receivedMessage[messageCount]==0 || receivedMessage[messageCount]==10 || receivedMessage[messageCount]==13){ //last char of the message reached or newline reached
          if(messageCount==0){  //null message
            continue;
          }
          receivedMessage[messageCount]=0;	//make sure the last char is always the null terminator
          break;
        }
        if(etherEventClient.available()==0){
          receivedMessage[messageCount]=0;	//make sure the last char is always the null terminator
          break;
        }   
      }
      Serial.print(F("sendEvent: Message received="));
      Serial.println(receivedMessage);
      Serial.print(F("sendEvent: sendEventFlag="));
      Serial.println(sendEventFlag);
      if(strncmp(receivedMessage,closeMessage,strlen(closeMessage))==0){	//close connection
        Serial.println(F("sendEvent: close message received"));
        sendEventFlag=0; //disable everything else in the message handler. It will continue to the end of the for loop and then disconnectavailableEventFlag
      }
      if(sendEventFlag==1){ //cookie received
        Serial.println(F("sendEvent: md5 received from receiver"));
        char cookiePassword[cookieLengthMax+1+strlen(etherEventPassword)+1];  //cookie, password separator(:), password, null terminator
        strcpy(cookiePassword,receivedMessage);
        strcat(cookiePassword,":");  //add the password separator to the cookie
        strcat(cookiePassword,etherEventPassword); //add password to the cookie
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
        continue;
      }
      if(sendEventFlag==2 && strncmp(acceptMessage,receivedMessage,strlen(acceptMessage))==0){  //combine this if with the one above authentication successful
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
        byte sendEventBytesSent=etherEventClient.print(sendEvent); //This one also works with the println. The events look the same but are not equivalent in eg
        sendEventBytesSent+=etherEventClient.print(F("\n"));
        Serial.print(F("sendEvent: event bytes sent="));
        Serial.println(sendEventBytesSent);
        sendEventSuccess=1;
      }
      break;
    }
    //etherEventClient.flush(); //do this right away in case it delays the stop
    Serial.print(F("sendEvent: close bytes sent="));
    sendEventBytesSent=etherEventClient.print(closeMessage);  //tell the receiver to close
    sendEventBytesSent+=etherEventClient.print(F("\n"));
    Serial.println(sendEventBytesSent);
    etherEventClient.stop();
  }
  else{
    Serial.println(F("sendEvent connection failed"));
  }
  return sendEventSuccess;  //send fail
}