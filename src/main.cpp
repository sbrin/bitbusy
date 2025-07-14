#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#include "defines.h"
#include "screens/screens.h"

Adafruit_NeoMatrix *matrix;

int frame = 0;

void setup() {
  Serial.begin(9600);

  matrix = new Adafruit_NeoMatrix(MATRIX_WIDTH, MATRIX_HEIGHT, 
    PIN,
    NEO_MATRIX_BOTTOM     + NEO_MATRIX_RIGHT +
      NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
    NEO_GRB            + NEO_KHZ800 );
}

void loop() {
  free(*matrix, frame);
  delay(100);
}

