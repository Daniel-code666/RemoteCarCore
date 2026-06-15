#ifndef BLE_SERVER_CALLBACKS_HANDLER_H
#define BLE_SERVER_CALLBACKS_HANDLER_H

#include <Arduino.h>
#include <BLEServer.h>

// clase para indicarle al servidor BLE que hacer cuando un cliente se conecta o desconecta. Esta clase hereda de BLEServerCallbacks, lo que significa 
// que puede manejar eventos relacionados con el servidor BLE, como conexiones y desconexiones de clientes. En este caso, se implementan los métodos onConnect 
// y onDisconnect para actualizar la bandera deviceConnected cuando un cliente se conecta o desconecta del servidor BLE.
class BleServerCallbacksHandler : public BLEServerCallbacks {
    public:
        void onConnect(BLEServer* pServer) override;
        void onDisconnect(BLEServer* pServer) override;
};

#endif