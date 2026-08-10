#include <Arduino.h>
#include "ultrasonic.h"

void ultrasonicInit() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

long readDistanceCM() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000); // 30ms timeout (~5m range)
  if (duration == 0) return -1; // no echo received

  long distanceCM = duration * 0.0343 / 2;
  return distanceCM;
}

bool obstacleDetected() {
  long d = readDistanceCM();
  return (d > 0 && d <= OBSTACLE_DISTANCE_CM);
}
