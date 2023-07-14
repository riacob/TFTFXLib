/**
 * @file FXScreenManager.h
 * @author Riccardo Iacob
 * @brief FXScreenManager Class
 * @version 0.1
 * @date 2023-07-12
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef FXSCREENMANAGER_H
#define FXSCREENMANAGER_H

#include "Includes.h"
#include "FXScreen.h"
#include "FXScreens.h"

#define _HANDLEWINDOWINSTANCE(x, y)                                                    \
    if (currentwindowidx == y)                                                         \
    {                                                                                  \
        if (!currentwindowptr)                                                         \
        {                                                                              \
            currentwindowptr = new x(tft, y);                                          \
            currentwindowptr->tft->fillScreen(currentwindowptr->getBackgroundColor()); \
        }                                                                              \
        if (currentwindowptr && currentwindowptr->getWindowID() != y)                  \
        {                                                                              \
            delete currentwindowptr, currentwindowptr = new x(tft, y);                 \
            currentwindowptr->tft->fillScreen(currentwindowptr->getBackgroundColor()); \
        }                                                                              \
    }

/* BEGIN USER SCREEN INCLUSION */
#include "MyScreen.h"
#include "MyScreen2.h"
#include "PwdScreen.h"
/* END USER SCREEN INCLUSION */

class FXScreenManager
{
private:
    TFT_eSPI *tft;
    uint16_t touchx;
    uint16_t touchy;
    bool touchpressed = false;
    FXScreen *currentwindowptr = NULL;
    FXScreens currentwindowidx = FXScreens::MAIN;
    bool changereq = false;
    size_t changeto = 0;

public:
    FXScreenManager(TFT_eSPI *t)
    {
        tft = t;
    }
    void doTick()
    {
        /* BEGIN USER WINDOW ACTIONS DEFINITIONS */
        _HANDLEWINDOWINSTANCE(MyScreen, FXScreens::MAIN);
        _HANDLEWINDOWINSTANCE(MyScreen2, FXScreens::CONFIG);
        _HANDLEWINDOWINSTANCE(PwdScreen, FXScreens::PWD);
        /* END USER WINDOW ACTIONS DEFINITIONS */
        if (touchpressed)
        {
            tft->getTouch(&touchx, &touchy);
            currentwindowptr->setTouchPos(touchx, touchy);
            touchpressed = false;
        }
        currentwindowptr->drawUI();
        if (currentwindowptr->wasJumpRequested())
        {
            currentwindowidx = currentwindowptr->getNewWindow();
            currentwindowptr->suppressJumpRequest();
        }
    }
    void updateTouch()
    {
        touchpressed = true;
    }
    void setWindow(FXScreens windowIdx)
    {
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