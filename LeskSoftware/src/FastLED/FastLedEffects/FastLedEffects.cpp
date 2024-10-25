#include "FastLedEffects.h"
#define NUM_LEDS 10
#define DATA_PIN_1 23

// Blink effect
unsigned long previousMillisBlink = 0;
bool ledsOn = true;
// Back And Forth One Dot effect
static int posBackAndForthOneDot = 0;           // Current position of the dot
static int directionBackAndForthOneDot = 1;

// Backa And Forth Lengthed Dot effect
static int posBackAndForthLengthed = 0;           // Current position of the dot
static int directionBackAndForthLengthed = 1;

// Hue fading
static uint8_t hue = 0;

// Moving Palette
static uint8_t paletteIndex = 0;

// First Noise
static uint16_t x = 0;
static int scale = 10;
static uint16_t t = 0;

// Noise palette
static uint16_t brightnessScale = 150;
static uint16_t indexScale = 20;

// Second Noise
static uint8_t octaveVal = 2;
static uint16_t xVal = 0;
static int scaleVal = 50;
static uint16_t timeVal = 0;
static uint8_t noiseData[NUM_LEDS];

// Fill Noise 16
static uint8_t hue_octaves = 1;
static uint16_t hue_x = 1;
static int hue_scale = 50;

// RainbowDave
static uint8_t initialHue = 0;

//Marquee Dave
static unsigned long lastUpdate = 0;  // Store the last update time
unsigned long interval = 0;   // Interval in milliseconds between updates

// BlendIntoRainbow
static uint8_t pos = 0;  //stores a position for color being blended in
static uint8_t hue2;  //stores a color to blend into the background

// Breathe V2
static float pulseSpeed = 0.5;  // Larger value gives faster pulse.
uint8_t hueA = 15;  // Start hue at valueMin.
uint8_t satA = 230;  // Start saturation at valueMin.
float valueMin = 120.0;  // Pulse minimum value (Should be less then valueMax).
uint8_t hueB = 95;  // End hue at valueMax.
uint8_t satB = 255;  // End saturation at valueMax.
float valueMax = 255.0;  // Pulse maximum value (Should be larger then valueMin).
// uint8_t hue = hueA;  // Do Not Edit
uint8_t sat = satA;  // Do Not Edit
float val = valueMin;  // Do Not Edit
uint8_t hueDelta = hueA - hueB;  // Do Not Edit
static float delta = (valueMax - valueMin) / 2.35040238;  // Do Not Edit

// Chase Target Tales Var A
static int target[NUM_LEDS];  // Place to save some target values.
static int countOff;
static int delta2;
static int temp;
static int lowCutoff = 50;

// Chase Target Var B
CHSV leds_vu[NUM_LEDS];  // FastLED array using HSV.
int highCutoff = 200;
// int lowCutoff = 30;
static int hue_high = 0;  // red for high values with,
static int hue_low = 96;  // green for low values.

// Chase target tales Var C
static uint8_t pixel;  // Which pixel to operate on.
static uint8_t ccc = 0;  // color combination choice (ccc)

// everyNTimerVariables
static boolean counterTriggered = 0;  // Event triggered? [1=true, 0=false]

// FillUpStrip
static uint8_t fill_delay = 20;        // Increase to slow fill rate.
static float delay_base = 1.17;        // Used to add a delay as strip fills up.
static float delay_multiplier = 2.15;  // Used to add a delay as strip fills up.

// Heart Beat 2
CRGB lubs_color = CHSV(15,230,255);
CRGB dubs_color = CHSV(0,255,90);

// Heart Beat 3
#define LUB_TIME   785  // Time between main lubs [milliseconds]
#define DUB_DELAY  120  // Short delay for when secondary dub starts [milliseconds]
uint8_t beatHue = 0;  // Hue of heart beat (0 is red)

// Heart Pulse Blood Flowing
static uint8_t bloodHue = 96;  // Blood color [hue from 0-255]
static uint8_t bloodSat = 255;  // Blood staturation [0-255]
static int flowDirection = -1;   // Use either 1 or -1 to set flow direction
static uint16_t cycleLength = 1500;  // Lover values = continuous flow, higher values = distinct pulses.
static uint16_t pulseLength = 150;  // How long the pulse takes to fade out.  Higher value is longer.
static uint16_t pulseOffset = 200;  // Delay before second pulse.  Higher value is more delay.
static uint8_t baseBrightness = 10;  // Brightness of LEDs when not pulsing. Set to 0 for off.

// Light House Beacon V2
int deltaInt = 1; // Number of 16ths of a pixel to move.  (Use negative value for reverse.)
int pixelPos = 0; // position of the "fraction-based bar" [don't edit]

// Moving Colored Bar
static int barPosition = 1;
static int paletteIndexmcb = 0;

// Repeating pattern
// How often does the pattern repeat?
static uint16_t repeatEvery = 5;
// Therefore the number of times the pattern will repeat down the strip is:
static uint16_t numberOfRepeats = NUM_LEDS/repeatEvery;

// Saved Pixel
CRGB pData[NUM_LEDS];  // extra array to store some info about the pixels

// SinCosLinear
uint8_t potValue;  // Simulated potentiometer value.
uint8_t sin_output;
uint8_t cos_output;
uint16_t slowBy = 15;  // miliseconds to delay

// Objects here
// Bounce bouncer = Bounce(NUM_LEDS, 1);
Bounce bouncer = Bounce(NUM_LEDS, 1, 64, false);
FireEffect fireEffect(NUM_LEDS, 80, 100, 2, 2, false, false);


// Add link to fastLed : 
// Add link to video : https://www.youtube.com/watch?v=4Ut4UK7612M&list=PLgXkGn3BBAGi5dTOCuEwrLuFtfz0kGFTC&index=2
void FastLedEffects::fill(int r, int g, int b, CRGB leds[]) {
    fill_solid(leds, NUM_LEDS, CRGB(r, g, b));
    FastLED.show();
}

// Add link to fastLed : 
// Add link to video : https://www.youtube.com/watch?v=4Ut4UK7612M&list=PLgXkGn3BBAGi5dTOCuEwrLuFtfz0kGFTC&index=2
void FastLedEffects::blink(int r, int g, int b, CRGB leds[], int tid_blink) {
    unsigned long currentMillis = millis();

    // Check if it's time to toggle the state
    if (currentMillis - previousMillisBlink >= tid_blink) {
        previousMillisBlink = currentMillis;

        // Toggle the LED state
        ledsOn = !ledsOn;

        if (ledsOn) {
            // Turn the LEDs on
            fill_solid(leds, NUM_LEDS, CRGB(r, g, b));
        } else {
            // Turn the LEDs off
            fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
        }

        FastLED.show();
    }
}

// Add link to fastLed : 
// Add link to video : https://www.youtube.com/watch?v=4Ut4UK7612M&list=PLgXkGn3BBAGi5dTOCuEwrLuFtfz0kGFTC&index=2
void FastLedEffects::rainbowStatic(CRGB leds[]) {
    fill_rainbow(leds, NUM_LEDS, 0, 255 / NUM_LEDS);
    FastLED.show();
}

// Add link to fastLed : 
// Add link to video : https://www.youtube.com/watch?v=4Ut4UK7612M&list=PLgXkGn3BBAGi5dTOCuEwrLuFtfz0kGFTC&index=2
void FastLedEffects::fillGradientTwoColors(int r1, int g1, int b1, int r2, int g2, int b2, CRGB leds[]) {
    fill_gradient_RGB(leds, NUM_LEDS, CRGB(r1,g1,b1), CRGB(r2,g2,b2));
    FastLED.show();
}

void FastLedEffects::fillGradientThreeColors(int r1, int g1, int b1, int r2, int g2, int b2, int r3, int g3, int b3, CRGB leds[]) {
    fill_gradient_RGB(leds, NUM_LEDS, CRGB(r1,g1,b1), CRGB(r2,g2,b2), CRGB(r3,g3,b3));
    FastLED.show();
}

// Add link to video : https://www.youtube.com/watch?v=4Ut4UK7612M&list=PLgXkGn3BBAGi5dTOCuEwrLuFtfz0kGFTC&index=2
void FastLedEffects::backAndForthNoSmoothOneDot(int r, int g, int b, CRGB leds[], int tid_backAndForthNoSmoothOneDot) {
    static unsigned long lastUpdate = 0;
    
    // Get the current time
    unsigned long currentTime = millis();
    
    // Check if enough time has passed based on the value of tid
    if (currentTime - lastUpdate >= tid_backAndForthNoSmoothOneDot) {
        lastUpdate = currentTime;  // Update the last update time

        // Turn off all LEDs
        fill_solid(leds, NUM_LEDS, CRGB::Black);

        // Light up the current position
        leds[posBackAndForthOneDot] = CRGB(r, g, b);
        FastLED.show();

        // Update the position
        posBackAndForthOneDot += directionBackAndForthOneDot;

        // Reverse direction at the ends
        if (posBackAndForthOneDot == 0 || posBackAndForthOneDot == NUM_LEDS - 1) {
            directionBackAndForthOneDot = -directionBackAndForthOneDot;
        }
    }
}

void FastLedEffects::backAndForthNoSmoothLengthedDot(int r, int g, int b, CRGB leds[], int tid_backAndForthNoSmoothLengthedDot, int length_backAndForthNoSmoothLengthedDot) {
    static unsigned long lastUpdate = 0;

    // Get the current time
    unsigned long currentTime = millis();

    // Check if enough time has passed based on the value of tid
    if (currentTime - lastUpdate >= tid_backAndForthNoSmoothLengthedDot) {
        lastUpdate = currentTime;  // Update the last update time

        // Turn off all LEDs
        fill_solid(leds, NUM_LEDS, CRGB::Black);

        // Light up the current position for the given length
        for (int i = posBackAndForthLengthed; i < posBackAndForthLengthed + length_backAndForthNoSmoothLengthedDot; i++) {
            if (i >= 0 && i < NUM_LEDS) {
                leds[i] = CRGB(r, g, b);
            }
        }
        FastLED.show();

        // Update the position
        posBackAndForthLengthed += directionBackAndForthLengthed;

        // Reverse direction at the ends
        if (posBackAndForthLengthed <= 0 || posBackAndForthLengthed + length_backAndForthNoSmoothLengthedDot >= NUM_LEDS) {
            directionBackAndForthLengthed = -directionBackAndForthLengthed;
        }
    }
}

