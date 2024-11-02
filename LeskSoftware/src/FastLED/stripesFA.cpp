#include "stripesFA.h"
#include "const.h"
#include <iostream>
#include <FastLED.h>



// Here I have hard time to fetch a value from .xml and to make it a constant
// So I will leave it like this and we'll see what happens
// It breaks the idea of fetching information from a .xml file
// But let's go from the idea of us having 2 stripes with 10 colors
// The first one is connected to pin 18
// The second one is connected to pin 23
CRGB leds[NUM_LEDS];

// Constructor 1 color
StripesFA::StripesFA(int _port, int _length, int _direction, int _speed, int _effect, CRGB _color)
 : port(_port), length(_length), direction(_direction), speed(_speed), effectClassLvl(_effect), color1(_color)  {
    // This is a way to instantiate different stripes here
    // Not the smartest but let's take it for now
    this->setup(_port, _length);
    FastLED.setMaxRefreshRate(60);  // Limit to 60 frames per second


}

// Constructor 2 colors
StripesFA::StripesFA(int _port, int _length, int _direction, int _speed, int _effect, CRGB _color1, CRGB _color2)
 : port(_port), length(_length), direction(_direction), speed(_speed), effectClassLvl(_effect), color1(_color1), color2(_color2) {
    // This is a way to instantiate different stripes here
    // Not the smartest but let's take it for now
    this->setup(_port, _length);
    FastLED.setMaxRefreshRate(60);  // Limit to 60 frames per second

}

// Constructor 3 colors
StripesFA::StripesFA(int _port, int _length, int _direction, int _speed, int _effect, CRGB _color1, CRGB _color2, CRGB _color3)
 : port(_port), length(_length), direction(_direction), speed(_speed), effectClassLvl(_effect), color1(_color1), color2(_color2), color3(_color3) {
    // This is a way to instantiate different stripes here
    // Not the smartest but let's take it for now
    this->setup(_port, _length);
    FastLED.setMaxRefreshRate(60);  // Limit to 60 frames per second

}


void StripesFA::setup(int port, int _length) {

    if (port == DATA_PIN_1) {
    FastLED.addLeds<WS2812B, DATA_PIN_1, GRB>(leds, _length);
    this->fastleds = FastLED;
    } else if (port == DATA_PIN_2) {
    FastLED.addLeds<WS2812B, DATA_PIN_2, GRB>(leds, _length);
    this->fastleds = FastLED;
    }
    Serial.print("Test what effect we have: ");
    Serial.println(Settings::getEffect());
    this->setEffect(Settings::getEffect());
    FastLED.setBrightness(100);
    FastLED.show();
}


