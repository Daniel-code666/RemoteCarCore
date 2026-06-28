#ifndef CAR_MOVEMENT_H
#define CAR_MOVEMENT_H
#include "../Models/RemoteControlPayload.h"

class CarMotionController {
    public:
        void Apply(RemoteControlPayload currentPayload);
        void CheckSafety();
};

#endif