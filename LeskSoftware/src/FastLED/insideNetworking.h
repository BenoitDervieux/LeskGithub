#ifndef INSIDENETWORKING_H
#define INSIDENETWORKING_H

#include <WiFi.h>
#include "SPIFFS.h"
#include <ArduinoJson.h>
#include <esp_now.h>

#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

enum role {SLAVE, MASTER, SERVER, CLIENT };

class InsideNetworking {
    public:
        InsideNetworking();
        void setup();
    
    private:
        void connectToWifi();
        void setRole(enum role role);
        void setSSID(char* ssidToSet);
        void setPassword(char* passwordToSet);
        char* getSSID();
        char* getPassword();
        std::vector<std::pair<std::string, int>> scanAndSort();
        enum role role;
        char* ssid;
        char* password;

};


#endif