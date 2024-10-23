#include "Settings.h"
#include "Palettes.h"

CRGB                Settings::color                                     = CRGB::Red;
int                 Settings::effect                                    = 1;
int                 Settings::speed                                     = 30;
CRGB                Settings::color2                                    = CRGB::Red;
CRGB                Settings::color3                                    = CRGB::Red;
uint8_t             Settings::r                                         = 0;
uint8_t             Settings::g                                         = 0;
uint8_t             Settings::b                                         = 0;
uint8_t             Settings::r2                                        = 0;
uint8_t             Settings::g2                                        = 0;
uint8_t             Settings::b2                                        = 0;
uint8_t             Settings::r3                                        = 0;
uint8_t             Settings::g3                                        = 0;
uint8_t             Settings::b3                                        = 0;
int                 Settings::tid_blink                                 = 100;
int                 Settings::tid_backAndForthNoSmoothOneDot            = 100;
int                 Settings::tid_backAndForthNoSmoothLengthedDot       = 100;
int                 Settings::length_backAndForthNoSmoothLengthedDot    = 3;
int                 Settings::tid_hueFading                             = 0;
uint8_t             Settings::hueInsert_hueWhiteWave                    = 0;
int                 Settings::tid_hueWhiteWave                          = 100;
CRGBPalette16       Settings::palette1                                  = lavaPalette;
int                 Settings::tid_movingPaletteLinear                   = 100;  



uint8_t             Settings::bpm_sinBeat8                              = 30;
uint8_t             Settings::bpm_sinBeat8PhaseOff                      = 30;
uint8_t             Settings::phaseOffset_sinBeat8PhaseOff              = 30;
uint8_t             Settings::bpm_sinBeat8TimeOff                       = 30;