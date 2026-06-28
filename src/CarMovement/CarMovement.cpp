#include "CarMotionController.h"
#include "Servo/SGGlobals.h"
#include "Servo/SGDirection.h"
#include "../BLE/BLEGlobals.h"

void CarMotionController::Apply(RemoteControlPayload currentPayload)
{
    sgCarDirection.SetDirection(currentPayload.steering);
}

void CarMotionController::CheckSafety()
{
    if(!deviceConnected)
    {
        sgCarDirection.SetDirection(0);
    }
}