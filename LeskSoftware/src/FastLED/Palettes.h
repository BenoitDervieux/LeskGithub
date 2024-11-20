#ifndef PALETTES_H
#define PALETTES_H

#include <Arduino.h>
#include <FastLED.h>

class Palette {
public:
    CRGBPalette16 currentPalette;

    void setPalette(const String& paletteName) {
        if (paletteName == "purplePalette") {
            currentPalette = purplePalette;
        } else if (paletteName == "lavaPalette") {
            currentPalette = lavaPalette;
        } else if (paletteName == "pacificaPalette1") {
            currentPalette = pacifica_palette_1;
        } else if (paletteName == "pacifica2Palette") {
            currentPalette = pacifica_palette_2;
        } else if (paletteName == "pacifica3Palette") {
            currentPalette = pacifica_palette_3;
        } else if (paletteName == "sunsetPalette") {
            currentPalette = sunsetPalette;
        } else if (paletteName == "forestPalette") {
            currentPalette = forestPalette;
        } else if (paletteName == "oceanPalette") {
            currentPalette = oceanPalette;
        } else if (paletteName == "citrusPalette") {
            currentPalette = citrusPalette;
        } else if (paletteName == "neonPalette") {
            currentPalette = neonPalette;
        } else if (paletteName == "desertPalette") {
            currentPalette = desertPalette;
        } else if (paletteName == "pastelPalette") {
            currentPalette = pastelPalette;
        } else {
            // Optionally handle invalid palette names
            Serial.println("Palette not found.");
        }
    }

    CRGBPalette16 getCurrentPalette() {
        return currentPalette;
    }

    bool isNeonPalette() {
        return currentPalette == neonPalette;
    }

private:
    // Define your palettes here
    CRGBPalette16 heatmap_gp = CRGBPalette16 {
        CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black,
        CRGB::Red, CRGB::Red, CRGB::Yellow, CRGB::Yellow,
        CRGB::Yellow, CRGB::Yellow, CRGB::Green, CRGB::Green,
        CRGB::Green, CRGB::Green, CRGB::Blue, CRGB::Blue
    };

    CRGBPalette16 purplePalette = CRGBPalette16 {
        CRGB::DarkViolet, CRGB::DarkViolet, CRGB::DarkViolet, CRGB::DarkViolet,
        CRGB::Magenta, CRGB::Magenta, CRGB::Linen, CRGB::Linen,
        CRGB::Magenta, CRGB::Magenta, CRGB::DarkViolet, CRGB::DarkViolet,
        CRGB::DarkViolet, CRGB::DarkViolet, CRGB::Linen, CRGB::Linen
    };

    CRGBPalette16 lavaPalette = CRGBPalette16 {
        CRGB::DarkRed, CRGB::Maroon, CRGB::DarkRed, CRGB::Maroon,
        CRGB::DarkRed, CRGB::Maroon, CRGB::DarkRed, CRGB::DarkRed,
        CRGB::DarkRed, CRGB::DarkRed, CRGB::Red, CRGB::Orange,
        CRGB::White, CRGB::Orange, CRGB::Red, CRGB::DarkRed
    };

    CRGBPalette16 pacifica_palette_1 = CRGBPalette16 { 
        0x000507, 0x000409, 0x00030B, 0x00030D, 
        0x000210, 0x000212, 0x000114, 0x000117, 
        0x000019, 0x00001C, 0x000026, 0x000031, 
        0x00003B, 0x000046, 0x14554B, 0x28AA50 
    };

    CRGBPalette16 pacifica_palette_2 = CRGBPalette16 { 
        0x000507, 0x000409, 0x00030B, 0x00030D, 
        0x000210, 0x000212, 0x000114, 0x000117, 
        0x000019, 0x00001C, 0x000026, 0x000031, 
        0x00003B, 0x000046, 0x0C5F52, 0x19BE5F 
    };

    CRGBPalette16 pacifica_palette_3 = CRGBPalette16 { 
        0x000208, 0x00030E, 0x000514, 0x00061A, 
        0x000820, 0x000927, 0x000B2D, 0x000C33, 
        0x000E39, 0x001040, 0x001450, 0x001860, 
        0x001C70, 0x002080, 0x1040BF, 0x2060FF 
    };

    CRGBPalette16 sunsetPalette = CRGBPalette16 {
        0xFF4500, 0xFF6347, 0xFF7F50, 0xFFA07A,
        0xFFD700, 0xFFDAB9, 0xFFF5EE, 0xFFA07A,
        0xFF6347, 0xFF4500, 0xFFD700, 0xFFA500,
        0xFF8C00, 0xFF4500, 0xFF6347, 0xFF7F50
    };
    CRGBPalette16 forestPalette = CRGBPalette16 {
        0x013220, 0x2E8B57, 0x3CB371, 0x006400,
        0x8FBC8F, 0x228B22, 0x2E8B57, 0x556B2F,
        0x6B8E23, 0x006400, 0x32CD32, 0x00FF7F,
        0x3CB371, 0x2E8B57, 0x006400, 0x013220
    };
    CRGBPalette16 oceanPalette = CRGBPalette16 {
        0x000080, 0x0000CD, 0x1E90FF, 0x4682B4,
        0x5F9EA0, 0x20B2AA, 0x00CED1, 0x40E0D0,
        0xAFEEEE, 0xADD8E6, 0xB0E0E6, 0x5F9EA0,
        0x4682B4, 0x1E90FF, 0x0000CD, 0x000080
    };
    CRGBPalette16 citrusPalette = CRGBPalette16 {
        0xFFA500, 0xFF4500, 0xFF8C00, 0xFFD700,
        0xFFFACD, 0xFFF8DC, 0xFAFAD2, 0xFFE4B5,
        0xFFDAB9, 0xFFEFD5, 0xFFE4C4, 0xFFD700,
        0xFFA500, 0xFF8C00, 0xFF4500, 0xFFA07A
    };
    CRGBPalette16 neonPalette = CRGBPalette16 {
        0xFF00FF, 0xFF1493, 0xFF4500, 0xFF6347,
        0xFF8C00, 0xFFFF00, 0xADFF2F, 0x7FFF00,
        0x00FF00, 0x00FA9A, 0x00FFFF, 0x1E90FF,
        0x0000FF, 0x8A2BE2, 0xDA70D6, 0xFF00FF
    };
    CRGBPalette16 desertPalette = CRGBPalette16 {
        0xEDC9AF, 0xFFE4C4, 0xDEB887, 0xD2B48C,
        0xBC8F8F, 0xF4A460, 0xDAA520, 0xB8860B,
        0xCD853F, 0xD2691E, 0x8B4513, 0xA0522D,
        0x8B0000, 0xFFD700, 0xFF4500, 0xEDC9AF
    };
    CRGBPalette16 pastelPalette = CRGBPalette16 {
        0xFFB6C1, 0xFFDAB9, 0xFFFACD, 0xE6E6FA,
        0xE0FFFF, 0xAFEEEE, 0xD8BFD8, 0xDDA0DD,
        0xFFB6C1, 0xFAFAD2, 0xFFD700, 0xFFE4E1,
        0xE6E6FA, 0xD8BFD8, 0xAFEEEE, 0xE0FFFF
    };
};

#endif
