#ifndef MYSCREEN_H
#define MYSCREEN_H

#include "FXWindow.h"
#include "FXButton.h"

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

public:
    /* PUBLIC USER METHODS AND PARAMETERS BEGIN */
    /* PUBLIC USER METHODS AND PARAMETERS END */
private:
    /* PRIVATE USER METHODS AND PARAMETERS BEGIN */
    /* PRIVATE USER METHODS AND PARAMETERS END*/
public:
    MyScreen(TFT_eSPI *t) : FXWindow(t)
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
        btn2.setSize(70, 30);
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