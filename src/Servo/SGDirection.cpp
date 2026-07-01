#include "SGDirection.h"
#include "SGGlobals.h"
#include "Servo/SGConstants.h"


void SGCarDirection::SetDirection(int steering)
{
    int steeringConstraint = constrain(steering, -100, 100);

    int servoAngle = SERVO_CENTER;

    if (steeringConstraint < 0) {
        // Palanca hacia la izquierda
        servoAngle = map(
            steeringConstraint,
            -100,
            0,
            APP_LEFT_SERVO_ANGLE,
            SERVO_CENTER
        );
    } 
    else if (steeringConstraint > 0) {
        // Palanca hacia la derecha
        servoAngle = map(
            steeringConstraint,
            0,
            100,
            SERVO_CENTER,
            APP_RIGHT_SERVO_ANGLE
        );
    }

    if (servoAngle == lastServoAngle) {
        return;
    }

    steeringServo.write(servoAngle);
    lastServoAngle = servoAngle;
}