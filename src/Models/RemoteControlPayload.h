#ifndef REMOTE_CONTROL_PAYLOAD_H
#define REMOTE_CONTROL_PAYLOAD_H

struct RemoteControlPayload {
    char mode;
    int throttle;
    int steering;
    bool brake;
};

#endif