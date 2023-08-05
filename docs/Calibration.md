# Calibration
The touch controls might seem a little wonky. This is because at the factory the touch isn't calibrated, thus the registered touch porisions and the actual touch positions might differ a lot.
<br>
To get over this issue:
1. Run [this sketch](https://github.com/Bodmer/TFT_eSPI/blob/master/examples/Generic/Touch_calibrate/Touch_calibrate.ino) to get the screen's calibration values
2. Enter the 5 values inside the codeguard section "TOUCH_CALIBRATION" in main.cpp
3. Enjoy!