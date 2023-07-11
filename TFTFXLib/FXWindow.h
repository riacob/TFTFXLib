/**
 * @file FXWindow.h
 * @author Riccardo Iacob
 * @brief
 * @version 0.1
 * @date 2023-07-11
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef FXWINDOW_H
#define FXWINDOW_H

#include "Includes.h"

class FXWindow
{
protected:
    uint16_t touchx = 0;
    uint16_t touchy = 0;
    long touchtime = 0;
public:
    TFT_eSPI *tft;

public:
    FXWindow(TFT_eSPI *t)
    {
        tft = t;
    }
    virtual void drawUI() {}
    void setTouchPos(uint16_t x, uint16_t y)
    {
        touchx = x;
        touchy = y;
        touchtime = millis();
    }
};

#endif