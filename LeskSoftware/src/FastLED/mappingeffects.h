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

    {"FX_MODE_FILL", 1},
    {"FX_MODE_BLINK", 2},
    {"FX_MODE_RAINBOW_STATIC", 3},
    {"FX_MODE_FILL_GRADIENT_TWO_COLORS", 4},
    {"FX_MODE_FILL_GRADIENT_THREE_COLORS", 5},
    {"FX_MODE_BACK_AND_FORTH_NO_SMOOTH_ONE_DOT", 6},
    {"FX_MODE_BACK_AND_FORTH_NO_SMOOTH_LENGHTED_DOT", 7},
    {"FX_MODE_HUE_FADING", 8},
    {"FX_MODE_HUE_WHITE_WAVE", 9},
    {"FX_MODE_DISPLAY_PALETTE_LINEAR", 10},
    {"FX_MODE_MOVING_PALETTE_LINEAR", 11},
    {"FX_MODE_SPOTLIGHTING_PALETTE", 12},
    {"FX_MODE_SIN_BEAT_8", 13},
    {"FX_MODE_SIN_BEAT_8_PHASE_OFF", 14},
    {"FX_MODE_SIN_BEAT_8_TIME_OFF", 15},
    {"FX_MODE_TWO_SIN_BEAT_8", 16},
    {"FX_MODE_THREE_SIN_BEAT_8", 17},
    {"FX_MODE_BRIGHTNESS_SIN_BEAT_PALETTE", 18},
    {"FX_MODE_FUNKY_RAINBOW_SIN_BEAT_8", 19},
    {"FX_MODE_FUNKY_RANGES_SIN_BEAT_8", 20},
    {"FX_MODE_FUNKY_RAINBOW_SIN_BEAT_8_TWO", 21},
    {"FX_MODE_FUNKY_RANGE_SIN_BEAT_8_TWO", 22},
    {"FX_MODE_MOVING_FUNKY_PALETTE", 23},
    {"FX_MODE_RAINBOW_WAVE", 24},
    {"FX_MODE_CHOOSEN_WAVE", 25},
    {"FX_MODE_FIRST_NOISE_RAINBOW", 26},
    {"FX_MODE_FIRST_NOISE_COLORS", 27},
    {"FX_MODE_NOISE_PALETTE", 28},
    {"FX_MODE_RUN_FIRE", 29},
    {"FX_MODE_SECOND_NOISE", 30},
    {"FX_MODE_FILL_NOISE_16", 31},
    {"FX_MODE_RAINDBOW_DAVE", 32},
    {"FX_MODE_MARQUEE_DAVE", 33},
    {"FX_MODE_TWINKLE_OLD", 34},
    {"FX_MODE_TWINKLE", 35},
    {"FX_MODE_COMET", 36},
    {"FX_MODE_COMET_ONCE", 37},
    {"FX_MODE_BOUNCE", 38},
    {"FX_MODE_FIRE", 39},
    {"FX_MODE_STORM", 40},
    {"FX_MODE_STORM_COLORED", 41},
    {"FX_MODE_STORM_PALETTE", 42},
    {"FX_MODE_LIGHTING", 43},
    {"FX_MODE_LINGHTING_COLORED", 44},
    {"FX_MODE_LIGHTING_PALETTE", 45},
    {"FX_MODE_BEAT_8_TAIL", 46},
    {"FX_MODE_BLEND_INTO_RAINBOW", 47},
    {"FX_MODE_BREATHE_V2", 48},
    {"FX_MODECHASE_TARGET_TALES_VAR_A", 49},
    {"FX_MODE_CHASE_TARGET_TALES_VAR_B", 50},
    {"FX_MODE_CHASE_TARGET_TALES_VAR_C", 51},
    {"FX_MODE_EVERY_N_TIMER_VARIABLES", 52},
    {"FX_MODE_FILL_UP_STRING", 53},
    {"FX_MODE_HEART_BEAT_2", 54},
    {"FX_MODE_HEART_BEAT_3", 55},
    {"FX_MODE_HEART_PULSE_BLOOD_FLOWING", 56},
    {"FX_MODE_LIGHT_HOUSE_BEACON_V2", 57},
    {"FX_MODE_MATCHING_GLITTER_1", 58},
    {"FX_MODE_MATCHING_GLITTER_2", 59},
    {"FX_MODE_MATCHING_GLITTER_3", 60},
    {"FX_MODE_MATCHING_GLITTER_4", 61},
    {"FX_MODE_MIRROR_FADE_ENDS", 62},
    {"FX_MODE_FIRE_2012", 63},
    {"FX_MODE_FIRE_2012_HALF_STRIPE", 64},
    {"FX_MODE_MOVING_COLORED_BAR", 65},
    {"FX_MODE_REPEATING_PATTERNS", 66},
    {"FX_MODE_SAVED_PIXELS", 67},
    {"FX_MODE_SIN_COS_LINEAR", 68},
    {"FX_MODE_SPARKLES", 69},


    {"Fill", 1},
    {"Blink", 2},
    {"Rainbow Static", 3},
    {"Fill Gradient Two Colors", 4},
    {"Fill Gradient Three Colors", 5},
    {"Back and Forth No Smooth One Dot", 6},
    {"Back and Forth No Smooth Lengthed Dot", 7},
    {"Hue Fading", 8},
    {"Hue White Wave", 9},
    {"Display Palette Linear", 10},
    {"Moving Palette Linear", 11},
    {"Spotlighting Palette", 12},
    {"Sin Beat 8", 13},
    {"Sin Beat 8 Phase Off", 14},
    {"Sin Beat 8 Time Off", 15},
    {"Two Sin Beat 8", 16},
    {"Three Sin Beat 8", 17},
    {"Brightness Sin Beat 8 Palette", 18},
    {"Funky Rainbow Sin Beat 8", 19},
    {"Funky Range Sin Beat 8", 20},
    {"Funky Rainbow Sin Beat 8 Two", 21},
    {"Funky Range Sin Beat 8 Two", 22},
    {"Moving Funky Palette", 23},
    {"Rainbow Wave", 24},
    {"Choosen Wave", 25},
    {"First Noise Rainbow", 26},
    {"First Noise Color", 27},
    {"Noise Palette", 28},
    {"Run Fire", 29},
    {"Second Noise", 30},
    {"Fill Noise 16", 31},
    {"Rainbow Dave", 32},
    {"Marquee Dave", 33},
    {"Twinkle Old", 34},
    {"Twinkle", 35},
    {"Comet", 36},
    {"Comet Once", 37},
    {"Bounce", 38},
    {"Fire", 39},
    {"Storm", 40},
    {"Storm Colored", 41},
    {"Storm Palette", 42},
    {"Lighting", 43},
    {"Lighting Colored", 44},
    {"Lighting Palette", 45},
    {"Beat 8 Tail", 46},
    {"Blend Into Rainbow", 47},
    {"Breathe V2", 48},
    {"Chase Target Tales Var A", 49},
    {"Chase Target Tales Var B", 50},
    {"Chase Target Tales Var C", 51},
    {"Every N Timer Variables", 52},
    {"Fill Up Strip", 53},
    {"Heart Beat 2", 54},
    {"Heart Beat 3", 55},
    {"Heart Pulse Blood Flowing", 56},
    {"Lighthouse Beacon V2", 57},
    {"Matching Glitter 1", 58},
    {"Matching Glitter 2", 59},
    {"Matching Glitter 3", 60},
    {"Matching Glitter 4", 61},
    {"Mirror Fade Ends", 62},
    {"Fire 2012", 63},
    {"Fire 2012 Half Strip", 64},
    {"Moving Colored Bar", 65},
    {"Repeating Patterns", 66},
    {"Saved Pixels", 67},
    {"Sin Cos Linear", 68},
    {"Sparkles", 69}
    // Add more mappings as needed
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