void FastLedEffects::hueFading(int tid_hueFading, CRGB leds[]) {
    static unsigned long lastUpdate = 0;
    static uint8_t hue = 0;  // Start with an initial hue value

    // Get the current time
    unsigned long currentTime = millis();

    // Check if enough time has passed based on the value of tid
    if (currentTime - lastUpdate >= tid_hueFading) {
        lastUpdate = currentTime;  // Update the last update time

        // Increment the hue value
        hue++;
    }

    // Fill the LEDs with the current hue
    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CHSV(hue, 255, 255);
    }

    // Display the updated LEDs
    FastLED.show();
}

void FastLedEffects::hueWhiteWave(uint8_t hueInsert_hueWhiteWave, int tid_hueWhiteWave, CRGB leds[]) {
    static unsigned long lastUpdate = 0;
    unsigned long currentTime = millis();

    if(currentTime - lastUpdate >= tid_hueWhiteWave) {
        leds[0] = CHSV(hueInsert_hueWhiteWave, random8(), random8(100, 255));

        for (int i = NUM_LEDS - 1; i > 0; i--) {
            leds[i] = leds[i - 1];
        }
        FastLED.show();
    }
}


void FastLedEffects::displayPaletteLinear(CRGBPalette16 palette, CRGB leds[]) {
    fill_palette(leds, NUM_LEDS, 0, 255/NUM_LEDS, palette, 100, LINEARBLEND);
    FastLED.show();
}

void FastLedEffects::movingPaletteLinear(CRGBPalette16 palette, int tid_movingPaletteLinear, CRGB leds[]) {
    static unsigned long lastUpdate = 0;
    unsigned long currentTime = millis();

    if(currentTime - lastUpdate >= tid_movingPaletteLinear) {
      lastUpdate = currentTime;
      paletteIndex += 75;
    }
      fill_palette(leds, NUM_LEDS, paletteIndex, 255/NUM_LEDS, palette, 100, LINEARBLEND);
      FastLED.show();
}

// Link: https://www.youtube.com/watch?v=Ukq0tH2Tnkc&list=PLgXkGn3BBAGi5dTOCuEwrLuFtfz0kGFTC&index=3
void FastLedEffects::spotlightingPalette(CRGBPalette16 palette, int tid_spotlightingPalette, int fade_spotlightingPalette, CRGB leds[]) {
    static unsigned long lastUpdate = 0;
    unsigned long currentTime = millis();

    if(currentTime - lastUpdate >= tid_spotlightingPalette) {
      lastUpdate = currentTime;
      leds[random(0, NUM_LEDS - 1)] = ColorFromPalette(palette, random8(), 255, LINEARBLEND);
    }

    fadeToBlackBy(leds, NUM_LEDS, fade_spotlightingPalette);
    FastLED.show();
}

// Link : https://www.youtube.com/watch?v=2owTxbrmY-s&list=PLgXkGn3BBAGi5dTOCuEwrLuFtfz0kGFTC&index=4
void FastLedEffects::sinBeat8(int r, int g, int b, int fade_sinBeat8, uint8_t bpm_sinBeat8, CRGB leds[]) {
    // This effect do like a shooting star coming back and forth
    uint8_t sinBeat = beatsin8(bpm_sinBeat8, 0, NUM_LEDS - 1, 0, 0); // The last 2 zeros are phase offset and time based, not useful yet
    leds[sinBeat] = CRGB(r, g, b);

    fadeToBlackBy(leds, NUM_LEDS, fade_sinBeat8);
    FastLED.show();
}

// Link : https://www.youtube.com/watch?v=2owTxbrmY-s&list=PLgXkGn3BBAGi5dTOCuEwrLuFtfz0kGFTC&index=4
void FastLedEffects::sinBeat8PhaseOff(int r, int g, int b, int fade_sinBeat8PhaseOff, uint8_t bpm_sinBeat8PhaseOff, uint8_t phaseOffset_sinBeat8PhaseOff, CRGB leds[]) {
    // This function can be useful for adapting to the bpm of the song by modifying the phase
    uint8_t sinBeat = beatsin8(bpm_sinBeat8PhaseOff, 0, NUM_LEDS - 1, 0, phaseOffset_sinBeat8PhaseOff); 
    leds[sinBeat] = CRGB(r, g, b);
    fadeToBlackBy(leds, NUM_LEDS, fade_sinBeat8PhaseOff);
    FastLED.show();
}

// Link : https://www.youtube.com/watch?v=2owTxbrmY-s&list=PLgXkGn3BBAGi5dTOCuEwrLuFtfz0kGFTC&index=4
void FastLedEffects::sinBeat8TimeOff(int r, int g, int b, int fade_sinBeat8TimeOff, uint8_t bpm_sinBeat8TimeOff, int time_sinBeat8TimeOff, CRGB leds[]) {
    // This function can be useful for adapting to the bpm of the song by modifying the phase
    // Formula : Period of a wave = 60 / bpm * milliseconds
    uint8_t sinBeat = beatsin8(bpm_sinBeat8TimeOff, 0, NUM_LEDS - 1, time_sinBeat8TimeOff, 0);
    leds[sinBeat] = CRGB(r, g, b);

    fadeToBlackBy(leds, NUM_LEDS, fade_sinBeat8TimeOff);
    FastLED.show();
}
// Link : https://www.youtube.com/watch?v=2owTxbrmY-s&list=PLgXkGn3BBAGi5dTOCuEwrLuFtfz0kGFTC&index=4
void FastLedEffects::twoSinBeat8(int r, int g, int b, int r2, int g2, int b2, int fade_twoSinBeat8, uint8_t bpm_twoSinBeat8, CRGB leds[]) {    
    uint8_t sinBeat1 = beatsin8(bpm_twoSinBeat8, 0, NUM_LEDS - 1, 0, 0);
    uint8_t sinBeat2 = beatsin8(bpm_twoSinBeat8, 0, NUM_LEDS - 1, 0, 170);
    leds[sinBeat1] = CRGB(r, g, b);
    leds[sinBeat2] = CRGB(r2, g2, b2);
    fadeToBlackBy(leds, NUM_LEDS, fade_twoSinBeat8);
    FastLED.show();
}
// Link : https://www.youtube.com/watch?v=2owTxbrmY-s&list=PLgXkGn3BBAGi5dTOCuEwrLuFtfz0kGFTC&index=4
void FastLedEffects::threeSinBeat8(int r, int g, int b, int r2, int g2, int b2, int r3, int g3, int b3, int fade_threeSinBeat8, uint8_t bpm_threeSinBeat8, CRGB leds[]) {
    uint8_t sinBeat1 = beatsin8(bpm_threeSinBeat8, 0, NUM_LEDS - 1, 0, 0);
    uint8_t sinBeat2 = beatsin8(bpm_threeSinBeat8, 0, NUM_LEDS - 1, 0, 85);
    uint8_t sinBeat3 = beatsin8(bpm_threeSinBeat8, 0, NUM_LEDS - 1, 0, 170);
    leds[sinBeat1] = CRGB(r, g, b);
    leds[sinBeat2] = CRGB(r2, g2, b2);
    leds[sinBeat3] = CRGB(r3, g3, b3);
    fadeToBlackBy(leds, NUM_LEDS, fade_threeSinBeat8);
    FastLED.show();
}

void FastLedEffects::brightnessSinBeat8Palette(CRGBPalette16 palette, uint8_t bpm_brightnessSinBeat8Palette, int tid_brightnessSinBeat8Palette, CRGB leds[]) {
    static int more = 0;
    uint8_t sinBeat = beatsin8(bpm_brightnessSinBeat8Palette, 0, 255, 0, 0);
    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = ColorFromPalette(palette, (255/NUM_LEDS * i + more) % 255, sinBeat);
    }
    EVERY_N_MILLISECONDS(tid_brightnessSinBeat8Palette) {
        more++;
    }
    FastLED.show();
}

void FastLedEffects::funkyRainbowSinBeat8(int fade_funkyRainbowSinBeat8, CRGB leds[]) {
    // Waves for led position
    uint8_t posBeat = beatsin8(30, 0, NUM_LEDS - 1, 0, 0);
    uint8_t posBeat2 = beatsin8(60, 0, NUM_LEDS - 1, 0, 0);
    // Wave for LED color
    uint8_t colBeat = beatsin8(45, 0, 255, 0, 0);
    leds[(posBeat + posBeat2) / 2] = CHSV(colBeat, 255, 255);
    fadeToBlackBy(leds, NUM_LEDS, fade_funkyRainbowSinBeat8);
    FastLED.show();
}

void FastLedEffects::funkyRangeSinBeat8(int fade_funkyRangeSinBeat8, CRGB color, CRGB leds[]) {
    // Waves for led position
    uint8_t posBeat = beatsin8(30, 0, NUM_LEDS - 1, 0, 0);
    uint8_t posBeat2 = beatsin8(60, 0, NUM_LEDS - 1, 0, 0);
    // Wave for LED color
    uint32_t convertedColor = FastLedEffects::CRGBToInt(color);
    uint8_t colBeat = FastLedEffects::getBeatSinColor(convertedColor);
    leds[(posBeat + posBeat2) / 2] = CHSV(colBeat, 255, 255);
    fadeToBlackBy(leds, NUM_LEDS, fade_funkyRangeSinBeat8);
    FastLED.show();
}

void FastLedEffects::funkyRainbowSinBeat8Two(int fade_funkyRainbowSinBeat8Two, CRGB leds[]) {
    uint8_t posBeat = beatsin8(30, 0, NUM_LEDS - 1, 0, 0);
    uint8_t posBeat2 = beatsin8(60, 0, NUM_LEDS - 1, 0, 0);
    uint8_t posBeat3 = beatsin8(30, 0, NUM_LEDS - 1, 0, 127);
    uint8_t posBeat4 = beatsin8(60, 0, NUM_LEDS - 1, 0, 127);

    uint8_t colBeat = beatsin8(45, 0, 255, 0, 0);
    leds[(posBeat + posBeat2) / 2] = CHSV(colBeat, 255, 255);
    leds[(posBeat3 + posBeat4) / 2] = CHSV(colBeat, 255, 255);
    fadeToBlackBy(leds, NUM_LEDS, fade_funkyRainbowSinBeat8Two);
    FastLED.show();
}

