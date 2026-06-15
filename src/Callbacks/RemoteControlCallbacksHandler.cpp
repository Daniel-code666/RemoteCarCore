#include "RemoteControlCallbacksHandler.h"
#include "../BLE/BLEGlobals.h"
#include "../Utils/PayloadParser.h"

void RemoteControlCallbackHandler::onWrite(BLECharacteristic* pCharacteristic)
{
    // obtiene el valor de los datos entrantes a la característica BLE
    std::string payload = pCharacteristic->getValue();
    lastPayload = payload;

    RemoteControlPayload parsedPayload;

    // parsea la entrada a un objeto
    bool parsed = parseRemoteControlPayload(lastPayload, parsedPayload);

    if (!parsed)
    {
        Serial.print("Payload inválido: ");
        Serial.println(payload.c_str());
        return;
    }

    // establece el valor con el objeto parseado
    currentPayload = parsedPayload;

    hasNewPayload = true;
}
