# WORK IN PROGRESS DOCUMENTATION - WILL BE CONVERTED TO WIKI

# FXScreen
### 🟢 INCLUDE_WIDGETS
Used to include the widgets the screen uses.
```cpp
#include <FXButton.h>
...
```
### 🟢 NAMESPACE_DEFINITIONS
Used to define variables and constants which live inside the global namespace ExampleScreenNamespace.
### 🟢 NAMESPACE_CALLBACKS
Used to define callbacks which live inside the global namespace ExampleScreenNamespace (widgets' callbacks to be defined here).
```cpp
void myButtonCallback() {
    w->jumpToScreen(FXScreens::MAIN);
}
```
### 🟢 PROTECTED_DEFINITIONS
Used to define protected variables and constants which live inside the class ExampleScreen.
### 🟢 PUBLIC_DEFINITIONS
Used to define public variables and constants which live inside the class ExampleScreen.
### 🟢 PRIVATE_DEFINITIONS
Used to define private variables and constants which live inside the class ExampleScreen.
### 🟢 CONSTRUCTOR
Used to instantiate additional user-defined objects at the class' initialization.
### 🟢 DESTRUCTOR
Used to de-instantiate additional user-defined objects at the class' deinitialization.
### 🟢 MAIN
Used to write the main screen code.
Runs user methods to instantiate, draw and edit widgets.
```cpp
FXButton myButton(w);
myButton.setPressedCallback(ExampleScreenNamespace::myButtonCallback);
myButton.setSize(50,50);
myButton.setPosition(20,20);
myButton.draw();
myButton.touchAt(touchx, touchy);
```

# FXWidget

# FXWindowManager

# Calibration
1. Run [this sketch](https://github.com/Bodmer/TFT_eSPI/blob/master/examples/Generic/Touch_calibrate/Touch_calibrate.ino) to get the screen's calibration values.
2. Enter the 5 values inside the codeguard section "TOUCH_CALIBRATION" in main.cpp
3. Enjoy!