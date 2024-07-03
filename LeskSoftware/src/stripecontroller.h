#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "stripesWS.h"
#include "stripesFA.h"


class StripeController {

    public:
        StripeController();
        void setup();
        void setColor(uint8_t red, uint8_t green, uint8_t blue);
        void setEffect(uint8_t effect);
        void setBrightness(uint8_t brightness);
        void run();
        void stop();
        int getNumberOfStripes();
    
    private:
        // For WS2812FX
        // std::vector<StripesWS> stripesWS;

        // For FastLED
        std::vector<StripesFA> stripesFA;
        

};


#endif