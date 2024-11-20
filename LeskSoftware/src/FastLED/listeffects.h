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


// Alternative way but not working and memory problem
struct Effect {
    const char* name;                       // Effect name
    int effect;                              // Effect identifier
    std::function<int()> settings[11];      // Function pointers for settings
    const char** settingNames;               // Pointer to array of setting names
    int* minValues;                          // Pointer to array of minimum values
    int* maxValues;                          // Pointer to array of maximum values
    const char** realNames;                  // Pointer to array of real names
    int numSettings;                         // Number of settings

    // Constructor to initialize with dynamic arrays and name
    Effect(const char* effectName, int effectId, std::function<int()> settingFunctions[], 
           const char** settingNamesArray, int* minValuesArray, 
           int* maxValuesArray, const char** realNamesArray, int num)
        : name(effectName), effect(effectId), settingNames(settingNamesArray),
          minValues(minValuesArray), maxValues(maxValuesArray), realNames(realNamesArray),
          numSettings(num) {
              for (int i = 0; i < numSettings; ++i) {
                  settings[i] = settingFunctions[i]; // Initialize settings
              }
          }
};



// Define the settings function array
static std::function<int()> settingsFunctionFillEffect[1] = {[]() { return 0; }};
// Define setting names and values
static const char* settingNamesArrayFillEffect[] = { ""};
static int minValuesArrayFillEffect[] = {0};           // Corrected to match number of settings
static int maxValuesArrayFillEffect[] = {0};     // Corrected to match number of settings
static const char* realNamesArrayFillEffect[] = { ""}; // Real names for settings

// Create an instance of Effect
static Effect _fillEffect(
    "Fill", 
    FX_MODE_FILL, 
    settingsFunctionFillEffect,
    settingNamesArrayFillEffect,
    minValuesArrayFillEffect,
    maxValuesArrayFillEffect,
    realNamesArrayFillEffect,
    0 // Number of settings
);

static std::function<int()> settingsFunctionBlink[1] = {
    []() { return Settings::getVar0to1000_1();}
};
// Define setting names and values
static const char* settingNamesArrayBlink[] = {"Time"};
static int minValuesArrayBlink[] = {30};           // Corrected to match number of settings
static int maxValuesArrayBlink[] = { 1000};     // Corrected to match number of settings
static const char* realNamesArrayBlink[] = {"var_0to1000_1"}; // Real names for settings

// Create an instance of Effect
static Effect _blink(
    "Blink", 
    FX_MODE_BLINK, 
    settingsFunctionBlink,
    settingNamesArrayBlink,
    minValuesArrayBlink,
    maxValuesArrayBlink,
    realNamesArrayBlink,
    1 // Number of settings
);

// static std::function<int()> settingsFunction[] =
// static const char* settingNamesArray[] =
// static int minValuesArray[] =
// static int maxValuesArray[] =
// static const char* realNamesArray[] =
// static Effect X(

// )

static std::function<int()> settingsFunction_fillGradientTwoColors[1] ={
    []() { return Settings::color2.getColorU32();}
};
static const char* settingNamesArray_fillGradientTwoColors[] = {"Color 2"};
static int minValuesArray_fillGradientTwoColors[] ={ 0X000000};
static int maxValuesArray_fillGradientTwoColors[] = { 0XFFFFFF};
static const char* realNamesArray_fillGradientTwoColors[] = {"color2"};
static Effect _fillGradientTwoColors(
    "Fill Gradient 2 Colors",
    FX_MODE_FILL_GRADIENT_TWO_COLORS,
    settingsFunction_fillGradientTwoColors,
    settingNamesArray_fillGradientTwoColors,
    minValuesArray_fillGradientTwoColors,
    maxValuesArray_fillGradientTwoColors,
    realNamesArray_fillGradientTwoColors,
    1
);

// Define function array for settings
static std::function<int()> settingsFunctionFillGradientThreeColors[2] = {
    []() { return Settings::color2.getColorU32();},
    []() { return Settings::color3.getColorU32();}
};

// Define setting names and values
static const char* settingNamesArrayFillGradientThreeColors[] = {
    "Color 2", "Color 3"
};
static int minValuesArrayFillGradientThreeColors[] = {0X000000, 0X000000};
static int maxValuesArrayFillGradientThreeColors[] = { 0XFFFFFF, 0XFFFFFF};
static const char* realNamesArrayFillGradientThreeColors[] = {"color2", "color2" };

// Create an instance of Effect
static Effect _fillGradientThreeColors(
    "Fill Gradient 3 Colors",
    FX_MODE_FILL_GRADIENT_THREE_COLORS,
    settingsFunctionFillGradientThreeColors,
    settingNamesArrayFillGradientThreeColors,
    minValuesArrayFillGradientThreeColors,
    maxValuesArrayFillGradientThreeColors,
    realNamesArrayFillGradientThreeColors,
    2 // Number of settings
);




// Define function array for settings
static std::function<int()> settingsFunctionBackAndForthNoSmoothOneDot[1] = {
    []() { return Settings::getVar0to500_1(); }
};

// Define setting names and values
static const char* settingNamesArrayBackAndForthNoSmoothOneDot[] = {
        "Time"
};
static int minValuesArrayBackAndForthNoSmoothOneDot[] = {1};
static int maxValuesArrayBackAndForthNoSmoothOneDot[] = {500};
static const char* realNamesArrayBackAndForthNoSmoothOneDot[] = {
    "var_0to500_1"
};

// Create an instance of Effect
static Effect _BackAndForthNoSmoothOneDot(
    "Back and Forth No Smooth One Dot",
    FX_MODE_BACK_AND_FORTH_NO_SMOOTH_ONE_DOT,
    settingsFunctionBackAndForthNoSmoothOneDot,
    settingNamesArrayBackAndForthNoSmoothOneDot,
    minValuesArrayBackAndForthNoSmoothOneDot,
    maxValuesArrayBackAndForthNoSmoothOneDot,
    realNamesArrayBackAndForthNoSmoothOneDot,
    1 // Number of settings
);


// Define function array for settings
static std::function<int()> settingsFunctionBackAndForthNoSmoothLengthedDot[2] = {
    []() { return Settings::getVar0to500_1(); },
    []() { return Settings::getVar0to10_1(); }
};

// Define setting names and values
static const char* settingNamesArrayBackAndForthNoSmoothLengthedDot[] = {
    "Time", "Length"
};
static int minValuesArrayBackAndForthNoSmoothLengthedDot[] = { 1, 1};
static int maxValuesArrayBackAndForthNoSmoothLengthedDot[] = { 500, 8};
static const char* realNamesArrayBackAndForthNoSmoothLengthedDot[] = {
    "var_0to500_1", "var_0to10_1"
};

// Create an instance of Effect
static Effect _backAndForthNoSmoothLengthedDot(
    "Back and Forth No Smooth Lengthed Dot",
    FX_MODE_BACK_AND_FORTH_NO_SMOOTH_LENGHTED_DOT,
    settingsFunctionBackAndForthNoSmoothLengthedDot,
    settingNamesArrayBackAndForthNoSmoothLengthedDot,
    minValuesArrayBackAndForthNoSmoothLengthedDot,
    maxValuesArrayBackAndForthNoSmoothLengthedDot,
    realNamesArrayBackAndForthNoSmoothLengthedDot,
    2 // Number of settings
);

// Define function array for settings
static std::function<int()> settingsFunctionHueFading[1] = {
    []() { return Settings::getVar0to500_1(); }
};

// Define setting names and values
static const char* settingNamesArrayHueFading[] = {"Time"};
static int minValuesArrayHueFading[] = {0};
static int maxValuesArrayHueFading[] = {500};
static const char* realNamesArrayHueFading[] = {"var_0to500_1"};

// Create an instance of Effect
static Effect _hueFading(
    "Hue Fading",
    FX_MODE_HUE_FADING,
    settingsFunctionHueFading,
    settingNamesArrayHueFading,
    minValuesArrayHueFading,
    maxValuesArrayHueFading,
    realNamesArrayHueFading,
    1 // Number of settings
);

