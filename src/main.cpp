#include <Arduino.h>
#include <SPI.h>
#include <FS.h>
#include <SPIFFS.h>
#include "screen.h"

TFT_eSPI tft = TFT_eSPI();

MyScreen *screen1;

void setup() {
  tft.init();
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);
  screen1 = new MyScreen(&tft);
  Serial.begin(115200);
}

void loop() {
  screen1->drawUI();
  delay(5000);
}