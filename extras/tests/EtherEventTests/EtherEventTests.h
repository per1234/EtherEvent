#if !defined(ETHEREVENTTESTS_H)
#define ETHEREVENTTESTS_H

#include <SPI.h>  //bundled with Arduino hardware packages
#include <Ethernet.h> //built-in library included with Arduino IDE
#if !defined(__ARDUINO_X86__)
#include <utility/w5100.h>  //Part of built-in Ethernet library included with Arduino IDE. Used for setting the W5x00 retransmission time and count.
#endif //!defined(__ARDUINO_X86__)
EthernetServer ethernetServer(1024);  //TCP port to receive on
EthernetClient ethernetClient;  //create the client object for Ethernet communication

#if !defined(ETHEREVENT_NO_AUTHENTICATION) && !defined(ESP8266)
#include <MD5.h>  //http://github.com/tzikis/ArduinoMD5
#endif  //!defined(ETHEREVENT_NO_AUTHENTICATION) && !defined(ESP8266)
#include <EtherEvent.h> //https://github.com/per1234/EtherEvent

#if defined(__AVR__)
#include <MemoryFree.h> //https://github.com/McNeight/MemoryFree
#endif  //defined(__AVR__)

#include <Arduino.h>  //Arduino core library

#define DEBUG false
#define DEBUG_SERIAL if(DEBUG)Serial

#define EVENT_BUFFER_SIZE 42
#define PAYLOAD_BUFFER_SIZE 42

const unsigned long receiveTimeoutDuration = 500; //(ms) time to wait for reply after sending event

const byte maximumTimeoutCount = 10; //number of times to retry an event send due to timeout before failing
const byte maximumAuthenticatonFailCount = 2; //number of times to retry an event send due to authentication failure before failing
const byte maximumMismatchCount = 1; //number of times to retry an event send due to mismatch before failing

//timeout values - these can be tuned to your system to provide the most responsive operation. Too high of value will cause a long delay on failed Ethernet operations, too short will cause failed event send or receive.
//The default values used when these timeouts are not set are fairly conservative.
const byte etherEventTimeout = 20;  //(ms)The max time to wait for Ethernet communication.
const unsigned int W5x00timeout = 400;  //(0.1ms)used to set the timeout for the W5x00 module.
const byte W5x00retransmissionCount = 1;  //Retransmission count. 1 is the minimum value.


//arguments used in runTests():
const IPAddress targetIPAddress = IPAddress(192, 168, 69, 100);  //The IP address to send the test events to.
byte targetByteArray[] = {192, 168, 69, 100};  //The IP address to send the test events to.
const byte targetConstByteArray[] = {192, 168, 69, 100};  //The IP address to send the test events to.

char eventCharArray[] = "eventCharArray";
const char eventConstCharArray[] = "eventConstCharArray";
char eventChar = 'a';
byte eventByte = 1;
int8_t eventInt8_t = -2;
int eventInt = 1000;
const int eventConstInt = 1001;
unsigned int eventUnsignedInt = -1002;
long eventLong = 100000;
unsigned long eventUnsignedLong = -100001;
float eventFloat = 1.23;
double eventDouble = 2.34;
IPAddress eventIPAddress = IPAddress(101, 102, 103, 104);
String eventString = "eventString";
#define event_STRING_LITERAL "event_STRING_LITERAL"
#define event_FLASHSTRINGHELPER F("event_FLASHSTRINGHELPER")

char payloadCharArray[] = "payloadCharArray";
const char payloadConstCharArray[] = "payloadConstCharArray";
char payloadChar = 'b';
byte payloadByte = 10;
int8_t payloadInt8_t = -11;
int payloadInt = 2000;
const int payloadConstInt = 2001;
unsigned int payloadUnsignedInt = -2002;
long payloadLong = 200000;
unsigned long payloadUnsignedLong = -200001;
float payloadFloat = 3.45;
double payloadDouble = 4.56;
IPAddress payloadIPAddress = IPAddress(105, 106, 107, 108);
String payloadString = "payloadString";
#define payload_STRING_LITERAL "payload_STRING_LITERAL"
#define payload_FLASHSTRINGHELPER F("payload_FLASHSTRINGHELPER")

