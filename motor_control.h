#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

// Pin definitions — update to match your wiring (see docs/circuit_diagram.md)
#define ENA 9
#define ENB 10
#define IN1 7
#define IN2 8
#define IN3 11
#define IN4 12

enum MotionCommand {
  MOVE_FORWARD,
  MOVE_REVERSE,
  TURN_LEFT,
  TURN_RIGHT,
  STOP
};

void motorInit();
void executeMotion(MotionCommand cmd, int speed);
void setMotorSpeed(int leftSpeed, int rightSpeed);

#endif
