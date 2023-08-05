# FXScreens

## Adding a newly created screen
Add a screen name, preferably in caps, between the codeguards, followed by a comma. Suppose we want to add a "Settings" screen.
```cpp
enum class FXScreens
{
    ...
    /* BEGIN SECTION SCREENS */
    ...
    SETTINGS,
    ...
    /* END SECTION SCREENS */
    ...
};
```

## Codeguard sections

### 🟢 SCREENS
Used to define screen names as elements of the FXScreens enum.