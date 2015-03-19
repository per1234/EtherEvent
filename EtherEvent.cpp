//EtherEvent - Easy to use password authenticated network communication between Arduinos and EventGhost Network Event Sender/Receiver plugin,  EventGhost TCPEvents plugin,  Girder,  and NetRemote http://github.com/per1234/EtherEvent
#include <Arduino.h>
#include "EtherEvent.h"
#include <SPI.h>
#include <Ethernet.h>   //change to UIPEthernet.h(http://github.com/ntruchsess/arduino_uip) if using the ENC28J60 ethernet module  
#include "MD5.h"  //http://github.com/tzikis/ArduinoMD5 


//-----------------------------------------------------------------------------------------------------------
//START user configuration parameters
//-----------------------------------------------------------------------------------------------------------
//#include "Entropy.h"  //http://sites.google.com/site/astudyofentropy/file-cabinet Uncomment this line if you have the Entropy library installed. Warning, not using the library will save memory at the expense of authentication security.

//#define SENDERIP_ENABLE //Uncomment this line if the ethernet library has been modified to return the client IP address via the remoteIP function. Modification instructions here: http://forum.arduino.cc/index.php?topic=82416.0
const boolean randomCookie = 0;   //Set to 1 to use the entropy random function for the cookie instead of the arduino random function for added security. This will increase the time required for the availableEvent() function to receive a new message and use more memory

#define DEBUG 0 // (0 == serial debug output off,  1 == serial debug output on)The serial debug output will greatly increase communication time.
#define Serial if(DEBUG)Serial
//-----------------------------------------------------------------------------------------------------------
//END user configuration parameters
//-----------------------------------------------------------------------------------------------------------

//this will fix the Arduino 1.0.x compiler warning for F()
#ifdef PROGMEM
#undef PROGMEM
#define PROGMEM __attribute__((section(".progmem.data")))
#endif

#define MAGIC_WORD "quintessence\n\r"  //word used to trigger the cookie send from the receiver. I had to #define this instead of const because find() didn't like the const
#define ACCEPT_MESSAGE "accept\n"  //authentication success message. I had to #define this instead of const because find() didn't like the const

const char withoutRelease[] = "withoutRelease";   //eg sends this every time and EtherEvent filters it out
const byte withoutReleaseLength = 14;
const char payloadSeparator[] = "payload ";   //indicates payload
const byte payloadSeparatorLength = 8;   //includes space at the end
const char closeMessage[] = "close\n";   //sender sends this message to the receiver to close the connection
const unsigned int timeoutDefault = 300;   //(200)(ms)Timeout duration for each ethernet read/find of the availableEvent or sendEvent functions.
const unsigned int listenTimeoutDefault = 600;   //(400)(us)max time to wait for another char to be available from the client.read function during the availableEvent event/payload read - it was getting ahead of the stream and stopping before getting the whole message. This delay will be on every event receipt so it's important to make it as small as possible
const byte cookieLengthMax = 6;   //EtherEvent sends a 6 digit cookie(5 digit number and negative sign),  eg seems to be a 4 digit cookie(socket),  but it can be set larger if needed
const byte availableEventMessageLengthMax = payloadSeparatorLength + withoutReleaseLength + 1 + payloadSeparatorLength + etherEvent_payloadLengthMax + 1 + etherEvent_eventLengthMax;   //I'm using globals for these 2 so I can just calculate the buffer size in the setup() instead of every time the functions is called


//-----------------------------------------------------------------------------------------------------------
//begin
//-----------------------------------------------------------------------------------------------------------
void EtherEventClass::begin(const char pass[]) {
  strcpy(EEpassword, pass);   //store the password
  timeout = timeoutDefault;
  listenTimeout = listenTimeoutDefault;

#ifdef Entropy_h  //the Entropy library is in use
  Entropy.initialize();  //gets truly random numbers from the timer jitter
  if (randomCookie == 0) { //randomSeed is not needed if the entropy random function is used for every cookie instead of just the randomSeed
    randomSeed(Entropy.random());  //Initialize the random function with a truly random value from the entropy library
  }
#endif

  byte maxInput = payloadSeparatorLength + withoutReleaseLength;   //calculate the size of the payload/event buffer
  availableEventSubmessageLengthMax = max(etherEvent_eventLengthMax, maxInput);
  maxInput = payloadSeparatorLength + etherEvent_payloadLengthMax;
  availableEventSubmessageLengthMax = max(availableEventSubmessageLengthMax, maxInput);
  availableEventSubmessageLengthMax++;   //null terminator
}


