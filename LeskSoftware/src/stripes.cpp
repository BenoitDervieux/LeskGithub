#include "stripes.h"
#include "const.h"
#include <iostream>


Stripes::Stripes(int _port, int _length, int _direction, int _speed, short int _mode, WS2812FX _ws2812fx)
 : port(_port), length(_length), direction(_direction), speed(_speed), ws2812fx(_ws2812fx){
    ws2812fx.init();
    ws2812fx.setMode(_mode);
    ws2812fx.setSpeed(_speed);
    ws2812fx.setBrightness(255);
    ws2812fx.setColor(BLUE);
    ws2812fx.start();
}