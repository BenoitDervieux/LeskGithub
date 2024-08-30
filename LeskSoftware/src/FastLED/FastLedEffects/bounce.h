#ifndef BOUNCE_H
#define BOUNCE_H

// Link : https://www.youtube.com/watch?v=ysI30OrkiAc&list=PLF2KJ6Gy3cZ7ynsp8s4tnqEFmY15CKhmH&index=10

#include <FastLED.h>
using namespace std;
#include <vector>
#include <sys/time.h>

// extern CRGB leds[];

#define ARRAYSIZE(x) ( sizeof(x) / sizeof((x)[0]) )
static const CRGB ballColors [] = {
    CRGB::Green,
    CRGB::Red,
    CRGB::Blue,
    CRGB::Orange,
    CRGB::Indigo
};

#define Gravity (-9.81)

class Bounce {

    private:
        size_t _cLength;
        size_t _cBalls;
        byte _fadeRate;
        bool _bMirrored;

        int instantiated = 0;

        const double StartHeight = 1;
        const double ImpactVelocity = InitialBallSpeed(StartHeight);
        const double SpeedKnob = 1.0;
    
        std::vector<double> ClockTimeAtLastBounce, Height, BallSpeed, Dampening;
        std::vector<CRGB> Colors;

        double InitialBallSpeed(double height) const {
        return sqrt(-2 * Gravity * height);
        }

        static double TimeTo() {
            timeval tv = {0};
            gettimeofday(&tv, nullptr);
            return (double)(tv.tv_usec / 1000000.0 + (double)tv.tv_sec);
        }
    public: 
        Bounce(size_t cLength, 
        size_t ballCount = 3, 
        byte fade = 32, 
        bool bMirrored = false) : 
        _cLength(cLength), 
        _cBalls(ballCount),
         _fadeRate(fade), 
         _bMirrored(bMirrored),
         instantiated(ballCount),
         ClockTimeAtLastBounce(ballCount), 
         Height(ballCount),
         BallSpeed(ballCount),
         Dampening(ballCount),
         Colors(ballCount) {

        for (size_t i = 0; i < ballCount; i++) {
            Height[i]                   = StartHeight;                              // Current Ball height
            ClockTimeAtLastBounce[i]    = TimeTo();                                 // When Ball last hit ground
            Dampening[i]                = 0.90 - i / pow(_cBalls, 2);               // Bounciness
            BallSpeed[i]                = InitialBallSpeed(Height[i]);              // Initial ball speed
            Colors[i]                   = ballColors[i % ARRAYSIZE(ballColors)];    
        }
    }

    virtual void Draw(CRGB leds[]) {
        if (_fadeRate != 0) {
            for (size_t i = 0; i < _cLength; i++) {
                leds[i].fadeToBlackBy(_fadeRate);
            }
        } else {
                FastLED.clear();
        }

        for (size_t i = 0; i < _cBalls; i++) {
            double timeSinceLastBoucne = (TimeTo() - ClockTimeAtLastBounce[i])/ SpeedKnob;

            // Use standard constant acceleration function
            Height[i] = 0.5 * Gravity * pow(timeSinceLastBoucne, 2.0) + BallSpeed[i] * timeSinceLastBoucne;

            if (Height[i] < 0 ) {
                Height[i] = 0;
                BallSpeed[i] = Dampening[i] * BallSpeed[i];
                ClockTimeAtLastBounce[i] = TimeTo();

                if (BallSpeed[i] < 0.01) {
                    BallSpeed[i] = InitialBallSpeed(StartHeight) * Dampening[i];
                }
            }

            size_t position = (size_t)(Height[i] *(_cLength - 1) /  StartHeight);
            leds[position] += Colors[i];
            leds[position + 1] += Colors[i];

            if (_bMirrored) {
                leds[_cLength - 1 - position] += Colors[i];
                leds[_cLength - position] += Colors[i];
            }
        }
        delay(20); // Need to change that
        FastLED.show();
    }

    int GetInstantiated() { return instantiated; }
    void Recalibrate(size_t ballCount) {
        this->_cBalls = ballCount;
        this->instantiated = ballCount;
        for (size_t i = 0; i < ballCount; i++) {
            Height[i]                   = StartHeight;                              // Current Ball height
            ClockTimeAtLastBounce[i]    = TimeTo();                                 // When Ball last hit ground
            Dampening[i]                = 0.90 - i / pow(_cBalls, 2);               // Bounciness
            BallSpeed[i]                = InitialBallSpeed(Height[i]);              // Initial ball speed
            Colors[i]                   = ballColors[i % ARRAYSIZE(ballColors)];    
        }
    }

    size_t GetFade() { return _fadeRate; }
    void SetFade(size_t fade) { this->_fadeRate = fade; }
    bool GetMirror() {return _bMirrored;}
    void SetMirror(bool mirror) {this->_bMirrored = mirror;}
           
};

#endif