void FastLedEffects::funkyRangeSinBeat8Two(int fade_funkyRangeSinBeat8Two, CRGB color, CRGB leds[]) {
    uint8_t posBeat = beatsin8(30, 0, NUM_LEDS - 1, 0, 0);
    uint8_t posBeat2 = beatsin8(60, 0, NUM_LEDS - 1, 0, 0);
    uint8_t posBeat3 = beatsin8(30, 0, NUM_LEDS - 1, 0, 127);
    uint8_t posBeat4 = beatsin8(60, 0, NUM_LEDS - 1, 0, 127);

    uint32_t convertedColor = FastLedEffects::CRGBToInt(color);
    uint8_t colBeat = FastLedEffects::getBeatSinColor(convertedColor);
    leds[(posBeat + posBeat2) / 2] = CHSV(colBeat, 255, 255);
    leds[(posBeat3 + posBeat4) / 2] = CHSV(colBeat, 255, 255);
    fadeToBlackBy(leds, NUM_LEDS, fade_funkyRangeSinBeat8Two);
    FastLED.show();

}

void FastLedEffects::movingFunkyPalette(CRGBPalette16 palette, uint8_t bpm1_movingFunkyPalette, uint8_t bpm2_movingFunkyPalette, CRGB leds[]) {
    uint8_t beatA = beatsin8(bpm1_movingFunkyPalette, 0, 255);
    uint8_t beatB = beatsin8(bpm2_movingFunkyPalette, 0, 255);
    fill_palette(leds, NUM_LEDS, (beatA + beatB) / 2, 10, palette, 255, LINEARBLEND);
    FastLED.show();
}

void FastLedEffects::rainbowWave(uint8_t bpm_rainbowWave, int tid_rainbowWave, int fade_rainbowWave, CRGB leds[]) {
    uint8_t pos = map(beat8(bpm_rainbowWave, 0), 0, 255, 0, NUM_LEDS - 1);
    leds[pos] = CHSV(hue, 200, 255);
    fadeToBlackBy(leds, NUM_LEDS, fade_rainbowWave);
    EVERY_N_MILLISECONDS(tid_rainbowWave) {
        hue++;
    }
    FastLED.show();
}

void FastLedEffects::choosenWave(int tid_choosenWave, int fade_choosenWave, CRGB color, CRGB leds[]) {
    uint8_t pos = map(beat8(40, 0), 0, 255, 0, NUM_LEDS - 1);
    std::vector<uint8_t> colors = FastLedEffects::getArrayRangeValue(FastLedEffects::CRGBToInt(color));
    leds[pos] = CHSV(map(hue, 0, 255, colors[0], colors[1]), 200, 255);
    fadeToBlackBy(leds, NUM_LEDS, fade_choosenWave);
    EVERY_N_MILLISECONDS(tid_choosenWave) {
        hue++;
    }
    FastLED.show();
}

void FastLedEffects::firstNoiseRainbow(uint8_t bpm_firstNoiseRainbow, CRGB leds[]) {
    x = 0;
    scale = beatsin8(bpm_firstNoiseRainbow, 10, 30); // bpm
    t = millis() / 5;
    for (int i = 0; i < NUM_LEDS; i++) {
        uint8_t noise = inoise8(i * scale + x, t);
        uint8_t huetest = map(noise, 50, 190, 0, 255); // Color type of hue
        leds[i] = CHSV(huetest, 255, 255);
    }
    FastLED.show();
}

void FastLedEffects::firstNoiseColor(CRGB color, uint8_t bpm_firstNoiseColor, CRGB leds[]) {
    x = 0;
    scale = beatsin8(bpm_firstNoiseColor, 10, 30); // bpm
    t = millis() / 5;
    std::vector<uint8_t> colors = FastLedEffects::getArrayRangeValue(FastLedEffects::CRGBToInt(color));
    for (int i = 0; i < NUM_LEDS; i++) {
        uint8_t noise = inoise8(i * scale + x, t);
        uint8_t huetest = map(noise, 50, 190, colors[0], colors[1]); // Color type of hue
        leds[i] = CHSV(huetest, 255, 255);
    }
    FastLED.show();
}

void FastLedEffects::noisePalette(CRGBPalette16 palette, int scale_noisePalette, CRGB leds[]) {
    for (int i = 0; i < NUM_LEDS; i++) {
        indexScale = scale_noisePalette;
        uint8_t brightness = inoise8(i*brightnessScale, millis() / 5);
        uint8_t index = inoise8(i*indexScale, millis() / 10);
        leds[i] = ColorFromPalette(palette, index, brightness);
    }
    FastLED.show();
}

void FastLedEffects::runFire(CRGBPalette16 palette, CRGB leds[]) {
    int a = millis();
    for (int i = 0; i < NUM_LEDS; i++) {
        uint8_t noise = inoise8(0, i * 60 + a, a / 3);
        uint8_t math = abs8(i - (NUM_LEDS - 1) * 255 / (NUM_LEDS - 1));
        uint8_t indexFire = qsub8(noise, math);
        leds[i] = ColorFromPalette(palette, indexFire, 255, LINEARBLEND);
    }
    FastLED.show();
}

void FastLedEffects::secondNoise(CRGBPalette16 palette, CRGB leds[]) {

    timeVal = millis() / 4;
    memset(noiseData, 0, NUM_LEDS);
    fill_raw_noise8(noiseData, NUM_LEDS, octaveVal, xVal, scaleVal, timeVal);
    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = ColorFromPalette(palette, noiseData[i], noiseData[NUM_LEDS - i - 1], LINEARBLEND);
    }
    FastLED.show();
}

void FastLedEffects::fillNoise16(CRGB leds[]) {
    octaveVal = 1;
    xVal = 0;
    scaleVal = 100;
    uint16_t ntime = millis() / 3;
    uint8_t hue_shift = 5;
    fill_noise16(leds, NUM_LEDS, octaveVal, xVal, scaleVal, hue_octaves, hue_x, hue_scale, ntime, hue_shift);
    FastLED.show();
}

// Link : https://www.youtube.com/watch?v=r6vMdnqUjTk&list=PLF2KJ6Gy3cZ7ynsp8s4tnqEFmY15CKhmH&index=12
void FastLedEffects::rainbowDave(int density_rainbowDave, int delta_rainbowDave, int tid_rainbowDave, CRGB leds[]) {
    // Here the density is the speed of the animation
    EVERY_N_MILLISECONDS(tid_rainbowDave) {
      fill_rainbow(leds, NUM_LEDS, initialHue += density_rainbowDave, delta_rainbowDave);
    }
  
    FastLED.show();
}

// Link : https://www.youtube.com/watch?v=r6vMdnqUjTk&list=PLF2KJ6Gy3cZ7ynsp8s4tnqEFmY15CKhmH&index=12
void FastLedEffects::marqueeDave(int tid_marqueeDave, int density_marqueeDave, int length_marqueeDave, CRGB leds[]) {
    static byte j = HUE_BLUE;
    interval = tid_marqueeDave;
    static int scroll = 0;
    if (millis() - lastUpdate >= interval) {
        lastUpdate = millis();

        j += 1;
        byte k = j;

        CRGB c;
        for (int i = 0; i < NUM_LEDS; i++) {
            leds[i] = c.setHue(k+=density_marqueeDave);
        }
        
        scroll++;
        for (int i = scroll % length_marqueeDave; i < NUM_LEDS; i+=length_marqueeDave) {
            leds[i] = CRGB::Black;
        }
        FastLED.show();
    }
}

// Would be good to make something more extended later
#define NUM_COLORS 5
static const CRGB TwinkleColors [NUM_COLORS] = {
    CRGB::Red,
    CRGB::Blue,
    CRGB::Purple,
    CRGB::Green,
    CRGB::Orange
};
void FastLedEffects::twinkleOld(int tid_twinkleOld, CRGB leds[]) {
    interval = tid_twinkleOld;
    if (millis() - lastUpdate >= interval) {
        lastUpdate = millis();
        FastLED.clear(false);
        for (int i = 0; i < NUM_LEDS / 2; i++) {
            leds[random(NUM_LEDS)] = TwinkleColors[random(0, NUM_COLORS)];
            FastLED.show();
        }
    }
}

void FastLedEffects::twinkle(int tid_twinkle, CRGB leds[]) {
    interval = tid_twinkle;
    if (millis() - lastUpdate >= interval) {
        lastUpdate = millis();
        static int passCount = 0;
        passCount++;

        if (passCount == NUM_LEDS) {
            passCount = 0;
            FastLED.clear(false);
        }
        leds[random(NUM_LEDS)] = TwinkleColors[random(0, NUM_COLORS)];
        FastLED.show();
    }
}

void FastLedEffects::comet(int tid_comet, int fade_comet, int length_comet, int density_comet, CRGB leds[]) {

    byte fadeAmt = fade_comet;
    int cometSize = length_comet;
    int deltaHue = density_comet;

    static byte hueByte = HUE_RED;  // Current comet color
    static int iDirection = 1;      // Current direction
    static int iPos = 0;    // Current comet positon on the strip

     interval = tid_comet;
    if (millis() - lastUpdate >= interval) {
        lastUpdate = millis();
        hueByte += deltaHue;  //Update comet color
        iPos += iDirection;  // Update comet position

        // Flip the comet direction when it hits either end of the strip
        if (iPos == (NUM_LEDS - cometSize) || iPos == 0) {
            iDirection *= -1;
        }

        // Draw the comet at its current position
        for (int i = 0; i < cometSize; i++) {
            leds[iPos + i].setHue(hueByte);
        }

        // Fade the LEDS one step
        for (int j = 0; j < NUM_LEDS; j++) {
            if (random(2) == 1)
                // leds[j] =leds[j].fadeToBlackBy(fadeAmt);
                leds[j].fadeToBlackBy(fadeAmt);
        }
        FastLED.show();
    }
}

