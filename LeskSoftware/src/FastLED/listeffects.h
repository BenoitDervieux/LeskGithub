#ifndef LISTEFFECTS_H
#define LISTEFFECTS_H

#include "defineeffects.h"
#include "defineeffectsettings.h"
#include "Settings.h"


// The idea of this structure is to get the parameters of the effect as well as it's name
// For instance, let's take the effects "blink"
// The effect can have a first paramater which will be the time of blinking, then the time of pause
// This is just a test and we'll see later what happens
struct Effect {
    const char* name;
    int effect;
    std::function<int()> settings[10];
    const char* settingNames[10];
    int minValues[10];
    int maxValues[10];
    const char* realNames[10];
    int numSettings;
};

static Effect _fill_effect = {
    "Fill", FX_MODE_FILL, 
    {[]() { return Settings::getR(); }, []() { return Settings::getG(); }, []() { return Settings::getB(); }}, 
    {"Red", "Green", "Blue"}, 
    {0, 0, 0}, 
    {255, 255, 255}, 
    {"r", "g", "b"}, 
    3
};
static Effect _blink = {
    "Blink", FX_MODE_BLINK, 
    {[]() { return Settings::getR(); }, []() { return Settings::getG(); }, []() { return Settings::getB(); }, []() { return Settings::getTidBlink(); }}, 
    {"Red", "Green", "Blue", "Time"}, 
    {0, 0, 0, 30}, 
    {255, 255, 255, 1000}, 
    {"r", "g", "b", "tid_blink"}, 
    4
}; 

static Effect _rainbowStatic = {
    "Rainbow Static", FX_MODE_RAINBOW_STATIC, 
    nullptr,nullptr,nullptr,nullptr,nullptr, 
    0
};
static Effect _fillGradientTwoColors = {
    "Fill Gradient 2 Colors", FX_MODE_FILL_GRADIENT_TWO_COLORS,
    {[]() { return Settings::getR(); }, []() { return Settings::getG(); }, []() { return Settings::getB(); }, []() { return Settings::getR2(); }, []() { return Settings::getG2(); }, []() { return Settings::getB2(); }},
    {"Red", "Green", "Blue", "Red 2", "Green 2", "Blue 2"},
    {0,0,0,0,0,0},
    {255, 255, 255, 255, 255, 255},
    {"r", "g", "b", "r2", "g2", "b2"},
    6
};
static Effect _fillGradientThreeColors = {
    "Fill Gradient 3 Colors", FX_MODE_FILL_GRADIENT_THREE_COLORS,
    {[]() { return Settings::getR(); }, []() { return Settings::getG(); }, []() { return Settings::getB(); }, []() { return Settings::getR2(); }, []() { return Settings::getG2(); }, []() { return Settings::getB2(); }, []() { return Settings::getR3(); }, []() { return Settings::getG3(); }, []() { return Settings::getB3(); }},
    {"Red", "Green", "Blue", "Red 2", "Green 2", "Blue 2", "Red 3", "Green 3", "Blue 3"},
    {0,0,0,0,0,0,0,0,0},
    {255, 255, 255, 255, 255, 255, 255, 255, 255},
    {"r", "g", "b", "r2", "g2", "b2", "r3", "g3", "b3"},
    9
};

static Effect _BackAndForthNoSmoothOneDot = {
    "Back and Forth No Smooth One Dot", FX_MODE_BACK_AND_FORTH_NO_SMOOTH_ONE_DOT,
    {[]() { return Settings::getR(); }, []() { return Settings::getG(); }, []() { return Settings::getB(); }, []() { return Settings::getTidBackAndForthNoSmoothOneDot();}},
    {"Red", "Green", "Blue", "Time"},
    {0,0,0,1},
    {255, 255, 255, 500},
    {"r", "g", "b", "tid_backAndForthNoSmoothOneDot"},
    4
};

static Effect _backAndForthNoSmoothLengthedDot {
    "Back and Forth No Smooth Lengthed Dot", FX_MODE_BACK_AND_FORTH_NO_SMOOTH_LENGHTED_DOT,
    {[]() { return Settings::getR(); }, []() { return Settings::getG(); }, []() { return Settings::getB(); }, []() { return Settings::getTidBackAndForthNoSmoothLengthedDot();}, []() { return Settings::getLengthBackAndForthNoSmoothLengthedDot();}},
    {"Red", "Green", "Blue", "Time", "Length"},
    {0,0,0,1, 1},
    {255, 255, 255, 500, 8},
    {"r", "g", "b", "tid_backAndForthNoSmoothLengthedDot", "length_backAndForthNoSmoothLengthedDot"},
    5
};

static Effect _hueFading {
    "Hue Fading", FX_MODE_HUE_FADING,
    {[]() {return Settings::getTidHueFading();}},
    {"Time"},
    {0},
    {500},
    {"tid_hueFading"},
    1
};

static Effect _hueWhiteWave {
    "Hue White Wave", FX_MODE_HUE_WHITE_WAVE,
    {[]() {return Settings::getHueInsert_hueWhiteWave();}, []() {return Settings::getTidHueWhiteWave();}},
    {"Hue", "Time"},
    {0,0},
    {255, 500},
    {"hueInsert_hueWhiteWave", "tid_hueWhiteWave"},
    2
};

static Effect _displayPaletteLinear {
    "Display Palette Linear", FX_MODE_DISPLAY_PALETTE_LINEAR,
    // Here we should have a palette chooser
    {nullptr},
    {},
    {},
    {},
    0
};

static Effect _movingPaletteLinear {
    "Moving Palette Linear", FX_MODE_MOVING_PALETTE_LINEAR,
    {[]() {return Settings::getTidMovingPaletteLinear();}},
    {"Time"},
    {1},
    {200},
    {"tid_movingPaletteLinear"},
    1
};


static Effect _end_effect = {nullptr, -1, {0}}; // End marker for effects array

static Effect effects[] = {_fill_effect, _blink, _rainbowStatic, _fillGradientTwoColors, _fillGradientThreeColors,
                            _BackAndForthNoSmoothOneDot, _backAndForthNoSmoothLengthedDot, _hueFading, _hueWhiteWave, 
                            _displayPaletteLinear, _movingPaletteLinear, _end_effect};




#endif