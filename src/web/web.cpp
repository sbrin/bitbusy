#include "web.h"

void setup_routes(AsyncWebServer &server, Timer &timer){
    app(server);
    busy(server, timer);
}