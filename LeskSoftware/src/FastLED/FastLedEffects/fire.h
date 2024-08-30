#ifndef FIRE.H
#define FIRE.H

#include <FastLED.h>
using namespace std;

class FireEffect {

    protected:
        int         Size;           // How many pixels the flame is total
        int         Cooling;        // Rate at which the pixels cool off
        int         Sparks;         // How many sparks will be attempted each frame
        int         SparkHeight;    // If created, max height for a spark
        int         Sparking;       // Probability of a spack each attempt
        bool        bReversed;      // If reversed we draw from 0 outwards
        bool        bMirrored;      // If mirrored we split and duplicate the drawing

        byte *heat;

        // When diffusing the fire upwards, these controls how much to blend in from the cells below(ie: downward neighbors)
        // You can tune these coefficients to control how quickly and smoothly the fire spreads

        static const byte BlendSelf = 2;
        static const byte BlendNeighbor1 = 3;
        static const byte BlendNeighbor2 = 2;
        static const byte BlendNeighbor3 = 1;
        static const byte BlendTotal = (BlendSelf + BlendNeighbor1 + BlendNeighbor2 + BlendNeighbor3);

    public:
        FireEffect(int size, int cooling = 80, int sparking = 100, int sparks = 3, int sparkHeight = 4, bool breversed = true, bool bmirrored = true) 
            :   Size(size), 
                Cooling(cooling), 
                Sparks(sparks), 
                SparkHeight(sparkHeight), 
                Sparking(sparking), 
                bReversed(breversed), 
                bMirrored(bmirrored) 
        {
            if (bMirrored) {
                Size = Size / 2;
            }
            heat = new byte[size] { 0 };
        }

        virtual ~FireEffect() {
            delete[] heat;
        }

        virtual void DrawFire() {
            // First cool each cell by a little bit
            for (int i = 0; i < Size; i++) {
                heat[i] = max(0L, heat[i] - random(0, ((Cooling * 10) / Size) + 2));
            }
            // Next drift heat up and diffuse it a little bit
            for (int i = 0; i < Size; i++) {
                heat[i] = (heat[i] * BlendSelf + heat[(i+1) % Size] * BlendNeighbor1 + heat[(i+2) % Size] * BlendNeighbor2 + heat[(i+3) % Size] * BlendNeighbor3) / BlendTotal;
            }
            // Randomly ignite new sparks down in the flame kernel
            for (int i = 0; i < Sparks; i++) {
                if (random(0, 255) < Sparking) {
                    int y = Size - 1 - random(SparkHeight);
                    heat[y] = heat[y] + random(160, 255);
                } 
            }

            // Finally, convert heat to a color
            for (int i = 0; i < Size; i++) {
                CRGB color = HeatColor(heat[i]);
                int j = bReversed ? (Size - 1 - i) : i;
                DrawPixels(j, 1, color);
                if (bMirrored) {
                    DrawPixels(!bReversed ? (2 * Size - 1 - i) : Size + i, 1, color);
                }
            }

        }

        CRGB ColorFraction(CRGB colorIn, float fraction) {
            fraction = min(1.0f, fraction);
            return CRGB(colorIn).fadeToBlackBy(255 * (1.0f - fraction));
        }

        void DrawPixels(float fPos, float count, CRGB color) {
            // Calculate how much the first pixel will hold
            float availFirstPixel = 1.0f - (fPos - (long)(fPos));
            float amtFirstPixel = min(availFirstPixel, count);
            float remaining = min(count, FastLED.size()-fPos);
            int iPos = fPos;

            // Blend (add) in the color of the first partial pixel

            if (remaining > 0.0f)
            {
                FastLED.leds()[iPos++] += ColorFraction(color, amtFirstPixel);
                remaining -= amtFirstPixel;
            }

            // Now draw any full pixels in the middle

            while (remaining > 1.0f)
            {
                FastLED.leds()[iPos++] += color;
                remaining--;
            }
            // Draw tail pixel, up to a single full pixel
            if (remaining > 0.0f)
            {
                FastLED.leds()[iPos] += ColorFraction(color, remaining);
            }
            FastLED.show();
        }

        void SetSize(int size) {this->Size = size;}
        int GetSize() {return this->Size;}
        void SetCooling(int cooling) {this->Cooling = cooling;}
        int GetCooling() {return this->Cooling;}
        void SetSparks(int sparks) {this->Sparks = sparks;}
        int GetSparks() {return this->Sparks;}
        void SetSparking(int sparking) {this->Sparking = sparking;}
        int GetSparking() {return this->Sparking;}
        void SetSparkHeight(int sparkHeight) {this->SparkHeight = sparkHeight;}
        int GetSparkHeight() {return this->SparkHeight;}
        void SetReversed(bool breversed) {this->bReversed = breversed;}
        bool GetReversed() {return this->bReversed;}
        void SetMirrored(bool bmirrored) {this->bMirrored = bmirrored;}
        bool GetMirrored() {return this->bMirrored;}

};


#endif