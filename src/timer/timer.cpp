#include "timer.h"

Timer::Timer(int seconds, unsigned long init_millis): time(seconds), mils(init_millis), active(false) {}

void Timer::tick(){
    if(active && millis() - mils >= 1000){
        time += 1;
        mils = millis();
    }
}

void Timer::start(){
    active = true;
}

void Timer::stop(){
    active = false;
}