const unsigned int sendPort = 1024;  //The port to send the test events to.

#if !defined(ETHEREVENT_NO_AUTHENTICATION)
//used for availableEvent() overload tests:
const char passwordConstCharArray[] = "password";  //EtherEvent password. This must match the password set in EventGhost.
char passwordCharArray[] = "password";  //EtherEvent password. This must match the password set in EventGhost.
#define password_STRING_LITERAL "password"
#define password_FLASHSTRINGHELPER F("password")
String passwordString = "password";


//used for availableEvent() overload tests:
enum __attribute__((packed)) availableEventTest_t{
  availableEventTestStart,
  ethernetServerTest,
  ethernetServerCookieTest,
  ethernetServerCookiePasswordCharArrayTest,
  ethernetServerCookiePasswordConstCharArrayTest,
  ethernetServerCookiePasswordStringLiteralTest,
  ethernetServerCookiePasswordFlashStringHelperTest,
  availableEventTestCount
};
#endif  //!defined(ETHEREVENT_NO_AUTHENTICATION)


//receive() return codes
enum __attribute__((packed)) receiveReturnCode_t{
  timeoutReturnCode,
  authenticationFailedReturnCode,
  mismatchReturnCode,
  successReturnCode
};


static bool testPassed = true;

//PrintEvent and PrintPayload classes allow the Arduino core library's Print class to be used for event/payload conversions from any common type to char array
class PrintEvent : public Print {
  public:
    PrintEvent() {}
    virtual size_t write(uint8_t printChar);
    char eventBuffer[EVENT_BUFFER_SIZE];
    unsigned int writePosition;
};
static PrintEvent printEvent;

class PrintPayload : public Print {
  public:
    PrintPayload() {}
    virtual size_t write(uint8_t printChar);
    char payloadBuffer[PAYLOAD_BUFFER_SIZE];
    unsigned int writePosition;
};
static PrintPayload printPayload;


size_t PrintEvent::write(uint8_t printChar) {
  DEBUG_SERIAL.println(F("printEvent.write:"));

  if (writePosition == EVENT_BUFFER_SIZE - 1) {
    eventBuffer[writePosition] = 0;
    return 1;  // I'm not sure if this is the correct return value for full buffer, is there a way to abort the rest of the print?
  }
  eventBuffer[writePosition++] = printChar;
  DEBUG_SERIAL.print(">");
  DEBUG_SERIAL.println((char)printChar);
  return 1;
}


size_t PrintPayload::write(uint8_t printChar) {
  DEBUG_SERIAL.println(F("printPayload.write:"));

  if (writePosition == PAYLOAD_BUFFER_SIZE - 1) {
    payloadBuffer[writePosition] = 0;
    return 1;  // I'm not sure if this is the correct return value for full buffer, is there a way to abort the rest of the print?
  }
  payloadBuffer[writePosition++] = printChar;
  DEBUG_SERIAL.print(">");
  DEBUG_SERIAL.println((char)printChar);
  return 1;
}


//function/template prototypes
void etherEventTests();
void runTests();

template <typename target_t, typename event_t>void test(EthernetClient &ethernetClient, const target_t target, const char targetType[], const unsigned int sendPort, const event_t event, const char eventType[]);
template <typename target_t, typename event_t, typename payload_t>void test(EthernetClient & ethernetClient, const target_t target, const char targetType[], const unsigned int sendPort, const event_t event, const char eventType[], const payload_t payload, const char payloadType[]);
#if !defined(ETHEREVENT_NO_AUTHENTICATION)
template <typename target_t, typename event_t, typename payload_t, typename password_t>void test(EthernetClient & ethernetClient, const target_t target, const char targetType[], const unsigned int sendPort, const event_t event, const char eventType[], const payload_t payload, const char payloadType[], const password_t password, const char passwordType[]);
#endif  //!defined(ETHEREVENT_NO_AUTHENTICATION)