// Define function array for settings
static std::function<int()> settingsFunctionHueWhiteWave[2] = {
    []() { return Settings::getVar0to255_1(); },
    []() { return Settings::getVar0to500_1(); }
};

// Define setting names and values
static const char* settingNamesArrayHueWhiteWave[] = {"Hue", "Time"};
static int minValuesArrayHueWhiteWave[] = {0, 0};
static int maxValuesArrayHueWhiteWave[] = {255, 500};
static const char* realNamesArrayHueWhiteWave[] = {"var_0to255_1", "var_0to500_1"};

// Create an instance of Effect
static Effect _hueWhiteWave(
    "Hue White Wave",
    FX_MODE_HUE_WHITE_WAVE,
    settingsFunctionHueWhiteWave,
    settingNamesArrayHueWhiteWave,
    minValuesArrayHueWhiteWave,
    maxValuesArrayHueWhiteWave,
    realNamesArrayHueWhiteWave,
    2 // Number of settings
);

// Define function array for settings
static std::function<int()> settingsFunctionMovingPaletteLinear[1] = {
    []() { return Settings::getVar0to200_1(); }
};

// Define setting names and values
static const char* settingNamesArrayMovingPaletteLinear[] = {"Time"};
static int minValuesArrayMovingPaletteLinear[] = {1};
static int maxValuesArrayMovingPaletteLinear[] = {200};
static const char* realNamesArrayMovingPaletteLinear[] = {"var_0to200_1"};
// Create an instance of Effect
static Effect _movingPaletteLinear(
    "Moving Palette Linear",
    FX_MODE_MOVING_PALETTE_LINEAR,
    settingsFunctionMovingPaletteLinear,
    settingNamesArrayMovingPaletteLinear,
    minValuesArrayMovingPaletteLinear,
    maxValuesArrayMovingPaletteLinear,
    realNamesArrayMovingPaletteLinear,
    1 // Number of settings
);

// Define function array for settings
static std::function<int()> settingsFunctionSpotlightingPalette[2] = {
    []() { return Settings::getVar0to200_1(); },
    []() { return Settings::getVar0to128_1(); }
};

// Define setting names and values
static const char* settingNamesArraySpotlightingPalette[] = {"Time", "Fade"};
static int minValuesArraySpotlightingPalette[] = {1, 0};
static int maxValuesArraySpotlightingPalette[] = {200, 128};
static const char* realNamesArraySpotlightingPalette[] = {
    "var_0to200_1", "var_0to128_1"};

// Create an instance of Effect
static Effect _spotlightingPalette(
    "Spotlighting Palette",
    FX_MODE_SPOTLIGHTING_PALETTE,
    settingsFunctionSpotlightingPalette,
    settingNamesArraySpotlightingPalette,
    minValuesArraySpotlightingPalette,
    maxValuesArraySpotlightingPalette,
    realNamesArraySpotlightingPalette,
    2 // Number of settings
);

// Define function array for settings
static std::function<int()> settingsFunctionSinBeat8[2] = {
    []() { return Settings::getVar0to128_1(); },
    []() { return Settings::getVar0to140_1(); }
};

// Define setting names and values
static const char* settingNamesArraySinBeat8[] = {"Fade", "BPM"};
static int minValuesArraySinBeat8[] = {0, 0};
static int maxValuesArraySinBeat8[] = {128, 140};
static const char* realNamesArraySinBeat8[] = {"var_0to128_1", "var_0to140_1"};

// Create an instance of Effect
static Effect _sinBeat8(
    "Sin Beat 8",
    FX_MODE_SIN_BEAT_8,
    settingsFunctionSinBeat8,
    settingNamesArraySinBeat8,
    minValuesArraySinBeat8,
    maxValuesArraySinBeat8,
    realNamesArraySinBeat8,
    2 // Number of settings
);

// Define function array for settings
static std::function<int()> settingsFunctionSinBeat8PhaseOffset[3] = {
    []() { return Settings::getVar0to128_1(); },
    []() { return Settings::getVar0to140_1(); },
    []() { return Settings::getVar0to128_2(); }
};

// Define setting names and values
static const char* settingNamesArraySinBeat8PhaseOffset[] = {"Fade", "BPM", "Phase Offset"};
static int minValuesArraySinBeat8PhaseOffset[] = {0, 0, 0};
static int maxValuesArraySinBeat8PhaseOffset[] = {128, 140, 128};
static const char* realNamesArraySinBeat8PhaseOffset[] = {
    "var_0to128_1", "var_0to140_1", "var_0to128_2"};

// Create an instance of Effect
static Effect _sinBeat8PhaseOffset(
    "Sin Beat 8 Phase Off",
    FX_MODE_SIN_BEAT_8_PHASE_OFF,
    settingsFunctionSinBeat8PhaseOffset,
    settingNamesArraySinBeat8PhaseOffset,
    minValuesArraySinBeat8PhaseOffset,
    maxValuesArraySinBeat8PhaseOffset,
    realNamesArraySinBeat8PhaseOffset,
    3 // Number of settings
);

// Define function array for settings
static std::function<int()> settingsFunctionTwoSinBeat8[3] = {
    []() { return Settings::color2.getColorU32();},
    []() { return Settings::getVar0to128_1(); },
    []() { return Settings::getVar0to140_1(); }
};

// Define setting names and values
static const char* settingNamesArrayTwoSinBeat8[] = {"Color 2", "Fade", "BPM"};
static int minValuesArrayTwoSinBeat8[] = {0x000000, 0, 0};
static int maxValuesArrayTwoSinBeat8[] = {0xffffff, 128, 140};
static const char* realNamesArrayTwoSinBeat8[] = {
    "color2", "var_0to128_1", "var_0to140_1"};

// Create an instance of Effect
static Effect _twoSinBeat8(
    "Two Sin Beat 8",
    FX_MODE_TWO_SIN_BEAT_8,
    settingsFunctionTwoSinBeat8,
    settingNamesArrayTwoSinBeat8,
    minValuesArrayTwoSinBeat8,
    maxValuesArrayTwoSinBeat8,
    realNamesArrayTwoSinBeat8,
    3 // Number of settings
);

// Define function array for settings
static std::function<int()> settingsFunctionThreeSinBeat8[4] = {
    []() { return Settings::color2.getColorU32();},
    []() { return Settings::color3.getColorU32();},
    []() { return Settings::getVar0to128_1(); },
    []() { return Settings::getVar0to140_1(); }
};

// Define setting names and values
static const char* settingNamesArrayThreeSinBeat8[] = {"Color 2", "Color 3", "Fade", "BPM"};
static int minValuesArrayThreeSinBeat8[] = { 0x000000, 0x000000, 0, 0};
static int maxValuesArrayThreeSinBeat8[] = {
     0xffffff, 0xffffff, 128, 140};
static const char* realNamesArrayThreeSinBeat8[] = {
    "color2", "color3", "var_0to128_1", "var_0to140_1"};

// Create an instance of Effect
static Effect _threeSinBeat8(
    "Three Sin Beat 8",
    FX_MODE_THREE_SIN_BEAT_8,
    settingsFunctionThreeSinBeat8,
    settingNamesArrayThreeSinBeat8,
    minValuesArrayThreeSinBeat8,
    maxValuesArrayThreeSinBeat8,
    realNamesArrayThreeSinBeat8,
    4 // Number of settings
);

// Define function array for settings
static std::function<int()> settingsFunctionBrightnessSinBeat8Palette[2] = {
    []() { return Settings::getVar0to140_1(); },
    []() { return Settings::getVar0to500_1(); }
};

// Define setting names and values
static const char* settingNamesArrayBrightnessSinBeat8Palette[] = {"BPM", "Time"};
static int minValuesArrayBrightnessSinBeat8Palette[] = {0, 0};
static int maxValuesArrayBrightnessSinBeat8Palette[] = {140, 500};
static const char* realNamesArrayBrightnessSinBeat8Palette[] = {
    "var_0to140_1", "var_0to500_1"};

