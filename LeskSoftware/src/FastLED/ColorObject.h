#ifndef COLOROBJECT_H
#define COLOROBJECT_H

#include <FastLED.h>
#include "color_functions.h"
#include "Palettes.h"

class ColorObject {
    private:
        CRGB color = CRGB::Black;               // Default to Black
        Palette palette = Palette(); // Default empty palette
        bool isColor = true;                    // Track if `color` is active

    public:
        // Constructors for single color or palette
        ColorObject(const CRGB& color) : color(color), isColor(true) {}
        ColorObject(const Palette& palette) : palette(palette), isColor(false) {}
        ColorObject(const uint32_t hexColor) : color(CRGB(hexColor)), isColor(true) {}

        // Type checkers
        bool isColorFunc() const {
            return isColor;
        }

        CRGB getColor() const {
            return color;
        }

        uint32_t getColorU32() const {
            return ColorFunctions::CRGBToUint32(color);
        }

        Palette getPalette() const {
            return palette;
        }

        bool isPalette() const {
            return !isColor;
        }

        // Setters
        void setColor(const CRGB& color) {
            this->color = color;
            this->isColor = true;
        }

        void setHexColor(uint32_t hexColor) {
            this->color = CRGB(hexColor);
            this->isColor = true;
        }

        void setPalette(const Palette& palette) {
            this->palette = palette;
            this->isColor = false;
        }

        void setIsColor() {
            this->isColor = true;
        }

        void setIsNotColor() {
            this->isColor = false;
        }
};

#endif // COLOROBJECT_H