void FastLedEffects::cometOnce(int tid_cometOnce, int fade_cometOnce, int length_cometOnce, int density_cometOnce, double speed_cometOnce, CRGB leds[]) {

    byte fadeAmt = fade_cometOnce;
    int cometSize = length_cometOnce;
    int deltaHue = density_cometOnce;
    double cometSpeed = speed_cometOnce;

    static byte hueByte = HUE_RED;  // Current comet color
    static int iDirection = 1;      // Current direction
    static double iPos = 0.0;    // Current comet positon on the strip

    interval = tid_cometOnce;
    if (millis() - lastUpdate >= interval) {
        lastUpdate = millis();
        hueByte += deltaHue;  //Update comet color
        iPos += iDirection * cometSpeed;  // Update comet position

        // Flip the comet direction when it hits either end of the strip
        if (iPos == (NUM_LEDS - cometSize) || iPos == 0) {
            iDirection *= -1;
        }

        // Draw the comet at its current position
        for (int i = 0; i < cometSize; i++) {
            leds[(int)iPos + i].setHue(hueByte);
        }

        // Fade the LEDS one step
        for (int j = 0; j < NUM_LEDS; j++) { 
            if (random(2) == 1)
                // leds[j] =leds[j].fadeToBlackBy(fadeAmt);
                leds[j].fadeToBlackBy(fadeAmt);
        }
        FastLED.show();
    }
}

// Link : https://www.youtube.com/watch?v=ysI30OrkiAc&list=PLF2KJ6Gy3cZ7ynsp8s4tnqEFmY15CKhmH&index=10
void FastLedEffects::bounce( CRGB leds[], int balls_bounce, byte fade_bounce, bool mirror_bounce) {
    if (bouncer.GetInstantiated() != balls_bounce) {
       bouncer.Recalibrate(balls_bounce);
    }
    if (bouncer.GetFade() != fade_bounce) {
        bouncer.SetFade(fade_bounce);
    }
    if (bouncer.GetMirror() != mirror_bounce) {
        bouncer.SetMirror(mirror_bounce);
    }
    bouncer.Draw(leds);
}

// Link : https://www.youtube.com/watch?v=MauVVTJb2tk&list=PLF2KJ6Gy3cZ7ynsp8s4tnqEFmY15CKhmH&index=6
// Here we can develop but I am a bit tired of his tutorials tbh
// There is as well the fact that it takes the whole strip and doesn't behave necessarily like a fire on a 10 leds stripe

void FastLedEffects::fire(int size_fire, int cooling_fire, int sparking_fire, int sparks_fire, int sparkHeight_fire, bool breversed_fire, bool bmirrored_fire) {
    if (fireEffect.GetSize() != size_fire) {
        fireEffect.SetSize(size_fire);
    }
    if (fireEffect.GetCooling() != cooling_fire) {
        fireEffect.SetCooling(cooling_fire);
    }
    if (fireEffect.GetSparking() != sparking_fire) {
        fireEffect.SetSparking(sparking_fire);
    }
    if (fireEffect.GetSparks() != sparks_fire) {
        fireEffect.SetSparks(sparks_fire);
    }
    if (fireEffect.GetSparkHeight() != sparkHeight_fire) {
        fireEffect.SetSparkHeight(sparkHeight_fire);
    }
    if (fireEffect.GetReversed() != breversed_fire) {
        fireEffect.SetReversed(breversed_fire);
    }
    if (fireEffect.GetMirrored() != bmirrored_fire) {
        fireEffect.SetMirrored(bmirrored_fire);
    }
    fireEffect.DrawFire();
}

// Link : https://github.com/netmindz/arduino/blob/master/Deevstock/CloudsV3/CloudsV3.ino
void FastLedEffects::storm(int chance_storm, int length_storm, int tid_storm, int fade_storm, CRGB leds[]) {
  // clusters of leds, souce of
  if (random(0, chance_storm) == 0) {
    for (int i = 0; i < random(1, NUM_LEDS); i++) {
      int r = random16(NUM_LEDS);
      for (int j = 0; j < random(1, length_storm); j++) {
        if ((r + j) <  NUM_LEDS) {
          leds[(r + j)] = CHSV(random(0, 255), 100, 255);
        }
      }
    }
  }
  FastLED.delay(tid_storm);
  fadeToBlackBy(leds, NUM_LEDS, fade_storm);
}

void FastLedEffects::stormColored(int chance_stormColored, int length_stormColored, int tid_stormColored, int fade_stormColored, CRGB color, CRGB leds[]) {
    uint32_t convertedColor = FastLedEffects::CRGBToInt(color);
    uint8_t colBeat = FastLedEffects::getBeatSinColor(convertedColor);
    // clusters of leds, souce of
  if (random(0, chance_stormColored) == 0) {
    for (int i = 0; i < random(1, NUM_LEDS); i++) {
      int r = random16(NUM_LEDS);
      for (int j = 0; j < random(1, length_stormColored); j++) {
        if ((r + j) <  NUM_LEDS) {
          leds[(r + j)] = CHSV(colBeat, 100, 255);
        }
      }
    }
  }
  FastLED.delay(tid_stormColored);
  fadeToBlackBy(leds, NUM_LEDS, fade_stormColored);
}

void FastLedEffects::stormPalette(int chance_stormPalette, int length_stormPalette, int tid_stormPalette, int fade_stormPalette, CRGBPalette16 palette, CRGB leds[]) {
    if (random(0, chance_stormPalette) == 0) {
    for (int i = 0; i < random(1, NUM_LEDS); i++) {
      int r = random16(NUM_LEDS);
      for (int j = 0; j < random(1, length_stormPalette); j++) {
        if ((r + j) <  NUM_LEDS) {
          leds[(r + j)] = ColorFromPalette(palette, random8(), 255, LINEARBLEND);
        }
      }
    }
  }
  FastLED.delay(tid_stormPalette);
  fadeToBlackBy(leds, NUM_LEDS, fade_stormPalette);
}

// Link : https://github.com/netmindz/arduino/blob/master/Deevstock/CloudsV3/CloudsV3.ino
void FastLedEffects::lighting(int ledstart_lighting, int length_lighting, int flashes_lighting, int dimmer_lighting, int frequency_lighting, CRGB leds[]) {
        ledstart_lighting = random8(NUM_LEDS);                               // Determine starting location of flash
        length_lighting = random8(NUM_LEDS - ledstart_lighting);                      // Determine length of flash (not to go beyond NUM_LEDS-1)

        EVERY_N_MILLISECONDS(1000 / frequency_lighting) {
            for (int flashCounter = 0; flashCounter < random8(3, flashes_lighting); flashCounter++) {
                if (flashCounter == 0) dimmer_lighting = 5;                        // the brightness of the leader is scaled down by a factor of 5
                else dimmer_lighting = random8(1, 3);                              // return strokes are brighter than the leader

                fill_solid(leds + ledstart_lighting, length_lighting, CHSV(255, 0, 255 / dimmer_lighting));
                FastLED.show();                                           // Show a section of LED's
                delay(random8(4, 10));                                    // each flash only lasts 4-10 milliseconds
                fill_solid(leds + ledstart_lighting, length_lighting, CHSV(255, 0, 0));     // Clear the section of LED's
                FastLED.show();

                if (flashCounter == 0) delay (150);                       // longer delay until next flash after the leader

                delay(50 + random8(100));                                 // shorter delay between strokes
            }
        }
}

void FastLedEffects::lightingColored(int ledstart_lightingColored, int length_lightingColored, int flashes_lightingColored, int dimmer_lightingColored, int frequency_lightingColored, CRGB color, CRGB leds[]) {

        uint32_t convertedColor = FastLedEffects::CRGBToInt(color);
        uint8_t colBeat = FastLedEffects::getBeatSinColor(convertedColor);

        ledstart_lightingColored = random8(NUM_LEDS);                               // Determine starting location of flash
        length_lightingColored = random8(NUM_LEDS - ledstart_lightingColored);                      // Determine length of flash (not to go beyond NUM_LEDS-1)

        EVERY_N_MILLISECONDS(1000 / frequency_lightingColored) {
            for (int flashCounter = 0; flashCounter < random8(3, flashes_lightingColored); flashCounter++) {
                if (flashCounter == 0) dimmer_lightingColored = 5;                        // the brightness of the leader is scaled down by a factor of 5
                else dimmer_lightingColored = random8(1, 3);                              // return strokes are brighter than the leader

                fill_solid(leds + ledstart_lightingColored, length_lightingColored, CHSV(colBeat, 255, 255 / dimmer_lightingColored));
                FastLED.show();                                           // Show a section of LED's
                delay(random8(4, 10));                                    // each flash only lasts 4-10 milliseconds
                fill_solid(leds + ledstart_lightingColored, length_lightingColored, CHSV(255, 0, 0));     // Clear the section of LED's
                FastLED.show();

                if (flashCounter == 0) delay (150);                       // longer delay until next flash after the leader

                delay(50 + random8(100));                                 // shorter delay between strokes
            }
        }
}

void FastLedEffects::lightingPalette(int ledstart_lightingPalette, int length_lightingPalette, int flashes_lightingPalette, int dimmer_lightingPalette, int frequency_lightingPalette, CRGBPalette16 palette, CRGB leds[]) {
        ledstart_lightingPalette = random8(NUM_LEDS);                               // Determine starting location of flash
        length_lightingPalette = random8(NUM_LEDS - ledstart_lightingPalette);                      // Determine length of flash (not to go beyond NUM_LEDS-1)

        EVERY_N_MILLISECONDS(1000 / frequency_lightingPalette) {
            for (int flashCounter = 0; flashCounter < random8(3, flashes_lightingPalette); flashCounter++) {
                if (flashCounter == 0) dimmer_lightingPalette = 5;                        // the brightness of the leader is scaled down by a factor of 5
                else dimmer_lightingPalette = random8(1, 3);                              // return strokes are brighter than the leader

                fill_solid(leds + ledstart_lightingPalette, length_lightingPalette, ColorFromPalette(palette, random8(), 255, LINEARBLEND));
                FastLED.show();                                           // Show a section of LED's
                delay(random8(4, 10));                                    // each flash only lasts 4-10 milliseconds
                fill_solid(leds + ledstart_lightingPalette, length_lightingPalette, CHSV(255, 0, 0));     // Clear the section of LED's
                FastLED.show();

                if (flashCounter == 0) delay (150);                       // longer delay until next flash after the leader

                delay(50 + random8(100));                                 // shorter delay between strokes
            }
        }
}