//-----------------------------------------------------------------------------------------------------------
//availableEvent
//-----------------------------------------------------------------------------------------------------------
byte EtherEventClass::availableEvent(EthernetServer &ethernetServer) { //checks for senders,  connects,  authenticates,  reads the event and payload into the buffer and returns the number of bytes of the most recently received event are left in the buffer
  if (byte length = strlen(receivedEvent)) {  //strlen(receivedEvent) > 0
    return length + 1;    //number of bytes including the null terminator remaining to be read of the event
  }
  if (availablePayload() > 0) { //don't get another event until the last is fully read or flushed
    return 0;
  }
  if (EthernetClient ethernetClient = ethernetServer.available() ) { //connect to the client
    Serial.println(F("EtherEvent.availableEvent: connected--------------"));
    ethernetClient.setTimeout(timeout);   //timeout on read/readUntil/find/findUntil/etc
    if (ethernetClient.find(MAGIC_WORD) == 1) { //magic word correct
      Serial.println(F("EtherEvent.availableEvent: magic word received"));
      int cookieInt;
#ifdef Entropy_h
      if (randomCookie == 1) {
        Serial.println(F("EtherEvent.availableEvent: RANDOM_COOKIE"));
        cookieInt = Entropy.random(65536);   //true random cookie for highest security
      }
      else {
#endif
        //int cookieInt = random(65536);   //make random 5 digit number to use as cookie and send to the sender
        cookieInt = random(10000, 32768);   //using this to force a 5 digit cookie so I don't have to find the number of digits of the cookie for faster performance
#ifdef Entropy_h
      }
#endif
      char cookieChar[6];   //max 5 digits  +  minus  +  null terminator
      itoa(cookieInt, cookieChar, 10);
      Serial.print(F("EtherEvent.availableEvent: cookieChar="));
      Serial.println(cookieChar);
      cookieChar[5] = 0;   //apparently itoa doesn't add a null terminator? the authentication gets all messed up without this
      ethernetClient.print(cookieChar);   //using ln because the cookie can be different lengths eg will take this also without the ln
      char cookiePassword[max(cookieLengthMax, 5) + 1 + strlen(EEpassword) + 1];   //cookie  +  password separator  +  Password  +  null terminator
      strcpy(cookiePassword, cookieChar);  //create the hashword to compare to the received one
      strcat(cookiePassword, ":");  //create the hashword to compare to the received one
      strcat(cookiePassword, EEpassword);
      Serial.print(F("EtherEvent.availableEvent: cookiePassword="));
      Serial.println(cookiePassword);
      unsigned char* cookiePasswordHash = MD5::make_hash(cookiePassword);
      char *cookiePasswordMD5 = MD5::make_digest(cookiePasswordHash,  16);
      free(cookiePasswordHash);
      Serial.print(F("EtherEvent.availableEvent: cookiePasswordMD5="));
      Serial.println(cookiePasswordMD5);
      if (ethernetClient.find(cookiePasswordMD5) == 1) { //authentication successful
        ethernetClient.flush();   //clear the \n or it will cause a null message in the payload/event message read
        Serial.println(F("EtherEvent.availableEvent: authentication successful"));
        ethernetClient.print(ACCEPT_MESSAGE);
        free(cookiePasswordMD5);

        Serial.println(F("EtherEvent.availableEvent: payload/event handler start"));
        unsigned long timeStamp = millis();
        byte availableLength = 0;
        while (availableLength < 2) { //wait for a message. I have to do this because available() doesn't have a timeout,  it just gives the currently available
          availableLength = ethernetClient.available();
          if (millis() - timeStamp > timeout) { //timeout
            Serial.println(F("EtherEvent.availableEvent: timeout"));
            etherEventStop(ethernetClient);
            return 0;
          }
        }
        timeStamp = micros();   //reusing this variable for both wait loops
        do { //it takes a bit of time for the full message to come through so it has to wait for the available to be final
          if (availableLength >= availableEventMessageLengthMax + 1) { //break out of the loop if it has enough
            availableLength = availableEventMessageLengthMax + 1;
            break;
          }
          if (availableLength < ethernetClient.available()) {
            timeStamp = micros();
            availableLength = ethernetClient.available();
          }
        } while (micros() - timeStamp < listenTimeout);
        Serial.print(F("EtherEvent.availableEvent: availableLength="));
        Serial.println(availableLength);
        for (byte count = 0; count < 20; count++) { //the count stuff is just to make sure it will never go into an infinite loop
          Serial.println(F("EtherEvent.availableEvent: payload/event for loop"));
          byte receivedMessageSize = min(availableLength, availableEventSubmessageLengthMax);   //determine the max buffer size required
          char receivedMessage[receivedMessageSize];   //initialize the buffer to read into
          byte bytesRead = 0;
          bytesRead = ethernetClient.readBytesUntil(10, receivedMessage, receivedMessageSize);   //put the incoming data up to the newline into receivedMessage
          availableLength = availableLength - bytesRead; //used to reduce the buffer size on the next loop
          receivedMessage[bytesRead] = 0;   //add a null terminator
          Serial.print(F("EtherEvent.availableEvent: bytesRead="));
          Serial.println(bytesRead);
          if (bytesRead == 0) { //with Arduino 1.5 there is a leading char(10) for some reason(maybe flush() doesn't work and it's still left over from the last message?). This will handle null messages
            continue;
          }
          if (strncmp(receivedMessage,  payloadSeparator,  payloadSeparatorLength) == 0) { //received message is a payload
            Serial.println(F("EtherEvent.availableEvent: payload separator received"));
            if (bytesRead > payloadSeparatorLength + 1) { //there is a payload
              byte receivedPayloadLength = bytesRead - payloadSeparatorLength + 1; //including the null terminator
              Serial.print(F("EtherEvent.availableEvent: payload length(including null terminator)="));
              Serial.println(receivedPayloadLength);
              byte payloadCount = 0;
              char receivedPayloadTemp[etherEvent_payloadLengthMax + 1];
              for (payloadCount = 0; payloadCount < receivedPayloadLength; payloadCount++) {
                receivedPayloadTemp[payloadCount] = receivedMessage[payloadCount + payloadSeparatorLength];
              }
              receivedPayloadTemp[payloadCount + 1] = 0;
              if (strncmp(receivedPayloadTemp,  withoutRelease,  withoutReleaseLength) == 0) {
                Serial.println(F("EtherEvent.availableEvent: withoutRelease"));
                receivedPayloadTemp[0] = 0;   //delete the withoutRelease from the payload so it will be blank if there is no payload
                continue;
              }
              strcpy(receivedPayload,  receivedPayloadTemp);
              Serial.print(F("EtherEvent.availableEvent: payload="));
              Serial.println(receivedPayload);
            }
            else { //no payload
              Serial.println(F("EtherEvent.availableEvent: no payload"));
            }
            continue;
          }
          else {

            Serial.print(F("EtherEvent.availableEvent: event length="));
            Serial.println(bytesRead);
            if (strncmp(receivedMessage, closeMessage, 5) == 0) {
              Serial.println(F("EtherEvent.availableEvent: close received,  no event"));
              break;
            }
            strncpy(receivedEvent, receivedMessage, etherEvent_eventLengthMax);
            receivedEvent[bytesRead] = 0;
            Serial.print(F("EtherEvent.availableEvent: event received="));
            Serial.println(receivedEvent);
#ifdef SENDERIP_ENABLE
            byte tempIP[4];
            ethernetClient.getRemoteIP(tempIP);   //Save the IP address of the sender. Requires modified ethernet library
            fromIP = tempIP;
#endif
            break;   //exit the payload/event message handler loop
          }
        }
      }
      else {
        free(cookiePasswordMD5);
        Serial.println(F("EtherEvent.availableEvent: authentication failed"));
      }
    }
    etherEventStop(ethernetClient);
    if (byte length = strlen(receivedEvent)) { //there is an event
      return length + 1;
    }
  }
  return 0;   //no event
}


