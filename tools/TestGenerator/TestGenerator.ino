// This sketch is used to automatically generate the send()overload tests and print them to the Serial Monitor

#define EVENT_PAYLOAD_TYPES_ARRAY_NAME eventPayloadTypes1  //change this to eventPayloadTypes2 to generate the second half of the tests

const byte maximumStringLength = 25;
const char targetTypes[][maximumStringLength] = {
  {"IPAddress"},
  {"byte_array"},
  {"const_byte_array"}
};

const char eventPayloadTypes1[][maximumStringLength] = {
  {"char_array"},
  {"const_char_array"},
  ("char"),
  {"byte"},
  {"int8_t"},
  {"int"},
  {"const_int"},
  {"unsigned_int"}
};

const char eventPayloadTypes2[][maximumStringLength] = {
  {"long"},
  {"unsigned_long"},
  {"float"},
  {"double"},
  {"IPAddress"},
  {"String"},
  {"string_literal"},
  {"__FlashStringHelper"}
};

const char passwordTypes[][maximumStringLength] = {
  {"char_array"},
  {"string_literal"},
  {"__FlashStringHelper"}
};


const byte eventPayloadTypesCount = sizeof(EVENT_PAYLOAD_TYPES_ARRAY_NAME) / sizeof(EVENT_PAYLOAD_TYPES_ARRAY_NAME[0]);

void setup() {
  Serial.begin(115200);
  while (!Serial) {}
  Serial.println("void runTests(){");
  Serial.println("// send() overload tests:");

  for (byte targetTypeCounter = 0; targetTypeCounter < sizeof(targetTypes) / sizeof(targetTypes[0]); ++targetTypeCounter) {
    for (byte eventTypeCounter = 0; eventTypeCounter < eventPayloadTypesCount; ++eventTypeCounter) {
      // send(ethernetClient, target, port, event)
      printThroughEvent(targetTypeCounter, eventTypeCounter);
      Serial.println(");");

      for (byte payloadTypeCounter = 0; payloadTypeCounter < eventPayloadTypesCount; ++payloadTypeCounter) {
        // send(ethernetClient, target, port, event, payload)
        printThroughPayload(targetTypeCounter, eventTypeCounter, payloadTypeCounter);
        Serial.println(");");
        Serial.println("#ifndef ETHEREVENT_NO_AUTHENTICATION");

        for (byte passwordTypeCounter = 0; passwordTypeCounter < sizeof(passwordTypes) / sizeof(passwordTypes[0]); ++passwordTypeCounter) {
          // send(ethernetClient, target, port, event, payload, password)
          printThroughPayload(targetTypeCounter, eventTypeCounter, payloadTypeCounter);
          Serial.print(", sendPassword_");
          Serial.print(passwordTypes[passwordTypeCounter]);
          Serial.println(");");
        }
        Serial.println("#endif //ETHEREVENT_NO_AUTHENTICATION");
      }
    }
  }
  Serial.println("}");
}


void printThroughEvent(const byte targetTypeCounter, const byte eventTypeCounter) {
  Serial.print("EtherEvent.send(ethernetClient, target_");
  Serial.print(targetTypes[targetTypeCounter]);
  Serial.print(", sendPort, event_");
  Serial.print(EVENT_PAYLOAD_TYPES_ARRAY_NAME[eventTypeCounter]);
}


void printThroughPayload(const byte targetTypeCounter, const byte eventTypeCounter, const byte payloadTypeCounter) {
  printThroughEvent(targetTypeCounter, eventTypeCounter);
  Serial.print(", payload_");
  Serial.print(EVENT_PAYLOAD_TYPES_ARRAY_NAME[payloadTypeCounter]);
}


void loop() {}
