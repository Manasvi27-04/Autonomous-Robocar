/*
  Autonomous Robocar — Main Control Loop
  ---------------------------------------
  Fuses IR line-following input with ultrasonic obstacle detection
  to drive a differential-wheeled robot along a path while avoiding
  obstacles in real time.

  Author: Manasvi Gupta
*/

#include "motor_control.h"
#include "ir_sensor.h"
#include "ultrasonic.h"

const int BASE_SPEED = 150;      // 0-255
const int TURN_SPEED = 130;      // speed used while correcting/turning

void setup() {
  Serial.begin(9600);
  motorInit();
  irSensorInit();
  ultrasonicInit();
}

void loop() {
  // 1. Obstacle avoidance takes priority
  if (obstacleDetected()) {
    handleObstacle();
    return;
  }

  // 2. Otherwise, follow the line
  LinePosition pos = readLinePosition();
  switch (pos) {
    case ON_LINE_CENTER:
      executeMotion(MOVE_FORWARD, BASE_SPEED);
      break;
    case ON_LINE_LEFT:
      executeMotion(TURN_LEFT, TURN_SPEED);
      break;
    case ON_LINE_RIGHT:
      executeMotion(TURN_RIGHT, TURN_SPEED);
      break;
    case OFF_LINE:
    default:
      // Lost the line — stop and could trigger a search routine
      executeMotion(STOP, 0);
      break;
  }

  delay(20); // small loop delay for sensor stability
}

void handleObstacle() {
  executeMotion(STOP, 0);
  delay(200);
  executeMotion(MOVE_REVERSE, TURN_SPEED);
  delay(300);
  executeMotion(TURN_RIGHT, TURN_SPEED);
  delay(400);
  executeMotion(STOP, 0);
}