// Link: https://github.com/marmilicious/FastLED_examples/blob/master/beat8.ino
void FastLedEffects::beat8_tail(uint8_t bpm_beat8_tail, int fade_beat8_tail, CRGB leds[]) {
    static uint8_t hueBeat = 0;
    EVERY_N_MILLISECONDS( 50 ) { hueBeat++; }

    EVERY_N_MILLISECONDS( 5 ) {
    fadeToBlackBy( leds, NUM_LEDS, fade_beat8_tail);  // Fade out pixels.
    }
    uint16_t pos = beat8(bpm_beat8_tail) % NUM_LEDS;  // modulo the position to be within NUM_LEDS
    leds[pos] = CHSV( hueBeat, 200, 255);

    FastLED.show();

}


void FastLedEffects::blendIntoRainbow(int tid_blendIntoRainbow, int tid2_blendIntoRainbow, CRGB leds[]) {

    EVERY_N_MILLISECONDS(tid_blendIntoRainbow){
        hue++;  //used to cycle through the rainbow
    }

    EVERY_N_MILLISECONDS(tid_blendIntoRainbow + 30) {
        pos++;
        if (pos == NUM_LEDS) { pos = 0; }  //reset to begining
    }

    EVERY_N_MILLISECONDS(tid2_blendIntoRainbow){
        hue2 = hue2 - 1;  //used to change the moving color
    }
    CRGB blendThisIn  = CHSV(hue2, 170, 255);  //color to blend into the background
    CRGB blendThisIn2 = CHSV(hue2, 200, 225);  //color to blend into the background
    CRGB blendThisIn3 = CHSV(hue2, 230, 200);  //color to blend into the background
    CRGB blendThisIn4 = CHSV(hue2, 255, 180);  //color to blend into the background

    static uint8_t blendAmount = 240;  //amount of blend  [range: 0-255]

    nblend(leds[pos],                  blendThisIn4, blendAmount/3);
    nblend(leds[mod8(pos+1,NUM_LEDS)], blendThisIn3, blendAmount/2);
    nblend(leds[mod8(pos+2,NUM_LEDS)], blendThisIn2, blendAmount);
    nblend(leds[mod8(pos+3,NUM_LEDS)], blendThisIn,  blendAmount);
    nblend(leds[mod8(pos+4,NUM_LEDS)], blendThisIn2, blendAmount);
    nblend(leds[mod8(pos+5,NUM_LEDS)], blendThisIn3, blendAmount/2);
    nblend(leds[mod8(pos+6,NUM_LEDS)], blendThisIn4, blendAmount/3);

    FastLED.show();  //update the display

}

void FastLedEffects::breatheV2(float pulseSp_breatheV2, CRGB leds[]) {
    pulseSpeed = pulseSp_breatheV2;
    float dV = ((exp(sin(pulseSpeed * millis()/2000.0*PI)) -0.36787944) * delta);
    val = valueMin + dV;
    hue = map(val, valueMin, valueMax, hueA, hueB);  // Map hue based on current val
    sat = map(val, valueMin, valueMax, satA, satB);  // Map sat based on current val

    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CHSV(hue, sat, val);

        // You can experiment with commenting out these dim8_video lines
        // to get a different sort of look.
        leds[i].r = dim8_video(leds[i].r);
        leds[i].g = dim8_video(leds[i].g);
        leds[i].b = dim8_video(leds[i].b);
    }

    FastLED.show();
}


void FastLedEffects::chaseTargetTalesVarA(int tid_chaseTargetTalesVarA, CRGB leds[]) {
    EVERY_N_MILLISECONDS(tid_chaseTargetTalesVarA) {
        // Assign random target values whenever count is zero.
        if (countOff == 0){
            for (int i=0; i < NUM_LEDS; i++){
            target[random8(NUM_LEDS)] = random8();  // Pick random pixels, assign random values.
            if (target[i] < lowCutoff){
                target[i] = 0;  // Force low values to clamp to zero.
            }
            }
            countOff = random8(35,70);  // Pick a new count value.
        }
        for (int i=0; i < NUM_LEDS; i++){
            
            // Check current values against target values.
            if (leds[i].r < target[i]){  // less then the target, so fade up.
            delta2 = (target[i] - leds[i].r) / 5;
            if (leds[i].r + delta2 >= target[i]){
                leds[i].r = target[i];  // limit to target.
            }
            else { leds[i].r += delta2; }
            }
            else {  // greater then the target, so fade down.
            delta2 = ((leds[i].r - target[i])/8) + 1;  // +1 so delta is always at least 1.
            if (leds[i].r - delta <= target[i]){
                leds[i].r = target[i];  // limit to target.
            }
            else { leds[i].r -= delta2; }
            }
            if (i == 0){ temp = delta2; }  // Save first pixel's delta number to print below.
            // Continously fade target to zero.
            if (target[i] > lowCutoff){
            target[i] -= 2;  // Fade by this ammount.
            }
            else { target[i] = 0; }  // If target is less then lowCutoff, clamp to zero.
        }//end of looping over pixels.
        FastLED.show();  // Display the leds[] array.
        countOff--;  // reduce count by one.
    }
}


void FastLedEffects::chaseTargetTalesVarB(int tid_chaseTargetTalesVarB, CRGB leds[]) {
    lowCutoff = 30;
    EVERY_N_MILLISECONDS(tid_chaseTargetTalesVarB) {
                // Assign random target values whenever count is zero.
        if (countOff == 0){
            for (int i=0; i < NUM_LEDS; i++){
            target[random8(NUM_LEDS)] = random8();  // Pick random pixels, assign random values.
            if (target[i] < lowCutoff){
                target[i] = 0;  // Force low values to clamp to zero.
            }
            }
            countOff = random8(35,70);  // Pick a new count value.
            Serial.println("*New targets assigned!*");
        }


        for (int i=0; i < NUM_LEDS; i++){
            // Check current values against target values.
            if (leds_vu[i].value < target[i]){  // less then the target, so fade up.
            delta = (leds_vu[i].value - target[i]) / 5;
            if (leds_vu[i].value + delta >= target[i]){
                leds_vu[i].value = target[i];  // limit to target.
            }
            else {
                leds_vu[i].value += delta;
            }
            }

            else {  // greater then the target, so fade down.
            delta = ((leds_vu[i].value - target[i])/8) + 1;  // +1 so delta is always at least 1.
            if (leds_vu[i].value - delta <= target[i]){
                leds_vu[i].value = target[i];  // limit to target.
            }
            else {
                leds_vu[i].value -= delta;
            }
            }
            if (i == 0){ temp = delta; }  // Save first pixel's delta number to print below.

            // Tweak hue color based on brightness.
            int c_hue = constrain(leds_vu[i].value,lowCutoff,highCutoff);
            leds_vu[i].hue = map(c_hue, lowCutoff, highCutoff, hue_low, hue_high);
                        // map(valueIn, fromLow,   fromHigh,   toLow,   toHigh)

            leds_vu[i].saturation = 255;  // Set saturation to full.

            // Copy the HSV leds_vu[] data to the leds[] array.
            leds[i] = leds_vu[i];
            // FastLED will automatically convert HSV to RGB data.  Converting from HSV
            // to RGB is very fast and also accurate.  It is possible to convert from
            // RGB to HSV, but it is not automatic, not totally acurate, and not as fast.

            // Continously fade target to zero.
            if (target[i] > lowCutoff){
            target[i] -= 2;  // Fade by this ammount.
            }
            else {
            target[i] = 0;  // If target less then lowCutoff, clamp to zero.
            }

        }//end of looping over pixels.
        
        FastLED.show();  // Display the leds[] array.
        countOff--;  // reduce count by one.
    }
}


void FastLedEffects::chaseTargetTalesVarC(int boilingTime_chaseTargetTalesVarC, int tid_chaseTargetTalesVarC, int fadeTime_chaseTargetTalesVarC, CRGB leds[]) {
    // Normal values : Boiling from 200 to 2000, fade was 70, smoothfading was 50
    hue_high = 0;  // red for high values with,
    hue_low = 96;  // green for low values.
    lowCutoff = 20;
    highCutoff = 230;
    // Assign new random target values after a bit.
  EVERY_N_MILLISECONDS(2000) {
    for (int i=0; i < ( NUM_LEDS / 2 ); i++){  // Only do about half the pixels.
      pixel = random8(NUM_LEDS);  // Pick random pixel.
      target[pixel] = random8();  // Assign random value.
      while (target[pixel] > 90 && target[pixel] < 160) {  // Avoid some middle values, pick again.
        target[pixel] = random8();  // Assign another random value.
      }
      if (target[pixel] < lowCutoff){
        target[pixel] = 0;  // Force low values to clamp to zero.
      }
    }
  }//end assign new target values


  EVERY_N_MILLISECONDS(tid_chaseTargetTalesVarC) {
    for (uint8_t i=0; i < NUM_LEDS; i++){
      // Check current values against target values.
      if (leds_vu[i].value < target[i]){  // less then the target, so fade up.
        delta = ((target[i] - leds_vu[i].value) / 8) + 1;
        if (leds_vu[i].value + delta >= target[i]){
          leds_vu[i].value = target[i];  // limit to target.
        }
        else {
          leds_vu[i].value = leds_vu[i].value + delta;
        }
      }
      else {  // greater then the target, so fade down.
        delta = ((leds_vu[i].value - target[i]) / 12) + 1;  // +1 so delta is always at least 1.
        if (leds_vu[i].value - delta <= target[i]){
          leds_vu[i].value = target[i];  // limit to target.
        }
        else {
          leds_vu[i].value = leds_vu[i].value - delta;
        }
      }
      if (i == 0){ temp = delta; }  // Save first pixel's delta to print below.
  
      // Tweak hue color based on brightness.
      int c_hue = constrain(leds_vu[i].value,lowCutoff,highCutoff);
      leds_vu[i].hue = map(c_hue, lowCutoff, highCutoff, hue_low, hue_high);
                    // map(valueIn, fromLow,   fromHigh,   toLow,   toHigh)

  
      // Set saturation.
      leds_vu[i].saturation = 255;
  
      // Copy the HSV leds_vu[] data to the leds[] array.
      leds[i] = leds_vu[i];
        // FastLED will automatically convert HSV to RGB data.  Converting from HSV
        // to RGB is very fast and also accurate.  It is also possible to convert from
        // RGB to HSV, but it is not automatic, not as acurate, and not as fast.
  
    }//end of looping over all the pixels checking targets.
  }//end EVERY_N*

  // Continuosly fade target to zero.
  EVERY_N_MILLISECONDS(fadeTime_chaseTargetTalesVarC) {
    for (int j=0; j < NUM_LEDS; j++){
      if (target[j] > lowCutoff){
        target[j] -= 1;  // Fade by this amount.
      }
      else {
        target[j] = 0;  // If target less then lowCutoff, clamp to zero.
      }
    }
  }//end of continuously fading target down.

  FastLED.show();  // Display the leds[] array.

  EVERY_N_SECONDS(20) {  // Pick a new color combination choice (ccc).
    ccc =  random(4);
    if (ccc == 0) {
      hue_high = 0;  // red for high values
      hue_low = 96;  // green for low values
    }
    if (ccc == 1) {
      hue_high = 96;  // green for high values
      hue_low = 192;  // purple for low values
    }
    if (ccc == 2) {
      hue_high = 105;  // green for high values
      hue_low = 15;  // red for low values
    }
    if (ccc == 3) {
      hue_high = 82;  // yellow-green for high values
      hue_low = 140;  // aqua for low values
    }
  }//end EVERY_N* ccc

}


