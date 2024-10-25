#ifndef LISTCOLLECTIONS_H
#define LISTCOLLECTIONS_H

#include "listeffects.h"

struct LEDCollection {
    const char* name;
    Effect* effect[30];
};

LEDCollection testCollection1 = { "Test Collection 1",  {&_fillEffect, &_blink}};
LEDCollection testCollection2 = { "Test Collection 2",  {&_blink}};

LEDCollection collections[] = { testCollection1, testCollection2 };


#endif