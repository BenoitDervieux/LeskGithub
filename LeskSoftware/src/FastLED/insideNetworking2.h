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



class InsideNetworking2 {
    public:
        enum Role {SLAVE, MASTER, SERVER, CLIENT };
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
        static void areYouTheMaster(const uint8_t *mac);
        static void yesImTheMaster(const uint8_t *mac);
        void becomeMaster();
        void setSlave();
    private:
        void connectToWifi(char * ssid, char * password);
        void setRole(Role role);
        void setSSID(char* ssidToSet);
        void setPassword(char* passwordToSet);
        bool hasEnding(std::string const &fullString, std::string const &ending);
        char* getSSID();
        char* getPassword();
        std::vector<std::pair<std::string, int>> scanAndSort();
        static Role role;
        char* ssid;
        char* password;

};


#endif