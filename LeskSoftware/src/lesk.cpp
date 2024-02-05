#include "const.h"
#include <WS2812FX.h>
#include "testRepro.h"
#include <FastLED.h>


//Declaration for WS2812FX
//WS2812FX ws2812fx(NUM_LEDS, DATA_PIN, GRB);
FUNCTIONS functions;
CRGB leds[NUM_LEDS];

void LESK::setup() {
    FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
    /*ws2812fx.init();
    ws2812fx.setBrightness(150);
    ws2812fx.setSegment(0, 0, NUM_LEDS - 1);
    ws2812fx.setMode(FX_MODE_STATIC);
    ws2812fx.setColor(0xFF0000);
    //FastLED.show();
    ws2812fx.start();
    ws2812fx.init();
    ws2812fx.setBrightness(100);
    ws2812fx.setSpeed(5000);
    ws2812fx.setMode(FX_MODE_RAINBOW_CYCLE);
    ws2812fx.start();*/
    FastLED.setBrightness(100);
    //functions.fill();
    FastLED.show();
}

void LESK::loop() {
    functions.fill();
    FastLED.show();
    //ws2812fx.service();
}