// Create an instance of Effect
static Effect _brightnessSinBeat8Palette(
    "Brightness Sin Beat 8 Palette",
    FX_MODE_BRIGHTNESS_SIN_BEAT_PALETTE,
    settingsFunctionBrightnessSinBeat8Palette,
    settingNamesArrayBrightnessSinBeat8Palette,
    minValuesArrayBrightnessSinBeat8Palette,
    maxValuesArrayBrightnessSinBeat8Palette,
    realNamesArrayBrightnessSinBeat8Palette,
    2 // Number of settings
);

// Define function array for settings
static std::function<int()> settingsFunctionFunkyRainbowSinBeat8[1] = {
    []() { return Settings::getVar0to128_1(); }
};

// Define setting names and values
static const char* settingNamesArrayFunkyRainbowSinBeat8[] = {"Fade"};
static int minValuesArrayFunkyRainbowSinBeat8[] = {0};
static int maxValuesArrayFunkyRainbowSinBeat8[] = {128};
static const char* realNamesArrayFunkyRainbowSinBeat8[] = {"var_0to128_1"};

// Create an instance of Effect
static Effect _funkyRainbowSinBeat8(
    "Funky Rainbow Sin Beat 8",
    FX_MODE_FUNKY_RAINBOW_SIN_BEAT_8,
    settingsFunctionFunkyRainbowSinBeat8,
    settingNamesArrayFunkyRainbowSinBeat8,
    minValuesArrayFunkyRainbowSinBeat8,
    maxValuesArrayFunkyRainbowSinBeat8,
    realNamesArrayFunkyRainbowSinBeat8,
    1 // Number of settings
);

// Define function array for settings
static std::function<int()> settingsFunctionFunkyRangeSinBeat8[1] = {
    []() { return Settings::getVar0to128_1(); }
};

// Define setting names and values
static const char* settingNamesArrayFunkyRangeSinBeat8[] = {"Fade"};
static int minValuesArrayFunkyRangeSinBeat8[] = {0};
static int maxValuesArrayFunkyRangeSinBeat8[] = {128};
static const char* realNamesArrayFunkyRangeSinBeat8[] = {"var_0to128_1"};

// Create an instance of Effect
static Effect _funkyRangeSinBeat8(
    "Funky Range Sin Beat 8",
    FX_MODE_FUNKY_RANGES_SIN_BEAT_8,
    settingsFunctionFunkyRangeSinBeat8,
    settingNamesArrayFunkyRangeSinBeat8,
    minValuesArrayFunkyRangeSinBeat8,
    maxValuesArrayFunkyRangeSinBeat8,
    realNamesArrayFunkyRangeSinBeat8,
    1 // Number of settings
);

// Define function array for settings
static std::function<int()> settingsFunctionFunkyRainbowSinBeat8Two[1] = {
    []() { return Settings::getVar0to128_1(); }
};

// Define setting names and values
static const char* settingNamesArrayFunkyRainbowSinBeat8Two[] = {"Fade"};
static int minValuesArrayFunkyRainbowSinBeat8Two[] = {0};
static int maxValuesArrayFunkyRainbowSinBeat8Two[] = {128};
static const char* realNamesArrayFunkyRainbowSinBeat8Two[] = {"var_0to128_1"};

// Create an instance of Effect
static Effect _funkyRainbowSinBeat8Two(
    "Funky Rainbow Sin Beat 8 Two",
    FX_MODE_FUNKY_RAINBOW_SIN_BEAT_8_TWO,
    settingsFunctionFunkyRainbowSinBeat8Two,
    settingNamesArrayFunkyRainbowSinBeat8Two,
    minValuesArrayFunkyRainbowSinBeat8Two,
    maxValuesArrayFunkyRainbowSinBeat8Two,
    realNamesArrayFunkyRainbowSinBeat8Two,
    1 // Number of settings
);

// Define function array for settings
static std::function<int()> settingsFunctionFunkyRangeSinBeat8Two[1] = {
    []() { return Settings::getVar0to128_1(); }
};

// Define setting names and values
static const char* settingNamesArrayFunkyRangeSinBeat8Two[] = {"Fade"};
static int minValuesArrayFunkyRangeSinBeat8Two[] = {0};
static int maxValuesArrayFunkyRangeSinBeat8Two[] = {128};
static const char* realNamesArrayFunkyRangeSinBeat8Two[] = {"var_0to128_1"};

// Create an instance of Effect
static Effect _funkyRangeSinBeat8Two(
    "Funky Range Sin Beat 8 Two",
    FX_MODE_FUNKY_RANGE_SIN_BEAT_8_TWO,
    settingsFunctionFunkyRangeSinBeat8Two,
    settingNamesArrayFunkyRangeSinBeat8Two,
    minValuesArrayFunkyRangeSinBeat8Two,
    maxValuesArrayFunkyRangeSinBeat8Two,
    realNamesArrayFunkyRangeSinBeat8Two,
    1 // Number of settings
);

// Define function array for settings
static std::function<int()> settingsFunctionMovingFunkyPalette[2] = {
    []() { return Settings::getVar0to140_1(); },
    []() { return Settings::getVar0to140_2(); }
};

// Define setting names and values
static const char* settingNamesArrayMovingFunkyPalette[] = {"BPM1", "BPM2"};
static int minValuesArrayMovingFunkyPalette[] = {0, 0};
static int maxValuesArrayMovingFunkyPalette[] = {140, 140};
static const char* realNamesArrayMovingFunkyPalette[] = {"var_0to140_1", "var_0to140_2"};

// Create an instance of Effect
static Effect _movingFunkyPalette(
    "Moving Funky Palette",
    FX_MODE_MOVING_FUNKY_PALETTE,
    settingsFunctionMovingFunkyPalette,
    settingNamesArrayMovingFunkyPalette,
    minValuesArrayMovingFunkyPalette,
    maxValuesArrayMovingFunkyPalette,
    realNamesArrayMovingFunkyPalette,
    2 // Number of settings
);

// Define function array for settings
static std::function<int()> settingsFunctionRainbowWave[3] = {
    []() { return Settings::getVar0to140_1(); },
    []() { return Settings::getVar0to500_1(); },
    []() { return Settings::getVar0to128_1(); }
};

// Define setting names and values
static const char* settingNamesArrayRainbowWave[] = {"BPM", "Time", "Fade"};
static int minValuesArrayRainbowWave[] = {0, 0, 0};
static int maxValuesArrayRainbowWave[] = {140, 500, 128};
static const char* realNamesArrayRainbowWave[] = {
    "var_0to140_1", "var_0to500_1", "var_0to128_1"};

// Create an instance of Effect
static Effect _rainbowWave(
    "Rainbow Wave",
    FX_MODE_RAINBOW_WAVE,
    settingsFunctionRainbowWave,
    settingNamesArrayRainbowWave,
    minValuesArrayRainbowWave,
    maxValuesArrayRainbowWave,
    realNamesArrayRainbowWave,
    3 // Number of settings
);

// Define function array for settings
static std::function<int()> settingsFunctionChoosenWave[3] = {
    []() { return Settings::getVar0to500_1(); },
    []() { return Settings::getVar0to140_1(); },
    []() { return Settings::getVar0to128_1(); },
};

// Define setting names and values
static const char* settingNamesArrayChoosenWave[] = {"Time", "BPM", "Fade"};
static int minValuesArrayChoosenWave[] = {0, 0, 0};
static int maxValuesArrayChoosenWave[] = {500, 140, 128};
static const char* realNamesArrayChoosenWave[] = {
    "var_0to500_1", "var_0to140_1", "var_0to128_1" };

// Create an instance of Effect
static Effect _choosenWave(
    "Choosen Wave",
    FX_MODE_CHOOSEN_WAVE,
    settingsFunctionChoosenWave,
    settingNamesArrayChoosenWave,
    minValuesArrayChoosenWave,
    maxValuesArrayChoosenWave,
    realNamesArrayChoosenWave,
    3 // Number of settings
);

