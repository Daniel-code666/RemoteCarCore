#include "CarMotionController.h"
#include "Servo/SGGlobals.h"
#include "Servo/SGDirection.h"
#include "../BLE/BLEGlobals.h"
#include "Motor/MotorControl.h"
#include "Motor/MotorGlobals.h"
#include "Motor/MotorConstants.h"

void CarMotionController::Apply(RemoteControlPayload currentPayload)
{
    sgCarDirection.SetDirection(currentPayload.steering);

    if (currentPayload.brake) 
    {
        motorControl.Brake(currentPayload.mode);
        return;
    }

    motorControl.SetThrottle(currentPayload.throttle, currentPayload.mode);
}

void CarMotionController::CheckSafety()
{
    if(!deviceConnected)
    {
        sgCarDirection.SetDirection(0);
        motorControl.Stop();
        return;
    }
}