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
    PwdScreen(TFT_eSPI *t, size_t windowID) : FXWindow(t, windowID)
    {
        w = (FXWindow *)this;
        PwdScreenNamespace::w = w;
    }
    void drawUI() override
    {
        /* MAIN USER CODE BEGIN */

        FXButton btn1(w);
        /*FXButton btn2(w);
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
        FXButton textBox(w);*/

        btn1.setPosition(0, 50);
        btn1.setSize(50, 50);
        btn1.setButtonBackgroundColor(TFT_BLACK);

        /*btn0.draw();*/
        btn1.draw();
        /*btn2.draw();
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

        btn0.touchAt(touchx,touchy);*/
        btn1.touchAt(touchx,touchy);
        /*btn2.touchAt(touchx,touchy);
        btn3.touchAt(touchx,touchy);
        btn4.touchAt(touchx,touchy);
        btn5.touchAt(touchx,touchy);
        btn6.touchAt(touchx,touchy);
        btn7.touchAt(touchx,touchy);
        btn8.touchAt(touchx,touchy);
        btn9.touchAt(touchx,touchy);
        btnA.touchAt(touchx,touchy);
        btnB.touchAt(touchx,touchy);
        btnC.touchAt(touchx,touchy);
        btnD.touchAt(touchx,touchy);
        btnSTAR.touchAt(touchx,touchy);
        btnHASH.touchAt(touchx,touchy);*/

        /* MAIN USER CODE END */

        w->resetTouch();
    }
};

#endif