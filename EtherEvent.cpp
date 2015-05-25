// EtherEvent - Easy to use password authenticated network communication between Arduinos and EventGhost Network Event Sender/Receiver plugin,  EventGhost TCPEvents plugin,  Girder,  and NetRemote http://github.com/per1234/EtherEvent
#include "EtherEvent.h"
#include <SPI.h>
#include "Ethernet.h"  //change to UIPEthernet.h if using the ENC28J60 ethernet module  
#include "MD5.h"
//#include "Flash.h"  //uncomment this line if you have the Flash library installed


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//START user configuration parameters
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include "Entropy.h"  //Uncomment this line if you have the Entropy library installed. Warning, not using the library will save memory at the expense of authentication security.

const boolean randomCookie = false;  //Set to true to use the entropy random function for the cookie instead of the arduino random function for added security. This will increase the time required for the availableEvent() function to receive a new message and use more memory.

#define DEBUG false  //(false == serial debug output off,  true == serial debug output on)The serial debug output will increase memory usage and communication latency so only enable when in use.
#define Serial if(DEBUG)Serial
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//END user configuration parameters
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define MAGIC_WORD "quintessence\n\r"  //word used to trigger the cookie send from the receiver. I had to #define this instead of const because find() didn't like the const
#define ACCEPT_MESSAGE "accept\n"  //authentication success message. I had to #define this instead of const because find() didn't like the const

