/**
 * @file FXWindow.h
 * @author Riccardo Iacob
 * @brief 
 * @version 0.1
 * @date 2023-07-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef FXWINDOW_H
#define FXWINDOW_H

#include "Includes.h"

class FXWindow {
    public:
    TFT_eSPI *tft;
    public:
    FXWindow(TFT_eSPI* t) {
        tft = t;
    }
    virtual void drawUI() {}
};

#endif