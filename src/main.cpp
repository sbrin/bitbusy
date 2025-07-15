#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <WiFi.h>
#include <DNSServer.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

#include "defines.h"
#include "screens/screens.h"

Adafruit_NeoMatrix *matrix;

DNSServer dnsServer;
AsyncWebServer server(80);

int frame = 0;

void setup() {
  Serial.begin(9600);

  matrix = new Adafruit_NeoMatrix(MATRIX_WIDTH, MATRIX_HEIGHT, 
    PIN,
    NEO_MATRIX_BOTTOM     + NEO_MATRIX_RIGHT +
      NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
    NEO_GRB            + NEO_KHZ800 );

      WiFi.setHostname("bitbusy");

  if(AP){
    WiFi.mode(WIFI_AP);
    WiFi.softAP(SSID, PASSWORD, CHANNEL, HIDDEN);
    dnsServer.setErrorReplyCode(DNSReplyCode::NoError);
    dnsServer.start(53, "*", WiFi.softAPIP());
  }
  else{
    WiFi.mode(WIFI_STA);
    WiFi.begin(SSID, PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
      vTaskDelay(500);
      Serial.print(".");
    }
  }

  Serial.println("");
  Serial.println("WiFi initialized");
  Serial.print("IP address: ");
  if(AP) { 
    Serial.println(WiFi.localIP()); 
  }
  else { 
    Serial.println(WiFi.softAPIP()); 
  }


}

void loop() {
  busy(*matrix, frame, 899);
  vTaskDelay(50);
}

