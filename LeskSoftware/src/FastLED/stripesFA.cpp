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
        FastLedEffects::fill(Settings::getR(), Settings::getG(), Settings::getB(), leds);
        effect = 1;
        effectClassLvl = effect-1;
        break;
    case 2:
        FastLedEffects::blink(Settings::getR(), Settings::getG(), Settings::getB(), leds, Settings::getTidBlink());
        effect = 2;
        effectClassLvl = effect-1;
        break;
    case 3:
        FastLedEffects::rainbowStatic(leds);
        effect = 3;
        effectClassLvl = effect-1;
        break;
    case 4:
        FastLedEffects::fillGradientTwoColors(Settings::getR(), Settings::getG(), Settings::getB(), Settings::getR2(), Settings::getG2(), Settings::getB2(), leds);
        effect = 4;
        effectClassLvl = effect-1;
        break;
    case 5:
        FastLedEffects::fillGradientThreeColors(Settings::getR(), Settings::getG(), Settings::getB(), Settings::getR2(), Settings::getG2(), Settings::getB2(),  Settings::getR3(), Settings::getG3(), Settings::getB3(), leds);
        effect = 5;
        effectClassLvl = effect-1;
        break;
    case 6:
        FastLedEffects::backAndForthNoSmoothOneDot(Settings::getR(), Settings::getG(), Settings::getB(), leds, Settings::getTidBackAndForthNoSmoothOneDot());
        effect = 6;
        effectClassLvl = effect-1;
        break;
    case 7:
        FastLedEffects::backAndForthNoSmoothLengthedDot(Settings::getR(), Settings::getG(), Settings::getB(), leds, Settings::getTidBackAndForthNoSmoothLengthedDot(), Settings::getLengthBackAndForthNoSmoothLengthedDot());
        effect = 7;
        effectClassLvl = effect-1;
        break;
    case 8:
        FastLedEffects::hueFading(Settings::getTidHueFading(), leds);
        effect = 8;
        effectClassLvl = effect-1;
        break;
    case 9:
        FastLedEffects::hueWhiteWave(Settings::getHueInsert_hueWhiteWave(), Settings::getTidHueWhiteWave(), leds);
        effect = 9;
        effectClassLvl = effect-1;
        break;
    case 10:
        FastLedEffects::displayPaletteLinear(Settings::getPalette1(), leds);
        effect = 10;
        effectClassLvl = effect-1;
        break;
    case 11:
        FastLedEffects::movingPaletteLinear(Settings::getPalette1(), Settings::getTidMovingPaletteLinear(), leds);
        effect = 11;
        effectClassLvl = effect-1;
        break;
    case 12:
        FastLedEffects::spotlightingPalette(Settings::getPalette1(), Settings::getTidSpotlightingPalette(), Settings::getFade_spotlightingPalette(), leds);
        effect = 12;
        effectClassLvl = effect-1;
        break;
    case 13:
        FastLedEffects::sinBeat8(Settings::getR(), Settings::getG(), Settings::getB(), Settings::getFade_sinBeat8(), Settings::getBpmSinBeat8(), leds);
        effect = 13;
        effectClassLvl = effect-1;
        break;
    case 14:
        FastLedEffects::sinBeat8PhaseOff(Settings::getR(), Settings::getG(), Settings::getB(), Settings::getFade_sinBeat8(), Settings::getBpmSinBeat8(), Settings::getSinBeat8PhaseOff_phaseOffset(), leds);
        effect = 14;
        effectClassLvl = effect-1;
        break;
    case 15:
        FastLedEffects::sinBeat8TimeOff(Settings::getR(), Settings::getG(), Settings::getB(), Settings::getFade_sinBeat8(), Settings::getBpmSinBeat8(), Settings::getTidSinBeat8TimeOff(), leds);
        effect = 15;
        effectClassLvl = effect-1;
        break;
    case 16:
        FastLedEffects::twoSinBeat8(Settings::getR(), Settings::getG(), Settings::getB(), Settings::getR2(), Settings::getG2(), Settings::getB2(), Settings::getFade_sinBeat8(), Settings::getBpmSinBeat8(), leds);
        effect = 16;
        effectClassLvl = effect-1;
        break;
    case 17:
        FastLedEffects::threeSinBeat8(Settings::getR(), Settings::getG(), Settings::getB(), Settings::getR2(), Settings::getG2(), Settings::getB2(),Settings::getR3(), Settings::getG3(), Settings::getB3(), Settings::getFade_sinBeat8(), Settings::getBpmSinBeat8(), leds);
        effect = 17;
        effectClassLvl = effect-1;
        break;
    case 18:
        FastLedEffects::brightnessSinBeat8Palette(Settings::getPalette1(), Settings::getBpmSinBeat8(), Settings::getTidBrightnessSinBeat8Palette(), leds);
        effect = 18;
        effectClassLvl = effect-1;
        break;
    case 19:
        FastLedEffects::funkyRainbowSinBeat8(Settings::getFade_sinBeat8(), leds);
        effect = 19;
        effectClassLvl = effect-1;
        break;
    case 20:
        FastLedEffects::funkyRangeSinBeat8(Settings::getFade_sinBeat8(), Settings::getR(), Settings::getG(), Settings::getB(), leds);
        effect = 20;
        effectClassLvl = effect-1;
        break;
    case 21:
        FastLedEffects::funkyRainbowSinBeat8Two(Settings::getFade_sinBeat8(), leds);
        effect = 21;
        effectClassLvl = effect-1;
        break;
    case 22:
        FastLedEffects::funkyRangeSinBeat8Two(Settings::getFade_sinBeat8(), Settings::getR(), Settings::getG(), Settings::getB(), leds);
        effect = 22;
        effectClassLvl = effect-1;
        break;
    case 23:
        FastLedEffects::movingFunkyPalette(Settings::getPalette1(), Settings::getBpmSinBeat8(), Settings::getBpm2SinBeat8(), leds);
        effect = 23;
        effectClassLvl = effect-1;
        break;
    case 24:
        FastLedEffects::rainbowWave(Settings::getBpmSinBeat8(), Settings::getTidRainbowWave(), Settings::getFade_sinBeat8(), leds);
        effect = 24;
        effectClassLvl = effect-1;
        break;
    case 25:
        FastLedEffects::choosenWave(Settings::getTidChoosenWave(), Settings::getBpmSinBeat8(), Settings::getFade_sinBeat8(), Settings::getR(), Settings::getG(), Settings::getB(), leds);
        effect = 25;
        effectClassLvl = effect-1;
        break;
    case 26:
        FastLedEffects::firstNoiseRainbow(Settings::getBpmSinBeat8(), leds);
        effect = 26;
        effectClassLvl = effect-1;
        break;
    case 27:
        FastLedEffects::firstNoiseColor(Settings::getR(), Settings::getG(), Settings::getB(), Settings::getBpmSinBeat8(), leds);
        effect = 27;
        effectClassLvl = effect-1;
        break;
    case 28:
        FastLedEffects::noisePalette(Settings::getPalette1(), Settings::getScaleNoisePalette(), leds);
        effect = 28;
        effectClassLvl = effect-1;
        break;
    case 29:
        FastLedEffects::runFire(Settings::getPalette1(), leds);
        effect = 29;
        effectClassLvl = effect-1;
        break;
    case 30:
        FastLedEffects::secondNoise(Settings::getPalette1(), leds);
        effect = 30;
        effectClassLvl = effect-1;
        break;
    case 31:
        FastLedEffects::fillNoise16(leds);
        effect = 31;
        effectClassLvl = effect-1;
        break;
    case 32:
        FastLedEffects::rainbowDave(Settings::getDensityRainbowDave(), Settings::getDeltaRainbowDave(), Settings::getTidBlink(), leds);
        effect = 32;
        effectClassLvl = effect-1;
        break;
    case 33:
        FastLedEffects::marqueeDave(Settings::getTidBlink(), Settings::getDensityRainbowDave(), Settings::getLengthBackAndForthNoSmoothLengthedDot(), leds);
        effect = 33;
        effectClassLvl = effect-1;
        break;
    case 34:
        FastLedEffects::twinkleOld(Settings::getTidBlink(), leds);
        effect = 34;
        effectClassLvl = effect-1;
        break;
    case 35:
        FastLedEffects::twinkle(Settings::getTidBlink(), leds);
        effect = 35;
        effectClassLvl = effect-1;
        break;
    case 36:
        FastLedEffects::comet(Settings::getTidBlink(), Settings::getFade_sinBeat8(), Settings::getLengthBackAndForthNoSmoothLengthedDot(), Settings::getDeltaRainbowDave(), leds);
        effect = 36;
        effectClassLvl = effect-1;
        break;
    case 37:
        FastLedEffects::cometOnce(Settings::getTidBlink(), Settings::getFade_sinBeat8(), Settings::getLengthBackAndForthNoSmoothLengthedDot(), Settings::getDeltaRainbowDave(), Settings::getSpeedCometOnce(), leds);
        effect = 37;
        effectClassLvl = effect-1;
        break;
    case 38:
        FastLedEffects::bounce(leds, Settings::getBallsBounce(), Settings::getFade_sinBeat8(), Settings::getMirrorBounce());
        effect = 38;
        effectClassLvl = effect-1;
        break;
    case 39:
        FastLedEffects::fire(Settings::getLengthBackAndForthNoSmoothLengthedDot(), Settings::getCoolingFire(), Settings::getSparkingFire(),  Settings::getSparksFire(), Settings::getSparkHeightFire(),  Settings::getReversedFire(), Settings::getMirrorBounce());
        effect = 39;
        effectClassLvl = effect-1;
        break;
    case 40:
        FastLedEffects::storm(Settings::getChanceStorm(), Settings::getClusterStorm(), Settings::getSpeedCometOnce(), Settings::getFade_sinBeat8(), leds);
        effect = 40;
        effectClassLvl = effect-1;
        break;
    case 41:
        FastLedEffects::stormColored(Settings::getChanceStorm(), Settings::getClusterStorm(), Settings::getSpeedCometOnce(), Settings::getFade_sinBeat8(), Settings::getR(), Settings::getG(), Settings::getB(), leds);
        effect = 41;
        effectClassLvl = effect-1;
        break;
    case 42:
        FastLedEffects::stormPalette(Settings::getChanceStorm(), Settings::getClusterStorm(), Settings::getSpeedCometOnce(), Settings::getFade_sinBeat8(), Settings::getPalette1(), leds);
        effect = 42;
        effectClassLvl = effect-1;
        break;
    case 43:
        FastLedEffects::lighting(Settings::getLedstartLighting(), Settings::getLedlenLighting(), Settings::getFlashesLighting(), Settings::getDimmerLighting(), Settings::getFrequencyLighting(), leds);
        effect = 43;
        effectClassLvl = effect-1;
        break;
    case 44:
        FastLedEffects::lightingColored(Settings::getLedstartLighting(), Settings::getLedlenLighting(), Settings::getFlashesLighting(), Settings::getDimmerLighting(), Settings::getFrequencyLighting(), Settings::getR(), Settings::getG(), Settings::getB(), leds);
        effect = 44;
        effectClassLvl = effect-1;
        break;
    case 45:
        FastLedEffects::lightingPalette(Settings::getLedstartLighting(), Settings::getLedlenLighting(), Settings::getFlashesLighting(), Settings::getDimmerLighting(), Settings::getFrequencyLighting(), Settings::getPalette1(), leds);
        effect = 45;
        effectClassLvl = effect-1;
        break;
    case 46:
        FastLedEffects::beat8_tail(Settings::getBpmSinBeat8(), Settings::getFade_sinBeat8(), Settings::getTidBlink(), leds);
        effect = 46;
        effectClassLvl = effect-1;
        break;
    case 47:
        FastLedEffects::blendIntoRainbow(Settings::getTidBlink(), Settings::getTidBlendIntoRainbow(), Settings::getInitialHue(), Settings::getBlendAmount(), leds);
        effect = 47;
        effectClassLvl = effect-1;
        break;
    case 48:
        FastLedEffects::breatheV2(Settings::getPulseSpBreathe(), leds);
        effect = 48;
        effectClassLvl = effect-1;
        break;
    /*case 49:
        FastLedEffects::chaseTargetTalesVarA(tid, leds);
        this->effect = 48;
        break;
    case 50:
        FastLedEffects::chaseTargetTalesVarB(tid, leds);
        this->effect = 49;
        break;
    case 51:
        FastLedEffects::chaseTargetTalesVarC(boilingTime, smoothFading, fade, leds);
        this->effect = 50;
        break;
    case 52:
        FastLedEffects::everyNTimerVariables(timerA, timerB, leds);
        this->effect = 51;
        break;
    case 53:
        FastLedEffects::fillUpStrip(leds);
        this->effect = 52;
        break;
    case 54:
        FastLedEffects::heartBeat2(beat_speed, dub_offset, leds);
        this->effect = 53;
        break;
    case 55:
        FastLedEffects::heartBeat3(rainbow, leds);
        this->effect = 54;
        break;
    case 56:
        FastLedEffects::heartPulseBloodFlowing(leds);
        this->effect = 55;
        break;
    case 57:
        FastLedEffects::lighthouseBeaconV2(width, tid, fadeRate, leds);
        this->effect = 56;
        break;
    case 58:
        FastLedEffects::matchingGlitter1(leds);
        this->effect = 57;
        break;
    case 59:
        FastLedEffects::matchingGlitter2(leds);
        this->effect = 58;
        break;
    case 60:
        FastLedEffects::matchingGlitter3(second, thrid, leds);
        this->effect = 59;
        break;
    case 61:
        FastLedEffects::matchingGlitter4(more, leds);
        this->effect = 60;
        break;
    case 62:
        FastLedEffects::mirrorFadeEnds(fade, leds);
        this->effect = 61;
        break;
    case 63:
        FastLedEffects::Fire2012(tid, cooling, sparking, leds);
        this->effect = 62;
        break;
    case 64:
        FastLedEffects::Fire2012_halfStrip(tid, cooling, sparking, gReverseDirection, leds);
        this->effect = 63;
        break;
    case 65:
        FastLedEffects::movingColoredBar(palette, leds, colorBarLength, frameDelay);
        this->effect = 64;
        break;
    case 66:
        FastLedEffects::repeatingPattern(time1, time2, fade, leds);
        this->effect = 65;
        break;
    case 67:
        FastLedEffects::savedPixel(tid, leds);
        this->effect = 66;
        break;
    case 68:
        FastLedEffects::sinCosLinear(leds);
        this->effect = 67;
        break;
    case 69:
        FastLedEffects::sparkles(leds, sparkel_duration, sparkel_amount, sparkel_spread);
        this->effect = 68;
        break;*/
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

