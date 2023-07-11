#include <Arduino.h>
#include <SPI.h>
#include <FS.h>
#include <SPIFFS.h>
#include "MyScreen.h"
#include "FXWindowManager.h"

TFT_eSPI tft = TFT_eSPI();
FXWindowManager mgr(&tft);

MyScreen *screen1;
volatile bool touchUpdated = false;
static long ms_start = 0;

void touchISR()
{
  touchUpdated = true;
}

void setup()
{
  tft.init();
  uint16_t calData[5] = {338, 3387, 343, 3489, 4};
  tft.setTouch(calData);
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);
  screen1 = new MyScreen(&tft,&mgr);
  attachInterrupt(22, touchISR, FALLING);
  Serial.begin(115200);
  ms_start = millis();
}

void loop()
{
  if (touchUpdated)
  {
    uint16_t x, y;
    tft.getTouch(&x, &y);
    screen1->setTouchPos(x, y);
    touchUpdated = false;
  }
  // Update screen every 5ms
  if (millis() - ms_start >= 5)
  {
    screen1->drawUI();
    ms_start = millis();
  }
}