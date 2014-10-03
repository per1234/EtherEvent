//EtherEvent - Easy to use password authenticated network communication between Arduinos and EventGhost Network Event Sender/Receiver plugin, EventGhost TCPEvents plugin, Girder, and NetRemote
#include "Arduino.h"  //not needed?
#include "EtherEvent.h"
#include <MD5.h>  //http://github.com/tzikis/ArduinoMD5
#include <SPI.h>
#include <Ethernet.h>  //change to UIPEthernet.h(http://github.com/ntruchsess/arduino_uip) if using the ENC28J60 ethernet module  
#define ENTROPY_FLAG  //Comment this line out to disable use of the Entropy true random number library to save memory. Warning this will compromise the security of the authentication process as the cookie will not be truly random
#ifdef ENTROPY_FLAG  //I don't think this works, the include will go through either way and probably the define too, probably have to comment to disable
  #include <Entropy.h>  //http://sites.google.com/site/astudyofentropy/file-cabinet
  //#define RANDOM_COOKIE //Uncomment this line to use the entropy random function for the cookie instead of the arduino random function for added security. This will increase the time required for the availableEvent() function to receive a new message and use more memory
#endif

//this will disable the compiler warning for F()
#ifdef PROGMEM
#undef PROGMEM
#define PROGMEM __attribute__((section(".progmem.data")))
#endif

#define DEBUG 0 // (0==serial debug output off, 1==serial debug output on)The serial debug output will greatly slow down communication time and so different timeout values are enabled.
#define Serial if(DEBUG)Serial
//#define SENDERIP_ENABLE //Uncomment this line if the ethernet library has been modified to return the client IP address via the remoteIP function. Modification instructions here: http://forum.arduino.cc/index.php?/topic,82416.0.html

#define MAGIC_WORD "quintessence\n\r"  //word used to trigger the cookie send from the receiver. I had to #define this instead of const because find() didn't like the const
#define ACCEPT_MESSAGE "accept\n"  //authentication success message. I had to #define this instead of const because find() didn't like the const

const char withoutRelease[]="withoutRelease";  //eg sends this every time and EtherEvent filters it out
const byte withoutReleaseLength=14;
const char payloadSeparator[]="payload ";  //indicates payload
const byte payloadSeparatorLength=8;  //includes space at the end
const char closeMessage[]="close\n";  //sender sends this message to the receiver to close the connection

const byte passwordLengthMax=20;
const byte cookieLengthMax=6;  //EtherEvent sends a 6 digit cookie(5 digit number and negative sign), eg seems to be a 4 digit cookie(socket), but it can be set larger if needed
const byte eventLengthMax=15;  //Maximum event length
const byte payloadLengthMax=60;  //Maximum payload length
const byte availableEventMessageLengthMax=payloadSeparatorLength+withoutReleaseLength+1+payloadSeparatorLength+payloadLengthMax+1+eventLengthMax;  //I'm using globals for these 2 so I can just calculate the buffer size in the setup() instead of every time the functions is called
byte availableEventSubmessageLengthMax;  //non-const because I have to use max()(in begin())

unsigned int timeout=250;  //(200)(ms)Timeout duration for each ethernet read/find of the availableEvent or sendEvent functions.
unsigned int listenTimeout=500;  //(400)(us)max time to wait for another char to be available from the client.read function during the availableEvent event/payload read - it was getting ahead of the stream and stopping before getting the whole message. This delay will be on every event receipt so it's important to make it as small as possible

char EEpassword[passwordLengthMax+1];
char receivedEvent[eventLengthMax+1];  //event buffer
char receivedPayload[payloadLengthMax+1];  //payload buffer
IPAddress fromIP(0,0,0,0);  //IP address of the last event sender


EtherEvent::EtherEvent(const char pass[]){
  strcpy(EEpassword,pass);  //store the password
  
  #ifdef ENTROPY_FLAG
    Entropy.initialize(); //gets truly random numbers from the timer jitter
    #ifndef RANDOM_COOKIE //randomSeed is not needed if the entropy random function is used via the RANDOM_COOKIE flag. 
      randomSeed(Entropy.random()); //Initialize the random function with a truly random value from the entropy library
    #endif
  #endif
  
  byte maxInput=payloadSeparatorLength+withoutReleaseLength;  //calculate the size of the payload/event buffer
  availableEventSubmessageLengthMax=max(eventLengthMax,maxInput);
  maxInput=payloadSeparatorLength+payloadLengthMax;
  availableEventSubmessageLengthMax=max(availableEventSubmessageLengthMax,maxInput);
  availableEventSubmessageLengthMax++;  //null terminator
}


