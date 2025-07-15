#pragma once

#include <Arduino.h>

class Timer{
    private:
        int time;
        bool active;
        unsigned long mils;
    public:
        Timer(int, unsigned long);
        void start();
        void stop();
        void tick();
};