# Circuit / Wiring Reference

> Update this file with your actual wiring once you re-confirm your hardware setup or upload your original diagram to `images/`.

## Components

- Arduino Uno (or Atmega32 dev board)
- L298N Dual H-Bridge Motor Driver
- 2–3x IR Sensor Modules (line following)
- 1x HC-SR04 Ultrasonic Sensor
- Camera Module (e.g., ESP32-CAM or USB camera, depending on build)
- 2x DC Geared Motors + Wheels
- Li-ion battery pack (7.4V–12V typical) + voltage regulation as needed

## Suggested Pin Mapping (edit to match your build)

| Arduino Pin | Connected To |
|---|---|
| D2 | IR Sensor — Left |
| D3 | IR Sensor — Center |
| D4 | IR Sensor — Right |
| D5 | HC-SR04 — Trig |
| D6 | HC-SR04 — Echo |
| D9  (PWM) | L298N — ENA (Left motor speed) |
| D10 (PWM) | L298N — ENB (Right motor speed) |
| D7 | L298N — IN1 |
| D8 | L298N — IN2 |
| D11 | L298N — IN3 |
| D12 | L298N — IN4 |
| 5V / GND | Shared logic power rail |

## Power Notes

- Motors are powered separately from the Arduino logic rail (shared ground is required).
- The L298N's 5V regulator output can power the Arduino if the input voltage is within its supported range — otherwise power the Arduino separately.

## Diagram

Add a photo or Fritzing/EasyEDA export of your actual wiring to `images/circuit.png` and reference it here:

```markdown
![Circuit Diagram](../images/circuit.png)
```
