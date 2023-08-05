# FXScreenManager

## Adding a newly created screen
Suppose we want to add a "Settings" screen.
1. Include the screen's header file inside the codeguard section "INCLUDE_SCREENS"
```cpp
/* BEGIN SECTION INCLUDE_SCREENS */
...
#include "SettingsScreen.h"
...
/* END SECTION INCLUDE_SCREENS */
```
2. Call the _HANDLEWINDOWINSTANCE macro inside the codeguard section "INSTANCE_HANDLERS", first parameter is the class name, second parameter is the element of the FXScreens enum. If the naming conventions were followed, the first parameter should be SettingsScreen and the second FXScreens::SETTINGS
```cpp
    void doTick()
    {
        ...
        /* BEGIN SECTION INSTANCE_HANDLERS */
        ...
        _HANDLEWINDOWINSTANCE(SettingsScreen, FXScreens::SETTINGS);
        ...
        /* END SECTION INSTANCE_HANDLERS */
        ...
    }
```

## Codeguard sections

### 🟢 INCLUDE_SCREENS
Used to include all the screens present in the program.

### 🟢 INSTANCE_HANDLERS
Used to handle all the screens' instances (creating, deleting and updating them).