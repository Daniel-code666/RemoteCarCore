#include "BLEGlobals.h"
#include "BLEConstants.h"

bool deviceConnected = false;
bool showConnMsg = true;

std::string lastPayload = "";
volatile bool hasNewPayload = false;

unsigned long lastControlUpdateTime = 0;

BLECharacteristic remoteControlCharacteristic(REMOTE_CONTROL_CHARACTERISTIC_UUID, BLECharacteristic::PROPERTY_WRITE_NR | BLECharacteristic::PROPERTY_WRITE);

RemoteControlPayload currentPayload = {
    'N', 0, 0, false
};
