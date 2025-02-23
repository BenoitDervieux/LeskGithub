#include "insideNetworking.h"
#include "../../.variables/variables.h"


char* ssid = SSID_LOCAL; 
char* password = SSID_PASSWORD_LOCAL;

// Structure to send/receive data
typedef struct {
    char message[32];
    bool isMaster;
} esp_now_message;

// The idea of this setup is that
// first we try to connect to the wifi
// Second we check if there isn't other networks available that we know of
// Third we check if there are other Lesk panels around
//      If yes, we need to check if they are masters or not
//      And then connect to them
//Fourth we decide to make it a master 

InsideNetworking::InsideNetworking() {
}


void InsideNetworking::setup() {
    this->setSSID(SSID_LOCAL);
    this->setPassword(SSID_PASSWORD_LOCAL);

    this->connectToWifi();
    if (WiFi.status() == WL_CONNECTED) {
        this->setRole(CLIENT);
        Serial.println("Connected to WiFi et nique sa mère la réré");
        std::vector<std::pair<std::string, int>> network_map = this->scanAndSort();
        if (network_map.size() > 0) {
            std::vector<std::pair<std::string, int>> result_lesk;
            // Here we check all the networks we have in memory
            fs::File listNetworks = SPIFFS.open("/networks.json", FILE_READ);
            if (!listNetworks) {
                Serial.println("Failed to open file");
                // return;
            }
            DynamicJsonDocument doc(1024);
            DeserializationError error = deserializeJson(doc, listNetworks);
            listNetworks.close();
            if (error) {
                Serial.println("Failed to parse JSON file");
                return;
            }
            Serial.println("Point 98788: The JSON");
            Serial.println(doc["networks"].size());
            for (int i = 0; i < doc["networks"].size(); i++) {
                std::string ssid = doc["networks"]["networks" + String(i)]["ssid"];
                Serial.println(ssid.c_str());
            }
        }
    } else {
        std::vector<std::pair<std::string, int>> network_map = this->scanAndSort();
        if (network_map.size() > 0) {
            // intialize 2 vectors to store the on one hand the networks available
            // on the other hand the lesk panels around
            std::vector<std::pair<std::string, int>> networks_available;
            std::vector<std::pair<std::string, int>> result_lesk;
            // Here we check all the networks we have in memory
            fs::File listNetworks = SPIFFS.open("/networks.json", FILE_READ);
            if (!listNetworks) {
                Serial.println("Failed to open file");
                // return;
            }
            // Structure that will hold the json
            DynamicJsonDocument doc(1024);
            DeserializationError error = deserializeJson(doc, listNetworks);
            listNetworks.close();
            if (error) {
                Serial.println("Failed to parse JSON file");
                return;
            }
            Serial.println(doc["networks"].size());
            // Iterate through all the networks scanned [TODO] --> Make a function that can as well save them
            for (int i = 0; i < network_map.size(); i++) {
                std::string network_ssid = network_map[i].first;
                // Iterate through all the networks in memory
                for (int j = 0; j < doc["networks"].size(); j++) {
                    std::string in_memory_ssid = doc["networks"]["networks" + String(j)]["ssid"];
                    Serial.println(in_memory_ssid.c_str());
                    if (in_memory_ssid.compare(network_ssid) == 0) {
                        networks_available.push_back(network_map[i]);
                    }
                }
                // Check the other lesk panels around and store them
                if (hasEnding(network_ssid, "_lesklights")) {
                    result_lesk.push_back(network_map[i]);
                }
            }
            // Check if there were networks available around that we could connect to
            if (networks_available.size() > 0) {
                // Iterate through all the networks available
                for (int i = 0; i < networks_available.size(); i++) {
                    // Set the SSID and password locally in the class
                    this->setSSID((char*)networks_available[i].first.c_str());
                    this->setPassword((char*)networks_available[i].first.c_str());
                    // Try to start the connexion
                    WiFi.begin(this->getSSID(), this->getPassword());
                    int attempt = 0;
                    // 10 seconds or 10 attempts
                    while (WiFi.status() != WL_CONNECTED && attempt < 10) {
                        delay(1000);
                        Serial.println("Connecting to WiFi...");
                        attempt++;
                    }
                    // If connected, the set as a client and then break the loop
                    if (WiFi.status() == WL_CONNECTED) {
                        this->setRole(CLIENT);
                        break;
                    }
                }
            } else {
                if (result_lesk.size() > 0) {
                    WiFi.mode(WIFI_STA);
  
                    // Initialize ESP-NOW
                    if (esp_now_init() != ESP_OK) {
                      Serial.println("ESP-NOW Init Failed");
                      return;
                    }
                    // Register callbacks
                    esp_now_register_send_cb(OnDataSent);
                    esp_now_register_recv_cb(OnDataRecv);

                    // Send a broadcast message asking, "Are you the master?"
                    esp_now_message query;
                    strcpy(query.message, "Are you the master?");
                    query.isMaster = false;

                    // Broadcast address
                    uint8_t broadcastAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
                    
                    // Add the broadcast address as a peer
                    esp_now_peer_info_t peerInfo;
                    memcpy(peerInfo.peer_addr, broadcastAddress, 6);
                    peerInfo.channel = 0;
                    peerInfo.encrypt = false;
                    if (esp_now_add_peer(&peerInfo) != ESP_OK) {
                        Serial.println("Failed to add broadcast peer");
                        return;
                    }

                    // Send the query
                    esp_now_send(broadcastAddress, (uint8_t *) &query, sizeof(query));
                    Serial.println("Broadcast query sent: Are you the master?");
                }
            }
        } else {
            // Set the role has a master
            this->role = MASTER;
            fs::File listNetworks = SPIFFS.open("/networks.json", FILE_READ);
            if (!listNetworks) {
                Serial.println("Failed to open file");
                // return;
            }
            DynamicJsonDocument doc(1024);
            DeserializationError error = deserializeJson(doc, listNetworks);
            listNetworks.close();
            if (error) {
                Serial.println("Failed to parse JSON file");
                return;
            }
            Serial.println("Point 98788: The JSON");
            const char* ssid_temp = doc["personal_network"]["ssid"];
            const char* password_temp = doc["personal_network"]["password"];
            WiFi.softAP(ssid_temp, password_temp);
            // Set the ESP-Now functions for master
            esp_now_register_send_cb(OnDataSent);
            esp_now_register_recv_cb(OnDataRecv);
        }
    }



}

