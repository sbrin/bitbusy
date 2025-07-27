#include "state.h"

State::State(): state(false), pomodoro(false), busy_timer(false), frame(0), timeleft(1800), pomocycle(false), settime(1800){}

void State::check(Timer &timer){
    timeleft = timer.left();
    busy_timer = timeleft == -1;
    if(pomodoro){
        if(!timer.busy()){
            pomocycle = !pomocycle;

            if(pomocycle){
                timer.set(settime / 5);
                state = false;
            }
            else{
                timer.set(settime);
                state = true;
            }

            timer.start();
        }
    }
    else{
        state = timer.busy();
    }
}

void State::screen_select(Adafruit_NeoMatrix &matrix){
    if(!state){
        free(matrix, frame);
    }
    else{
        if(!busy_timer){
            busy_time(matrix, frame, timeleft);
        }
        else{
            busy(matrix, frame);
        }    
    } 
}
    
bool State::getPomodoro(){
    return pomodoro;
}

bool State::getBusy(){
    return state;
}

void State::setPomodoro(bool j){
    pomodoro = j;
}

void State::setBusy(bool j){
    state = j;
}

void State::setTime(int j){
    settime = j;
}