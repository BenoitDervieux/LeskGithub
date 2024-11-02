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
        settingMap["r"] = Settings::setR;
        settingMap["g"] = Settings::setG;
        settingMap["b"] = Settings::setB;
        settingMap["r2"] = Settings::setR2;
        settingMap["g2"] = Settings::setG2;
        settingMap["b2"] = Settings::setB2;
        settingMap["r3"] = Settings::setR3;
        settingMap["g3"] = Settings::setG3;
        settingMap["b3"] = Settings::setB3;
        settingMap["mirror_bounce"] = Settings::setMirrorBounce;
        settingMap["breversed_fire"] = Settings::setReversedFire;
        settingMap["speed"] = Settings::setSpeed;
        settingMap["pulseSp_breathe"] = Settings::setPulseSpBreathe;
        settingMap["rainbow_heartBeat3"] = Settings::setRainbowHeartBeat3;

        settingMap["var_0to5_1"] = Settings::setVar0to5_1;
        settingMap["var_0to10_1"] = Settings::setVar0to10_1;
        settingMap["var_0to10_2"] = Settings::setVar0to10_2;
        settingMap["var_0to10_3"] = Settings::setVar0to10_3;
        settingMap["var_0to128_1"] = Settings::setVar0to128_1;
        settingMap["var_0to128_2"] = Settings::setVar0to128_2;
        settingMap["var_0to140_1"] = Settings::setVar0to140_1;
        settingMap["var_0to140_2"] = Settings::setVar0to140_2;
        settingMap["var_0to200_1"] = Settings::setVar0to200_1;
        settingMap["var_0to255_1"] = Settings::setVar0to255_1;
        settingMap["var_0to255_2"] = Settings::setVar0to255_2;
        settingMap["var_0to500_1"] = Settings::setVar0to500_1;
        settingMap["var_0to500_2"] = Settings::setVar0to500_2;
        settingMap["var_0to1000_1"] = Settings::setVar0to1000_1;
        settingMap["var_0to1000_2"] = Settings::setVar0to1000_2;
        settingMap["var_0to3000_1"] = Settings::setVar0to3000_1;

        settingMap["color1"] = Settings::setColorU32;
        settingMap["color2"] = Settings::setColor2U32;
        settingMap["color3"] = Settings::setColor3U32;

    }

    void setSetting(const String& settingName, int value);

    private:
    std::map<String, SetterFunction> settingMap;
};