// Define function array for settings
static std::function<int()> settingsFunctionFirstNoiseRainbow[1] = {
    []() { return Settings::getVar0to140_1(); }
};

// Define setting names and values
static const char* settingNamesArrayFirstNoiseRainbow[] = {"BPM"};
static int minValuesArrayFirstNoiseRainbow[] = {0};
static int maxValuesArrayFirstNoiseRainbow[] = {140};
static const char* realNamesArrayFirstNoiseRainbow[] = {"var_0to140_1"};

// Create an instance of Effect
static Effect _firstNoiseRainbow(
    "First Noise Rainbow",
    FX_MODE_FIRST_NOISE_RAINBOW,
    settingsFunctionFirstNoiseRainbow,
    settingNamesArrayFirstNoiseRainbow,
    minValuesArrayFirstNoiseRainbow,
    maxValuesArrayFirstNoiseRainbow,
    realNamesArrayFirstNoiseRainbow,
    1 // Number of settings
);

// Define function array for settings
static std::function<int()> settingsFunctionFirstNoiseColor[1] = {
    []() { return Settings::getVar0to140_1(); }
};

// Define setting names and values
static const char* settingNamesArrayFirstNoiseColor[] = {"BPM"};
static int minValuesArrayFirstNoiseColor[] = {0};
static int maxValuesArrayFirstNoiseColor[] = {140};
static const char* realNamesArrayFirstNoiseColor[] = {"var_0to140_1"};

// Create an instance of Effect
static Effect _firstNoiseColor(
    "First Noise Color",
    FX_MODE_FIRST_NOISE_COLORS,
    settingsFunctionFirstNoiseColor,
    settingNamesArrayFirstNoiseColor,
    minValuesArrayFirstNoiseColor,
    maxValuesArrayFirstNoiseColor,
    realNamesArrayFirstNoiseColor,
    1 // Number of settings
);

// Define function array for settings
static std::function<int()> settingsFunctionNoisePalette[1] = {
    []() { return Settings::getVar0to140_1(); }
};

// Define setting names and values
static const char* settingNamesArrayNoisePalette[] = {"Scale"};
static int minValuesArrayNoisePalette[] = {0};
static int maxValuesArrayNoisePalette[] = {144};
static const char* realNamesArrayNoisePalette[] = {"var_0to140_1"};

// Create an instance of Effect
static Effect _noisePalette(
    "Noise Palette",
    FX_MODE_NOISE_PALETTE,
    settingsFunctionNoisePalette,
    settingNamesArrayNoisePalette,
    minValuesArrayNoisePalette,
    maxValuesArrayNoisePalette,
    realNamesArrayNoisePalette,
    1 // Number of settings
);

// Define function array for settings
static std::function<int()> settingsFunctionRunFire[1] = {nullptr};

// Define setting names and values
static const char* settingNamesArrayRunFire[] = {};
static int minValuesArrayRunFire[] = {};
static int maxValuesArrayRunFire[] = {};
static const char* realNamesArrayRunFire[] = {};

// Create an instance of Effect
static Effect _runFire(
    "Run Fire",
    FX_MODE_RUN_FIRE,
    settingsFunctionRunFire,
    settingNamesArrayRunFire,
    minValuesArrayRunFire,
    maxValuesArrayRunFire,
    realNamesArrayRunFire,
    0 // Number of settings
);


// Define function array for settings
static std::function<int()> settingsFunctionSecondNoise[1] = {nullptr};

// Define setting names and values
static const char* settingNamesArraySecondNoise[] = {};
static int minValuesArraySecondNoise[] = {};
static int maxValuesArraySecondNoise[] = {};
static const char* realNamesArraySecondNoise[] = {};

// Create an instance of Effect
static Effect _secondNoise(
    "Second Noise",
    FX_MODE_SECOND_NOISE,
    settingsFunctionSecondNoise,
    settingNamesArraySecondNoise,
    minValuesArraySecondNoise,
    maxValuesArraySecondNoise,
    realNamesArraySecondNoise,
    0 // Number of settings
);

// Define function array for settings
static std::function<int()> settingsFunctionFillNoise16[1] = {nullptr};

// Define setting names and values
static const char* settingNamesArrayFillNoise16[] = {};
static int minValuesArrayFillNoise16[] = {};
static int maxValuesArrayFillNoise16[] = {};
static const char* realNamesArrayFillNoise16[] = {};

// Create an instance of Effect
static Effect _fillNoise16(
    "Fill Noise 16",
    FX_MODE_FILL_NOISE_16,
    settingsFunctionFillNoise16,
    settingNamesArrayFillNoise16,
    minValuesArrayFillNoise16,
    maxValuesArrayFillNoise16,
    realNamesArrayFillNoise16,
    0 // Number of settings
);

// Define function array for settings
static std::function<int()> settingsFunctionRainbowDave[3] = {
    []() { return Settings::getVar0to128_1(); },
    []() { return Settings::getVar0to128_2(); },
    []() { return Settings::getVar0to500_1(); }
};

// Define setting names and values
static const char* settingNamesArrayRainbowDave[] = {"Density", "Delta", "Time"};
static int minValuesArrayRainbowDave[] = {0, 0, 0};
static int maxValuesArrayRainbowDave[] = {128, 128, 500};
static const char* realNamesArrayRainbowDave[] = {
    "var_0to128_1", "var_0to128_2", "var_0to500_1"};

// Create an instance of Effect
static Effect _rainbowDave(
    "Rainbow Dave",
    FX_MODE_RAINBOW_DAVE,
    settingsFunctionRainbowDave,
    settingNamesArrayRainbowDave,
    minValuesArrayRainbowDave,
    maxValuesArrayRainbowDave,
    realNamesArrayRainbowDave,
    3 // Number of settings
);

// Define function array for settings
static std::function<int()> settingsFunctionMarqueeDave[3] = {
    []() { return Settings::getVar0to500_1(); },
    []() { return Settings::getVar0to128_1(); },
    []() { return Settings::getVar0to10_1(); }
};

// Define setting names and values
static const char* settingNamesArrayMarqueeDave[] = {"Time", "Density", "Length"};
static int minValuesArrayMarqueeDave[] = {0, 0, 2};
static int maxValuesArrayMarqueeDave[] = {500, 128, 10};
static const char* realNamesArrayMarqueeDave[] = {
    "var_0to500_1", "var_0to128_1", "var_0to10_1"};

// Create an instance of Effect
static Effect _marqueeDave(
    "Marquee Dave",
    FX_MODE_MARQUEE_DAVE,
    settingsFunctionMarqueeDave,
    settingNamesArrayMarqueeDave,
    minValuesArrayMarqueeDave,
    maxValuesArrayMarqueeDave,
    realNamesArrayMarqueeDave,
    3 // Number of settings
);

// Define function array for settings
static std::function<int()> settingsFunctionTwinkleOld[1] = {
    []() { return Settings::getVar0to500_1(); }
};

// Define setting names and values
static const char* settingNamesArrayTwinkleOld[] = {"Time"};
static int minValuesArrayTwinkleOld[] = {0};
static int maxValuesArrayTwinkleOld[] = {500};
static const char* realNamesArrayTwinkleOld[] = {"var_0to500_1"};

// Create an instance of Effect
static Effect _twinkleOld(
    "Twinkle Old",
    FX_MODE_TWINKLE_OLD,
    settingsFunctionTwinkleOld,
    settingNamesArrayTwinkleOld,
    minValuesArrayTwinkleOld,
    maxValuesArrayTwinkleOld,
    realNamesArrayTwinkleOld,
    1 // Number of settings
);

// Define function array for settings
static std::function<int()> settingsFunctionTwinkle[1] = {
    []() { return Settings::getVar0to500_1(); }
};

