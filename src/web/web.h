#pragma once
#include <ESPAsyncWebServer.h>
#include <Arduino.h>

#include "timer/timer.h"
#include "routes/busy/busy.h"

void setup_routes(AsyncWebServer, Timer);