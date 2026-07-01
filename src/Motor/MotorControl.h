#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

class MotorControl {
    public:
        void Begin();
        void SetThrottle(int throttle, char mode);
        void Brake(char mode);
        void Stop();
    private:
        int lastPwm = -1;
        int lastDirection = 0;
        int currentDirection = 0;
        int lastMoveDirection = 0;

        void Forward(int pwm, int maxPwm);
        void Backward(int pwm, int maxPwm);
        int GetMaxPwmByMode(char mode);
};

#endif
