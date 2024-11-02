#include "Settings.h"
#include "Palettes.h"

ColorObject         Settings::color1                                    = CRGB::Red;
ColorObject         Settings::color2                                    = CRGB::Blue;
ColorObject         Settings::color3                                    = CRGB::Green;
int                 Settings::effect                                    = 1;
int                 Settings::speed                                     = 30;
uint8_t             Settings::r                                         = 0;
uint8_t             Settings::g                                         = 0;
uint8_t             Settings::b                                         = 0;
uint8_t             Settings::r2                                        = 0;
uint8_t             Settings::g2                                        = 0;
uint8_t             Settings::b2                                        = 0;
uint8_t             Settings::r3                                        = 0;
uint8_t             Settings::g3                                        = 0;
uint8_t             Settings::b3                                        = 0;

CRGBPalette16       Settings::palette1                                  = lavaPalette;
bool                Settings::mirror_bounce                             = false;
bool                Settings::breversed_fire                            = true;   
float               Settings::pulseSp_breathe                           = 0.1;
bool                Settings::rainbow_heartBeat3                        = true;
bool                Settings::matchingGlitter_second                    = true;
bool                Settings::matchingGlitter_third                     = true;
bool                Settings::more_matchingGlitter4                     = true;

int                 Settings::var_0to5_1                                = 1;
int                 Settings::var_0to10_1                               = 1;
int                 Settings::var_0to10_2                               = 1;
int                 Settings::var_0to10_3                               = 1;
int                 Settings::var_0to128_1                              = 1;
int                 Settings::var_0to128_2                              = 1;
int                 Settings::var_0to140_1                              = 1;
int                 Settings::var_0to140_2                              = 1;
int                 Settings::var_0to200_1                              = 1;
int                 Settings::var_0to255_1                              = 1;
int                 Settings::var_0to255_2                              = 1;
int                 Settings::var_0to500_1                              = 1;
int                 Settings::var_0to500_2                              = 1;
int                 Settings::var_0to1000_1                             = 1;
int                 Settings::var_0to1000_2                             = 1;
int                 Settings::var_0to3000_1                             = 1;