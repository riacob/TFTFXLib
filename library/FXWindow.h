/**
 * @file FXWindow.h
 * @author Riccardo Iacob
 * @brief FXWindow Parent Class
 * @version 0.1
 * @date 2023-07-11
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef FXWINDOW_H
#define FXWINDOW_H

#include "Includes.h"
#include "FXScreens.h"

class FXWindow
{
private:
    bool windowChangeRequested = false;
    FXScreens targetWindow;
    FXScreens wid;

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
    FXWindow(TFT_eSPI *t, FXScreens windowID)
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
    FXScreens getNewWindow()
    {
        return targetWindow;
    }
    void jumpToWindow(FXScreens idx)
    {
        windowChangeRequested = true;
        targetWindow = idx;
    }
    void suppressJumpRequest()
    {
        windowChangeRequested = false;
    }
    FXScreens getWindowID()
    {
        return wid;
    }
    void resetTouch(){
        touchx = 0;
        touchy = 0;
    }
};

#endif