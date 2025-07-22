#include "timer.h"

Timer::Timer(int seconds, unsigned long init_millis): time(seconds), mils(init_millis), active(false) {}

int Timer::left(){
    return time;
}

bool Timer::busy(){ 
    return active;
}

void Timer::refresh(){
    mils = millis();
}

void Timer::tick(){
    if(time != -1){
        if(active && millis() - mils >= 1000){
            time -= 1;
            mils = millis();

            if(time <= 0){
                active = false;
            }
        }
    }
}

void Timer::start(){
    active = true;
    refresh();
}

void Timer::stop(){
    active = false;
}

void Timer::set(int newtime){
    if(!active){
        time = newtime;
    }
}