/**
 * @file FXHSwitch.h
 * @author Riccardo Iacob
 * @brief FXHSwitch Widget Class
 * @version 0.1
 * @date 2023-07-12
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef FXHSWITCH_H
#define FXHSWITCH_H

#include <Arduino.h>
#include "FXWidget.h"

class FXHSwitch : public FXWidget
{
private:
    void (*switchedoncallback)();
    void (*switchedoffcallback)();
    void (*pressedcallback)();
    bool switchedoncallbackset = false;
    bool switchedoffcallbackset = false;
    bool pressedcallbackset = false;

protected:
    uint16_t cornerradius = 0;
    uint32_t bgcolor = TFT_WHITE;
    uint32_t oncolor = TFT_RED;
    uint32_t onaccentcolor = TFT_DARKRED;
    uint32_t offcolor = TFT_GREEN;
    uint32_t offaccentcolor = TFT_DARKGREEN;
    uint32_t bordercolor = TFT_BLACK;
    bool _state = false;

public:
    /**
     * @brief Constructs a new FXHSwitch object
     *
     * @param parent
     */
    FXHSwitch(FXScreen *parent) : FXWidget(parent)
    {
    }

    /**
     * @brief Renders the switch on the screen
     *
     */
    void draw()
    {
        createWidget();
        // Draw widget background
        widget->fillRect(0, 0, widgetsizex, widgetsizey, widgetbgcolor);
        // Draw background
        widget->fillRoundRect(0, 0, widgetsizex, widgetsizey, cornerradius, bgcolor);
        // If ON
        if (_state)
        {
            widget->fillRoundRect(0, 0, widgetsizex, widgetsizey, cornerradius, onaccentcolor);
            widget->fillRoundRect(widgetsizex / 2, 0, widgetsizex / 2, widgetsizey, cornerradius, oncolor);
            widget->drawRoundRect(widgetsizex / 2, 0, widgetsizex / 2, widgetsizey, cornerradius - 1, bordercolor);
        }
        // If OFF
        else
        {
            widget->fillRoundRect(0, 0, widgetsizex, widgetsizey, cornerradius, offaccentcolor);
            widget->fillRoundRect(0, 0, widgetsizex / 2, widgetsizey, cornerradius, offcolor);
            widget->drawRoundRect(0, 0, widgetsizex / 2, widgetsizey, cornerradius - 1, bordercolor);
        }
        // Draw
        widget->drawRoundRect(0, 0, widgetsizex, widgetsizey, cornerradius, bordercolor);
        drawWidget();
        deleteWidget();
    }

    /**
     * @brief Sets the size of the switch
     *
     * @param sizeX: X size
     * @param sizeY: Y size
     */
    void setSize(uint16_t sizeX, uint16_t sizeY)
    {
        widgetsizex = sizeX;
        widgetsizey = sizeY;
    }

    /**
     * @brief Sets the position of the switch
     *
     * @param x: X position
     * @param y: Y position
     */
    void setPosition(uint16_t x, uint16_t y)
    {
        widgetstartx = x;
        widgetstarty = y;
    }

    /**
     * @brief Sets the corner radius of the progressbar
     *
     * @param radius: Corner radius
     */
    void setCornerRadius(uint16_t radius)
    {
        cornerradius = radius;
    }

    /**
     * @brief Maps x and y coordinates to callbacks, if found executes them, else does nothing
     *
     * @param x: X touch coordinate
     * @param y: Y touch coordinate
     */
    void touchAt(uint16_t x, uint16_t y)
    {
        // Check if the touch is in any position where a callback should be called
        // Button press
        if (x > widgetstartx && x < widgetstartx + widgetsizex && y > widgetstarty && y < widgetstarty + widgetsizey)
        {
            // If turning OFF
            if (_state)
            {
                _state = 0;
                if (switchedoffcallbackset)
                {
                    switchedoffcallback();
                }
            }
            // If turning ON
            else
            {
                _state = 1;
                if (switchedoncallbackset)
                {
                    switchedoncallback();
                }
            }
            // Always
            if (pressedcallbackset)
            {
                pressedcallback();
            }
        }
    }
};

#endif
