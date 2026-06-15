#include <Arduino.h>
#include <ESP32Servo.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

// definiciones del server BLE
#define bleServerName "BLE_Remote_Car"
#define SERVICE_UUID "65215951-565f-4530-ae33-166245c668cf"

// Características BLE
BLECharacteristic remoteControlCharacteristic("3986086c-190f-4de8-8164-24abdf042717", BLECharacteristic::PROPERTY_WRITE_NR | BLECharacteristic::PROPERTY_WRITE);

// bandera para saber si el dispositivo BLE está conectado o no
bool deviceConnected = false;

// bandera para mostrar mensaje de conexión
bool showConnMsg = true;

// clase para indicarle al servidor BLE que hacer cuando un cliente se conecta o desconecta. Esta clase hereda de BLEServerCallbacks, lo que significa 
// que puede manejar eventos relacionados con el servidor BLE, como conexiones y desconexiones de clientes. En este caso, se implementan los métodos onConnect 
// y onDisconnect para actualizar la bandera deviceConnected cuando un cliente se conecta o desconecta del servidor BLE.
class MyServerCallbacks: public BLEServerCallbacks {
    // método que se llama cuando un cliente se conecta al servidor BLE
    // recibe un puntero al servidor BLE que ha recibido la conexión
    void onConnect(BLEServer* pServer) {
        deviceConnected = true;
        Serial.println("Cliente conectado al servidor BLE");
    }

    void onDisconnect(BLEServer* pServer) {
        deviceConnected = false;
        Serial.println("Cliente desconectado del servidor BLE");
        pServer->getAdvertising()->start();
        Serial.println("Reiniciando el advertising");
    }
};

class RemoteControlCallback: public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic* pCharacteristic) {
        std::string payload = pCharacteristic->getValue();
        
        if (payload.length() == 0)
            return;
        
        Serial.print("Payload recibido: ");
        Serial.println(payload.c_str());
    }
};

void setup() {
    Serial.begin(115200);

    // crea el nombre del servidor BLE
    BLEDevice::init(bleServerName);

    // crea el servidor BLE
    // puntero que guarda la dirección en memoria del servidor creado. createServer devuelve la dirección en memoria del servidor creado
    BLEServer *pServer = BLEDevice::createServer();
    // el operador -> se utiliza para acceder a los miembros de un objeto a través de un puntero. En este caso, se accede al método setCallbacks del objeto pServer
    // el callback se establece para manejar los eventos de conexión y desconexión del cliente BLE, en este caso usa la clase MyServerCallbacks
    pServer->setCallbacks(new MyServerCallbacks());

    // crea el servicio BLE
    BLEService *bleService = pServer->createService(SERVICE_UUID);

    // Creación del descriptor y caracaterística para el control remoto
    bleService->addCharacteristic(&remoteControlCharacteristic);
    remoteControlCharacteristic.setCallbacks(new RemoteControlCallback());

    // inicia el servicio BLE
    bleService->start();

    BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
    pAdvertising->addServiceUUID(SERVICE_UUID);
    pServer->getAdvertising()->start();
    Serial.println("Servicio BLE iniciado");
    Serial.println("Esperando a conexión con el cliente");
}

void loop() {
    if (deviceConnected) 
    {
        // aquí se pueden enviar datos al cliente BLE o realizar otras acciones
        if (showConnMsg) {
            Serial.println("Cliente conectado al servidor BLE");
            showConnMsg = false;
        }
    }
    else 
    {
        // aquí se pueden realizar acciones cuando no hay ningún cliente conectado al servidor BLE
        if (!showConnMsg) {
            Serial.println("Cliente desconectado del servidor BLE");
            showConnMsg = true;
        }
    }
}