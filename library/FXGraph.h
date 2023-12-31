/**
 * @file FXGraph.h
 * @author Riccardo Iacob
 * @brief FXGraph Widget Class
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

class FXGraph : public FXWidget
{
private:
    // Graph background color
    uint32_t bgcolor = TFT_YELLOW;
    // Graph color
    uint32_t linecolor = TFT_BLUE;
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
    // Biggest value in dataset
    float biggestval = 0;
    // Smallest value in dataset
    float smallestval = 0;
    // Average value of dataset
    float avgval = 0;
    // If the offset is automatically adjusted based on the average value
    bool autooffset = true;
    // If the scaling is automatically adjusted based on the biggest value
    bool autoscaling = true;

    /**
     * @brief Renders the graph on the screen
     *
     */
    void renderGraph()
    {
        size_t i;
        // Find the maximum and minimum values of the graph
        for (i = 0; i < yvalscnt; i++)
        {
            // If values are negative module them first
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
            // Else just check them
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
            // Increment avgval by the current f(x)
            avgval += yvals[i];
        }
        // Divide avgval by the number of values to obtain the average
        avgval /= yvalscnt;
        // Find the scaling factor
        if (autoscaling)
        {
            scalingfactor = biggestval / widgetsizey;
        }
        // Find the offset
        if (autooffset)
        {
            offset = (widgetsizey / 2) - (avgval * scalingfactor);
        }
        //  Render the scaled graph
        //  Don't render the graph points outside of the wiget
        for (i = 0; (i < yvalscnt) && (i < widgetsizex); i++)
        {
            widget->drawPixel(i, yvals[i] * scalingfactor + offset, linecolor);
            // (i < yvalscnt - 1) overflow because this loop checks for yvals[i+1]
            if (i < yvalscnt - 1)
            {
                if (connectdots)
                {
                    float pA = yvals[i] * scalingfactor + offset;
                    float pB = yvals[i + 1] * scalingfactor + offset;
                    if (pA != pB)
                    {
                        widget->drawLine(i, pA, i + 1, pB, linecolor);
                    }
                }
            }
        }
    }

public:
    /**
     * @brief Constructs a new FXGraph object
     * 
     * @param parent: Parent screen
     */
    FXGraph(FXScreen *parent) : FXWidget(parent)
    {
    }

    /**
     * @brief Renders the graph on the screen
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
     * @brief Sets the size of the graph widget
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
     * @brief Sets the position of the graph widget
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
     * @brief Connects the individual dots (pixels) in the graph
     */
    void connectDots()
    {
        connectdots = true;
    }

    /**
     * @brief Disconnects the individual dots (pixels) in the graph
     */
    void disconnectDots()
    {
        connectdots = false;
    }

    /**
     * @brief Sets the background color
     * 
     * @param color 
     */
    void setGraphBackgroundColor(uint32_t color)
    {
        bgcolor = color;
    }

    /**
     * @brief Sets the graph color 
     * 
     * @param color 
     */
    void setGraphLineColor(uint32_t color)
    {
        linecolor = color;
    }

    /**
     * @brief Sets the detail color
     * 
     * @param color 
     */
    void setGraphDetailColor(uint32_t color)
    {
        detailcolor = color;
    }

    /**
     * @brief Sets the border color
     * 
     * @param color 
     */
    void setGraphBorderColor(uint32_t color)
    {
        bordercolor = color;
    }

    /**
     * @brief Gets the biggest absolute value
     * 
     * @return float 
     */
    float getBiggestAbsoluteValue()
    {
        return biggestval;
    }

    /**
     * @brief Gets the smallest absolute value
     * 
     * @return float 
     */
    float getSmallestAbsoluteValue()
    {
        return smallestval;
    }

    /**
     * @brief Gets the average absolute value
     * 
     * @return float 
     */
    float getAverageAbsoluteValue()
    {
        return avgval;
    }

    /**
     * @brief Gets the y offset (position)
     * 
     * @return float 
     */
    float getOffset()
    {
        return offset;
    }

    /**
     * @brief Enables auto y-offset
     */
    void setAutoOffset()
    {
        autooffset = true;
    }

    /**
     * @brief Sets a manual y-offset
     * 
     * @param ofst 
     */
    void setManualOffset(float ofst)
    {
        autooffset = false;
        offset = ofst;
    }

    /**
     * @brief Gets the scaling factor for the y values
     * 
     * @return float 
     */
    float getScalingFactor()
    {
        return scalingfactor;
    }

    /**
     * @brief Enables auto y-scaling
     */
    void setAutoScaling()
    {
        autoscaling = true;
    }

    /**
     * @brief Sets a manual y-scaling
     * 
     * @param scaling 
     */
    void setManualScaling(float scaling)
    {
        autoscaling = false;
        scalingfactor = scaling;
    }
};

#endif