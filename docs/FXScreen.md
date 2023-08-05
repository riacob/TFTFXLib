# FXScreen

## Creating a new screen (also read the section about naming standards)
1. Copy examples/TemplateFXScreen.h, to your working directory
2. Edit TemplateFXScreen.h as you please. Refer to the codeguards and the guide below. You can use the examples provided in examples/screens/
3. Edit FXScreens.h, adding a new screen to the enum with the name you like, as described in docs/FXScreens.md
4. Edit FXScreenManager.h, adding your newly created screen, as described in docs/FXScreenManager.md

## Renaming your screen and naming standards
By default, your screen will be called "ExampleFXScreen".
<br>
You will probably want to change that, so here's how you do it:
<br>
Suppose you want to call your new screen "Settings".
<br>
Please note you can have only a screen with a given name.
<br>
"Settings1" and "Settings2" would be fine, but two "Settings" cannot coexist.

1. Rename the header file to "SettingsScreen.h"
2. Replace the include guards
```cpp
#ifndef SETTINGSSCREEN_H
#define SETTINGSSCREEN_H
```
3. Rename the namespace to "SettingsNamespace"
4. Rename the class name to "SettingsScreen"
5. Rename the constructor and destructor to "SettingsScreen" and "~SettingsScreen" respectively.
6. In "Screens.h", your screen should be called "SETTINGS"

## Codeguard sections

### 🟢 INCLUDE_WIDGETS
Used to include the widgets the screen uses.
```cpp
#include <FXButton.h>
...
```

### 🟢 NAMESPACE_CALLBACKS
Used to define callbacks which live inside the global namespace ExampleScreenNamespace (widgets' callbacks to be defined here).
```cpp
void myButtonCallback() {
    w->jumpToScreen(FXScreens::MAIN);
}
```

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