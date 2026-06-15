#ifndef PAYLOAD_PARSER_H
#define PAYLOAD_PARSER_H

#include <Arduino.h>
#include "../Models/RemoteControlPayload.h"

// convierte la entrada del comando en un objeto para trabajar mejor
bool parseRemoteControlPayload(const std::string& rawPayload, RemoteControlPayload& output);

#endif