template <typename event_t, typename payload_t>receiveReturnCode_t receive(const event_t sentEvent, const payload_t sentPayload);
template <typename event_t>receiveReturnCode_t receive(const event_t sentEvent, const char sentPayload[]);
receiveReturnCode_t receive(const char sentEvent[], const char sentPayload[]);


void etherEventTests() {
  Serial.begin(9600);
  DEBUG_SERIAL.println(F("setup: starting"));

  byte MACaddress[] = {0, 1, 2, 3, 4, 4};  //this can be anything you like as long as it's unique on your network
  Ethernet.begin(MACaddress, IPAddress(192, 168, 69, 104));  //use static IP address
  ethernetServer.begin();  //begin the server that will be used to receive events

  EtherEvent.begin(EVENT_BUFFER_SIZE, PAYLOAD_BUFFER_SIZE);

#if defined(ETHEREVENT_FAST_SEND)
  EtherEvent.setSendDoubleDecimalPlaces(2); //Print class defaults to two decimal places
#endif  //defined(ETHEREVENT_FAST_SEND)

#if !defined(ETHEREVENT_NO_AUTHENTICATION)
  EtherEvent.setPassword(passwordConstCharArray);
#endif  //!defined(ETHEREVENT_NO_AUTHENTICATION)

  Serial.print(F("Setting timeout to: "));
  Serial.println(etherEventTimeout);
  EtherEvent.setTimeout(etherEventTimeout);  //set timeout duration
  Serial.print(F("EtherEvent.getTimeout(): "));
  Serial.println(EtherEvent.getTimeout());

#if !defined(__ARDUINO_X86__)
  W5100.setRetransmissionTime(W5x00timeout);  //set the timeout for the W5x00 module.
  W5100.setRetransmissionCount(W5x00retransmissionCount);  //Retransmission Count - 1 is the minimum value
#endif //!defined(__ARDUINO_X86__)

#if defined(__AVR__)
  const unsigned long previousFreeMemory = freeMemory();
#endif  //defined(__AVR__)

  runTests();

  //test for memory leaks
#if defined(__AVR__)
  const unsigned long currentFreeMemory = freeMemory();
  if (previousFreeMemory > currentFreeMemory) {
    Serial.print(F("Memory leak detected. Difference="));
    Serial.println(previousFreeMemory - currentFreeMemory);
    testPassed = false;
  }
#endif  //defined(__AVR__)

  Serial.print(F("\n\nTests finished: "));
  Serial.println(testPassed == true ? F("Passed") : F("Failed"));
  Serial.println(F("Configuration:"));
#if defined(ETHEREVENT_NO_AUTHENTICATION)
  Serial.println(F("ETHEREVENT_NO_AUTHENTICATION"));
#endif  //defined(ETHEREVENT_NO_AUTHENTICATION)
#if defined(ETHEREVENT_FAST_SEND)
  Serial.println(F("ETHEREVENT_FAST_SEND"));
#endif  //defined(ETHEREVENT_FAST_SEND)
  Serial.print(F("TEST_BATCH: "));
  Serial.println(TEST_BATCH);
}


