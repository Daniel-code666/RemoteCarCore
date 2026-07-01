#ifndef LED_CONTROL_H
#define LED_CONTROL_H

class LedControl {
    public:
        void UpdateSportLed();
    private:
        void SetStatusLed(bool on);
};

#endif