void FastLedEffects::everyNTimerVariables(uint16_t timerA_everyNTimerVariables, uint16_t timerB_everyNTimerVariables, CRGB leds[]) {
    // TimerA roughly 3000 and timerB 500
    // Setting the amount of time for "triggerTimer".
  // You can name "triggerTimer" whatever you want.
  static CEveryNMilliseconds triggerTimer(timerB_everyNTimerVariables);
  
  EVERY_N_MILLISECONDS(timerA_everyNTimerVariables){
    // do Event A stuff
    fill_solid(leds, NUM_LEDS, CHSV(random8(),255,128));
    counterTriggered = 1;  // Set to True
    triggerTimer.reset();  // Start trigger timer
  }
  
  if (counterTriggered == 1) {  // Will only be True if Event A has started
    if (triggerTimer) {  // Check if triggerTimer time reached
      // do Event B stuff
      for (uint8_t i=0; i<NUM_LEDS/2; i++){
        leds[random8(NUM_LEDS)] = CRGB::Red;
      }
      counterTriggered = 0;  // Set back to False
    }
  }
    EVERY_N_SECONDS_I( timingObj, 20) {
        // This initally defaults to 20 seconds, but then will change the run
        // period to a new random number of seconds from 10 and 30 seconds.
        // You can name "timingObj" whatever you want.
        timingObj.setPeriod( random8(10,31) );
        FastLED.clear();
        for (uint16_t i=0; i<NUM_LEDS*3; i++){
        leds[random8(NUM_LEDS)] = CRGB::Black;
        leds[random8(NUM_LEDS)] = CHSV(random8(), random8(140,255), random8(50,255));
        FastLED.show();
        delay(random8(20,80));
        }
    }

  FastLED.show();
}


void FastLedEffects::fillUpStrip(CRGB leds[]) {
    // Draw the moving pixels.
    for (int i=0; i < (NUM_LEDS - countOff); i++){
        leds[i] = CHSV(hue,sat,255);
        FastLED.show();
        delay(fill_delay);  // Slow things down just a bit.
        leds[i] = CRGB::Black;
    }

    // Add the new filled pixels.
    leds[NUM_LEDS - 1 - countOff] = CHSV(hue,sat,255);
    FastLED.show();
    countOff++;

    // Delay the filling effect to slow near end.
    delta = (pow(delay_base, countOff) * delay_multiplier);  // Delta increases as strip fills up.
    delay(delta);  // Delay can increase as strip fills up.
    // Uncomment to help visualize the increasing delay.
    //Serial.print("  count:"); Serial.print(count); Serial.print("    delta: "); Serial.println(delta);


    // Clear the strip when full.
    if (countOff == NUM_LEDS){
        delay(1400);             // Hold filled strip for a moment.
        FastLED.clear();         // Blank out the strip data.
        FastLED.show();
        countOff = 0;               // Reset count.
        hue = random8();         // Pick a new random fill color.
        sat = random8(160,255);  // Pick a random saturation in range.
        delay(700);              // Breif pause before filling again.
    }
}


void FastLedEffects::heartBeat2(uint16_t beat_speed_heartBeat2, uint8_t dub_offset_heartBeat2, CRGB leds[]) {
    // Beat_speed supposed to be 1100
    // Dub_offset supposed to be 180
    // Lubs
  static boolean lubbing = 0;
  EVERY_N_MILLISECONDS_I( timingLubs, 1) {
    lubbing = !lubbing;
    if (lubbing) {
      timingLubs.setPeriod(dub_offset_heartBeat2);  // time to hold before fading
      for (int i = 0; i < 8; i++) {
          leds[i] = lubs_color;
      }
    } else {
      timingLubs.setPeriod(beat_speed_heartBeat2);
    }
  }
  if (lubbing == 0) {
    EVERY_N_MILLISECONDS(10) {
        for (int i = 0; i < NUM_LEDS/2; i++) {
          leds[i].fadeToBlackBy(25);
      }
    }
  }

  // Dubs
  static boolean dubbing = 0;
  EVERY_N_MILLISECONDS_I( timingDubs, dub_offset_heartBeat2) {
    dubbing = !dubbing;
    if (dubbing) {
      timingDubs.setPeriod(dub_offset_heartBeat2);  // time to hold before fading
      for (int i = NUM_LEDS/2; i < NUM_LEDS; i++) {
          leds[i] = dubs_color;
      }
    } else {
      timingDubs.setPeriod(beat_speed_heartBeat2);
    }
  }
  if (dubbing == 0) {
    EVERY_N_MILLISECONDS(7) {
        for (int i = NUM_LEDS/2; i < NUM_LEDS; i++) {
          leds[i].fadeToBlackBy(15);
      }
    }
  }
  FastLED.show();

}

void FastLedEffects::heartBeat3(bool rainbow_heartBeat3, CRGB leds[]) {

    static boolean lubRunning = 0;  // Is lub running? [1=true/0=false]
    static boolean dubRunning = 0;  // Is dub running? [1=true/0=false]
    static boolean dubTrigger = 0;  // Is dub triggered? [1=true/0=false]
    static CEveryNMilliseconds dubTimer(DUB_DELAY);  // Create timer for dub delay
    static uint8_t lubValue, dubValue;

    //---------------------------------
    // Regularly fade out the heart beat pixels
    EVERY_N_MILLISECONDS(5) {  // How often to do the fade
        for (int i = 0; i < NUM_LEDS; i++) {
            leds[i].fadeToBlackBy(25);
        }
    }

    //---------------------------------
    // Timing of heart beat
    EVERY_N_MILLISECONDS(LUB_TIME) {
        lubRunning = 1;
        lubValue = 20;  // Starting value when ramping up [Use 1 or greater]
        dubTrigger = 1;
        dubTimer.reset();  // Reset dub timer
    }
    if (dubTrigger && dubTimer) {
        dubRunning = 1;
        dubValue = 1; // Starting value when ramping up [Use 1 or greater]
        dubTrigger = 0;  // Reset trigger
    }

    //---------------------------------
    // Assign pixel data
    if(lubRunning) {
        EVERY_N_MILLISECONDS(7) {
        lubValue = brighten8_video(lubValue);
        }
        for (int i = 0; i < 8; i++) {
          leds[i] = CHSV(beatHue,255,lubValue);
        }
        if (lubValue >= 250) {
        lubRunning = 0;  // Reset
        }
    }

    if(dubRunning) {
        EVERY_N_MILLISECONDS(7) {
        dubValue = brighten8_video(dubValue);
        }
        for (int i = NUM_LEDS/2; i < NUM_LEDS; i++) {
          leds[i] = CHSV(beatHue,255,dubValue);
        }
        if (dubValue >= 250) {
        dubRunning = 0;  // Reset
        }
    }

    //---------------------------------
    // Just for fun... Uncomment for rainbow heart beats!
    EVERY_N_MILLISECONDS(DUB_DELAY) {
        if(rainbow_heartBeat3)
            beatHue = beatHue + random8(32,65);
    }
    FastLED.show();
}

void FastLedEffects::heartPulseBloodFlowing(CRGB leds[]) {
    for (int i = 0; i < NUM_LEDS ; i++) {
    uint8_t bloodVal = sumPulse( (5/NUM_LEDS/2) + (NUM_LEDS/2) * i * flowDirection );
    leds[i] = CHSV( bloodHue, bloodSat, bloodVal );
  }
  FastLED.show();
}

void FastLedEffects::lighthouseBeaconV2(int length_lighthouseBeaconV2, int tid_lighthouseBeaconV2, int fade_lighthouseBeaconV2, CRGB leds[]) {
    sat = 190;
    hue = 42;
    EVERY_N_MILLISECONDS(tid_lighthouseBeaconV2) {  // wait a bit before micro advancing
    if (delta > 0) {
      pixelPos += deltaInt;
    } else {
      pixelPos = (pixelPos + deltaInt + (NUM_LEDS * 16)) % (NUM_LEDS * 16);
    }

    if( pixelPos >= (NUM_LEDS * 16)) {
      pixelPos -= (NUM_LEDS * 16);
    }

    static byte countdown = 0;
    if( countdown == 0) { countdown = 16; } // reset countdown
    countdown -= 1;  // decrement once each time through

    memset8( leds, 0, NUM_LEDS * sizeof(CRGB));  // Clear the pixel buffer
    drawFractionalBar( pixelPos, length_lighthouseBeaconV2, hue, fade_lighthouseBeaconV2, leds);  // Draw the pixels
  }

  FastLED.show();  // Show the pixels

}

