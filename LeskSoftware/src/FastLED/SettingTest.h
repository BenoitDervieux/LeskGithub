#ifndef SETTINGTEST_H
#define SETTINGTEST_H

#include <FastLED.h>
//
//
// NEED TO CONTINUE THE IMPLEMENTATION ZEUBI
class SettingTest {
    public: 
        static CRGB             color;
    public:
        static CRGB getColor() {return color;};
        static void setColor(CRGB newColor) {color = newColor;};
};

#endif