// Define setting names and values
static const char* settingNamesArrayTwinkle[] = {"Time"};
static int minValuesArrayTwinkle[] = {0};
static int maxValuesArrayTwinkle[] = {500};
static const char* realNamesArrayTwinkle[] = {"var_0to500_1"};

// Create an instance of Effect
static Effect _twinkle(
    "Twinkle",
    FX_MODE_TWINKLE,
    settingsFunctionTwinkle,
    settingNamesArrayTwinkle,
    minValuesArrayTwinkle,
    maxValuesArrayTwinkle,
    realNamesArrayTwinkle,
    1 // Number of settings
);

// Define function array for settings
static std::function<int()> settingsFunctionComet[4] = {
    []() { return Settings::getVar0to500_1(); },
    []() { return Settings::getVar0to128_1(); },
    []() { return Settings::getVar0to10_1(); },
    []() { return Settings::getVar0to128_2(); }
};

// Define setting names and values
static const char* settingNamesArrayComet[] = {"Time", "Fade", "Length", "Delta"};
static int minValuesArrayComet[] = {0, 0, 0, 0};
static int maxValuesArrayComet[] = {500, 128, 10, 128};
static const char* realNamesArrayComet[] = {
    "var_0to500_1", "var_0to128_1", "var_0to10_1", "var_0to128_2"};

// Create an instance of Effect
static Effect _comet(
    "Comet",
    FX_MODE_COMET,
    settingsFunctionComet,
    settingNamesArrayComet,
    minValuesArrayComet,
    maxValuesArrayComet,
    realNamesArrayComet,
    4 // Number of settings
);

// Define function array for settings
static std::function<int()> settingsFunctionCometOnce[5] = {
    []() { return Settings::getVar0to500_1(); },
    []() { return Settings::getVar0to128_1(); },
    []() { return Settings::getVar0to10_1(); },
    []() { return Settings::getVar0to128_2(); },
    []() { return Settings::getVar0to500_2(); }
};

// Define setting names and values
static const char* settingNamesArrayCometOnce[] = {"Time", "Fade", "Length", "Delta", "Speed"};
static int minValuesArrayCometOnce[] = {0, 0, 0, 0, 0};
static int maxValuesArrayCometOnce[] = {500, 128, 10, 128, 500};
static const char* realNamesArrayCometOnce[] = {
    "var_0to500_1", "var_0to128_1", "var_0to10_1", 
    "var_0to128_2", "var_0to500_2"};

// Create an instance of Effect
static Effect _cometOnce(
    "Comet Once",
    FX_MODE_COMET_ONCE,
    settingsFunctionCometOnce,
    settingNamesArrayCometOnce,
    minValuesArrayCometOnce,
    maxValuesArrayCometOnce,
    realNamesArrayCometOnce,
    5 // Number of settings
);

// Define function array for settings
static std::function<int()> settingsFunctionBounce[2] = {
    []() { return Settings::getVar0to5_1(); },
    []() { return Settings::getVar0to128_1(); }
};

// Define setting names and values
static const char* settingNamesArrayBounce[] = {"Balls", "Fade"};
static int minValuesArrayBounce[] = {1, 0};
static int maxValuesArrayBounce[] = {5, 128};
static const char* realNamesArrayBounce[] = {"var_0to5_1", "var_0to128_1"};

// Create an instance of Effect
static Effect _bounce(
    "Bounce",
    FX_MODE_BOUNCE,
    settingsFunctionBounce,
    settingNamesArrayBounce,
    minValuesArrayBounce,
    maxValuesArrayBounce,
    realNamesArrayBounce,
    2 // Number of settings
);

// Define function array for settings
static std::function<int()> settingsFunctionFire[5] = {
    []() { return Settings::getVar0to10_1(); },
    []() { return Settings::getVar0to200_1(); },
    []() { return Settings::getVar0to128_1(); },
    []() { return Settings::getVar0to10_2(); },
    []() { return Settings::getVar0to10_3(); }
};

// Define function array for settings
static std::function<int()> settingsFunctionStorm[4] = {
    []() { return Settings::getVar0to5_1(); },
    []() { return Settings::getVar0to128_1(); },
    []() { return Settings::getVar0to500_1(); },
    []() { return Settings::getVar0to128_2(); }
};

// Define setting names and values
static const char* settingNamesArrayStorm[] = {"Chance", "Cluster", "Speed", "Fade"};
static int minValuesArrayStorm[] = {1, 0, 0, 0};
static int maxValuesArrayStorm[] = {5, 128, 500, 128};
static const char* realNamesArrayStorm[] = {
    "var_0to5_1", "var_0to128_1", "var_0to500_1", "var_0to128_2"};

// Create an instance of Effect
static Effect _storm(
    "Storm",
    FX_MODE_STORM,
    settingsFunctionStorm,
    settingNamesArrayStorm,
    minValuesArrayStorm,
    maxValuesArrayStorm,
    realNamesArrayStorm,
    4 // Number of settings
);

// Define function array for settings
static std::function<int()> settingsFunctionStormColored[4] = {
    []() { return Settings::getVar0to5_1(); },
    []() { return Settings::getVar0to128_1(); },
    []() { return Settings::getVar0to500_1(); },
    []() { return Settings::getVar0to128_2(); }
};


// Define function array for settings
static std::function<int()> settingsFunctionStormPalette[4] = {
    []() { return Settings::getVar0to5_1(); },
    []() { return Settings::getVar0to128_1(); },
    []() { return Settings::getVar0to500_1(); },
    []() { return Settings::getVar0to128_2(); }
};



// Define function array for settings
static std::function<int()> settingsFunctionLighting[5] = {
    []() { return Settings::getVar0to5_1(); },
    []() { return Settings::getVar0to10_1(); },
    []() { return Settings::getVar0to10_2(); },
    []() { return Settings::getVar0to128_1(); },
    []() { return Settings::getVar0to1000_1(); }
};

// Define setting names and values
static const char* settingNamesArrayLighting[] = {"Start", "Length", "Flashes", "Dimmer", "Frequency"};
static int minValuesArrayLighting[] = {0, 0, 0, 0, 0};
static int maxValuesArrayLighting[] = {5, 10, 10, 128, 1000};
static const char* realNamesArrayLighting[] = {
    "var_0to5_1", "var_0to10_1", "var_0to10_2", "var_0to128_1", "var_0to1000_1"};

// Create an instance of Effect
static Effect _lighting(
    "Lighting",
    FX_MODE_LIGHTING,
    settingsFunctionLighting,
    settingNamesArrayLighting,
    minValuesArrayLighting,
    maxValuesArrayLighting,
    realNamesArrayLighting,
    5 // Number of settings
);

// Define function array for settings
static std::function<int()> settingsFunctionLightingColored[5] = {
    []() { return Settings::getVar0to5_1(); },
    []() { return Settings::getVar0to10_1(); },
    []() { return Settings::getVar0to10_2(); },
    []() { return Settings::getVar0to128_1(); },
    []() { return Settings::getVar0to1000_1(); }
};

// Define setting names and values
static const char* settingNamesArrayLightingColored[] = {"Start", "Length", "Flashes", "Dimmer", "Frequency"};
static int minValuesArrayLightingColored[] = {0, 0, 0, 0, 0};
static int maxValuesArrayLightingColored[] = {5, 10, 10, 128, 1000};
static const char* realNamesArrayLightingColored[] = {
    "var_0to5_1", "var_0to10_1", "var_0to10_2", "var_0to128_1", "var_0to1000_1"};

// Create an instance of Effect
static Effect _lightingColored(
    "Lighting Colored",
    FX_MODE_LIGHTING_COLORED,
    settingsFunctionLightingColored,
    settingNamesArrayLightingColored,
    minValuesArrayLightingColored,
    maxValuesArrayLightingColored,
    realNamesArrayLightingColored,
    5 // Number of settings
);

// Define function array for settings
static std::function<int()> settingsFunctionLightingPalette[5] = {
    []() { return Settings::getVar0to5_1(); },
    []() { return Settings::getVar0to10_1(); },
    []() { return Settings::getVar0to10_2(); },
    []() { return Settings::getVar0to128_1(); },
    []() { return Settings::getVar0to1000_1(); }
};


