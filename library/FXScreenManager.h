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
    if (currentScreenIdx == y)                                                         \
    {                                                                                  \
        if (!currentScreenPtr)                                                         \
        {                                                                              \
            currentScreenPtr = new x(tft, y);                                          \
            currentScreenPtr->tft->fillScreen(currentScreenPtr->getBackgroundColor()); \
        }                                                                              \
        if (currentScreenPtr && currentScreenPtr->getScreenID() != y)                  \
        {                                                                              \
            delete currentScreenPtr, currentScreenPtr = new x(tft, y);                 \
            currentScreenPtr->tft->fillScreen(currentScreenPtr->getBackgroundColor()); \
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
    FXScreen *currentScreenPtr = NULL;
    FXScreens currentScreenIdx = FXScreens::MAIN;
    bool changereq = false;
    size_t changeto = 0;

public:
    /**
     * @brief Construct a new FXScreenManager object
     * 
     * @param t: Pointer to the TFT_eSPI object
     */
    FXScreenManager(TFT_eSPI *t)
    {
        tft = t;
    }
    /**
     * @brief Ticks the FXScreenManager, updating the current window if needed (or touched), or jumping to another window
     */
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
            currentScreenPtr->setTouchPos(touchx, touchy);
            touchpressed = false;
        }
        currentScreenPtr->drawUI();
        if (currentScreenPtr->wasJumpRequested())
        {
            currentScreenIdx = currentScreenPtr->getNewWindow();
            currentScreenPtr->suppressJumpRequest();
        }
    }
    /**
     * @brief ISR triggers this method, forcing the FXScreenManager to update the touch coordinates 
     */
    void updateTouch()
    {
        touchpressed = true;
    }
    /**
     * @brief Sets (jumps to) the desired window
     * 
     * @param windowIdx 
     */
    void setWindow(FXScreens windowIdx)
    {
        currentScreenIdx = windowIdx;
    }
    /**
     * @brief Gets the X touch position
     * 
     * @return uint16_t: X touch position
     */
    uint16_t getTouchX()
    {
        return touchx;
    }
    /**
     * @brief Gets the Y touch position
     * 
     * @return uint16_t: Y touch position
     */
    uint16_t getTouchY()
    {
        return touchy;
    }
};

#endif