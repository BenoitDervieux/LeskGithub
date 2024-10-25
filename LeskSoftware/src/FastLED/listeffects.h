#ifndef LISTEFFECTS_H
#define LISTEFFECTS_H

#include "defineeffects.h"
#include "Settings.h"
#include <iostream>
#include <vector>
#include <string>
#include <functional>


// The idea of this structure is to get the parameters of the effect as well as it's name
// For instance, let's take the effects "blink"
// The effect can have a first paramater which will be the time of blinking, then the time of pause
// This is just a test and we'll see later what happens



// struct Effect {
//     const char* name;
//     int effect;
//     std::function<int()> settings[11];
//     const char* settingNames[11];
//     int minValues[11];
//     int maxValues[11];
//     const char* realNames[11];
//     int numSettings;
// };

struct Effect {
    std::string name;  // Dynamic string storage for effect name
    int effect;

    std::vector<std::function<int()>> settings; // Store settings as a vector of functions
    std::vector<std::string> settingNames;       // Store setting names as a vector of strings
    std::vector<int> minValues;                   // Store min values as a vector
    std::vector<int> maxValues;                   // Store max values as a vector
    std::vector<std::string> realNames;           // Store real names as a vector

    // Full constructor to initialize all members
    Effect(const std::string& effectName, int effectCode,
           const std::vector<std::function<int()>>& settingsList,
           const std::vector<std::string>& names,
           const std::vector<int>& mins,
           const std::vector<int>& maxs,
           const std::vector<std::string>& realNams)
        : name(effectName), effect(effectCode),
          settings(settingsList), settingNames(names),
          minValues(mins), maxValues(maxs), realNames(realNams) {}
};

static Effect _fillEffect = {
    "Fill", 1,  // Effect name and effect code
    {            // Settings as lambda functions
        []() { return Settings::getR(); },
        []() { return Settings::getG(); },
        []() { return Settings::getB(); }
    }, 
    {            // Setting names
        "Red", "Green", "Blue"
    }, 
    {            // Min values
        0, 0, 0
    }, 
    {            // Max values
        255, 255, 255
    }, 
    {            // Real names
        "r", "g", "b"
    }
};
// static Effect _blink = {
//     "Blink", FX_MODE_BLINK, 
//     {[]() { return Settings::getR(); }, []() { return Settings::getG(); }, []() { return Settings::getB(); }, []() { return Settings::getTidBlink(); }}, 
//     {"Red", "Green", "Blue", "Time"}, 
//     {0, 0, 0, 30}, 
//     {255, 255, 255, 1000}, 
//     {"r", "g", "b", "tid_blink"}, 
//     4
// }; 

static Effect _blink(
    "Blink", // Effect name
    FX_MODE_BLINK, // Assuming FX_MODE_BLINK is defined as 1
    { // Settings as lambda functions
        []() { return Settings::getR(); },
        []() { return Settings::getG(); },
        []() { return Settings::getB(); },
        []() { return Settings::getTidBlink(); }
    },
    { // Setting names
        "Red", "Green", "Blue", "Time"
    },
    { // Min values
        0, 0, 0, 30
    },
    { // Max values
        255, 255, 255, 1000
    },
    { // Real names
        "r", "g", "b", "tid_blink"
    }
);



