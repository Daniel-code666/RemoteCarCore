#include "SGGlobals.h"
#include "SGConstants.h"
#include "SGDirection.h"

Servo steeringServo;
int currentSteering = 0;
int currentServoAngle = SERVO_CENTER;

SGCarDirection sgCarDirection = SGCarDirection();
