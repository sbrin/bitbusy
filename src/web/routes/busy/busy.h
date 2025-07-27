#pragma once
#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>

#include "timer/timer.h"
#include "state/state.h"

void busy(AsyncWebServer &server, Timer &timer, State &state);
