# Arduino Radar Project

## Overview
This project involves an Arduino setup with a servo motor and an ultrasonic sensor to measure distances and provide visual feedback using a radar-style display. The Arduino code controls the hardware to scan the environment, while the Processing-based Java application visualizes the data.

## Functionality
- **Distance measurement**: Utilizes an ultrasonic sensor attached to a servo motor. The sensor systematically measures distances at various angles as the servo rotates.
- **Data transmission**: Measurements are sent from the Arduino to a computer via serial communication.
- **Real-time visualization**: A Processing application receives the data and visualizes it in a radar-like interface, providing a dynamic view of the environment based on sensor readings.

## Features
- **Arduino Script**: Controls a servo motor to rotate an ultrasonic sensor and measures distances. The distances are sent over serial communication.
- **Processing Application**: Visualizes the data received from the Arduino in a radar-style interface, updating in real-time as the sensor scans.

## Installation Requirements
- **Arduino IDE**: To upload the sketch to your Arduino board. [Link](https://www.arduino.cc/en/software)
- **Processing 3**: To run the radar interface visual application. [Link](https://processing.org/download)

### Hardware Required
- Arduino Board
- Servo Motor
- Ultrasonic Sensor (HC-SR04)
- Buzzer
- Appropriate cables and power supply

## Setup and Usage
1. **Arduino Setup**:
   - Connect the servo to the specified pin on the Arduino.
   - Attach the ultrasonic sensor to the servo.
   - Connect the buzzer to the appropriate pin.
   - Upload `arduino_code.ino` to the Arduino.

2. **Processing Setup**:
   - Open `radar_interface.java` with Processing.
   - Ensure the COM port in the code matches the one used by your Arduino.
   - Run the program to visualize the sensor data.

# Videos

![](/img/Project/radar_scheme.gif)

[![Watch the video](/img/Project/real_radar.png)](https://youtu.be/txFutFT6s20)


