/**
 * @file PwdScreen.h
 * @author Riccardo Iacob
 * @brief
 * @version 0.1
 * @date 2023-07-12
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef PWDSCREEN_H
#define PWDCREEN_H

#include "FXWindow.h"
#include "FXButton.h"
#include "FXGraph.h"
#include "FXHProgressBar.h"
#include "FXVProgressBar.h"
#include "FXHSwitch.h"

namespace PwdScreenNamespace
{
    FXWindow *w;
    /* USER CALLBACKS BEGIN */
    /* USER CALLBACKS END */
};

class PwdScreen : public FXWindow
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
    PwdScreen(TFT_eSPI *t, FXScreens windowID) : FXWindow(t, windowID)
    {
        w = (FXWindow *)this;
        PwdScreenNamespace::w = w;
    }
    ~PwdScreen() {
        /* user delete window heap-instantiated objects such as BMP images*/
    }
    void drawUI() override
    {
        /* MAIN USER CODE BEGIN */

        FXButton btn1(w);
        FXButton btn2(w);
        FXButton btn3(w);
        FXButton btn4(w);
        FXButton btn5(w);
        FXButton btn6(w);
        FXButton btn7(w);
        FXButton btn8(w);
        FXButton btn9(w);
        FXButton btn0(w);
        FXButton btnA(w);
        FXButton btnB(w);
        FXButton btnC(w);
        FXButton btnD(w);
        FXButton btnSTAR(w);
        FXButton btnHASH(w);
        FXButton textBox(w);

        // row1
        btn1.setPosition(0, 100);
        btn1.setSize(50, 50);
        btn1.setButtonBackgroundColor(TFT_BLUE);
        btn1.setButtonText("1", 2, 2);

        btn2.setPosition(50, 100);
        btn2.setSize(50, 50);
        btn2.setButtonBackgroundColor(TFT_BLUE);
        btn2.setButtonText("2", 2, 2);

        btn3.setPosition(100, 100);
        btn3.setSize(50, 50);
        btn3.setButtonBackgroundColor(TFT_BLUE);
        btn3.setButtonText("3", 2, 2);

        btnA.setPosition(150, 100);
        btnA.setSize(50, 50);
        btnA.setButtonBackgroundColor(TFT_BLUE);
        btnA.setButtonText("A", 2, 2);

        // row2
        btn4.setPosition(0, 150);
        btn4.setSize(50, 50);
        btn4.setButtonBackgroundColor(TFT_BLUE);
        btn4.setButtonText("4", 2, 2);

        btn5.setPosition(50, 150);
        btn5.setSize(50, 50);
        btn5.setButtonBackgroundColor(TFT_BLUE);
        btn5.setButtonText("5", 2, 2);

        btn6.setPosition(100, 150);
        btn6.setSize(50, 50);
        btn6.setButtonBackgroundColor(TFT_BLUE);
        btn6.setButtonText("6", 2, 2);

        btnB.setPosition(150, 150);
        btnB.setSize(50, 50);
        btnB.setButtonBackgroundColor(TFT_BLUE);
        btnB.setButtonText("B", 2, 2);

        btn0.draw();
        btn1.draw();
        btn2.draw();
        btn3.draw();
        btn4.draw();
        btn5.draw();
        btn6.draw();
        btn7.draw();
        btn8.draw();
        btn9.draw();
        btnA.draw();
        btnB.draw();
        btnC.draw();
        btnD.draw();
        btnSTAR.draw();
        btnHASH.draw();
        textBox.draw();

        btn0.touchAt(touchx, touchy);
        btn1.touchAt(touchx, touchy);
        btn2.touchAt(touchx, touchy);
        btn3.touchAt(touchx, touchy);
        btn4.touchAt(touchx, touchy);
        btn5.touchAt(touchx, touchy);
        btn6.touchAt(touchx, touchy);
        btn7.touchAt(touchx, touchy);
        btn8.touchAt(touchx, touchy);
        btn9.touchAt(touchx, touchy);
        btnA.touchAt(touchx, touchy);
        btnB.touchAt(touchx, touchy);
        btnC.touchAt(touchx, touchy);
        btnD.touchAt(touchx, touchy);
        btnSTAR.touchAt(touchx, touchy);
        btnHASH.touchAt(touchx, touchy);

        /* MAIN USER CODE END */

        w->resetTouch();
    }
};

#endif