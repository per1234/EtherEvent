void runTests() {
  // send() overload tests:
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_long);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_long, payload_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_long, payload_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_long, payload_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_long, payload_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_long, payload_unsigned_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_long, payload_unsigned_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_long, payload_unsigned_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_long, payload_unsigned_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_long, payload_float);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_long, payload_float, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_long, payload_float, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_long, payload_float, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_long, payload_double);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_long, payload_double, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_long, payload_double, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_long, payload_double, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_long, payload_IPAddress);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_long, payload_IPAddress, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_long, payload_IPAddress, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_long, payload_IPAddress, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_long, payload_String);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_long, payload_String, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_long, payload_String, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_long, payload_String, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_long, payload_string_literal);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_long, payload_string_literal, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_long, payload_string_literal, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_long, payload_string_literal, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_long, payload___FlashStringHelper);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_long, payload___FlashStringHelper, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_long, payload___FlashStringHelper, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_long, payload___FlashStringHelper, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_long);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_long, payload_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_long, payload_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_long, payload_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_long, payload_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_long, payload_unsigned_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_long, payload_unsigned_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_long, payload_unsigned_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_long, payload_unsigned_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_long, payload_float);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_long, payload_float, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_long, payload_float, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_long, payload_float, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_long, payload_double);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_long, payload_double, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_long, payload_double, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_long, payload_double, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_long, payload_IPAddress);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_long, payload_IPAddress, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_long, payload_IPAddress, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_long, payload_IPAddress, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_long, payload_String);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_long, payload_String, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_long, payload_String, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_long, payload_String, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_long, payload_string_literal);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_long, payload_string_literal, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_long, payload_string_literal, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_long, payload_string_literal, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_long, payload___FlashStringHelper);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_long, payload___FlashStringHelper, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_long, payload___FlashStringHelper, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_long, payload___FlashStringHelper, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_float);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_float, payload_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_float, payload_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_float, payload_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_float, payload_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_float, payload_unsigned_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_float, payload_unsigned_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_float, payload_unsigned_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_float, payload_unsigned_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_float, payload_float);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_float, payload_float, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_float, payload_float, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_float, payload_float, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_float, payload_double);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_float, payload_double, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_float, payload_double, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_float, payload_double, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_float, payload_IPAddress);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_float, payload_IPAddress, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_float, payload_IPAddress, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_float, payload_IPAddress, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_float, payload_String);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_float, payload_String, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_float, payload_String, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_float, payload_String, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_float, payload_string_literal);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_float, payload_string_literal, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_float, payload_string_literal, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_float, payload_string_literal, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_float, payload___FlashStringHelper);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_float, payload___FlashStringHelper, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_float, payload___FlashStringHelper, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_float, payload___FlashStringHelper, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_double);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_double, payload_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_double, payload_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_double, payload_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_double, payload_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_double, payload_unsigned_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_double, payload_unsigned_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_double, payload_unsigned_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_double, payload_unsigned_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_double, payload_float);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_double, payload_float, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_double, payload_float, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_double, payload_float, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_double, payload_double);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_double, payload_double, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_double, payload_double, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_double, payload_double, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_double, payload_IPAddress);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_double, payload_IPAddress, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_double, payload_IPAddress, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_double, payload_IPAddress, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_double, payload_String);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_double, payload_String, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_double, payload_String, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_double, payload_String, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_double, payload_string_literal);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_double, payload_string_literal, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_double, payload_string_literal, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_double, payload_string_literal, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_double, payload___FlashStringHelper);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_double, payload___FlashStringHelper, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_double, payload___FlashStringHelper, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_double, payload___FlashStringHelper, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_IPAddress);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_IPAddress, payload_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_IPAddress, payload_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_IPAddress, payload_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_IPAddress, payload_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_IPAddress, payload_unsigned_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_IPAddress, payload_unsigned_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_IPAddress, payload_unsigned_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_IPAddress, payload_unsigned_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_IPAddress, payload_float);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_IPAddress, payload_float, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_IPAddress, payload_float, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_IPAddress, payload_float, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_IPAddress, payload_double);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_IPAddress, payload_double, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_IPAddress, payload_double, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_IPAddress, payload_double, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_IPAddress, payload_IPAddress);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_IPAddress, payload_IPAddress, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_IPAddress, payload_IPAddress, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_IPAddress, payload_IPAddress, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_IPAddress, payload_String);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_IPAddress, payload_String, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_IPAddress, payload_String, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_IPAddress, payload_String, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_IPAddress, payload_string_literal);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_IPAddress, payload_string_literal, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_IPAddress, payload_string_literal, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_IPAddress, payload_string_literal, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_IPAddress, payload___FlashStringHelper);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_IPAddress, payload___FlashStringHelper, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_IPAddress, payload___FlashStringHelper, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_IPAddress, payload___FlashStringHelper, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_String);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_String, payload_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_String, payload_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_String, payload_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_String, payload_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_String, payload_unsigned_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_String, payload_unsigned_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_String, payload_unsigned_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_String, payload_unsigned_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_String, payload_float);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_String, payload_float, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_String, payload_float, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_String, payload_float, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_String, payload_double);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_String, payload_double, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_String, payload_double, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_String, payload_double, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_String, payload_IPAddress);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_String, payload_IPAddress, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_String, payload_IPAddress, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_String, payload_IPAddress, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_String, payload_String);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_String, payload_String, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_String, payload_String, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_String, payload_String, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_String, payload_string_literal);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_String, payload_string_literal, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_String, payload_string_literal, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_String, payload_string_literal, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_String, payload___FlashStringHelper);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_String, payload___FlashStringHelper, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_String, payload___FlashStringHelper, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_String, payload___FlashStringHelper, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_string_literal, payload_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_string_literal, payload_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_string_literal, payload_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_string_literal, payload_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_string_literal, payload_unsigned_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_string_literal, payload_unsigned_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_string_literal, payload_unsigned_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_string_literal, payload_unsigned_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_string_literal, payload_float);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_string_literal, payload_float, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_string_literal, payload_float, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_string_literal, payload_float, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_string_literal, payload_double);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_string_literal, payload_double, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_string_literal, payload_double, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_string_literal, payload_double, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_string_literal, payload_IPAddress);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_string_literal, payload_IPAddress, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_string_literal, payload_IPAddress, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_string_literal, payload_IPAddress, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_string_literal, payload_String);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_string_literal, payload_String, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_string_literal, payload_String, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_string_literal, payload_String, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_string_literal, payload_string_literal);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_string_literal, payload_string_literal, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_string_literal, payload_string_literal, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_string_literal, payload_string_literal, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_string_literal, payload___FlashStringHelper);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_string_literal, payload___FlashStringHelper, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_string_literal, payload___FlashStringHelper, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_string_literal, payload___FlashStringHelper, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event___FlashStringHelper);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event___FlashStringHelper, payload_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event___FlashStringHelper, payload_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event___FlashStringHelper, payload_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event___FlashStringHelper, payload_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event___FlashStringHelper, payload_unsigned_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event___FlashStringHelper, payload_unsigned_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event___FlashStringHelper, payload_unsigned_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event___FlashStringHelper, payload_unsigned_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event___FlashStringHelper, payload_float);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event___FlashStringHelper, payload_float, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event___FlashStringHelper, payload_float, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event___FlashStringHelper, payload_float, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event___FlashStringHelper, payload_double);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event___FlashStringHelper, payload_double, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event___FlashStringHelper, payload_double, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event___FlashStringHelper, payload_double, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event___FlashStringHelper, payload_IPAddress);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event___FlashStringHelper, payload_IPAddress, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event___FlashStringHelper, payload_IPAddress, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event___FlashStringHelper, payload_IPAddress, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event___FlashStringHelper, payload_String);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event___FlashStringHelper, payload_String, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event___FlashStringHelper, payload_String, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event___FlashStringHelper, payload_String, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event___FlashStringHelper, payload_string_literal);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event___FlashStringHelper, payload_string_literal, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event___FlashStringHelper, payload_string_literal, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event___FlashStringHelper, payload_string_literal, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event___FlashStringHelper, payload___FlashStringHelper);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event___FlashStringHelper, payload___FlashStringHelper, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event___FlashStringHelper, payload___FlashStringHelper, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event___FlashStringHelper, payload___FlashStringHelper, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_long);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_long, payload_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_long, payload_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_long, payload_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_long, payload_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_long, payload_unsigned_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_long, payload_unsigned_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_long, payload_unsigned_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_long, payload_unsigned_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_long, payload_float);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_long, payload_float, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_long, payload_float, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_long, payload_float, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_long, payload_double);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_long, payload_double, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_long, payload_double, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_long, payload_double, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_long, payload_IPAddress);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_long, payload_IPAddress, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_long, payload_IPAddress, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_long, payload_IPAddress, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_long, payload_String);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_long, payload_String, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_long, payload_String, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_long, payload_String, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_long, payload_string_literal);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_long, payload_string_literal, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_long, payload_string_literal, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_long, payload_string_literal, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_long, payload___FlashStringHelper);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_long, payload___FlashStringHelper, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_long, payload___FlashStringHelper, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_long, payload___FlashStringHelper, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_long);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_long, payload_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_long, payload_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_long, payload_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_long, payload_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_long, payload_unsigned_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_long, payload_unsigned_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_long, payload_unsigned_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_long, payload_unsigned_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_long, payload_float);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_long, payload_float, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_long, payload_float, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_long, payload_float, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_long, payload_double);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_long, payload_double, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_long, payload_double, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_long, payload_double, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_long, payload_IPAddress);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_long, payload_IPAddress, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_long, payload_IPAddress, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_long, payload_IPAddress, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_long, payload_String);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_long, payload_String, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_long, payload_String, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_long, payload_String, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_long, payload_string_literal);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_long, payload_string_literal, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_long, payload_string_literal, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_long, payload_string_literal, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_long, payload___FlashStringHelper);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_long, payload___FlashStringHelper, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_long, payload___FlashStringHelper, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_long, payload___FlashStringHelper, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_float);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_float, payload_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_float, payload_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_float, payload_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_float, payload_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_float, payload_unsigned_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_float, payload_unsigned_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_float, payload_unsigned_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_float, payload_unsigned_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_float, payload_float);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_float, payload_float, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_float, payload_float, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_float, payload_float, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_float, payload_double);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_float, payload_double, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_float, payload_double, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_float, payload_double, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_float, payload_IPAddress);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_float, payload_IPAddress, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_float, payload_IPAddress, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_float, payload_IPAddress, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_float, payload_String);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_float, payload_String, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_float, payload_String, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_float, payload_String, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_float, payload_string_literal);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_float, payload_string_literal, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_float, payload_string_literal, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_float, payload_string_literal, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_float, payload___FlashStringHelper);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_float, payload___FlashStringHelper, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_float, payload___FlashStringHelper, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_float, payload___FlashStringHelper, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_double);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_double, payload_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_double, payload_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_double, payload_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_double, payload_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_double, payload_unsigned_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_double, payload_unsigned_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_double, payload_unsigned_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_double, payload_unsigned_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_double, payload_float);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_double, payload_float, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_double, payload_float, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_double, payload_float, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_double, payload_double);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_double, payload_double, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_double, payload_double, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_double, payload_double, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_double, payload_IPAddress);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_double, payload_IPAddress, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_double, payload_IPAddress, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_double, payload_IPAddress, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_double, payload_String);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_double, payload_String, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_double, payload_String, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_double, payload_String, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_double, payload_string_literal);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_double, payload_string_literal, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_double, payload_string_literal, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_double, payload_string_literal, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_double, payload___FlashStringHelper);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_double, payload___FlashStringHelper, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_double, payload___FlashStringHelper, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_double, payload___FlashStringHelper, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_IPAddress);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_IPAddress, payload_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_IPAddress, payload_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_IPAddress, payload_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_IPAddress, payload_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_IPAddress, payload_unsigned_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_IPAddress, payload_unsigned_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_IPAddress, payload_unsigned_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_IPAddress, payload_unsigned_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_IPAddress, payload_float);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_IPAddress, payload_float, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_IPAddress, payload_float, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_IPAddress, payload_float, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_IPAddress, payload_double);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_IPAddress, payload_double, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_IPAddress, payload_double, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_IPAddress, payload_double, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_IPAddress, payload_IPAddress);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_IPAddress, payload_IPAddress, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_IPAddress, payload_IPAddress, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_IPAddress, payload_IPAddress, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_IPAddress, payload_String);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_IPAddress, payload_String, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_IPAddress, payload_String, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_IPAddress, payload_String, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_IPAddress, payload_string_literal);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_IPAddress, payload_string_literal, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_IPAddress, payload_string_literal, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_IPAddress, payload_string_literal, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_IPAddress, payload___FlashStringHelper);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_IPAddress, payload___FlashStringHelper, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_IPAddress, payload___FlashStringHelper, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_IPAddress, payload___FlashStringHelper, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_String);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_String, payload_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_String, payload_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_String, payload_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_String, payload_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_String, payload_unsigned_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_String, payload_unsigned_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_String, payload_unsigned_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_String, payload_unsigned_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_String, payload_float);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_String, payload_float, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_String, payload_float, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_String, payload_float, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_String, payload_double);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_String, payload_double, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_String, payload_double, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_String, payload_double, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_String, payload_IPAddress);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_String, payload_IPAddress, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_String, payload_IPAddress, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_String, payload_IPAddress, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_String, payload_String);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_String, payload_String, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_String, payload_String, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_String, payload_String, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_String, payload_string_literal);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_String, payload_string_literal, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_String, payload_string_literal, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_String, payload_string_literal, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_String, payload___FlashStringHelper);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_String, payload___FlashStringHelper, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_String, payload___FlashStringHelper, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_String, payload___FlashStringHelper, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_string_literal, payload_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_string_literal, payload_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_string_literal, payload_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_string_literal, payload_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_string_literal, payload_unsigned_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_string_literal, payload_unsigned_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_string_literal, payload_unsigned_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_string_literal, payload_unsigned_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_string_literal, payload_float);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_string_literal, payload_float, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_string_literal, payload_float, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_string_literal, payload_float, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_string_literal, payload_double);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_string_literal, payload_double, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_string_literal, payload_double, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_string_literal, payload_double, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_string_literal, payload_IPAddress);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_string_literal, payload_IPAddress, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_string_literal, payload_IPAddress, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_string_literal, payload_IPAddress, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_string_literal, payload_String);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_string_literal, payload_String, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_string_literal, payload_String, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_string_literal, payload_String, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_string_literal, payload_string_literal);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_string_literal, payload_string_literal, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_string_literal, payload_string_literal, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_string_literal, payload_string_literal, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_string_literal, payload___FlashStringHelper);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_string_literal, payload___FlashStringHelper, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_string_literal, payload___FlashStringHelper, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_string_literal, payload___FlashStringHelper, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event___FlashStringHelper);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event___FlashStringHelper, payload_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event___FlashStringHelper, payload_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event___FlashStringHelper, payload_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event___FlashStringHelper, payload_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event___FlashStringHelper, payload_unsigned_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event___FlashStringHelper, payload_unsigned_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event___FlashStringHelper, payload_unsigned_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event___FlashStringHelper, payload_unsigned_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event___FlashStringHelper, payload_float);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event___FlashStringHelper, payload_float, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event___FlashStringHelper, payload_float, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event___FlashStringHelper, payload_float, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event___FlashStringHelper, payload_double);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event___FlashStringHelper, payload_double, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event___FlashStringHelper, payload_double, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event___FlashStringHelper, payload_double, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event___FlashStringHelper, payload_IPAddress);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event___FlashStringHelper, payload_IPAddress, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event___FlashStringHelper, payload_IPAddress, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event___FlashStringHelper, payload_IPAddress, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event___FlashStringHelper, payload_String);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event___FlashStringHelper, payload_String, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event___FlashStringHelper, payload_String, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event___FlashStringHelper, payload_String, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event___FlashStringHelper, payload_string_literal);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event___FlashStringHelper, payload_string_literal, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event___FlashStringHelper, payload_string_literal, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event___FlashStringHelper, payload_string_literal, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event___FlashStringHelper, payload___FlashStringHelper);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event___FlashStringHelper, payload___FlashStringHelper, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event___FlashStringHelper, payload___FlashStringHelper, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event___FlashStringHelper, payload___FlashStringHelper, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_long);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_long, payload_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_long, payload_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_long, payload_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_long, payload_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_long, payload_unsigned_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_long, payload_unsigned_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_long, payload_unsigned_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_long, payload_unsigned_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_long, payload_float);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_long, payload_float, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_long, payload_float, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_long, payload_float, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_long, payload_double);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_long, payload_double, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_long, payload_double, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_long, payload_double, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_long, payload_IPAddress);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_long, payload_IPAddress, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_long, payload_IPAddress, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_long, payload_IPAddress, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_long, payload_String);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_long, payload_String, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_long, payload_String, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_long, payload_String, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_long, payload_string_literal);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_long, payload_string_literal, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_long, payload_string_literal, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_long, payload_string_literal, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_long, payload___FlashStringHelper);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_long, payload___FlashStringHelper, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_long, payload___FlashStringHelper, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_long, payload___FlashStringHelper, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_long);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_long, payload_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_long, payload_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_long, payload_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_long, payload_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_long, payload_unsigned_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_long, payload_unsigned_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_long, payload_unsigned_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_long, payload_unsigned_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_long, payload_float);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_long, payload_float, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_long, payload_float, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_long, payload_float, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_long, payload_double);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_long, payload_double, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_long, payload_double, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_long, payload_double, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_long, payload_IPAddress);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_long, payload_IPAddress, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_long, payload_IPAddress, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_long, payload_IPAddress, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_long, payload_String);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_long, payload_String, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_long, payload_String, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_long, payload_String, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_long, payload_string_literal);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_long, payload_string_literal, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_long, payload_string_literal, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_long, payload_string_literal, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_long, payload___FlashStringHelper);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_long, payload___FlashStringHelper, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_long, payload___FlashStringHelper, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_long, payload___FlashStringHelper, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_float);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_float, payload_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_float, payload_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_float, payload_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_float, payload_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_float, payload_unsigned_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_float, payload_unsigned_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_float, payload_unsigned_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_float, payload_unsigned_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_float, payload_float);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_float, payload_float, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_float, payload_float, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_float, payload_float, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_float, payload_double);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_float, payload_double, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_float, payload_double, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_float, payload_double, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_float, payload_IPAddress);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_float, payload_IPAddress, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_float, payload_IPAddress, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_float, payload_IPAddress, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_float, payload_String);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_float, payload_String, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_float, payload_String, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_float, payload_String, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_float, payload_string_literal);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_float, payload_string_literal, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_float, payload_string_literal, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_float, payload_string_literal, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_float, payload___FlashStringHelper);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_float, payload___FlashStringHelper, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_float, payload___FlashStringHelper, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_float, payload___FlashStringHelper, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_double);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_double, payload_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_double, payload_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_double, payload_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_double, payload_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_double, payload_unsigned_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_double, payload_unsigned_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_double, payload_unsigned_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_double, payload_unsigned_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_double, payload_float);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_double, payload_float, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_double, payload_float, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_double, payload_float, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_double, payload_double);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_double, payload_double, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_double, payload_double, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_double, payload_double, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_double, payload_IPAddress);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_double, payload_IPAddress, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_double, payload_IPAddress, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_double, payload_IPAddress, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_double, payload_String);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_double, payload_String, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_double, payload_String, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_double, payload_String, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_double, payload_string_literal);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_double, payload_string_literal, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_double, payload_string_literal, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_double, payload_string_literal, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_double, payload___FlashStringHelper);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_double, payload___FlashStringHelper, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_double, payload___FlashStringHelper, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_double, payload___FlashStringHelper, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_IPAddress);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_IPAddress, payload_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_IPAddress, payload_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_IPAddress, payload_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_IPAddress, payload_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_IPAddress, payload_unsigned_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_IPAddress, payload_unsigned_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_IPAddress, payload_unsigned_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_IPAddress, payload_unsigned_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_IPAddress, payload_float);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_IPAddress, payload_float, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_IPAddress, payload_float, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_IPAddress, payload_float, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_IPAddress, payload_double);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_IPAddress, payload_double, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_IPAddress, payload_double, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_IPAddress, payload_double, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_IPAddress, payload_IPAddress);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_IPAddress, payload_IPAddress, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_IPAddress, payload_IPAddress, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_IPAddress, payload_IPAddress, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_IPAddress, payload_String);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_IPAddress, payload_String, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_IPAddress, payload_String, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_IPAddress, payload_String, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_IPAddress, payload_string_literal);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_IPAddress, payload_string_literal, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_IPAddress, payload_string_literal, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_IPAddress, payload_string_literal, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_IPAddress, payload___FlashStringHelper);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_IPAddress, payload___FlashStringHelper, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_IPAddress, payload___FlashStringHelper, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_IPAddress, payload___FlashStringHelper, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_String);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_String, payload_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_String, payload_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_String, payload_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_String, payload_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_String, payload_unsigned_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_String, payload_unsigned_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_String, payload_unsigned_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_String, payload_unsigned_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_String, payload_float);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_String, payload_float, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_String, payload_float, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_String, payload_float, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_String, payload_double);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_String, payload_double, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_String, payload_double, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_String, payload_double, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_String, payload_IPAddress);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_String, payload_IPAddress, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_String, payload_IPAddress, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_String, payload_IPAddress, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_String, payload_String);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_String, payload_String, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_String, payload_String, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_String, payload_String, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_String, payload_string_literal);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_String, payload_string_literal, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_String, payload_string_literal, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_String, payload_string_literal, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_String, payload___FlashStringHelper);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_String, payload___FlashStringHelper, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_String, payload___FlashStringHelper, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_String, payload___FlashStringHelper, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_string_literal, payload_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_string_literal, payload_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_string_literal, payload_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_string_literal, payload_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_string_literal, payload_unsigned_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_string_literal, payload_unsigned_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_string_literal, payload_unsigned_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_string_literal, payload_unsigned_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_string_literal, payload_float);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_string_literal, payload_float, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_string_literal, payload_float, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_string_literal, payload_float, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_string_literal, payload_double);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_string_literal, payload_double, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_string_literal, payload_double, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_string_literal, payload_double, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_string_literal, payload_IPAddress);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_string_literal, payload_IPAddress, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_string_literal, payload_IPAddress, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_string_literal, payload_IPAddress, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_string_literal, payload_String);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_string_literal, payload_String, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_string_literal, payload_String, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_string_literal, payload_String, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_string_literal, payload_string_literal);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_string_literal, payload_string_literal, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_string_literal, payload_string_literal, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_string_literal, payload_string_literal, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_string_literal, payload___FlashStringHelper);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_string_literal, payload___FlashStringHelper, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_string_literal, payload___FlashStringHelper, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_string_literal, payload___FlashStringHelper, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event___FlashStringHelper);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event___FlashStringHelper, payload_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event___FlashStringHelper, payload_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event___FlashStringHelper, payload_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event___FlashStringHelper, payload_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event___FlashStringHelper, payload_unsigned_long);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event___FlashStringHelper, payload_unsigned_long, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event___FlashStringHelper, payload_unsigned_long, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event___FlashStringHelper, payload_unsigned_long, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event___FlashStringHelper, payload_float);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event___FlashStringHelper, payload_float, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event___FlashStringHelper, payload_float, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event___FlashStringHelper, payload_float, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event___FlashStringHelper, payload_double);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event___FlashStringHelper, payload_double, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event___FlashStringHelper, payload_double, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event___FlashStringHelper, payload_double, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event___FlashStringHelper, payload_IPAddress);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event___FlashStringHelper, payload_IPAddress, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event___FlashStringHelper, payload_IPAddress, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event___FlashStringHelper, payload_IPAddress, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event___FlashStringHelper, payload_String);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event___FlashStringHelper, payload_String, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event___FlashStringHelper, payload_String, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event___FlashStringHelper, payload_String, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event___FlashStringHelper, payload_string_literal);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event___FlashStringHelper, payload_string_literal, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event___FlashStringHelper, payload_string_literal, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event___FlashStringHelper, payload_string_literal, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event___FlashStringHelper, payload___FlashStringHelper);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event___FlashStringHelper, payload___FlashStringHelper, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event___FlashStringHelper, payload___FlashStringHelper, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event___FlashStringHelper, payload___FlashStringHelper, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
}