//-----------------------------------------------------------------------------------------------------------
//availablePayload
//-----------------------------------------------------------------------------------------------------------
byte EtherEventClass::availablePayload() { //returns the number of chars in the payload including the null terminator if there is one
  if (byte length = strlen(receivedPayload)) { //strlen(receivedPayload) > 0
    return length + 1;   //length of the payload  +  null terminator
  }
  return 0;
}


//-----------------------------------------------------------------------------------------------------------
//readEvent
//-----------------------------------------------------------------------------------------------------------
void EtherEventClass::readEvent(char eventBuffer[]) {
  strcpy(eventBuffer, receivedEvent);
  eventBuffer[strlen(receivedEvent)] = 0;   //null terminator - is this needed?
  receivedEvent[0] = 0;   //reset the event buffer
}


//-----------------------------------------------------------------------------------------------------------
//readPayload
//-----------------------------------------------------------------------------------------------------------
void EtherEventClass::readPayload(char payloadBuffer[]) {
  strcpy(payloadBuffer, receivedPayload);
  payloadBuffer[strlen(receivedPayload)] = 0;   //null terminator - is this needed?
  receivedPayload[0] = 0;   //reset the payload buffer
}


//-----------------------------------------------------------------------------------------------------------
//flushReceiver
//-----------------------------------------------------------------------------------------------------------
void EtherEventClass::flushReceiver() { //dump the last message received so another one can be received
  Serial.println(F("EtherEvent.flushReceiver: start"));
  receivedEvent[0] = 0;   //reset the event buffer
  receivedPayload[0] = 0;   //reset the payload buffer
}


