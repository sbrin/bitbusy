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
        
        if(doc["running"].is<bool>()){
            if(doc["running"].as<bool>()){
                state.setRunning(doc["running"].as<bool>());
                state.setColor(doc["color"].as<int>());
                state.setText(doc["text"].as<String>());
            }
        }
        else{
            state.setRunning(false);
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
        }
        request->send(200, "text/plain", "OK");
    });

    server.on("/api/busy", HTTP_GET, [&timer, &state](AsyncWebServerRequest *request){
        JsonDocument doc;
        if(state.getRunning()){
            doc["running"] = state.getRunning();
            doc["text"]  = state.getText();
            doc["color"] = state.getColor();
        }
        else{
            doc["busy"] = state.getBusy();
            doc["time"] = timer.left();
            doc["pomodoro"] = state.getPomodoro();
            doc["settime"] = state.getSettime();
        }
        String response;
        serializeJson(doc, response);

        request->send(200, "text/plain", response);
    });}