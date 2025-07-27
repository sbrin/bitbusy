#pragma once

#include <Arduino.h>

class Timer{
    private:
        int time;
        bool active;
        bool busy;
        bool pomodoro;
        unsigned long mils;
    public:
        Timer(int, unsigned long);
        int left();
        void start();
        void set(int);
        void set_busy(bool);
        void set_pomodoro(bool);
        void stop();
        void tick();
        bool state();
        void refresh();
};