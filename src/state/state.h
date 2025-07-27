#pragma once

#include <Arduino.h>
#include "timer/timer.h"
#include "screens/screens.h"

class State{
    bool state;
    bool busy_timer;
    bool pomodoro;
    int frame;
    int timeleft;
    public:
        State();
        void check(bool, int);
        void setBusy(bool);
        void setPomodoro(bool);
        bool getBusy();
        bool getPomodoro();
        void screen_select(Adafruit_NeoMatrix &matrix);
};