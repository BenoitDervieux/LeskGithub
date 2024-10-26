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



struct Effect {
    const char* name;
    int effect;
    std::function<int()> settings[11];
    const char* settingNames[11];
    int minValues[11];
    int maxValues[11];
    const char* realNames[11];
    int numSettings;
};


static Effect _fillEffect = {
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
    {255, 255, 255, 128, 140},
    {"r", "g", "b", "fade_sinBeat8", "bpm_sinBeat8"},
    5
};

static Effect _sinBeat8PhaseOffset {
    "Sin Beat 8 Phase Off", FX_MODE_SIN_BEAT_8_PHASE_OFF,
    {[]() {return Settings::getR();}, []() {return Settings::getG();}, []() {return Settings::getB();}, []() {return Settings::getFade_sinBeat8();}, []() {return Settings::getBpmSinBeat8();}, []() {return Settings::getSinBeat8PhaseOff_phaseOffset();}},
    {"Red", "Green", "Blue", "Fade", "BPM", "Phase Offset"},
    {0,0,0,0,0,0},
    {255, 255, 255, 128, 140, 128},
    {"r", "g", "b", "fade_sinBeat8", "bpm_sinBeat8", "sinBeat8PhaseOff_phaseOffset"},
    6
};

static Effect _sinBeat8TimeOff {
    "Sin Beat 8 Time Off", FX_MODE_SIN_BEAT_8_TIME_OFF,
    {[]() {return Settings::getR();}, []() {return Settings::getG();}, []() {return Settings::getB();}, []() {return Settings::getFade_sinBeat8();}, []() {return Settings::getBpmSinBeat8();}, [](){return Settings::getTidSinBeat8TimeOff();}},
    {"Red", "Green", "Blue", "Fade", "BPM", "Time"},
    {0,0,0,0,0,0},
    {255, 255, 255, 128, 140, 500},
    {"r", "g", "b", "fade_sinBeat8", "bpm_sinBeat8", "tid_sinBeat8TimeOff"},
    6
};

static Effect _twoSinBeat8 {
    "Two Sin Beat 8", FX_MODE_TWO_SIN_BEAT_8,
    {[]() { return Settings::getR(); }, []() { return Settings::getG(); }, []() { return Settings::getB(); }, []() { return Settings::getR2(); }, []() { return Settings::getG2(); }, []() { return Settings::getB2();}, []() {return Settings::getFade_sinBeat8();}, []() {return Settings::getBpmSinBeat8();}},
    {"Red", "Green", "Blue", "Red 2", "Green 2", "Blue 2", "Fade", "BPM"},
    {0,0,0,0,0,0,0,0},
    {255, 255, 255, 255, 255, 255, 128, 140},
    {"r", "g", "b", "r2", "g2", "b2","fade_sinBeat8", "bpm_sinBeat8"},
    8
};

static Effect _threeSinBeat8 {
    "Three Sin Beat 8", FX_MODE_THREE_SIN_BEAT_8, 
    {[]() { return Settings::getR(); }, []() { return Settings::getG(); }, []() { return Settings::getB(); }, []() { return Settings::getR2(); }, []() { return Settings::getG2(); }, []() { return Settings::getB2();}, []() { return Settings::getR3(); }, []() { return Settings::getG3(); }, []() { return Settings::getB3(); }, []() {return Settings::getFade_sinBeat8();}, []() {return Settings::getBpmSinBeat8();}},
    {"Red", "Green", "Blue", "Red 2", "Green 2", "Blue 2","Red 3", "Green 3", "Blue 3", "Fade", "BPM"},
    {0,0,0,0,0,0,0,0,0,0,0},
    {255, 255, 255, 255, 255, 255, 255, 255, 255,128, 140},
    {"r", "g", "b", "r2", "g2", "b2","r3", "g3", "b3","fade_sinBeat8", "bpm_sinBeat8"},
    11
};

static Effect _brightnessSinBeat8Palette {
    "Brightness Sin Beat 8 Palette", FX_MODE_BRIGHTNESS_SIN_BEAT_PALETTE,
    {[](){return Settings::getBpmSinBeat8();}, [](){return Settings::getTidBrightnessSinBeat8Palette();}},
    {"BPM", "Time"},
    {0,0},
    {140, 500},
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
    {128, 255,255,255},
    {"fade_sinBeat8", "r", "g", "b"},
    4
};

