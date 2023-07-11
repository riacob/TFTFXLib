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
public:
    /**
     * @brief Button shapes
     *
     */
    enum class FXButtonShapes
    {
        RECT,
        ROUND_RECT,
        ELLIPSE
    };

    /**
     * @brief Contents of the button
     *
     */
    enum class FXButtonContentTypes
    {
        ICON,
        TEXT
    };

protected:
    // Size X of the button inside the sprite
    uint16_t btnsizex = 0;
    // Size Y of the button inside the sprite
    uint16_t btnsizey = 0;
    // Start X of the button
    uint16_t btnstartx = 0;
    // Start Y of the button
    uint16_t btnstarty = 0;
    // Callback pointer on button press
    void (*pressedcallback)();
    // Shape of the button
    FXButtonShapes btnshape = FXButtonShapes::RECT;
    // Contents of the button
    FXButtonContentTypes btncontenttype = FXButtonContentTypes::TEXT;
    // Button text if content type is TEXT
    String btntext = "";
    uint8_t btnfont = 2;
    uint8_t btnfontsize = 1;
    // Icon path if content type is ICON
    uint8_t *btnicon = {0};
    // Background color of the button
    uint32_t btnbgcolor = TFT_WHITE;
    // Foreground color of the button
    uint32_t btnfgcolor = TFT_BLACK;

public:
    FXButton(FXWindow *w) : FXWidget(w)
    {
        parent = w;
        _tft = w->tft;
    }
    /**
     * @brief Sets the position of the button
     *
     * @param x: X position
     * @param y: Y position
     */
    void setPosition(uint16_t x, uint16_t y)
    {
        btnstartx = x;
        btnstarty = y;
    }
    /**
     * @brief Sets the size of the button
     *
     * @param sizeX: x size
     * @param sizeY: y size
     */
    void setSize(uint16_t sizeX, uint16_t sizeY)
    {
        btnsizex = sizeX;
        btnsizey = sizeY;
    }
    /**
     * @brief Renders the button on the screen
     */
    void draw()
    {
        // If no tooltip is present we don't need to make the
        // widget size any bigger than the button size
        widgetsizex = btnsizex;
        widgetsizey = btnsizey;
        widgetstartx = btnstartx;
        widgetstarty = btnstarty;
        // create the widget
        createWidget();
        // add button to the widget
        switch (btnshape)
        {
        case FXButtonShapes::RECT:
        {
            // Draw widget background
            widget->fillRect(widgetstartx, widgetstarty, widgetsizex, widgetsizey, widgetbgcolor);
            // Draw button background
            widget->fillRect(btnstartx, btnstarty, btnsizex, btnsizey, btnbgcolor);
            break;
        }
        case FXButtonShapes::ROUND_RECT:
        {
            // Draw widget background
            // Draw button background
            break;
        }
        case FXButtonShapes::ELLIPSE:
        {
            // Draw widget background
            // Draw button background
            break;
        }
        }
        // add text or icon to the widget
        switch (btncontenttype)
        {
        case FXButtonContentTypes::TEXT:
        {
            // Align text in the center of the button
            widget->setTextSize(btnfontsize);
            widget->setTextFont(btnfont);
            widget->setTextColor(btnfgcolor);
            uint8_t fontSizeY = widget->fontHeight();
            uint8_t fontSizeX = widget->textWidth(btntext, btnfont);
            uint16_t startX = btnstartx + ((btnsizex - fontSizeX) / 2);
            uint16_t startY = btnstarty + ((btnsizey - fontSizeY) / 2);
            // Print the text
            widget->drawString(btntext,startX,startY);
            break;
        }
        case FXButtonContentTypes::ICON:
        {
            break;
        }
        }
        // draw the widget on the screen
        drawWidget();
        // delete the widget from PSRAM
        deleteWidget();
    }
    /**
     * @brief Sets the callback that gets called when the button gets pressed
     *
     * @param f: Callback function
     */
    void setPressedCallback(void (*f)())
    {
        pressedcallback = f;
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
        if (x > btnstartx && x < btnstartx + btnsizex && y > btnstarty && y < btnstarty + btnsizey)
        {
            // debugln("[fxbutton.h] touched");
            pressedcallback();
        }
    }
    /**
     * @brief Sets the shape of the button
     *
     * @param shape: Shape of the button
     */
    void setButtonShape(FXButtonShapes shape)
    {
        btnshape = shape;
    }
    /**
     * @brief Sets the foreground color of the button
     *
     * @param color: Foreground color
     */
    void setButtonForegroundColor(uint32_t color)
    {
        btnfgcolor = color;
    }
    /**
     * @brief Sets the background color of the button
     *
     * @param color: Background color
     */
    void setButtonBackgroundColor(uint32_t color)
    {
        btnbgcolor = color;
    }
    void setButtonText(String text, uint8_t font, uint8_t fontSize) {
        btncontenttype = FXButtonContentTypes::TEXT;
        btntext = text;
        btnfont = font;
        btnfontsize = fontSize;
    }
    void setButtonIcon(uint8_t *icon) {
        btncontenttype = FXButtonContentTypes::ICON;
        btnicon = icon;
    }
};

#endif