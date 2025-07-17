#pragma once
#include <Arduino.h>
#include <ESPAsyncWebServer.h>

#include "timer/timer.h"

void busy(AsyncWebServer, Timer);
