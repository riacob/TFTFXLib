/**
 * @file FXWindowManager.h
 * @author Riccardo Iacob
 * @brief 
 * @version 0.1
 * @date 2023-07-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef FXWINDOWMANAGER_H
#define FXWINDOWMANAGER_H

#include "Includes.h"
#include "FXWindow.h"

class FXWindowManager {
    public:
    enum WindowNames {
        /* USER WINDOWNAMES BEGIN */
        /* USER WINDOWNAMES END */
    };
    protected:
    FXWindow** windows;
    size_t windowcount = 1;
    size_t currentwindow = 0;
    TFT_eSPI *tft;
    public:
    FXWindowManager(TFT_eSPI *t) {
        tft = t;
    }
    size_t getWindowCount() 
    {
        return windowcount;
    }
    size_t getCurrentWindow()
    {
        return currentwindow;
    }
    void addWindow(FXWindow* w)
    {
        windows[windowcount-1] = w;
    }
    void drawWindow(size_t w)
    {
        if (w > windowcount) {
            return;
        }
        windows[w]->drawUI();
    }
};

#endif