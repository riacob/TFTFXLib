/**
 * @file MyScreen.h
 * @author Riccardo Iacob
 * @brief
 * @version 0.1
 * @date 2023-07-12
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef MYSCREEN_H
#define MYSCREEN_H

#include "FXWindow.h"
#include "FXButton.h"
#include "FXGraph.h"

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

        // Create fake graph data
        float yvals[100];
        int i, j;
        for (i = 0; i < 20; i++)
        {
            yvals[i] = 20;
        }
        for (i; i < 40; i++)
        {
            yvals[i] = -35;
        }
        for (i; i < 60; i++)
        {
            yvals[i] = 67;
        }
        for (i; i < 100; i++)
        {
            yvals[i] = 33;
        }

        // FXButton btn1(w);
        // w->tft->fillScreen(TFT_WHITE);
        FXButton btn2(w);
        FXGraph graph(w);
        btn2.setPressedCallback(MyScreenCallbacks::btn2callback);
        graph.setPosition(63, 250);
        graph.setSize(100, 100);
        graph.setData(yvals, 100);
        //graph.setScalingFactor(1.0);
        // btn1.setSize(70, 30);
        btn2.setButtonStyle(FXButton::FXButtonStyles::FILL_RECT_V_GRADIENT);
        btn2.setButtonGradientColors(TFT_BLUE, TFT_YELLOW);
        btn2.setButtonBorder(4, TFT_CYAN);
        btn2.setSize(250, 90);
        btn2.setCornerRadius(45);
        btn2.setPosition(20, 120);
        btn2.setButtonBackgroundColor(TFT_PURPLE);
        btn2.setButtonForegroundColor(TFT_WHITE);
        btn2.setButtonText("Button", 2, 1);
        // btn1.draw();
        graph.draw();
        btn2.draw();
        btn2.touchAt(touchx, touchy);

        /* MAIN USER CODE END */
    }
};

#endif