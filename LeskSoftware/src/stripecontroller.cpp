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
    int nb_stripes = 1;


    //*************************************
    // Here is for WS2812FX
    //*************************************
    
    // // Initialize the different stripes
    // for (int i = 0; i < nb_stripes; i++) {
    //     stripesWS.emplace_back(port, length, direction, speed, mode, color);
    //     // Stripes s(port + i, length, direction, speed, mode, color);
    //     // stripes[i] = s;
    //     // stripes.push_back(s);
    // }


    //*************************************
    // Here is for FastLED
    //*************************************
    for (int i = 0; i < nb_stripes; i++) {
        stripesFA.emplace_back(port, length, direction, speed, mode, color);
    }

}


void StripeController::run() {
    //*************************************
    // Here is for WS2812FX
    //*************************************
    // for (auto& s: stripesWS) {
    //     s.ws2812fx.service();
    // }



    //*************************************
    // Here is for FastLED
    //*************************************
}

void StripeController::setColor(uint8_t red, uint8_t green, uint8_t blue) {
    std::cout << "Inside color function" << std::endl;

    //*************************************
    // Here is for WS2812FX
    //*************************************
    // for (auto& s: stripesWS) {
    //     std::cout << "Setting color inside controller" << std::endl;
    //     s.setColor(red, green, blue);
    // }

    
    //*************************************
    // Here is for FastLED
    //*************************************
    for (auto& s: stripesFA) {
        std::cout << "Setting color inside controller" << std::endl;
        s.setColor(red, green, blue);
    }

}

void StripeController::setEffect(uint8_t effect) {
    //*************************************
    // Here is for WS2812FX
    //*************************************
    // for (auto& s: stripesWS) {
    //     s.setEffect(effect);
    // }


    //*************************************
    // Here is for FastLED
    //*************************************

}

void StripeController::setBrightness(uint8_t brightness) {
    //*************************************
    // Here is for WS2812FX
    //*************************************
    // for (auto& s: stripesWS) {
    //     s.setBrightness(brightness);
    // }


    //*************************************
    // Here is for FastLED
    //*************************************
}

void StripeController::stop() {
    //*************************************
    // Here is for WS2812FX
    //*************************************
    // for (auto& s: stripesWS) {
    //     s.stop();
    // }


    //*************************************
    // Here is for FastLED
    //*************************************
}

int StripeController::getNumberOfStripes() {
    //*************************************
    // Here is for WS2812FX
    //*************************************
    // return stripesWS.size();


    //*************************************
    // Here is for FastLED
    //*************************************
    return stripesFA.size();
    
}