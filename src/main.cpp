#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#define BRIGHTNESS 100

#define PIN 2

#define mw 32
#define mh 8

static const unsigned char PROGMEM image_Layer_2_bits[] = {0x38,0x44,0x82,0xba,0x82,0x44,0x38};

Adafruit_NeoMatrix *matrix = new Adafruit_NeoMatrix(mw, mh, 
  PIN,
  NEO_MATRIX_BOTTOM     + NEO_MATRIX_RIGHT +
    NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800 );

void setup() {
  Serial.begin(9600);
  matrix->begin();
  matrix->setTextWrap(false);
  matrix->setBrightness(BRIGHTNESS);

  matrix->setTextColor(0xC0E5);
  matrix->setTextWrap(false);
  matrix->setCursor(9, 0);
  matrix->print("Busy");

  matrix->drawBitmap(0, 0, image_Layer_2_bits, 7, 7, 0xC0E5);
  matrix->show();
}

void loop() {
}