void InsideNetworking::connectToWifi() {
    WiFi.begin(ssid, password);
    int attempt = 0;
    // Here we try to connect
    while (WiFi.status() != WL_CONNECTED && attempt < 10) {
      delay(1000);
      Serial.println("Connecting to WiFi...");
      attempt++;
    }
}

void InsideNetworking::setRole(enum role roleToSet) {
    this->role = roleToSet;
}

std::vector<std::pair<std::string, int>> InsideNetworking::scanAndSort() {
    int networksFound = WiFi.scanNetworks();
    std::vector<std::pair<std::string, int>> network_map;
    for (int i = 0; i < networksFound; ++i) {
        std::string ssid_temp = WiFi.SSID(i).c_str();
        network_map.push_back(std::make_pair(ssid_temp, WiFi.RSSI(i)));
    }
    auto cmp = [](std::pair<std::string, int> a, std::pair<std::string, int>b) { return a.second > b.second; };

    std::sort(network_map.begin(), network_map.end(), cmp);
    return network_map;
}

bool hasEnding (std::string const &fullString, std::string const &ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

void InsideNetworking::setSSID(char* ssidToSet) {
    this->ssid = ssidToSet;
}
void InsideNetworking::setPassword(char* passwordToSet) {
    this->password = passwordToSet;
}

char* InsideNetworking::getSSID() {
    return this->ssid;
}
char* InsideNetworking::getPassword() {
    return this->password;
}

// Callback when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
    Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

// Callback when data is received
void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len) {
    esp_now_message receivedMessage;
    memcpy(&receivedMessage, incomingData, sizeof(receivedMessage));
    
    // Check if the response is from the master
    if (receivedMessage.isMaster && strcmp(receivedMessage.message, "Yes, I am the master.") == 0) {
      Serial.println("Found master! Becoming a slave...");
      
      // Register the master as a peer
      esp_now_peer_info_t peerInfo;
      memcpy(peerInfo.peer_addr, mac, 6);
      peerInfo.channel = 0;
      peerInfo.encrypt = false;
      if (esp_now_add_peer(&peerInfo) != ESP_OK) {
        Serial.println("Failed to add master as peer");
        return;
      }
      
      Serial.println("Successfully became a slave.");
    }
    // Check if the message is "Are you the master?"
    if (strcmp(receivedMessage.message, "Are you the master?") == 0) {
        Serial.println("Received query from a slave. Responding...");
        
        // Prepare the response
        esp_now_message response;
        strcpy(response.message, "Yes, I am the master.");
        response.isMaster = true;
        
        // Send the response back to the sender
        esp_now_send(mac, (uint8_t *) &response, sizeof(response));
    }

    /*
    *
    * Here I need to add the way to handle requests like changing the effects and the colors
    * And bascially we need a kind of  subscriber pattern because the master is supposed to send informations to the slaves
    * But there is nothing here, only the slave/master connexion 
    *   
    */
}
 