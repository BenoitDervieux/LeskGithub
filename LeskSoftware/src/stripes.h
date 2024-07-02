#ifndef STRIPES_H
#define STRIPES_H
#include <WS2812FX.h>


class Stripes {

    public :
        Stripes(int _port, int _length, int _direction, int _speed, short int _mode, WS2812FX _ws2812fx);

        void setEffect();
        void setBrightness();
        void setColor();

    public : 
        int port;
        int length;
        int direction;
        int speed;
        WS2812FX &ws2812fx;

};

#endif