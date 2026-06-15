#ifndef SG_DIRECTION_H
#define SG_DIRECTION_H

#include <Arduino.h>
#include <ESP32Servo.h>
#include "../Models/RemoteControlPayload.h"

class SGCarDirection {
    public:
        void SetDirection(RemoteControlPayload currentPayload);
};

#endif