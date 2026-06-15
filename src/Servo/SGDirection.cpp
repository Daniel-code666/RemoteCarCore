#include "SGDirection.h"

void SGCarDirection::SetDirection(RemoteControlPayload currentPayload)
{
    Serial.print("último payload recibido desde SGDirection: ");
    Serial.print("Modo: ");
    Serial.println(currentPayload.mode);

    Serial.print("Throttle: ");
    Serial.println(currentPayload.throttle);

    Serial.print("Steering: ");
    Serial.println(currentPayload.steering);

    Serial.print("Brake: ");
    Serial.println(currentPayload.brake ? "Activo" : "Inactivo");
}