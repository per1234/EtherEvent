// EtherEvent - Easy to use password authenticated network communication between Arduinos and EventGhost Network Event Sender/Receiver and TCPEvents plugins: http://github.com/per1234/EtherEvent
#define ETHEREVENT_NO_AUTHENTICATION  //this is to prevent EtherEvent.cpp's include of EtherEvent.h from including MD5.h(not needed in this file even with authentication enabled
#include "EtherEvent.h"


const unsigned int timeoutDefault = 1000;  //(ms)Timeout duration for ethernet stream functions.
const byte sendDoubleDecimalPlacesDefault = 3;  //default number of decimal places when sending event/payload of double/float type


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//constructor
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
EtherEvent::EtherEvent(Server *_server, Client *_client) {
  timeout = timeoutDefault;  //set default timeout value, this can be changed by the user via setTimeout()
  sendDoubleDecimalPlaces = sendDoubleDecimalPlacesDefault;
  server = _server;
  client = _client;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//begin
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
boolean EtherEvent::begin(const byte eventLengthMaxInput, const unsigned int payloadLengthMaxInput) {
#if ETHEREVENT_DEBUG == true
  delay(20);  //There needs to be a delay between the calls to ETHEREVENT_SERIAL.begin() in sketch setup() and here or garbage will be printed to the serial monitor
#endif
  ETHEREVENT_SERIAL.begin(EtherEventNamespace::debugSerialBaud);  //for debugging
  ETHEREVENT_SERIAL.println(F("\n\n\nEtherEvent.begin"));

  eventLengthMax = eventLengthMaxInput;
  payloadLengthMax = payloadLengthMaxInput;
  availableEventSubmessageLengthMax = max(max(EtherEventNamespace::payloadWithoutReleaseLength, EtherEventNamespace::payloadSeparatorLength + payloadLengthMax + TCPEventsPayloadFormattingLength), eventLengthMax);
  if (availableEventSubmessageLengthMax > availableEventSubmessageLengthMax + 1) {  //availableEventSubmessageLengthMax is the max value of the type
    availableEventSubmessageLengthMax--;  //have to decrement because I need to add one in the event/payload handler section of availableEvent()
  }

  receivedEvent = (char*)realloc(receivedEvent, (eventLengthMax + 1) * sizeof(*receivedEvent));
  receivedEvent[0] = 0;  //clear buffer - realloc does not zero initialize so the buffer could contain anything
  receivedPayload = (char*)realloc(receivedPayload, (payloadLengthMax + 1) * sizeof(*receivedPayload));
  receivedPayload[0] = 0;  //clear buffer - realloc does not zero initialize so the buffer could contain anything
  if (receivedEvent == NULL || receivedPayload == NULL) {
    ETHEREVENT_SERIAL.println(F("memory allocation failed"));
    return false;
  }
  return true;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//availablePayload - returns the number of chars in the payload including the null terminator if there is one
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
unsigned int EtherEvent::availablePayload() {
  if (unsigned int receivedPayloadLength = strlen(receivedPayload)) {  //strlen(receivedPayload) > 0
    return receivedPayloadLength + 1;  //length of the payload  +  null terminator
  }
  return false;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//readEvent
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void EtherEvent::readEvent(char eventBuffer[]) {
  strcpy(eventBuffer, receivedEvent);
  receivedEvent[0] = 0;  //reset the event buffer
  receivedEventLength = 0;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//readPayload
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void EtherEvent::readPayload(char payloadBuffer[]) {
  strcpy(payloadBuffer, receivedPayload);
  receivedPayload[0] = 0;  //reset the payload buffer
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//flushReceiver - dump the last message received so another one can be received
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void EtherEvent::flushReceiver() {
  ETHEREVENT_SERIAL.println(F("EtherEvent.flushReceiver: start"));
  receivedEvent[0] = 0;  //reset the event buffer
  receivedPayload[0] = 0;  //reset the payload buffer
  receivedEventLength = 0;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//senderIP - returns the ip address the current event was sent from. Requires modified ethernet library, thus the preprocesser direcive system
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef ethernetclientwithremoteIP_h  //the include guard from the modified EthernetClient.h
IPAddress EtherEvent::senderIP() {
  return fromIP;
}
#endif


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//setTimeout
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void EtherEvent::setTimeout(const unsigned int timeoutInput) {
  timeout = timeoutInput;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//getTimeout
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
unsigned int EtherEvent::getTimeout() {
  return timeout;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//setPassword
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
boolean EtherEvent::setPassword(const char passwordInput[]) {
  ETHEREVENT_SERIAL.println(F("EtherEvent.setPassword(char)"));
  passwordLength = strlen(passwordInput);
  password = (char*)realloc(password, (passwordLength + 1) * sizeof(*password));  //allocate memory for the password
  strcpy(password, passwordInput);  //store the password
  if (password == NULL) {
    ETHEREVENT_SERIAL.println(F("EtherEvent.setPassword: memory allocation failed"));
    return false;
  }
  return true;
}

boolean EtherEvent::setPassword(const __FlashStringHelper* passwordInput) {
  ETHEREVENT_SERIAL.println(F("EtherEvent.setPassword(F())"));
  passwordLength = FSHlength(passwordInput);
  password = (char*)realloc(password, (passwordLength + 1) * sizeof(*password));  //allocate memory for the password
  if (password == NULL) {
    ETHEREVENT_SERIAL.println(F("EtherEvent.setPassword: memory allocation failed"));
    return false;
  }
  memcpy_P(password, passwordInput, passwordLength + 1);  //+1 for the null terminator
  return true;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//setSendDoubleDecimalPlaces
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void EtherEvent::setSendDoubleDecimalPlaces(const byte decimalPlaces) {
  ETHEREVENT_SERIAL.println(F("EtherEvent.setSendDoubleDecimalPlaces"));
  sendDoubleDecimalPlaces = decimalPlaces;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//IPtoa - convert IPAddress to char array and put it in the passed buffer
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void EtherEvent::IPtoa(const IPAddress &IP, char IPcharBuffer[]) {
  utoa(IP[0], IPcharBuffer, 10);  //convert the first octet
  for (byte octetCount = 1; octetCount < 4; octetCount++) {  //convert the other 3 octets
    strcat(IPcharBuffer, ".");
    char octetChar[3 + 1];  //3 digit byte + null terminator
    utoa(IP[octetCount], octetChar, 10);  //convert the first octet
    strcat(IPcharBuffer, octetChar);
  }
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//FSHlength - determine length of __FlashStringHelper
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
byte EtherEvent::FSHlength(const __FlashStringHelper* passwordInput) {
  const char* passwordInputPointer = (const char PROGMEM *)passwordInput;
  byte stringLength = 0;
  while (true) {
    unsigned char character = pgm_read_byte(passwordInputPointer++);
    if (character == 0) break;
    stringLength++;
  }
  return stringLength;
}

