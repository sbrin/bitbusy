#include "screens.h"

void connecting(Adafruit_NeoMatrix &matrix){
    matrix.clear();
    matrix.drawBitmap(0, 0, fill, 32, 8, COLOR_ORANGE);
    matrix.drawBitmap(1, 1, wifi, 29, 7, COLOR_TEXT);
    matrix.show();
}

void free(Adafruit_NeoMatrix &matrix, int &frame){
    matrix.clear();
    matrix.drawBitmap(0, 0, fill, 32, 8, COLOR_GREEN);
    if(frame < 103){
        if(frame < 60){
            matrix.drawBitmap(1 - frame, 1, available, 30, 7, COLOR_TEXT);
        }
        else{
            matrix.drawBitmap(103 - frame, 1, available, 30, 7, COLOR_TEXT);
        }

        matrix.drawBitmap(35 - frame, 1, online, 7, 7, COLOR_TEXT);
        matrix.setTextColor(COLOR_TEXT);
        matrix.setTextWrap(false);
        matrix.setFont(&Petme8x8);
        matrix.setCursor(43 - frame, 9);
        matrix.print("WELCOME");
    }
    else if(frame < 140){
        matrix.drawBitmap(1, 1, available, 30, 7, COLOR_TEXT);
    }
    else{
        frame = 0;
        matrix.drawBitmap(1, 1, available, 30, 7, COLOR_TEXT);
    }
    matrix.show();
    frame++;
}

void busy_time(Adafruit_NeoMatrix &matrix, int &frame, int timeleft){
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
    frame++;
}

void busy(Adafruit_NeoMatrix &matrix, int &frame){
    matrix.clear();
    matrix.drawBitmap(0, 0, fill, 32, 8, COLOR_RED);

    if(frame < 70){
        matrix.drawBitmap(-68 + frame, 1, working, 30, 7, COLOR_TEXT);
        matrix.drawBitmap(1 + frame, 1, working, 30, 7, COLOR_TEXT);
        matrix.drawBitmap(-35 + frame, 1, restricted, 7, 7, COLOR_TEXT);
        matrix.drawBitmap(-26 + frame, 1, dnd, 22, 7, COLOR_TEXT);
    }   
    else if (frame < 100){
        matrix.drawBitmap(1, 1, working, 30, 7, COLOR_TEXT);
    }
    else {
        frame = 0;
        matrix.drawBitmap(1, 1, working, 30, 7, COLOR_TEXT);
    }
    
    matrix.show();
    frame++;
}

void running_string(Adafruit_NeoMatrix &matrix, int &frame, String text, int color){
    matrix.clear();
    matrix.drawBitmap(0, 0, fill, 32, 8, color);
    matrix.setFont(&Petme8x8);
    matrix.setTextWrap(false);
    matrix.setTextColor(COLOR_TEXT);
    matrix.setCursor(matrix.width() - frame, 9);
    matrix.print(text);

    int16_t x1, y1;
    uint16_t w, h;

    matrix.getTextBounds(text, 0, 0, &x1, &y1, &w, &h);

    int displayWidth = matrix.width();
    int gap = 3;
    int totalWidth = w + gap;

    int x = displayWidth - frame;

    matrix.setCursor(x, 9); 
    matrix.print(text);

    if (frame >= totalWidth + displayWidth) {
        frame = 0;
    } else {
        frame++;
    }

    matrix.show();
}