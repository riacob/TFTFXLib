/**
 * @file FXWidget.h
 * @author Riccardo Iacob
 * @brief Main widget class. All widgets are inherited from this superclass.
 * @version 0.1
 * @date 2023-07-11
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef FXWIDGET_H
#define FXWIDGET_H

#include "Includes.h"
#include "FXWindow.h"

class FXWidget
{
protected:
    // Parent window (the window in which the widget is present)
    FXWindow *parent;
    // TFT screen object reference, there shall be one screen per program
    TFT_eSPI *_tft;
    // TFT sprite object reference
    TFT_eSprite *widget;
    // Start X of the widget's bounds
    uint16_t widgetstartx = 0;
    // Start Y of the widget's bounds
    uint16_t widgetstarty = 0;
    // Size X of the widget
    uint16_t widgetsizex = 0;
    // Size Y of the widget
    uint16_t widgetsizey = 0;
    // If true the sprite for the widget exists
    bool isValid = false;
    // If true the sprite for the widget is currently drawn
    bool isVisible = true;

    FXWidget(FXWindow *w)
    {
        parent = w;
        _tft = w->tft;
    }
    ~FXWidget()
    {
        delete widget;
    }
    void createWidget()
    {
        /*debug("[fxwidget.h] createWidget() sizex");
        debug(widgetsizex);
        debug(" sizey");
        debugln(widgetsizey);*/
        widget = new TFT_eSprite(_tft);
        widget->createSprite(widgetsizex, widgetsizey);
        isValid = true;
    }
    void drawWidget()
    {
        if (!isValid)
        {
            //debugln("[fxwidget.h] drawWidget() widget invalid");
            return;
        }
        if (!isVisible)
        {
            //debugln("[fxwidget.h] drawWidget() widget invisible");
            return;
        }
        /*debug("[fxwidget.h] drawWidget() startx");
        debug(widgetstartx);
        debug(" starty");
        debugln(widgetstarty);*/
        widget->pushSprite(widgetstartx, widgetstarty);
    }
    void deleteWidget()
    {
        if (!isValid)
        {
            //debugln("[fxwidget.h] deleteWidget() widget invalid");
            return;
        }
        //debugln("[fxwidget.h] deleteWidget()");
        widget->deleteSprite();
        isValid = false;
    }

public:
    void setVisible()
    {
        isVisible = true;
    }
    void setInvisible()
    {
        isVisible = false;
    }
    void setVisibility(bool visible)
    {
        isVisible = visible;
    }
};

#endif