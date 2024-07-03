#include "stripesFA.h"
#include "const.h"
#include <iostream>
#include <FastLED.h>

#define NUM_LEDS 10
#define DATA_PIN_1 18
#define DATA_PIN_2 23
CRGB leds[NUM_LEDS];

StripesFA::StripesFA(int _port, int _length, int _direction, int _speed, short int _mode, uint32_t _color)
 : port(_port), length(_length), direction(_direction), speed(_speed), color(_color) {
    FastLED.addLeds<WS2812B, DATA_PIN_1, GRB>(leds, _length);
    
}


void StripesFA::setEffect(uint8_t effect) {

}

void StripesFA::setBrightness(uint8_t brightness) {

}

void StripesFA::setColor(uint8_t g, uint8_t r, uint8_t b) {
    std::cout << "Inside color function in the stripe" << std::endl;
   fill_solid(leds, NUM_LEDS, CRGB(g, r, b));
   FastLED.show();

}

void StripesFA::stop() {

}