byte EtherEvent::availableEvent(EthernetServer &etherEventServer){  //checks for senders, connects, authenticates, reads the event and payload into the buffer and returns the number of bytes of the most recently received event are left in the buffer
  if(byte length=strlen(receivedEvent)){    //strlen(receivedEvent)>0
    return length+1;   //number of bytes including the null terminator remaining to be read of the event
  }
  if(availablePayload()>0){  //don't get another event until the last is fully read or flushed
    return 0;
  }
  if(EthernetClient etherEventClient = etherEventServer.available() ){  //connect to the client
    Serial.println(F("availableEvent: connected--------------"));
    etherEventClient.setTimeout(timeout);  //timeout on read/readUntil/find/findUntil/etc    
    if(etherEventClient.find(MAGIC_WORD)==1){  //magic word correct
      Serial.println(F("availableEvent: magic word received"));
      #ifdef RANDOM_COOKIE
        Serial.println(F("availableEvent: RANDOM_COOKIE"));
        int cookieInt=Entropy.random(65536);  //true random cookie for highest security
      #else  
        //int cookieInt=random(65536);  //make random 5 digit number to use as cookie and send to the sender
        int cookieInt=random(10000,32768);  //using this to force a 5 digit cookie so I don't have to find the number of digits of the cookie for faster performance
      #endif
      char cookieChar[6];  //max 5 digits + minus + null terminator
      itoa(cookieInt,cookieChar,10);
      Serial.print(F("availableEvent: cookieChar="));
      Serial.println(cookieChar);
      cookieChar[5]=0;  //apparently itoa doesn't add a null terminator? the authentication gets all messed up without this
      etherEventClient.print(cookieChar);  //using ln because the cookie can be different lengths eg will take this also without the ln
      char cookiePassword[max(cookieLengthMax,5)+1+strlen(EEpassword)+1];  //cookie + password separator + Password + null terminator
      strcpy(cookiePassword,cookieChar); //create the hashword to compare to the received one
      strcat(cookiePassword,":"); //create the hashword to compare to the received one
      strcat(cookiePassword,EEpassword);
      Serial.print(F("availableEvent: cookiePassword="));
      Serial.println(cookiePassword);
      unsigned char* cookiePasswordHash=MD5::make_hash(cookiePassword);
      char *cookiePasswordMD5 = MD5::make_digest(cookiePasswordHash, 16);
      Serial.print(F("availableEvent: cookiePasswordMD5="));
      Serial.println(cookiePasswordMD5);
      if(etherEventClient.find(cookiePasswordMD5)==1){
        etherEventClient.flush();  //clear the \n or it will cause a null message in the payload/event message read
        Serial.println(F("availableEvent: authentication successful"));
        etherEventClient.print(ACCEPT_MESSAGE);
        free(cookiePasswordMD5);
    
        Serial.println(F("availableEvent: payload/event handler start"));
        unsigned long timeStamp=millis();
        byte availableLength=0;
        while(availableLength<2){  //wait for a message. I have to do this because available() doesn't have a timeout, it just gives the currently available
          availableLength=etherEventClient.available();
          if(millis()>timeStamp+timeout){  //timeout
            Serial.println(F("availableEvent: timeout"));
            etherEventStop(etherEventClient);
            return 0;
          }
        }
        timeStamp=micros();  //reusing this variable for both wait loops
        do{  //it takes a bit of time for the full message to come through so it has to wait for the available to be final
          if(availableLength>=availableEventMessageLengthMax+1){  //break out of the loop if it has enough
            availableLength=availableEventMessageLengthMax+1;
            break;
          }
          if(availableLength<etherEventClient.available()){
            timeStamp=micros();
            availableLength=etherEventClient.available();
          }
        }while(micros()<timeStamp+listenTimeout);
        Serial.print(F("availableEvent: availableLength="));
        Serial.println(availableLength);
        for(;;){
          Serial.println(F("availableEvent: payload/event for loop"));
          byte receivedMessageSize=min(availableLength,availableEventSubmessageLengthMax);  //determine the max buffer size required
          char receivedMessage[receivedMessageSize];  //initialize the buffer to read into
          byte bytesRead=0;
          bytesRead=etherEventClient.readBytesUntil(10,receivedMessage,receivedMessageSize);  //put the incoming data up to the newline into receivedMessage
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
              char receivedPayloadTemp[payloadLengthMax+1];
              for(payloadCount=0;payloadCount<receivedPayloadLength;payloadCount++){
                receivedPayloadTemp[payloadCount]=receivedMessage[payloadCount+payloadSeparatorLength];
              }
              receivedPayloadTemp[payloadCount+1]=0;
              if(strncmp(receivedPayloadTemp, withoutRelease, withoutReleaseLength)==0){
                Serial.println(F("availableEvent: withoutRelease"));
                receivedPayloadTemp[0]=0;  //delete the withoutRelease from the payload so it will be blank if there is no payload
                continue;
              }
              strcpy(receivedPayload, receivedPayloadTemp);
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
            if(strncmp(receivedMessage,closeMessage,5)==0){
              Serial.println(F("availableEvent: close received, no event"));
              break;
            }
            strncpy(receivedEvent,receivedMessage,eventLengthMax);
            receivedEvent[bytesRead]=0;
            Serial.print(F("availableEvent: event received="));              
            Serial.println(receivedEvent);
            #ifdef SENDERIP_ENABLE
              byte tempIP[4];
              etherEventClient.getRemoteIP(tempIP);  //Save the IP address of the sender. Requires modified ethernet library
              fromIP=tempIP;
            #endif
            break;  //exit the payload/event message handler loop
          }
        }
      }
      else{
        free(cookiePasswordMD5);
        Serial.println(F("availableEvent: authentication failed"));
      }
    }
    etherEventStop(etherEventClient);
    if(byte length=strlen(receivedEvent)){  //there is an event
      return length+1;
    }
  }
  return 0;  //no event
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
    

