EtherEvent
==========

Arduino library for easy to use password authenticated network communication between Arduinos and other devices running EventGhost, Girder, or any other program compatible with the EventGhost Network Event Sender and Receiver plugins.
The current focus of EtherEvent is to allow network communication at the previously established level of security(MD5 password encryption). This is not very secure and should not be used for critical applications without a thorough analysis of possible attacks.

This is an alpha release. It is not thoroughly tested and has not been tested at all with UIPEthernet, Girder, NetRemote, and terRemote. Feel free to make pull requests or issue reports. Thanks!

#### Required Libraries
- ArduinoMD5 http://github.com/mrparp/ArduinoMD5

#### Compatible Software
- Free
  - Tested to work with this library:
    - EventGhost: http://eventghost.com -  free open source automation tool for Windows
    - TCP Events EventGhost plugin: http://eventghost.org/forum/viewtopic.php?p=16803 - Improved network event sender/receiver allows sending events to multiple IP addresses
  - Untested:
    - eventghost-android: http://github.com/timhoeck/eventghost-android - Android network event app
    - EventGhost automation with LabVIEW: http://decibel.ni.com/content/docs/DOC-13135 - LabVIEW network event sender and receiver VI
    - ProntoScript Library: http://remotecentral.com/cgi-bin/mboard/prontopro/thread.cgi?3646 - Philips Pronto Home Control Panel communication
    - Android / Event Ghost Communication Suite: http://ip-symcon.de/forum/threads/19614-Android-Eventghost-Communication-Suite - IP-Symcon(pay software) automation system communication
    - EventGhost + zVirtualScenes Integration: http://stevecross.org/wiki/doku.php?id=eventghost_zvirtualscenes_integration - communication with zVirtualScenes free open-source home automation tool for Windows, Android, iOS, Blackberry and the Web
    - RemoteGhost: http://windowsphone.com/en-us/store/app/remoteghost/15e3196b-c62c-4bb3-9ca8-2d7d1f0d2f50 http://forum.xda-developers.com/showthread.php?t=2076716 - Windows phone network event app
    - EGRemote Lite: http://play.google.com/store/apps/details?id=eu.rml.lab.egremote_lite - Android network event app
    - MoviePoster: http://movieposterapp.com/ - 
- Pay
  - Untested:
    - Girder - Automation software
    - NetRemote - Automation software
    - terRemote - Android network event app
    - RemoteGhostPro - Windows phone network event app
    - EGRemote  - Android network event app

#### Related Programs
- Entropy truly random numbers library: http://sites.google.com/site/astudyofentropy/file-cabinet
- EtherEventQueue outgoing event queue library: http://github.com/per1234/EtherEventQueue
- UIPEthernet ENC28J60 ethernet chip library: http://github.com/ntruchsess/arduino_uip

#### Installation
- Make sure you have the current version of EtherEvent: http://github.com/per1234/EtherEvent
- 32k is the minimum recommended flash memory capacity of the MCU
- Download EtherEvent - Download ZIP button(or Clone in Desktop if you have GitHub Desktop installed)
- Extract the EtherEvent-master folder from the downloaded zip file
- Rename the folder EtherEvent
- Move the folder to your arduino sketchbook\libraries folder
- Repeat this process with the other required libraries
- If you want to use the senderIP() function then you must modify the arduino Ethernet library using these instructions: http://forum.arduino.cc/index.php?topic=82416.0 and set the library configuration parameter as explained below.
- EtherEvent library configuration parameters(EtherEvent.cpp) - there are a few flags that can be set in the library code to enable extra features.
  - Entropy library - uncomment the line  //#include "Entropy.h"
  - Debug - set #define DEBUG 1 to get debug output in the serial monitor, this will slow down communication.
  - senderIP() function enable - if you have the modified Arduino Ethernet library then you can enable use of the EtherEvent senderIP() function via the `SENDERIP_ENABLE` flag
  - Truly random cookie - A higher level of security can be achieved at the cost of slower receipt of events via availableEvent() by enabling the `RANDOM_COOKIE` flag  
