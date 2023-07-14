/**
 * @file TemplateMain.cpp
 * @author Riccardo Iacob
 * @brief Template for main.cpp
 * @version 0.1
 * @date 2023-07-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "Includes.h"
#include "FXScreenManager.h"

TFT_eSPI tft = TFT_eSPI();
FXScreenManager mgr(&tft);
volatile long debounce_ms = 0;
long debounce_ms_threshold = 500;

/* BEGIN SECTION GLOBAL_DEFINITIONS */
/* END SECTION GLOBAL_DEFINITIONS */

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
  attachInterrupt(22, touchISR, FALLING);
  Serial.begin(115200);
  /* BEGIN SECTION SETUP */
  /* END SECTION SETUP */
}

void loop()
{
  mgr.doTick();
  /* BEGIN SECTION LOOP */
  /* END SECTION LOOP */
}