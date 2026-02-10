# Arduino Smart Fan Automation System

## Overview

This project is an Arduino-based smart fan automation system that combines temperature sensing and human presence detection to control a fan efficiently. The system uses a DHT11 temperature sensor and a PIR motion sensor to ensure the fan operates only when necessary.

Designed as an academic project, this repository demonstrates basic automation logic, sensor integration, and real-time status display using Arduino.

---

## Main Features

* Automatic fan control based on temperature threshold
* Human presence detection using PIR sensor
* Dual-condition logic for fan activation
* Real-time temperature monitoring
* 16x2 I2C LCD display for system status
* LED indicator synchronized with fan operation
* Simple and reliable control flow

---

## Hardware Components

* Arduino Board
* DHT11 Temperature Sensor
* PIR Motion Sensor
* DC Fan / Motor
* Motor Driver (INA & INB control)
* LED Indicator
* 16x2 I2C LCD Display
* Breadboard and Jumper Wires
* Power Supply

---

## Pin Configuration

| Component       | Arduino Pin |
| --------------- | ----------- |
| DHT11 Data      | D2          |
| PIR Sensor      | D6          |
| Fan Control INA | D4          |
| Fan Control INB | D5          |
| LED Indicator   | D7          |
| I2C LCD         | SDA / SCL   |

---

## Software Requirements

* Arduino IDE
* Required Libraries:

  * DHT Sensor Library
  * Wire
  * LiquidCrystal_I2C

---

## System Architecture

The Arduino continuously reads temperature data from the DHT11 sensor and detects human presence using the PIR sensor. The control logic evaluates both inputs before activating the fan.

Fan activation conditions:

* Temperature is greater than or equal to 28°C
* Human presence is detected by the PIR sensor

If either condition is not met, the fan remains OFF.

---

## Operation Flow

1. Arduino initializes sensors and LCD display
2. Temperature and motion data are read continuously
3. System evaluates fan activation conditions
4. Fan and LED turn ON only when both conditions are satisfied
5. LCD displays:

   * Current temperature (°C)
   * Presence status (Detected / Not Detected)

---

## Display Information

* **LCD Line 1:** Current temperature
* **LCD Line 2:** Human presence status

---

## Installation Steps

1. Clone this repository: https://github.com/harsadella/arduino-smart-fan-automation
2. Open the project in Arduino IDE
3. Install all required libraries
4. Assemble the circuit according to the pin configuration
5. Upload the main code to the Arduino board
6. Power the system

---

## Project Purpose

This project was developed as an academic assignment to demonstrate:

* Basic automation systems
* Sensor integration using Arduino
* Conditional control logic
* Real-time system monitoring

---

## License

This project is intended for educational and learning purposes.
