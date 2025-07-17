#include "busy.h"

void busy(AsyncWebServer &server, Timer &timer){
server.on("/api/busy", HTTP_POST, [](AsyncWebServerRequest *request){}, NULL, [](AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total){
    String body;

    for (size_t i = 0; i < len; i++) {
      body += (char)data[i];
    }

    
});}