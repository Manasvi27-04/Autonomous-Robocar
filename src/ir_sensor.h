#ifndef IR_SENSOR_H
#define IR_SENSOR_H

#define IR_LEFT_PIN   2
#define IR_CENTER_PIN 3
#define IR_RIGHT_PIN  4

enum LinePosition {
  ON_LINE_CENTER,
  ON_LINE_LEFT,
  ON_LINE_RIGHT,
  OFF_LINE
};

void irSensorInit();
LinePosition readLinePosition();

#endif
