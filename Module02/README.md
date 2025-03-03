# Module 2
Description: In this module, you will learn the basics of prototyping a small electronic project that involves using the breadboard, look into the sensors, actuators, and microcontrollers available for you to use in our course, and learn how the relay-lock system works. You have the chance to look into the M5StickC and what parts it is comprised of. Also, learn about resistors, capacitors, pull-up and pull-down resistors.

My patner was Maare Karmen, her portfolio can be found here: [Maare's portfolio](https://github.com/maarekarmenoras/iot-portfolio) and her Module 2 is located here: [Maare's Module 2](https://github.com/maarekarmenoras/iot-portfolio/tree/main/Module02). <br>
We are going to show here notes for Task 1, 2, 3, 4, and 5 to prove

## Task 1 - Kit cataloge

The kit contains:
- USB-C to USB-A Cable: Used for data transfer and power delivery between devices. This is commonly used to connect microcontrollers like the ESP8266 to a computer.
- 100-240V AC/DC Adapter with Barrel Adapter + Y Cable: Converts high-voltage AC (from a wall outlet) into lower-voltage DC, suitable for powering electronic components. The barrel adapter provides an easy connection to compatible devices, and the Y cable allows power distribution to multiple components.
- Breadboard: A reusable platform for assembling temporary circuits without soldering. It has interconnected rows and columns for easy wiring.
- Jumper Wires: Used to make electrical connections between components on a breadboard or between a breadboard and other devices.
- White LED, Red LED, Yellow LED: Light-emitting diodes that emit light when current passes through them. Different colors require different voltage levels.
- Resistors (3× 330Ω + 1× 10kΩ):
  - 330Ω resistors are commonly used to limit current for LEDs, preventing them from burning out.
  - 10kΩ resistors are often used as pull-up or pull-down resistors for buttons or sensors.
- Capacitor: Stores and releases electrical energy. It can be used for filtering noise in circuits or stabilizing power supply voltage.
- Wi-Fi ESP8266 Micro USB Chip: A low-cost microcontroller with built-in Wi-Fi, often used for IoT projects. The USB port allows easy programming and power supply.
- Wemos D1 Mini Relay Shield (Blue) + Mechanical Relay:
The Wemos D1 Mini Relay Shield is an add-on for the Wemos D1 Mini (ESP8266-based board) that allows it to control high-power devices.
The Mechanical Relay acts as an electrically controlled switch, enabling low-power circuits to control higher voltage or current loads.
- 12V Solenoid Drawer Lock (contains small coils): A solenoid lock uses an electromagnetic coil to move a metal latch, allowing it to lock or unlock when power is applied. It's commonly used for electronic locking systems.

## Task 2 - Breadboards
[The video](https://youtu.be/yXirMBP3x4U?si=kBeR9sAi3R3IHdmV )

What is a breadboard?
- A breadboard is a platform for assembling electronic circuits. It features horizontal connections in the center and vertical ones along the edges. If additional space is needed, multiple breadboards can be linked together.

Cable color coding conventions:
- Typically, black or blue wires indicate ground, while red or brown wires signify the positive connection.

Wiring an LED to 5V:
- An LED consists of a small filament that lights up when current flows through it. Since different LED colors require varying voltages, a resistor is necessary when connecting an LED to a 5V supply to prevent damage.

Unclear or important concept:
- Needed to refresh my understanding of Ohm’s Law.

## Task 3 - ESP8622
[The video](https://youtu.be/wOEDaFRlhLo)
- Why ESP8266? It’s an affordable and versatile microcontroller with built-in Wi-Fi.
- What is inspiring? Microcontrollers are surprisingly inexpensive, making electronics accessible to everyone.
- What about coffee? The ESPresso Lite microcontroller costs about the same as a cup of coffee.

## Task 4 - Other MCU
One other MCU is the ESP32. The disadvantages of WeMos D1 Mini(ESP8266) are:
- ESP32 has more processing power – The ESP32 has a dual-core processor (compared to the ESP8266’s single-core), making it faster and more efficient for multitasking.
- ESP32 has more RAM & storage – The ESP32 has 520KB RAM and up to 16MB flash storage, whereas the ESP8266 has 80KB RAM and typically 4MB flash.
- ESP32 has Bluetooth support – The ESP32 includes Bluetooth (Classic + BLE), which the ESP8266 lacks.

## Week 2 mini-project 1 - LED-button
[Picture](https://github.com/marleneibrus/iot-portfolio/blob/main/Module02/pictures/IMG_0001.png) <br>
[Schematic and calculations](https://github.com/marleneibrus/iot-portfolio/blob/main/Module02/pictures/IMG_9909.png)

## Week 2 mini-project 2 - relay-lock-button
[Picture](https://github.com/marleneibrus/iot-portfolio/blob/main/Module02/pictures/IMG_9920.png)

Active-high and active-low refer to how a circuit responds to a control signal:
- Active-High: The device activates when the control signal is HIGH (1) or VCC.
- Active-Low: The device activates when the control signal is LOW (0) or GND.

Normally-Open (NO) vs. Normally-Closed (NC)
- Normally-Open (NO): The circuit is disconnected by default, and the relay closes it when activated. This is common for solenoid locks, as power is only applied when unlocking.
- Normally-Closed (NC): The circuit is connected by default, and the relay breaks the connection when activated. This is used in cases where a device should remain powered unless explicitly turned off.

Pull-Down vs. Pull-Up Resistors
- Pull-Down Resistor (10kΩ to GND): Keeps the input LOW (0) when the button is not pressed. When pressed, the voltage is pulled HIGH.
- Pull-Up Resistor (10kΩ to VCC): Keeps the input HIGH (1) when the button is not pressed. When pressed, the voltage is pulled LOW.

## Reflection 2
[Reflection 2](https://github.com/marleneibrus/iot-portfolio/blob/main/Reflections/ref02.md)

## Task 5 - Presentations
| **Protocol** | **Speed** | **Max Length** | **Wires** | **Notes** |
|-------------|----------|--------------|----------|-----------|
| **1-Wire** | 16.3 kbps | 100m (300m with twisted pairs) | 2 conductors + small capacitor | 3V or 5V, 64-bit unique address, master/slave communication, used in NFC, locks, smart batteries, thermostats |
| **RS232** | 40 kbps | 15m | ? | From the 50s, used for PC peripherals (mice, printers, storage), replaced by USB, 15V, auto shutdown/wakeup, high ESP protection |
| **RS485 (TIA-485(-A) / EIA-485)** | 10 Mbit/s | 1200m | 2 or 4 wires | Strong immunity against electrical noise |
| **CAN** | - | - | - | [Slides](https://docs.google.com/presentation/d/1J2QVYmNpkkFoUbIkxXJ87nYsgVCiI62j0ol10EM5o7I/edit?usp=sharing), supports 32-127 nodes |
| **I2C / I3C** | 100 kbit/s – 3.4 Mbit/s (I2C) / 100 kbit/s – 20 Mbit/s (I3C) | 3-4m (I3C max length depends on speed) | Not specified | Used in sensors, actuators, LCD/OLED displays, master/slave system |
| **SPI** | Not specified | Short distances | Not specified | Master/slave communication, used in IoT, sensors, SD card modules, RFID |

## Task 6 - Arduino
How are programs saved and run on the Wemos D1 Mini – how many at once?
- Programs are flashed using Arduino IDE or PlatformIO. Only one program can run at a time.

Which voltages did you use? Which voltages can you use?
- We used 5V, but 3.3V is also supported.

What does High and Low mean?
- High means power is present, Low means no power.

Where is the easiest place to find example solutions?
- [Here](https://github.com/wemos/D1_mini_Examples/tree/master)

What is special about the onboard LED on the Wemos D1 Mini?
- It is connected to D4 and is inverted (LOW = ON, HIGH = OFF).

## Task 7 - IDE
I prefer working with VSC and PlatformIO, I'm already used to working with VSC and PlatformIO works well once I managed to set it up.

## Week 3 Mini project 1 - Blink an LED
Getting the LED to blink was straightforward once we resolved PlatformIO's port recognition issues on my partners computer, though that took some time. The code was sourced online.
From my partner's portfolio: [Blink on](https://github.com/maarekarmenoras/iot-portfolio/blob/main/Module02/pictures/20250225_132451.jpg), [Blink off](https://github.com/maarekarmenoras/iot-portfolio/blob/main/Module02/pictures/20250225_132452.jpg)

## Week 3 Mini project 2 - Reading analog values
We followed a provided schematic and used online code to read analog values successfully.
From my partner's portfolio: [Reading analog values](https://github.com/maarekarmenoras/iot-portfolio/blob/main/Module02/pictures/20250301_150118.jpg) <br>
[Picture](https://github.com/marleneibrus/iot-portfolio/blob/main/Module02/pictures/IMG_0002.png)

## Week 3 Mini project 3 - Pick-mpr121 touch sensor and building a touch interface
We did not figure out how we were supposed to connect this to multiple interesting surfaces. However, we observed that when using a folded Kinder chocolate wrapper, more pressure was required for the touch to register.
From my partner's portfolio: [Touch sensor](https://github.com/maarekarmenoras/iot-portfolio/blob/main/Module02/pictures/20250301_152049.jpg) and [code](https://38-3d.co.uk/blogs/blog/how-to-use-the-mpr121-capacitive-touch-sensor-with-arduino).

## Week 3 Mini project 4 - Bomb defuse challenge
I was not able to fully complete this challenge as my M5 Stick stopped working. I created a schematic of what I imagine the solution to this cahllenge being, which can be found [here](https://github.com/marleneibrus/iot-portfolio/blob/main/Module02/pictures/21901126-d958-4a4b-b398-f9f66e872c81.jpeg). The LED strip should be 12V not 5V. I also rewrote the code, which can be found [here](https://github.com/marleneibrus/iot-portfolio/blob/main/Module02/pictures/main.cpp).

## Week 3 Mini project 5 - Combination challenge
I could not solve this challenge, because my M5 Stick was not working. Using my partners M5 Stick we experimented with different approaches but eventually ran out of energy and decided to wrap it up.

## Reflection 3
[Reflection 3](https://github.com/marleneibrus/iot-portfolio/blob/main/Reflections/ref03.md)


