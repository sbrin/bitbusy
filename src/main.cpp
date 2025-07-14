#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#include "defines.h"

Adafruit_NeoMatrix *matrix = new Adafruit_NeoMatrix(mw, mh, 
  PIN,
  NEO_MATRIX_BOTTOM     + NEO_MATRIX_RIGHT +
    NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800 );

void setup() {
  Serial.begin(9600);

static const unsigned char PROGMEM image_Layer_3_bits[] = {0xf8,0xcc,0x78,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xc0,0xcc,0xf8,0xcc,0x78,0x78,0xcc,0xcc,0x0c,0x30,0xcc,0xcc,0xcc,0x30,0xf8,0x78,0x78,0x30};


// Layer 1
matrix->setTextColor(0xE0C4);
matrix->setTextWrap(false);
matrix->setCursor(5, -7);
matrix->print("f");

// Layer 3
matrix->drawBitmap(1, 1, image_Layer_3_bits, 30, 7, 0xE0C4);

  matrix->show();
}

void loop() {
}

