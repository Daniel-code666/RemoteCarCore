#ifndef BLE_CONSTANTS_H
#define BLE_CONSTANTS_H

// definiciones del server BLE
constexpr const char* BLE_SERVER_NAME = "BLE_Remote_Car";
// definición del servicio
constexpr const char* SERVICE_UUID = "65215951-565f-4530-ae33-166245c668cf";
// defición de la característica
constexpr const char* REMOTE_CONTROL_CHARACTERISTIC_UUID = "3986086c-190f-4de8-8164-24abdf042717";
// valor con el cual se establece un intervalo para mostrar mensajes en la consola
constexpr unsigned long PRINT_INTERVAL_MS = 100;

#endif