/*static Effect _fillEffect = {
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

static Effect _spotlightingPalette {
    "Spotlighting Palette", FX_MODE_SPOTLIGHTING_PALETTE,
    {[]() {return Settings::getTidSpotlightingPalette();}, []() {return Settings::getFade_spotlightingPalette();}},
    {"Time", "Fade"},
    {1,0},
    {200, 128},
    {"tid_spotlightingPalette", "fade_spotlightingPalette"},
    2
};

static Effect _sinBeat8 {
    "Sin Beat 8", FX_MODE_SIN_BEAT_8,
    {[]() {return Settings::getR();}, []() {return Settings::getG();}, []() {return Settings::getB();}, []() {return Settings::getFade_sinBeat8();}, []() {return Settings::getBpmSinBeat8();}},
    {"Red", "Green", "Blue", "Fade", "BPM"},
    {0,0,0,0,0},
    {255, 255, 255, 128, 128},
    {"r", "g", "b", "fade_sinBeat8", "bpm_sinBeat8"},
    5
};

static Effect _sinBeat8PhaseOffset {
    "Sin Beat 8 Phase Off", FX_MODE_SIN_BEAT_8_PHASE_OFF,
    {[]() {return Settings::getR();}, []() {return Settings::getG();}, []() {return Settings::getB();}, []() {return Settings::getFade_sinBeat8();}, []() {return Settings::getBpmSinBeat8();}, []() {return Settings::getSinBeat8PhaseOff_phaseOffset();}},
    {"Red", "Green", "Blue", "Fade", "BPM", "Phase Offset"},
    {0,0,0,0,0,0},
    {255, 255, 255, 128, 128, 128},
    {"r", "g", "b", "fade_sinBeat8", "bpm_sinBeat8", "sinBeat8PhaseOff_phaseOffset"},
    6
};

static Effect _sinBeat8TimeOff {
    "Sin Beat 8 Time Off", FX_MODE_SIN_BEAT_8_TIME_OFF,
    {[]() {return Settings::getR();}, []() {return Settings::getG();}, []() {return Settings::getB();}, []() {return Settings::getFade_sinBeat8();}, []() {return Settings::getBpmSinBeat8();}, [](){return Settings::getTidSinBeat8TimeOff();}},
    {"Red", "Green", "Blue", "Fade", "BPM", "Time"},
    {0,0,0,0,0,0},
    {255, 255, 255, 128, 128, 500},
    {"r", "g", "b", "fade_sinBeat8", "bpm_sinBeat8", "tid_sinBeat8TimeOff"},
    6
};

static Effect _twoSinBeat8 {
    "Two Sin Beat 8", FX_MODE_TWO_SIN_BEAT_8,
    {[]() { return Settings::getR(); }, []() { return Settings::getG(); }, []() { return Settings::getB(); }, []() { return Settings::getR2(); }, []() { return Settings::getG2(); }, []() { return Settings::getB2();}, []() {return Settings::getFade_sinBeat8();}, []() {return Settings::getBpmSinBeat8();}},
    {"Red", "Green", "Blue", "Red 2", "Green 2", "Blue 2", "Fade", "BPM"},
    {0,0,0,0,0,0,0,0},
    {255, 255, 255, 255, 255, 255, 128, 128},
    {"r", "g", "b", "r2", "g2", "b2","fade_sinBeat8", "bpm_sinBeat8"},
    8
};

static Effect _threeSinBeat8 {
    "Three Sin Beat 8", FX_MODE_THREE_SIN_BEAT_8, 
    {[]() { return Settings::getR(); }, []() { return Settings::getG(); }, []() { return Settings::getB(); }, []() { return Settings::getR2(); }, []() { return Settings::getG2(); }, []() { return Settings::getB2();}, []() { return Settings::getR3(); }, []() { return Settings::getG3(); }, []() { return Settings::getB3(); }, []() {return Settings::getFade_sinBeat8();}, []() {return Settings::getBpmSinBeat8();}},
    {"Red", "Green", "Blue", "Red 2", "Green 2", "Blue 2","Red 3", "Green 3", "Blue 3", "Fade", "BPM"},
    {0,0,0,0,0,0,0,0,0,0,0},
    {255, 255, 255, 255, 255, 255, 255, 255, 255,128, 128},
    {"r", "g", "b", "r2", "g2", "b2","r3", "g3", "b3","fade_sinBeat8", "bpm_sinBeat8"},
    11
};

static Effect _brightnessSinBeat8Palette {
    "Brightness Sin Beat 8 Palette", FX_MODE_BRIGHTNESS_SIN_BEAT_PALETTE,
    {[](){return Settings::getBpmSinBeat8();}, [](){return Settings::getTidBrightnessSinBeat8Palette();}},
    {"BPM", "Time"},
    {0,0},
    {128, 500},
    {"bpm_sinBeat8", "tid_brightnessSinBeat8Palette"},
    2
};

static Effect _funkyRainbowSinBeat8 {
    "Funky Rainbow Sin Beat 8", FX_MODE_FUNKY_RAINBOW_SIN_BEAT_8,
    {[]() {return Settings::getFade_sinBeat8();}},
    {"Fade"},
    {0},
    {128},
    {"fade_sinBeat8"},
    1
};

static Effect _funkyRangeSinBeat8 {
    "Funky Range Sin Beat 8",FX_MODE_FUNKY_RANGES_SIN_BEAT_8,
    {[](){return Settings::getFade_sinBeat8();}, [](){return Settings::getR();}, [](){return Settings::getG();}, [](){return Settings::getB();}},
    {"Fade", "Red", "Green", "Blue"},
    {0,0,0,0},
    {128, 255, 255, 255},
    {"fade_sinBeat8", "r", "g", "b"},
    4
};
    



static Effect _end_effect = {nullptr, -1, {0}}; // End marker for effects array

static Effect effects[] = {_fillEffect, _blink, _rainbowStatic, _fillGradientTwoColors, _fillGradientThreeColors,
                            _BackAndForthNoSmoothOneDot, _backAndForthNoSmoothLengthedDot, _hueFading, _hueWhiteWave, 
                            _displayPaletteLinear, _movingPaletteLinear, _spotlightingPalette, _sinBeat8, _sinBeat8PhaseOffset, 
                            _sinBeat8TimeOff, _twoSinBeat8, _threeSinBeat8,  _brightnessSinBeat8Palette, 
                            _funkyRainbowSinBeat8, _funkyRangeSinBeat8, _end_effect};
*/
static Effect _end_effect(
    "",         // Empty name to indicate it's an end marker
    -1,        // Invalid effect code
    {},        // Empty settings vector
    {},        // Empty setting names vector
    {},        // Empty min values vector
    {},        // Empty max values vector
    {}         // Empty real names vector
);
static Effect effects[] = {_fillEffect, _blink, _end_effect};




#endif