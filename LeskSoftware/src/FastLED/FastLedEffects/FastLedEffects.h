#define FASTLED_INTERRUPT_RETRY_COUNT 5
#define FASTLED_ALLOW_INTERRUPTS 0
#include <FastLED.h>
#include <vector>
#include <sys/time.h>
#include "bounce.h"
#include "fire.h"
#include <iostream>

class FastLedEffects {
    public:
        /*   1 */ static void fill(int r, int g, int b, CRGB leds[]);
        /*   2 */ static void blink(int r, int g, int b, CRGB leds[], int tid_blink);
        /*   3 */ static void rainbowStatic(CRGB leds[]);
        /*   4 */ static void fillGradientTwoColors(int r, int g, int b, int r2, int g2, int b2, CRGB leds[]);
        /*   5 */ static void fillGradientThreeColors(int r, int g, int b, int r2, int g2, int b2, int r3, int g3, int b3, CRGB leds[]);
        /*   6 */ static void backAndForthNoSmoothOneDot(int r, int g, int b, CRGB leds[], int tid_backAndForthNoSmoothOneDot);
        /*   7 */ static void backAndForthNoSmoothLengthedDot(int r, int g, int b, CRGB leds[], int tid_backAndForthNoSmoothLengthedDot, int length_backAndForthNoSmoothLengthedDot);
        /*   8 */ static void hueFading(int tid_hueFading, CRGB leds[]);
        /*   9 */ static void hueWhiteWave(uint8_t hueInsert_hueWhiteWave, int tid_hueWhiteWave, CRGB leds[]);
        /*  10 */ static void displayPaletteLinear(CRGBPalette16 palette, CRGB leds[]);
        /*  11 */ static void movingPaletteLinear(CRGBPalette16 palette, int tid_movingPaletteLinear, CRGB leds[]);
        /*  12 */ static void spotlightingPalette(CRGBPalette16 palette, int tid_spotlightingPalette, int fade_spotlightingPalette, CRGB leds[]);
        /*  13 */ static void sinBeat8(int r, int g, int b, int fade_sinBeat8, uint8_t bpm_sinBeat8, CRGB leds[]);
        /*  14 */ static void sinBeat8PhaseOff(int r, int g, int b, int fade_sinBeat8PhaseOff, uint8_t bpm_sinBeat8PhaseOff, uint8_t phaseOffset_sinBeat8PhaseOff, CRGB leds[]);
        /*  15 */ static void sinBeat8TimeOff(int r, int g, int b, int fade_sinBeat8TimeOff, uint8_t bpm_sinBeat8TimeOff, int time_sinBeat8TimeOff, CRGB leds[]);
        /*  16 */ static void twoSinBeat8(int r, int g, int b, int r2, int g2, int b2, int fade_twoSinBeat8, uint8_t bpm_twoSinBeat8, CRGB leds[]);
        /*  17 */ static void threeSinBeat8(int r, int g, int b, int r2, int g2, int b2, int r3, int g3, int b3, int fade_threeSinBeat8, uint8_t bpm_threeSinBeat8, CRGB leds[]);
        /*  18 */ static void brightnessSinBeat8Palette(CRGBPalette16 palette, uint8_t bpm_brightnessSinBeat8Palette, int tid_brightnessSinBeat8Palette, CRGB leds[]);
        /*  19 */ static void funkyRainbowSinBeat8(int fade_funkyRainbowSinBeat8, CRGB leds[]);
        /*  20 */ static void funkyRangeSinBeat8(int fade_funkyRangeSinBeat8, int r, int g, int b, CRGB leds[]);
        /*  21 */ static void funkyRainbowSinBeat8Two(int fade_funkyRainbowSinBeat8Two, CRGB leds[]);
        /*  22 */ static void funkyRangeSinBeat8Two(int fade_funkyRangeSinBeat8Two, int r, int g, int b, CRGB leds[]);
        /*  23 */ static void movingFunkyPalette(CRGBPalette16 palette, uint8_t bpm1_movingFunkyPalette, uint8_t bpm2_movingFunkyPalette, CRGB leds[]);
        /*  24 */ static void rainbowWave(uint8_t bpm_rainbowWave, int tid_rainbowWave, int fade_rainbowWave, CRGB leds[]);
        /*  25 */ static void choosenWave(int tid_choosenWave, int bpm, int fade_choosenWave, int r, int g, int b, CRGB leds[]);
        /*  26 */ static void firstNoiseRainbow(uint8_t bpm_firstNoiseRainbow, CRGB leds[]);
        /*  27 */ static void firstNoiseColor(int r, int g, int b, uint8_t bpm_firstNoiseColor, CRGB leds[]);
        /*  28 */ static void noisePalette(CRGBPalette16 palette, int scale_noisePalette, CRGB leds[]);
        /*  29 */ static void runFire(CRGBPalette16 palette, CRGB leds[]);
        /*  30 */ static void secondNoise(CRGBPalette16 palette, CRGB leds[]);
        /*  31 */ static void fillNoise16(CRGB leds[]);

