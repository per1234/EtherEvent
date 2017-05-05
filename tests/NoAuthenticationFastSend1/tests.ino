void runTests() {
  // send() overload tests:
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char_array, payload_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char_array, payload_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char_array, payload_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char_array, payload_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char_array, payload_const_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char_array, payload_const_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char_array, payload_const_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char_array, payload_const_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char_array, payload_char);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char_array, payload_char, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char_array, payload_char, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char_array, payload_char, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char_array, payload_byte);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char_array, payload_byte, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char_array, payload_byte, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char_array, payload_byte, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char_array, payload_int8_t);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char_array, payload_int8_t, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char_array, payload_int8_t, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char_array, payload_int8_t, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char_array, payload_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char_array, payload_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char_array, payload_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char_array, payload_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char_array, payload_const_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char_array, payload_const_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char_array, payload_const_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char_array, payload_const_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char_array, payload_unsigned_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char_array, payload_unsigned_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char_array, payload_unsigned_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char_array, payload_unsigned_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_char_array, payload_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_char_array, payload_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_char_array, payload_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_char_array, payload_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_char_array, payload_const_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_char_array, payload_const_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_char_array, payload_const_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_char_array, payload_const_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_char_array, payload_char);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_char_array, payload_char, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_char_array, payload_char, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_char_array, payload_char, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_char_array, payload_byte);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_char_array, payload_byte, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_char_array, payload_byte, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_char_array, payload_byte, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_char_array, payload_int8_t);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_char_array, payload_int8_t, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_char_array, payload_int8_t, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_char_array, payload_int8_t, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_char_array, payload_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_char_array, payload_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_char_array, payload_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_char_array, payload_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_char_array, payload_const_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_char_array, payload_const_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_char_array, payload_const_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_char_array, payload_const_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_char_array, payload_unsigned_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_char_array, payload_unsigned_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_char_array, payload_unsigned_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_char_array, payload_unsigned_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char, payload_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char, payload_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char, payload_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char, payload_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char, payload_const_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char, payload_const_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char, payload_const_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char, payload_const_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char, payload_char);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char, payload_char, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char, payload_char, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char, payload_char, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char, payload_byte);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char, payload_byte, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char, payload_byte, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char, payload_byte, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char, payload_int8_t);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char, payload_int8_t, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char, payload_int8_t, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char, payload_int8_t, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char, payload_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char, payload_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char, payload_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char, payload_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char, payload_const_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char, payload_const_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char, payload_const_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char, payload_const_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char, payload_unsigned_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char, payload_unsigned_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char, payload_unsigned_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_char, payload_unsigned_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_byte);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_byte, payload_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_byte, payload_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_byte, payload_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_byte, payload_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_byte, payload_const_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_byte, payload_const_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_byte, payload_const_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_byte, payload_const_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_byte, payload_char);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_byte, payload_char, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_byte, payload_char, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_byte, payload_char, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_byte, payload_byte);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_byte, payload_byte, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_byte, payload_byte, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_byte, payload_byte, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_byte, payload_int8_t);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_byte, payload_int8_t, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_byte, payload_int8_t, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_byte, payload_int8_t, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_byte, payload_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_byte, payload_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_byte, payload_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_byte, payload_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_byte, payload_const_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_byte, payload_const_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_byte, payload_const_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_byte, payload_const_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_byte, payload_unsigned_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_byte, payload_unsigned_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_byte, payload_unsigned_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_byte, payload_unsigned_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int8_t);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int8_t, payload_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int8_t, payload_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int8_t, payload_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int8_t, payload_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int8_t, payload_const_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int8_t, payload_const_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int8_t, payload_const_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int8_t, payload_const_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int8_t, payload_char);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int8_t, payload_char, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int8_t, payload_char, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int8_t, payload_char, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int8_t, payload_byte);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int8_t, payload_byte, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int8_t, payload_byte, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int8_t, payload_byte, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int8_t, payload_int8_t);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int8_t, payload_int8_t, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int8_t, payload_int8_t, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int8_t, payload_int8_t, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int8_t, payload_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int8_t, payload_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int8_t, payload_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int8_t, payload_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int8_t, payload_const_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int8_t, payload_const_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int8_t, payload_const_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int8_t, payload_const_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int8_t, payload_unsigned_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int8_t, payload_unsigned_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int8_t, payload_unsigned_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int8_t, payload_unsigned_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int, payload_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int, payload_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int, payload_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int, payload_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int, payload_const_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int, payload_const_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int, payload_const_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int, payload_const_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int, payload_char);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int, payload_char, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int, payload_char, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int, payload_char, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int, payload_byte);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int, payload_byte, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int, payload_byte, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int, payload_byte, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int, payload_int8_t);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int, payload_int8_t, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int, payload_int8_t, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int, payload_int8_t, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int, payload_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int, payload_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int, payload_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int, payload_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int, payload_const_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int, payload_const_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int, payload_const_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int, payload_const_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int, payload_unsigned_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int, payload_unsigned_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int, payload_unsigned_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_int, payload_unsigned_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_int);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_int, payload_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_int, payload_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_int, payload_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_int, payload_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_int, payload_const_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_int, payload_const_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_int, payload_const_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_int, payload_const_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_int, payload_char);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_int, payload_char, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_int, payload_char, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_int, payload_char, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_int, payload_byte);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_int, payload_byte, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_int, payload_byte, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_int, payload_byte, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_int, payload_int8_t);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_int, payload_int8_t, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_int, payload_int8_t, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_int, payload_int8_t, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_int, payload_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_int, payload_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_int, payload_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_int, payload_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_int, payload_const_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_int, payload_const_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_int, payload_const_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_int, payload_const_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_int, payload_unsigned_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_int, payload_unsigned_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_int, payload_unsigned_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_const_int, payload_unsigned_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_int);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_int, payload_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_int, payload_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_int, payload_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_int, payload_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_int, payload_const_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_int, payload_const_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_int, payload_const_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_int, payload_const_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_int, payload_char);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_int, payload_char, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_int, payload_char, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_int, payload_char, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_int, payload_byte);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_int, payload_byte, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_int, payload_byte, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_int, payload_byte, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_int, payload_int8_t);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_int, payload_int8_t, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_int, payload_int8_t, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_int, payload_int8_t, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_int, payload_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_int, payload_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_int, payload_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_int, payload_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_int, payload_const_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_int, payload_const_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_int, payload_const_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_int, payload_const_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_int, payload_unsigned_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_int, payload_unsigned_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_int, payload_unsigned_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_IPAddress, sendPort, event_unsigned_int, payload_unsigned_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char_array, payload_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char_array, payload_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char_array, payload_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char_array, payload_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char_array, payload_const_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char_array, payload_const_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char_array, payload_const_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char_array, payload_const_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char_array, payload_char);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char_array, payload_char, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char_array, payload_char, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char_array, payload_char, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char_array, payload_byte);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char_array, payload_byte, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char_array, payload_byte, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char_array, payload_byte, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char_array, payload_int8_t);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char_array, payload_int8_t, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char_array, payload_int8_t, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char_array, payload_int8_t, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char_array, payload_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char_array, payload_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char_array, payload_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char_array, payload_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char_array, payload_const_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char_array, payload_const_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char_array, payload_const_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char_array, payload_const_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char_array, payload_unsigned_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char_array, payload_unsigned_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char_array, payload_unsigned_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char_array, payload_unsigned_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_char_array, payload_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_char_array, payload_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_char_array, payload_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_char_array, payload_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_char_array, payload_const_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_char_array, payload_const_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_char_array, payload_const_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_char_array, payload_const_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_char_array, payload_char);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_char_array, payload_char, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_char_array, payload_char, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_char_array, payload_char, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_char_array, payload_byte);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_char_array, payload_byte, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_char_array, payload_byte, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_char_array, payload_byte, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_char_array, payload_int8_t);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_char_array, payload_int8_t, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_char_array, payload_int8_t, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_char_array, payload_int8_t, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_char_array, payload_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_char_array, payload_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_char_array, payload_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_char_array, payload_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_char_array, payload_const_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_char_array, payload_const_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_char_array, payload_const_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_char_array, payload_const_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_char_array, payload_unsigned_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_char_array, payload_unsigned_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_char_array, payload_unsigned_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_char_array, payload_unsigned_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char, payload_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char, payload_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char, payload_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char, payload_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char, payload_const_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char, payload_const_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char, payload_const_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char, payload_const_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char, payload_char);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char, payload_char, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char, payload_char, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char, payload_char, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char, payload_byte);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char, payload_byte, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char, payload_byte, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char, payload_byte, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char, payload_int8_t);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char, payload_int8_t, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char, payload_int8_t, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char, payload_int8_t, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char, payload_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char, payload_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char, payload_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char, payload_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char, payload_const_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char, payload_const_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char, payload_const_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char, payload_const_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char, payload_unsigned_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char, payload_unsigned_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char, payload_unsigned_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_char, payload_unsigned_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_byte);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_byte, payload_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_byte, payload_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_byte, payload_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_byte, payload_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_byte, payload_const_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_byte, payload_const_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_byte, payload_const_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_byte, payload_const_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_byte, payload_char);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_byte, payload_char, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_byte, payload_char, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_byte, payload_char, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_byte, payload_byte);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_byte, payload_byte, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_byte, payload_byte, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_byte, payload_byte, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_byte, payload_int8_t);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_byte, payload_int8_t, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_byte, payload_int8_t, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_byte, payload_int8_t, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_byte, payload_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_byte, payload_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_byte, payload_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_byte, payload_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_byte, payload_const_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_byte, payload_const_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_byte, payload_const_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_byte, payload_const_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_byte, payload_unsigned_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_byte, payload_unsigned_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_byte, payload_unsigned_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_byte, payload_unsigned_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int8_t);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int8_t, payload_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int8_t, payload_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int8_t, payload_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int8_t, payload_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int8_t, payload_const_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int8_t, payload_const_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int8_t, payload_const_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int8_t, payload_const_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int8_t, payload_char);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int8_t, payload_char, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int8_t, payload_char, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int8_t, payload_char, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int8_t, payload_byte);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int8_t, payload_byte, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int8_t, payload_byte, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int8_t, payload_byte, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int8_t, payload_int8_t);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int8_t, payload_int8_t, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int8_t, payload_int8_t, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int8_t, payload_int8_t, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int8_t, payload_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int8_t, payload_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int8_t, payload_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int8_t, payload_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int8_t, payload_const_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int8_t, payload_const_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int8_t, payload_const_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int8_t, payload_const_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int8_t, payload_unsigned_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int8_t, payload_unsigned_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int8_t, payload_unsigned_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int8_t, payload_unsigned_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int, payload_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int, payload_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int, payload_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int, payload_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int, payload_const_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int, payload_const_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int, payload_const_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int, payload_const_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int, payload_char);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int, payload_char, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int, payload_char, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int, payload_char, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int, payload_byte);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int, payload_byte, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int, payload_byte, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int, payload_byte, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int, payload_int8_t);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int, payload_int8_t, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int, payload_int8_t, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int, payload_int8_t, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int, payload_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int, payload_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int, payload_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int, payload_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int, payload_const_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int, payload_const_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int, payload_const_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int, payload_const_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int, payload_unsigned_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int, payload_unsigned_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int, payload_unsigned_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_int, payload_unsigned_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_int);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_int, payload_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_int, payload_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_int, payload_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_int, payload_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_int, payload_const_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_int, payload_const_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_int, payload_const_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_int, payload_const_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_int, payload_char);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_int, payload_char, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_int, payload_char, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_int, payload_char, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_int, payload_byte);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_int, payload_byte, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_int, payload_byte, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_int, payload_byte, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_int, payload_int8_t);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_int, payload_int8_t, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_int, payload_int8_t, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_int, payload_int8_t, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_int, payload_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_int, payload_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_int, payload_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_int, payload_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_int, payload_const_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_int, payload_const_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_int, payload_const_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_int, payload_const_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_int, payload_unsigned_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_int, payload_unsigned_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_int, payload_unsigned_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_const_int, payload_unsigned_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_int);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_int, payload_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_int, payload_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_int, payload_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_int, payload_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_int, payload_const_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_int, payload_const_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_int, payload_const_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_int, payload_const_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_int, payload_char);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_int, payload_char, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_int, payload_char, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_int, payload_char, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_int, payload_byte);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_int, payload_byte, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_int, payload_byte, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_int, payload_byte, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_int, payload_int8_t);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_int, payload_int8_t, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_int, payload_int8_t, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_int, payload_int8_t, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_int, payload_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_int, payload_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_int, payload_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_int, payload_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_int, payload_const_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_int, payload_const_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_int, payload_const_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_int, payload_const_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_int, payload_unsigned_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_int, payload_unsigned_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_int, payload_unsigned_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_byte_array, sendPort, event_unsigned_int, payload_unsigned_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char_array, payload_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char_array, payload_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char_array, payload_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char_array, payload_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char_array, payload_const_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char_array, payload_const_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char_array, payload_const_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char_array, payload_const_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char_array, payload_char);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char_array, payload_char, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char_array, payload_char, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char_array, payload_char, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char_array, payload_byte);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char_array, payload_byte, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char_array, payload_byte, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char_array, payload_byte, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char_array, payload_int8_t);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char_array, payload_int8_t, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char_array, payload_int8_t, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char_array, payload_int8_t, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char_array, payload_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char_array, payload_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char_array, payload_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char_array, payload_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char_array, payload_const_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char_array, payload_const_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char_array, payload_const_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char_array, payload_const_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char_array, payload_unsigned_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char_array, payload_unsigned_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char_array, payload_unsigned_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char_array, payload_unsigned_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_char_array, payload_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_char_array, payload_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_char_array, payload_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_char_array, payload_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_char_array, payload_const_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_char_array, payload_const_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_char_array, payload_const_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_char_array, payload_const_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_char_array, payload_char);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_char_array, payload_char, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_char_array, payload_char, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_char_array, payload_char, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_char_array, payload_byte);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_char_array, payload_byte, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_char_array, payload_byte, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_char_array, payload_byte, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_char_array, payload_int8_t);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_char_array, payload_int8_t, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_char_array, payload_int8_t, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_char_array, payload_int8_t, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_char_array, payload_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_char_array, payload_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_char_array, payload_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_char_array, payload_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_char_array, payload_const_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_char_array, payload_const_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_char_array, payload_const_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_char_array, payload_const_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_char_array, payload_unsigned_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_char_array, payload_unsigned_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_char_array, payload_unsigned_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_char_array, payload_unsigned_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char, payload_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char, payload_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char, payload_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char, payload_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char, payload_const_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char, payload_const_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char, payload_const_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char, payload_const_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char, payload_char);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char, payload_char, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char, payload_char, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char, payload_char, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char, payload_byte);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char, payload_byte, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char, payload_byte, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char, payload_byte, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char, payload_int8_t);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char, payload_int8_t, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char, payload_int8_t, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char, payload_int8_t, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char, payload_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char, payload_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char, payload_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char, payload_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char, payload_const_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char, payload_const_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char, payload_const_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char, payload_const_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char, payload_unsigned_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char, payload_unsigned_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char, payload_unsigned_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_char, payload_unsigned_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_byte);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_byte, payload_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_byte, payload_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_byte, payload_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_byte, payload_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_byte, payload_const_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_byte, payload_const_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_byte, payload_const_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_byte, payload_const_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_byte, payload_char);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_byte, payload_char, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_byte, payload_char, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_byte, payload_char, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_byte, payload_byte);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_byte, payload_byte, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_byte, payload_byte, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_byte, payload_byte, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_byte, payload_int8_t);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_byte, payload_int8_t, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_byte, payload_int8_t, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_byte, payload_int8_t, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_byte, payload_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_byte, payload_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_byte, payload_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_byte, payload_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_byte, payload_const_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_byte, payload_const_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_byte, payload_const_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_byte, payload_const_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_byte, payload_unsigned_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_byte, payload_unsigned_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_byte, payload_unsigned_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_byte, payload_unsigned_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int8_t);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int8_t, payload_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int8_t, payload_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int8_t, payload_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int8_t, payload_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int8_t, payload_const_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int8_t, payload_const_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int8_t, payload_const_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int8_t, payload_const_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int8_t, payload_char);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int8_t, payload_char, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int8_t, payload_char, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int8_t, payload_char, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int8_t, payload_byte);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int8_t, payload_byte, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int8_t, payload_byte, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int8_t, payload_byte, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int8_t, payload_int8_t);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int8_t, payload_int8_t, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int8_t, payload_int8_t, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int8_t, payload_int8_t, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int8_t, payload_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int8_t, payload_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int8_t, payload_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int8_t, payload_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int8_t, payload_const_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int8_t, payload_const_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int8_t, payload_const_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int8_t, payload_const_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int8_t, payload_unsigned_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int8_t, payload_unsigned_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int8_t, payload_unsigned_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int8_t, payload_unsigned_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int, payload_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int, payload_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int, payload_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int, payload_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int, payload_const_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int, payload_const_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int, payload_const_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int, payload_const_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int, payload_char);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int, payload_char, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int, payload_char, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int, payload_char, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int, payload_byte);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int, payload_byte, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int, payload_byte, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int, payload_byte, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int, payload_int8_t);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int, payload_int8_t, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int, payload_int8_t, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int, payload_int8_t, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int, payload_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int, payload_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int, payload_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int, payload_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int, payload_const_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int, payload_const_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int, payload_const_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int, payload_const_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int, payload_unsigned_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int, payload_unsigned_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int, payload_unsigned_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_int, payload_unsigned_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_int);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_int, payload_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_int, payload_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_int, payload_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_int, payload_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_int, payload_const_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_int, payload_const_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_int, payload_const_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_int, payload_const_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_int, payload_char);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_int, payload_char, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_int, payload_char, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_int, payload_char, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_int, payload_byte);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_int, payload_byte, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_int, payload_byte, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_int, payload_byte, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_int, payload_int8_t);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_int, payload_int8_t, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_int, payload_int8_t, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_int, payload_int8_t, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_int, payload_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_int, payload_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_int, payload_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_int, payload_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_int, payload_const_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_int, payload_const_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_int, payload_const_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_int, payload_const_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_int, payload_unsigned_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_int, payload_unsigned_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_int, payload_unsigned_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_const_int, payload_unsigned_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_int);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_int, payload_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_int, payload_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_int, payload_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_int, payload_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_int, payload_const_char_array);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_int, payload_const_char_array, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_int, payload_const_char_array, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_int, payload_const_char_array, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_int, payload_char);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_int, payload_char, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_int, payload_char, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_int, payload_char, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_int, payload_byte);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_int, payload_byte, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_int, payload_byte, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_int, payload_byte, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_int, payload_int8_t);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_int, payload_int8_t, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_int, payload_int8_t, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_int, payload_int8_t, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_int, payload_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_int, payload_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_int, payload_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_int, payload_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_int, payload_const_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_int, payload_const_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_int, payload_const_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_int, payload_const_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_int, payload_unsigned_int);
#ifndef ETHEREVENT_NO_AUTHENTICATION
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_int, payload_unsigned_int, sendPassword_char_array);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_int, payload_unsigned_int, sendPassword_string_literal);
  EtherEvent.send(ethernetClient, target_const_byte_array, sendPort, event_unsigned_int, payload_unsigned_int, sendPassword___FlashStringHelper);
#endif //ETHEREVENT_NO_AUTHENTICATION
}
