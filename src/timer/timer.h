#pragma once

#include <Arduino.h>

class Timer{
    private:
        int time;
        bool active;
        bool alrm;
        unsigned long mils;
    public:
        Timer(int, unsigned long);
        int left();
        void start();
        void stop();
        void tick();
        bool done();
};