void FastLedEffects::matchingGlitter1(CRGB leds[]) {
        EVERY_N_MILLISECONDS(20) {
        hue++;  // slowly cycle around the color wheel
    }
    EVERY_N_MILLISECONDS(80) {
        fill_solid(leds, NUM_LEDS, CHSV(hue, 175, 140) );

            if( random8() < 99) {
            leds[ random16(NUM_LEDS) ] += CHSV(hue,255,255);
        }
    }
    FastLED.show();
}

void FastLedEffects::matchingGlitter2(CRGB leds[]) {
        EVERY_N_MILLISECONDS(20) {
        hue++;  // slowly cycle around the color wheel
    }
    EVERY_N_MILLISECONDS(80) {
        fill_solid(leds, NUM_LEDS, CHSV(hue, 175, 140) );

            if( random8() < 99) {
                leds[ random16(NUM_LEDS) ].maximizeBrightness(255);
            }
    }
    FastLED.show();
}

void FastLedEffects::matchingGlitter3(bool second_matchingGlitter3, bool third_matchingGlitter3, CRGB leds[]) {
        EVERY_N_MILLISECONDS(20) {
        hue++;  // slowly cycle around the color wheel
    }
    EVERY_N_MILLISECONDS(80) {
        fill_solid(leds, NUM_LEDS, CHSV(hue, 175, 140) );

            if( random8() < 99) {
                uint16_t i = random16(NUM_LEDS);
                CRGB color = leds[i];
                leds[i] += color.nscale8_video(255);
                // Can apply a second or third time for even brighter effect
                if (second_matchingGlitter3)
                    leds[i] += color.nscale8_video(255);
                if (third_matchingGlitter3)
                    leds[i] += color.nscale8_video(255);
            }
    }
    FastLED.show();
}

void FastLedEffects::matchingGlitter4(bool more_matchingGlitter4, CRGB leds[]) {
        EVERY_N_MILLISECONDS(20) {
        hue++;  // slowly cycle around the color wheel
    }
    EVERY_N_MILLISECONDS(80) {
        fill_solid(leds, NUM_LEDS, CHSV(hue, 175, 140) );

            if( random8() < 99) {
                uint16_t i = random16(NUM_LEDS);
                leds[i].r = brighten8_video(leds[i].r);
                leds[i].g = brighten8_video(leds[i].g);
                leds[i].b = brighten8_video(leds[i].b);
                // Can apply a second time for even brigter effect
                if (more_matchingGlitter4) {
                    leds[i].r = brighten8_video(leds[i].r);
                    leds[i].g = brighten8_video(leds[i].g);
                    leds[i].b = brighten8_video(leds[i].b);
                }
                
            }
    }
    FastLED.show();
}

void FastLedEffects::mirrorFadeEnds(int fade_mirrorFadeEnds, CRGB leds[]) {
    // It's not the best effect of the list but jebiga
    // Here fadeOver is 7 as a base

    fill_rainbow( leds, NUM_LEDS / 2, (millis() / 50) );

    for (uint8_t i = 0; i < NUM_LEDS / 2; i++) {
        leds[NUM_LEDS - 1 - i] = leds[i];
    }

    uint8_t fadePP = 255 / fade_mirrorFadeEnds;  // fade per pixel
    for (uint8_t i = 0; i < fade_mirrorFadeEnds + 1; i++) {
        uint8_t fadeAmmount = (255 - (fadePP * i));
        leds[i].fadeToBlackBy(fadeAmmount);
        leds[NUM_LEDS - 1 - i].fadeToBlackBy(fadeAmmount);
    }

    // update the display
    FastLED.show();
}

void FastLedEffects::Fire2012(int tid_Fire2012, int cooling_Fire2012, int sparking_Fire2012, CRGB leds[]) {
  // cooling is 90, sparking 50, and time around 15 I think
  EVERY_N_MILLISECONDS(tid_Fire2012) {
    // Array of temperature readings at each simulation cell
    static byte heat[NUM_LEDS];
    // Step 1.  Cool down every cell a little
    for( int i = 0; i < NUM_LEDS; i++) {
        heat[i] = qsub8( heat[i],  random8(0, ((cooling_Fire2012 * 10) / (NUM_LEDS)) + 2));
    }
    // Step 2.  Heat from each cell drifts 'up' and diffuses a little
    for( int k= (NUM_LEDS) - 1; k >= 2; k--) {
        heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
    }
    // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
    if( random8() < sparking_Fire2012 ) {
        int y = random8(7);
        heat[y] = qadd8( heat[y], random8(160,255) );
    }
    // Step 4.  Map from heat cells to LED colors
    for( int j = 0; j < NUM_LEDS; j++) {
        CRGB color = HeatColor( heat[j]);
        leds[j] = color;
    }
    FastLED.show(); // display leds
  }
}

void FastLedEffects::Fire2012_halfStrip(int tid_Fire2012_halfStrip, int cooling_Fire2012_halfStrip, int sparking_Fire2012_halfStrip, bool gReverseDirection_Fire2012_halfStrip, CRGB leds[]) {
  // cooling is 90, sparking 50, and time around 15 I think
  EVERY_N_MILLISECONDS(tid_Fire2012_halfStrip) {
    // Array of temperature readings at each simulation cell
    static byte heat[NUM_LEDS/2];
    // Step 1.  Cool down every cell a little
    for( int i = 0; i < NUM_LEDS/2; i++) {
        heat[i] = qsub8( heat[i],  random8(0, ((cooling_Fire2012_halfStrip * 10) / (NUM_LEDS/2)) + 2));
    }
    // Step 2.  Heat from each cell drifts 'up' and diffuses a little
    for( int k= (NUM_LEDS/2) - 1; k >= 2; k--) {
        heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
    }
    // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
    if( random8() < sparking_Fire2012_halfStrip ) {
        int y = random8(7);
        heat[y] = qadd8( heat[y], random8(160,255) );
    }
    // Step 4.  Map from heat cells to LED colors
    for( int j = 0; j < NUM_LEDS/2; j++) {
        CRGB color = HeatColor( heat[j]);
        leds[j] = color;
    }

        if (gReverseDirection_Fire2012_halfStrip == false) {  //false is center outward
        for (uint8_t i=0; i<NUM_LEDS/2; i++) {
        leds[(NUM_LEDS/2)-1-i] = leds[i];
        leds[(NUM_LEDS/2)+i] = leds[i];
        }

    } else {  //true is from ends inward
        for (uint8_t i=0; i<NUM_LEDS/2; i++) {
        leds[i] = leds[i];
        leds[(NUM_LEDS-1)-i] = leds[i];
        }
    }
    FastLED.show(); // display leds
  }
}
 

void FastLedEffects::movingColoredBar(CRGBPalette16 palette, CRGB leds[], int length_movingColoredBar, uint8_t frameDelay_movingColoredBar) {
    // Adjust framde delay if you want it to be more frequent
    int numberofColors = sizeof(palette)/sizeof(long);
    EVERY_N_MILLISECONDS(frameDelay_movingColoredBar) {
        // move current pixel data over one position
        for (uint16_t x = 0; x < NUM_LEDS-1; x++)
        {
        leds[x] = leds[x+1];
        }
        // assign new data at end of line
        leds[NUM_LEDS-1] = palette[paletteIndexmcb];
        barPosition++;
        // check and reset things as needed
        if ( (barPosition > length_movingColoredBar) && (paletteIndexmcb == numberofColors-1) )
        {
        barPosition = 1;
        //Serial.println("  barPosition reset");
        paletteIndexmcb = 0;
        //Serial.println("  paletteIndex reset");
        }
        else if (barPosition > length_movingColoredBar)
        {
        barPosition = 1;
        //Serial.println("  barPosition reset");
        paletteIndexmcb = paletteIndexmcb + 1;
        }
    }//end_EVERY_N
  FastLED.show();
}

void FastLedEffects::repeatingPattern(int tid_repeatingPattern, int tid2_repeatingPattern, int fade_repeatingPattern, CRGB leds[]) {
    // Time1 is 50 usually nd time2 is 1000, fade is 7

    EVERY_N_MILLISECONDS(tid_repeatingPattern) {
    fadeToBlackBy( leds, NUM_LEDS, fade_repeatingPattern);  // slowly fade out pixels
  }

  EVERY_N_MILLISECONDS(tid2_repeatingPattern) {
    static uint8_t hueOffset;
    static uint8_t hueShift;
    
    //hue = ((255 / repeatEvery) * hueOffset) + hueShift;  // Change the hue for each pixel set.
    hue = (20 * hueOffset) + hueShift;  // Change the hue for each pixel set.
    
    for (uint16_t x = 0; x < numberOfRepeats + 1; x++) {
      static uint16_t i;
      i = (repeatEvery * (x - 1)) + repeatEvery + hueOffset;  // The pixel number to draw
      if (i < NUM_LEDS) {  // Only draw pixel numbers within NUM_LEDS
        leds[i] = CHSV(hue,180,255);
      }
    }

    hueOffset++;
    if (hueOffset == repeatEvery) {
      hueOffset = 0;
      hueShift = hueShift + random8(55,77);
    }

  } //end_every_n

  FastLED.show();  // Display all pixels in a set at the same time.

}

void FastLedEffects::savedPixel(int tid_savedPixel, int tid2_savedPixel,  CRGB leds[]) {
  // tid2 should be 8
    EVERY_N_MILLISECONDS_I(timingObj, tid_savedPixel) {
    uint8_t n = random8(1,5);
    for (uint8_t i = 0; i < n; i++) {    
      uint8_t p = random8(NUM_LEDS);
      if (leds[p] == CRGB(0,0,0)) {
        pData[p] = CRGB(random8(), random8(0,150), 1);  // These r,g,b channels will actually store hue, sat, val
      }
    }
    timingObj.setPeriod(random16(150,600));  // random time to display next new pixel
  }

  EVERY_N_MILLISECONDS(tid2_savedPixel) {
    for (uint8_t i = 0; i < NUM_LEDS; i++) {
      if (pData[i]) {  // true if there is data

        if ((pData[i].b % 2 == 0) && (pData[i].b >= 2)) {  // even so decrease
          pData[i].b = pData[i].b - 2;  // darken pixel
        } else {  // odd so increase
          pData[i].b = pData[i].b + 2;  // brighten pixel
        }

        if (pData[i].b == 0) {  // if true reset some data to zero
          pData[i].r = 0;
          pData[i].g = 0;
        }

        if (pData[i].b == 255) {  // then switch to val to an even number so brightness will go down
          pData[i].b = 254;
        }

        sat = map(pData[i].b, 0, 255, pData[i].g, 170);  // desaturate some
        leds[i] = CHSV(pData[i].r, sat, pData[i].b);  // copy data to leds to be displayed
      }
    }

    FastLED.show();
  }

}

