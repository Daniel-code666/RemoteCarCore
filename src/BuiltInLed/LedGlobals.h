#ifndef LED_GLOBALS_H
#define LED_GLOBALS_H
#include "LedControl.h"

extern bool sportLedState;
extern unsigned long lastSportLedBlinkTime;
extern char currentMode;
extern int status_led_pin;
extern LedControl ledControl;

#endif