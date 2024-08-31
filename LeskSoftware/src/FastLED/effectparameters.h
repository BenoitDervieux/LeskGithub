#ifndef EFFECTPARAMETERS_H
#define EFFECTPARAMETERS_H
#include <cstdint>

// wait for implementing this one, we first need some confirmation
class EffectParameters {

    public:
        EffectParameters();


    private:
    // Color variables
        uint8_t red1;
        uint8_t green1;
        uint8_t blue1;
        uint8_t red2;
        uint8_t green2;
        uint8_t blue2;
        uint8_t red3;
        uint8_t green3;
        uint8_t blue3;
        uint8_t hueNumber;
    // Time Variables
        int tid;
        int tid2;

};


#endif