//-----------------------------------------------------------------------------------------------------------
//senderIP
//-----------------------------------------------------------------------------------------------------------
IPAddress EtherEventClass::senderIP() { //returns the ip address the current event was sent from. Requires modified ethernet library,  thus the preprocesser direcive system
  return fromIP;
}


//-----------------------------------------------------------------------------------------------------------
//send
//-----------------------------------------------------------------------------------------------------------
boolean EtherEventClass::send(EthernetClient &ethernetClient,  const IPAddress sendIP,  unsigned int sendPort,  const char sendEvent[],  const char sendPayload[]) {
  Serial.println(F("EtherEvent.sendEvent: attempting connection---------------"));
  ethernetClient.setTimeout(timeout);   //timeout on read/readUntil/find/findUntil/etc
  byte sendEventSuccess = 0;
  if (ethernetClient.connect(sendIP, sendPort)) { //connected to receiver

    Serial.println(F("EtherEvent.sendEvent: connected,  sending magic word"));
    ethernetClient.print(MAGIC_WORD);   //send the magic word to the receiver so it will send the cookie

    char receivedMessage[cookieLengthMax + 1];
    byte bytesRead;
    if (bytesRead = ethernetClient.readBytesUntil(10, receivedMessage, cookieLengthMax)) {

      receivedMessage[bytesRead] = 0;
      char cookiePassword[bytesRead + 1 + strlen(EEpassword) + 1];   //cookie,  password separator(:),  password,  null terminator
      strcpy(cookiePassword, receivedMessage);
      strcat(cookiePassword, ":");   //add the password separator to the cookie
      strcat(cookiePassword, EEpassword);  //add password to the cookie
      Serial.print(F("EtherEvent.sendEvent: cookiePassword="));
      Serial.println(cookiePassword);
      unsigned char* cookiePasswordHash = MD5::make_hash(cookiePassword);
      char *cookiePasswordMD5 = MD5::make_digest(cookiePasswordHash,  16);
      free(cookiePasswordHash);
      Serial.print(F("EtherEvent.sendEvent: hashWordMD5="));
      Serial.println(cookiePasswordMD5);
      ethernetClient.print(cookiePasswordMD5);   //send the MD5 of the hashword
      ethernetClient.write(10);
      free(cookiePasswordMD5);

      if (ethernetClient.find(ACCEPT_MESSAGE) == 1) {
        Serial.print(F("EtherEvent.sendEvent: Payload="));
        Serial.println(sendPayload);
        Serial.print(F("EtherEvent.sendEvent: event="));
        Serial.println(sendEvent);
        if (sendPayload[0] != 0) { //check if there is a payload
          ethernetClient.print(payloadSeparator);
          ethernetClient.print(sendPayload);
          ethernetClient.write(10);
        }
        ethernetClient.print(sendEvent);
        ethernetClient.write(10);
        sendEventSuccess = 1;
      }
    }
    etherEventStop(ethernetClient);   //close the connection
  }
  else {
    Serial.println(F("EtherEvent.sendEvent connection failed"));
  }
  return sendEventSuccess;   //send finished
}


//-----------------------------------------------------------------------------------------------------------
//setTimeout
//-----------------------------------------------------------------------------------------------------------
void EtherEventClass::setTimeout(unsigned int timeoutNew,  unsigned int timeoutListenNew) {
  timeout = timeoutNew;
  listenTimeout = timeoutListenNew;
}


//-----------------------------------------------------------------------------------------------------------
//private
//-----------------------------------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------------------------------
//etherEventStop
//-----------------------------------------------------------------------------------------------------------
void EtherEventClass::etherEventStop(EthernetClient &ethernetClient) {
  Serial.println(F("EtherEvent.etherEventStop: stopping..."));
  ethernetClient.print(closeMessage);   //tell the receiver to close
  ethernetClient.stop();
  Serial.println(F("EtherEvent.etherEventStop: stopped"));
}


EtherEventClass EtherEvent;  //This sets up a single global instance of the library so the class doesn't need to be declared in the user sketch and multiple instances are not necessary in this case.
