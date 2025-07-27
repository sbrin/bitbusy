#include "web.h"

void setup_routes(AsyncWebServer &server, Timer &timer, bool &state){
    app(server);
    busy(server, timer, state);
}