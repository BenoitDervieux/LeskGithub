#ifndef MAPPINGSETTINGS_H
#define MAPPINGSETTINGS_H

#include <stdio.h>
#include <string.h>
#include "defineeffectsettings.h"

// Define the structure for the mapping
typedef struct {
    const char *name;
    int number;
} SettingsMapping;

// Initialize the array with mappings
static SettingsMapping settings_mappings[] = {
    {"SETTING_SPEED", 1},
    {"SETTING_INTENSITY", 2},
    {"SETTING_PAUSE", 3},
    {"SETTING_ONECOLOR", 4},
    {"SETTING_TWOCOLOR", 5},
    {"SETTING_THREECOLOR", 6},
    {"EFF", 1},
    // Add more mappings as needed
};

#define MAPPINGS_SIZE (sizeof(settings_mappings) / sizeof(SettingsMapping))

static int getSettingsNumber(const char *name) {
    for (size_t i = 0; i < MAPPINGS_SIZE; ++i) {
        if (strcmp(settings_mappings[i].name, name) == 0) {
            return settings_mappings[i].number;
        }
    }
    return -1; 
}


#endif