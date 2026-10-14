# ESP32_CoelaWS35Board

This is firmware for a potential LED board I may use in my LED face display project. The WS35 V1 board is a open source board by Coela Can't which uses WS2812B addressable LEDs. The board features an irregular shape so the solution was to make a look up table and replace normal (x, y) coordinates on a screen with index positions. In a regularly shaped display, a simple math function would of worked. The boards feature many places where LEDs do not exist within the bounding rectangle, so an error handling segment was added to let the table skip over them, as well a sections outside the rectangle. 

The boards can be addressed from front or back, or physically split to be addressed by both. I intended to write options for all 3 but did not have the means at the time, so will attempt again later if I use this option for my project.
