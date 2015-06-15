EtherEvent
==========

Easy to use [Arduino](http://arduino.cc/) library for password authenticated network communication via Ethernet between Arduinos and [EventGhost](http://eventghost.com), or any other program compatible with the EventGhost Network Event Sender and Receiver plugins. Compatible with Arduino Ethernet, Ethernet Shield, and other devices using the W5100/W5200/W5500 Ethernet controller.

This is a beta release. I have been successfully using it with EventGhost in my home automation system constantly for the last 5 months. Pull requests and issue reports are welcome.


#### Required Libraries
- ArduinoMD5 http://github.com/tzikis/ArduinoMD5


#### Compatible Software
- Free
  - Tested to work with this library:
    - EventGhost: http://eventghost.com - Free open source automation tool for Windows
    - TCPEvents EventGhost plugin: https://github.com/per1234/TCPEvents - Improved network event sender/receiver allows sending events to multiple IP addresses.
    - EventGhost automation with LabVIEW: http://decibel.ni.com/content/docs/DOC-13135 - LabVIEW network event sender and receiver VI. The receiver requires a large timeout value.
  - Untested:
    - eventghost-android: http://github.com/timhoeck/eventghost-android - Android network event app
    - EGRemote Lite: http://play.google.com/store/apps/details?id=eu.rml.lab.egremote_lite - Android network event app
    - RemoteGhost: http://forum.xda-developers.com/showthread.php?t=2076716 - Windows phone network event app
    - ProntoScript Library: http://remotecentral.com/cgi-bin/mboard/prontopro/thread.cgi?3646 - Philips Pronto Home Control Panel communication
    - Android/Eventghost Communication Suite: http://ip-symcon.de/forum/threads/19614-Android-Eventghost-Communication-Suite - IP-Symcon(pay software) automation system communication
- Pay
  - Untested:
    - terRemote - Android network event app
    - EGRemote  - Android network event app
    - RemoteGhostPro - Windows Phone network event app


#### Related Programs
- EtherEventQueue outgoing event queue library: http://github.com/per1234/EtherEventQueue
- Modified Ethernet library - allows the use of the senderIP() function: http://github.com/per1234/Ethernet - make sure to choose the correct branch for your Arduino IDE version
- Wiznet Ethernet library for use with W5200 or W5500 Ethernet controller: https://github.com/embeddist/WIZ_Ethernet_Library-IDE1.5.x


<a id="installation"></a>
#### Installation
- 32KB is the minimum recommended flash memory capacity for use of this library.
- Download the most recent version of EtherEvent here: https://github.com/per1234/EtherEvent/archive/master.zip
- Using Arduino IDE 1.0.x:
  - Sketch > Import Library... > Add Library... > select the downloaded file > Open
- Using Arduino IDE 1.5+:
  - Sketch > Include Library > Add ZIP Library... > select the downloaded file > Open
- Repeat this process with the other required libraries.
- If you want to use the senderIP() function then you must install the modified Ethernet library: http://github.com/per1234/Ethernet
- Running the example sketch:
  - File > Examples > EtherEventExample
  - Enable DHCP or set the device IP address, this can be any available IP address on your network.
  - Set the device MAC address. This can be any address not already used on your network
  - Set the EtherEvent password. The password must be the same on all connected devices.
  - Upload to device
  - Repeat with other connected devices. The serial monitor will show details of the test communications.


#### About Events and Payloads
Events are used to trigger an action. The payload is information that accompanies the event. An example is an event code that triggers the display of the payload. Some events don't require a payload and in this case the payload may be left blank.


<a id="usage"></a>
#### Usage
See the example sketches and EventGhost tree files for demonstration of library usage.

`EtherEvent.begin([eventLengthMax, payloadLengthMax])` - Initialize EtherEvent.
- Parameter(optional): **eventLengthMax** - The maximum length of event that can be received. Longer events will be truncated to this length. EtherEvent reserves SRAM to buffer the received event so this value affects the amount of memory used. If this parameter is not passed then the default will be used.
  - Type: byte
- Parameter(optional): **payloadLengthMax** - The maximum length of payload that can be received. Longer payloads will be truncated to this length. EtherEvent reserves SRAM to buffer the received payload so this value affects the amount of memory used. If this parameter is not passed then the default will be used.
  - Type: byte
- Returns: `true` = success, `false` = memory allocation failed
  - Type: boolean

`EtherEvent.setPassword(password)` - Set the password.
- Parameter: **password** - Password used to authenticate event transmission.
  - Type: char array or __FlashStringHelper/F()
- Returns: `true` = success, `false` = memory allocation failed
  - Type: boolean

`EtherEvent.availableEvent(ethernetServer, cookie)` - Receives new event if an event is not already buffered.
- Parameter: **ethernetServer** - The EthernetServer object created in the Ethernet setup of the user's sketch.
  - Type: EthernetServer
- Parameter(optional): **cookie** - Cookie value to use in the authentication process. This can be used to provide a truly random cookie for enhanced security. If this parameter is not specified then a pseudorandom cookie will be generated with the random() function.
  - Type: long
- Returns: Buffer size required to receive the event. This is the length of the received event and the null terminator.
  - Type: byte

`EtherEvent.availablePayload()` - availableEvent() must be called first.
- Returns: Buffer size required to receive the payload. This is the length of the received payload and the null terminator.
  - Type: byte

`EtherEvent.readEvent(eventBuffer)` - Puts the event in the passed array. availableEvent() must be called first. Size a char array according to the result of availableEvent() and pass it to readEvent(). After that it will contain the event.
- Parameter: **eventBuffer** - Buffer to hold the received event.
  - Type: char array
- Returns: none

`EtherEvent.readPayload(payloadBuffer)` - Puts the payload string in the passed array. availableEvent() must be called first. Size a char array according to the result of availablePayload() and pass it to readPayload(). After that it will contain the payload.
- Parameter: **payloadBuffer** - Buffer to hold the received payload.
  - Type: char array
- Returns: none

`EtherEvent.senderIP()` - Returns the IP address of the sender of the most recent event. Must have the modified Ethernet library(http://github.com/per1234/Ethernet) installed for this function to be available.
- Returns: IP address of the sender.
  - Type: IPAddress

`EtherEvent.flushReceiver()` - Clear any buffered event and payload data so a new event can be received.
- Returns: none

`EtherEvent.send(ethernetClient, target, port, event[, eventLength][, payload[, payloadLength]])` - Send an event and payload.
- Parameter: **ethernetClient** - The EthernetClient object created in the Ethernet setup of the user's sketch.
  - Type: EthernetClient
- Parameter: **target** - IP address to send the event to.
  - Type: IPAddress or byte(4 byte array)
- Parameter: **port** - Port to send the event to.
  - Type: unsigned int
- Parameter: **event**
  - Type: char array/int8_t/byte/int/unsigned int/long/unsigned long/_FLASH_STRING/__FlashStringHelper(F() macro)
- Parameter: **eventLength** - Length of the event. This parameter should only be used if event is of type __FlashStringHelper(F() macro).
  - Type: byte
- Parameter(optional): **payload** - Payload to send with the event. The payload is not optional when the event is of type __FlashStringHelper(F() macro).
  - Type: char array/int8_t/byte/int/unsigned int/long/unsigned long/_FLASH_STRING/__FlashStringHelper(F() macro)
- Parameter: **payloadLength** - Length of the payload. This parameter should only be used if event is of type __FlashStringHelper(F() macro).
  - Type: byte
- Returns: `true` = success, `false` = failure
  - Type: boolean

`EtherEvent.getTimeout()` - Returns the current timeout duration setting.
- Returns: The current timeout duration setting.
  - Type: unsigned int

`EtherEvent.setTimeout(timeout)` - Set the timeout duration.
- Parameter: **timeout** - The max time to wait for Ethernet communication in milliseconds.
  - Type: unsigned int
- Returns: none


<a id="configuration"></a>
#### Configuration
There are a few configuration options that can be set in the library source file **EtherEvent.h** to enable extra features:
- Debug output: By turning debug output on you can get details of the authentication process in the serial monitor. Set `#define ETHEREVENT_DEBUG true` in EtherEvent.h, this will slow down communication so only enable when needed.
- Flash library: https://github.com/schinken/Flash/tree/patch-2 If you are using the Flash library then uncomment `//#include "Flash.h"`. This will allow easy use of program memory with send() and setPassword().


<a id="troubleshooting"></a>
#### Troubleshooting
- Network configuration:
  - The MAC address you choose for the device must be unique on your network.
  - If using a static IP address it must also be unique on your network.
  - The firewall on computers running EventGhost must allow it to communicate via the network.
- Timeouts: When using the **BasicUsage.ino** example sketch you may notice sending or receiving an event sometimes will hang for a long time before failing. This is caused by the conservative default timeout values. **AdvancedUsage.ino** demonstrates setting the EtherEvent timeout via `setTimeout()` and the W5x00 Ethernet controller timeout and retry count via `W5100.setRetransmissionTime()` and `W5100.setRetransmissionCount()`. `setTimeout()` controls the amount of time that EtherEvent will wait for the authentication process communications. `W5100.setRetransmissionTime()` controls the amount of time that the W5x00 will wait after a connection attempt before retrying. `W5100.setRetransmissionCount()` controls the number of attempts the W5x00 will make before failing the connection attempt. By reducing the timeout values you can shorten the amount of time that the system will hang during a failed event transmission. If the timeout values are too small then you will see frequent transmission failures. By experimenting with different values you can find appropriate timeouts for your system. Be aware that the timeout requirements for Arduino to EventGhost event transmission may be different than Arduino to Arduino transmission.
- Debug output: By turning debug output on you can get details of the authentication process in the serial monitor. Set `#define ETHEREVENT_DEBUG true` in EtherEvent.h, this will slow down communication so only enable when needed.


<a id="security"></a>
#### Security Considerations
- EtherEvent only encrypts the authentication password. The event is sent in plaintext. This prevents the receipt of unauthorized events but does not protect the information contained in the event from being seen.
- Use of EventGhost Network Event Receiver plugin is not recommended due to a bug that causes it to send the same cookie for every event. My [modified TCPEvents EventGhost plugin](https://github.com/per1234/TCPEvents0 has this security vulnerability patched.
- Cookie Randomization: an important factor in the authentication security is the randomness of the cookie supplied by the event receiver. There is a tradeoff between security and memory usage/speed so the ideal level of cookie randomization depends on your application.
  - Default operation: If a cookie is not supplied then EtherEvent uses the value of `micros()` for a seed and produces the cookie using the `random()` function.
  - User supplied cookie: You can generate your own random cookie and pass the value to `availableEvent()`.
    - Entropy library: A truly random number can be generated by the Entropy library and used for every cookie. This will cause greater flash memory usage and slower authentication. See the example sketch **Entropy.ino** for demonstration of use of the Entropy library with EtherEvent.


<a id="process"></a>
#### Authentication Process
EventGhost uses MD5 encrypted APOP style authentication to avoid sending passwords in plaintext.
- sender: Connect to receiver. Send `quintessence\n\r`.
- receiver: Send cookie.
- sender: The password is appended to the cookie and the MD5 digest is calculated and sent back to the receiver.
- receiver: If the received MD5 digest is correct then it sends `accept`.
- sender: Send `payload {payload string}\n{event}\nclose\n` to the receiver.
- receiver: Close the connection to the sender.

