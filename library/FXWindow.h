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
private:
    bool windowChangeRequested = false;
    size_t targetWindow = 0;
    size_t wid = 0;

protected:
    // Last X touch point
    uint16_t touchx = 0;
    // Last Y touch point
    uint16_t touchy = 0;
    // millis() when the touch points where updated
    long touchtime = 0;

public:
    TFT_eSPI *tft;

public:
    FXWindow(TFT_eSPI *t, size_t windowID)
    {
        wid = windowID;
        tft = t;
    }
    virtual void drawUI() {}
    void setTouchPos(uint16_t x, uint16_t y)
    {
        touchx = x;
        touchy = y;
        touchtime = millis();
    }
    bool wasJumpRequested()
    {
        return windowChangeRequested;
    }
    size_t getNewWindow()
    {
        return targetWindow;
    }
    void jumpToWindow(size_t idx)
    {
        windowChangeRequested = true;
        targetWindow = idx;
    }
    void suppressJumpRequest()
    {
        windowChangeRequested = false;
    }
    size_t getWindowID()
    {
        return wid;
    }
    void resetTouch(){
        touchx = 0;
        touchy = 0;
    }
};

#endif