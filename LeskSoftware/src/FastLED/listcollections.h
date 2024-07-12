#ifndef LISTCOLLECTIONS_H
#define LISTCOLLECTIONS_H

#include "listeffects.h"

struct LEDCollection {
    const char* name;
    Effect effect[30];
};

LEDCollection testCollection1 = { "Test Collection 1",  {_fill_effect, _rainbow_effect, _gradient_rgb_effect}};
LEDCollection testCollection2 = { "Test Collection 2",  { _rainbow_effect, _gradient_rgb_effect}};

LEDCollection collections[] = { testCollection1, testCollection2 };


#endif