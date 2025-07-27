#include "busy.h"

void busy(AsyncWebServer &server, Timer &timer, State &state){
    server.on("/api/busy", HTTP_POST, [](AsyncWebServerRequest *request){}, NULL, [&timer, &state](AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total){
        String body;

        for (size_t i = 0; i < len; i++) {
        body += (char)data[i];
        }

        JsonDocument doc;
        DeserializationError error = deserializeJson(doc, body);

        if (error){
            Serial.print(F("deserializeJson() failed: "));
            Serial.println(error.f_str());
            request->send(400, "text/plain", "Bad Request");
            return;
        }

        state.setBusy(doc["busy"].as<bool>());
        state.setTime(doc["time"].as<int>());

        if(doc["busy"].as<bool>()){
            state.setPomodoro(doc["pomodoro"].as<bool>());
            timer.set(doc["time"].as<int>());
            timer.start();    
        }
        else{
            state.setPomodoro(false);
            timer.stop();
        }

        request->send(200, "text/plain", String(timer.left()));
    });

    server.on("/api/busy", HTTP_GET, [&timer, &state](AsyncWebServerRequest *request){
        JsonDocument doc;
        doc["busy"] = state.getBusy();
        doc["time"] = timer.left();
        doc["pomodoro"] = state.getPomodoro();
        doc["settime"] = state.getSettime();
        
        String response;
        serializeJson(doc, response);

        request->send(200, "text/plain", response);
    });}