#ifndef PALETTES_H
#define PALETTES_H

#include <Arduino.h>
#include <FastLED.h>

DEFINE_GRADIENT_PALETTE(heatmap_gp) {
    0, 0, 0, 0,
    128, 255, 0, 0,
    200, 255, 255, 0,
    255, 255, 255, 255
};

CRGBPalette16 purplePalette = CRGBPalette16 {
    CRGB::DarkViolet, CRGB::DarkViolet, CRGB::DarkViolet, CRGB::DarkViolet,
    CRGB::Magenta, CRGB::Magenta,CRGB::Linen, CRGB::Linen,
    CRGB::Magenta, CRGB::Magenta, CRGB::DarkViolet, CRGB::DarkViolet,
    CRGB::DarkViolet, CRGB::DarkViolet, CRGB::Linen, CRGB::Linen
};

CRGBPalette16 lavaPalette = CRGBPalette16 {
    CRGB::DarkRed, CRGB::Maroon, CRGB::DarkRed, CRGB::Maroon,
    CRGB::DarkRed, CRGB::Maroon, CRGB::DarkRed, CRGB::DarkRed,
    CRGB::DarkRed, CRGB::DarkRed, CRGB::Red, CRGB::Orange,
    CRGB::White, CRGB::Orange, CRGB::Red, CRGB::DarkRed
};

CRGBPalette16 pacifica_palette_1 = 
    { 0x000507, 0x000409, 0x00030B, 0x00030D, 0x000210, 0x000212, 0x000114, 0x000117, 
      0x000019, 0x00001C, 0x000026, 0x000031, 0x00003B, 0x000046, 0x14554B, 0x28AA50 };
CRGBPalette16 pacifica_palette_2 = 
    { 0x000507, 0x000409, 0x00030B, 0x00030D, 0x000210, 0x000212, 0x000114, 0x000117, 
      0x000019, 0x00001C, 0x000026, 0x000031, 0x00003B, 0x000046, 0x0C5F52, 0x19BE5F };
CRGBPalette16 pacifica_palette_3 = 
    { 0x000208, 0x00030E, 0x000514, 0x00061A, 0x000820, 0x000927, 0x000B2D, 0x000C33, 
      0x000E39, 0x001040, 0x001450, 0x001860, 0x001C70, 0x002080, 0x1040BF, 0x2060FF };


#endif