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
#include "FXHProgressBar.h"
#include "FXVProgressBar.h"
#include "FXHSwitch.h"

namespace MyScreenNamespace
{
    FXWindow *w;
    /* USER CALLBACKS BEGIN */
    void btn2callback()
    {
        // debugln("[myscreen.h] btn2 callback");
        w->tft->fillScreen(TFT_WHITE);
        w->jumpToWindow(FXScreens::CONFIG);
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
    MyScreen(TFT_eSPI *t, FXScreens windowID) : FXWindow(t, windowID)
    {
        w = (FXWindow *)this;
        MyScreenNamespace::w = w;
    }
    ~MyScreen() {
        /* user delete window heap-instantiated objects such as BMP images*/
    }
    void drawUI() override
    {
        /* MAIN USER CODE BEGIN */

        // Create fake graph data
        float yvals[200];
        int i, j;
        for (i = 0; i < 200; i++)
        {
            yvals[i] = random(-50, 50);
        }

        FXButton btn2(w);
        FXGraph graph(w);
        FXHProgressBar pbar(w);
        FXVProgressBar pbar2(w);
        FXHSwitch hsw(w);

        pbar.setPosition(10, 450);
        pbar.setSize(80, 20);
        pbar.setMultiplier(random(0, 999) / 1000.0);
        pbar.setCornerRadius(8);

        pbar2.setPosition(0, 0);
        pbar2.setSize(20, 80);
        pbar2.setMultiplier(random(0, 999) / 1000.0);
        pbar2.invert();

        graph.setPosition(63, 250);
        graph.setSize(200, 120);
        graph.setData(yvals, 200);
        graph.setGraphBackgroundColor(TFT_WHITE);
        graph.setGraphBorderColor(TFT_BLACK);
        graph.setGraphLineColor(TFT_BLACK);
        graph.setGraphDetailColor(TFT_LIGHTGREY);

        btn2.setPressedCallback(MyScreenNamespace::btn2callback);
        btn2.setButtonStyle(FXButton::FXButtonStyles::FILL_RECT_V_GRADIENT);
        btn2.setButtonGradientColors(TFT_BLUE, TFT_YELLOW);
        btn2.setButtonBorder(4, TFT_CYAN);
        btn2.setSize(250, 90);
        btn2.setCornerRadius(45);
        btn2.setPosition(20, 120);
        btn2.setButtonBackgroundColor(TFT_PURPLE);
        btn2.setButtonForegroundColor(TFT_BLACK);
        btn2.setButtonText("Button", 2, 1);

        hsw.setPosition(30, 30);
        hsw.setSize(100, 50);
        hsw.setCornerRadius(25);

        hsw.draw();
        graph.draw();
        btn2.draw();
        pbar.draw();
        pbar2.draw();

        btn2.touchAt(touchx, touchy);
        hsw.touchAt(touchx, touchy);

        /* MAIN USER CODE END */

        w->resetTouch();
    }
};

#endif