#include <Arduino.h>
#include "MotorControl.h"
#include "MotorConstants.h"

void MotorControl::Begin() {
    ledcSetup(MOTOR_RPWM_CHANNEL, MOTOR_PWM_FREQ, MOTOR_PWM_RESOLUTION);
    ledcSetup(MOTOR_LPWM_CHANNEL, MOTOR_PWM_FREQ, MOTOR_PWM_RESOLUTION);

    ledcAttachPin(MOTOR_RPWM_PIN, MOTOR_RPWM_CHANNEL);
    ledcAttachPin(MOTOR_LPWM_PIN, MOTOR_LPWM_CHANNEL);

    Stop();
}

void MotorControl::SetThrottle(int throttle, char mode) {
    int throttleConstraint = constrain(throttle, -100, 100);

    int maxPwm = GetMaxPwmByMode(mode);

    int pwm = map(abs(throttleConstraint), 1, 100, 0, maxPwm);

    if (throttleConstraint > 0) 
    {
        Forward(pwm, maxPwm);
    }
    else 
    {
        Backward(pwm, maxPwm);
    }
}

void MotorControl::Brake(char mode) {
    int maxPwm = GetMaxPwmByMode(mode);

    if (lastDirection > 0) 
    {
        // Si venía avanzando, frena aplicando reversa limitada
        Backward(MOTOR_BRAKE_PWM, maxPwm);
        return;
    }

    if (lastDirection < 0) 
    {
        // Si venía en reversa, frena aplicando avance limitado
        Forward(MOTOR_BRAKE_PWM, maxPwm);
        return;
    }

    Stop();
}

void MotorControl::Forward(int pwm, int maxPwm)
{
    pwm = constrain(pwm, 0, maxPwm);

    ledcWrite(MOTOR_LPWM_CHANNEL, 0);
    ledcWrite(MOTOR_RPWM_CHANNEL, pwm);

    currentDirection = pwm > 0 ? 1 : 0;

    if (pwm > 0) {
        lastMoveDirection = 1;
    }

    lastPwm = pwm;
}

void MotorControl::Backward(int pwm, int maxPwm)
{
    pwm = constrain(pwm, 0, maxPwm);

    ledcWrite(MOTOR_RPWM_CHANNEL, 0);
    ledcWrite(MOTOR_LPWM_CHANNEL, pwm);

    currentDirection = pwm > 0 ? -1 : 0;

    if (pwm > 0) {
        lastMoveDirection = -1;
    }

    lastPwm = pwm;
}

void MotorControl::Stop() {
    ledcWrite(MOTOR_RPWM_CHANNEL, 0);
    ledcWrite(MOTOR_LPWM_CHANNEL, 0);

    lastPwm = 0;
    lastDirection = 0;
}

int MotorControl::GetMaxPwmByMode(char mode) {
    if (mode == 'S') return MOTOR_SPORT_MAX_PWM;

    return MOTOR_MAX_PWM;
}