static Effect _funkyRainbowSinBeat8Two {
    "Funky Rainbow Sin Beat 8 Two", FX_MODE_FUNKY_RAINBOW_SIN_BEAT_8_TWO,
    {[]() {return Settings::getFade_sinBeat8();}},
    {"Fade"},
    {0},
    {128},
    {"fade_sinBeat8",},
    1
};

static Effect _funkyRangeSinBeat8Two {
    "Funky Range Sin Beat 8 Two", FX_MODE_FUNKY_RANGE_SIN_BEAT_8_TWO,
    {[](){return Settings::getFade_sinBeat8();}, [](){return Settings::getR();}, [](){return Settings::getG();}, [](){return Settings::getB();}},
    {"Fade", "Red", "Green", "Blue"},
    {0,0,0,0},
    {128, 255,255,255},
    {"fade_sinBeat8", "r", "g", "b"},
    4
};

static Effect _movingFunkyPalette {
    "Moving Funky Palette", FX_MODE_MOVING_FUNKY_PALETTE,
    {[](){return Settings::getFade_sinBeat8();}, [](){return Settings::getBpm2SinBeat8();}},
    {"BPM1", "BPM2"},
    {0,0},
    {140, 140},
    {"bpm_sinBeat8", "bpm2_sinBeat8"},
    2
};

static Effect _rainbowWave {
    "Rainbow Wave", FX_MODE_RAINBOW_WAVE,
    {[](){return Settings::getBpmSinBeat8();}, [](){return Settings::getTidRainbowWave();}, [](){return Settings::getFade_sinBeat8();}},
    {"BPM", "Time", "Fade"},
    {0,0,0},
    {140, 500, 128},
    {"bpm_sinBeat8", "tid_rainbowWave", "fade_sinBeat8"},
    3
};

static Effect _choosenWave {
    "Choosen Wave", FX_MODE_CHOOSEN_WAVE,
    {[](){return Settings::getTidChoosenWave();}, [](){return Settings::getBpmSinBeat8();}, [](){return Settings::getFade_sinBeat8();}, [](){return Settings::getR();}, [](){return Settings::getG();}, [](){return Settings::getB();}},
    {"Time", "BPM","Fade", "Red", "Green", "Blue"},
    {0,0,0,0,0,0},
    {500, 140, 128, 255, 255, 255},
    {"tid_choosenWave", "bpm_sinBeat8", "fade_sinBeat8", "r", "g", "b"},
    6
};

static Effect _firstNoiseRainbow {
    "First Noise Rainbow", FX_MODE_FIRST_NOISE_RAINBOW,
    {[](){return Settings::getBpmSinBeat8();}},
    {"BPM"},
    {0},
    {140},
    {"bpm_sinBeat8"},
    1
};

static Effect _firstNoiseColor {
    "First Noise Color", FX_MODE_FIRST_NOISE_COLORS,
    {[](){return Settings::getR();}, [](){return Settings::getG();}, [](){return Settings::getB();}, [](){return Settings::getBpmSinBeat8();}},
    {"Red", "Green", "Blue", "BPM"},
    {0,0,0,0},
    {255, 255, 255, 140},
    {"r", "g", "b", "bpm_sinBeat8"},
    4
};

static Effect _noisePalette {
    "Noise Palette", FX_MODE_NOISE_PALETTE,
    {[](){return Settings::getScaleNoisePalette();}},
    {"Scale"},
    {0},
    {144},
    {"scale_noisePalette"},
    1
};

static Effect _runFire {
    "Run Fire", FX_MODE_RUN_FIRE,
    {nullptr},
    {},
    {},
    {},
    0
};

static Effect _secondNoise {
    "Second Noise", FX_MODE_SECOND_NOISE,
    {nullptr},
    {},
    {},
    {},
    0
};

static Effect _fillNoise16 {
    "Fill Noise 16", FX_MODE_FILL_NOISE_16,
    {nullptr},
    {},
    {},
    {},
    0
};

