#include "effectmanager.h"


void EffectManager::setSetting(const String& settingName, int value) {
    if (settingMap.find(settingName) != settingMap.end()) {
            settingMap[settingName](value); // Call the corresponding setter function
        } else {
            Serial.println("Setting not found");
    }
}