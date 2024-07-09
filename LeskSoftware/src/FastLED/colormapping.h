#ifndef COLORMAPPING_H
#define COLORMAPPING_H

#include <stdio.h>
#include <string.h>
#include <iostream>

// Define the structure for the mapping
typedef struct {
    const char *name;
    uint32_t color;
} ColorMapping;

// Initialize the array with mappings
// [TODO] --> continue the mapping using this site : https://encycolorpedia.fr/html
ColorMapping color_mappings[] = {
    {"RED", 0xFF0000},
    {"BLUE", 0x0000FF},
    {"GREEN", 0x00FF00},
    {"CHARTREUSE", 0x7fff00},
    {"PINK", 0xFF69B4},
    {"PURPLE", 0xFF00FF},
    // Add more mappings as needed
};

#define COLOR_MAPPINGS_SIZE (sizeof(color_mappings) / sizeof(ColorMapping))

uint32_t getColorNumber(const char *name) {
    for (size_t i = 0; i < COLOR_MAPPINGS_SIZE; ++i) {
        if (strcmp(color_mappings[i].name, name) == 0) {
            return color_mappings[i].color;
        }
    }
    return -1; 
}


#endif