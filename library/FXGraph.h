/**
 * @file FXGraph.h
 * @author Riccardo Iacob
 * @brief
 * @version 0.1
 * @date 2023-07-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef FXGRAPH_H
#define FXGRAPH_H

#include <Arduino.h>
#include "FXWidget.h"

class FXGraph : FXWidget
{
private:
    // Graph background color
    uint32_t bgcolor = TFT_YELLOW;
    // Graph color
    uint32_t graphcolor = TFT_BLUE;
    // Graph detail color
    uint32_t detailcolor = TFT_LIGHTGREY;
    // Graph border color
    uint32_t bordercolor = TFT_DARKGREY;
    // Graph data
    // Y values
    float *yvals;
    // Number of y values
    size_t yvalscnt = 0;
    // Scaling factor (yvals[n]*scalingfactor)
    float scalingfactor = 1;
    // Graph position offset
    float offset = 0;
    // If the dots are to be connected or not
    bool connectdots = true;

    /**
     * @brief Renders the graph on the screen
     * 
     */
    void renderGraph()
    {
        float biggestval = 0;
        float smallestval = 0;
        size_t i;
        // To find the scaling factor:
        // 1. Find the biggest (absolute) y value
        for (i = 0; i < yvalscnt; i++)
        {
            if (yvals[i] < 0)
            {
                if (yvals[i] * -1 > biggestval)
                {
                    biggestval = yvals[i];
                }
                if (yvals[i] * -1 < smallestval)
                {
                    smallestval = yvals[i];
                }
            }
            else
            {
                if (yvals[i] > biggestval)
                {
                    biggestval = yvals[i];
                }
                if (yvals[i] < smallestval)
                {
                    smallestval = yvals[i];
                }
            }
        }
        // 2. Find the scaling factor and the offset
        scalingfactor = biggestval / widgetsizey;
        offset = (biggestval - smallestval)/2;
        debugln(scalingfactor);
        // debugln(scalingfactor);
        //  3. Render the scaled graph
        //  Don't render the graph points outside of the wiget
        for (i = 0; (i < yvalscnt) && (i < widgetsizex); i++)
        {
            widget->drawPixel(i, yvals[i] * scalingfactor + offset, graphcolor);
            // i < i-1 prevents overflow because this function checks for i+1
            if (connectdots && (i < yvalscnt - 1))
            {
                float pA = yvals[i] * scalingfactor + offset;
                float pB = yvals[i + 1] * scalingfactor + offset;
                if (pA != pB)
                {
                    widget->drawLine(i, pA, i + 1, pB, graphcolor);
                }
            }
        }
    }

public:
    FXGraph(FXWindow *parent) : FXWidget(parent)
    {
    }
    /**
     * @brief Renders the graph window
     * 
     */
    void draw()
    {
        createWidget();
        // Draw graph background
        widget->fillRect(0, 0, widgetsizex, widgetsizey, bgcolor);
        // Draw details under graph
        // Draw the graph
        renderGraph();
        // Draw border over graph
        widget->drawRect(0, 0, widgetsizex, widgetsizey, bordercolor);
        // widget->drawString("Test",0,0);
        drawWidget();
        deleteWidget();
    }

    /**
     * @brief Sets the size of the graph window
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
     * @brief Sets the position of the graph window
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
     * @brief Sets the data points of the graph
     * 
     * @param yvalues: Y values array 
     * @param datapoints: number of Y values in the array
     */
    void setData(float *yvalues, size_t datapoints)
    {
        yvals = yvalues;
        yvalscnt = datapoints;
    }

    /**
     * @brief Gets the scaling factor of the graph's values
     * 
     * @return float: Scaling factor
     */
    float getScalingFactor() {
        return scalingfactor;
    }

    /**
     * @brief Sets the scaling factor of the graph's values
     * 
     * @param factor: Scaling factor
     */
    void setScalingFactor(float factor) {
        scalingfactor = factor;
    }

    /**
     * @brief Sets the connectdots option to true
     */
    void connectDots()
    {
        connectdots = true;
    }

    /**
     * @brief Sets the connectdots option to false
     */
    void disconnectDots()
    {
        connectdots = false;
    }
};

#endif