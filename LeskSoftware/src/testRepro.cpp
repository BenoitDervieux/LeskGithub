#include "testRepro.h"
#include "const.h"
#include <FastLED.h>

extern CRGB leds[NUM_LEDS];

void FUNCTIONS::fill() {
        fill_rainbow(leds, NUM_LEDS, 0, 560);
}