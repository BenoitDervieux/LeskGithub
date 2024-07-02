#ifndef LESK_H
#define LESK_H

#include <Arduino.h>
#include <FastLED.h>

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




