#ifndef LESK_H
#define LESK_H

#include <Arduino.h>
#include <FastLED.h>
#include <WS2812FX.h>
#include "stripes.h"
#include "const.h"
#include "controller.h"

class LESK {
    public:
        static LESK& instance() {
            static LESK instance;
            return instance;
        }
        void setup();
        void loop();
    private:

};

#endif




