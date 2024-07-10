#ifndef STRIPESFA_H
#define STRIPESFA_H

#include <FastLED.h>



class StripesFA {

    public :
        // Constructor with one color
        StripesFA(int _port, int _length, int _direction, int speed, int effect_number, uint32_t _color);
        StripesFA(int _port, int _length, int _direction, int speed, int effect_number, uint32_t _color1, uint32_t _color2);
        StripesFA(int _port, int _length, int _direction, int speed, int effect_number, uint32_t _color1, uint32_t _color2, uint32_t _color3);

        void setup(int port, int _length);


        // [TODO] to have a function with 1,2,3 colors
        void setEffect(int effect);
        void setBrightness(uint8_t brightness);


        // [TODO] to have several way to set the color
        void setColor(uint8_t g, uint8_t r, uint8_t b);
        
        uint32_t getColor1();
        uint32_t getColor2();
        uint32_t getColor3();
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
        int effect;
        uint32_t color1;
        uint32_t color2;
        uint32_t color3;
        CFastLED fastleds;
        
};

#endif

/*
Comments : 
    Attributes : I 



 */