void FastLedEffects::sinCosLinear(CRGB leds[]) {

    //====run forward direction====
  for (potValue = 0; potValue < 255; potValue++) {
    sin_output = sin8(potValue);
    cos_output = cos8(potValue);

    for (uint8_t j = 0; j < 3; j++) {
      leds[j] = CHSV(sin_output, 255, 255);
    }
    for (uint8_t j = 3; j < 7; j++) {
      leds[j] = CHSV(cos_output, 255, 255);
    }
    for (uint8_t j = 7; j < 10; j++) {
      leds[j] = CHSV(potValue, 255, 255);
    }

    FastLED.show();
    Serial.print("  potValue = "); Serial.print(potValue);
    Serial.print("\tsin8: "); Serial.print(sin_output);
    Serial.print("\tcos8: "); Serial.println(cos_output);

    //Blink pixel 7 white as a visual to show loop ends.
    if (potValue == 0) {
      leds[7] = CHSV(0,0,64);
    }
    else {
      leds[7] = CRGB::Black;
    }

    delay(slowBy);
  }

  //====run reverse direction====
  for (potValue = 255; potValue > 0; potValue--) {
    sin_output = sin8(potValue);
    cos_output = cos8(potValue);

    for (uint8_t j = 0; j < 2; j++) {
      leds[j] = CHSV(sin_output, 255, 255);
    }
    for (uint8_t j = 2; j < 4; j++) {
      leds[j] = CHSV(cos_output, 255, 255);
    }
    for (uint8_t j = 4; j < 6; j++) {
      leds[j] = CHSV(potValue, 255, 255);
    }
    FastLED.show();
    //Blink pixel 7 white as a visual to show loop ends.
    if (potValue == 255) {
      leds[7] = CHSV(0,0,64);
    }
    else {
      leds[7] = CRGB::Black;
    }
    delay(slowBy);
  }

}

void FastLedEffects::sparkles(CRGB leds[], int sparkel_duration_sparkles, int sparkel_amount_sparkles, int sparkel_spread_sparkles) {

     static uint8_t sparkle_pixel;
    EVERY_N_MILLISECONDS_I( timingObj, 1) {
        timingObj.setPeriod(sparkel_duration_sparkles);
        leds[sparkle_pixel] = CRGB::Black;
        uint8_t previous_pixel = sparkle_pixel;
        while (previous_pixel == sparkle_pixel) {  // pixel can't repeat
        sparkle_pixel = random8(NUM_LEDS);
        }
        if (random8(100) < sparkel_amount_sparkles) {
        //leds[sparkle_pixel] = CRGB(random8(), random8(), random8());
        leds[sparkle_pixel] = CHSV(random8(), random8(20,200), random8(50,255));
        }
    }
    EVERY_N_MILLISECONDS(10) {
        //fadeToBlackBy(leds, NUM_LEDS, 1);  // fade out a bit over time
        blur1d(leds, NUM_LEDS, sparkel_spread_sparkles);  // spreads and fades out color over time
    }

    FastLED.show();
}


//+---------------------------------------------------------------------------------
// 
// Utility functions
//
//+---------------------------------------------------------------------------------
uint32_t FastLedEffects::CRGBToInt(const CRGB& color) {
    return (static_cast<uint32_t>(color.r) << 16) |
           (static_cast<uint32_t>(color.g) << 8)  |
           static_cast<uint32_t>(color.b);
}

uint8_t FastLedEffects::getBeatSinColor(uint32_t Color) {
    uint8_t colBeat;
    switch (Color) {
        case CRGB::Red:
            colBeat = beatsin8(45, 200, 255, 0, 0);
            break;
        case CRGB::Green:
            colBeat = beatsin8(45, 80, 128, 255, 0);
            break;
        case CRGB::Blue:
            colBeat = beatsin8(45, 128, 176, 0, 255);
            break;
        case CRGB::Yellow:
            colBeat = beatsin8(45, 48, 70, 0, 255);
            break;
        case CRGB::Orange:
            colBeat = beatsin8(45, 16, 48, 0, 255);
            break;
        case CRGB::Purple:
            colBeat = beatsin8(45, 192, 224, 0, 255);
            break;
        case CRGB::Aqua:
            colBeat = beatsin8(45, 112, 144, 0, 255);
            break;
        default:
            colBeat = beatsin8(45, 0, 255, 0, 255);
            break;
    }
    return colBeat;
}

std::vector<uint8_t> FastLedEffects::getArrayRangeValue(uint32_t Color) {
    std::vector<uint8_t> arrayOfRanges;
    switch (Color) {
        case CRGB::Red:
            arrayOfRanges = {200, 255};
            break;
        case CRGB::Green:
            arrayOfRanges = {80, 128};
            break;
        case CRGB::Blue:
            arrayOfRanges = {128, 176};
            break;
        case CRGB::Yellow:
            arrayOfRanges = {48, 70};
            break;
        case CRGB::Orange:
            arrayOfRanges = {16, 48};
            break;
        case CRGB::Purple:
            arrayOfRanges = {192, 224};
            break;
        case CRGB::Aqua:
            arrayOfRanges = {112, 144};
            break;
        default:
            arrayOfRanges = {0, 255};
            break;
    }
    return arrayOfRanges;
}


// Pixel drawing functions -- Hard time to really use it. To see later if needed for improvment.
// Here is the link of the video : https://www.youtube.com/watch?v=RF7GekbNmjU&list=PLF2KJ6Gy3cZ7ynsp8s4tnqEFmY15CKhmH&index=8
// Comment : might be overwhelming for the controller

CRGB ColorFraction(CRGB colorIn, float fraction) {
  fraction = min(1.0f, fraction);
  return CRGB(colorIn).fadeToBlackBy(255 * (1.0f - fraction));
}


void FastLedEffects::DrawPixels(float fPos, float count, CRGB color) {
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
}

void DrawMarqueeComparison() {
    FastLED.clear();
    EVERY_N_MILLISECONDS(20) {
        static float scroll = 0.0f;
        scroll += 0.1f;
        if (scroll > 5.0)
            scroll -= 5.0;

        for (float i = scroll; i < NUM_LEDS/2 ; i+= 5)
        {
            FastLedEffects::DrawPixels(i, 3, CRGB::Green);
            FastLedEffects::DrawPixels(NUM_LEDS-1-(int)i, 3, CRGB::Red);
        }    
    }
    FastLED.show();

}

// Function to convert CHSV to CRGB
CRGB FastLedEffects::hsvToRgb(const CHSV& hsv) {
    uint8_t region, remainder, p, q, t;
    uint16_t h, s, v;

    if (hsv.saturation == 0) {
        // Achromatic (grey)
        return CRGB(hsv.value, hsv.value, hsv.value);
    }

    h = hsv.hue;
    s = hsv.saturation;
    v = hsv.value;

    region = h / 43;
    remainder = (h - (region * 43)) * 6; 

    p = (v * (255 - s)) >> 8;
    q = (v * (255 - ((s * remainder) >> 8))) >> 8;
    t = (v * (255 - ((s * (255 - remainder)) >> 8))) >> 8;

    switch (region) {
        case 0:
            return CRGB(v, t, p);
        case 1:
            return CRGB(q, v, p);
        case 2:
            return CRGB(p, v, t);
        case 3:
            return CRGB(p, q, v);
        case 4:
            return CRGB(t, p, v);
        default:
            return CRGB(v, p, q);
    }
}

int FastLedEffects::sumPulse(int time_shift) {
  //time_shift = 0;  //Uncomment to heart beat/pulse all LEDs together
  int pulse1 = pulseWave8( millis() + time_shift, cycleLength, pulseLength );
  int pulse2 = pulseWave8( millis() + time_shift + pulseOffset, cycleLength, pulseLength );
  return qadd8( pulse1, pulse2 );  // Add pulses together without overflow
}

uint8_t FastLedEffects::pulseWave8(uint32_t ms, uint16_t cycleLength, uint16_t pulseLength) {
  uint16_t T = ms % cycleLength;
  if ( T > pulseLength) return baseBrightness;
  uint16_t halfPulse = pulseLength / 2;
  if (T <= halfPulse ) {
    return (T * 255) / halfPulse;  //first half = going up
  } else {
    return((pulseLength - T) * 255) / halfPulse;  //second half = going down
  }
}

// Fractional bar funtion
void FastLedEffects::drawFractionalBar( int pos16, int width, uint8_t hue, uint8_t fadeRate, CRGB leds[])
{
  int i = pos16 / 16; // convert from pos to raw pixel number
  uint8_t frac = pos16 & 0x0F; // extract the 'factional' part of the position
  uint8_t firstpixelbrightness = 255 - (frac * 16);
  uint8_t lastpixelbrightness  = 255 - firstpixelbrightness;
  uint8_t bright;
  for( uint8_t n = 0; n <= width; n++) {
    if( n == 0) {
      bright = firstpixelbrightness;  // first pixel in the bar
      leds[i] += CHSV( hue, sat, bright);
    }
    else if (n == width) {
      bright = lastpixelbrightness;  // last pixel in the bar
      leds[i] += CHSV( hue, sat, bright);
      fadeToBlackBy( leds, NUM_LEDS, fadeRate );  // creates outward fade
    }
    else {
      bright = 255;  // center pixel always max bright
      leds[i] += CHSV( hue, sat, bright);
    }
    i++;
    if( i == NUM_LEDS) i = 0; // wrap around
  }
}