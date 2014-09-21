EtherEvent
==========

Arduino library for simple password authenticated network communication between Arduinos and EventGhost Network Event Sender/Receiver plugin, EventGhost TCP Events plugin, Girder, or NetRemote.

This is an alpha release of this library. It is not thoroughly tested and has not been tested at all with UIPEthernet, Girder, or NetRemote. There is a lot of room for improvement so if you have any issues, bugs, improvements, feature requests feel free to make pull requests or issue reports. Thanks!

Requires the arduinoMD5 library by Vasilis Georgitzikis: http://github.com/tzikis/ArduinoMD5
UIPEthernet library required for ENC28J60 ethernet chip: http://github.com/ntruchsess/arduino_uip
EventGhost is a free open source automation tool for Windows http://eventghost.com
TCP Events EventGhost plugin by miljbee - improved network event sender/receiver: http://www.eventghost.org/forum/viewtopic.php?p=16803 - allows sending events to multiple IP addresses

Receive Port: the port to receive events on is initially set to 1024 it can be changed in EtherEvent.cpp by modifying the value of receivePort

Usage:

EtherEvent etherEvent() - Declare the EtherEvent class. You can use any name you like in place of etherEvent.
Parameters: none
Returns: none

etherEvent.etherEventStart(mac,IP) - initialize the network
Parameter: mac - MAC address, if your device has the address printed on it use that or just pick any address that is unique on your network.
Type: byte(array)
Parameter: IP - the IP Address of the arduino. You can use any IP address on your network that is not being used.
Type: IPAddress

etherEvent.availableEvent() - parameters:none, returns: number of chars of event including null terminator available to read.
Parameters: none
Returns: Number of chars in the event including the null terminator at the end of the string.
Return Type: byte

etherEvent.availablePayload() -  parameters:none, returns: number of chars of payload including null terminator available to read
Parameters: none
Returns: Number of chars in the payload including the null terminator at the end of the string.
Return Type: byte

etherEvent.readEvent()
Parameters: none
Returns: next char of the event
Return Type: char

etherEvent.readPayload()  - parameters: none, returns: next char of the payload
Parameters: none
Returns: next char of the payload
Return Type: char      

etherEvent.flushReceiver()
Parameters:none
Returns:none

etherEvent.sendEvent(IPAddress sendIP, unsigned int sendPort, char sendEvent[],char sendPayload[]) - Send an event and payload
Parameter: sendIP: IP address to send the event to
Type: IPAddress
Parameter: sendPort: port to send the event to
Type: unsigned int
Parameter: sendEvent: string to send as the event(char array).
Type: char
Parameter: sendPayload: payload to send with the event(char array). If you don't want a payload then just use "" for this parameter
Type: char
Returns: 1 for success, 0 for failure
Type: Byte

etherEvent.senderIP() - Returns the IP address of the sender of the most recent event. Must use the modified Ethernet library and enable the function in EtherEvent.cpp the line that starts with //#define REMOTEIP change to #define REMOTEIP or this will return only 0.0.0.0. Instructions for the ethernet library modification here: http://forum.arduino.cc/index.php?/topic,82416.0.html
Parameters:none
Returns: IP address of the sender
Return Type: IPAddress
