#include "BleServerCallbacksHandler.h"
#include "../BLE/BLEGlobals.h"
#include "../Servo/SGGlobals.h"
#include "../Servo/SGConstants.h"

void BleServerCallbacksHandler::onConnect(BLEServer* pServer) 
{
    deviceConnected = true;
    Serial.println("Cliente conectado al servidor BLE");
}

void BleServerCallbacksHandler::onDisconnect(BLEServer* pServer)
{
    deviceConnected = false;
    Serial.println("Cliente desconectado del servidor BLE");

    pServer->getAdvertising()->start();
    Serial.println("Reiniciando el adverising");

    steeringServo.write(SERVO_CENTER);
    currentSteering = 0;
    currentServoAngle = SERVO_CENTER;
}