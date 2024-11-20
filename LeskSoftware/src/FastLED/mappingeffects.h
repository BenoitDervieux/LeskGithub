#ifndef LISTEFFECTSMAPPING_H
#define LISTEFFECTSMAPPING_H

#include <stdio.h>
#include <string.h>
#include "defineeffects.h"

// Define the structure for the mapping
typedef struct {
    const char *name;
    int number;
} FunctionMapping;

// Initialize the array with mappings
static FunctionMapping function_mappings[] = {

    {"FX_MODE_FILL",                                    1},
    {"FX_MODE_BLINK",                                   2},
    {"FX_MODE_FILL_GRADIENT_TWO_COLORS",                3},
    {"FX_MODE_FILL_GRADIENT_THREE_COLORS",              4},
    {"FX_MODE_BACK_AND_FORTH_NO_SMOOTH_ONE_DOT",        5},
    {"FX_MODE_BACK_AND_FORTH_NO_SMOOTH_LENGHTED_DOT",   6},
    {"FX_MODE_HUE_FADING",                              7},
    {"FX_MODE_HUE_WHITE_WAVE",                          8},
    {"FX_MODE_MOVING_PALETTE_LINEAR",                   9},
    {"FX_MODE_SPOTLIGHTING_PALETTE",                    10},
    {"FX_MODE_SIN_BEAT_8",                              11},
    {"FX_MODE_SIN_BEAT_8_PHASE_OFF",                    12},
    {"FX_MODE_TWO_SIN_BEAT_8",                          13},
    {"FX_MODE_THREE_SIN_BEAT_8",                        14},
    {"FX_MODE_BRIGHTNESS_SIN_BEAT_PALETTE",             15},
    {"FX_MODE_FUNKY_RAINBOW_SIN_BEAT_8",                16},
    {"FX_MODE_FUNKY_RANGES_SIN_BEAT_8",                 17},
    {"FX_MODE_FUNKY_RAINBOW_SIN_BEAT_8_TWO",            18},
    {"FX_MODE_FUNKY_RANGE_SIN_BEAT_8_TWO",              19},
    {"FX_MODE_MOVING_FUNKY_PALETTE",                    20},
    {"FX_MODE_RAINBOW_WAVE",                            21},
    {"FX_MODE_CHOOSEN_WAVE",                            22},
    {"FX_MODE_FIRST_NOISE_RAINBOW",                     23},
    {"FX_MODE_FIRST_NOISE_COLORS",                      24},
    {"FX_MODE_NOISE_PALETTE",                           25},
    {"FX_MODE_RUN_FIRE",                                26},
    {"FX_MODE_SECOND_NOISE",                            27},
    {"FX_MODE_FILL_NOISE_16",                           28},
    {"FX_MODE_RAINDBOW_DAVE",                           29},
    {"FX_MODE_MARQUEE_DAVE",                            30},
    {"FX_MODE_TWINKLE_OLD",                             31},
    {"FX_MODE_TWINKLE",                                 32},
    {"FX_MODE_COMET",                                   33},
    {"FX_MODE_COMET_ONCE",                              34},
    {"FX_MODE_BOUNCE",                                  35},
    {"FX_MODE_STORM",                                   36},
    {"FX_MODE_LIGHTING",                                37},
    {"FX_MODE_LINGHTING_COLORED",                       38},
    {"FX_MODE_BEAT_8_TAIL",                             39},
    {"FX_MODE_BLEND_INTO_RAINBOW",                      40},
    {"FX_MODE_BREATHE_V2",                              41},
    {"FX_MODECHASE_TARGET_TALES_VAR_A",                 42},
    {"FX_MODE_CHASE_TARGET_TALES_VAR_B",                43},
    {"FX_MODE_CHASE_TARGET_TALES_VAR_C",                44},
    {"FX_MODE_EVERY_N_TIMER_VARIABLES",                 45},
    {"FX_MODE_FILL_UP_STRING",                          46},
    {"FX_MODE_HEART_BEAT_3",                            47},
    {"FX_MODE_HEART_PULSE_BLOOD_FLOWING",               48},
    {"FX_MODE_LIGHT_HOUSE_BEACON_V2",                   49},
    {"FX_MODE_MATCHING_GLITTER_1",                      50},
    {"FX_MODE_FIRE_2012",                               51},
    {"FX_MODE_FIRE_2012_HALF_STRIPE",                   52},
    {"FX_MODE_MOVING_COLORED_BAR",                      53},
    {"FX_MODE_REPEATING_PATTERNS",                      54},
    {"FX_MODE_SAVED_PIXELS",                            55},

    {"Fill",                                            1},
    {"Blink",                                           2},
    {"Fill Gradient 2 Colors",                          3},
    {"Fill Gradient 3 Colors",                          4},
    {"Back and Forth No Smooth One Dot",                5},
    {"Back and Forth No Smooth Lengthed Dot",           6},
    {"Hue Fading",                                      7},
    {"Hue White Wave",                                  8},
    {"Moving Palette Linear",                           9},
    {"Spotlighting Palette",                            10},
    {"Sin Beat 8",                                      11},
    {"Sin Beat 8 Phase Off",                            12},
    {"Two Sin Beat 8",                                  13},
    {"Three Sin Beat 8",                                14},
    {"Brightness Sin Beat 8 Palette",                   15},
    {"Funky Rainbow Sin Beat 8",                        16},
    {"Funky Range Sin Beat 8",                          17},
    {"Funky Rainbow Sin Beat 8 Two",                    18},
    {"Funky Range Sin Beat 8 Two",                      19},
    {"Moving Funky Palette",                            20},
    {"Rainbow Wave",                                    21},
    {"Choosen Wave",                                    22},
    {"First Noise Rainbow",                             23},
    {"First Noise Color",                               24},
    {"Noise Palette",                                   25},
    {"Run Fire",                                        26},
    {"Second Noise",                                    27},
    {"Fill Noise 16",                                   28},
    {"Rainbow Dave",                                    29},
    {"Marquee Dave",                                    30},
    {"Twinkle Old",                                     31},
    {"Twinkle",                                         32},
    {"Comet",                                           33},
    {"Comet Once",                                      34},
    {"Bounce",                                          35},
    {"Storm",                                           36},
    {"Lighting",                                        37},
    {"Lighting Colored",                                38},
    {"Beat 8 Tail",                                     39},
    {"Blend Into Rainbow",                              40},
    {"Breathe V2",                                      41},
    {"Chase Target Tales Var A",                        42},
    {"Chase Target Tales Var B",                        43},
    {"Chase Target Tales Var C",                        44},
    {"Every N Timer Variables",                         45},
    {"Fill Up Strip",                                   46},
    {"Heart Beat 3",                                    47},
    {"Heart Pulse Blood Flowing",                       48},
    {"Lighthouse Beacon V2",                            49},
    {"Matching Glitter 1",                              50},
    {"Fire 2012",                                       51},
    {"Fire 2012 Half Strip",                            52},
    {"Moving Colored Bar",                              53},
    {"Repeating Patterns",                              54},
    {"Saved Pixels",                                    55},

};

#define MAPPINGS_SIZE (sizeof(function_mappings) / sizeof(FunctionMapping))

static int getFunctionNumber(const char *name) {
    for (size_t i = 0; i < MAPPINGS_SIZE; ++i) {
        if (strcmp(function_mappings[i].name, name) == 0) {
            return function_mappings[i].number;
        }
    }
    return -1; 
}


#endif