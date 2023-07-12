# Using the library
The library is still in early development, thus the documentation is practically non-existant.
<br>
Refer to the comments in the code (especially in *screen*.h and FXWindowManager.h) to understand how to setup the library to create windows with widgets.
<br>
To create a new widget, you should implement the parent class FXWidget() and build the new widget similarly to the existing ones.
<br>
Widgets are mainly composed of a draw() method and some style/content settings, as well as callback function settings.