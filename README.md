# Using the library
NO  CONFIGURATION WIZARD IS YET AVAILABLE and won't be available unless enough interest and collaboration is shown to this library.
<br>
User creates and edits screens called MyScreen.h (unique name for each screen);
<br>
User edits FXWindowManager.h to handle all the screens they created; this allows a "state machine" behavior where the screen contents and touch mappings are automatically adjusted depending on the currently displayed window.