// Define function array for settings
static std::function<int()> settingsFunctionBeat8Tail[3] = {
    []() { return Settings::getVar0to10_1(); },
    []() { return Settings::getVar0to128_1(); },
    []() { return Settings::getVar0to1000_1(); }
};

// Define setting names and values
static const char* settingNamesArrayBeat8Tail[] = {"BPM", "Fade", "Time"};
static int minValuesArrayBeat8Tail[] = {1, 0, 0};
static int maxValuesArrayBeat8Tail[] = {12, 128, 1000};
static const char* realNamesArrayBeat8Tail[] = {"var_0to10_1", "var_0to128_1", "var_0to1000_1"};

// Create an instance of Effect
static Effect _beat8_tail(
    "Beat 8 Tail",
    FX_MODE_BEAT_8_TAIL,
    settingsFunctionBeat8Tail,
    settingNamesArrayBeat8Tail,
    minValuesArrayBeat8Tail,
    maxValuesArrayBeat8Tail,
    realNamesArrayBeat8Tail,
    3 // Number of settings
);

// Define function array for settings
static std::function<int()> settingsFunctionBlendIntoRainbow[4] = {
    []() { return Settings::getVar0to1000_1(); },
    []() { return Settings::getVar0to1000_2(); },
    []() { return Settings::getVar0to255_1(); },
    []() { return Settings::getVar0to255_2(); }
};

// Define setting names and values
static const char* settingNamesArrayBlendIntoRainbow[] = {"Time", "Time 2", "Hue", "Blend"};
static int minValuesArrayBlendIntoRainbow[] = {0, 0, 0, 0};
static int maxValuesArrayBlendIntoRainbow[] = {1000, 1000, 255, 255};
static const char* realNamesArrayBlendIntoRainbow[] = {
    "var_0to1000_1", "var_0to1000_2", "var_0to255_1", "var_0to255_2"};

// Create an instance of Effect
static Effect _blendIntoRainbow(
    "Blend Into Rainbow",
    FX_MODE_BLEND_INTO_RAINBOW,
    settingsFunctionBlendIntoRainbow,
    settingNamesArrayBlendIntoRainbow,
    minValuesArrayBlendIntoRainbow,
    maxValuesArrayBlendIntoRainbow,
    realNamesArrayBlendIntoRainbow,
    4 // Number of settings
);

// Define function array for settings
static std::function<int()> settingsFunctionBreatheV2[1] = {
    []() { return Settings::getPulseSpBreathe(); }
};

// Define setting names and values
static const char* settingNamesArrayBreatheV2[] = {"Pulse"};
static int minValuesArrayBreatheV2[] = {0};
static int maxValuesArrayBreatheV2[] = {255};
static const char* realNamesArrayBreatheV2[] = {"pulseSp_breathe"};

// Create an instance of Effect
static Effect _breatheV2(
    "Breathe V2",
    FX_MODE_BREATHE_V2,
    settingsFunctionBreatheV2,
    settingNamesArrayBreatheV2,
    minValuesArrayBreatheV2,
    maxValuesArrayBreatheV2,
    realNamesArrayBreatheV2,
    1 // Number of settings
);


static std::function<int()> settingsFunctionChaseTargetTalesVarA[1] = {
    []() { return Settings::getVar0to500_1(); }
};

static const char* settingNamesArrayChaseTargetTalesVarA[] = {"Time"};
static int minValuesArrayChaseTargetTalesVarA[] = {0};
static int maxValuesArrayChaseTargetTalesVarA[] = {500};
static const char* realNamesArrayChaseTargetTalesVarA[] = {"var_0to500_1"};

static Effect _chaseTargetTalesVarA(
    "Chase Target Tales Var A",
    FX_MODE_CHASE_TARGET_TALES_VAR_A,
    settingsFunctionChaseTargetTalesVarA,
    settingNamesArrayChaseTargetTalesVarA,
    minValuesArrayChaseTargetTalesVarA,
    maxValuesArrayChaseTargetTalesVarA,
    realNamesArrayChaseTargetTalesVarA,
    1 // Number of settings
);

static std::function<int()> settingsFunctionChaseTargetTalesVarB[1] = {
    []() { return Settings::getVar0to500_1(); }
};

static const char* settingNamesArrayChaseTargetTalesVarB[] = {"Time"};
static int minValuesArrayChaseTargetTalesVarB[] = {0};
static int maxValuesArrayChaseTargetTalesVarB[] = {500};
static const char* realNamesArrayChaseTargetTalesVarB[] = {"var_0to500_1"};

static Effect _chaseTargetTalesVarB(
    "Chase Target Tales Var B",
    FX_MODE_CHASE_TARGET_TALES_VAR_B,
    settingsFunctionChaseTargetTalesVarB,
    settingNamesArrayChaseTargetTalesVarB,
    minValuesArrayChaseTargetTalesVarB,
    maxValuesArrayChaseTargetTalesVarB,
    realNamesArrayChaseTargetTalesVarB,
    1 // Number of settings
);

static std::function<int()> settingsFunctionChaseTargetTalesVarC[3] = {
    []() { return Settings::getVar0to500_1(); },
    []() { return Settings::getVar0to128_1(); },
    []() { return Settings::getVar0to128_2(); }
};

static const char* settingNamesArrayChaseTargetTalesVarC[] = {"Boiling Time", "Fading Chase", "Fading"};
static int minValuesArrayChaseTargetTalesVarC[] = {0, 0, 0};
static int maxValuesArrayChaseTargetTalesVarC[] = {500, 128, 128};
static const char* realNamesArrayChaseTargetTalesVarC[] = {
    "var_0to500_1", "var_0to128_1", "var_0to128_2"};

static Effect _chaseTargetTalesVarC(
    "Chase Target Tales Var C",
    FX_MODE_CHASE_TARGET_TALES_VAR_C,
    settingsFunctionChaseTargetTalesVarC,
    settingNamesArrayChaseTargetTalesVarC,
    minValuesArrayChaseTargetTalesVarC,
    maxValuesArrayChaseTargetTalesVarC,
    realNamesArrayChaseTargetTalesVarC,
    3
);

static std::function<int()> settingsFunction_everyNTimerVariables[2] = {
    []() { return Settings::getVar0to500_1(); },
    []() { return Settings::getVar0to500_2(); }
};
static const char* settingNamesArray_everyNTimerVariables[] = {"Timer A", "Timer B"};
static int minValuesArray_everyNTimerVariables[] = {0, 0};
static int maxValuesArray_everyNTimerVariables[] = {500, 500};
static const char* realNamesArray_everyNTimerVariables[] = {"var_0to500_1", "var_0to500_2"};

static Effect _everyNTimerVariables(
    "Every N Timer Variables",
    FX_MODE_EVERY_N_TIMER_VARIABLES,
    settingsFunction_everyNTimerVariables,
    settingNamesArray_everyNTimerVariables,
    minValuesArray_everyNTimerVariables,
    maxValuesArray_everyNTimerVariables,
    realNamesArray_everyNTimerVariables,
    2
);


static std::function<int()> settingsFunction_fillUpStrip[1] = {[]() { return 0; }};
static const char* settingNamesArray_fillUpStrip[1] = {""};
static int minValuesArray_fillUpStrip[1] = {0};
static int maxValuesArray_fillUpStrip[1] = {0};
static const char* realNamesArray_fillUpStrip[1] = {""};

static Effect _fillUpStrip(
    "Fill Up Strip",
    FX_MODE_FILL_UP_STRING,
    settingsFunction_fillUpStrip,
    settingNamesArray_fillUpStrip,
    minValuesArray_fillUpStrip,
    maxValuesArray_fillUpStrip,
    realNamesArray_fillUpStrip,
    0
);


