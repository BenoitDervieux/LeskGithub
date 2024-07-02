
#include <WS2812FX.h>
#include <FastLED.h>
#include "lesk.h"
#include "const.h"


//Declaration for WS2812FX
WS2812FX ws2812fx(NUM_LEDS, DATA_PIN, NEO_GRB); //Be carefull here for the type of stripe we need the NEO_PIXEL type https://github.com/adafruit/Adafruit_NeoPixel/blob/master/Adafruit_NeoPixel.h
// CRGB leds[NUM_LEDS];

void LESK::setup() {

    ws2812fx.init();
    ws2812fx.setBrightness(105);
    ws2812fx.setColor(RED);
    ws2812fx.setSpeed(1000);
    ws2812fx.setMode(1);
    ws2812fx.start();

}

void LESK::loop() {
    // FastLED.show();
    ws2812fx.service();
}