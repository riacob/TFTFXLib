/**
 * @file FXButton.h
 * @author Riccardo Iacob
 * @brief FXButton Widget Class
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
#include "FXScreen.h"

class FXButton : public FXWidget
{
public:
    /**
     * @brief Button shapes
     *
     */
    enum class FXButtonStyles
    {
        FILL_ROUND_RECT,
        FILL_ELLIPSE,
        FILL_RECT_H_GRADIENT,
        FILL_RECT_V_GRADIENT
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
private:
    // Callback pointer on button press
    void (*pressedcallback)();
    bool pressedcallbackset = false;
protected:
    // Size X of the button inside the sprite
    uint16_t btnsizex = 0;
    // Size Y of the button inside the sprite
    uint16_t btnsizey = 0;
    // Start X of the button
    uint16_t btnstartx = 0;
    // Start Y of the button
    uint16_t btnstarty = 0;

    // Shape of the button
    FXButtonStyles btnstyle = FXButtonStyles::FILL_ROUND_RECT;
    // Button corner radius
    uint16_t btncornerradius = 0;
    // Button colors if style is FILL_RECT_H_GRADIENT or FILL_RECT_V_GRADIENT
    uint32_t btncolor1 = TFT_WHITE;
    uint32_t btncolor2 = TFT_BLACK;

    // Contents of the button
    FXButtonContentTypes btncontenttype = FXButtonContentTypes::TEXT;
    // Button text if content type is TEXT
    String btntext = "";
    // Button font if content type is TEXT
    uint8_t btnfont = 2;
    // Button font size if content type is TEXT
    uint8_t btnfontsize = 1;
    // Icon path if content type is ICON
    uint8_t *btnicon = {0};

    // Border of the button
    bool btnborder = false;
    uint16_t btnborderthickness = 1;
    uint32_t btnbordercolor = TFT_WHITE;

    // Background color of the button
    uint32_t btnbgcolor = TFT_WHITE;
    // Foreground color of the button
    uint32_t btnfgcolor = TFT_BLACK;

public:
    /**
     * @brief Constructs a new FXButton object
     *
     * @param parent: The screen in which the button (widget) is in
     */
    FXButton(FXScreen *parent) : FXWidget(parent)
    {
    }

    /**
     * @brief Sets the position of the widget
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
        btnstartx = 0;
        btnstarty = 0;
        widgetsizex = btnsizex;
        widgetsizey = btnsizey;
        // widgetstartx = btnstartx;
        // widgetstarty = btnstarty;
        //  create the widget
        createWidget();
        // Draw widget background
        widget->fillRect(0, 0, widgetsizex, widgetsizey, widgetbgcolor);
        // add button to the widget
        switch (btnstyle)
        {
        case FXButtonStyles::FILL_ROUND_RECT:
        {
            widget->fillRoundRect(btnstartx, btnstarty, btnsizex, btnsizey, btncornerradius, btnbgcolor);
            if (btnborder)
            {
                for (uint16_t i = 0; i < btnborderthickness; i++)
                {
                    widget->drawRoundRect(btnstartx + i, btnstarty + i, btnsizex - 2 * i, btnsizey - 2 * i, btncornerradius - i, btnbordercolor);
                }
            }
            break;
        }
        case FXButtonStyles::FILL_ELLIPSE:
        {
            uint16_t ellipsex = btnstartx + btnsizex / 2;
            uint16_t ellipsey = btnstarty + btnsizey / 2;
            widget->fillEllipse(ellipsex, ellipsey, btnsizex / 2, btnsizey / 2, btnbgcolor);
            if (btnborder)
            {
                for (uint16_t i = 0; i < btnborderthickness; i++)
                {
                    widget->drawEllipse(ellipsex, ellipsey, (btnsizex) / 2 - i, (btnsizey) / 2 - i, btnbordercolor);
                }
            }
            break;
        }
        case FXButtonStyles::FILL_RECT_H_GRADIENT:
        {
            widget->fillRectHGradient(btnstartx, btnstarty, btnsizex, btnsizey, btncolor1, btncolor2);
            if (btnborder)
            {
                for (uint16_t i = 0; i < btnborderthickness; i++)
                {
                    widget->drawRect(btnstartx + i, btnstarty + i, btnsizex - 2 * i, btnsizey - 2 * i, btnbordercolor);
                }
            }
            break;
        }
        case FXButtonStyles::FILL_RECT_V_GRADIENT:
        {
            widget->fillRectVGradient(btnstartx, btnstarty, btnsizex, btnsizey, btncolor1, btncolor2);
            if (btnborder)
            {
                for (uint16_t i = 0; i < btnborderthickness; i++)
                {
                    widget->drawRect(btnstartx + i, btnstarty + i, btnsizex - 2 * i, btnsizey - 2 * i, btnbordercolor);
                }
            }
            break;
        }
        }
        // add text or icon to the button
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
            widget->drawString(btntext, startX, startY);
            break;
        }
        case FXButtonContentTypes::ICON:
        {
            widget->drawXBitmap(btnstartx, btnstarty, btnicon, btnsizex, btnsizey, btnfgcolor);
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
        pressedcallbackset = true;
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
        if (x > widgetstartx && x < widgetstartx + btnsizex && y > widgetstarty && y < widgetstarty + btnsizey)
        {
            if (pressedcallbackset) {pressedcallback();}
        }
    }

    /**
     * @brief Sets the shape of the button
     *
     * @param style: Shape of the button
     */
    void setButtonStyle(FXButtonStyles style)
    {
        btnstyle = style;
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

    /**
     * @brief Sets the button text. Mutual alternative to setButtonIcon().
     *
     * @param text
     * @param font
     * @param fontSize
     */
    void setButtonText(String text, uint8_t font, uint8_t fontSize)
    {
        btncontenttype = FXButtonContentTypes::TEXT;
        btntext = text;
        btnfont = font;
        btnfontsize = fontSize;
    }

    /**
     * @brief Sets the button's icon. Mutual alternative to setButtonText().
     *
     * @param icon
     */
    void setButtonIcon(uint8_t *icon)
    {
        btncontenttype = FXButtonContentTypes::ICON;
        btnicon = icon;
    }

    /**
     * @brief Sets the gradient colors if using FXButtonStyles::FILL_H_GRADIENT or FXButtonStyles::FILL_V_GRADIENT
     *
     * @param color1: The first (leftmost or downmost) color
     * @param color2: The second (rightmost or upmost) color
     */
    void setButtonGradientColors(uint32_t color1, uint32_t color2)
    {
        btncolor1 = color1;
        btncolor2 = color2;
    }

    /**
     * @brief Sets a border for the button according to the given parameters
     *
     * @param thickness: Border thickness in px
     * @param color: Border color
     */
    void setButtonBorder(uint16_t thickness, uint32_t color)
    {
        btnborder = true;
        btnborderthickness = thickness;
        btnbordercolor = color;
    }

    /**
     * @brief Removes the button's border
     *
     */
    void removeButtonBorder()
    {
        btnborder = false;
    }

    /**
     * @brief Sets the corner radius of the rounded rectangle if using FXButtonStyles::FILL_ROUND_RECT
     *
     * @param radius: Corner radius
     */
    void setCornerRadius(uint16_t radius)
    {
        btncornerradius = radius;
    }
};

#endif