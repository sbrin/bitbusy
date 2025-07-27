#pragma once

#include <Arduino.h>
#include "timer/timer.h"
#include "screens/screens.h"

class State{
    bool state;
    bool busy_timer;
    bool pomodoro;
    bool pomocycle;
    int frame;
    int settime;
    int timeleft;
    public:
        State();
        void check(Timer&);
        void setBusy(bool);
        void setPomodoro(bool);
        void setTime(int);
        bool getBusy();
        bool getPomodoro();
        void screen_select(Adafruit_NeoMatrix &matrix);
};