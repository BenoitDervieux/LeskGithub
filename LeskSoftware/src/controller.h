#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "stripes.h"


class Controller {
    public:
        Controller();

        void setColor(uint8_t red, uint8_t green, uint8_t blue);
        void setEffect(uint8_t effect);
        void setBrightness(uint8_t brightness);
        void run();
    
    private:
        Stripes stripes;

};


#endif