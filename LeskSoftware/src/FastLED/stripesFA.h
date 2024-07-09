#ifndef STRIPESFA_H
#define STRIPESFA_H

#include <FastLED.h>



class StripesFA {

    public :
        // Constructor with one color
        StripesFA(int _port, int _length, int _direction, int speed, uint32_t _color, uint8_t effect_number = 0);
        StripesFA(int _port, int _length, int _direction, int speed, uint32_t _color1, uint32_t _color2, uint8_t effect_number = 0);
        StripesFA(int _port, int _length, int _direction, int speed, uint32_t _color1, uint32_t _color2, uint32_t _color3, uint8_t effect_number = 0);

        void setup(int port, int _length);



        // [TODO] to have a function with 1,2,3 colors
        void setEffect(uint8_t effect);
        void setBrightness(uint8_t brightness);


        // [TODO] to have several way to set the color
        void setColor(uint8_t g, uint8_t r, uint8_t b);
        
        uint32_t getColor1();
        uint32_t getColor2();
        uint32_t getColor3();
        int getPort();
        int getLength();
        int getDirection();
        uint8_t getEffect();

        void stop();

    public : 
        int port;
        int length;
        int direction;
        int speed;
        uint32_t color1;
        uint32_t color2;
        uint32_t color3;
        CFastLED fastleds;
        uint8_t effect;
};

#endif

/*
Comments : 
    Attributes : I 



 */