byte EtherEvent::send(EthernetClient &etherEventClient, const IPAddress sendIP, unsigned int sendPort, const char sendEvent[], const char sendPayload[]){
  Serial.println(F("sendEvent: attempting connection---------------"));
  etherEventClient.setTimeout(timeout);  //timeout on read/readUntil/find/findUntil/etc      
  byte sendEventSuccess=0;
  if(etherEventClient.connect(sendIP,sendPort)){  //connected to receiver

    Serial.println(F("sendEvent: connected, sending magic word"));
    etherEventClient.print(MAGIC_WORD);  //send the magic word to the receiver so it will send the cookie

    char receivedMessage[cookieLengthMax+1];
    byte bytesRead;
    if(bytesRead=etherEventClient.readBytesUntil(10,receivedMessage,cookieLengthMax)){

      receivedMessage[bytesRead]=0;
      char cookiePassword[bytesRead+1+strlen(EEpassword)+1];  //cookie, password separator(:), password, null terminator
      strcpy(cookiePassword,receivedMessage);
      strcat(cookiePassword,":");  //add the password separator to the cookie
      strcat(cookiePassword,EEpassword); //add password to the cookie
      Serial.print(F("sendEvent: cookiePassword="));
      Serial.println(cookiePassword);
      unsigned char* cookiePasswordHash=MD5::make_hash(cookiePassword);
      char *cookiePasswordMD5 = MD5::make_digest(cookiePasswordHash, 16);
      Serial.print(F("sendEvent: hashWordMD5="));
      Serial.println(cookiePasswordMD5);
      cookiePasswordMD5[32]=10;  //add /n - it fails the authentication with eg without this
      cookiePasswordMD5[33]=0;  //add the null terminator(otherwise it will keep printing garbage after the end of the string and the /n
      etherEventClient.print(cookiePasswordMD5);  //send the MD5 of the hashword
      free(cookiePasswordMD5);
  
      if(etherEventClient.find(ACCEPT_MESSAGE)==1){
        Serial.print(F("sendEvent: Payload="));
        Serial.println(sendPayload);
        Serial.print(F("sendEvent: event="));
        Serial.println(sendEvent);
        if(sendPayload[0]!=0){  //check if there is a payload
          etherEventClient.print(payloadSeparator);
          etherEventClient.print(sendPayload);
          etherEventClient.write(10);
        }
        etherEventClient.print(sendEvent);
        etherEventClient.write(10);
        sendEventSuccess=1;
      }
    }
    etherEventStop(etherEventClient);  //close the connection
  }
  else{
    Serial.println(F("sendEvent connection failed"));
  }
  return sendEventSuccess;  //send finished
}


void EtherEvent::etherEventStop(EthernetClient &client){
  Serial.println(F("etherEventStop: stopping..."));
  client.print(closeMessage);  //tell the receiver to close
  client.stop();
  Serial.println(F("etherEventStop: stopped"));
}


void EtherEvent::setTimeout(unsigned int timeoutNew, unsigned int timeoutListenNew){
  timeout=timeoutNew;
  listenTimeout=timeoutListenNew;
}
