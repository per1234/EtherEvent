EtherEvent
==========

Easy to use Arduino library for password authenticated network communication via Ethernet between Arduinos and other devices running EventGhost, Girder, or any other program compatible with the EventGhost Network Event Sender and Receiver plugins.
The current focus of EtherEvent is to allow network communication at the level of security(MD5 password encryption) previously established by EventGhost. This is not very secure and should not be used for critical applications without a thorough analysis of possible attacks.

This is a beta release. I have been successfully using it with EventGhost in my home automation system constantly for the last 4 months but it has not been tested at all with UIPEthernet, Girder, NetRemote, and terRemote. Feel free to make pull requests or issue reports. Thanks!


#### Required Libraries
- ArduinoMD5 http://github.com/tzikis/ArduinoMD5


#### Compatible Software
- Free
  - Tested to work with this library:
    - EventGhost: http://eventghost.com -  free open source automation tool for Windows
    - TCP Events EventGhost plugin: http://eventghost.org/forum/viewtopic.php?p=16803 download link: http://docs.google.com/uc?id=0B3RTucUBY2bwVW5MQWdvRU90eTA - Improved network event sender/receiver allows sending events to multiple IP addresses
  - Untested:
    - eventghost-android: http://github.com/timhoeck/eventghost-android - Android network event app
    - EventGhost automation with LabVIEW: http://decibel.ni.com/content/docs/DOC-13135 - LabVIEW network event sender and receiver VI
    - ProntoScript Library: http://remotecentral.com/cgi-bin/mboard/prontopro/thread.cgi?3646 - Philips Pronto Home Control Panel communication
    - Android / Event Ghost Communication Suite: http://ip-symcon.de/forum/threads/19614-Android-Eventghost-Communication-Suite - IP-Symcon(pay software) automation system communication
    - EventGhost + zVirtualScenes Integration: http://stevecross.org/wiki/doku.php?id=eventghost_zvirtualscenes_integration - communication with zVirtualScenes free open-source home automation tool for Windows, Android, iOS, Blackberry and the Web
    - RemoteGhost: http://windowsphone.com/en-us/store/app/remoteghost/15e3196b-c62c-4bb3-9ca8-2d7d1f0d2f50 http://forum.xda-developers.com/showthread.php?t=2076716 - Windows phone network event app
    - EGRemote Lite: http://play.google.com/store/apps/details?id=eu.rml.lab.egremote_lite - Android network event app
    - MoviePoster: http://movieposterapp.com/
- Pay
  - Untested:
    - Girder - Automation software
    - NetRemote - Automation software
    - terRemote - Android network event app
    - RemoteGhostPro - Windows phone network event app
    - EGRemote  - Android network event app


#### Related Programs
- Modified Ethernet library - allows the use of the senderIP() function: http://github.com/per1234/Ethernet - make sure to choose the correct branch for your Arduino IDE version
- Entropy truly random numbers library: http://sites.google.com/site/astudyofentropy/file-cabinet
- EtherEventQueue outgoing event queue library: http://github.com/per1234/EtherEventQueue
- UIPEthernet ENC28J60 Ethernet chip library: http://github.com/ntruchsess/arduino_uip
<<<<<<< HEAD
- Flash library to allow passing payload strings stored in flash memory without a string length argument: http://github.com/rkhamilton/Flash

=======
>>>>>>> 9e19770... Format documentation


#### Installation
- 32k is the minimum recommended flash memory capacity for use of this library.
- Download the most recent version of EtherEvent here: https://github.com/per1234/EtherEvent/archive/master.zip
- Extract the **EtherEvent-master** folder from the downloaded zip file.
- Rename the folder **EtherEvent**.
- Move the folder to the libraries folder under your Arduino sketchbook folder as configured in Arduino IDE **File > Preferences > Sketchbook** location.
- Repeat this process with the other required libraries.
- If you want to use the senderIP() function then you must install the modified Ethernet library: http://github.com/per1234/Ethernet
- Restart the Arduino IDE if it is open.
- Running the example sketch:
  - File > Examples > EtherEventExample
  - Enable DHCP or set the device IP address, this can be any available IP address on your network.
  - Set the device MAC address. This can be any address not already used on your network
  - Set the EtherEvent password. The password must be the same on all connected devices.
  - Upload to device
  - Repeat with other connected devices. The serial monitor will show details of the test communications.


#### About Events and Payloads
Events are used to trigger an action. The payload is information that accompanies the event. An example is an event code that triggers the display of the payload. Some events don't require a payload and in this case the payload may be left blank.


#### Usage
See the example sketches and EventGhost tree files for demonstration of library usage.
`EtherEvent.begin([eventLengthMax, payloadLengthMax])` - Initialize EtherEvent.
- Parameter(optional): eventLengthMax - The maximum length of event that can be received. Longer events will be truncated to this length. EtherEvent reserves SRAM to buffer the received event so this value affects the amount of memory used. If this parameter is not passed then the default will be used.
  - Type: byte
- Parameter(optional): payloadLengthMax - The maximum length of payload that can be received. Longer payloads will be truncated to this length. EtherEvent reserves SRAM to buffer the received payload so this value affects the amount of memory used. If this parameter is not passed then the default will be used.
  - Type: byte
- Returns: true = success, false = memory allocation failed
  - Type: boolean

`EtherEvent.setPassword(password[, passwordLength])` - Set the password.
- Parameter: password - Password used to authenticate event transmission.
  - Type: char array or _FLASH_STRING(Flash library)
- Parameter: passwordLength - Length of the password. Use this parameter only with __FlashStringHelper/F() password type.
  - Type: byte
