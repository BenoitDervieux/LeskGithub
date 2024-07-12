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
FunctionMapping function_mappings[] = {
    {"FX_MODE_STATIC", 0},
    {"FX_MODE_RAINBOW", 1},
    {"FX_MODE_GRADIENT_RGB", 2},
    // Add more mappings as needed
};

#define MAPPINGS_SIZE (sizeof(function_mappings) / sizeof(FunctionMapping))

int getFunctionNumber(const char *name) {
    for (size_t i = 0; i < MAPPINGS_SIZE; ++i) {
        if (strcmp(function_mappings[i].name, name) == 0) {
            return function_mappings[i].number;
        }
    }
    return -1; 
}


#endif