#pragma once

#include <Arduino.h>
#include "timer/timer.h"
#include "screens/screens.h"

class State{
    bool state;
    bool running;
    bool busy_timer;
    bool pomodoro;
    bool pomocycle;
    String text;
    int color;
    int frame;
    int settime;
    int timeleft;
    public:
        State();
        void check(Timer&);
        void setBusy(bool);
        void setPomodoro(bool);
        void setTime(int);
        void setColor(int);
        void setText(String);
        void setRunning(bool);
        bool getBusy();
        bool getPomodoro();
        int getColor();
        String getText();
        bool getRunning();
        int getSettime();
        void screen_select(Adafruit_NeoMatrix &matrix);
};