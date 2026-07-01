#ifndef MOTOR_CONSTANTS_H
#define MOTOR_CONSTANTS_H

constexpr int MOTOR_RPWM_PIN = 5;
constexpr int MOTOR_LPWM_PIN = 6;

constexpr int MOTOR_PWM_FREQ = 1000;
constexpr int MOTOR_PWM_RESOLUTION = 8;

constexpr int MOTOR_RPWM_CHANNEL = 4;
constexpr int MOTOR_LPWM_CHANNEL = 5;

constexpr int MOTOR_MIN_PWM = 25;
constexpr int MOTOR_MAX_PWM = 100;
constexpr int MOTOR_SPORT_MAX_PWM = 115;

constexpr int MOTOR_BRAKE_PWM = 45;

constexpr unsigned long CONTROL_TIMEOUT_MS = 300;

#endif