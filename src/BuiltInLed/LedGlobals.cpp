#include "Arduino.h"
#include "LedGlobals.h"

bool sportLedState = false;
unsigned long lastSportLedBlinkTime = 0;
char currentMode = 'N';
int status_led_pin = 8;

LedControl ledControl = LedControl();