#include "screens.h"

void free(Adafruit_NeoMatrix &matrix, int &frame){
    matrix.clear();
    matrix.drawBitmap(0, 0, fill, 32, 8, COLOR_GREEN);
    if(frame < 101){
        if(frame < 60){
            matrix.drawBitmap(1 + frame, 1, available, 30, 7, COLOR_TEXT);
        }
        else{
            matrix.drawBitmap(-100 + frame, 1, available, 30, 7, COLOR_TEXT);
        }
        matrix.drawCircle(-62, 4, 3, COLOR_TEXT);
        matrix.drawBitmap(-66 + frame, 1, online, 7, 7, COLOR_TEXT);
        matrix.setTextColor(COLOR_TEXT);
        matrix.setTextWrap(false);
        matrix.setFont(&Petme8x8);
        matrix.setCursor(-58 + frame, 9);
        matrix.print("WELCOME");
    }
    else if(frame < 121){
        matrix.drawBitmap(1, 1, available, 30, 7, COLOR_TEXT);
    }
    else{
        frame = 0;
        matrix.drawBitmap(1, 1, available, 30, 7, COLOR_TEXT);
    }
    matrix.show();
    frame += 1;
}

void busy(Adafruit_NeoMatrix &matrix, int &frame, int timeleft){
    matrix.clear();
    matrix.drawBitmap(0, 0, fill, 32, 8, COLOR_RED);
    int minutes = timeleft / 60;
    int seconds = timeleft % 60;

    matrix.setTextColor(COLOR_TEXT);
    matrix.setTextWrap(false);
    matrix.setFont();
    
    String time = String(minutes);
    if (minutes < 10) time = "0" + time;

    time += ":";

    if (seconds < 10) time += "0";
    time += String(seconds);

    if(frame < 68){
        if(frame < 60){
            matrix.drawBitmap(1 + frame, 1, working, 30, 7, COLOR_TEXT);
        }
        else{
            matrix.drawBitmap(-100 + frame, 1, working, 30, 7, COLOR_TEXT);
        }
        matrix.drawBitmap(-35 + frame, 1, restricted, 7, 7, COLOR_TEXT);
        matrix.drawBitmap(-26 + frame, 1, dnd, 22, 7, COLOR_TEXT);
        matrix.setCursor(-67 + frame, 1);
        matrix.print(time);
    }   
    else if(frame < 101){
        matrix.setCursor(1, 1);
        matrix.print(time);
    }
    else if(frame < 136){
        matrix.drawBitmap(-135 + frame, 1, working, 30, 7, COLOR_TEXT);
        matrix.setCursor(-100 + frame, 1);
        matrix.print(time);
    }
    else if(frame < 168){
        matrix.drawBitmap(1, 1, working, 30, 7, COLOR_TEXT);
    }
    else{
        frame = 0;
        matrix.drawBitmap(1, 1, working, 30, 7, COLOR_TEXT);
    }
    
    matrix.show();
    frame += 1;
}

void select(Adafruit_NeoMatrix &matrix, int &frame, bool state, int timeleft){
    if(!state){
        free(matrix, frame);
    }
    else{
        if(timeleft != -1){
            busy(matrix, frame, timeleft);
        }    
    }
}