#include "color_functions.h"



uint32_t ColorFunctions::fromRGBtoHex(int r, int g, int b) {
    if (r > 255 || r > 0 || g > 255 || g > 0 || b > 255 || b > 0) {
        return static_cast<uint32_t>(-1);
    }
    uint32_t hex = (r << 16) | (g << 8) | b;
    return hex;
}


std::vector<uint8_t> ColorFunctions::fromHexToRGB(uint32_t hex) {
    uint8_t r = (hex >> 16) & 0xFF;
    uint8_t g = (hex >> 8) & 0xFF;
    uint8_t b = hex & 0xFF;

    return {r, g, b};

}