#include "RemoteControlCallbacksHandler.h"
#include "../BLE/BLEGlobals.h"

void RemoteControlCallbackHandler::onWrite(BLECharacteristic* pCharacteristic)
{
    std::string payload = pCharacteristic->getValue();

    if (payload.length() == 0)
        return;

    lastPayload = payload;
    hasNewPayload = true;
}
