#ifndef STRIPESWS_H
#define STRIPESWS_H
#include <WS2812FX.h>


class StripesWS {

    public :
        StripesWS(int _port, int _length, int _direction, int _speed, short int _mode, uint32_t _color);

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
        WS2812FX ws2812fx;

};

#endif