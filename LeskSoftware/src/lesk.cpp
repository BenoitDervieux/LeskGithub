#include <WS2812FX.h>
#include <FastLED.h>
#include "lesk.h"
#include "const.h"
#include "controller.h"


// CRGB leds[NUM_LEDS];


//Declaration for WS2812FX
// WS2812FX ws2812fx(NUM_LEDS, DATA_PIN, NEO_GRB);
//Be carefull here for the type of stripe we need the NEO_PIXEL type https://github.com/adafruit/Adafruit_NeoPixel/blob/master/Adafruit_NeoPixel.h
Controller controller;

void LESK::setup() {
    controller = Controller();
}

void LESK::loop() {
    // FastLED.show();
    // ws2812fx.service();
    controller.run();
}