- Returns: true = success, false = memory allocation failed
  - Type: boolean

`EtherEvent.availableEvent(ethernetServer)` - Receives new event if an event is not already buffered.
- Parameter: ethernetServer - The EthernetServer object created in the Ethernet setup of the user's sketch.
  - Type: EthernetServer
- Returns: Buffer size required to receive the event. This is the length of the received event and the null terminator.
  - Type: byte

`EtherEvent.availablePayload()` - availableEvent() must be called first.
- Parameter: none
- Returns: Buffer size required to receive the payload. This is the length of the received payload and the null terminator.
  - Type: byte

`EtherEvent.readEvent(eventBuffer)` - Puts the event in the passed array. availableEvent() must be called first. Size a char array according to the result of availableEvent() and pass it to readEvent(). After that it will contain the event.
- Parameter: eventBuffer - Buffer to hold the received event.
  - Type: char array
- Returns: none

`EtherEvent.readPayload(payloadBuffer)` - Puts the payload string in the passed array. availableEvent() must be called first. Size a char array according to the result of availablePayload() and pass it to readPayload(). After that it will contain the payload.
- Parameter: payloadBuffer - Buffer to hold the received payload.
  - Type: char array
- Returns: none

`EtherEvent.senderIP()` - Returns the IP address of the sender of the most recent event. Must have the modified Ethernet library(http://github.com/per1234/Ethernet) installed for this function to be available.
- Parameter: none
- Returns: IP address of the sender.
  - Type: IPAddress

`EtherEvent.flushReceiver()` - Clear any buffered event and payload data so a new event can be received.
- Parameter:none
- Returns:none

`EtherEvent.send(ethenetClient, target, port, event[, eventLength][, payload[, payloadLength]])` - Send an event and payload.
- Parameter: ethernetClient - The EthernetClient object created in the Ethernet setup of the user's sketch.
  - Type: EthernetClient
- Parameter: target - IP address to send the event to.
  - Type: IPAddress or byte(4 byte array)
- Parameter: port: port to send the event to.
  - Type: unsigned int
- Parameter: event - String to send as the event.
  - Type: const char(char array)
- Parameter: eventLength - Length of the event. This parameter should only be used if event is of type __FlashStringHelper(F() macro).
  - Type: byte
- Parameter(optional): payload - payload to send with the event(char array). The payload is not optional when the event is of type __FlashStringHelper(F() macro).
  - Type: char/int8_t/byte/int/unsigned int/long/unsigned long/_FLASH_STRING/__FlashStringHelper(F() macro)
- Parameter: payloadLength:- length of the payload. This parameter should only be used if event is of type type __FlashStringHelper(F() macro).
  - Type: byte
- Returns: true = success, false = failure
  - Type: boolean

`EtherEvent.setTimeout(timeout)`
- Parameter: timeout - The max time to wait for Ethernet communication in milliseconds.
  - Type: unsigned int
- Returns:none


<<<<<<< HEAD
<<<<<<< HEAD
`EtherEvent.setPassword(password)` - Set the password.
- Parameter: password - Password used to authenticate event transmission.
  - Type: char array
- Returns: true == success, false == memory allocation failed
  - Type: boolean
=======
#### Configuration Parameters
There are a few flags that can be set in the file **EtherEvent.cpp** to enable extra features:
- If you are using the Flash library then uncomment `//#include "Flash.h"` in **EtherEvent.cpp** and **EtherEvent.h**.
- Debug - set `#define DEBUG true` to get debug output in the serial monitor, this will slow down communication.
- Entropy library - uncomment the line  `//#include "Entropy.h"`.
- Truly random cookie - A higher level of security can be achieved at the cost of slower receipt of events via availableEvent() by setting `const boolean randomCookie = true`.
>>>>>>> 9af0e87... setPassword() __FlashStringHelper and _FLASH_STRING
=======
#### Configuration Parameters
<<<<<<< HEAD
There are a few flags that can be set in the file EtherEvent.cpp to enable extra features:
- Entropy library - uncomment the line  //#include "Entropy.h"
- Debug - set #define DEBUG true to get debug output in the serial monitor, this will slow down communication.
- Truly random cookie - A higher level of security can be achieved at the cost of slower receipt of events via availableEvent() by enabling the `RANDOM_COOKIE` flag.
>>>>>>> 9e19770... Format documentation
=======
There are a few flags that can be set in the file **EtherEvent.cpp** to enable extra features:
- Entropy library - uncomment the line  `//#include "Entropy.h"`.
- Debug - set `#define DEBUG true` to get debug output in the serial monitor, this will slow down communication.
- Truly random cookie - A higher level of security can be achieved at the cost of slower receipt of events via availableEvent() by setting `const boolean randomCookie = true`.
>>>>>>> 95a2af3... Update documentation


#### Authentication Process
EventGhost/Girder use APOP style authentication for TCP communication without sending passwords in plaintext. The EtherEvent library allows the Arduino to use this previously established authentication system. Cryptographic use of MD5 is now considered insecure.
- sender: Connect to receiver.
- receiver: Waits for `quintessence\n\r`.
- sender: Send `quintessence\n\r` and wait for cookie.
- receiver: Send a cookie(EventGhost uses the sock, EtherEvent uses a random number) to the sender and wait for response.
- sender: The password is appended to the cookie and a new md5 digest calculated and sent back to the receiver and waits for `accept`.
- receiver: Calculates the proper MD5 value and compares it to the one from the sender. If it is correct then it sends back `accept`.
- sender: Send `payload {payload string}\n{event}\nclose\n` to the receiver.
- receiver: Handle message and close the connection to the sender.

