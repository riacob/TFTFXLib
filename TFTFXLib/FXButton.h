/**
 * @file FXButton.h
 * @author Riccardo Iacob
 * @brief
 * @version 0.1
 * @date 2023-07-11
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef FXBUTTON_H
#define FXBUTTON_H

#include "Includes.h"
#include "FXWidget.h"
#include "FXWindow.h"

class FXButton : public FXWidget
{
private:
    void (*pressedcallback)();

protected:
    uint16_t sizex = 0;
    uint16_t sizey = 0;
    uint16_t startx = 0;
    uint16_t starty = 0;

public:
    FXButton(FXWindow *w) : FXWidget(w)
    {
        parent = w;
        _tft = w->tft;
    }
    void setPosition(uint16_t x, uint16_t y)
    {
        startx = x;
        starty = y;
    }
    void setSize(uint16_t sizeX, uint16_t sizeY)
    {
        sizex = sizeX;
        sizey = sizeY;
    }
    void draw()
    {
        // If no tooltip is present we don't need to make the
        // widget size any bigger than the button size
        widgetsizex = sizex;
        widgetsizey = sizey;
        widgetstartx = startx;
        widgetstarty = starty;
        // create the widget
        createWidget();
        // add button to the widget
        widget->fillScreen(TFT_WHITE);
        widget->fillRect(startx, starty, sizex, sizey, TFT_WHITE);
        // draw the widget on the screen
        drawWidget();
        // delete the widget from PSRAM
        deleteWidget();
    }
    void setPressedCallback(void (*f)())
    {
        pressedcallback = f;
    }
    void touchAt(uint16_t x, uint16_t y)
    {
        // Check if the touch is in any position where a callback should be called
        // Button press
        if (x > startx && x < startx + sizex && y > starty && y < starty + sizey)
        {
            //debugln("[fxbutton.h] touched");
            pressedcallback();
        }
    }
};

#endif