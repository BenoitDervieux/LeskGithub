#include <map>
#include <functional>
#include "Settings.h"

/*
This class is intended to take an argument from the webserver and to change it
into a setting.
What happen is that, the argument comes to /setSetting
Example: /setSetting%effect=tiblink%value=250
and it will recognize from here that we need to use the static class settings
and to set up the value of tidblink
so that then it will run in the stripe controller and in the stripes
 */

class EffectManager {

    public:
    using SetterFunction = std::function<void(int)>;

    EffectManager() {
        settingMap["tid_blink"] = Settings::setTidBlink;
        settingMap["r"] = Settings::setR;
        settingMap["g"] = Settings::setG;
        settingMap["b"] = Settings::setB;
        settingMap["r2"] = Settings::setR2;
        settingMap["g2"] = Settings::setG2;
        settingMap["b2"] = Settings::setB2;
        settingMap["r3"] = Settings::setR3;
        settingMap["g3"] = Settings::setG3;
        settingMap["b3"] = Settings::setB3;
        settingMap["tid_backAndForthNoSmoothOneDot"] = Settings::setTidBackAndForthNoSmoothOneDot;
        settingMap["tid_backAndForthNoSmoothLengthedDot"] = Settings::setTidBackAndForthNoSmoothLengthedDot;
        settingMap["length_backAndForthNoSmoothLengthedDot"] = Settings::setLengthBackAndForthNoSmoothLengthedDot;
        settingMap["tid_hueFading"] = Settings::setTidHueFading;
        settingMap["hueInsert_hueWhiteWave"] = Settings::setHueInsert_hueWhiteWave;
        settingMap["tid_hueWhiteWave"] = Settings::setTidHueWhiteWave;
        settingMap["tid_movingPaletteLinear"] = Settings::setTidMovingPaletteLinear;
    }

    void setSetting(const String& settingName, int value);

    private:
    std::map<String, SetterFunction> settingMap;
};