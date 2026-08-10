#include <Arduino.h>
#include "ir_sensor.h"

void irSensorInit() {
  pinMode(IR_LEFT_PIN, INPUT);
  pinMode(IR_CENTER_PIN, INPUT);
  pinMode(IR_RIGHT_PIN, INPUT);
}

// Assumes digital IR modules: LOW = line detected, HIGH = no line
// (invert the logic below if your modules behave the opposite way)
LinePosition readLinePosition() {
  bool left   = digitalRead(IR_LEFT_PIN)   == LOW;
  bool center = digitalRead(IR_CENTER_PIN) == LOW;
  bool right  = digitalRead(IR_RIGHT_PIN)  == LOW;

  if (center) return ON_LINE_CENTER;
  if (left)   return ON_LINE_LEFT;
  if (right)  return ON_LINE_RIGHT;
  return OFF_LINE;
}