static std::function<int()> settingsFunction_heartBeat3[1] = {[]() { return 0; }};
static const char* settingNamesArray_heartBeat3[1] = {""};
static int minValuesArray_heartBeat3[1] = {0};
static int maxValuesArray_heartBeat3[1] = {0};
static const char* realNamesArray_heartBeat3[1] = {""};

static Effect _heartBeat3(
    "Heart Beat 3",
    FX_MODE_HEART_BEAT_3,
    settingsFunction_heartBeat3,
    settingNamesArray_heartBeat3,
    minValuesArray_heartBeat3,
    maxValuesArray_heartBeat3,
    realNamesArray_heartBeat3,
    0
);


static std::function<int()> settingsFunction_heartPulseBloodFlowing[1] = {[]() { return 0; }};
static const char* settingNamesArray_heartPulseBloodFlowing[1] = {""};
static int minValuesArray_heartPulseBloodFlowing[1] = {0};
static int maxValuesArray_heartPulseBloodFlowing[1] = {0};
static const char* realNamesArray_heartPulseBloodFlowing[1] = {""};

static Effect _heartPulseBloodFlowing(
    "Heart Pulse Blood Flowing",
    FX_MODE_HEART_PULSE_BLOOD_FLOWING,
    settingsFunction_heartPulseBloodFlowing,
    settingNamesArray_heartPulseBloodFlowing,
    minValuesArray_heartPulseBloodFlowing,
    maxValuesArray_heartPulseBloodFlowing,
    realNamesArray_heartPulseBloodFlowing,
    0
);



static std::function<int()> settingsFunction_lighthouseBeaconV2[3] = {
    []() { return Settings::getVar0to10_1(); },
    []() { return Settings::getVar0to500_1(); },
    []() { return Settings::getVar0to128_1(); }
};
static const char* settingNamesArray_lighthouseBeaconV2[] = {"Length", "Time", "Fade"};
static int minValuesArray_lighthouseBeaconV2[] = {1, 0, 0};
static int maxValuesArray_lighthouseBeaconV2[] = {8, 500, 128};
static const char* realNamesArray_lighthouseBeaconV2[] = {
    "var_0to10_1", "var_0to500_1", "var_0to128_1"};

static Effect _lighthouseBeaconV2(
    "Lighthouse Beacon V2",
    FX_MODE_LIGHT_HOUSE_BEACON_V2,
    settingsFunction_lighthouseBeaconV2,
    settingNamesArray_lighthouseBeaconV2,
    minValuesArray_lighthouseBeaconV2,
    maxValuesArray_lighthouseBeaconV2,
    realNamesArray_lighthouseBeaconV2,
    3
);



static std::function<int()> settingsFunction_matchingGlitter1[2] = {
    []() { return Settings::getVar0to500_1(); },
    []() { return Settings::getVar0to500_2(); }
};
static const char* settingNamesArray_matchingGlitter1[] = {"Time hue", "Time Stripe"};
static int minValuesArray_matchingGlitter1[] = {1, 1};
static int maxValuesArray_matchingGlitter1[] = {500, 500};
static const char* realNamesArray_matchingGlitter1[] = {
    "var_0to500_1","var_0to500_2"};

static Effect _matchingGlitter1(
    "Matching Glitter 1",
    FX_MODE_MATCHING_GLITTER_1,
    settingsFunction_matchingGlitter1,
    settingNamesArray_matchingGlitter1,
    minValuesArray_matchingGlitter1,
    maxValuesArray_matchingGlitter1,
    realNamesArray_matchingGlitter1,
    2
);

// static std::function<int()> settingsFunction_matchingGlitter2[2] = {
//     []() { return Settings::getVar0to500_1(); },
//     []() { return Settings::getVar0to500_2(); }
// };
// static const char* settingNamesArray_matchingGlitter2[] = {"Time hue", "Time Stripe"};
// static int minValuesArray_matchingGlitter2[] = {1, 1};
// static int maxValuesArray_matchingGlitter2[] = {500, 500};
// static const char* realNamesArray_matchingGlitter2[] = {
//     "var_0to500_1","var_0to500_2"};

// static Effect _matchingGlitter2(
//     "Matching Glitter 2",
//     FX_MODE_MATCHING_GLITTER_2,
//     settingsFunction_matchingGlitter2,
//     settingNamesArray_matchingGlitter2,
//     minValuesArray_matchingGlitter2,
//     maxValuesArray_matchingGlitter2,
//     realNamesArray_matchingGlitter2,
//     2
// );

// static std::function<int()> settingsFunction_matchingGlitter3[2] = {
//     []() { return Settings::getVar0to500_1(); },
//     []() { return Settings::getVar0to500_2(); }
// };
// static const char* settingNamesArray_matchingGlitter3[] = {"Time hue", "Time Stripe"};
// static int minValuesArray_matchingGlitter3[] = {1, 1};
// static int maxValuesArray_matchingGlitter3[] = {500, 500};
// static const char* realNamesArray_matchingGlitter3[] = {
//     "var_0to500_1","var_0to500_2"};
// static Effect _matchingGlitter3(
//     "Matching Glitter 3",
//     FX_MODE_MATCHING_GLITTER_3,
//     settingsFunction_matchingGlitter3,
//     settingNamesArray_matchingGlitter3,
//     minValuesArray_matchingGlitter3,
//     maxValuesArray_matchingGlitter3,
//     realNamesArray_matchingGlitter3,
//     2
// );

// static std::function<int()> settingsFunction_matchingGlitter4[2] = {
//     []() { return Settings::getVar0to500_1(); },
//     []() { return Settings::getVar0to500_2(); }
// };
// static const char* settingNamesArray_matchingGlitter4[] = {"Time hue", "Time Stripe"};
// static int minValuesArray_matchingGlitter4[] = {1, 1};
// static int maxValuesArray_matchingGlitter4[] = {500, 500};
// static const char* realNamesArray_matchingGlitter4[] = {
//     "var_0to500_1","var_0to500_2"};
// static Effect _matchingGlitter4(
//     "Matching Glitter 4",
//     FX_MODE_MATCHING_GLITTER_4,
//     settingsFunction_matchingGlitter4,
//     settingNamesArray_matchingGlitter4,
//     minValuesArray_matchingGlitter4,
//     maxValuesArray_matchingGlitter4,
//     realNamesArray_matchingGlitter4,
//     2
// );

// static std::function<int()> settingsFunction_mirrorFadeEnds[1] = {
//     []() { return Settings::getVar0to10_1(); }
// };
// static const char* settingNamesArray_mirrorFadeEnds[] = {"Fade"};
// static int minValuesArray_mirrorFadeEnds[] = {0};
// static int maxValuesArray_mirrorFadeEnds[] = {20};
// static const char* realNamesArray_mirrorFadeEnds[] = {"var_0to10_1"};
// static Effect _mirrorFadeEnds(
//     "Mirror Fade Ends",
//     FX_MODE_MIRROR_FADE_ENDS,
//     settingsFunction_mirrorFadeEnds,
//     settingNamesArray_mirrorFadeEnds,
//     minValuesArray_mirrorFadeEnds,
//     maxValuesArray_mirrorFadeEnds,
//     realNamesArray_mirrorFadeEnds,
//     1
// );

// Settings::getTidBlink(), Settings::getCoolingFire(), Settings::getSparksFire()
static std::function<int()> settingsFunction_Fire2012[3] = {
    []() { return Settings::getVar0to500_1(); },
    []() { return Settings::getVar0to200_1(); },
    []() { return Settings::getVar0to128_1(); }
};
static const char* settingNamesArray_Fire2012[] = {"Time", "Cooling", "Sparking"};
static int minValuesArray_Fire2012[] = {0,0,0};
static int maxValuesArray_Fire2012[] = {500, 200, 50};
static const char* realNamesArray_Fire2012[] = {
    "var_0to500_1", "var_0to200_1", "var_0to128_1"};
static Effect _Fire2012(
    "Fire 2012",
    FX_MODE_FIRE_2012,
    settingsFunction_Fire2012,
    settingNamesArray_Fire2012,
    minValuesArray_Fire2012,
    maxValuesArray_Fire2012,
    realNamesArray_Fire2012,
    3
);

