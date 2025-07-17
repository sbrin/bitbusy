#include "app.h"

void app(AsyncWebServer &server) {
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(LittleFS, "/dist/index.html", "text/html");
    });

    server.serveStatic("/", LittleFS, "/dist/");
}