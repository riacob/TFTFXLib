# TODO

## Wigets
- FXPaint
- FXDropdownMenu

## Window examples
- PIN login
- Weather station

## Minor patches and fixes
- Inverted progressbar with rounded corners looks weird (because fg/bg are inverted and not the drawing process)

## Short term
- SDCard/SPIFFS icon parser, modifying [Bodmer's](https://github.com/Bodmer/TFT_eSPI/blob/master/examples/Generic/TFT_SPIFFS_BMP/BMP_functions.ino)
    - Parser loads BMP and modifies a BMP struct/class (passed as pointer as parameter) containing a "data validity" bit, size x and y, and the pixel array. This struct can be deleted after the icon is no longer in use (Since widgets are constantly deleted and redrawn, the pointer and delete call for the image shall be in the widgets which support icons).

## Long term
- Window creation wizard (JavaFX or Qt)
    - Allows user to create a window with widgets in a drag-and-drop enviroment
    - User can also configure style and callbacks of widgets, possibly with preview of entire screen
    - Automatically modifies FXWindowManager.h to integrate the window into the system