#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

#include "defines.h"
#include "screens/screens.h"
#include "timer/timer.h"

Adafruit_NeoMatrix *matrix;
Timer *timer;
AsyncWebServer server(80);

int frame = 0;

void setup() {
  Serial.begin(9600);

  matrix = new Adafruit_NeoMatrix(MATRIX_WIDTH, MATRIX_HEIGHT, 
    PIN,
    NEO_MATRIX_BOTTOM     + NEO_MATRIX_RIGHT +
      NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
    NEO_GRB            + NEO_KHZ800 );
  
  Serial.println("Matrix initialized");

  timer = new Timer(0, millis());

  WiFi.setHostname("bitbusy");

  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    vTaskDelay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi initialized");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP()); 
  
  server.begin();
  Serial.println("Server started");
  Serial.println("Setup complete");
}

void loop() {
  select(*matrix, frame, timer->done(), timer->left());
  vTaskDelay(50);
}

