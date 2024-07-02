#include "controller.h"

WS2812FX ws2812fx;

Controller::Controller() {
    // Here we initialize the 1 stripe,let's fake it
    int port = 18;
    int length = 10;
    int direction = 0;
    int speed = 1000;
    short int mode = 0;
    WS2812FX ws2812fx = WS2812FX(length, port, NEO_GRB);
    Stripes stripe(port, length, direction, speed, mode, ws2812fx);
};


void Controller::run() {
    for (Stripes s: stripes) {
        s.ws2812fx.service();
    }
}

void Controller::setColor(uint8_t red, uint8_t green, uint8_t blue) {
    for (Stripes s: stripes) {
        s.ws2812fx.setColor(red, green, blue);
    }
    this->run();
}

void Controller::setEffect(uint8_t effect) {
    for (Stripes s: stripes) {
        s.ws2812fx.setMode(effect);
    }

}

void Controller::setBrightness(uint8_t brightness) {
    for (Stripes s: stripes) {
        s.ws2812fx.setBrightness(brightness);
    }
}