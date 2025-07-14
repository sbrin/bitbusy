#include "screens.h"

void free(Adafruit_NeoMatrix &matrix, int &frame){
    matrix.clear();
    if(frame < 101){
        if(frame < 60){
            matrix.drawBitmap(1 + frame, 1, available, 30, 7, COLOR_GREEN);
        }
        else{
            matrix.drawBitmap(-100 + frame, 1, available, 30, 7, COLOR_GREEN);
        }
        matrix.drawCircle(-62, 4, 3, COLOR_GREEN);
        matrix.drawBitmap(-66 + frame, 1, online, 7, 7, COLOR_GREEN);
        matrix.setTextColor(COLOR_GREEN);
        matrix.setTextWrap(false);
        matrix.setFont(&Petme8x8);
        matrix.setCursor(-58 + frame, 9);
        matrix.print("WELCOME");
    }
    else if(frame < 121){
        matrix.drawBitmap(1, 1, available, 30, 7, COLOR_GREEN);
    }
    else{
        frame = 0;
        matrix.drawBitmap(1, 1, available, 30, 7, COLOR_GREEN);
    }
    matrix.show();
    frame += 1;
}