//test() allows single function calls generated by TestGenerator.ino to provide test progress output, EtherEvent.send() call, and receive() call. I think it's cleaner this way, rather than changing TestGenerator to produce 6 LOC for each test.
template <typename target_t, typename event_t>void test(EthernetClient &ethernetClient, const target_t target, const char targetType[], const unsigned int sendPort, const event_t event, const char eventType[]) {
  //provide some output to show test progress
  Serial.print(F("Target type: "));
  Serial.println(targetType);
  Serial.print(F("Event type: "));
  Serial.println(eventType);

  byte timeoutCount = 0;
  byte authenticationFailCount = 0;
  byte mismatchCount = 0;
  receiveReturnCode_t receiveReturnCode;
  do {
    const unsigned long preSentTimestamp = micros();
    EtherEvent.send(ethernetClient, target, sendPort, event);
    const unsigned long postSentTimestamp = micros();
    const unsigned long sendDuration = postSentTimestamp - preSentTimestamp;
    Serial.print(F("Send duration: "));
    Serial.println(sendDuration);

    receiveReturnCode = receive(event, "");
    switch (receiveReturnCode) {
      case timeoutReturnCode:
        timeoutCount++;
        break;
      case authenticationFailedReturnCode:
        authenticationFailCount++;
        break;
      case mismatchReturnCode:
        mismatchCount++;
        break;
      case successReturnCode:
        break;
    }
  } while (receiveReturnCode != successReturnCode && timeoutCount <= maximumTimeoutCount && authenticationFailCount <= maximumAuthenticatonFailCount && mismatchCount <= maximumMismatchCount);
  if (receiveReturnCode != successReturnCode) {
    testPassed = false;
    Serial.println(F("\nTest failed\n"));
  }
}


template <typename target_t, typename event_t, typename payload_t>void test(EthernetClient & ethernetClient, const target_t target, const char targetType[], const unsigned int sendPort, const event_t event, const char eventType[], const payload_t payload, const char payloadType[]) {
  //provide some output to show test progress
  Serial.print(F("Target type: "));
  Serial.println(targetType);
  Serial.print(F("Event type: "));
  Serial.println(eventType);
  Serial.print(F("Payload type: "));
  Serial.println(payloadType);

  byte timeoutCount = 0;
  byte authenticationFailCount = 0;
  byte mismatchCount = 0;
  receiveReturnCode_t receiveReturnCode;
  do {
    const unsigned long preSentTimestamp = micros();
    EtherEvent.send(ethernetClient, target, sendPort, event, payload);
    const unsigned long postSentTimestamp = micros();
    const unsigned long sendDuration = postSentTimestamp - preSentTimestamp;
    Serial.print(F("Send duration: "));
    Serial.println(sendDuration);

    receiveReturnCode = receive(event, payload);
    switch (receiveReturnCode) {
      case timeoutReturnCode:
        timeoutCount++;
        break;
      case authenticationFailedReturnCode:
        authenticationFailCount++;
        break;
      case mismatchReturnCode:
        mismatchCount++;
        break;
      case successReturnCode:
        break;
    }
  } while (receiveReturnCode != successReturnCode && timeoutCount <= maximumTimeoutCount && authenticationFailCount <= maximumAuthenticatonFailCount && mismatchCount <= maximumMismatchCount);
  if (receiveReturnCode != successReturnCode) {
    testPassed = false;
    Serial.println(F("\nTest failed\n"));
  }
}


#if !defined(ETHEREVENT_NO_AUTHENTICATION)
template <typename target_t, typename event_t, typename payload_t, typename password_t>void test(EthernetClient & ethernetClient, const target_t target, const char targetType[], const unsigned int sendPort, const event_t event, const char eventType[], const payload_t payload, const char payloadType[], const password_t password, const char passwordType[]) {
  //provide some output to show test progress
  Serial.print(F("Target type: "));
  Serial.println(targetType);
  Serial.print(F("Event type: "));
  Serial.println(eventType);
  Serial.print(F("Payload type: "));
  Serial.println(payloadType);
  Serial.print(F("Password type: "));
  Serial.println(passwordType);

  byte timeoutCount = 0;
  byte authenticationFailCount = 0;
  byte mismatchCount = 0;
  receiveReturnCode_t receiveReturnCode;
  do {
    const unsigned long preSentTimestamp = micros();
    EtherEvent.send(ethernetClient, target, sendPort, event, payload, password);
    const unsigned long postSentTimestamp = micros();
    const unsigned long sendDuration = postSentTimestamp - preSentTimestamp;
    Serial.print(F("Send duration: "));
    Serial.println(sendDuration);

    receiveReturnCode = receive(event, payload);
    switch (receiveReturnCode) {
      case timeoutReturnCode:
        timeoutCount++;
        break;
      case authenticationFailedReturnCode:
        authenticationFailCount++;
        break;
      case mismatchReturnCode:
        mismatchCount++;
        break;
      case successReturnCode:
        break;
    }
  } while (receiveReturnCode != successReturnCode && timeoutCount <= maximumTimeoutCount && authenticationFailCount <= maximumAuthenticatonFailCount && mismatchCount <= maximumMismatchCount);
  if (receiveReturnCode != successReturnCode) {
    testPassed = false;
    Serial.println(F("\nTest failed\n"));
  }
}
#endif  //!defined(ETHEREVENT_NO_AUTHENTICATION)


