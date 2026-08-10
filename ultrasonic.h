#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#define TRIG_PIN 5
#define ECHO_PIN 6
#define OBSTACLE_DISTANCE_CM 20

void ultrasonicInit();
long readDistanceCM();
bool obstacleDetected();

#endif
