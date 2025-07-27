#include "timer.h"

Timer::Timer(int seconds, unsigned long init_millis, bool& busy): time(seconds), mils(init_millis), state(busy), active(false) {}

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
                stop();
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
    state = false;
}

void Timer::set(int newtime){
    if(!active){
        time = newtime;
    }
}