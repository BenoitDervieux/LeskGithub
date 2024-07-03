#ifndef STRIPESFA_H
#define STRIPESFA_H

#include <FastLED.h>



class StripesFA {

    public :
        StripesFA(int _port, int _length, int _direction, int _speed, short int _mode, uint32_t _color);

        void setEffect(uint8_t effect);
        void setBrightness(uint8_t brightness);
        void setColor(uint8_t g, uint8_t r, uint8_t b);
        void stop();


    public : 
        int port;
        int length;
        int direction;
        int speed;
        uint32_t color;
        CFastLED fastleds;

};

#endif