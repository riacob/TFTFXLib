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
private:
    // Parent window (the window in which the widget is present)
    FXWindow *parent;

protected:
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
    // Background color of the whole sprite
    uint32_t widgetbgcolor = TFT_WHITE;

    FXWidget(FXWindow *w)
    {
        parent = w;
    }
    ~FXWidget()
    {
        delete widget;
    }
    void createWidget()
    {
        widget = new TFT_eSprite(parent->tft);
        widget->createSprite(widgetsizex, widgetsizey);
        isValid = true;
    }
    void drawWidget()
    {
        if (!isValid)
        {
            return;
        }
        if (!isVisible)
        {
            return;
        }
        widget->pushSprite(widgetstartx, widgetstarty);
    }
    void deleteWidget()
    {
        if (!isValid)
        {
            return;
        }
        widget->deleteSprite();
        isValid = false;
    }

public:
    /**
     * @brief Makes the widget visible
     *
     */
    void setWidgetVisible()
    {
        isVisible = true;
    }
    /**
     * @brief Makes the widget invisible
     *
     */
    void setWidgetInvisible()
    {
        isVisible = false;
    }
    /**
     * @brief Sets the visibility of the widget
     *
     * @param visible: true if the widget should be visible
     */
    void setWidgetVisibility(bool visible)
    {
        isVisible = visible;
    }
    /**
     * @brief Sets the background color of the widget
     *
     * @param color: Background color
     */
    void setWidgetBackgroundColor(uint32_t color)
    {
        widgetbgcolor = color;
    }
    void clearWidget()
    {
        deleteWidget();
        createWidget();
        widget->fillRect(widgetstartx, widgetstarty, widgetsizex, widgetsizey, widgetbgcolor);
        setWidgetVisible();
        drawWidget();
    }
};

#endif