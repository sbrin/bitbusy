#include "state.h"

State::State(): state(false), pomodoro(false), busy_timer(false), frame(0), timeleft(1800){}

void State::check(bool active, int time){
    timeleft = time;
    if(active){
        if(timeleft == -1){
            busy_timer = true;
        }
        state = true;
    }
    else{
        state = false;
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