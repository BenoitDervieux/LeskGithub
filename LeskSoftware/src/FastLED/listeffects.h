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

static Effect _fill_effect = {"Fill", FX_MODE_FILL, {red_1, green_1, blue_1}};
static Effect _blink = {"Blink", FX_MODE_BLINK, {red_1, green_1, blue_1, tid} }; 




static Effect _end_effect = {nullptr, -1, {0}}; // End marker for effects array

static Effect effects[] = {_fill_effect, _blink, _end_effect};




#endif