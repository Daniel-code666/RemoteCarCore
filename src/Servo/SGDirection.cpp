#include "SGDirection.h"
#include "SGGlobals.h"
#include "Servo/SGConstants.h"


void SGCarDirection::SetDirection(int steering)
{
    int steeringConstraint = constrain(steering, -100, 100);

    int servoAngle = SERVO_CENTER + ((steeringConstraint * SERVO_MAX_OFFSET) / 100);

    if (servoAngle == lastServoAngle) return;

    steeringServo.write(servoAngle);
    lastServoAngle = servoAngle;
}