#include "Settings.h"

CRGB        Settings::color                                     = CRGB::Red;
int         Settings::effect                                    = 1;
int         Settings::speed                                     = 30;
CRGB        Settings::color2                                    = CRGB::Red;
CRGB        Settings::color3                                    = CRGB::Red;
uint8_t     Settings::bpm_sinBeat8                              = 30;
uint8_t     Settings::bpm_sinBeat8PhaseOff                      = 30;
uint8_t     Settings::phaseOffset_sinBeat8PhaseOff              = 30;
uint8_t     Settings::bpm_sinBeat8TimeOff                       = 30;
int         Settings::tid_blink                                 = 100;
int         Settings::tid_backAndForthNoSmoothOneDot            = 30;
int         Settings::tid_backAndForthNoSmoothLengthedDot       = 30;
int         Settings::length_backAndForthNoSmoothLengthedDot    = 3;