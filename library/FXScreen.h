/**
 * @file FXScreen.h
 * @author Riccardo Iacob
 * @brief FXScreen Parent Class
 * @version 0.1
 * @date 2023-07-11
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef FXSCREEN_H
#define FXSCREEN_H

#include "Includes.h"
#include "FXScreens.h"

class FXScreen
{
protected:
    bool screenChangeRequested = false;
    FXScreens targetScreen;
    FXScreens sid;
    // Last X touch point
    uint16_t touchx = 0;
    // Last Y touch point
    uint16_t touchy = 0;
    // millis() when the touch points where updated
    long touchtime = 0;
    uint32_t bgcolor = TFT_WHITE;

public:
    TFT_eSPI *tft;

public:
    /**
     * @brief Constructs a new FXScreen object
     * 
     * @param t: Pointer to the TFT_eSPI object
     * @param screenID: the ID of the current screen
     */
    FXScreen(TFT_eSPI *t, FXScreens screenID)
    {
        sid = screenID;
        tft = t;
    }

    /**
     * @brief Virtual function that draws the screen's contents (widgets)
     * 
     */
    virtual void drawUI() {}

    /**
     * @brief Sets the touch position
     * 
     * @param x 
     * @param y 
     */
    void setTouchPos(uint16_t x, uint16_t y)
    {
        touchx = x;
        touchy = y;
        touchtime = millis();
    }

    /**
     * @brief Checks if a screen jump was requested
     * 
     * @return true: If a screen jump was requested
     * @return false: If a screen jump was notrequested
     */
    bool wasJumpRequested()
    {
        return screenChangeRequested;
    }

    /**
     * @brief Gets the target of the screen jump
     * 
     * @return FXScreens: the target screen
     */
    FXScreens getNewScreen()
    {
        return targetScreen;
    }

    /**
     * @brief Jumps to desired screen
     * 
     * @param newScreen: the desired screen 
     */
    void jumpToScreen(FXScreens newScreen)
    {
        screenChangeRequested = true;
        targetScreen = newScreen;
    }

    /**
     * @brief Unrequests a screen jump
     * 
     */
    void suppressJumpRequest()
    {
        screenChangeRequested = false;
    }

    /**
     * @brief Gets the screen ID
     * 
     * @return FXScreens: The screen ID
     */
    FXScreens getScreenID()
    {
        return sid;
    }

    /**
     * @brief Resets touch position to 0,0
     */
    void resetTouch()
    {
        touchx = 0;
        touchy = 0;
    }

    /**
     * @brief Gets the background color
     * 
     * @return uint32_t: Background color
     */
    uint32_t getBackgroundColor()
    {
        return bgcolor;
    }

    /**
     * @brief Sets the background color
     * 
     * @param color: Background color
     */
    void setBackgroundColor(uint32_t color)
    {
        bgcolor = color;
    }
};

#endif