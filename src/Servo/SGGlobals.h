#ifndef SG_GLOBALS_H
#define SG_GLOBALS_H

#include <ESP32Servo.h>

class SGCarDirection;

extern Servo steeringServo;
extern int currentSteering;
extern int currentServoAngle;

extern SGCarDirection sgCarDirection;


#endif