#ifndef MYSCREEN_H
#define MYSCREEN_H

#include "FXWindow.h"
#include "FXButton.h"

/* USER CALLBACKS BEGIN */
void btn2callback()
{
    debugln("[screen.h] btn1 pressed");
}
/* USER CALLBACKS END */

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

        // Create FXWidgets
        FXButton btn1(w);
        FXButton btn2(w);
        // Set callbacks
        btn2.setPressedCallback(btn2callback);
        // Edit created FXWidgets
        btn1.setSize(20, 20);
        btn2.setSize(250, 250);
        btn2.setPosition(100, 100);
        // Draw created FXWidgets
        btn1.draw();
        btn2.draw();
        // Check for touch on FXWidgets
        btn2.touchAt(touchx, touchy);

        /* MAIN USER CODE END */
    }
};

#endif