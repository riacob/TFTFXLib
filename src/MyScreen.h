#ifndef MYSCREEN_H
#define MYSCREEN_H

#include "FXWindow.h"
#include "FXButton.h"
#include "FXWindowManager.h"

namespace MyScreenCallbacks {
/* USER CALLBACKS BEGIN */
void btn2callback()
{
    debugln("[screen.h] btn2 pressed");
}
/* USER CALLBACKS END */
};

class MyScreen : public FXWindow
{
private:
    TFT_eSPI *tft;
    FXWindow *w;
    FXWindowManager *wm;

public:
    /* PUBLIC USER METHODS AND PARAMETERS BEGIN */
    /* PUBLIC USER METHODS AND PARAMETERS END */
private:
    /* PRIVATE USER METHODS AND PARAMETERS BEGIN */
    /* PRIVATE USER METHODS AND PARAMETERS END*/
public:
    MyScreen(TFT_eSPI *t, FXWindowManager *manager) : FXWindow(t)
    {
    }
    void drawUI() override
    {
        //debugln("[screen.h] drawing ui");
        w = (FXWindow *)this;

        /* MAIN USER CODE BEGIN */

        //FXButton btn1(w);
        FXButton btn2(w);
        btn2.setPressedCallback(MyScreenCallbacks::btn2callback);
        //btn1.setSize(70, 30);
        btn2.setButtonStyle(FXButton::FXButtonStyles::FILL_ROUND_RECT);
        btn2.setButtonBorder(4,TFT_CYAN);
        btn2.setSize(250, 90);
        btn2.setCornerRadius(45);
        btn2.setPosition(0, 0);
        btn2.setButtonBackgroundColor(TFT_PURPLE);
        btn2.setButtonForegroundColor(TFT_WHITE);
        btn2.setButtonText("Button",2,1);
        //btn1.draw();
        btn2.draw();
        btn2.touchAt(touchx, touchy);

        /* MAIN USER CODE END */
    }
};

#endif