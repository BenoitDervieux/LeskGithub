#ifndef SETTINGTEST_H
#define SETTINGTEST_H

#include <FastLED.h>
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
        static CRGB             color2;
        static CRGB             color3;
        static uint8_t          bpm_sinBeat8;
        static uint8_t          bpm_sinBeat8PhaseOff;
        static uint8_t          phaseOffset_sinBeat8PhaseOff;
        static uint8_t          bpm_sinBeat8TimeOff;
        static int              tid_blink;
        static int              tid_backAndForthNoSmoothOneDot;
        static int              tid_backAndForthNoSmoothLengthedDot;
        static int              length_backAndForthNoSmoothLengthedDot;
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
        //color2
        static CRGB getColor2() {return color2;};
        static void setColor2(CRGB newColor2) {color2 = newColor2;};
        //color3
        static CRGB getColor3() {return color3;};
        static void setColor3(CRGB newColor3) {color3 = newColor3;};
        //bpm_sinBeat8
        static uint8_t getBpmSinBeat8() {return bpm_sinBeat8;};
        static void setBpmSinBeat8(uint8_t newBpmSinBeat8) {bpm_sinBeat8 = newBpmSinBeat8;};
        //bpm_sinBeat8PhaseOff
        static uint8_t getBpmSinBeat8PhaseOff() {return bpm_sinBeat8PhaseOff;};
        static void setBpmSinBeat8PhaseOff(uint8_t newBpmSinBeat8PhaseOff) {bpm_sinBeat8PhaseOff = newBpmSinBeat8PhaseOff;};
        //phaseOffset_sinBeat8PhaseOff
        static uint8_t getPhaseOffset_sinBeat8PhaseOff() {return phaseOffset_sinBeat8PhaseOff;};
        static void setPhaseOffset_sinBeat8PhaseOff(uint8_t newPhaseOffset_sinBeat8PhaseOff) {phaseOffset_sinBeat8PhaseOff = newPhaseOffset_sinBeat8PhaseOff;};
        //bpm_sinBeat8TimeOff
        static uint8_t getBpmSinBeat8TimeOff() {return bpm_sinBeat8TimeOff;};
        static void setBpmSinBeat8TimeOff(uint8_t newBpmSinBeat8TimeOff) {bpm_sinBeat8TimeOff = newBpmSinBeat8TimeOff;};
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
};

#endif