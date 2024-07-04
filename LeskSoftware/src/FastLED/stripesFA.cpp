#include "stripesFA.h"
#include "const.h"
#include <iostream>
#include <FastLED.h>


CRGB leds[NUM_LEDS];

// Constructor 1 color
StripesFA::StripesFA(int _port, int _length, int _direction, uint32_t _color, uint8_t effect_number = 0)
 : port(_port), length(_length), direction(_direction), color1(_color), effect(effect_number) {
    // This is a way to instantiate different stripes here
    // Not the smartest but let's take it for now
    this->setup(_port, _length);
}

// Constructor 2 colors
StripesFA::StripesFA(int _port, int _length, int _direction, uint32_t _color1, uint32_t _color2, uint8_t effect_number = 0)
 : port(_port), length(_length), direction(_direction), color1(_color1), color2(_color2), effect(effect_number) {
    // This is a way to instantiate different stripes here
    // Not the smartest but let's take it for now
    this->setup(_port, _length);
}

// Constructor 3 colors
StripesFA::StripesFA(int _port, int _length, int _direction, uint32_t _color1, uint32_t _color2, uint32_t _color3, uint8_t effect_number = 0)
 : port(_port), length(_length), direction(_direction), color1(_color1), color2(_color2), color3(_color3), effect(effect_number) {
    // This is a way to instantiate different stripes here
    // Not the smartest but let's take it for now
    this->setup(_port, _length);
}




void StripesFA::setup(int port, int _length) {
    if (port == DATA_PIN_1) {
    FastLED.addLeds<WS2812B, DATA_PIN_1, GRB>(leds, _length);
    } else if (port == DATA_PIN_2) {
    FastLED.addLeds<WS2812B, DATA_PIN_2, GRB>(leds, _length);
    }
    FastLED.setBrightness(100);
}


void StripesFA::setEffect(uint8_t effect) {
    // This system of switching effect seems good for now
    // I just need to get a lot of function and to define them
    // in the listeffects.h file
    switch(effect) {
        case 0:
            fill_solid(leds, NUM_LEDS, CRGB(this->color1));
            this->effect = 0;
            break;
        case 1:
            fill_rainbow(leds, NUM_LEDS, 0, 255 / NUM_LEDS);
            this->effect = 1;
            break;
        case 2:
            fill_gradient_RGB(leds, NUM_LEDS, CRGB(255,0,0), CRGB(0,0,255));
            this->effect = 2;
            break;
        case 3:
            break;
        default:
            break;
    }
    FastLED.show();

}

void StripesFA::setBrightness(uint8_t brightness) {
    FastLED.setBrightness(brightness);
    FastLED.show();
}

void StripesFA::setColor(uint8_t g, uint8_t r, uint8_t b) {
   std::cout << "Inside color function in the stripe" << std::endl;
   fill_solid(leds, NUM_LEDS, CRGB(g, r, b));
   FastLED.show();
}

void StripesFA::stop() {

}

uint32_t StripesFA::getColor1() {
    return this->color1;
}

uint32_t StripesFA::getColor2() {
    return this->color2;
}

uint32_t StripesFA::getColor3() {
    return this->color3;
}

int StripesFA::getPort() {
    return this->port;
}
int StripesFA::getLength() {
    return this->length;
}
int StripesFA::getDirection() {
    return this->direction;

}
uint8_t StripesFA::getEffect() {
    return this->effect;
}

