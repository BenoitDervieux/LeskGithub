#include "color_functions.h"

uint32_t ColorFunctions::fromRGBtoHex(int r, int g, int b) {
    if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0) {
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


CRGB ColorFunctions::hexToCRGB(const std::string& hex) {
    // Ensure the hex string is valid and properly formatted
    std::string cleanedHex = hex;
    if (cleanedHex.find("#")) {
        cleanedHex.erase(0, 1); // Remove '#'
    }
    uint32_t color = strtoul(cleanedHex.c_str(), nullptr, 16);
    return CRGB(
        (color >> 16) & 0xFF,  // Red
        (color >> 8) & 0xFF,   // Green
        color & 0xFF           // Blue
    );
}

// // Check for later when we'll need the JSON implementation with Painless mesh
// std::string ColorFunctions::decimalStringToHex(std::string decimalString) {
//     // Convert the decimal string to an integer
//     int decimalColor = std::stol(decimalString);

//     // Use sprintf to format the integer as a hexadecimal string
//     char hexColor[8];  // Enough space for a 6-digit hex number and the null terminator
//     sprintf(hexColor, "#%06X", decimalColor);
    
//     // Return the hexadecimal string
//     return std::string(hexColor);
// }

std::vector<uint8_t> ColorFunctions::extractRGB(uint32_t color) {
    std::vector<uint8_t> rgb(3); // Vector to hold RGB values
    rgb[0] = (color >> 16) & 0xFF; // Red component
    rgb[1] = (color >> 8) & 0xFF;  // Green component
    rgb[2] = color & 0xFF;         // Blue component
    return rgb;
}