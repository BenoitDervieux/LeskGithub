#include "stripecontroller.h"
#include <iostream>

StripeController::StripeController() {
    
}

void StripeController::setup() {
    // Here we initialize the 1 stripe,let's fake it
    // SIMULATE --> fetching the information here
    int port = 18;
    int length = 10;
    int direction = 1;
    int speed = 1000;
    short int mode = 0;
    uint32_t color = 0xFF0000;

    // Simulate the number of stripes fetched
    int nb_stripes = 2;
    
    // Initialize the different stripes
    for (int i = 0; i < nb_stripes; i++) {
        stripes.emplace_back(port, length, direction, speed, mode, color);
        // Stripes s(port + i, length, direction, speed, mode, color);
        // stripes[i] = s;
        // stripes.push_back(s);
    }

}


void StripeController::run() {
    for (auto& s: stripes) {
        s.ws2812fx.service();
    }
}

void StripeController::setColor(uint8_t red, uint8_t green, uint8_t blue) {
    std::cout << "Inside color function" << std::endl;
    for (auto& s: stripes) {
        std::cout << "Setting color inside controller" << std::endl;
        s.setColor(red, green, blue);
    }
    // this->run();
}

void StripeController::setEffect(uint8_t effect) {
    for (auto& s: stripes) {
        s.setEffect(effect);
    }

}

void StripeController::setBrightness(uint8_t brightness) {
    for (auto& s: stripes) {
        s.setBrightness(brightness);
    }
}

void StripeController::stop() {
    for (auto& s: stripes) {
        s.stop();
    }
}

int StripeController::getNumberOfStripes() {
    return stripes.size();
}