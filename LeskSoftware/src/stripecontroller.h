#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "stripes.h"


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
        std::vector<Stripes> stripes;
        

};


#endif