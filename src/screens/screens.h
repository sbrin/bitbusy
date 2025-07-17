#pragma once
#include "images/images.h"
#include "colors/colors.h"
#include "fonts/Petme8x8.h"

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

void free(Adafruit_NeoMatrix &matrix, int &frame);
void busy(Adafruit_NeoMatrix &matrix, int &frame, int timeleft);

void select(Adafruit_NeoMatrix &matrix, int &frame, bool free, int timeleft);