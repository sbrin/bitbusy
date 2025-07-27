#include "web.h"

void setup_routes(AsyncWebServer &server, Timer &timer, State &state){
    app(server);
    busy(server, timer, state);
}