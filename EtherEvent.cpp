//EtherEvent - Easy to use password authenticated network communication between Arduinos and EventGhost Network Event Sender/Receiver plugin, EventGhost TCPEvents plugin, Girder, and NetRemote
#include "Arduino.h"  //not needed?
#include "EtherEvent.h"
#include <MD5.h>  //http://github.com/tzikis/ArduinoMD5
#include <SPI.h>
#include <Ethernet.h>  //change to UIPEthernet.h(http://github.com/ntruchsess/arduino_uip) if using the ENC28J60 ethernet module  
#define ENTROPY_FLAG  //Comment this line out to disable use of the Entropy true random number library to save memory. Warning this will compromise the security of the authentication process as the cookie will not be truly random
#ifdef ENTROPY_FLAG
  #include <Entropy.h>  //http://sites.google.com/site/astudyofentropy/file-cabinet
  //#define RANDOM_COOKIE //Uncomment this line to use the entropy random function for the cookie instead of the arduino random function for added security. This will increase the time required for the availableEvent() function to receive a new message
#endif

#define DEBUG 0 // (0==serial debug output off, 1==serial debug output on)The serial debug output will greatly slow down communication time and so different timeout values are enabled.
#define Serial if(DEBUG)Serial
//#define SENDERIP_ENABLE //Uncomment this line if the ethernet library has been modified to return the client IP address via the remoteIP function. Modification instructions here: http://forum.arduino.cc/index.php?/topic,82416.0.html

#define MAGIC_WORD "quintessence"  //word used to trigger the cookie send from the receiver. I had to #define this instead of const because findUntil didn't like the const
#define ACCEPT_MESSAGE "accept"  //authentication success message
const char withoutRelease[]="withoutRelease";  //eg sends this every time and EtherEvent filters it out
const byte withoutReleaseLength=14;
const char payloadSeparator[]="payload ";  //indicates payload
const byte payloadSeparatorLength=8;  //includes space at the end
const char closeMessage[]="close";  //sender sends this message to the receiver to close the connection

const byte passwordLengthMax=20;
const byte cookieLengthMax=6;  //EtherEvent sends a 6 digit cookie(5 digit number and negative sign), eg seems to be a 4 digit cookie(socket), but it can be set larger if needed
const byte eventLengthMax=15;  //Maximum event length
const byte payloadLengthMax=60;  //Maximum payload length
const byte availableEventMessageLengthMax=payloadSeparatorLength+withoutReleaseLength+1+payloadSeparatorLength+payloadLengthMax+1+eventLengthMax;  //I'm using globals for these 2 so I can just calculate the buffer size in the setup() instead of every time the functions is called
byte availableEventSubmessageLengthMax;  //non-const because I have to use max()


#if DEBUG==0  //the timeout values can be smaller without the serial slowing things down
  const unsigned int timeoutDuration=150;  //(ms)Timeout duration for each step of the availableEvent or sendEvent functions.
  const unsigned int listenTimeout=800;  //(us)max time to wait for another char to be available from the client.read function - it was getting ahead of the stream and stopping before getting the whole message event though I send the full string all at once
#else //use larger timeout values because of the serial slowing things down
  const unsigned int timeoutDuration=500;  //(ms)Timeout duration for each step of the availableEvent or sendEvent functions.
  const unsigned int listenTimeout=2000;  //(us)max time to wait for another char to be available from the client.read function - it was getting ahead of the stream and stopping before getting the whole message event though I send the full string all at once
#endif
const int receivePort = 1024;  //TCP port to receive on

EthernetServer etherEventServer = EthernetServer(receivePort);
EthernetClient etherEventClient;

char etherEventPassword[passwordLengthMax+1];
char receivedEvent[eventLengthMax+1];  //event buffer
char receivedPayload[payloadLengthMax+1];  //payload buffer
IPAddress fromIP(0,0,0,0);  //IP address of the last event sender


