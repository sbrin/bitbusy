#include <Arduino.h>
#include <ArduinoOTA.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <LittleFS.h>

#include "defines.h"
#include "screens/screens.h"
#include "timer/timer.h"
#include "web/web.h"

Adafruit_NeoMatrix *matrix;
Timer *timer;
AsyncWebServer server(80);

int frame = 0;
unsigned long prev = 0;

bool state = false;

void setup() {
  Serial.begin(9600);
  LittleFS.begin();
  
  matrix = new Adafruit_NeoMatrix(MATRIX_WIDTH, MATRIX_HEIGHT, 
    PIN,
    NEO_MATRIX_BOTTOM     + NEO_MATRIX_RIGHT +
      NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
    NEO_GRB            + NEO_KHZ800 );
  
  matrix->setBrightness(BRIGHTNESS);

  Serial.println("Matrix initialized");

  connecting(*matrix);

  timer = new Timer(1800, millis(), state);

  WiFi.setHostname(HOSTNAME);

  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASSWORD);
  
  while (WiFi.status() != WL_CONNECTED) {
    vTaskDelay(500);
    Serial.print(".");
  }

  ArduinoOTA.setHostname(HOSTNAME); // Имя, под которым плата будет видна
  ArduinoOTA.setPassword(OTA_PASSWORD); // Можно задать пароль

  ArduinoOTA.onStart([]() {
    Serial.println("Start OTA");
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd OTA");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress * 100) / total);
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
  });

  ArduinoOTA.begin();
  Serial.println("Ready for OTA");
  Serial.println("");
  Serial.println("WiFi initialized");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP()); 
  
  setup_routes(server, *timer, state);
  server.begin();

  Serial.println("Server started");
  Serial.println("Setup complete");
}

void loop() {
  timer->tick();
  ArduinoOTA.handle();
  if (millis() - prev > 50) {
    prev = millis();
    select(*matrix, frame, state, timer->left());
  }
}

