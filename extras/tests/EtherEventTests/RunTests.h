void runTests() {
  // send() overload tests:
#if TEST_BATCH == 0
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventCharArray, "CharArray", payloadCharArray, "CharArray");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventCharArray, "CharArray", payloadCharArray, "CharArray", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventCharArray, "CharArray", payloadCharArray, "CharArray", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventCharArray, "CharArray", payloadCharArray, "CharArray", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventCharArray, "CharArray", payloadCharArray, "CharArray", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventCharArray, "CharArray", payloadCharArray, "CharArray", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventCharArray, "CharArray", payloadConstCharArray, "ConstCharArray");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventCharArray, "CharArray", payloadConstCharArray, "ConstCharArray", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventCharArray, "CharArray", payloadConstCharArray, "ConstCharArray", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventCharArray, "CharArray", payloadConstCharArray, "ConstCharArray", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventCharArray, "CharArray", payloadConstCharArray, "ConstCharArray", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventCharArray, "CharArray", payloadConstCharArray, "ConstCharArray", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventCharArray, "CharArray", payloadChar, "Char");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventCharArray, "CharArray", payloadChar, "Char", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventCharArray, "CharArray", payloadChar, "Char", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventCharArray, "CharArray", payloadChar, "Char", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventCharArray, "CharArray", payloadChar, "Char", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventCharArray, "CharArray", payloadChar, "Char", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventCharArray, "CharArray", payloadByte, "Byte");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventCharArray, "CharArray", payloadByte, "Byte", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventCharArray, "CharArray", payloadByte, "Byte", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventCharArray, "CharArray", payloadByte, "Byte", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventCharArray, "CharArray", payloadByte, "Byte", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventCharArray, "CharArray", payloadByte, "Byte", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstCharArray, "ConstCharArray", payloadCharArray, "CharArray");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstCharArray, "ConstCharArray", payloadCharArray, "CharArray", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstCharArray, "ConstCharArray", payloadCharArray, "CharArray", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstCharArray, "ConstCharArray", payloadCharArray, "CharArray", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstCharArray, "ConstCharArray", payloadCharArray, "CharArray", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstCharArray, "ConstCharArray", payloadCharArray, "CharArray", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstCharArray, "ConstCharArray", payloadConstCharArray, "ConstCharArray");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstCharArray, "ConstCharArray", payloadConstCharArray, "ConstCharArray", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstCharArray, "ConstCharArray", payloadConstCharArray, "ConstCharArray", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstCharArray, "ConstCharArray", payloadConstCharArray, "ConstCharArray", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstCharArray, "ConstCharArray", payloadConstCharArray, "ConstCharArray", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstCharArray, "ConstCharArray", payloadConstCharArray, "ConstCharArray", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstCharArray, "ConstCharArray", payloadChar, "Char");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstCharArray, "ConstCharArray", payloadChar, "Char", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstCharArray, "ConstCharArray", payloadChar, "Char", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstCharArray, "ConstCharArray", payloadChar, "Char", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstCharArray, "ConstCharArray", payloadChar, "Char", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstCharArray, "ConstCharArray", payloadChar, "Char", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstCharArray, "ConstCharArray", payloadByte, "Byte");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstCharArray, "ConstCharArray", payloadByte, "Byte", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstCharArray, "ConstCharArray", payloadByte, "Byte", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstCharArray, "ConstCharArray", payloadByte, "Byte", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstCharArray, "ConstCharArray", payloadByte, "Byte", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstCharArray, "ConstCharArray", payloadByte, "Byte", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventChar, "Char");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventChar, "Char", payloadCharArray, "CharArray");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventChar, "Char", payloadCharArray, "CharArray", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventChar, "Char", payloadCharArray, "CharArray", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventChar, "Char", payloadCharArray, "CharArray", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventChar, "Char", payloadCharArray, "CharArray", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventChar, "Char", payloadCharArray, "CharArray", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventChar, "Char", payloadConstCharArray, "ConstCharArray");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventChar, "Char", payloadConstCharArray, "ConstCharArray", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventChar, "Char", payloadConstCharArray, "ConstCharArray", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventChar, "Char", payloadConstCharArray, "ConstCharArray", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventChar, "Char", payloadConstCharArray, "ConstCharArray", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventChar, "Char", payloadConstCharArray, "ConstCharArray", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventChar, "Char", payloadChar, "Char");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventChar, "Char", payloadChar, "Char", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventChar, "Char", payloadChar, "Char", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventChar, "Char", payloadChar, "Char", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventChar, "Char", payloadChar, "Char", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventChar, "Char", payloadChar, "Char", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventChar, "Char", payloadByte, "Byte");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventChar, "Char", payloadByte, "Byte", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventChar, "Char", payloadByte, "Byte", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventChar, "Char", payloadByte, "Byte", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventChar, "Char", payloadByte, "Byte", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventChar, "Char", payloadByte, "Byte", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventByte, "Byte");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventByte, "Byte", payloadCharArray, "CharArray");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventByte, "Byte", payloadCharArray, "CharArray", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventByte, "Byte", payloadCharArray, "CharArray", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventByte, "Byte", payloadCharArray, "CharArray", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventByte, "Byte", payloadCharArray, "CharArray", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventByte, "Byte", payloadCharArray, "CharArray", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventByte, "Byte", payloadConstCharArray, "ConstCharArray");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventByte, "Byte", payloadConstCharArray, "ConstCharArray", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventByte, "Byte", payloadConstCharArray, "ConstCharArray", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventByte, "Byte", payloadConstCharArray, "ConstCharArray", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventByte, "Byte", payloadConstCharArray, "ConstCharArray", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventByte, "Byte", payloadConstCharArray, "ConstCharArray", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventByte, "Byte", payloadChar, "Char");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventByte, "Byte", payloadChar, "Char", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventByte, "Byte", payloadChar, "Char", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventByte, "Byte", payloadChar, "Char", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventByte, "Byte", payloadChar, "Char", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventByte, "Byte", payloadChar, "Char", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventByte, "Byte", payloadByte, "Byte");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventByte, "Byte", payloadByte, "Byte", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventByte, "Byte", payloadByte, "Byte", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventByte, "Byte", payloadByte, "Byte", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventByte, "Byte", payloadByte, "Byte", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventByte, "Byte", payloadByte, "Byte", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventCharArray, "CharArray", payloadCharArray, "CharArray");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventCharArray, "CharArray", payloadCharArray, "CharArray", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventCharArray, "CharArray", payloadCharArray, "CharArray", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventCharArray, "CharArray", payloadCharArray, "CharArray", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventCharArray, "CharArray", payloadCharArray, "CharArray", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventCharArray, "CharArray", payloadCharArray, "CharArray", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventCharArray, "CharArray", payloadConstCharArray, "ConstCharArray");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventCharArray, "CharArray", payloadConstCharArray, "ConstCharArray", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventCharArray, "CharArray", payloadConstCharArray, "ConstCharArray", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventCharArray, "CharArray", payloadConstCharArray, "ConstCharArray", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventCharArray, "CharArray", payloadConstCharArray, "ConstCharArray", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventCharArray, "CharArray", payloadConstCharArray, "ConstCharArray", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventCharArray, "CharArray", payloadChar, "Char");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventCharArray, "CharArray", payloadChar, "Char", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventCharArray, "CharArray", payloadChar, "Char", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventCharArray, "CharArray", payloadChar, "Char", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventCharArray, "CharArray", payloadChar, "Char", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventCharArray, "CharArray", payloadChar, "Char", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventCharArray, "CharArray", payloadByte, "Byte");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventCharArray, "CharArray", payloadByte, "Byte", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventCharArray, "CharArray", payloadByte, "Byte", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventCharArray, "CharArray", payloadByte, "Byte", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventCharArray, "CharArray", payloadByte, "Byte", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventCharArray, "CharArray", payloadByte, "Byte", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadCharArray, "CharArray");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadCharArray, "CharArray", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadCharArray, "CharArray", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadCharArray, "CharArray", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadCharArray, "CharArray", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadCharArray, "CharArray", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadConstCharArray, "ConstCharArray");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadConstCharArray, "ConstCharArray", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadConstCharArray, "ConstCharArray", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadConstCharArray, "ConstCharArray", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadConstCharArray, "ConstCharArray", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadConstCharArray, "ConstCharArray", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadChar, "Char");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadChar, "Char", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadChar, "Char", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadChar, "Char", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadChar, "Char", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadChar, "Char", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadByte, "Byte");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadByte, "Byte", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadByte, "Byte", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadByte, "Byte", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadByte, "Byte", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadByte, "Byte", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventChar, "Char");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventChar, "Char", payloadCharArray, "CharArray");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventChar, "Char", payloadCharArray, "CharArray", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventChar, "Char", payloadCharArray, "CharArray", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventChar, "Char", payloadCharArray, "CharArray", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventChar, "Char", payloadCharArray, "CharArray", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventChar, "Char", payloadCharArray, "CharArray", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventChar, "Char", payloadConstCharArray, "ConstCharArray");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventChar, "Char", payloadConstCharArray, "ConstCharArray", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventChar, "Char", payloadConstCharArray, "ConstCharArray", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventChar, "Char", payloadConstCharArray, "ConstCharArray", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventChar, "Char", payloadConstCharArray, "ConstCharArray", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventChar, "Char", payloadConstCharArray, "ConstCharArray", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventChar, "Char", payloadChar, "Char");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventChar, "Char", payloadChar, "Char", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventChar, "Char", payloadChar, "Char", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventChar, "Char", payloadChar, "Char", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventChar, "Char", payloadChar, "Char", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventChar, "Char", payloadChar, "Char", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventChar, "Char", payloadByte, "Byte");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventChar, "Char", payloadByte, "Byte", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventChar, "Char", payloadByte, "Byte", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventChar, "Char", payloadByte, "Byte", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventChar, "Char", payloadByte, "Byte", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventChar, "Char", payloadByte, "Byte", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventByte, "Byte");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventByte, "Byte", payloadCharArray, "CharArray");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventByte, "Byte", payloadCharArray, "CharArray", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventByte, "Byte", payloadCharArray, "CharArray", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventByte, "Byte", payloadCharArray, "CharArray", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventByte, "Byte", payloadCharArray, "CharArray", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventByte, "Byte", payloadCharArray, "CharArray", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventByte, "Byte", payloadConstCharArray, "ConstCharArray");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventByte, "Byte", payloadConstCharArray, "ConstCharArray", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventByte, "Byte", payloadConstCharArray, "ConstCharArray", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventByte, "Byte", payloadConstCharArray, "ConstCharArray", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventByte, "Byte", payloadConstCharArray, "ConstCharArray", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventByte, "Byte", payloadConstCharArray, "ConstCharArray", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventByte, "Byte", payloadChar, "Char");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventByte, "Byte", payloadChar, "Char", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventByte, "Byte", payloadChar, "Char", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventByte, "Byte", payloadChar, "Char", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventByte, "Byte", payloadChar, "Char", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventByte, "Byte", payloadChar, "Char", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventByte, "Byte", payloadByte, "Byte");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventByte, "Byte", payloadByte, "Byte", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventByte, "Byte", payloadByte, "Byte", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventByte, "Byte", payloadByte, "Byte", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventByte, "Byte", payloadByte, "Byte", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventByte, "Byte", payloadByte, "Byte", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventCharArray, "CharArray", payloadCharArray, "CharArray");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventCharArray, "CharArray", payloadCharArray, "CharArray", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventCharArray, "CharArray", payloadCharArray, "CharArray", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventCharArray, "CharArray", payloadCharArray, "CharArray", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventCharArray, "CharArray", payloadCharArray, "CharArray", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventCharArray, "CharArray", payloadCharArray, "CharArray", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventCharArray, "CharArray", payloadConstCharArray, "ConstCharArray");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventCharArray, "CharArray", payloadConstCharArray, "ConstCharArray", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventCharArray, "CharArray", payloadConstCharArray, "ConstCharArray", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventCharArray, "CharArray", payloadConstCharArray, "ConstCharArray", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventCharArray, "CharArray", payloadConstCharArray, "ConstCharArray", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventCharArray, "CharArray", payloadConstCharArray, "ConstCharArray", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventCharArray, "CharArray", payloadChar, "Char");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventCharArray, "CharArray", payloadChar, "Char", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventCharArray, "CharArray", payloadChar, "Char", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventCharArray, "CharArray", payloadChar, "Char", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventCharArray, "CharArray", payloadChar, "Char", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventCharArray, "CharArray", payloadChar, "Char", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventCharArray, "CharArray", payloadByte, "Byte");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventCharArray, "CharArray", payloadByte, "Byte", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventCharArray, "CharArray", payloadByte, "Byte", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventCharArray, "CharArray", payloadByte, "Byte", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventCharArray, "CharArray", payloadByte, "Byte", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventCharArray, "CharArray", payloadByte, "Byte", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadCharArray, "CharArray");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadCharArray, "CharArray", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadCharArray, "CharArray", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadCharArray, "CharArray", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadCharArray, "CharArray", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadCharArray, "CharArray", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadConstCharArray, "ConstCharArray");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadConstCharArray, "ConstCharArray", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadConstCharArray, "ConstCharArray", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadConstCharArray, "ConstCharArray", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadConstCharArray, "ConstCharArray", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadConstCharArray, "ConstCharArray", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadChar, "Char");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadChar, "Char", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadChar, "Char", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadChar, "Char", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadChar, "Char", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadChar, "Char", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadByte, "Byte");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadByte, "Byte", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadByte, "Byte", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadByte, "Byte", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadByte, "Byte", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstCharArray, "ConstCharArray", payloadByte, "Byte", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventChar, "Char");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventChar, "Char", payloadCharArray, "CharArray");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventChar, "Char", payloadCharArray, "CharArray", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventChar, "Char", payloadCharArray, "CharArray", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventChar, "Char", payloadCharArray, "CharArray", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventChar, "Char", payloadCharArray, "CharArray", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventChar, "Char", payloadCharArray, "CharArray", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventChar, "Char", payloadConstCharArray, "ConstCharArray");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventChar, "Char", payloadConstCharArray, "ConstCharArray", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventChar, "Char", payloadConstCharArray, "ConstCharArray", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventChar, "Char", payloadConstCharArray, "ConstCharArray", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventChar, "Char", payloadConstCharArray, "ConstCharArray", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventChar, "Char", payloadConstCharArray, "ConstCharArray", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventChar, "Char", payloadChar, "Char");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventChar, "Char", payloadChar, "Char", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventChar, "Char", payloadChar, "Char", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventChar, "Char", payloadChar, "Char", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventChar, "Char", payloadChar, "Char", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventChar, "Char", payloadChar, "Char", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventChar, "Char", payloadByte, "Byte");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventChar, "Char", payloadByte, "Byte", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventChar, "Char", payloadByte, "Byte", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventChar, "Char", payloadByte, "Byte", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventChar, "Char", payloadByte, "Byte", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventChar, "Char", payloadByte, "Byte", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventByte, "Byte");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventByte, "Byte", payloadCharArray, "CharArray");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventByte, "Byte", payloadCharArray, "CharArray", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventByte, "Byte", payloadCharArray, "CharArray", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventByte, "Byte", payloadCharArray, "CharArray", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventByte, "Byte", payloadCharArray, "CharArray", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventByte, "Byte", payloadCharArray, "CharArray", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventByte, "Byte", payloadConstCharArray, "ConstCharArray");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventByte, "Byte", payloadConstCharArray, "ConstCharArray", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventByte, "Byte", payloadConstCharArray, "ConstCharArray", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventByte, "Byte", payloadConstCharArray, "ConstCharArray", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventByte, "Byte", payloadConstCharArray, "ConstCharArray", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventByte, "Byte", payloadConstCharArray, "ConstCharArray", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventByte, "Byte", payloadChar, "Char");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventByte, "Byte", payloadChar, "Char", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventByte, "Byte", payloadChar, "Char", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventByte, "Byte", payloadChar, "Char", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventByte, "Byte", payloadChar, "Char", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventByte, "Byte", payloadChar, "Char", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventByte, "Byte", payloadByte, "Byte");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventByte, "Byte", payloadByte, "Byte", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventByte, "Byte", payloadByte, "Byte", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventByte, "Byte", payloadByte, "Byte", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventByte, "Byte", payloadByte, "Byte", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventByte, "Byte", payloadByte, "Byte", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
#elif TEST_BATCH == 1
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt8_t, "Int8_t");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt8_t, "Int8_t", payloadInt8_t, "Int8_t");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt8_t, "Int8_t", payloadInt8_t, "Int8_t", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt8_t, "Int8_t", payloadInt8_t, "Int8_t", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt8_t, "Int8_t", payloadInt8_t, "Int8_t", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt8_t, "Int8_t", payloadInt8_t, "Int8_t", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt8_t, "Int8_t", payloadInt8_t, "Int8_t", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt8_t, "Int8_t", payloadInt, "Int");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt8_t, "Int8_t", payloadInt, "Int", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt8_t, "Int8_t", payloadInt, "Int", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt8_t, "Int8_t", payloadInt, "Int", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt8_t, "Int8_t", payloadInt, "Int", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt8_t, "Int8_t", payloadInt, "Int", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt8_t, "Int8_t", payloadConstInt, "ConstInt");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt8_t, "Int8_t", payloadConstInt, "ConstInt", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt8_t, "Int8_t", payloadConstInt, "ConstInt", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt8_t, "Int8_t", payloadConstInt, "ConstInt", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt8_t, "Int8_t", payloadConstInt, "ConstInt", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt8_t, "Int8_t", payloadConstInt, "ConstInt", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt8_t, "Int8_t", payloadUnsignedInt, "UnsignedInt");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt8_t, "Int8_t", payloadUnsignedInt, "UnsignedInt", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt8_t, "Int8_t", payloadUnsignedInt, "UnsignedInt", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt8_t, "Int8_t", payloadUnsignedInt, "UnsignedInt", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt8_t, "Int8_t", payloadUnsignedInt, "UnsignedInt", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt8_t, "Int8_t", payloadUnsignedInt, "UnsignedInt", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt, "Int");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt, "Int", payloadInt8_t, "Int8_t");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt, "Int", payloadInt8_t, "Int8_t", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt, "Int", payloadInt8_t, "Int8_t", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt, "Int", payloadInt8_t, "Int8_t", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt, "Int", payloadInt8_t, "Int8_t", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt, "Int", payloadInt8_t, "Int8_t", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt, "Int", payloadInt, "Int");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt, "Int", payloadInt, "Int", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt, "Int", payloadInt, "Int", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt, "Int", payloadInt, "Int", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt, "Int", payloadInt, "Int", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt, "Int", payloadInt, "Int", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt, "Int", payloadConstInt, "ConstInt");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt, "Int", payloadConstInt, "ConstInt", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt, "Int", payloadConstInt, "ConstInt", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt, "Int", payloadConstInt, "ConstInt", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt, "Int", payloadConstInt, "ConstInt", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt, "Int", payloadConstInt, "ConstInt", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt, "Int", payloadUnsignedInt, "UnsignedInt");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt, "Int", payloadUnsignedInt, "UnsignedInt", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt, "Int", payloadUnsignedInt, "UnsignedInt", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt, "Int", payloadUnsignedInt, "UnsignedInt", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt, "Int", payloadUnsignedInt, "UnsignedInt", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventInt, "Int", payloadUnsignedInt, "UnsignedInt", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstInt, "ConstInt");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstInt, "ConstInt", payloadInt8_t, "Int8_t");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstInt, "ConstInt", payloadInt8_t, "Int8_t", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstInt, "ConstInt", payloadInt8_t, "Int8_t", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstInt, "ConstInt", payloadInt8_t, "Int8_t", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstInt, "ConstInt", payloadInt8_t, "Int8_t", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstInt, "ConstInt", payloadInt8_t, "Int8_t", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstInt, "ConstInt", payloadInt, "Int");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstInt, "ConstInt", payloadInt, "Int", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstInt, "ConstInt", payloadInt, "Int", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstInt, "ConstInt", payloadInt, "Int", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstInt, "ConstInt", payloadInt, "Int", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstInt, "ConstInt", payloadInt, "Int", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstInt, "ConstInt", payloadConstInt, "ConstInt");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstInt, "ConstInt", payloadConstInt, "ConstInt", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstInt, "ConstInt", payloadConstInt, "ConstInt", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstInt, "ConstInt", payloadConstInt, "ConstInt", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstInt, "ConstInt", payloadConstInt, "ConstInt", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstInt, "ConstInt", payloadConstInt, "ConstInt", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstInt, "ConstInt", payloadUnsignedInt, "UnsignedInt");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstInt, "ConstInt", payloadUnsignedInt, "UnsignedInt", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstInt, "ConstInt", payloadUnsignedInt, "UnsignedInt", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstInt, "ConstInt", payloadUnsignedInt, "UnsignedInt", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstInt, "ConstInt", payloadUnsignedInt, "UnsignedInt", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventConstInt, "ConstInt", payloadUnsignedInt, "UnsignedInt", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedInt, "UnsignedInt");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedInt, "UnsignedInt", payloadInt8_t, "Int8_t");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedInt, "UnsignedInt", payloadInt8_t, "Int8_t", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedInt, "UnsignedInt", payloadInt8_t, "Int8_t", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedInt, "UnsignedInt", payloadInt8_t, "Int8_t", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedInt, "UnsignedInt", payloadInt8_t, "Int8_t", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedInt, "UnsignedInt", payloadInt8_t, "Int8_t", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedInt, "UnsignedInt", payloadInt, "Int");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedInt, "UnsignedInt", payloadInt, "Int", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedInt, "UnsignedInt", payloadInt, "Int", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedInt, "UnsignedInt", payloadInt, "Int", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedInt, "UnsignedInt", payloadInt, "Int", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedInt, "UnsignedInt", payloadInt, "Int", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedInt, "UnsignedInt", payloadConstInt, "ConstInt");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedInt, "UnsignedInt", payloadConstInt, "ConstInt", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedInt, "UnsignedInt", payloadConstInt, "ConstInt", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedInt, "UnsignedInt", payloadConstInt, "ConstInt", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedInt, "UnsignedInt", payloadConstInt, "ConstInt", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedInt, "UnsignedInt", payloadConstInt, "ConstInt", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedInt, "UnsignedInt", payloadUnsignedInt, "UnsignedInt");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedInt, "UnsignedInt", payloadUnsignedInt, "UnsignedInt", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedInt, "UnsignedInt", payloadUnsignedInt, "UnsignedInt", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedInt, "UnsignedInt", payloadUnsignedInt, "UnsignedInt", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedInt, "UnsignedInt", payloadUnsignedInt, "UnsignedInt", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedInt, "UnsignedInt", payloadUnsignedInt, "UnsignedInt", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt8_t, "Int8_t");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt8_t, "Int8_t", payloadInt8_t, "Int8_t");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt8_t, "Int8_t", payloadInt8_t, "Int8_t", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt8_t, "Int8_t", payloadInt8_t, "Int8_t", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt8_t, "Int8_t", payloadInt8_t, "Int8_t", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt8_t, "Int8_t", payloadInt8_t, "Int8_t", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt8_t, "Int8_t", payloadInt8_t, "Int8_t", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt8_t, "Int8_t", payloadInt, "Int");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt8_t, "Int8_t", payloadInt, "Int", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt8_t, "Int8_t", payloadInt, "Int", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt8_t, "Int8_t", payloadInt, "Int", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt8_t, "Int8_t", payloadInt, "Int", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt8_t, "Int8_t", payloadInt, "Int", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt8_t, "Int8_t", payloadConstInt, "ConstInt");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt8_t, "Int8_t", payloadConstInt, "ConstInt", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt8_t, "Int8_t", payloadConstInt, "ConstInt", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt8_t, "Int8_t", payloadConstInt, "ConstInt", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt8_t, "Int8_t", payloadConstInt, "ConstInt", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt8_t, "Int8_t", payloadConstInt, "ConstInt", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt8_t, "Int8_t", payloadUnsignedInt, "UnsignedInt");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt8_t, "Int8_t", payloadUnsignedInt, "UnsignedInt", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt8_t, "Int8_t", payloadUnsignedInt, "UnsignedInt", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt8_t, "Int8_t", payloadUnsignedInt, "UnsignedInt", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt8_t, "Int8_t", payloadUnsignedInt, "UnsignedInt", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt8_t, "Int8_t", payloadUnsignedInt, "UnsignedInt", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt, "Int");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt, "Int", payloadInt8_t, "Int8_t");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt, "Int", payloadInt8_t, "Int8_t", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt, "Int", payloadInt8_t, "Int8_t", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt, "Int", payloadInt8_t, "Int8_t", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt, "Int", payloadInt8_t, "Int8_t", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt, "Int", payloadInt8_t, "Int8_t", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt, "Int", payloadInt, "Int");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt, "Int", payloadInt, "Int", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt, "Int", payloadInt, "Int", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt, "Int", payloadInt, "Int", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt, "Int", payloadInt, "Int", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt, "Int", payloadInt, "Int", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt, "Int", payloadConstInt, "ConstInt");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt, "Int", payloadConstInt, "ConstInt", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt, "Int", payloadConstInt, "ConstInt", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt, "Int", payloadConstInt, "ConstInt", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt, "Int", payloadConstInt, "ConstInt", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt, "Int", payloadConstInt, "ConstInt", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt, "Int", payloadUnsignedInt, "UnsignedInt");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt, "Int", payloadUnsignedInt, "UnsignedInt", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt, "Int", payloadUnsignedInt, "UnsignedInt", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt, "Int", payloadUnsignedInt, "UnsignedInt", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt, "Int", payloadUnsignedInt, "UnsignedInt", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventInt, "Int", payloadUnsignedInt, "UnsignedInt", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstInt, "ConstInt");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstInt, "ConstInt", payloadInt8_t, "Int8_t");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstInt, "ConstInt", payloadInt8_t, "Int8_t", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstInt, "ConstInt", payloadInt8_t, "Int8_t", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstInt, "ConstInt", payloadInt8_t, "Int8_t", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstInt, "ConstInt", payloadInt8_t, "Int8_t", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstInt, "ConstInt", payloadInt8_t, "Int8_t", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstInt, "ConstInt", payloadInt, "Int");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstInt, "ConstInt", payloadInt, "Int", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstInt, "ConstInt", payloadInt, "Int", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstInt, "ConstInt", payloadInt, "Int", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstInt, "ConstInt", payloadInt, "Int", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstInt, "ConstInt", payloadInt, "Int", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstInt, "ConstInt", payloadConstInt, "ConstInt");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstInt, "ConstInt", payloadConstInt, "ConstInt", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstInt, "ConstInt", payloadConstInt, "ConstInt", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstInt, "ConstInt", payloadConstInt, "ConstInt", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstInt, "ConstInt", payloadConstInt, "ConstInt", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstInt, "ConstInt", payloadConstInt, "ConstInt", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstInt, "ConstInt", payloadUnsignedInt, "UnsignedInt");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstInt, "ConstInt", payloadUnsignedInt, "UnsignedInt", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstInt, "ConstInt", payloadUnsignedInt, "UnsignedInt", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstInt, "ConstInt", payloadUnsignedInt, "UnsignedInt", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstInt, "ConstInt", payloadUnsignedInt, "UnsignedInt", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventConstInt, "ConstInt", payloadUnsignedInt, "UnsignedInt", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedInt, "UnsignedInt");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadInt8_t, "Int8_t");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadInt8_t, "Int8_t", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadInt8_t, "Int8_t", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadInt8_t, "Int8_t", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadInt8_t, "Int8_t", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadInt8_t, "Int8_t", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadInt, "Int");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadInt, "Int", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadInt, "Int", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadInt, "Int", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadInt, "Int", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadInt, "Int", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadConstInt, "ConstInt");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadConstInt, "ConstInt", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadConstInt, "ConstInt", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadConstInt, "ConstInt", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadConstInt, "ConstInt", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadConstInt, "ConstInt", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadUnsignedInt, "UnsignedInt");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadUnsignedInt, "UnsignedInt", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadUnsignedInt, "UnsignedInt", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadUnsignedInt, "UnsignedInt", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadUnsignedInt, "UnsignedInt", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadUnsignedInt, "UnsignedInt", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt8_t, "Int8_t");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt8_t, "Int8_t", payloadInt8_t, "Int8_t");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt8_t, "Int8_t", payloadInt8_t, "Int8_t", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt8_t, "Int8_t", payloadInt8_t, "Int8_t", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt8_t, "Int8_t", payloadInt8_t, "Int8_t", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt8_t, "Int8_t", payloadInt8_t, "Int8_t", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt8_t, "Int8_t", payloadInt8_t, "Int8_t", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt8_t, "Int8_t", payloadInt, "Int");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt8_t, "Int8_t", payloadInt, "Int", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt8_t, "Int8_t", payloadInt, "Int", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt8_t, "Int8_t", payloadInt, "Int", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt8_t, "Int8_t", payloadInt, "Int", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt8_t, "Int8_t", payloadInt, "Int", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt8_t, "Int8_t", payloadConstInt, "ConstInt");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt8_t, "Int8_t", payloadConstInt, "ConstInt", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt8_t, "Int8_t", payloadConstInt, "ConstInt", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt8_t, "Int8_t", payloadConstInt, "ConstInt", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt8_t, "Int8_t", payloadConstInt, "ConstInt", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt8_t, "Int8_t", payloadConstInt, "ConstInt", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt8_t, "Int8_t", payloadUnsignedInt, "UnsignedInt");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt8_t, "Int8_t", payloadUnsignedInt, "UnsignedInt", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt8_t, "Int8_t", payloadUnsignedInt, "UnsignedInt", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt8_t, "Int8_t", payloadUnsignedInt, "UnsignedInt", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt8_t, "Int8_t", payloadUnsignedInt, "UnsignedInt", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt8_t, "Int8_t", payloadUnsignedInt, "UnsignedInt", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt, "Int");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt, "Int", payloadInt8_t, "Int8_t");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt, "Int", payloadInt8_t, "Int8_t", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt, "Int", payloadInt8_t, "Int8_t", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt, "Int", payloadInt8_t, "Int8_t", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt, "Int", payloadInt8_t, "Int8_t", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt, "Int", payloadInt8_t, "Int8_t", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt, "Int", payloadInt, "Int");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt, "Int", payloadInt, "Int", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt, "Int", payloadInt, "Int", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt, "Int", payloadInt, "Int", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt, "Int", payloadInt, "Int", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt, "Int", payloadInt, "Int", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt, "Int", payloadConstInt, "ConstInt");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt, "Int", payloadConstInt, "ConstInt", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt, "Int", payloadConstInt, "ConstInt", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt, "Int", payloadConstInt, "ConstInt", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt, "Int", payloadConstInt, "ConstInt", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt, "Int", payloadConstInt, "ConstInt", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt, "Int", payloadUnsignedInt, "UnsignedInt");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt, "Int", payloadUnsignedInt, "UnsignedInt", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt, "Int", payloadUnsignedInt, "UnsignedInt", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt, "Int", payloadUnsignedInt, "UnsignedInt", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt, "Int", payloadUnsignedInt, "UnsignedInt", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventInt, "Int", payloadUnsignedInt, "UnsignedInt", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstInt, "ConstInt");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstInt, "ConstInt", payloadInt8_t, "Int8_t");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstInt, "ConstInt", payloadInt8_t, "Int8_t", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstInt, "ConstInt", payloadInt8_t, "Int8_t", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstInt, "ConstInt", payloadInt8_t, "Int8_t", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstInt, "ConstInt", payloadInt8_t, "Int8_t", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstInt, "ConstInt", payloadInt8_t, "Int8_t", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstInt, "ConstInt", payloadInt, "Int");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstInt, "ConstInt", payloadInt, "Int", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstInt, "ConstInt", payloadInt, "Int", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstInt, "ConstInt", payloadInt, "Int", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstInt, "ConstInt", payloadInt, "Int", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstInt, "ConstInt", payloadInt, "Int", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstInt, "ConstInt", payloadConstInt, "ConstInt");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstInt, "ConstInt", payloadConstInt, "ConstInt", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstInt, "ConstInt", payloadConstInt, "ConstInt", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstInt, "ConstInt", payloadConstInt, "ConstInt", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstInt, "ConstInt", payloadConstInt, "ConstInt", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstInt, "ConstInt", payloadConstInt, "ConstInt", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstInt, "ConstInt", payloadUnsignedInt, "UnsignedInt");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstInt, "ConstInt", payloadUnsignedInt, "UnsignedInt", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstInt, "ConstInt", payloadUnsignedInt, "UnsignedInt", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstInt, "ConstInt", payloadUnsignedInt, "UnsignedInt", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstInt, "ConstInt", payloadUnsignedInt, "UnsignedInt", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventConstInt, "ConstInt", payloadUnsignedInt, "UnsignedInt", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedInt, "UnsignedInt");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadInt8_t, "Int8_t");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadInt8_t, "Int8_t", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadInt8_t, "Int8_t", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadInt8_t, "Int8_t", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadInt8_t, "Int8_t", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadInt8_t, "Int8_t", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadInt, "Int");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadInt, "Int", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadInt, "Int", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadInt, "Int", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadInt, "Int", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadInt, "Int", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadConstInt, "ConstInt");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadConstInt, "ConstInt", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadConstInt, "ConstInt", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadConstInt, "ConstInt", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadConstInt, "ConstInt", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadConstInt, "ConstInt", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadUnsignedInt, "UnsignedInt");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadUnsignedInt, "UnsignedInt", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadUnsignedInt, "UnsignedInt", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadUnsignedInt, "UnsignedInt", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadUnsignedInt, "UnsignedInt", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedInt, "UnsignedInt", payloadUnsignedInt, "UnsignedInt", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
#elif TEST_BATCH == 2
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventLong, "Long");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventLong, "Long", payloadLong, "Long");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventLong, "Long", payloadLong, "Long", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventLong, "Long", payloadLong, "Long", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventLong, "Long", payloadLong, "Long", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventLong, "Long", payloadLong, "Long", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventLong, "Long", payloadLong, "Long", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventLong, "Long", payloadUnsignedLong, "UnsignedLong");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventLong, "Long", payloadUnsignedLong, "UnsignedLong", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventLong, "Long", payloadUnsignedLong, "UnsignedLong", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventLong, "Long", payloadUnsignedLong, "UnsignedLong", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventLong, "Long", payloadUnsignedLong, "UnsignedLong", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventLong, "Long", payloadUnsignedLong, "UnsignedLong", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventLong, "Long", payloadFloat, "Float");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventLong, "Long", payloadFloat, "Float", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventLong, "Long", payloadFloat, "Float", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventLong, "Long", payloadFloat, "Float", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventLong, "Long", payloadFloat, "Float", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventLong, "Long", payloadFloat, "Float", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventLong, "Long", payloadDouble, "Double");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventLong, "Long", payloadDouble, "Double", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventLong, "Long", payloadDouble, "Double", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventLong, "Long", payloadDouble, "Double", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventLong, "Long", payloadDouble, "Double", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventLong, "Long", payloadDouble, "Double", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedLong, "UnsignedLong");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedLong, "UnsignedLong", payloadLong, "Long");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedLong, "UnsignedLong", payloadLong, "Long", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedLong, "UnsignedLong", payloadLong, "Long", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedLong, "UnsignedLong", payloadLong, "Long", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedLong, "UnsignedLong", payloadLong, "Long", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedLong, "UnsignedLong", payloadLong, "Long", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedLong, "UnsignedLong", payloadUnsignedLong, "UnsignedLong");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedLong, "UnsignedLong", payloadUnsignedLong, "UnsignedLong", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedLong, "UnsignedLong", payloadUnsignedLong, "UnsignedLong", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedLong, "UnsignedLong", payloadUnsignedLong, "UnsignedLong", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedLong, "UnsignedLong", payloadUnsignedLong, "UnsignedLong", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedLong, "UnsignedLong", payloadUnsignedLong, "UnsignedLong", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedLong, "UnsignedLong", payloadFloat, "Float");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedLong, "UnsignedLong", payloadFloat, "Float", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedLong, "UnsignedLong", payloadFloat, "Float", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedLong, "UnsignedLong", payloadFloat, "Float", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedLong, "UnsignedLong", payloadFloat, "Float", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedLong, "UnsignedLong", payloadFloat, "Float", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedLong, "UnsignedLong", payloadDouble, "Double");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedLong, "UnsignedLong", payloadDouble, "Double", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedLong, "UnsignedLong", payloadDouble, "Double", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedLong, "UnsignedLong", payloadDouble, "Double", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedLong, "UnsignedLong", payloadDouble, "Double", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventUnsignedLong, "UnsignedLong", payloadDouble, "Double", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventFloat, "Float");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventFloat, "Float", payloadLong, "Long");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventFloat, "Float", payloadLong, "Long", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventFloat, "Float", payloadLong, "Long", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventFloat, "Float", payloadLong, "Long", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventFloat, "Float", payloadLong, "Long", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventFloat, "Float", payloadLong, "Long", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventFloat, "Float", payloadUnsignedLong, "UnsignedLong");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventFloat, "Float", payloadUnsignedLong, "UnsignedLong", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventFloat, "Float", payloadUnsignedLong, "UnsignedLong", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventFloat, "Float", payloadUnsignedLong, "UnsignedLong", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventFloat, "Float", payloadUnsignedLong, "UnsignedLong", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventFloat, "Float", payloadUnsignedLong, "UnsignedLong", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventFloat, "Float", payloadFloat, "Float");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventFloat, "Float", payloadFloat, "Float", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventFloat, "Float", payloadFloat, "Float", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventFloat, "Float", payloadFloat, "Float", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventFloat, "Float", payloadFloat, "Float", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventFloat, "Float", payloadFloat, "Float", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventFloat, "Float", payloadDouble, "Double");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventFloat, "Float", payloadDouble, "Double", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventFloat, "Float", payloadDouble, "Double", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventFloat, "Float", payloadDouble, "Double", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventFloat, "Float", payloadDouble, "Double", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventFloat, "Float", payloadDouble, "Double", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventDouble, "Double");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventDouble, "Double", payloadLong, "Long");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventDouble, "Double", payloadLong, "Long", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventDouble, "Double", payloadLong, "Long", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventDouble, "Double", payloadLong, "Long", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventDouble, "Double", payloadLong, "Long", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventDouble, "Double", payloadLong, "Long", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventDouble, "Double", payloadUnsignedLong, "UnsignedLong");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventDouble, "Double", payloadUnsignedLong, "UnsignedLong", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventDouble, "Double", payloadUnsignedLong, "UnsignedLong", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventDouble, "Double", payloadUnsignedLong, "UnsignedLong", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventDouble, "Double", payloadUnsignedLong, "UnsignedLong", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventDouble, "Double", payloadUnsignedLong, "UnsignedLong", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventDouble, "Double", payloadFloat, "Float");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventDouble, "Double", payloadFloat, "Float", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventDouble, "Double", payloadFloat, "Float", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventDouble, "Double", payloadFloat, "Float", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventDouble, "Double", payloadFloat, "Float", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventDouble, "Double", payloadFloat, "Float", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventDouble, "Double", payloadDouble, "Double");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventDouble, "Double", payloadDouble, "Double", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventDouble, "Double", payloadDouble, "Double", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventDouble, "Double", payloadDouble, "Double", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventDouble, "Double", payloadDouble, "Double", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventDouble, "Double", payloadDouble, "Double", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventLong, "Long");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventLong, "Long", payloadLong, "Long");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventLong, "Long", payloadLong, "Long", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventLong, "Long", payloadLong, "Long", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventLong, "Long", payloadLong, "Long", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventLong, "Long", payloadLong, "Long", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventLong, "Long", payloadLong, "Long", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventLong, "Long", payloadUnsignedLong, "UnsignedLong");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventLong, "Long", payloadUnsignedLong, "UnsignedLong", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventLong, "Long", payloadUnsignedLong, "UnsignedLong", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventLong, "Long", payloadUnsignedLong, "UnsignedLong", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventLong, "Long", payloadUnsignedLong, "UnsignedLong", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventLong, "Long", payloadUnsignedLong, "UnsignedLong", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventLong, "Long", payloadFloat, "Float");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventLong, "Long", payloadFloat, "Float", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventLong, "Long", payloadFloat, "Float", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventLong, "Long", payloadFloat, "Float", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventLong, "Long", payloadFloat, "Float", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventLong, "Long", payloadFloat, "Float", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventLong, "Long", payloadDouble, "Double");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventLong, "Long", payloadDouble, "Double", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventLong, "Long", payloadDouble, "Double", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventLong, "Long", payloadDouble, "Double", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventLong, "Long", payloadDouble, "Double", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventLong, "Long", payloadDouble, "Double", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedLong, "UnsignedLong");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadLong, "Long");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadLong, "Long", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadLong, "Long", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadLong, "Long", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadLong, "Long", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadLong, "Long", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadUnsignedLong, "UnsignedLong");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadUnsignedLong, "UnsignedLong", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadUnsignedLong, "UnsignedLong", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadUnsignedLong, "UnsignedLong", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadUnsignedLong, "UnsignedLong", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadUnsignedLong, "UnsignedLong", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadFloat, "Float");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadFloat, "Float", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadFloat, "Float", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadFloat, "Float", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadFloat, "Float", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadFloat, "Float", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadDouble, "Double");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadDouble, "Double", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadDouble, "Double", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadDouble, "Double", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadDouble, "Double", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadDouble, "Double", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventFloat, "Float");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventFloat, "Float", payloadLong, "Long");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventFloat, "Float", payloadLong, "Long", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventFloat, "Float", payloadLong, "Long", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventFloat, "Float", payloadLong, "Long", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventFloat, "Float", payloadLong, "Long", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventFloat, "Float", payloadLong, "Long", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventFloat, "Float", payloadUnsignedLong, "UnsignedLong");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventFloat, "Float", payloadUnsignedLong, "UnsignedLong", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventFloat, "Float", payloadUnsignedLong, "UnsignedLong", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventFloat, "Float", payloadUnsignedLong, "UnsignedLong", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventFloat, "Float", payloadUnsignedLong, "UnsignedLong", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventFloat, "Float", payloadUnsignedLong, "UnsignedLong", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventFloat, "Float", payloadFloat, "Float");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventFloat, "Float", payloadFloat, "Float", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventFloat, "Float", payloadFloat, "Float", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventFloat, "Float", payloadFloat, "Float", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventFloat, "Float", payloadFloat, "Float", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventFloat, "Float", payloadFloat, "Float", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventFloat, "Float", payloadDouble, "Double");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventFloat, "Float", payloadDouble, "Double", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventFloat, "Float", payloadDouble, "Double", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventFloat, "Float", payloadDouble, "Double", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventFloat, "Float", payloadDouble, "Double", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventFloat, "Float", payloadDouble, "Double", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventDouble, "Double");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventDouble, "Double", payloadLong, "Long");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventDouble, "Double", payloadLong, "Long", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventDouble, "Double", payloadLong, "Long", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventDouble, "Double", payloadLong, "Long", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventDouble, "Double", payloadLong, "Long", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventDouble, "Double", payloadLong, "Long", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventDouble, "Double", payloadUnsignedLong, "UnsignedLong");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventDouble, "Double", payloadUnsignedLong, "UnsignedLong", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventDouble, "Double", payloadUnsignedLong, "UnsignedLong", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventDouble, "Double", payloadUnsignedLong, "UnsignedLong", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventDouble, "Double", payloadUnsignedLong, "UnsignedLong", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventDouble, "Double", payloadUnsignedLong, "UnsignedLong", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventDouble, "Double", payloadFloat, "Float");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventDouble, "Double", payloadFloat, "Float", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventDouble, "Double", payloadFloat, "Float", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventDouble, "Double", payloadFloat, "Float", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventDouble, "Double", payloadFloat, "Float", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventDouble, "Double", payloadFloat, "Float", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventDouble, "Double", payloadDouble, "Double");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventDouble, "Double", payloadDouble, "Double", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventDouble, "Double", payloadDouble, "Double", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventDouble, "Double", payloadDouble, "Double", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventDouble, "Double", payloadDouble, "Double", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventDouble, "Double", payloadDouble, "Double", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventLong, "Long");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventLong, "Long", payloadLong, "Long");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventLong, "Long", payloadLong, "Long", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventLong, "Long", payloadLong, "Long", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventLong, "Long", payloadLong, "Long", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventLong, "Long", payloadLong, "Long", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventLong, "Long", payloadLong, "Long", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventLong, "Long", payloadUnsignedLong, "UnsignedLong");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventLong, "Long", payloadUnsignedLong, "UnsignedLong", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventLong, "Long", payloadUnsignedLong, "UnsignedLong", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventLong, "Long", payloadUnsignedLong, "UnsignedLong", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventLong, "Long", payloadUnsignedLong, "UnsignedLong", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventLong, "Long", payloadUnsignedLong, "UnsignedLong", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventLong, "Long", payloadFloat, "Float");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventLong, "Long", payloadFloat, "Float", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventLong, "Long", payloadFloat, "Float", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventLong, "Long", payloadFloat, "Float", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventLong, "Long", payloadFloat, "Float", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventLong, "Long", payloadFloat, "Float", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventLong, "Long", payloadDouble, "Double");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventLong, "Long", payloadDouble, "Double", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventLong, "Long", payloadDouble, "Double", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventLong, "Long", payloadDouble, "Double", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventLong, "Long", payloadDouble, "Double", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventLong, "Long", payloadDouble, "Double", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedLong, "UnsignedLong");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadLong, "Long");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadLong, "Long", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadLong, "Long", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadLong, "Long", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadLong, "Long", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadLong, "Long", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadUnsignedLong, "UnsignedLong");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadUnsignedLong, "UnsignedLong", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadUnsignedLong, "UnsignedLong", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadUnsignedLong, "UnsignedLong", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadUnsignedLong, "UnsignedLong", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadUnsignedLong, "UnsignedLong", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadFloat, "Float");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadFloat, "Float", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadFloat, "Float", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadFloat, "Float", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadFloat, "Float", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadFloat, "Float", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadDouble, "Double");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadDouble, "Double", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadDouble, "Double", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadDouble, "Double", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadDouble, "Double", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventUnsignedLong, "UnsignedLong", payloadDouble, "Double", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventFloat, "Float");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventFloat, "Float", payloadLong, "Long");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventFloat, "Float", payloadLong, "Long", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventFloat, "Float", payloadLong, "Long", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventFloat, "Float", payloadLong, "Long", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventFloat, "Float", payloadLong, "Long", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventFloat, "Float", payloadLong, "Long", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventFloat, "Float", payloadUnsignedLong, "UnsignedLong");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventFloat, "Float", payloadUnsignedLong, "UnsignedLong", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventFloat, "Float", payloadUnsignedLong, "UnsignedLong", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventFloat, "Float", payloadUnsignedLong, "UnsignedLong", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventFloat, "Float", payloadUnsignedLong, "UnsignedLong", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventFloat, "Float", payloadUnsignedLong, "UnsignedLong", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventFloat, "Float", payloadFloat, "Float");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventFloat, "Float", payloadFloat, "Float", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventFloat, "Float", payloadFloat, "Float", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventFloat, "Float", payloadFloat, "Float", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventFloat, "Float", payloadFloat, "Float", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventFloat, "Float", payloadFloat, "Float", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventFloat, "Float", payloadDouble, "Double");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventFloat, "Float", payloadDouble, "Double", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventFloat, "Float", payloadDouble, "Double", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventFloat, "Float", payloadDouble, "Double", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventFloat, "Float", payloadDouble, "Double", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventFloat, "Float", payloadDouble, "Double", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventDouble, "Double");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventDouble, "Double", payloadLong, "Long");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventDouble, "Double", payloadLong, "Long", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventDouble, "Double", payloadLong, "Long", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventDouble, "Double", payloadLong, "Long", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventDouble, "Double", payloadLong, "Long", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventDouble, "Double", payloadLong, "Long", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventDouble, "Double", payloadUnsignedLong, "UnsignedLong");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventDouble, "Double", payloadUnsignedLong, "UnsignedLong", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventDouble, "Double", payloadUnsignedLong, "UnsignedLong", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventDouble, "Double", payloadUnsignedLong, "UnsignedLong", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventDouble, "Double", payloadUnsignedLong, "UnsignedLong", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventDouble, "Double", payloadUnsignedLong, "UnsignedLong", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventDouble, "Double", payloadFloat, "Float");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventDouble, "Double", payloadFloat, "Float", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventDouble, "Double", payloadFloat, "Float", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventDouble, "Double", payloadFloat, "Float", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventDouble, "Double", payloadFloat, "Float", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventDouble, "Double", payloadFloat, "Float", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventDouble, "Double", payloadDouble, "Double");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventDouble, "Double", payloadDouble, "Double", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventDouble, "Double", payloadDouble, "Double", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventDouble, "Double", payloadDouble, "Double", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventDouble, "Double", payloadDouble, "Double", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventDouble, "Double", payloadDouble, "Double", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
#elif TEST_BATCH == 3
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventIPAddress, "IPAddress");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventIPAddress, "IPAddress", payloadIPAddress, "IPAddress");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventIPAddress, "IPAddress", payloadIPAddress, "IPAddress", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventIPAddress, "IPAddress", payloadIPAddress, "IPAddress", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventIPAddress, "IPAddress", payloadIPAddress, "IPAddress", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventIPAddress, "IPAddress", payloadIPAddress, "IPAddress", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventIPAddress, "IPAddress", payloadIPAddress, "IPAddress", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventIPAddress, "IPAddress", payloadString, "String");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventIPAddress, "IPAddress", payloadString, "String", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventIPAddress, "IPAddress", payloadString, "String", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventIPAddress, "IPAddress", payloadString, "String", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventIPAddress, "IPAddress", payloadString, "String", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventIPAddress, "IPAddress", payloadString, "String", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventIPAddress, "IPAddress", payload_STRING_LITERAL, "_STRING_LITERAL");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventIPAddress, "IPAddress", payload_STRING_LITERAL, "_STRING_LITERAL", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventIPAddress, "IPAddress", payload_STRING_LITERAL, "_STRING_LITERAL", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventIPAddress, "IPAddress", payload_STRING_LITERAL, "_STRING_LITERAL", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventIPAddress, "IPAddress", payload_STRING_LITERAL, "_STRING_LITERAL", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventIPAddress, "IPAddress", payload_STRING_LITERAL, "_STRING_LITERAL", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventIPAddress, "IPAddress", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventIPAddress, "IPAddress", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventIPAddress, "IPAddress", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventIPAddress, "IPAddress", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventIPAddress, "IPAddress", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventIPAddress, "IPAddress", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventString, "String");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventString, "String", payloadIPAddress, "IPAddress");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventString, "String", payloadIPAddress, "IPAddress", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventString, "String", payloadIPAddress, "IPAddress", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventString, "String", payloadIPAddress, "IPAddress", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventString, "String", payloadIPAddress, "IPAddress", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventString, "String", payloadIPAddress, "IPAddress", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventString, "String", payloadString, "String");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventString, "String", payloadString, "String", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventString, "String", payloadString, "String", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventString, "String", payloadString, "String", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventString, "String", payloadString, "String", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventString, "String", payloadString, "String", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventString, "String", payload_STRING_LITERAL, "_STRING_LITERAL");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventString, "String", payload_STRING_LITERAL, "_STRING_LITERAL", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventString, "String", payload_STRING_LITERAL, "_STRING_LITERAL", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventString, "String", payload_STRING_LITERAL, "_STRING_LITERAL", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventString, "String", payload_STRING_LITERAL, "_STRING_LITERAL", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventString, "String", payload_STRING_LITERAL, "_STRING_LITERAL", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventString, "String", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventString, "String", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventString, "String", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventString, "String", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventString, "String", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, eventString, "String", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payloadIPAddress, "IPAddress");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payloadIPAddress, "IPAddress", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payloadIPAddress, "IPAddress", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payloadIPAddress, "IPAddress", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payloadIPAddress, "IPAddress", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payloadIPAddress, "IPAddress", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payloadString, "String");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payloadString, "String", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payloadString, "String", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payloadString, "String", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payloadString, "String", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payloadString, "String", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payload_STRING_LITERAL, "_STRING_LITERAL");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payload_STRING_LITERAL, "_STRING_LITERAL", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payload_STRING_LITERAL, "_STRING_LITERAL", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payload_STRING_LITERAL, "_STRING_LITERAL", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payload_STRING_LITERAL, "_STRING_LITERAL", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payload_STRING_LITERAL, "_STRING_LITERAL", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payloadIPAddress, "IPAddress");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payloadIPAddress, "IPAddress", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payloadIPAddress, "IPAddress", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payloadIPAddress, "IPAddress", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payloadIPAddress, "IPAddress", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payloadIPAddress, "IPAddress", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payloadString, "String");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payloadString, "String", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payloadString, "String", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payloadString, "String", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payloadString, "String", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payloadString, "String", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payload_STRING_LITERAL, "_STRING_LITERAL");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payload_STRING_LITERAL, "_STRING_LITERAL", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payload_STRING_LITERAL, "_STRING_LITERAL", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payload_STRING_LITERAL, "_STRING_LITERAL", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payload_STRING_LITERAL, "_STRING_LITERAL", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payload_STRING_LITERAL, "_STRING_LITERAL", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", passwordCharArray, "CharArray");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetIPAddress, "IPAddress", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventIPAddress, "IPAddress");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventIPAddress, "IPAddress", payloadIPAddress, "IPAddress");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventIPAddress, "IPAddress", payloadIPAddress, "IPAddress", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventIPAddress, "IPAddress", payloadIPAddress, "IPAddress", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventIPAddress, "IPAddress", payloadIPAddress, "IPAddress", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventIPAddress, "IPAddress", payloadIPAddress, "IPAddress", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventIPAddress, "IPAddress", payloadIPAddress, "IPAddress", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventIPAddress, "IPAddress", payloadString, "String");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventIPAddress, "IPAddress", payloadString, "String", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventIPAddress, "IPAddress", payloadString, "String", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventIPAddress, "IPAddress", payloadString, "String", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventIPAddress, "IPAddress", payloadString, "String", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventIPAddress, "IPAddress", payloadString, "String", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventIPAddress, "IPAddress", payload_STRING_LITERAL, "_STRING_LITERAL");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventIPAddress, "IPAddress", payload_STRING_LITERAL, "_STRING_LITERAL", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventIPAddress, "IPAddress", payload_STRING_LITERAL, "_STRING_LITERAL", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventIPAddress, "IPAddress", payload_STRING_LITERAL, "_STRING_LITERAL", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventIPAddress, "IPAddress", payload_STRING_LITERAL, "_STRING_LITERAL", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventIPAddress, "IPAddress", payload_STRING_LITERAL, "_STRING_LITERAL", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventIPAddress, "IPAddress", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventIPAddress, "IPAddress", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventIPAddress, "IPAddress", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventIPAddress, "IPAddress", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventIPAddress, "IPAddress", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventIPAddress, "IPAddress", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventString, "String");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventString, "String", payloadIPAddress, "IPAddress");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventString, "String", payloadIPAddress, "IPAddress", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventString, "String", payloadIPAddress, "IPAddress", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventString, "String", payloadIPAddress, "IPAddress", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventString, "String", payloadIPAddress, "IPAddress", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventString, "String", payloadIPAddress, "IPAddress", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventString, "String", payloadString, "String");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventString, "String", payloadString, "String", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventString, "String", payloadString, "String", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventString, "String", payloadString, "String", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventString, "String", payloadString, "String", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventString, "String", payloadString, "String", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventString, "String", payload_STRING_LITERAL, "_STRING_LITERAL");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventString, "String", payload_STRING_LITERAL, "_STRING_LITERAL", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventString, "String", payload_STRING_LITERAL, "_STRING_LITERAL", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventString, "String", payload_STRING_LITERAL, "_STRING_LITERAL", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventString, "String", payload_STRING_LITERAL, "_STRING_LITERAL", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventString, "String", payload_STRING_LITERAL, "_STRING_LITERAL", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventString, "String", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventString, "String", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventString, "String", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventString, "String", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventString, "String", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, eventString, "String", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payloadIPAddress, "IPAddress");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payloadIPAddress, "IPAddress", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payloadIPAddress, "IPAddress", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payloadIPAddress, "IPAddress", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payloadIPAddress, "IPAddress", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payloadIPAddress, "IPAddress", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payloadString, "String");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payloadString, "String", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payloadString, "String", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payloadString, "String", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payloadString, "String", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payloadString, "String", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payload_STRING_LITERAL, "_STRING_LITERAL");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payload_STRING_LITERAL, "_STRING_LITERAL", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payload_STRING_LITERAL, "_STRING_LITERAL", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payload_STRING_LITERAL, "_STRING_LITERAL", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payload_STRING_LITERAL, "_STRING_LITERAL", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payload_STRING_LITERAL, "_STRING_LITERAL", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payloadIPAddress, "IPAddress");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payloadIPAddress, "IPAddress", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payloadIPAddress, "IPAddress", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payloadIPAddress, "IPAddress", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payloadIPAddress, "IPAddress", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payloadIPAddress, "IPAddress", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payloadString, "String");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payloadString, "String", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payloadString, "String", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payloadString, "String", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payloadString, "String", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payloadString, "String", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payload_STRING_LITERAL, "_STRING_LITERAL");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payload_STRING_LITERAL, "_STRING_LITERAL", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payload_STRING_LITERAL, "_STRING_LITERAL", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payload_STRING_LITERAL, "_STRING_LITERAL", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payload_STRING_LITERAL, "_STRING_LITERAL", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payload_STRING_LITERAL, "_STRING_LITERAL", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", passwordCharArray, "CharArray");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetByteArray, "ByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventIPAddress, "IPAddress");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventIPAddress, "IPAddress", payloadIPAddress, "IPAddress");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventIPAddress, "IPAddress", payloadIPAddress, "IPAddress", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventIPAddress, "IPAddress", payloadIPAddress, "IPAddress", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventIPAddress, "IPAddress", payloadIPAddress, "IPAddress", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventIPAddress, "IPAddress", payloadIPAddress, "IPAddress", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventIPAddress, "IPAddress", payloadIPAddress, "IPAddress", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventIPAddress, "IPAddress", payloadString, "String");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventIPAddress, "IPAddress", payloadString, "String", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventIPAddress, "IPAddress", payloadString, "String", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventIPAddress, "IPAddress", payloadString, "String", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventIPAddress, "IPAddress", payloadString, "String", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventIPAddress, "IPAddress", payloadString, "String", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventIPAddress, "IPAddress", payload_STRING_LITERAL, "_STRING_LITERAL");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventIPAddress, "IPAddress", payload_STRING_LITERAL, "_STRING_LITERAL", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventIPAddress, "IPAddress", payload_STRING_LITERAL, "_STRING_LITERAL", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventIPAddress, "IPAddress", payload_STRING_LITERAL, "_STRING_LITERAL", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventIPAddress, "IPAddress", payload_STRING_LITERAL, "_STRING_LITERAL", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventIPAddress, "IPAddress", payload_STRING_LITERAL, "_STRING_LITERAL", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventIPAddress, "IPAddress", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventIPAddress, "IPAddress", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventIPAddress, "IPAddress", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventIPAddress, "IPAddress", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventIPAddress, "IPAddress", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventIPAddress, "IPAddress", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventString, "String");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventString, "String", payloadIPAddress, "IPAddress");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventString, "String", payloadIPAddress, "IPAddress", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventString, "String", payloadIPAddress, "IPAddress", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventString, "String", payloadIPAddress, "IPAddress", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventString, "String", payloadIPAddress, "IPAddress", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventString, "String", payloadIPAddress, "IPAddress", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventString, "String", payloadString, "String");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventString, "String", payloadString, "String", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventString, "String", payloadString, "String", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventString, "String", payloadString, "String", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventString, "String", payloadString, "String", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventString, "String", payloadString, "String", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventString, "String", payload_STRING_LITERAL, "_STRING_LITERAL");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventString, "String", payload_STRING_LITERAL, "_STRING_LITERAL", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventString, "String", payload_STRING_LITERAL, "_STRING_LITERAL", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventString, "String", payload_STRING_LITERAL, "_STRING_LITERAL", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventString, "String", payload_STRING_LITERAL, "_STRING_LITERAL", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventString, "String", payload_STRING_LITERAL, "_STRING_LITERAL", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventString, "String", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventString, "String", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventString, "String", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventString, "String", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventString, "String", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, eventString, "String", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payloadIPAddress, "IPAddress");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payloadIPAddress, "IPAddress", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payloadIPAddress, "IPAddress", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payloadIPAddress, "IPAddress", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payloadIPAddress, "IPAddress", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payloadIPAddress, "IPAddress", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payloadString, "String");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payloadString, "String", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payloadString, "String", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payloadString, "String", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payloadString, "String", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payloadString, "String", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payload_STRING_LITERAL, "_STRING_LITERAL");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payload_STRING_LITERAL, "_STRING_LITERAL", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payload_STRING_LITERAL, "_STRING_LITERAL", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payload_STRING_LITERAL, "_STRING_LITERAL", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payload_STRING_LITERAL, "_STRING_LITERAL", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payload_STRING_LITERAL, "_STRING_LITERAL", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_STRING_LITERAL, "_STRING_LITERAL", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payloadIPAddress, "IPAddress");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payloadIPAddress, "IPAddress", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payloadIPAddress, "IPAddress", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payloadIPAddress, "IPAddress", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payloadIPAddress, "IPAddress", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payloadIPAddress, "IPAddress", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payloadString, "String");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payloadString, "String", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payloadString, "String", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payloadString, "String", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payloadString, "String", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payloadString, "String", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payload_STRING_LITERAL, "_STRING_LITERAL");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payload_STRING_LITERAL, "_STRING_LITERAL", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payload_STRING_LITERAL, "_STRING_LITERAL", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payload_STRING_LITERAL, "_STRING_LITERAL", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payload_STRING_LITERAL, "_STRING_LITERAL", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payload_STRING_LITERAL, "_STRING_LITERAL", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
#ifndef ETHEREVENT_NO_AUTHENTICATION
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", passwordConstCharArray, "ConstCharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", passwordCharArray, "CharArray");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", password_STRING_LITERAL, "_STRING_LITERAL");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", password_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER");
  test(ethernetClient, targetConstByteArray, "ConstByteArray", sendPort, event_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", payload_FLASHSTRINGHELPER, "_FLASHSTRINGHELPER", passwordString, "String");
#endif //ETHEREVENT_NO_AUTHENTICATION
#endif //TEST_BATCH == 0
}
