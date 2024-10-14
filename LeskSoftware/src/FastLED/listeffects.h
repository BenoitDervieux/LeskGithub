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
    // int settings[10];
    std::function<int()> settings[10];
    const char* settingNames[10];
    int minValues[10];
    int maxValues[10];
    const char* realNames[10];
    int numSettings;
};

static Effect _fill_effect = {"Fill", FX_MODE_FILL, 
                            {[]() { return Settings::getR(); }, []() { return Settings::getG(); }, []() { return Settings::getB(); }}, 
                            {"Red", "Green", "Blue"}, {0, 0, 0}, {255, 255, 255}, {"r", "g", "b"}, 3};
static Effect _blink = {"Blink", FX_MODE_BLINK, 
                        {[]() { return Settings::getR(); }, []() { return Settings::getG(); }, []() { return Settings::getB(); }, []() { return Settings::getTidBlink(); }}, 
                        {"Red", "Green", "Blue", "Time"}, {0, 0, 0, 30}, {255, 255, 255, 1000}, {"r", "g", "b", "tid_blink"}, 4}; 




static Effect _end_effect = {nullptr, -1, {0}}; // End marker for effects array

static Effect effects[] = {_fill_effect, _blink, _end_effect};




#endif