static Effect _rainbowDave {
    "Rainbow Dave", FX_MODE_RAINBOW_DAVE,
    {[](){return Settings::getDensityRainbowDave();}, [](){return Settings::getDeltaRainbowDave();}, [](){return Settings::getTidBlink();}},
    {"Density", "Delta", "Time"},
    {0,0,0},
    {128, 128, 500},
    {"density_rainbowDave", "delta_rainbowDave", "tid_blink"},
    3
};

static Effect _marqueeDave {
    "Marquee Dave", FX_MODE_MARQUEE_DAVE,
    {[](){return Settings::getTidBlink();}, [](){return Settings::getDensityRainbowDave();}, []() { return Settings::getLengthBackAndForthNoSmoothLengthedDot();}},
    {"Time", "Density", "Length"},
    {0,0,2},
    {500, 128, 10},
    {"tid_blink", "density_rainbowDave", "length_backAndForthNoSmoothLengthedDot"},
    3
};

static Effect _twinkleOld {
    "Twinkle Old", FX_MODE_TWINKLE_OLD,
    {[](){return Settings::getTidBlink();}},
    {"Time"},
    {0},
    {500},
    {"tid_blink"},
    1
};

static Effect _twinkle {
    "Twinkle", FX_MODE_TWINKLE,
    {[](){return Settings::getTidBlink();}},
    {"Time"},
    {0},
    {500},
    {"tid_blink"},
    1
};

static Effect _comet {
    "Comet", FX_MODE_COMET,
    {[]() { return Settings::getTidBlink();}, []() { return Settings::getFade_sinBeat8();}, []() { return Settings::getLengthBackAndForthNoSmoothLengthedDot();}, []() { return  Settings::getDeltaRainbowDave();}},
    {"Time", "Fade", "Length", "Delta"},
    {0,0,0,0},
    {500, 128, 10, 128},
    {"tid_blink", "fade_sinBeat8", "length_backAndForthNoSmoothLengthedDot", "delta_rainbowDave"},
    4
};

static Effect _cometOnce {
    "Comet Once", FX_MODE_COMET_ONCE,
    {[]() { return  Settings::getTidBlink();}, []() { return  Settings::getFade_sinBeat8();}, []() { return Settings::getLengthBackAndForthNoSmoothLengthedDot();}, []() { return  Settings::getDeltaRainbowDave();}, []() { return Settings::getSpeed();}},
    {"Time", "Fade", "Length", "Delta", "Speed"},
    {0,0,0,0,0},
    {500, 128, 10, 128, 500},
    {"tid_blink", "fade_sinBeat8", "length_backAndForthNoSmoothLengthedDot", "delta_rainbowDave", "speed"},
    5
};
    



static Effect _end_effect = {nullptr, -1, {0}}; // End marker for effects array

static Effect effects[] = {_fillEffect, _blink, _rainbowStatic, _fillGradientTwoColors, _fillGradientThreeColors,
                            _BackAndForthNoSmoothOneDot, _backAndForthNoSmoothLengthedDot, _hueFading, _hueWhiteWave, 
                            _displayPaletteLinear, _movingPaletteLinear, _spotlightingPalette, _sinBeat8, _sinBeat8PhaseOffset, 
                            _sinBeat8TimeOff, _twoSinBeat8, _threeSinBeat8,  _brightnessSinBeat8Palette, 
                            _funkyRainbowSinBeat8, _funkyRangeSinBeat8, _funkyRainbowSinBeat8Two, _funkyRangeSinBeat8Two, 
                            _movingFunkyPalette, _rainbowWave, _choosenWave, _firstNoiseRainbow, _firstNoiseColor, 
                            _noisePalette, _runFire, _secondNoise, _fillNoise16,_rainbowDave, _marqueeDave, 
                            _twinkleOld, _twinkle, _comet, _cometOnce, _end_effect};

// static Effect _end_effect(
//     "",         // Empty name to indicate it's an end marker
//     -1,        // Invalid effect code
//     {},        // Empty settings vector
//     {},        // Empty setting names vector
//     {},        // Empty min values vector
//     {},        // Empty max values vector
//     {}         // Empty real names vector
// );
// static Effect effects[] = {_fillEffect, _blink, _end_effect};




#endif