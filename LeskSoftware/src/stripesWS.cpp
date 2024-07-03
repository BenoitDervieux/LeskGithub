#include "stripesWS.h"
#include "const.h"
#include <iostream>
#include <WS2812FX.h>

StripesWS::StripesWS(int _port, int _length, int _direction, int _speed, short int _mode, uint32_t _color)
 : port(_port), length(_length), direction(_direction), speed(_speed), color(_color), ws2812fx(length, port, NEO_GRB) {
    ws2812fx.init();
    ws2812fx.setMode(_mode);
    ws2812fx.setSpeed(_speed);
    ws2812fx.setBrightness(100);
    ws2812fx.setColor(_color);
    ws2812fx.start();
    ws2812fx.service();
}


void StripesWS::setEffect(uint8_t effect) {
    ws2812fx.setMode(effect);
    ws2812fx.service();
}

void StripesWS::setBrightness(uint8_t brightness) {
    ws2812fx.setBrightness(brightness);
    ws2812fx.service();

}

void StripesWS::setColor(uint8_t g, uint8_t r, uint8_t b) {
    std::cout << "Inside color function in the stripe" << std::endl;
    ws2812fx.setColor(g, r, b);
    ws2812fx.service();
}

void StripesWS::stop() {
    // This functions basically stop the stripe and it turns it off
    // No way to make it bright again after (not that I have tried tho)
    ws2812fx.stop();
    ws2812fx.service();
}

