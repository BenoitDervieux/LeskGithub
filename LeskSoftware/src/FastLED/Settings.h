#ifndef SETTINGTEST_H
#define SETTINGTEST_H

#include <FastLED.h>
// #include <Palettes.h>
//
//
// NEED TO CONTINUE THE IMPLEMENTATION ZEUBI
class Settings {
    public: 
        static CRGB             color;
        static int              effect;
        static int              speed;
        static uint8_t          r;
        static uint8_t          g;
        static uint8_t          b;
        static uint8_t          r2;
        static uint8_t          g2;
        static uint8_t          b2;
        static uint8_t          r3;
        static uint8_t          g3;
        static uint8_t          b3;
        static CRGB             color2;
        static CRGB             color3;
        static int              tid_blink;
        static int              tid_backAndForthNoSmoothOneDot;
        static int              tid_backAndForthNoSmoothLengthedDot;
        static int              length_backAndForthNoSmoothLengthedDot;
        static int              tid_hueFading;
        static uint8_t          hueInsert_hueWhiteWave;
        static int              tid_hueWhiteWave;
        static CRGBPalette16    palette1;
        static int              tid_movingPaletteLinear;
        static int              tid_spotlightingPalette;
        static int              fade_spotlightingPalette;
        static int              fade_sinBeat8;
        static uint8_t          bpm_sinBeat8;
        static uint8_t          sinBeat8PhaseOff_phaseOffset;
        static int              tid_sinBeat8TimeOff;
        static int              tid_brightnessSinBeat8Palette;
    public:
        //color
        static CRGB getColor() {return color;};
        static void setColor(CRGB newColor) {color = newColor;};
        //effect
        static int getEffect() {return effect;};
        static void setEffect(int newEffect) {effect = newEffect;};
        //speed
        static int getSpeed() {return speed;};
        static void setSpeed(int newSpeed) {speed = newSpeed;};
        // r
        static uint8_t getR() {return r;};
        static void setR(uint8_t newR) {r = newR;};
        // g
        static uint8_t getG() {return g;};
        static void setG(uint8_t newG) {g = newG;};
        // b
        static uint8_t getB() {return b;};
        static void setB(uint8_t newB) {b = newB;};
        // r2
        static uint8_t getR2() {return r2;};
        static void setR2(uint8_t newR) {r2 = newR;};
        // g2
        static uint8_t getG2() {return g2;};
        static void setG2(uint8_t newG) {g2 = newG;};
        // b2
        static uint8_t getB2() {return b2;};
        static void setB2(uint8_t newB) {b2 = newB;};
        // r3
        static uint8_t getR3() {return r3;};
        static void setR3(uint8_t newR) {r3 = newR;};
        // g3
        static uint8_t getG3() {return g3;};
        static void setG3(uint8_t newG) {g3 = newG;};
        // b3
        static uint8_t getB3() {return b3;};
        static void setB3(uint8_t newB) {b3 = newB;};
        //color2
        static CRGB getColor2() {return color2;};
        static void setColor2(CRGB newColor2) {color2 = newColor2;};
        //color3
        static CRGB getColor3() {return color3;};
        static void setColor3(CRGB newColor3) {color3 = newColor3;};
        //tid_blink
        static int getTidBlink() {return tid_blink;};
        static void setTidBlink(int newTidBlink) {tid_blink = newTidBlink;};
        //tid_backAndForthNoSmoothOneDot
        static int getTidBackAndForthNoSmoothOneDot() {return tid_backAndForthNoSmoothOneDot;};
        static void setTidBackAndForthNoSmoothOneDot(int newTidBackAndForthNoSmoothOneDot) {tid_backAndForthNoSmoothOneDot = newTidBackAndForthNoSmoothOneDot;};
        //tid_backAndForthNoSmoothLengthedDot
        static int getTidBackAndForthNoSmoothLengthedDot() {return tid_backAndForthNoSmoothLengthedDot;};
        static void setTidBackAndForthNoSmoothLengthedDot(int newTidBackAndForthNoSmoothLengthedDot) {tid_backAndForthNoSmoothLengthedDot = newTidBackAndForthNoSmoothLengthedDot;};
        //length_backAndForthNoSmoothLengthedDot
        static int getLengthBackAndForthNoSmoothLengthedDot() {return length_backAndForthNoSmoothLengthedDot;};
        static void setLengthBackAndForthNoSmoothLengthedDot(int newLengthBackAndForthNoSmoothLengthedDot) {length_backAndForthNoSmoothLengthedDot = newLengthBackAndForthNoSmoothLengthedDot;};
        //tid_hueFading
        static int getTidHueFading() {return tid_hueFading;};
        static void setTidHueFading(int newTidHueFading) {tid_hueFading = newTidHueFading;};
        //hueInsert_hueWhiteWave;
        static uint8_t getHueInsert_hueWhiteWave() {return hueInsert_hueWhiteWave;};
        static void setHueInsert_hueWhiteWave(uint8_t newHueInsert_hueWhiteWave) {hueInsert_hueWhiteWave = newHueInsert_hueWhiteWave;};
        //tid_hueWhiteWave;
        static int getTidHueWhiteWave() {return tid_hueWhiteWave;};
        static void setTidHueWhiteWave(int newTidHueWhiteWave) {tid_hueWhiteWave = newTidHueWhiteWave;};
        // Palette 1
        static CRGBPalette16 getPalette1() {return palette1;};
        static void setPalette1(CRGBPalette16 newPalette1) {palette1 = newPalette1;};
        // tid_movingPaletteLinear
        static int getTidMovingPaletteLinear() {return tid_movingPaletteLinear;};
        static void setTidMovingPaletteLinear(int newTidMovingPaletteLinear) {tid_movingPaletteLinear = newTidMovingPaletteLinear;};
        // tid_spotlightingPalette;
        static int getTidSpotlightingPalette() {return tid_spotlightingPalette;};
        static void setTidSpotlightingPalette(int newTidSpotlightingPalette) {tid_spotlightingPalette = newTidSpotlightingPalette;};
        // fade_spotlightingPalette;
        static int getFade_spotlightingPalette() {return fade_spotlightingPalette;};
        static void setFade_spotlightingPalette(int newFade_spotlightingPalette) {fade_spotlightingPalette = newFade_spotlightingPalette;};
        // fade_sinBeat8;
        static int getFade_sinBeat8() {return fade_sinBeat8;};
        static void setFade_sinBeat8(int newFade_sinBeat8) {fade_sinBeat8 = newFade_sinBeat8;};
        // bpm_sinBeat8
        static uint8_t getBpmSinBeat8() {return bpm_sinBeat8;};
        static void setBpmSinBeat8(uint8_t newBpmSinBeat8) {bpm_sinBeat8 = newBpmSinBeat8;};
        // sinBeat8PhaseOff_phaseOffset;
        static uint8_t getSinBeat8PhaseOff_phaseOffset() {return sinBeat8PhaseOff_phaseOffset;};
        static void setSinBeat8PhaseOff_phaseOffset(uint8_t newSinBeat8PhaseOff_phaseOffset) {sinBeat8PhaseOff_phaseOffset = newSinBeat8PhaseOff_phaseOffset;};
        // tid_sinBeat8TimeOff
        static int getTidSinBeat8TimeOff() {return tid_sinBeat8TimeOff;};
        static void setTidSinBeat8TimeOff(int newTidSinBeat8TimeOff) {tid_sinBeat8TimeOff = newTidSinBeat8TimeOff;};
        // tid_brightnessSinBeat8Palette
        static int getTidBrightnessSinBeat8Palette() {return tid_brightnessSinBeat8Palette;};
        static void setTidBrightnessSinBeat8Palette(int newTidBrightnessSinBeat8Palette) {tid_brightnessSinBeat8Palette = newTidBrightnessSinBeat8Palette;};


};

#endif