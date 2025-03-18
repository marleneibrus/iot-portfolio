# Module 3

Description: This module will teach you how to set up your Internet of Things infrastructure. You will understand the difference between deploying a system on the Internet vs. the Intranet. You understand transports and how to set up a gateway to manage your future projects. During the labs, you will install the open-source IoTempower framework and OpenWRT on the hardware provided.  You will deploy your own WiFi network also, learn about the MQTT protocol, and have a chance to run Mosquitto broker on your system. In short, you will have practical experience with all the basics needed to set up your own IoT infrastructure anywhere for your projects.

## Task 1 - Adabird video 
The protocols mentioned are Etehrnet, WiFi, Bluetooth, cellular, RFID/NFC, satellites, sub-GHz, LoRa and mesh networks.

| Protocol | Advantage | Disadvantage |
| :---: | :---: | :---:|
| Ethernet | High speed & low latency |	Requires physical cables, limiting mobility |
WiFi |	Wireless and widely available |	Higher power consumption & interference issues |
Bluetooth |	Low power & good for short-range IoT |	Limited range (typically 10-100m) |
Cellular |	Large coverage area & reliable |	Requires a data plan & higher power usage |
RFID/NFC |	Fast, contactless communication	| Very short range (NFC: ~10cm, RFID: ~1-10m) |
Satellites |	Global coverage |	High latency & expensive to deploy |
Sub-GHz |	Long-range & low power |	Lower data rates compared to WiFi |
LoRa |	Extremely long-range & low power |	Limited bandwidth for data transmission |
Mesh Networks |	Self-healing & scalable |	Can be complex to set up and manage |

## Task 2 - Quick quide on setting up an IoT Network with MQTT on a router
In order to set up an IoT network with MQTT, one should follow these general steps:
 1. Choose an MQTT Broker: Could be Mosquitto (recommended for lightweight setups)which can be installed directly if your router supports OpenWRT/DD-WRT.
 2. Set Up Your Router for IoT Devices: Log into the router settings, create a separate IoT Wi-Fi network (optional for security), assign static IPs to IoT devices for stable connections.
 3. Install Mosquitto on the Router (If Supported)
 4. Configure Mosquitto MQTT Broker
 5. Connect IoT Devices (ESP8266/ESP32)
 6. Test MQTT Communication
 7. Expand the network

## Week 1 mini-project 1 - etup your local cloud/intranet
The solution to this task can be found in py partners portfolio [here](https://github.com/maarekarmenoras/iot-portfolio/tree/main/Module03).

## Week 2 mini-project 1 - IoTempower networking
Setup Process
 1. Connected the phone via USB to the router.
 2. Enabled USB tethering on the phone.
 3. Logged into the router’s Config Interface (via Ethernet).
 4. Navigated to Network → Interfaces and created a new interface named usb1.
 5. Set the device to eth1, assigned the firewall zone to wan wna6, and saved the settings.
 6. Verified internet access on both the laptop and the WiFi network.

we also faced a large challenge during this mini-project. Mainly, USB tethering not detected by the router
Initially, the router did not recognize the phone’s tethered connection. We solved this by with the help of the lab assistants. They halped us ensure that the phone was in USB Tethering Mode, then we restarted both the router and phone, and used a different USB cable. A picture of us using USB tethering can be found [here](https://github.com/maarekarmenoras/iot-portfolio/blob/main/Module03/pictures/usb_tethering.jpg).

## Week 2 mini-project 2 - MQTT listens everywhere
A more detailed solution to this task can be found in my partners portfolio [here](https://github.com/maarekarmenoras/iot-portfolio/tree/main/Module03). Using NodeRed was not overly difficult.

## Week 2 mini-project 3 - FirstAid station emergency button
When trying to solve this task at home, we kept running into the same issue with the router not working that we had had in the lab. We did build the circuit and [here](https://github.com/marleneibrus/iot-portfolio/blob/main/Module03/pictures/emergency.cpp) is our proposed code.

## Week 2 mini-project 4 - Remote access to the gateway
We had no connection to the router so we could not solve this task.
 