        // From here is the Dave's Garage implementations
        /*  32 */ static void rainbowDave(int density_rainbowDave, int delta_rainbowDave, int tid_rainbowDave, CRGB leds[]);
        /*  33 */ static void marqueeDave(int tid_marqueeDave, int density_marqueeDave, int length_marqueeDave, CRGB leds[]);
        /*  34 */ static void twinkleOld(int tid_twinkleOld, CRGB leds[]);
        /*  35 */ static void twinkle(int tid_twinkle, CRGB leds[]);
        /*  36 */ static void comet(int tid_comet, int fade_comet, int length_comet, int density_comet, CRGB leds[]);
        /*  37 */ static void cometOnce(int tid_cometOnce, int fade_cometOnce, int length_cometOnce, int density_cometOnce, double speed_cometOnce, CRGB leds[]);
        /*  38 */ static void bounce(CRGB leds[], int balls_bounce, byte fade_bounce, bool mirror_bounce); // Not the best but we keep it for now 
        /*  39 */ static void fire(int size_fire, int cooling_fire, int sparking_fire, int sparks_fire, int sparkHeight_fire, bool breversed_fire, bool bmirrored_fire);

        // Here optimization to make for the colors and the delay
        /*  40 */ static void storm(int chance_storm, int length_storm, int tid_storm, int fade_storm, CRGB leds[]); // Need to improve the use of delay !!!!
        /*  41 */ static void stormColored(int chance_stormColored, int length_stormColored, int tid_stormColored, int fade_stormColored, CRGB color, CRGB leds[]); // Need to improve the use of delay !!!!
        /*  42 */ static void stormPalette(int chance_stormPalette, int length_stormPalette, int tid_stormPalette, int fade_stormPalette, CRGBPalette16 palette, CRGB leds[]); // Need to improve the use of delay !!!!

        // Here optimization to make for the colors and the delay
        /*  43 */ static void lighting(int ledstart_lighting, int length_lighting, int flashes_lighting, int dimmer_lighting, int frequency_lighting, CRGB leds[]);
        /*  44 */ static void lightingColored(int ledstart_lightingColored, int length_lightingColored, int flashes_lightingColored, int dimmer_lightingColored, int frequency_lightingColored, CRGB color, CRGB leds[]);
        /*  45 */ static void lightingPalette(int ledstart_lightingPalette, int length_lightingPalette, int flashes_lightingPalette, int dimmer_lightingPalette, int frequency_lightingPalette, CRGBPalette16 palette, CRGB leds[]);

        // Links to find new effects
        // This one : https://www.reddit.com/r/FastLED/comments/pytqrm/party_lighting_for_the_garage_club_delta/

