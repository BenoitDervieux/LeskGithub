#ifndef COLOR_FUNCTIONS_H
#define COLOR_FUNCTIONS_H

#include <iostream>
#include <vector>
#include <string>
#include <FastLED.h>


class ColorFunctions {
    public: 
        static uint32_t fromRGBtoHex(int r, int g, int b);
        static std::vector<uint8_t> fromHexToRGB(uint32_t hex);
        static CRGB hexToCRGB(const std::string& hex);
        // static std::string decimalStringToHex(std::string decimalString);
        static std::vector<uint8_t> extractRGB(uint32_t color);
    
};


#endif