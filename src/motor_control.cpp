#include <Arduino.h>
#include "motor_control.h"

void motorInit() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  setMotorSpeed(0, 0);
}

// leftSpeed/rightSpeed range: -255 (full reverse) to 255 (full forward)
void setMotorSpeed(int leftSpeed, int rightSpeed) {
  // Left motor
  digitalWrite(IN1, leftSpeed >= 0 ? HIGH : LOW);
  digitalWrite(IN2, leftSpeed >= 0 ? LOW : HIGH);
  analogWrite(ENA, abs(leftSpeed));

  // Right motor
  digitalWrite(IN3, rightSpeed >= 0 ? HIGH : LOW);
  digitalWrite(IN4, rightSpeed >= 0 ? LOW : HIGH);
  analogWrite(ENB, abs(rightSpeed));
}

void executeMotion(MotionCommand cmd, int speed) {
  switch (cmd) {
    case MOVE_FORWARD:
      setMotorSpeed(speed, speed);
      break;
    case MOVE_REVERSE:
      setMotorSpeed(-speed, -speed);
      break;
    case TURN_LEFT:
      setMotorSpeed(-speed / 2, speed);
      break;
    case TURN_RIGHT:
      setMotorSpeed(speed, -speed / 2);
      break;
    case STOP:
    default:
      setMotorSpeed(0, 0);
      break;
  }
}