const char payloadWithoutRelease[] = "payload withoutRelease";  //eg sends this every time and EtherEvent filters it out
const byte payloadWithoutReleaseLength = strlen(payloadWithoutRelease);
const char payloadSeparator[] = "payload ";  //indicates payload
const byte payloadSeparatorLength = strlen(payloadSeparator);  //includes space at the end
const char closeMessage[] = "close\n";  //sender sends this message to the receiver to close the connection
const byte closeMessageLength = strlen(closeMessage);
const unsigned int timeoutDefault = 1000;  //(ms)Timeout duration for ethernet stream functions.
const byte cookieLengthMax = 5;  //EtherEvent sends a 5 digit cookie,  EventGhost seems to send a 4 digit cookie(socket),  but it can be set larger if needed


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//constructor
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
EtherEventClass::EtherEventClass() {
  timeout = timeoutDefault;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//begin
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
boolean EtherEventClass::begin(const byte eventLengthMaxInput, const byte payloadLengthMaxInput) {
#if DEBUG == true
  delay(20);  //There needs to be a delay between the calls to Serial.begin() in sketch setup() and here or garbage will be printed to the serial monitor
#endif
  Serial.begin(9600);  //for debugging
  Serial.println(F("\n\n\nEtherEvent.begin"));
  //set default timeout values, these globals can be changed by the user via setTimeout()
  availableEventSubmessageLengthMax = max(max(payloadWithoutReleaseLength, payloadSeparatorLength + payloadLengthMax), eventLengthMax);
  eventLengthMax = eventLengthMaxInput;
  payloadLengthMax = payloadLengthMaxInput;
  receivedEvent = (char*)realloc(receivedEvent, (eventLengthMax + 1) * sizeof(*receivedEvent));
  receivedEvent[0] = 0;  //clear buffer - realloc does not zero initialize so the buffer could contain anything
  receivedPayload = (char*)realloc(receivedPayload, (payloadLengthMax + 1) * sizeof(*receivedPayload));
  receivedPayload[0] = 0;  //clear buffer - realloc does not zero initialize so the buffer could contain anything
  if (receivedEvent == NULL || receivedPayload == NULL) {
    Serial.println(F("memory allocation failed"));
    return false;
  }

#ifdef Entropy_h  //the Entropy library is in use
  Entropy.initialize();  //gets truly random numbers from the timer jitter
  if (randomCookie == false) {  //randomSeed is not needed if the entropy random function is used for every cookie instead of just the randomSeed
    randomSeed(Entropy.random());  //Initialize the random function with a truly random value from the entropy library
  }
#endif
  return true;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//availableEvent - checks for senders,  connects,  authenticates,  reads the event and payload into the buffer and returns the number of bytes of the most recently received event are left in the buffer
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
byte EtherEventClass::availableEvent(EthernetServer &ethernetServer) {
  if (receivedEventLength == 0) {  //no event buffered
    if (EthernetClient ethernetClient = ethernetServer.available() ) {  //connect to the client
      Serial.println(F("EtherEvent.availableEvent: connected"));
      ethernetClient.setTimeout(timeout);  //timeout on read/readUntil/find/findUntil/etc

      if (ethernetClient.find(MAGIC_WORD) == 1) {  //magic word correct
        Serial.println(F("EtherEvent.availableEvent: magic word received"));

        //create and send cookie
        int cookie;
#ifdef Entropy_h
        if (randomCookie == 1) {
          Serial.println(F("EtherEvent.availableEvent: RANDOM_COOKIE"));
          cookie = Entropy.random();  //true random cookie for highest security - returns unsigned long
        }
        else {
#endif
          cookie = random(65536);  //make random 5 digit number to use as cookie and send to the sender, random returns a long but I'm limiting it to
#ifdef Entropy_h
        }
#endif
        char cookiePassword[5 + 1 + passwordLength + 1];  //cookie  +  password separator  +  Password  +  null terminator
        sprintf_P(cookiePassword, PSTR("%u"), cookie);  //convert the unsigned long cookie to char
        Serial.print(F("EtherEvent.availableEvent: cookie: "));
        Serial.println(cookiePassword);
        ethernetClient.print(cookiePassword);  //send the cookie

        //calculate the hashword
        strcat(cookiePassword, ":");  //create the hashword to compare to the received one
        strcat(cookiePassword, password);
        Serial.print(F("EtherEvent.availableEvent: cookiePassword: "));
        Serial.println(cookiePassword);
        unsigned char* cookiePasswordHash = MD5::make_hash(cookiePassword);
        char *cookiePasswordMD5 = MD5::make_digest(cookiePasswordHash,  16);
        free(cookiePasswordHash);
        Serial.print(F("EtherEvent.availableEvent: cookiePasswordMD5: "));
        Serial.println(cookiePasswordMD5);

        //verify the received hashword
        if (ethernetClient.find(cookiePasswordMD5) == 1) {  //authentication successful
          ethernetClient.flush();  //clear the \n or it will cause a null message in the payload/event message read
          Serial.println(F("EtherEvent.availableEvent: authentication successful"));
          ethernetClient.print(ACCEPT_MESSAGE);
          free(cookiePasswordMD5);

          //Read and process the message
          for (byte count = 0; count < 7; count++) {  //Read and process the count stuff is just to make sure it will never go into an infinite loop
            Serial.println(F("EtherEvent.availableEvent: payload/event for loop"));
            char receivedMessage[availableEventSubmessageLengthMax + 1];  //initialize the buffer to read into
            const byte bytesRead = ethernetClient.readBytesUntil(10, receivedMessage, availableEventSubmessageLengthMax);  //put the incoming data up to the newline into receivedMessage
            Serial.print(F("EtherEvent.availableEvent: bytesRead: "));
            Serial.println(bytesRead);
            if (bytesRead == 0) {  //with Arduino 1.5 there is a leading char(10) for some reason(maybe flush() doesn't work and it's still left over from the last message?). This will handle null messages
              continue;
            }
            receivedMessage[bytesRead] = 0;  //add a null terminator

            if (strncmp(receivedMessage,  payloadSeparator,  payloadSeparatorLength) == 0) {  //received message is a payload
              Serial.println(F("EtherEvent.availableEvent: payload separator received"));
              if (bytesRead > payloadSeparatorLength) {  //there is a payload

                if (strncmp(receivedMessage,  payloadWithoutRelease,  payloadWithoutReleaseLength) == 0) {  //"withoutRelease" received
                  Serial.println(F("EtherEvent.availableEvent: payloadWithoutRelease"));
                  continue;
                }

                const byte receivedPayloadLength = bytesRead - payloadSeparatorLength;
                Serial.print(F("EtherEvent.availableEvent: payload length: "));
                Serial.println(receivedPayloadLength);
                const byte readPayloadLength = min(receivedPayloadLength, payloadLengthMax);  //make sure the payload will never be longer than the max length
                for (byte payloadCount = 0; payloadCount < readPayloadLength; payloadCount++) {  //put the payload into the buffer
                  receivedPayload[payloadCount] = receivedMessage[payloadCount + payloadSeparatorLength];
                }
                receivedPayload[readPayloadLength] = 0;  //null terminator
                Serial.print(F("EtherEvent.availableEvent: payload: "));
                Serial.println(receivedPayload);
              }

              else {  //no payload
                Serial.println(F("EtherEvent.availableEvent: no payload"));
              }
              continue;
            }

            else {  //received message is event
              Serial.print(F("EtherEvent.availableEvent: event length: "));
              Serial.println(bytesRead);
              if (strncmp(receivedMessage, closeMessage, closeMessageLength) == 0) {
                Serial.println(F("EtherEvent.availableEvent: close received,  no event"));
                break;
              }
              strncpy(receivedEvent, receivedMessage, eventLengthMax);
              receivedEventLength = min(bytesRead, eventLengthMax) + 1;  //length including null terminator
              receivedEvent[receivedEventLength - 1] = 0;  //-1 because it is zero indexed and the receivedEventLength includes the null terminator
              Serial.print(F("EtherEvent.availableEvent: event received: "));
              Serial.println(receivedEvent);

              //save the sender IP address
#ifdef ethernetclientwithremoteIP_h  //the include guard from the modified EthernetClient.h
              byte tempIP[4];  //W5100 uses the byte array to return the IP address so I have to do this to convert it to IPAddress type instead of just passing fromIP to getRemoteIP()
              ethernetClient.remoteIP(tempIP);  //Save the IP address of the sender. Requires modified ethernet library
              fromIP = tempIP;
#endif

              break;  //exit the payload/event message handler loop
            }
          }
        }

        //authentication failed
        else {
          free(cookiePasswordMD5);
          Serial.println(F("EtherEvent.availableEvent: authentication failed"));
        }
      }
      ethernetClient.print(closeMessage);  //tell the receiver to close
      ethernetClient.stop();
      Serial.println(F("EtherEvent.availableEvent: connection closed"));
    }
  }
  return receivedEventLength;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//availablePayload - returns the number of chars in the payload including the null terminator if there is one
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
byte EtherEventClass::availablePayload() {
  if (byte receivedPayloadLength = strlen(receivedPayload)) {  //strlen(receivedPayload) > 0
    return receivedPayloadLength + 1;  //length of the payload  +  null terminator
  }
  return false;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//readEvent
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void EtherEventClass::readEvent(char eventBuffer[]) {
  strcpy(eventBuffer, receivedEvent);
  receivedEvent[0] = 0;  //reset the event buffer
  receivedEventLength = 0;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//readPayload
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void EtherEventClass::readPayload(char payloadBuffer[]) {
  strcpy(payloadBuffer, receivedPayload);
  receivedPayload[0] = 0;  //reset the payload buffer
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//flushReceiver - dump the last message received so another one can be received
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void EtherEventClass::flushReceiver() {
  Serial.println(F("EtherEvent.flushReceiver: start"));
  receivedEvent[0] = 0;  //reset the event buffer
  receivedPayload[0] = 0;  //reset the payload buffer
  receivedEventLength = 0;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//senderIP
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef ethernetclientwithremoteIP_h  //the include guard from the modified EthernetClient.h
IPAddress EtherEventClass::senderIP() {  //returns the ip address the current event was sent from. Requires modified ethernet library,  thus the preprocesser direcive system
  return fromIP;
}
#endif


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//send
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
boolean EtherEventClass::send(EthernetClient &ethernetClient, const byte target[], const unsigned int port, const char event[], const char payload[]) {
  IPAddress targetIP = IPAddress(target[0], target[1], target[2], target[3]);
  return send(ethernetClient, targetIP, port, event, payload);
}

boolean EtherEventClass::send(EthernetClient &ethernetClient, const IPAddress target, const unsigned int port, const char event[], const char payload[]) {
  Serial.println(F("EtherEvent.send: attempting connection"));
  Serial.print(F("EtherEvent.send: target: "));
  Serial.println(target);
  Serial.print(F("EtherEvent.send: port: "));
  Serial.println(port);
  Serial.print(F("EtherEvent.send: event: "));
  Serial.println(event);
  Serial.print(F("EtherEvent.send: payload: "));
  Serial.println(payload);
  ethernetClient.setTimeout(timeout);  //timeout on read/readUntil/find/findUntil/etc
  byte eventSuccess = false;
  if (ethernetClient.connect(target, port)) {  //connected to receiver

    Serial.println(F("EtherEvent.send: connected, sending magic word"));
    ethernetClient.print(MAGIC_WORD);  //send the magic word to the receiver so it will send the cookie

    char cookiePassword[cookieLengthMax + 1 + passwordLength + 1];  //cookie,  password separator(:),  password,  null terminator
    if (byte bytesRead = ethernetClient.readBytesUntil(10, cookiePassword, cookieLengthMax)) {  //get the cookie
      cookiePassword[bytesRead] = 0;
      strcat(cookiePassword, ":");  //add the password separator to the cookie
      strcat(cookiePassword, password);  //add password to the cookie
      Serial.print(F("EtherEvent.send: cookiePassword: "));
      Serial.println(cookiePassword);
      unsigned char* cookiePasswordHash = MD5::make_hash(cookiePassword);
      char *cookiePasswordMD5 = MD5::make_digest(cookiePasswordHash,  16);
      free(cookiePasswordHash);
      Serial.print(F("EtherEvent.send: hashWordMD5: "));
      Serial.println(cookiePasswordMD5);
      ethernetClient.print(cookiePasswordMD5);  //send the MD5 of the hashword
      ethernetClient.write(10);  //newline
      free(cookiePasswordMD5);

      if (ethernetClient.find(ACCEPT_MESSAGE) == 1) {  //authentication successful
        Serial.print(F("EtherEvent.send: Payload: "));
        Serial.println(payload);
        Serial.print(F("EtherEvent.send: event: "));
        Serial.println(event);
        if (payload[0] != 0) {  //check if there is a payload
          ethernetClient.print(payloadSeparator);
          ethernetClient.print(payload);
          ethernetClient.write(10);  //newline
        }
        ethernetClient.print(event);  //transmit event
        ethernetClient.write(10);  //newline
        eventSuccess = true;
      }
    }
    ethernetClient.print(closeMessage);  //tell the receiver to close
    ethernetClient.stop();
    Serial.println(F("EtherEvent.send: connection closed"));
  }
  else {
    Serial.println(F("EtherEvent.send: connection failed"));
  }
  return eventSuccess;  //send finished
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//setTimeout
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void EtherEventClass::setTimeout(const unsigned int timeoutInput) {
  timeout = timeoutInput;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//setPassword
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
boolean EtherEventClass::setPassword(const char passwordInput[]) {
  Serial.println(F("EtherEvent.setPassword(char)"));
  passwordLength = strlen(passwordInput);
  password = (char*)realloc(password, (passwordLength + 1) * sizeof(*password));  //allocate memory for the password
  strcpy(password, passwordInput);  //store the password
  if (password == NULL) {
    Serial.println(F("EtherEvent.setPassword: memory allocation failed"));
    return false;
  }
  return true;
}

boolean EtherEventClass::setPassword(const __FlashStringHelper* passwordInput, const byte passwordLengthInput) {
  Serial.println(F("EtherEvent.setPassword(F())"));
  passwordLength = passwordLengthInput;
  password = (char*)realloc(password, (passwordLength + 1) * sizeof(*password));  //allocate memory for the password
  memcpy_P(password, passwordInput, passwordLength + 1);  //+1 for the null terminator
  if (password == NULL) {
    Serial.println(F("EtherEvent.setPassword: memory allocation failed"));
    return false;
  }
  return true;
}

#ifdef __FLASH_H__
boolean EtherEventClass::setPassword(const _FLASH_STRING passwordInput) {
  Serial.println(F("EtherEvent.setPassword(Flash)"));
  passwordLength = passwordInput.length();
  password = (char*)realloc(password, (passwordLength + 1) * sizeof(*password));  //allocate memory for the password
  passwordInput.copy(password, passwordLength + 1, 0);  //+1 for null terminator
  if (password == NULL) {
    Serial.println(F("EtherEvent.setPassword: memory allocation failed"));
    return false;
  }
  return true;
}
#endif


EtherEventClass EtherEvent;  //This sets up a single global instance of the library so the class doesn't need to be declared in the user sketch and multiple instances are not necessary in this case.