void StripesFA::setEffect(int effect) {
    // This system of switching effect seems good for now
    // I just need to get a lot of function and to define them
    // in the listeffects.h file
    
    switch(effect) {
    case 1:
        FastLedEffects::fill(Settings::getColor(), leds);
        effect = 1;
        effectClassLvl = effect-1;
        break;
    case 2:
        FastLedEffects::blink(Settings::getColor(), leds, Settings::getVar0to1000_1());
        effect = 2;
        effectClassLvl = effect-1;
        break;
    case 3:
        FastLedEffects::rainbowStatic(leds);
        effect = 3;
        effectClassLvl = effect-1;
        break;
    case 4:
        FastLedEffects::fillGradientTwoColors(Settings::getColor(), Settings::getColor2(), leds);
        effect = 4;
        effectClassLvl = effect-1;
        break;
    case 5:
        FastLedEffects::fillGradientThreeColors(Settings::getColor(), Settings::getColor2(),  Settings::getColor3(), leds);
        effect = 5;
        effectClassLvl = effect-1;
        break;
    case 6:
        FastLedEffects::backAndForthNoSmoothOneDot(Settings::getColor(), leds, Settings::getVar0to500_1());
        effect = 6;
        effectClassLvl = effect-1;
        break;
    case 7:
        FastLedEffects::backAndForthNoSmoothLengthedDot(Settings::getColor(), leds, Settings::getVar0to500_1(), Settings::getVar0to10_1());
        effect = 7;
        effectClassLvl = effect-1;
        break;
    case 8:
        FastLedEffects::hueFading(Settings::getVar0to500_1(), leds);
        effect = 8;
        effectClassLvl = effect-1;
        break;
    case 9:
        FastLedEffects::hueWhiteWave(Settings::getVar0to255_1(), Settings::getVar0to500_1(), leds);
        effect = 9;
        effectClassLvl = effect-1;
        break;
    case 10:
        FastLedEffects::displayPaletteLinear(Settings::getColor(), leds);
        effect = 10;
        effectClassLvl = effect-1;
        break;
    case 11:
        FastLedEffects::movingPaletteLinear(Settings::getColor(), Settings::getVar0to200_1(), leds);
        effect = 11;
        effectClassLvl = effect-1;
        break;
    case 12:
        FastLedEffects::spotlightingPalette(Settings::getColor(), Settings::getVar0to200_1(), Settings::getVar0to128_1(), leds);
        effect = 12;
        effectClassLvl = effect-1;
        break;
    case 13:
        FastLedEffects::sinBeat8(Settings::getColor(), Settings::getVar0to128_1(), Settings::getVar0to140_1(), leds);
        effect = 13;
        effectClassLvl = effect-1;
        break;
    case 14:
        FastLedEffects::sinBeat8PhaseOff(Settings::getColor(), Settings::getVar0to128_1(), Settings::getVar0to140_1(), Settings::getVar0to128_2(), leds);
        effect = 14;
        effectClassLvl = effect-1;
        break;
    case 15:
        FastLedEffects::sinBeat8TimeOff(Settings::getColor(), Settings::getVar0to128_1(), Settings::getVar0to140_1(), Settings::getVar0to500_1(), leds);
        effect = 15;
        effectClassLvl = effect-1;
        break;
    case 16:
        FastLedEffects::twoSinBeat8(Settings::getColor(), Settings::getColor2(), Settings::getVar0to128_1(), Settings::getVar0to140_1(), leds);
        effect = 16;
        effectClassLvl = effect-1;
        break;
    case 17:
        FastLedEffects::threeSinBeat8(Settings::getColor(), Settings::getColor2(), Settings::getColor3(), Settings::getVar0to128_1(), Settings::getVar0to140_1(), leds);
        effect = 17;
        effectClassLvl = effect-1;
        break;
    case 18:
        FastLedEffects::brightnessSinBeat8Palette(Settings::getColor(), Settings::getVar0to140_1(), Settings::getVar0to500_1(), leds);
        effect = 18;
        effectClassLvl = effect-1;
        break;
    case 19:
        FastLedEffects::funkyRainbowSinBeat8(Settings::getVar0to128_1(), leds);
        effect = 19;
        effectClassLvl = effect-1;
        break;
    case 20:
        FastLedEffects::funkyRangeSinBeat8(Settings::getVar0to128_1(), Settings::getColor(), leds);
        effect = 20;
        effectClassLvl = effect-1;
        break;
    case 21:
        FastLedEffects::funkyRainbowSinBeat8Two(Settings::getVar0to128_1(), leds);
        effect = 21;
        effectClassLvl = effect-1;
        break;
    case 22:
        FastLedEffects::funkyRangeSinBeat8Two(Settings::getVar0to128_1(), Settings::getColor(), leds);
        effect = 22;
        effectClassLvl = effect-1;
        break;
    case 23:
        FastLedEffects::movingFunkyPalette(Settings::getColor(), Settings::getVar0to140_1(), Settings::getVar0to140_2(), leds);
        effect = 23;
        effectClassLvl = effect-1;
        break;
    case 24:
        FastLedEffects::rainbowWave(Settings::getVar0to140_1(), Settings::getVar0to500_1(), Settings::getVar0to128_1(), leds);
        effect = 24;
        effectClassLvl = effect-1;
        break;
    case 25:
        FastLedEffects::choosenWave(Settings::getVar0to500_1(), Settings::getVar0to140_1(), Settings::getVar0to128_1(), Settings::getColor(), leds);
        effect = 25;
        effectClassLvl = effect-1;
        break;
    case 26:
        FastLedEffects::firstNoiseRainbow(Settings::getVar0to140_1(), leds);
        effect = 26;
        effectClassLvl = effect-1;
        break;
    case 27:
        FastLedEffects::firstNoiseColor(Settings::getColor(), Settings::getVar0to140_1(), leds);
        effect = 27;
        effectClassLvl = effect-1;
        break;
    case 28:
        FastLedEffects::noisePalette(Settings::getColor(), Settings::getVar0to140_1(), leds);
        effect = 28;
        effectClassLvl = effect-1;
        break;
    case 29:
        FastLedEffects::runFire(Settings::getColor(), leds);
        effect = 29;
        effectClassLvl = effect-1;
        break;
    case 30:
        FastLedEffects::secondNoise(Settings::getColor(), leds);
        effect = 30;
        effectClassLvl = effect-1;
        break;
    case 31:
        FastLedEffects::fillNoise16(leds);
        effect = 31;
        effectClassLvl = effect-1;
        break;
    case 32:
        FastLedEffects::rainbowDave(Settings::getVar0to128_1(), Settings::getVar0to128_2(), Settings::getVar0to500_1(), leds);
        effect = 32;
        effectClassLvl = effect-1;
        break;
    case 33:
        FastLedEffects::marqueeDave(Settings::getVar0to500_1(), Settings::getVar0to128_1(), Settings::getVar0to10_1(), leds);
        effect = 33;
        effectClassLvl = effect-1;
        break;
    case 34:
        FastLedEffects::twinkleOld(Settings::getVar0to500_1(), leds);
        effect = 34;
        effectClassLvl = effect-1;
        break;
    case 35:
        FastLedEffects::twinkle(Settings::getVar0to500_1(), leds);
        effect = 35;
        effectClassLvl = effect-1;
        break;
    case 36:
        FastLedEffects::comet(Settings::getVar0to500_1(), Settings::getVar0to128_1(), Settings::getVar0to10_1(), Settings::getVar0to128_2(), leds);
        effect = 36;
        effectClassLvl = effect-1;
        break;
    case 37:
        FastLedEffects::cometOnce(Settings::getVar0to500_1(), Settings::getVar0to128_1(), Settings::getVar0to10_1(), Settings::getVar0to128_2(), Settings::getVar0to500_2(), leds);
        effect = 37;
        effectClassLvl = effect-1;
        break;
    case 38:
        FastLedEffects::bounce(leds, Settings::getVar0to5_1(), Settings::getVar0to128_1(), Settings::getMirrorBounce());
        effect = 38;
        effectClassLvl = effect-1;
        break;
    case 39:
        FastLedEffects::fire(Settings::getVar0to10_1(), Settings::getVar0to200_1(), Settings::getVar0to128_1(),  Settings::getVar0to10_2(), Settings::getVar0to10_3(),  Settings::getReversedFire(), Settings::getMirrorBounce());
        effect = 39;
        effectClassLvl = effect-1;
        break;
    case 40:
        FastLedEffects::storm(Settings::getVar0to5_1(), Settings::getVar0to128_1(), Settings::getVar0to500_1(), Settings::getVar0to128_2(), leds);
        effect = 40;
        effectClassLvl = effect-1;
        break;
    case 41:
        FastLedEffects::stormColored(Settings::getVar0to5_1(), Settings::getVar0to128_1(), Settings::getVar0to500_1(), Settings::getVar0to128_2(), Settings::getColor(), leds);
        effect = 41;
        effectClassLvl = effect-1;
        break;
    case 42:
        FastLedEffects::stormPalette(Settings::getVar0to5_1(), Settings::getVar0to128_1(), Settings::getVar0to500_1(), Settings::getVar0to128_2(), Settings::getColor(), leds);
        effect = 42;
        effectClassLvl = effect-1;
        break;
    case 43:
        FastLedEffects::lighting(Settings::getVar0to5_1(), Settings::getVar0to10_1(), Settings::getVar0to10_2(), Settings::getVar0to128_1(), Settings::getVar0to1000_1(), leds);
        effect = 43;
        effectClassLvl = effect-1;
        break;
    case 44:
        FastLedEffects::lightingColored(Settings::getVar0to5_1(), Settings::getVar0to10_1(), Settings::getVar0to10_2(), Settings::getVar0to128_1(), Settings::getVar0to1000_1(), Settings::getColor(), leds);
        effect = 44;
        effectClassLvl = effect-1;
        break;
    case 45:
        FastLedEffects::lightingPalette(Settings::getVar0to5_1(), Settings::getVar0to10_1(), Settings::getVar0to10_2(), Settings::getVar0to128_1(), Settings::getVar0to1000_1(), Settings::getColor(), leds);
        effect = 45;
        effectClassLvl = effect-1;
        break;
    case 46:
        FastLedEffects::beat8_tail(Settings::getVar0to10_1(), Settings::getVar0to128_1(), Settings::getVar0to1000_1(), leds);
        effect = 46;
        effectClassLvl = effect-1;
        break;
    case 47:
        FastLedEffects::blendIntoRainbow(Settings::getVar0to1000_1(), Settings::getVar0to1000_2(), Settings::getVar0to255_1(), Settings::getVar0to255_2(), leds);
        effect = 47;
        effectClassLvl = effect-1;
        break;
    case 48:
        FastLedEffects::breatheV2(Settings::getPulseSpBreathe(), leds);
        effect = 48;
        effectClassLvl = effect-1;
        break;
    case 49:
        FastLedEffects::chaseTargetTalesVarA(Settings::getVar0to500_1(), leds);
        effect = 49;
        effectClassLvl = effect-1;
        break;
    case 50:
        FastLedEffects::chaseTargetTalesVarB(Settings::getVar0to500_1(), leds);
        effect = 50;
        effectClassLvl = effect-1;
        break;
    case 51:
        FastLedEffects::chaseTargetTalesVarC(Settings::getVar0to500_1(), Settings::getVar0to128_1(), Settings::getVar0to128_2(), leds);
        effect = 51;
        effectClassLvl = effect-1;
        break;
    case 52:
        FastLedEffects::everyNTimerVariables(Settings::getVar0to500_1(), Settings::getVar0to500_2(), leds);
        effect = 52;
        effectClassLvl = effect-1;
        break;
    case 53:
        FastLedEffects::fillUpStrip(leds);
        effect = 53;
        effectClassLvl = effect-1;
        break;
    case 54:
        FastLedEffects::heartBeat2(Settings::getVar0to3000_1(), Settings::getVar0to255_1(), leds);
        effect = 54;
        effectClassLvl = effect-1;
        break;
    case 55:
        FastLedEffects::heartBeat3(Settings::getRainbowHeartBeat3(), leds);
        effect = 55;
        effectClassLvl = effect-1;
        break;
    case 56:
        FastLedEffects::heartPulseBloodFlowing(leds);
        effect = 56;
        effectClassLvl = effect-1;
        break;
    case 57:
        FastLedEffects::lighthouseBeaconV2(Settings::getVar0to10_1(), Settings::getVar0to500_1(), Settings::getVar0to128_1(), leds);
        effect = 57;
        effectClassLvl = effect-1;
        break;
    case 58:
        FastLedEffects::matchingGlitter1(Settings::getVar0to500_1(), Settings::getVar0to500_2(), leds);
        effect = 58;
        effectClassLvl = effect-1;
        break;
    case 59:
        FastLedEffects::matchingGlitter2(Settings::getVar0to500_1(), Settings::getVar0to500_2(), leds);
        effect = 59;
        effectClassLvl = effect-1;
        break;
    case 60:
        FastLedEffects::matchingGlitter3(Settings::getMatchingGlitterSecond(), Settings::getMatchingGlitterThird(), Settings::getVar0to500_1(), Settings::getVar0to500_2(), leds);
        effect = 60;
        effectClassLvl = effect-1;
        break;
    case 61:
        FastLedEffects::matchingGlitter4(Settings::getMoreMatchingGlitter4(), Settings::getVar0to500_1(), Settings::getVar0to500_2(), leds);
        effect = 61;
        effectClassLvl = effect-1;
        break;
    case 62:
        FastLedEffects::mirrorFadeEnds(Settings::getVar0to10_1(), leds);
        effect = 62;
        effectClassLvl = effect-1;
        break;
    case 63:
        FastLedEffects::Fire2012(Settings::getVar0to500_1(), Settings::getVar0to200_1(), Settings::getVar0to128_1(), leds);
        effect = 63;
        effectClassLvl = effect-1;
        break;
    case 64:
        FastLedEffects::Fire2012_halfStrip(Settings::getVar0to500_1(), Settings::getVar0to200_1(), Settings::getVar0to128_1(), true, leds);
        effect = 64;
        effectClassLvl = effect-1;
        break;
    case 65:
        FastLedEffects::movingColoredBar(Settings::getColor(), leds, Settings::getVar0to10_1(), Settings::getVar0to140_1());
        effect = 65;
        effectClassLvl = effect-1;
        break;
    case 66:
        FastLedEffects::repeatingPattern(Settings::getVar0to128_1(), Settings::getVar0to3000_1(), Settings::getVar0to128_2(), leds);
        effect = 66;
        effectClassLvl = effect-1;
        break;
    case 67:
        FastLedEffects::savedPixel(Settings::getVar0to10_1(), Settings::getVar0to1000_1(), leds);
        effect = 67;
        effectClassLvl = effect-1;
        break;
    case 68:
        FastLedEffects::sinCosLinear(leds);
        effect = 68;
        effectClassLvl = effect-1;
        break;
    case 69:
        FastLedEffects::sparkles(leds, Settings::getVar0to1000_1(), Settings::getVar0to1000_2(), Settings::getVar0to3000_1());
        effect = 69;
        effectClassLvl = effect-1;
        break;
    default:
        break;
    
}

FastLED.show();


}

void StripesFA::setBrightness(uint8_t brightness) {
    FastLED.setBrightness(brightness);
    FastLED.show();
}

void StripesFA::setColor(uint8_t g, uint8_t r, uint8_t b) {
//    std::cout << "Inside color function in the stripe" << std::endl;
   fill_solid(leds, NUM_LEDS, CRGB(g, r, b));
   FastLED.show();
}

void StripesFA::stop() {

}

CRGB StripesFA::getColor1() {
    return this->color1;
}

CRGB StripesFA::getColor2() {
    return this->color2;
}

CRGB StripesFA::getColor3() {
    return this->color3;
}

int StripesFA::getPort() {
    return this->port;
}
int StripesFA::getLength() {
    return this->length;
}
int StripesFA::getDirection() {
    return this->direction;

}
int StripesFA::getEffect() {
    return this->effectClassLvl;
}