- Restart the Arduino IDE
- File>Examples>etherEventExample
- Set the device IP address, this can be any available IP address on the network. DHCP not currently implemented.
- Set the device MAC address. This can be any address not already used on the network
- Set the EtherEvent password. The password must be the same on all connected devices.
- Upload to device
- Repeat with other connected devices. The serial monitor will show details of the test communications.

#### Usage
`EtherEvent.begin(password)` - initialize EtherEvent and set the authentication password.
- Parameters: password
  - Type: const char
- Returns: none

`EtherEvent.availableEvent(ethernetServer)` - Returns the number of chars of event including null terminator available to read. readEvent() or flushReceiver() must be called before the next event can be received.
- Parameters: ethernetServer - the EthernetServer object created in the Ethernet setup of the user's sketch
  - Type: EthernetServer
- Returns: Number of chars in the event including the null terminator at the end of the string.
  - Type: byte

`EtherEvent.availablePayload()` - Returns the number of chars of payload including null terminator available to read. availableEvent() must be called first.
- Parameters: none
- Returns: Number of chars in the payload including the null terminator at the end of the string.
  - Type: byte

`EtherEvent.readEvent(char eventBuffer[])` - Puts the event in the passed array. availableEvent() must be called first.
- Parameter: eventBuffer - size a char array according to the result of availableEvent () and pass it to the readEvent  function. After that it will contain the event.
  - Type: char
- Returns: none

`EtherEvent.readPayload(char payloadBuffer[])` - Puts the payload string in the passed array. availableEvent() must be called first.
- Parameter: payloadBuffer - size a char array according to the result of availablePayload () and pass it to the readPayload  function. After that it will contain the payload.
  - Type: char
- Returns: none   

`EtherEvent.senderIP()` - Returns the IP address of the sender of the most recent event. Must use the modified Ethernet library and enable the function in EtherEvent.cpp the line that starts with  //#define REMOTEIP change to #define REMOTEIP or this will return only 0.0.0.0. Instructions for the ethernet library modification here: http://forum.arduino.cc/index.php?topic=82416.0
- Parameters:none
- Returns: IP address of the sender
  - Type: IPAddress
  
`EtherEvent.flushReceiver()` - clear any buffered event and payload data so a new event can be received
- Parameters:none
- Returns:none

`EtherEvent.sendEvent(ethenetClient, sendIP, sendPort, sendEvent[], sendPayload[])` - Send an event and payload
- Parameters: ethernetClient - the EthernetClient object created in the Ethernet setup of the user's sketch
  - Type: EthernetClient
- Parameter: sendIP: IP address to send the event to
  - Type: IPAddress
- Parameter: sendPort: port to send the event to
  - Type: unsigned int
- Parameter: sendEvent: string to send as the event(char array).
  - Type: const char
- Parameter: sendPayload: payload to send with the event(char array). If you don't want a payload then just use "" for this parameter
  - Type: const char
- Returns: 1 for success, 0 for failure
  - Type: boolean

EtherEvent.setTimeout(timeout, listenTimeout)
- Parameter: timeout - the max time to wait for ethenet communication in milliseconds
  - Type: unsigned int
- Parameter: listenTimeout - the time to wait for the full message to come through in microseconds
  -Type: unsigned int


#### Authentication Process
EventGhost/Girder use APOP style authentication for TCP communication without sending passwords in plaintext. The EtherEvent library allows the arduino to use this previously established authentication system. Cryptographic use of MD5 is now considered insecure.
- sender: connect to receiver
- receiver: waits for "quintessence\n\r"
- sender: send "quintessence\n\r" and wait for cookie
- receiver: send a cookie(EventGhost uses the sock, EtherEvent uses a random number) to the sender and wait for response
- sender: the password is appended to the cookie and a new md5 digest calculated and sent back to the reciever and waits for "accept"
- receiver: calculates the proper MD5 value and compares it to the one from the sender, if it is correct then it sends back "accept"
- sender: send "payload "{payload string}, event, and "close" to the receiver
- receiver: handle message and close the connection to the sender
