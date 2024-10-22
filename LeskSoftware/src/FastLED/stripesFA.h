#ifndef STRIPESFA_H
#define STRIPESFA_H

#define FASTLED_INTERRUPT_RETRY_COUNT 5
#define FASTLED_ALLOW_INTERRUPTS 0

#include <FastLED.h>
#include "./FastLedEffects/FastLedEffects.h"
#include "color_functions.h"
#include "defineeffectsettings.h"
#include "Settings.h"



class StripesFA {

    public :
        // Constructor with one color
        StripesFA(int _port, int _length, int _direction, int speed, int effectClassLvl, CRGB _color);
        StripesFA(int _port, int _length, int _direction, int speed, int effectClassLvl, CRGB _color, CRGB _color2);
        StripesFA(int _port, int _length, int _direction, int speed, int effectClassLvl, CRGB _color, CRGB _color2, CRGB _color3);

        void setup(int port, int _length);


        // [TODO] to have a function with 1,2,3 colors
        void setEffect(int effect);
        void setBrightness(uint8_t brightness);


        // [TODO] to have several way to set the color
        void setColor(uint8_t g, uint8_t r, uint8_t b);
        
        CRGB getColor1();
        CRGB getColor2();
        CRGB getColor3();
        int getPort();
        int getLength();
        int getDirection();
        int getEffect();

        void stop();

    public : 
        int port;
        int length;
        int direction;
        int speed;
        int effectClassLvl;
        CRGB color1;
        CRGB color2;
        CRGB color3;
        CFastLED fastleds;
        
};

#endif

/*
Comments : 
    Attributes : I 



 */