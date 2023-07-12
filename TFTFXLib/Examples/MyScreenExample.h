#ifndef MYSCREEN_H
#define MYSCREEN_H

#include "FXWindow.h"
#include "FXButton.h"

namespace MyScreenCallbacks
{
    FXWindow *w;
    /* USER CALLBACKS BEGIN */
    void btn2callback()
    {
        debugln("[myscreen.h] btn2 callback");
        w->tft->fillScreen(TFT_WHITE);
        w->jumpToWindow(1);
    }
    /* USER CALLBACKS END */
};

class MyScreen : public FXWindow
{
private:
    FXWindow *w;

public:
    /* PUBLIC USER METHODS AND PARAMETERS BEGIN */
    /* PUBLIC USER METHODS AND PARAMETERS END */
private:
    /* PRIVATE USER METHODS AND PARAMETERS BEGIN */
    /* PRIVATE USER METHODS AND PARAMETERS END*/
public:
    MyScreen(TFT_eSPI *t) : FXWindow(t)
    {
        w = (FXWindow *)this;
        MyScreenCallbacks::w = w;
    }
    void drawUI() override
    {
        // debugln("[screen.h] drawing ui");

        /* MAIN USER CODE BEGIN */

        // FXButton btn1(w);
        //w->tft->fillScreen(TFT_WHITE);
        FXButton btn2(w);
        btn2.setPressedCallback(MyScreenCallbacks::btn2callback);
        // btn1.setSize(70, 30);
        btn2.setButtonStyle(FXButton::FXButtonStyles::FILL_ROUND_RECT);
        btn2.setButtonBorder(4, TFT_CYAN);
        btn2.setSize(250, 90);
        btn2.setCornerRadius(45);
        btn2.setPosition(0, 0);
        btn2.setButtonBackgroundColor(TFT_PURPLE);
        btn2.setButtonForegroundColor(TFT_WHITE);
        btn2.setButtonText("Button", 2, 1);
        // btn1.draw();
        btn2.draw();
        btn2.touchAt(touchx, touchy);

        /* MAIN USER CODE END */
    }
};

#endif