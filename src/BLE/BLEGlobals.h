#ifndef BLE_GLOBALS_H
#define BLE_GLOBALS_H

#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include "../Models/RemoteControlPayload.h"

// bandera para saber si el dispositivo BLE está conectado o no
extern bool deviceConnected;
// bandera para mostrar mensaje de conexión
extern bool showConnMsg;

// variable para almacenar el último payload recibido
extern std::string lastPayload;
// bandera que indica si hay un nuevo payload diferente al anterior
extern bool hasNewPayload;

// variable que almacena último tiempo del impresión en la consola
extern unsigned long lastPrintTime;
// característica BLE global
extern BLECharacteristic remoteControlCharacteristic;

// objeto de payload
extern RemoteControlPayload currentPayload;

#endif