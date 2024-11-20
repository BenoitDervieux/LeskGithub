#ifndef SETTINGTEST_H
#define SETTINGTEST_H

#include <FastLED.h>
#include "ColorObject.h"
#include "Palettes.h"
//
//
// NEED TO CONTINUE THE IMPLEMENTATION ZEUBI
class Settings {
    public: 
        static ColorObject      color1;
        static ColorObject      color2;
        static ColorObject      color3;
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
        static Palette          palette1;

        static int              var_0to5_1;
        static int              var_0to10_1;
        static int              var_0to10_2;
        static int              var_0to10_3;
        static int              var_0to128_1;
        static int              var_0to128_2;
        static int              var_0to140_1;
        static int              var_0to140_2;
        static int              var_0to200_1;
        static int              var_0to255_1;
        static int              var_0to255_2;
        static int              var_0to500_1;
        static int              var_0to500_2;
        static int              var_0to1000_1;
        static int              var_0to1000_2;
        static int              var_0to3000_1;
        
        static float            pulseSp_breathe;
        static bool             mirror_bounce;
        static bool             breversed_fire;
        static bool             rainbow_heartBeat3;
        static bool             matchingGlitter_second;
        static bool             matchingGlitter_third;
        static bool             more_matchingGlitter4;



    public:
        //color 1
        static ColorObject getColor() {return color1;};
        static void setColor(CRGB newColor) {color1.setColor(newColor);};
        static void setColorU32(uint32_t newColor) {color1.setHexColor(newColor);};
        //color 1
        static ColorObject getColor2() {return color2;};
        static void setColor2(CRGB newColor) {color2.setColor(newColor);};
        static void setColor2U32(uint32_t newColor) {color2.setHexColor(newColor);};
        //color 1
        static ColorObject getColor3() {return color3;};
        static void setColor3(CRGB newColor) {color3.setColor(newColor); };
        static void setColor3U32(uint32_t newColor) {color3.setHexColor(newColor);};
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
        // Palette 1
        static Palette getPalette1() {return palette1;};
        static void setPalette1(String newPalette1) {palette1.setPalette(newPalette1);};
        // mirror_bounce
        static bool getMirrorBounce() {return mirror_bounce;};
        static void setMirrorBounce(bool newMirrorBounce) {mirror_bounce = newMirrorBounce;};
        // breversed_fire;
        static bool getReversedFire() {return breversed_fire;};
        static void setReversedFire(bool newReversedFire) {breversed_fire = newReversedFire;};
        // pulseSp_breathe
        static float getPulseSpBreathe() {return pulseSp_breathe;};
        static void setPulseSpBreathe(int newPulseSpBreathe) {pulseSp_breathe = (float)newPulseSpBreathe;};
        // rainbow_heartBeat3
        static int getRainbowHeartBeat3() {return rainbow_heartBeat3;};
        static void setRainbowHeartBeat3(int newRainbowHeartBeat3) {rainbow_heartBeat3 = newRainbowHeartBeat3;};
        // matchingGlitter_second
        static bool getMatchingGlitterSecond() {return matchingGlitter_second;};
        static void setMatchingGlitterSecond(bool newMatchingGlitterSecond) {matchingGlitter_second = newMatchingGlitterSecond;}
        // matchingGlitter_third
        static bool getMatchingGlitterThird() {return matchingGlitter_third;};
        static void setMatchingGlitterThird(bool newMatchingGlitterThird) {matchingGlitter_third = newMatchingGlitterThird;}
        // more_matchingGlitter4
        static bool getMoreMatchingGlitter4() {return more_matchingGlitter4;};
        static void setMoreMatchingGlitter4(bool newMoreMatchingGlitter4) {more_matchingGlitter4 = newMoreMatchingGlitter4;}
        
        
        //  var_0to5_1;
        static int getVar0to5_1() {return var_0to5_1;};
        static void setVar0to5_1(int newVar0to5_1) {var_0to5_1 = newVar0to5_1;};
        //  var_0to10_1;
        static int getVar0to10_1() {return var_0to10_1;};
        static void setVar0to10_1(int newVar0to10_1) {var_0to10_1 = newVar0to10_1;};
        //  var_0to10_2;
        static int getVar0to10_2() {return var_0to10_2;};
        static void setVar0to10_2(int newVar0to10_2) {var_0to10_2 = newVar0to10_2;};
        //  var_0to10_3;
        static int getVar0to10_3() {return var_0to10_3;};
        static void setVar0to10_3(int newVar0to10_3) {var_0to10_3 = newVar0to10_3;};
        //  var_0to128_1;
        static int getVar0to128_1() {return var_0to128_1;};
        static void setVar0to128_1(int newVar0to128_1) {var_0to128_1 = newVar0to128_1;}
        //  var_0to128_2;
        static int getVar0to128_2() {return var_0to128_2;};
        static void setVar0to128_2(int newVar0to128_2) {var_0to128_2 = newVar0to128_2;}
        //  var_0to140_1;
        static int getVar0to140_1() {return var_0to140_1;};
        static void setVar0to140_1(int newVar0to140_1) {var_0to140_1 = newVar0to140_1;}
        //  var_0to140_2;
        static int getVar0to140_2() {return var_0to140_2;};
        static void setVar0to140_2(int newVar0to140_2) {var_0to140_2 = newVar0to140_2;}
        //  var_0to200_1;
        static int getVar0to200_1() {return var_0to200_1;};
        static void setVar0to200_1(int newVar0to200_1) {var_0to200_1 = newVar0to200_1;}
        //  var_0to255_1;
        static int getVar0to255_1() {return var_0to255_1;};
        static void setVar0to255_1(int newVar0to255_1) {var_0to255_1 = newVar0to255_1;}
        // var_0to255_2;
        static int getVar0to255_2() {return var_0to255_2;};
        static void setVar0to255_2(int newVar0to255_2) {var_0to255_2 = newVar0to255_2;}
        //  var_0to500_1;
        static int getVar0to500_1() {return var_0to500_1;};
        static void setVar0to500_1(int newVar0to500_1) {var_0to500_1 = newVar0to500_1;}
        //  var_0to500_2;
        static int getVar0to500_2() {return var_0to500_2;};
        static void setVar0to500_2(int newVar0to500_2) {var_0to500_2 = newVar0to500_2;}
        //  var_0to1000_1;
        static int getVar0to1000_1() {return var_0to1000_1;};
        static void setVar0to1000_1(int newVar0to1000_1) {var_0to1000_1 = newVar0to1000_1;}
        //  var_0to1000_2;
        static int getVar0to1000_2() {return var_0to1000_2;};
        static void setVar0to1000_2(int newVar0to1000_2) {var_0to1000_2 = newVar0to1000_2;}
        //  var_0to3000_1;
        static int getVar0to3000_1() {return var_0to3000_1;};
        static void setVar0to3000_1(int newVar0to3000_1) {var_0to3000_1 = newVar0to3000_1;}

};




#endif