EtherEvent::EtherEvent(){
}


void EtherEvent::begin(byte macAdd[],IPAddress deviceIP, char password[]){
  Serial.println(F("etherEventStart: start"));
  Ethernet.begin(macAdd,deviceIP);
  etherEventServer.begin();
  etherEventClient.setTimeout(timeoutDuration);  //timeout on read/readUntil/find/findUntil/etc      
  strcpy(etherEventPassword,password);
  
  #ifdef ENTROPY_FLAG
    Entropy.initialize(); //gets truly random numbers from the timer jitter
    #ifndef RANDOM_COOKIE //randomSeed is not needed if the entropy random function is used via the RANDOM_COOKIE flag. 
      randomSeed(Entropy.random()); //Initialize the random function with a truly random value from the entropy library
    #endif
  #endif
  
  byte maxInput=payloadSeparatorLength+withoutReleaseLength;
  availableEventSubmessageLengthMax=max(eventLengthMax,maxInput);
  maxInput=payloadSeparatorLength+payloadLengthMax;
  availableEventSubmessageLengthMax=max(availableEventSubmessageLengthMax,maxInput);
  availableEventSubmessageLengthMax++;  //null terminator
}


byte EtherEvent::availableEvent(){  //checks for senders, connects, authenticates, reads the event and payload into the buffer and returns the number of bytes of the most recently received event are left in the buffer
  if(byte length=strlen(receivedEvent)){    //strlen(receivedEvent)>0
    return length+1;   //number of bytes including the null terminator remaining to be read of the event
  }
  if(availablePayload()>0){  //don't get another event until the last is fully read or flushed
    return 0;
  }
  if(EthernetClient etherEventClient = etherEventServer.available() ){  //connect to the client
    Serial.println(F("availableEvent: connected--------------"));
    etherEventClient.setTimeout(timeoutDuration);  //timeout on read/readUntil/find/findUntil/etc    
    char cookieChar[cookieLengthMax+1];  //initializing here because it needs to be used in the cookie send if and the hashword verify if and if it's inside the while then it will be reinitialized on every loop    
    if(etherEventClient.findUntil(MAGIC_WORD,0)==0){  //magic word received
      return 0;
    }
    Serial.println(F("availableEvent: magic word received"));
    #ifdef RANDOM_COOKIE
      int cookieInt=Entropy.random(65536);  //true random cookie for highest security
    #else  
      int cookieInt=random(65536);  //make random 5 digit number to use as cookie and send to the sender
    #endif
    itoa(cookieInt,cookieChar,10);
    Serial.print(F("availableEvent: cookieChar="));
    Serial.println(cookieChar);
    etherEventClient.print(cookieChar);

    char cookiePassword[max(cookieLengthMax,5)+1+strlen(etherEventPassword)+1];  //cookie + password separator + Password + null terminator
    strcpy(cookiePassword,cookieChar); //create the hashword to compare to the received one
    strcat(cookiePassword,":"); //create the hashword to compare to the received one
    strcat(cookiePassword,etherEventPassword);
    Serial.print(F("availableEvent: cookiePassword="));  //it always hangs here
    Serial.println(cookiePassword);
    unsigned char* cookiePasswordHash=MD5::make_hash(cookiePassword);
    char *cookiePasswordMD5 = MD5::make_digest(cookiePasswordHash, 16);
    Serial.print(F("availableEvent: cookiePasswordMD5="));
    Serial.println(cookiePasswordMD5);
    if(etherEventClient.findUntil(cookiePasswordMD5,0)==0){
      free(cookiePasswordMD5);
      Serial.println(F("availableEvent: authentication failed"));
      return 0;
    }
    Serial.println(F("availableEvent: authentication successful"));
    etherEventClient.print(ACCEPT_MESSAGE);
    free(cookiePasswordMD5);

    unsigned long timeStamp=millis();
    byte availableLength;
    Serial.println(F("availableEvent: payload/event handler start"));
    for(;;){  //wait for a message. I have to do this because available() doesn't have a timeout, it just gives the currently available
      if(millis()>timeStamp+timeoutDuration){  //timeout
        Serial.println(F("getMessage: timeout"));
        etherEventClient.stop();
        return 0;
      }
      if(availableLength=etherEventClient.available()){
        if(availableLength>1){ //the message must be at least one char not including the null terminator. Couldn't combine this with the if above because it needs to set the receivedMessageLength value first
          break;
        }
      }
    }
    timeStamp=micros();  //reusing this variable for both wait loops
    while(micros()<timeStamp+listenTimeout){  //it takes a bit of time for the full message to come through so it has to wait for the available to be final
      if(availableLength<etherEventClient.available()){
        timeStamp=micros();
        availableLength=etherEventClient.available();
      }
      if(availableLength>=availableEventMessageLengthMax+1){  //break out of the loop if it has enough
        availableLength=availableEventMessageLengthMax+1;
        break;
      }
    }
    for(;;){
      Serial.println(F("availableEvent: payload/event for loop"));
      byte receivedMessageSize=min(availableLength,availableEventSubmessageLengthMax);  //determine the max buffer size required
      char receivedMessage[receivedMessageSize];  //initialize the buffer to read into
      byte bytesRead=0;
      bytesRead=etherEventClient.readBytesUntil(10,receivedMessage,receivedMessageSize);  //put the incoming data up to the null terminator into receivedMessage
      if (bytesRead==0){
        Serial.println(F("availableEvent: null message"));
        continue;
      }
      availableLength=availableLength-bytesRead;  //used to reduce the buffer size on the next loop
      receivedMessage[bytesRead]=0;  //add a null terminator
      Serial.print(F("availableEvent: bytesRead="));
      Serial.println(bytesRead);
      if(strncmp(receivedMessage, payloadSeparator, payloadSeparatorLength)==0){  //received message is a payload
        Serial.println(F("availableEvent: payload separator received"));
        if(bytesRead>payloadSeparatorLength+1){ //there is a payload
          byte receivedPayloadLength=bytesRead-payloadSeparatorLength+1;  //including the null terminator
          Serial.print(F("availableEvent: payload length(including null terminator)=")); 
          Serial.println(receivedPayloadLength);
          byte payloadCount=0;
          for(payloadCount=0;payloadCount<receivedPayloadLength;payloadCount++){  //copy just the payload portion of the message to the payload variable - I had to change payloadCount< to payloadCount<= to make the payload correct(when a longer length payload was passed and then a shorter one after would have the letter from the previous message appended to the end of the payload) so I don't know if it still works with eventGhost
            receivedPayload[payloadCount]=receivedMessage[payloadCount+payloadSeparatorLength];
          }
          receivedPayload[payloadCount+1]=0;
          if(strncmp(receivedPayload, withoutRelease, withoutReleaseLength)==0){
            Serial.println(F("availableEvent: withoutRelease")); 
            continue;
          }
          Serial.print(F("availableEvent: payload=")); 
          Serial.println(receivedPayload);
        }
        else{  //no payload
          Serial.println(F("availableEvent: no payload"));
        }
        continue;
      }
      else{
        Serial.print(F("availableEvent: event length="));
        Serial.println(bytesRead);
        strncpy(receivedEvent,receivedMessage,eventLengthMax);
        receivedEvent[bytesRead]=0;
        Serial.print(F("availableEvent: event received="));              
        Serial.println(receivedEvent);
        #ifdef SENDERIP_ENABLE
          byte tempIP[4];
          etherEventClient.getRemoteIP(tempIP);  //Save the IP address of the sender. Requires modified ethernet library
          fromIP=tempIP;
        #endif
        break;
      }
    }
    Serial.println(F("availableEvent: Disconnect"));
    etherEventClient.stop();
    if(byte length=strlen(receivedEvent)){
      return length+1;
    }
  }
  return 0;
}


