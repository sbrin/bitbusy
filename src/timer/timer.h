#pragma once

#include <Arduino.h>

class Timer{
    private:
        int time;
        bool active;
        unsigned long mils;
    public:
        Timer(int);
        int left();
        void start();
        void set(int);
        void stop();
        void tick();
        bool busy();
        void refresh();
};