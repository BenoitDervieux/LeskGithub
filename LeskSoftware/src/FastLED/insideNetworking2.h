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

class InsideNetworking2 {
    public:
        InsideNetworking2();
        void setup();
        static void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status);
        static void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len);
        void attemptToConnectToUsualWifi();
        void checkPreviousConnexion(std::vector<std::pair<std::string, int>> network_map);
        bool checkLesksAround(std::vector<std::pair<std::string, int>> network_map);
        void tryToEstablishLeskConnexion();
        void initializeAndRegisterEspFunction();
        void sendRequestForMaster();
    private:
        void connectToWifi(char * ssid, char * password);
        void setRole(enum role role);
        void setSSID(char* ssidToSet);
        void setPassword(char* passwordToSet);
        bool hasEnding(std::string const &fullString, std::string const &ending);
        char* getSSID();
        char* getPassword();
        std::vector<std::pair<std::string, int>> scanAndSort();
        enum role role;
        char* ssid;
        char* password;

};


#endif