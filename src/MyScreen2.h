/**
 * @file MyScreen2.h
 * @author Riccardo Iacob
 * @brief
 * @version 0.1
 * @date 2023-07-12
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef MYSCREEN2_H
#define MYSCREEN2_H

#include "FXScreen.h"
#include "FXScreens.h"
#include "FXButton.h"

#include "icons/IconCog_63.h"

namespace MyScreen2Namespace
{
    FXScreen *w;
    /* USER CALLBACKS BEGIN */
    void btn2callback()
    {
        // debugln("[myscreen2.h] btn2 callback");
        w->tft->fillScreen(TFT_WHITE);
        w->jumpToScreen(FXScreens::MAIN);
    }
    /* USER CALLBACKS END */
};

class MyScreen2 : public FXScreen
{
private:
    FXScreen *w;

public:
    /* PUBLIC USER METHODS AND PARAMETERS BEGIN */
    /* PUBLIC USER METHODS AND PARAMETERS END */
private:
    /* PRIVATE USER METHODS AND PARAMETERS BEGIN */
    /* PRIVATE USER METHODS AND PARAMETERS END*/
public:
    MyScreen2(TFT_eSPI *t, FXScreens windowID) : FXScreen(t, windowID)
    {
        w = (FXScreen *)this;
        MyScreen2Namespace::w = w;
    }
    ~MyScreen2() {
        /* user delete window heap-instantiated objects such as BMP images*/
    }
    void drawUI() override
    {
        // debugln("[screen.h] drawing ui");

        /* MAIN USER CODE BEGIN */

        // FXButton btn1(w);
        // w->tft->fillScreen(TFT_YELLOW);
        FXButton btn2(w);
        btn2.setPressedCallback(MyScreen2Namespace::btn2callback);
        // btn1.setSize(70, 30);
        btn2.setButtonStyle(FXButton::FXButtonStyles::FILL_ELLIPSE);
        // btn2.setButtonBorder(4,TFT_CYAN);
        btn2.setSize(63, 63);
        // btn2.setCornerRadius(20);
        btn2.setPosition(40, 75);
        btn2.setButtonBackgroundColor(TFT_BLUE);
        btn2.setButtonForegroundColor(TFT_WHITE);
        btn2.setWidgetBackgroundColor(TFT_PURPLE);
        btn2.setButtonIcon(icon_cog_63);
        // btn2.setButtonText("Hello",2,1);
        //  btn1.draw();
        btn2.draw();
        btn2.touchAt(touchx, touchy);

        /* MAIN USER CODE END */

        w->resetTouch();
    }
};

#endif