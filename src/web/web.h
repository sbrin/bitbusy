#pragma once
#include <ESPAsyncWebServer.h>
#include <Arduino.h>

#include "timer/timer.h"
#include "routes/busy/busy.h"
#include "routes/app/app.h"

void setup_routes(AsyncWebServer &server, Timer &timer, bool &busy);