byte EtherEvent::availablePayload(){  //returns the number of chars in the payload including the null terminator if there is one
  if(byte length=strlen(receivedPayload)){  //strlen(receivedPayload)>0
    return length+1;  //length of the payload + null terminator
  }
  return 0;
}


void EtherEvent::readEvent(char eventBuffer[]){
  strcpy(eventBuffer,receivedEvent);
  eventBuffer[strlen(receivedEvent)]=0;  //null terminator - is this needed?
  receivedEvent[0]=0;  //reset the event buffer
}


void EtherEvent::readPayload(char payloadBuffer[]){
  strcpy(payloadBuffer,receivedPayload);
  payloadBuffer[strlen(receivedPayload)]=0;  //null terminator - is this needed?
  receivedPayload[0]=0;  //reset the event buffer
}


void EtherEvent::flushReceiver(){  //dump the last message received so another one can be received
  Serial.println(F("flushReceiver: start"));
  receivedEvent[0]=0;  //reset the event buffer
  receivedPayload[0]=0;  //reset the event buffer
}


IPAddress EtherEvent::senderIP(){  //returns the ip address the current event was sent from. Requires modified ethernet library, thus the preprocesser direcive system
  return fromIP;
} 
    

byte EtherEvent::send(IPAddress sendIP, unsigned int sendPort, char sendEvent[], char sendPayload[]){
  Serial.println(F("sendEvent: attempting connection---------------"));
  byte sendEventSuccess=0;
  if(etherEventClient.connect(sendIP,sendPort)){  //connected to receiver
    Serial.println(F("sendEvent: connected, sending magic word"));

    etherEventClient.print(MAGIC_WORD);  //send the magic word to the receiver so it will send the cookie
    etherEventClient.print(F("\n"));

    char receivedMessage[cookieLengthMax+1];
    byte bytesRead=etherEventClient.readBytesUntil(10,receivedMessage,cookieLengthMax);
    receivedMessage[bytesRead]=0;
    char cookiePassword[bytesRead+1+strlen(etherEventPassword)+1];  //cookie, password separator(:), password, null terminator
    strcpy(cookiePassword,receivedMessage);
    strcat(cookiePassword,":");  //add the password separator to the cookie
    strcat(cookiePassword,etherEventPassword); //add password to the cookie
    Serial.print(F("sendEvent cookiePassword="));
    Serial.println(cookiePassword);
    unsigned char* cookiePasswordHash=MD5::make_hash(cookiePassword);
    char *cookiePasswordMD5 = MD5::make_digest(cookiePasswordHash, 16);
    Serial.print(F("sendEvent hashWordMD5="));
    Serial.println(cookiePasswordMD5);
    etherEventClient.print(cookiePasswordMD5);  //send the MD5 of the hashword
    free(cookiePasswordMD5);
    etherEventClient.print(F("\n"));

    if(etherEventClient.find(ACCEPT_MESSAGE)==1){
      Serial.print(F("sendEvent: Payload="));
      Serial.println(sendPayload);
      Serial.print(F("sendEvent: event="));
      Serial.println(sendEvent);
      if(sendPayload[0]!=0){  //check if there is a payload
        etherEventClient.print(payloadSeparator);
        etherEventClient.print(sendPayload);
        etherEventClient.print(F("\n"));
      }
      etherEventClient.print(sendEvent); //This one also works with the println. The events look the same but are not equivalent in eg
      etherEventClient.print(F("\n"));
      sendEventSuccess=1;
    }

    Serial.println(F("eventSendStop: close"));
    etherEventClient.print(closeMessage);  //tell the receiver to close
    etherEventClient.print(F("\n"));
    etherEventClient.stop();    
  }
  else{
    Serial.println(F("sendEvent connection failed"));
  }
  return sendEventSuccess;  //send finished
}
