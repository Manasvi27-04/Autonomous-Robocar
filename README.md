# Autonomous Robocar

A miniature autonomous vehicle capable of **lane/line following**, **obstacle avoidance**, and **real-time path correction**, built using Arduino, IR sensors, ultrasonic sensors, and a camera module. Sensor fusion and decision logic are implemented in C++ for responsive navigation in dynamic environments.

**Duration:** Jan 2025 – May 2025

---

## Overview

This project explores low-level autonomous navigation on a resource-constrained embedded platform (Arduino/Atmega32). Instead of relying on a single sensing modality, the car fuses signals from:

- **IR sensors** → line/lane detection and path following
- **Ultrasonic sensors (HC-SR04)** → obstacle detection and avoidance
- **Camera module** → visual reference for lane markers / obstacle context

The onboard logic continuously arbitrates between "follow the path" and "avoid the obstacle" behaviors, prioritizing safety while trying to stay on course.

## Features

- Real-time line/lane following using dual/triple IR sensor arrays
- Ultrasonic-based obstacle detection with automatic re-routing
- Sensor fusion layer that merges IR + ultrasonic inputs into a single motion decision
- PWM-based differential motor control for smooth turns
- Modular C++ structure — motor control, sensing, and decision logic are decoupled for easy tuning

## Hardware Used

| Component | Purpose |
|---|---|
| Arduino Uno / Atmega32 | Main controller |
| IR Sensor Array (2–3 sensors) | Line/lane detection |
| HC-SR04 Ultrasonic Sensor | Obstacle distance measurement |
| Camera Module | Visual feedback / future CV upgrades |
| L298N Motor Driver | Differential drive control |
| DC Geared Motors + Chassis | Locomotion |
| Li-ion Battery Pack | Power supply |

## Repository Structure

```
Autonomous-Robocar/
├── src/
│   ├── robocar_main.ino      # Main control loop
│   ├── motor_control.h       # Motor driver abstraction
│   ├── motor_control.cpp
│   ├── ir_sensor.h           # Line-following sensor logic
│   ├── ir_sensor.cpp
│   ├── ultrasonic.h          # Obstacle detection logic
│   └── ultrasonic.cpp
├── docs/
│   └── circuit_diagram.md    # Wiring reference
├── images/                   # Photos/diagrams of the build (add your own)
├── .gitignore
├── LICENSE
└── README.md
```

## How It Works

1. **Sensing loop** — every cycle, the IR array reports line position (left/center/right/off-line) and the ultrasonic sensor reports distance to the nearest obstacle ahead.
2. **Decision layer (sensor fusion)** — if an obstacle is within the safety threshold, obstacle-avoidance takes priority (stop → reverse/turn → resume). Otherwise, the car follows the line-following correction logic.
3. **Actuation** — the decision layer outputs a motion command (forward, left, right, reverse, stop) which is translated into PWM signals for the left/right motor pairs.

## Getting Started

1. Wire the components as described in [`docs/circuit_diagram.md`](docs/circuit_diagram.md).
2. Open `src/robocar_main.ino` in the Arduino IDE.
3. Adjust the pin definitions at the top of the file to match your wiring.
4. Calibrate the IR sensor thresholds (`IR_THRESHOLD`) and the obstacle distance threshold (`OBSTACLE_DISTANCE_CM`) for your track/environment.
5. Upload to the board and power the chassis.

## Future Improvements

- Replace the camera's role from passive feedback to active lane detection using onboard/edge computer vision
- Add PID-based steering correction instead of discrete left/right/center states
- Log sensor data over serial for offline tuning
- Migrate decision logic to an ESP32 for Wi-Fi telemetry

## Author

**Manasvi Gupta** — Electronics & Computer Engineering, Thapar Institute of Engineering & Technology
