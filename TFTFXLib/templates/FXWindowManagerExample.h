/**
 * @file FXWindowManager.h
 * @author Riccardo Iacob
 * @brief
 * @version 0.1
 * @date 2023-07-12
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef FXWINDOWMANAGER_H
#define FXWINDOWMANAGER_H

#include "Includes.h"
#include "FXWindow.h"

/* BEGIN USER SCREEN INCLUSION */
#include "MyScreen.h"
#include "MyScreen2.h"
/* END USER SCREEN INCLUSION */

class FXWindowManager
{
public:
    enum Windows
    {
        /* BEGIN USER WINDOW NAME DEFINITIONS */
        MAIN,
        CONFIG,
        /* END USER WINDOW NAME DEFINITIONS */
        TOT_WINDOWS
    };

private:
    TFT_eSPI *tft;
    uint16_t touchx;
    uint16_t touchy;
    bool touchpressed = false;
    FXWindow *currentwindowptr;
    size_t currentwindowidx = 0;
    bool changereq = false;
    size_t changeto = 0;

public:
    FXWindowManager(TFT_eSPI *t)
    {
        tft = t;
    }
    void doTick()
    {
        switch (currentwindowidx)
        {
        /* BEGIN USER WINDOW ACTIONS DEFINITIONS */
        case MAIN:
        {
            currentwindowidx = MAIN;
            currentwindowptr = new MyScreen(tft);
            break;
        }
        case CONFIG:
        {
            currentwindowidx = CONFIG;
            currentwindowptr = new MyScreen2(tft);
            break;
        }
            /* END USER WINDOW ACTIONS DEFINITIONS */
        }
        if (touchpressed)
        {
            tft->getTouch(&touchx, &touchy);
            currentwindowptr->setTouchPos(touchx, touchy);
            debugln("[fxwindowmanager.h] touch pressed");
            debugln(touchx);
            debugln(touchy);
            touchpressed = false;
        }
        currentwindowptr->drawUI();
        if (currentwindowptr->wasJumpRequested())
        {
            debugln("[fxwindowmanager.h] window jump requested");
            currentwindowidx = currentwindowptr->getNewWindow();
            currentwindowptr->suppressJumpRequest();
        }
        delete currentwindowptr;
    }
    void updateTouch()
    {
        touchpressed = true;
    }
    void setWindow(size_t windowIdx)
    {
        if (windowIdx >= TOT_WINDOWS)
        {
            return;
        }
        currentwindowidx = windowIdx;
    }
    uint16_t getTouchX()
    {
        return touchx;
    }
    uint16_t getTouchY()
    {
        return touchy;
    }
};

#endif