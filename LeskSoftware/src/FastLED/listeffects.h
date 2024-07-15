#ifndef LISTEFFECTS_H
#define LISTEFFECTS_H

#include "defineeffects.h"
#include "defineeffectsettings.h"


// The idea of this structure is to get the parameters of the effect as well as it's name
// For instance, let's take the effects "blink"
// The effect can have a first paramater which will be the time of blinking, then the time of pause
// This is just a test and we'll see later what happens
struct Effect {
    const char* name;
    int effect;
    int settings[10];
};

static Effect _fill_effect = {"Fill", FILL, {ONECOLOR}};
static Effect _rainbow_effect = {"Rainbow", RAINBOW, {SPEED}};
static Effect _gradient_rgb_effect = {"Gradient RGB", GRADIENT_RGB, {SPEED, TWOCOLOR, THREECOLOR}};
static Effect _end_effect = {nullptr, -1, {0}}; // End marker for effects array

static Effect effects[] = {_fill_effect, _rainbow_effect, _gradient_rgb_effect, _end_effect};




#endif