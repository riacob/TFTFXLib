/**
 * @file FXHProgressBar.h
 * @author Riccardo Iacob
 * @brief
 * @version 0.1
 * @date 2023-07-12
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef FXHPROGRESSBAR_H
#define FXHPROGRESSBAR_H

#include <Arduino.h>
#include "FXWidget.h"

class FXHProgressBar : public FXWidget
{
private:
protected:
    float multiplier = 0.5;
    uint16_t cornerradius = 0;
    uint32_t bgcolor = TFT_WHITE;
    uint32_t barcolor = TFT_GREEN;
    uint32_t bordercolor = TFT_BLACK;
    bool inverted = false;

public:
    FXHProgressBar(FXWindow *parent) : FXWidget(parent)
    {
    }
    /**
     * @brief Renders the progress bar
     *
     */
    void draw()
    {
        createWidget();
        // Draw widget background
        widget->fillRect(0, 0, widgetsizex, widgetsizey, widgetbgcolor);
        // Draw background and bar
        if (inverted)
        {
            widget->fillRoundRect(0, 0, widgetsizex, widgetsizey, cornerradius, barcolor);
            widget->fillRoundRect(0, 0, widgetsizex * multiplier, widgetsizey, cornerradius, bgcolor);
        }
        else
        {
            widget->fillRoundRect(0, 0, widgetsizex, widgetsizey, cornerradius, bgcolor);
            widget->fillRoundRect(0, 0, widgetsizex * multiplier, widgetsizey, cornerradius, barcolor);
        }
        // Draw border
        widget->drawRoundRect(0, 0, widgetsizex, widgetsizey, cornerradius, bordercolor);
        drawWidget();
        deleteWidget();
    }
    /**
     * @brief Sets the size of the progress bar
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
     * @brief Sets the position of the progress bar
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
     * @brief Sets the multiplier of the progressbar (percentage/100)
     *
     * @param m: Multiplier, between 0 and 1
     */
    void setMultiplier(float m)
    {
        if (m > 1 || m < 0)
        {
            return;
        }
        else
            multiplier = m;
    }

    /**
     * @brief Inverts the bar direction
     *
     */
    void invert()
    {
        inverted = !inverted;
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
};

#endif