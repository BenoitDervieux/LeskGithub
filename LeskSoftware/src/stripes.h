#ifndef LESK_H
#define LESK_H
#include <WS2812FX.h>


class Stripes {

    public :
        Stripes(int _port, int _length, int _direction, int _speed, short int _mode);

        void setEffect();

    private : 
        int port;
        int length;
        int direction;
        int speed;
        WS2812FX ws2812fx;

};

#endif