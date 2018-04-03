// This sketch is used to automatically generate the send() overload tests and print them to the Serial Monitor

const byte testBatchCount = 4;

const byte maximumStringLength = 25;
const char targetTypes[][maximumStringLength] = {
  {"IPAddress"},
  {"ByteArray"},
  {"ConstByteArray"}
};

const char eventPayloadTypes[][maximumStringLength] = {
  {"CharArray"},
  {"ConstCharArray"},
  ("Char"),
  {"Byte"},
  {"Int8_t"},
  {"Int"},
  {"ConstInt"},
  {"UnsignedInt"},
  {"Long"},
  {"UnsignedLong"},
  {"Float"},
  {"Double"},
  {"IPAddress"},
  {"String"},
  {"_STRING_LITERAL"},
  {"_FLASHSTRINGHELPER"}
};

const char passwordTypes[][maximumStringLength] = {
  {"ConstCharArray"},
  {"CharArray"},
  {"_STRING_LITERAL"},
  {"_FLASHSTRINGHELPER"},
  {"String"}
};


void setup() {
  Serial.begin(115200);
  while (!Serial) {}
  Serial.println("void runTests(){");
  Serial.println("// send() overload tests:");

  const byte eventPayloadTypesCount = sizeof(eventPayloadTypes) / sizeof(eventPayloadTypes[0]);

  for (byte testBatchCounter = 0; testBatchCounter < testBatchCount; testBatchCounter++) {
    Serial.print('#');
    if (testBatchCounter > 0) {
      Serial.print("el");
    }
    Serial.print("if TEST_BATCH == ");
    Serial.println(testBatchCounter);
    generateTests((testBatchCounter * eventPayloadTypesCount) / testBatchCount, (((testBatchCounter + 1) *eventPayloadTypesCount) / testBatchCount) - 1);
  }
  Serial.println("#endif //TEST_BATCH == 0");
  Serial.print("}");
}


void generateTests(const byte eventPayloadTypesStartIndex, const byte eventPayloadTypesEndIndex) {
  for (byte targetTypeCounter = 0; targetTypeCounter < sizeof(targetTypes) / sizeof(targetTypes[0]); ++targetTypeCounter) {
    for (byte eventTypeCounter = eventPayloadTypesStartIndex; eventTypeCounter <= eventPayloadTypesEndIndex; ++eventTypeCounter) {
      // test(ethernetClient, target, port, event)
      printThroughEvent(targetTypeCounter, eventTypeCounter);
      Serial.println(");");

      for (byte payloadTypeCounter = eventPayloadTypesStartIndex; payloadTypeCounter <= eventPayloadTypesEndIndex; ++payloadTypeCounter) {
        // test(ethernetClient, target, port, event, payload)
        printThroughPayload(targetTypeCounter, eventTypeCounter, payloadTypeCounter);
        Serial.println(");");
        Serial.println("#ifndef ETHEREVENT_NO_AUTHENTICATION");

        for (byte passwordTypeCounter = 0; passwordTypeCounter < sizeof(passwordTypes) / sizeof(passwordTypes[0]); ++passwordTypeCounter) {
          // test(ethernetClient, target, port, event, payload, password)
          printThroughPayload(targetTypeCounter, eventTypeCounter, payloadTypeCounter);
          Serial.print(", password");
          Serial.print(passwordTypes[passwordTypeCounter]);
          //passwordType argument
          Serial.print(", \"");
          Serial.print(passwordTypes[passwordTypeCounter]);
          Serial.println("\");");
        }
        Serial.println("#endif //ETHEREVENT_NO_AUTHENTICATION");
      }
    }
  }
}


void printThroughEvent(const byte targetTypeCounter, const byte eventTypeCounter) {
  Serial.print("test(ethernetClient, target");
  //target argument
  Serial.print(targetTypes[targetTypeCounter]);
  //targetType argument
  Serial.print(", \"");
  Serial.print(targetTypes[targetTypeCounter]);
  Serial.print('"');
  Serial.print(", sendPort, event");
  // event argument
  Serial.print(eventPayloadTypes[eventTypeCounter]);
  //eventType argument
  Serial.print(", \"");
  Serial.print(eventPayloadTypes[eventTypeCounter]);
  Serial.print('"');
}


void printThroughPayload(const byte targetTypeCounter, const byte eventTypeCounter, const byte payloadTypeCounter) {
  printThroughEvent(targetTypeCounter, eventTypeCounter);
  //payload argument
  Serial.print(", payload");
  Serial.print(eventPayloadTypes[payloadTypeCounter]);
  //payloadType argument
  Serial.print(", \"");
  Serial.print(eventPayloadTypes[payloadTypeCounter]);
  Serial.print('"');
}


void loop() {}
