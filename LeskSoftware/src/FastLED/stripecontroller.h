#ifndef CONTROLLER_H
#define CONTROLLER_H

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

        std::vector<uint32_t> getColors1();
        std::vector<uint32_t> getColors2();
        std::vector<uint32_t> getColors3();
        std::vector<int> getPorts();
        std::vector<int> getLengths();
        std::vector<int> getDirections();
        std::vector<uint8_t> getEffects();
    
    private:

        std::vector<StripesFA> stripesFA;
        

};


#endif