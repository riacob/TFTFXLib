/**
 * @file ExampleFXScreen.h
 * @author Riccardo Iacob
 * @brief Template for the creation of user-defined screens
 * @version 0.1
 * @date 2023-07-14
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef EXAMPLESCREEN_H
#define EXAMPLESCREEN_H

#include "FXScreen.h"
#include "FXScreens.h"

/* BEGIN SECTION INCLUDE_WIDGETS */
/* END SECTION INCLUDE_WIDGETS */

namespace ExampleScreenNamespace
{
    FXScreen *w;
    /* BEGIN SECTION NAMESPACE_CALLBACKS */
    /* END SECTION NAMESPACE_CALLBACKS */
};

class ExampleScreen : public FXScreen
{
private:
    FXScreen *w;
public:
    ExampleScreen(TFT_eSPI *t, FXScreens windowID) : FXScreen(t, windowID)
    {
        w = (FXScreen *)this;
        ExampleScreenNamespace::w = w;
    }
    ~ExampleScreen()
    {
    }
    void drawUI() override
    {
        /* BEGIN SECTION MAIN */
        /* END SECTION MAIN */
        w->resetTouch();
    }
};

#endif