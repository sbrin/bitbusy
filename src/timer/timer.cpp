#include "timer.h"

Timer::Timer(int seconds, unsigned long init_millis): time(seconds), mils(init_millis), active(false), alrm(false) {}

int Timer::left(){
    return time;
}

bool Timer::done(){
    return alrm;
}

void Timer::tick(){
    if(active && millis() - mils >= 1000){
        time -= 1;
        mils = millis();

        if(time <= 0){
            active = false;
            alrm = true;
        }
    }
}

void Timer::start(){
    if(!alrm){
        active = true;
    }
}

void Timer::stop(){
    if(!alrm){
        active = false;
    }
}