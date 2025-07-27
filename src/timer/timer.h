#pragma once

#include <Arduino.h>

class Timer{
    private:
        int time;
        bool pomodoro;
        bool active;
        unsigned long mils;
        bool& state;
    public:
        Timer(int, unsigned long, bool&);
        int left();
        void start();
        void set(int);
        void stop();
        void tick();
        bool busy();
        void refresh();
};