#include "timer.h"

Timer::Timer(int seconds, unsigned long init_millis): time(seconds), mils(init_millis), active(false), alrm(false) {}

int Timer::left(){
    return time;
}

bool Timer::busy(){ 
    return (alrm) or (time == 0);
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

void Timer::set(int newtime){
    if(!active){
        time = newtime;
    }
}