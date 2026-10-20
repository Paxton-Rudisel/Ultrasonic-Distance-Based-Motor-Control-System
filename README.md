# Ultrasonic Distance-Based Motor Control System

## Project Overview

This project uses an ESP32 microcontroller and an HC-SR04 ultrasonic sensor to control a DC motor based on the distance of nearby objects. An RGB LED strip provides visual feedback, displaying different colors to indicate the motor's operating state.

The system demonstrates embedded programming, sensor integration, motor control, and circuit prototyping.

## Hardware Components

- ESP32 microcontroller
- HC-SR04 ultrasonic distance sensor
- DC motor with fan attachment
- RGB LED strip
- Motor driver circuitry
- Breadboard and jumper wires
- Power supply

## System Operation

The ESP32 reads distance measurements from the ultrasonic sensor and determines the appropriate motor operating state. The LED strip changes color to indicate the current response.

| LED Color | Motor State | Operation |
|---|---|---|
| 🟢 Green | Forward | Motor rotates in its normal direction |
| 🟡 Yellow | Reverse | Motor rotates in the opposite direction |
| 🔴 Red | Stop | Motor stops rotating |

## Software Structure

The project is organized into seven Arduino source files:

- `Rudisel_Paxton_MP04.ino` — Main program
- `startup.ino` — System initialization
- `readSensorData.ino` — Ultrasonic sensor measurements
- `GoState.ino` — Forward motor operation
- `ReverseState.ino` — Reverse motor operation
- `StopState.ino` — Motor stop operation
- `OffState.ino` — Additional off-state functionality

## Skills Demonstrated

- ESP32 embedded systems programming
- Arduino IDE and C/C++
- Ultrasonic sensor integration
- DC motor control
- LED status indication
- Breadboard circuit prototyping
- Hardware and software troubleshooting

## Project Demonstration

Photos and a video demonstration show the system responding to changes in measured distance, including forward, reverse, and stop operations.
