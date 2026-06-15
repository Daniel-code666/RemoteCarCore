#ifndef BLE_REMOTE_CONTROL_CALLBACKS_HANDLER_H
#define BLE_REMOTE_CONTROL_CALLBACKS_HANDLER_H

#include <Arduino.h>
#include <BLEServer.h>

class RemoteControlCallbackHandler: public BLECharacteristicCallbacks {
    public:
        void onWrite(BLECharacteristic* pCharacteristic) override;
};

#endif