static std::function<int()> settingsFunction_Fire2012_halfStrip[3] = {
    []() { return Settings::getVar0to500_1(); },
    []() { return Settings::getVar0to200_1(); },
    []() { return Settings::getVar0to128_1(); }
};
static const char* settingNamesArray_Fire2012_halfStrip[] = {"Time", "Cooling", "Sparking"};
static int minValuesArray_Fire2012_halfStrip[] = {0,0,0};
static int maxValuesArray_Fire2012_halfStrip[] = {500, 200, 50};
static const char* realNamesArray_Fire2012_halfStrip[] = {
    "var_0to500_1", "var_0to200_1", "var_0to128_1"};
static Effect _Fire2012_halfStrip(
    "Fire 2012 Half Strip",
    FX_MODE_FIRE_2012_HALF_STRIPE,
    settingsFunction_Fire2012_halfStrip,
    settingNamesArray_Fire2012_halfStrip,
    minValuesArray_Fire2012_halfStrip,
    maxValuesArray_Fire2012_halfStrip,
    realNamesArray_Fire2012_halfStrip,
    3
);


static std::function<int()> settingsFunction_movingColoredBar[2] = {
    []() { return Settings::getVar0to10_1(); },
    []() { return Settings::getVar0to140_1(); }
};
static const char* settingNamesArray_movingColoredBar[] = {"Length", "Frame Delay"};
static int minValuesArray_movingColoredBar[] = {1,0};
static int maxValuesArray_movingColoredBar[] = {8, 140};
static const char* realNamesArray_movingColoredBar[] = {
    "var_0to10_1", "var_0to140_1"};
static Effect _movingColoredBar(
    "Moving Colored Bar",
    FX_MODE_MOVING_COLORED_BAR,
    settingsFunction_movingColoredBar,
    settingNamesArray_movingColoredBar,
    minValuesArray_movingColoredBar,
    maxValuesArray_movingColoredBar,
    realNamesArray_movingColoredBar,
    2
);


static std::function<int()> settingsFunction_repeatingPattern[3] = {
    []() { return Settings::getVar0to128_1(); },
    []() { return Settings::getVar0to1000_1(); },
    []() { return Settings::getVar0to128_2(); }
};
static const char* settingNamesArray_repeatingPattern[] = {"Time 1", "Time 2", "Fade"};
static int minValuesArray_repeatingPattern[] = {1,1, 0};
static int maxValuesArray_repeatingPattern[] = {100, 1000, 128};
static const char* realNamesArray_repeatingPattern[] = {
    "var_0to128_1", "var_0to1000_1", "var_0to128_2"};
static Effect _repeatingPattern(
    "Repeating Patterns",
    FX_MODE_REPEATING_PATTERNS,
    settingsFunction_repeatingPattern,
    settingNamesArray_repeatingPattern,
    minValuesArray_repeatingPattern,
    maxValuesArray_repeatingPattern,
    realNamesArray_repeatingPattern,
    3
);

static std::function<int()> settingsFunction_savedPixel[2] = {
    []() { return Settings::getVar0to10_1(); },
    []() { return Settings::getVar0to1000_1(); }
};
static const char* settingNamesArray_savedPixel[] = {"Time 1", "Time 2"};
static int minValuesArray_savedPixel[] = {1,1};
static int maxValuesArray_savedPixel[] = {1000, 16};
static const char* realNamesArray_savedPixel[] = {"var_0to10_1", "var_0to1000_1"};
static Effect _savedPixel(
    "Saved Pixels",
    FX_MODE_SAVED_PIXELS,
    settingsFunction_savedPixel,
    settingNamesArray_savedPixel,
    minValuesArray_savedPixel,
    maxValuesArray_savedPixel,
    realNamesArray_savedPixel,
    2
);





// For the alternative way trying to no use all the memory but not working yet
static Effect _end_effect(
    nullptr,
    -1,
    {0},
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    0
);

static Effect effects[] = {_fillEffect, _blink,  _fillGradientTwoColors, 
                            _fillGradientThreeColors, _BackAndForthNoSmoothOneDot, _backAndForthNoSmoothLengthedDot, 
                            _hueFading, _hueWhiteWave, _movingPaletteLinear, _spotlightingPalette, _sinBeat8, 
                            _sinBeat8PhaseOffset,  _twoSinBeat8, 
                            _threeSinBeat8, _brightnessSinBeat8Palette, _funkyRainbowSinBeat8, 
                            _funkyRangeSinBeat8, _funkyRainbowSinBeat8Two,  _funkyRangeSinBeat8Two, 
                            _movingFunkyPalette, _rainbowWave, _choosenWave, 
                            _firstNoiseRainbow, _firstNoiseColor, _noisePalette, 
                            _runFire, _secondNoise, _fillNoise16, 
                            _rainbowDave, _marqueeDave, _twinkleOld, 
                            _twinkle, _comet, _cometOnce, 
                            _bounce,  _storm, 
                             _lighting, 
                            _lightingColored, _beat8_tail, 
                            _blendIntoRainbow, _breatheV2, _chaseTargetTalesVarA, 
                            _chaseTargetTalesVarB,_chaseTargetTalesVarC, 
                            _everyNTimerVariables, _fillUpStrip, 
                            _heartBeat3, _heartPulseBloodFlowing, _lighthouseBeaconV2, 
                            _matchingGlitter1, _Fire2012, 
                            _Fire2012_halfStrip, _movingColoredBar, _repeatingPattern, 
                             _end_effect};





/*struct Effect {
    const char* name;
    int effect;
    std::function<int()> settings[11];
    const char* settingNames[11];
    int minValues[11];
    int maxValues[11];
    const char* realNames[11];
    int numSettings;
};



static Effect _blendIntoRainbow {
    "Blend Into Rainbow", FX_MODE_BLEND_INTO_RAINBOW,
    {[]() { return Settings::getTidBlink();}, []() { return Settings::getTidBlendIntoRainbow();}, []() { return Settings::getInitialHue();}, []() { return Settings::getBlendAmount();}},
    {"Time", "Time 2", "Hue", "Blend"},
    {0,0,0,0},
    {1000, 1000, 255, 255},
    {"tid_blink", "tid_blendIntoRainbow", "initial_hue", "blend_amount"},
    4
};

static Effect _breatheV2 {
    "Breathe V2", FX_MODE_BREATHE_V2,
    {[](){return Settings::getPulseSpBreathe();}},
    {"Pulse"},
    {0},
    {255},
    {"pulseSp_breathe"},
    1
};




static Effect _end_effect = {nullptr, -1, {0}}; // End marker for effects array

static Effect effects[] = {_fillEffect, _blink, _rainbowStatic, _fillGradientTwoColors, _fillGradientThreeColors,
                            _BackAndForthNoSmoothOneDot, _backAndForthNoSmoothLengthedDot, _hueFading, _hueWhiteWave, 
                            _displayPaletteLinear, _movingPaletteLinear, _spotlightingPalette, _sinBeat8, _sinBeat8PhaseOffset, 
                            _sinBeat8TimeOff, _twoSinBeat8, _threeSinBeat8,  _brightnessSinBeat8Palette, 
                            _funkyRainbowSinBeat8, _funkyRangeSinBeat8, _funkyRainbowSinBeat8Two, _funkyRangeSinBeat8Two, 
                            _movingFunkyPalette, _rainbowWave, _choosenWave, _firstNoiseRainbow, _firstNoiseColor, 
                            _noisePalette, _runFire, _secondNoise, _fillNoise16,_rainbowDave, _marqueeDave, 
                            _twinkleOld, _twinkle, _comet, _cometOnce, _bounce, _fire, _storm, _stormColored, _stormPalette,
                            _lighting, _lightingColored, _lightingPalette, _beat8_tail, _blendIntoRainbow, _breatheV2,
                            _end_effect};*/




#endif