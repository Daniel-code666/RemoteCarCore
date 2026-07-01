#ifndef SG_DIRECTION_H
#define SG_DIRECTION_H

#include "../Models/RemoteControlPayload.h"

class SGCarDirection {
    public:
        void SetDirection(int steering);
    private:
        int lastServoAngle = -1;
};

#endif