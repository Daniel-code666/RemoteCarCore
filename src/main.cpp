#include <Arduino.h>
#include <ESP32Servo.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include "BLE/BleGlobals.h"
#include "BLE/BLEConstants.h"
#include "Callbacks/BleServerCallbacksHandler.h"
#include "Callbacks/RemoteControlCallbacksHandler.h"

void setup() {
    Serial.begin(115200);

    // crea el nombre del servidor BLE
    BLEDevice::init(BLE_SERVER_NAME);

    // crea el servidor BLE
    // puntero que guarda la dirección en memoria del servidor creado. createServer devuelve la dirección en memoria del servidor creado
    BLEServer *pServer = BLEDevice::createServer();
    // el operador -> se utiliza para acceder a los miembros de un objeto a través de un puntero. En este caso, se accede al método setCallbacks del objeto pServer
    // el callback se establece para manejar los eventos de conexión y desconexión del cliente BLE, en este caso usa la clase MyServerCallbacks
    pServer->setCallbacks(new BleServerCallbacksHandler);

    // crea el servicio BLE
    BLEService *bleService = pServer->createService(SERVICE_UUID);

    // Creación del descriptor y caracaterística para el control remoto
    bleService->addCharacteristic(&remoteControlCharacteristic);
    remoteControlCharacteristic.setCallbacks(new RemoteControlCallbackHandler());

    // inicia el servicio BLE
    bleService->start();

    BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
    pAdvertising->addServiceUUID(SERVICE_UUID);
    pServer->getAdvertising()->start();
    Serial.println("Servicio BLE iniciado");
    Serial.println("Esperando a conexión con el cliente");
}

void loop() {
    if (hasNewPayload && millis() - lastPrintTime >= PRINT_INTERVAL_MS) {
        Serial.print("último payload recibido: ");
        Serial.println(lastPayload.c_str());
        hasNewPayload = false;
        lastPrintTime = millis();
    }

    delay(5);
}