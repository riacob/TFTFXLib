/**
 * @file MyScreenTemplate.h
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

namespace MyScreenCallbacks
{
    FXWindow *w;
    /* USER CALLBACKS BEGIN */
    /* USER CALLBACKS END */
};

class MyScreen : public FXWindow
{
private:
    FXWindow *w;

public:
    /* BEGIN PUBLIC USER METHODS AND PARAMETERS */
    /* END PUBLIC USER METHODS AND PARAMETERS  */
private:
    /* BEGIN PRIVATE USER METHODS AND PARAMETERS */
    /* END PRIVATE USER METHODS AND PARAMETERS */
public:
    MyScreen(TFT_eSPI *t) : FXWindow(t)
    {
        w = (FXWindow *)this;
        MyScreenCallbacks::w = w;
    }
    void drawUI() override
    {
        /* BEGIN USER UI CODE */
        /* END USER UI CODE */
    }
};

#endif