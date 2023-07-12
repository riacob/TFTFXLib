#include <Arduino.h>
#include <SPI.h>
#include <FS.h>
#include <SPIFFS.h>
#include "MyScreen.h"
#include "FXWindowManager.h"

TFT_eSPI tft = TFT_eSPI();
FXWindowManager mgr(&tft);
volatile long debounce_ms = 0;
long debounce_ms_threshold = 500;

void touchISR()
{
  if ((mgr.getTouchX() == 0 && mgr.getTouchY() == 0) || (millis() - debounce_ms >= debounce_ms_threshold) || (debounce_ms == 0))
  {
    mgr.updateTouch();
    debounce_ms = millis();
  }
}

void setup()
{
  tft.init();
  uint16_t calData[5] = {338, 3387, 343, 3489, 4} ;
  tft.setTouch(calData);
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);
  attachInterrupt(22, touchISR, FALLING);
  Serial.begin(115200);
}

void loop()
{
  mgr.doTick();
}