        /*  46 */ static void beat8_tail(uint8_t bpm_beat8_tail, int fade_beat8_tail, CRGB leds[]);
        /*  47 */ static void blendIntoRainbow(int tid_blendIntoRainbow, int tid2_blendIntoRainbow, CRGB leds[]);
        /*  48 */ static void breatheV2(float pulseSp_breatheV2, CRGB leds[]); // --> Need to add a color option here
        /*  49 */ static void chaseTargetTalesVarA(int tid_chaseTargetTalesVarA, CRGB leds[]);
        /*  50 */ static void chaseTargetTalesVarB(int tid_chaseTargetTalesVarB, CRGB leds[]);
        /*  51 */ static void chaseTargetTalesVarC(int boilingTime_chaseTargetTalesVarC, int tid_chaseTargetTalesVarC, int fadeTime_chaseTargetTalesVarC, CRGB leds[]);
        /*  52 */ static void everyNTimerVariables(uint16_t timerA_everyNTimerVariables, uint16_t timerB_everyNTimerVariables, CRGB leds[]);
        /*  53 */ static void fillUpStrip(CRGB leds[]);
        /*  54 */ static void heartBeat2(uint16_t beat_speed_heartBeat2, uint8_t dub_offset_heartBeat2, CRGB leds[]);
        /*  55 */ static void heartBeat3(bool rainbow_heartBeat3, CRGB leds[]); // --> Need to add color option
        /*  56 */ static void heartPulseBloodFlowing(CRGB leds[]); // --> Need to add color option
        /*  57 */ static void lighthouseBeaconV2(int length_lighthouseBeaconV2, int tid_lighthouseBeaconV2, int fade_lighthouseBeaconV2, CRGB leds[]); // --> Need to add color option
        /*  58 */ static void matchingGlitter1(CRGB leds[]); // Check for custom colors
        /*  59 */ static void matchingGlitter2(CRGB leds[]); // Check for custom colors
        /*  60 */ static void matchingGlitter3(bool second_matchingGlitter3, bool third_matchingGlitter3, CRGB leds[]); // Check for custom colors
        /*  61 */ static void matchingGlitter4(bool more_matchingGlitter4, CRGB leds[]); // Check for custom colors
        /*  62 */ static void mirrorFadeEnds(int fade_mirrorFadeEnds, CRGB leds[]);
        /*  63 */ static void Fire2012(int tid_Fire2012, int cooling_Fire2012, int sparking_Fire2012, CRGB leds[]);
        /*  64 */ static void Fire2012_halfStrip(int tid_Fire2012_halfStrip, int cooling_Fire2012_halfStrip, int sparking_Fire2012_halfStrip, bool gReverseDirection_Fire2012_halfStrip, CRGB leds[]);
        /*  65 */ static void movingColoredBar(CRGBPalette16 palette, CRGB leds[], int length_movingColoredBar = 5, uint8_t frameDelay_movingColoredBar = 80);
        /*  66 */ static void repeatingPattern(int tid_repeatingPattern, int tid2_repeatingPattern, int fade_repeatingPattern, CRGB leds[]);
        /*  67 */ static void savedPixel(int tid_savedPixel, int tid2_savedPixel, CRGB leds[]);
        /*  68 */ static void sinCosLinear(CRGB leds[]); // --> Need to add color option
        /*  69 */ static void sparkles(CRGB leds[], int sparkel_duration_sparkles = random(80, 200), int sparkel_amount_sparkles = 100, int sparkel_spread_sparkles = 30);
        /*  70 */
        
    


        static uint32_t CRGBToInt(const CRGB& color);
        static uint8_t getBeatSinColor(uint32_t Color);
        static std::vector<uint8_t> getArrayRangeValue(uint32_t Color);
        static CRGB hsvToRgb(const CHSV& hsv);
        static void DrawPixels(float fPos, float count, CRGB color);
        static int sumPulse(int time_shift);
        static uint8_t pulseWave8(uint32_t ms, uint16_t cycleLength, uint16_t pulseLength);
        static void drawFractionalBar( int pos16, int width, uint8_t hue, uint8_t fadeRate, CRGB leds[]);
        static uint32_t fromRGBtoHex(uint8_t r, uint8_t g, uint8_t b);
    
    private:
        int red;
        int green;
        int blue;
        void setColor(int r, int g, int b);

};