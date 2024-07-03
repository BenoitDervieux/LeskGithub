#ifndef COLOR_FUNCTIONS_H
#define COLOR_FUNCTIONS_H

#include <iostream>
#include <vector>


class ColorFunctions {
    public: 
        static uint32_t fromRGBtoHex(int r, int g, int b);
        static std::vector<uint8_t> fromHexToRGB(uint32_t hex);
    
};


#endif