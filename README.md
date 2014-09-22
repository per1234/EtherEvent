EtherEvent
==========

Arduino library for easy to use password authenticated network communication between Arduinos and EventGhost Network Event Sender/Receiver plugin, EventGhost TCPEvents plugin, Girder, and NetRemote

This is an alpha release. It is not thoroughly tested and has not been tested at all with UIPEthernet, Girder, or NetRemote. There is a lot of room for improvement so if you have any issues, bugs, improvements, feature requests feel free to make pull requests or issue reports. Thanks!

- Requires the arduinoMD5 library by Vasilis Georgitzikis: http://github.com/tzikis/ArduinoMD5
- Requires the Entropy library: https://sites.google.com/site/astudyofentropy/file-cabinet
- UIPEthernet library required for ENC28J60 ethernet chip: http://github.com/ntruchsess/arduino_uip
- EventGhost is a free open source automation tool for Windows http://eventghost.com
- TCP Events EventGhost plugin by miljbee: http://www.eventghost.org/forum/viewtopic.php?p=16803 - Improved network event sender/receiver allows sending events to multiple IP addresses

Receive Port: the port to receive events on is initially set to 1024 it can be changed in EtherEvent.cpp by modifying the value of receivePort

#### Usage:

`EtherEvent etherEvent` - Create an instance of the EtherEvent class called etherEvent. You can use any name you like in place of etherEvent.
- Parameters: none
- Returns: none

`etherEvent.etherEventStart(mac,IP)` - Initialize the network
- Parameter: mac - MAC address, if your device has the address printed on it use that or just pick any address that is unique on your network.
  - Type: byte(array)
- Parameter: IP - the IP Address of the arduino. You can use any IP address on your network that is not being used.
  - Type: IPAddress

`etherEvent.availableEvent()` - Returns the number of chars of event including null terminator available to read.
- Parameters: none
- Returns: Number of chars in the event including the null terminator at the end of the string.
  - Return Type: byte

`etherEvent.availablePayload()` - Returns the number of chars of payload including null terminator available to read
- Parameters: none
- Returns: Number of chars in the payload including the null terminator at the end of the string.
  - Type: byte

`etherEvent.readEvent()` - Returns the next char of the most recently received event
- Parameters: none
- Returns: next char of the event
  - Type: char

`etherEvent.readPayload()` - Returns the next char of the most recently received payload
- Parameters: none
- Returns: next char of the payload
  - Type: char      

`etherEvent.flushReceiver()` - clear any buffered event and payload data so a new event can be received
- Parameters:none
- Returns:none

`etherEvent.sendEvent(IPAddress sendIP, unsigned int sendPort, char sendEvent[],char sendPayload[])` - Send an event and payload
- Parameter: sendIP: IP address to send the event to
  - Type: IPAddress
- Parameter: sendPort: port to send the event to
  - Type: unsigned int
- Parameter: sendEvent: string to send as the event(char array).
  - Type: char
- Parameter: sendPayload: payload to send with the event(char array). If you don't want a payload then just use "" for this parameter
  - Type: char
- Returns: 1 for success, 0 for failure
  - Type: Byte

`etherEvent.senderIP()` - Returns the IP address of the sender of the most recent event. Must use the modified Ethernet library and enable the function in EtherEvent.cpp the line that starts with //#define REMOTEIP change to #define REMOTEIP or this will return only 0.0.0.0. Instructions for the ethernet library modification here: http://forum.arduino.cc/index.php?/topic,82416.0.html
- Parameters:none
- Returns: IP address of the sender
  - Type: IPAddress


#### Process:
EventGhost/Girder use APOP style authentication for TCP communication without sending passwords in plaintext. This library allows the arduino to use this previously established authentication system.
- sender: connect to receiver
- receiver: waits for "quintessence\n"
- sender: send "quintessence\n" and wait for cookie
- receiver: send a cookie(EventGhost uses the sock, EtherEvent uses a random number) to the sender and wait for response
- sender: the password is appended to the cookie and a new md5 digest calculated and sent back to the reciever and waits for "accept"
- receiver: calculates the proper md5 value and compares it to the one from the sender, if it is correct then it sends back "accept"
- sender: send "payload "{payload string}, event, and "close" to the receiver
- receiver: handle message and close the connection to the sender