template <typename event_t, typename payload_t>receiveReturnCode_t receive(const event_t sentEvent, const payload_t sentPayload) {
  DEBUG_SERIAL.println(F("receive: event_t, payload_t"));

  printPayload.print(sentPayload);
  printPayload.payloadBuffer[printPayload.writePosition] = 0; //add null terminator.
  printPayload.writePosition = 0; //reset the write position for the next send()
  return receive(sentEvent, (const char*)printPayload.payloadBuffer);
}


template <typename event_t>receiveReturnCode_t receive(const event_t sentEvent, const char sentPayload[]) {
  DEBUG_SERIAL.println(F("receive: event_t, char[]"));

  printEvent.print(sentEvent);
  printEvent.eventBuffer[printEvent.writePosition] = 0; //add null terminator.
  printEvent.writePosition = 0; //reset the write position for the next send()
  return receive((const char*)printEvent.eventBuffer, sentPayload);
}


receiveReturnCode_t receive(const char sentEvent[], const char sentPayload[]) {
  DEBUG_SERIAL.println(F("receive: char[], char[]"));

  const unsigned long timestamp = millis();

  //wait for the event to be received
#if !defined(ETHEREVENT_NO_AUTHENTICATION)
  static availableEventTest_t availableEventTest = ethernetServerTest;
  switch (availableEventTest) {
    case ethernetServerTest:
#endif  //!defined(ETHEREVENT_NO_AUTHENTICATION)
      while (EtherEvent.availableEvent(ethernetServer) == 0) {
        if (millis() - timestamp > receiveTimeoutDuration) {
          Serial.println(F("\nTimed out waiting for response\n"));
          return timeoutReturnCode;
        }
      }
#if !defined(ETHEREVENT_NO_AUTHENTICATION)
      break;
    case ethernetServerCookieTest:
      while (EtherEvent.availableEvent(ethernetServer, 42) == 0) {
        if (millis() - timestamp > receiveTimeoutDuration) {
          Serial.println(F("\nTimed out waiting for response\n"));
          return timeoutReturnCode;
        }
      }
      break;
    case ethernetServerCookiePasswordCharArrayTest:
      while (EtherEvent.availableEvent(ethernetServer, 42, passwordCharArray) == 0) {
        if (millis() - timestamp > receiveTimeoutDuration) {
          Serial.println(F("\nTimed out waiting for response\n"));
          return timeoutReturnCode;
        }
      }
      break;
    case ethernetServerCookiePasswordConstCharArrayTest:
      while (EtherEvent.availableEvent(ethernetServer, 42, passwordConstCharArray) == 0) {
        if (millis() - timestamp > receiveTimeoutDuration) {
          Serial.println(F("\nTimed out waiting for response\n"));
          return timeoutReturnCode;
        }
      }
      break;
    case ethernetServerCookiePasswordStringLiteralTest:
      while (EtherEvent.availableEvent(ethernetServer, 42, password_STRING_LITERAL) == 0) {
        if (millis() - timestamp > receiveTimeoutDuration) {
          Serial.println(F("\nTimed out waiting for response\n"));
          return timeoutReturnCode;
        }
      }
      break;
    case ethernetServerCookiePasswordFlashStringHelperTest:
      while (EtherEvent.availableEvent(ethernetServer, 42, password_FLASHSTRINGHELPER) == 0) {
        if (millis() - timestamp > receiveTimeoutDuration) {
          Serial.println(F("\nTimed out waiting for response\n"));
          return timeoutReturnCode;
        }
      }
      break;
    //these cases added to fix "enumeration value ... not handled in switch" warnings
    case availableEventTestStart:
      DEBUG_SERIAL.println(F("\nreceive: case availableEventTestStart reached. Something is wrong!\n"));
      break;
    case availableEventTestCount:
      DEBUG_SERIAL.println(F("\nreceive: case availableEventTestCount reached. Something is wrong!\n"));
      break;
  }
#endif  //!defined(ETHEREVENT_NO_AUTHENTICATION)
  int availableLength = EtherEvent.availableEvent();  //test availableEvent() called with no arguments
  if (availableLength == -1) {
    Serial.println(F("\nAuthentication failed\n"));
    return authenticationFailedReturnCode;
  }
  else {
    //put the event in the buffer
    DEBUG_SERIAL.print(F("receive: Received event length="));
    DEBUG_SERIAL.println(availableLength);
    char receivedEvent[availableLength];  //create the event buffer of the correct size
    EtherEvent.readEvent(receivedEvent);  //read the event into the event buffer
    DEBUG_SERIAL.print(F("receive: Received event: "));
    DEBUG_SERIAL.println(receivedEvent);  //now the event is in your buffer

    //compare sent event to received event
    if (strcmp(sentEvent, receivedEvent) != 0) {
      Serial.println(F("\nEvent mismatch"));
      Serial.print(F("Sent event: "));
      Serial.println(sentEvent);
      Serial.print(F("Received event: "));
      Serial.println(receivedEvent);
      Serial.println();
      return mismatchReturnCode;
    }
    else {
      DEBUG_SERIAL.println(F("receive: Event matched"));
    }

    //put the payload in the buffer
    availableLength = EtherEvent.availablePayload();
    DEBUG_SERIAL.print(F("receive: Received payload length="));
    DEBUG_SERIAL.println(availableLength);
    char receivedPayload[max(availableLength, 1)]; //the buffer must be sized to at least 1 element to accommodate the null terminator so that the strcmp will still work when no payload was sent
    receivedPayload[0] = 0; //default to an empty string
    if (availableLength > 0) {  //there is a payload
      EtherEvent.readPayload(receivedPayload);
      DEBUG_SERIAL.print(F("receive: Received payload: "));
      DEBUG_SERIAL.println(receivedPayload);
    }

    //compare sent payload to received payload (must be done even when no payload was received because if a payload was sent but not received that is a mismatch)
    if (strcmp(sentPayload, receivedPayload) != 0) {
      Serial.println(F("\nPayload mismatch"));
      Serial.print(F("Sent payload: "));
      Serial.println(sentPayload);
      Serial.print(F("Received payload: "));
      Serial.println(receivedPayload);
      Serial.println();
      return mismatchReturnCode;
    }
    else {
      DEBUG_SERIAL.println(F("receive: Payload matched"));
    }
  }
#if !defined(ETHEREVENT_NO_AUTHENTICATION)
  availableEventTest = static_cast<availableEventTest_t>(static_cast<int>(availableEventTest) + 1); //increment the test type
  if (availableEventTest == availableEventTestCount) {  //the last test type was reached
    //restart from the first test type
    availableEventTest = static_cast<availableEventTest_t>(static_cast<int>(availableEventTestStart) + 1);
  }
#endif  //!defined(ETHEREVENT_NO_AUTHENTICATION)
  return successReturnCode;
}


#include "RunTests.h"

#endif  //!defined(ETHEREVENTTESTS_H)
