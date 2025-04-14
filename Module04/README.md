# Module 4
Description: In these modules, you will learn how to build and simulate your own IoT systems from the ground up. The focus begins with programming ESP-based microcontrollers (ESP8266, ESP32, ESP32-S2) using PlatformIO. You will learn how to set up projects, import and manage libraries, connect via serial, and compile/upload your code. We'll explore essential libraries for sensors and actuators, and discuss common issues in IoT development—such as interrupt conflicts and cross-library problems.

You will also learn how to deploy firmware Over-The-Air (OTA) and enable communication between multiple nodes over your network. This includes a deeper look into the IoTempower framework and how it helps prepare and manage firmware across IoT nodes.

Once your hardware is running, the focus shifts to simulation and integration. You'll create your own software simulators to mimic real sensors and actuators, and use them to test your systems. You'll get hands-on with IoTknit, a CLI tool for building integration pipelines, and work with Node-RED, diving deeper into its powerful visual tools for automation and system orchestration.

## Week 1 mini-project 1 & mini-project 2 - Nullpointer Dereference & Divide by Zero
[simplebreak.cpp](https://github.com/marleneibrus/iot-portfolio/blob/main/Module04/pictures/simplebreak.cpp) <br>

## Week 1 mini-project 3 - Too Little Memory
[memorybreak.cpp](https://github.com/marleneibrus/iot-portfolio/blob/main/Module04/pictures/memorybreak.cpp) <br>

## Week 1 mini-project 4 - Crashing with interrupts
[crashinterrupt.cpp](https://github.com/marleneibrus/iot-portfolio/blob/main/Module04/pictures/crashinterrupt.cpp) <br>

## Week 1 mini-project 5 - OTA Flashing
[otaflash.cpp](https://github.com/marleneibrus/iot-portfolio/blob/main/Module04/pictures/otaflash.cpp)

## Week 1 mini-project 6 - Emergency Scenario: MQTT Alarm
[emergency.cpp](https://github.com/marleneibrus/iot-portfolio/blob/main/Module04/pictures/emergency.cpp)

## Week 2-3 mini-project 1 - HVAC system with Integration and Simulators/Mockups
Steps to set up this project:
- Watch the video and recreate the AC integrator component. The main issues that we faced were networking issues once again:( silly us:// The problem was that we did not supply enough power to the router.
    - The code: [test.py](https://github.com/marleneibrus/iot-portfolio/blob/main/Module04/pictures/test.py)
- Create a separate temperature simulator that publishes oscillating values to `home/temperature`.
    - Temperature simulator: [temp.py](https://github.com/marleneibrus/iot-portfolio/blob/main/Module04/pictures/temp.py)
- Create an AC simulator that subscribes to `home/ac/set` topic and publishes if the AC is on or off.
    - AC simulator: [ac.py](https://github.com/marleneibrus/iot-portfolio/blob/main/Module04/pictures/ac.py) (has a bug, no ON message gets published)
- Create an integrator(controller) that Subscribes to `home/temperature`, if temp > 24°C then it publishes `"on"` to `home/ac/set`, otherwise it publishes `"off"` to `home/ac/set`.
    - Integrator: [integrator.py](https://github.com/marleneibrus/iot-portfolio/blob/main/Module04/pictures/integrator.py)
- Run all of the components together.

Screenshot of the components running together: [Screenshot](https://github.com/marleneibrus/iot-portfolio/blob/main/Module04/pictures/iotmodule4_simulators.png)
