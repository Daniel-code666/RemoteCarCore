#include "LedControl.h"
#include "LedGlobals.h"
#include "Arduino.h"
#include "LedConstants.h"

void LedControl::UpdateSportLed() {
    if (currentMode != 'S')
    {
        sportLedState = false;
        SetStatusLed(false);
        return;
    }

    unsigned long now = millis();

    if (now - lastSportLedBlinkTime >= SPORT_LED_BLINK_MS) {
        lastSportLedBlinkTime = now;
        sportLedState = !sportLedState;
        SetStatusLed(sportLedState);
    }
}

void LedControl::SetStatusLed(bool on) {
    digitalWrite(status_led_pin, on ? LOW : HIGH);
}