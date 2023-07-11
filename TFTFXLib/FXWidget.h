/**
 * @file FXWidget.h
 * @author Riccardo Iacob
 * @brief
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
    FXWindow *parent;
    TFT_eSPI *_tft;
    TFT_eSprite *widget;
    uint16_t widgetstartx = 0;
    uint16_t widgetstarty = 0;
    uint16_t widgetsizex = 0;
    uint16_t widgetsizey = 0;
    bool isValid = false;
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
        debug("[fxwidget.h] createWidget() sizex");
        debug(widgetsizex);
        debug(" sizey");
        debugln(widgetsizey);
        widget = new TFT_eSprite(_tft);
        widget->createSprite(widgetsizex, widgetsizey);
        isValid = true;
    }
    void drawWidget()
    {
        if (!isValid) {
            debugln("[fxwidget.h] drawWidget() widget invalid");
            return;
        }
        debug("[fxwidget.h] drawWidget() startx");
        debug(widgetstartx);
        debug(" starty");
        debugln(widgetstarty);
        widget->pushSprite(widgetstartx,widgetstarty);
        isVisible = true;
    }
    void deleteWidget()
    {
        if (!isValid) {
            debugln("[fxwidget.h] deleteWidget() widget invalid");
            return;
        }
        debugln("[fxwidget.h] deleteWidget()");
        widget->deleteSprite();
        isVisible = false;
        isValid = false;
    }
};

#endif