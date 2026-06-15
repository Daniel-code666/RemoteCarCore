#include "PayloadParser.h"

static bool ModePartValidation(String modePart)
{
    if (modePart.length() != 1 || (modePart.charAt(0) != 'N' && modePart.charAt(0) != 'S')) return false;

    return true;
}

static bool MovementCommandsValidations(int throttle, int steering, int brake)
{
    if (throttle < -100 || throttle > 100) {
        return false;
    }

    if (steering < -100 || steering > 100) {
        return false;
    }

    if (brake != 0 && brake != 1) {
        return false;
    }

    return true;
}

static RemoteControlPayload& BuildPayloadObject(char mode, int throttle, int steering, int brake, RemoteControlPayload& output)
{
    output.mode = mode;
    output.throttle = throttle;
    output.steering = steering;
    output.brake = brake == 1;

    return output;
}

bool parseRemoteControlPayload(const std::string& rawPayload, RemoteControlPayload& output)
{
    // ejemplo del payload ('N', 0, 0, false)
    // N/S = modo
    // throttle = -100 a 100
    // steering = -100 a 100
    // brake = 0 o 1

    // valida que el payload contenga algo
    if (rawPayload.length() == 0) return false;

    // se convierte un string de c++ a arduino (tipo C)
    String payload = String(rawPayload.c_str());
    payload.trim();

    int firstComma = payload.indexOf(',');
    int secondComma = payload.indexOf(',', firstComma + 1);
    int thirdComma = payload.indexOf(',', secondComma + 1);

    // si el payload entrante está incompleto por algún motivo no lo procesa
    if (firstComma == -1 || secondComma == -1 || thirdComma == -1) return false;

    String modePart = payload.substring(0, firstComma);
    String throttlePart = payload.substring(firstComma + 1, secondComma);
    String steeringPart = payload.substring(secondComma + 1, thirdComma);
    String brakePart = payload.substring(thirdComma + 1);

    modePart.trim();
    throttlePart.trim();
    steeringPart.trim();
    brakePart.trim();

    if (!ModePartValidation(modePart)) return false;

    char mode = modePart.charAt(0);
    
    int throttle = throttlePart.toInt();
    int steering = steeringPart.toInt();
    int brake = brakePart.toInt();

    if (!MovementCommandsValidations(throttle, steering, brake)) return false;

    BuildPayloadObject(mode, throttle, steering, brake, output);

    return true;
}