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
    }

    void setSetting(const String& settingName, int value);

    private:
    std::map<String, SetterFunction> settingMap;
};