#include "insideNetworking2.h"
#include "../../.variables/variables.h"

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

InsideNetworking2::InsideNetworking2() {

}


void InsideNetworking2::setup() {
    this->setSSID(SSID_LOCAL);
    this->setPassword(SSID_PASSWORD_LOCAL);
    this->attemptToConnectToUsualWifi();
    if (WiFi.status() != WL_CONNECTED) {
        this->setRole(CLIENT);
        // Setting WiFi.mode and WiFi.disconnect helps to scann around
        WiFi.mode(WIFI_STA);
        WiFi.disconnect();
        // We scann all the networks
        std::vector<std::pair<std::string, int>> network_map = this->scanAndSort();
        this->checkPreviousConnexion(network_map);
        
    }
}

void InsideNetworking2::attemptToConnectToUsualWifi() {
    this->connectToWifi(this->getSSID(), this->getPassword());
}

void InsideNetworking2::checkPreviousConnexion(std::vector<std::pair<std::string, int>> network_map) {
    if (network_map.size() == 0) return;
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
    Serial.println("Point 98789: The JSON");
    Serial.println(network_map.size());
    for (int i = 0; i < doc["networks"].size(); i++) {
        std::string ssid = doc["networks"]["networks" + String(i)]["ssid"];
        std::string password = doc["networks"]["networks" + String(i)]["password"];
        Serial.println(ssid.c_str());
        Serial.println(password.c_str());
        for (int j = 0; j < network_map.size(); j++) {
            if (network_map[j].first == ssid) {
                Serial.println(network_map[j].first.c_str());
                this->connectToWifi((char*)ssid.c_str(), (char*)password.c_str());
                if (WiFi.status() == WL_CONNECTED)  return;
            }
        }
        Serial.println("");
    }

}

void InsideNetworking2::connectToWifi(char * ssid, char * password) {
    Serial.print("Pt9745: SSID in connectToWifi --> ");
    Serial.println(ssid);
    Serial.print("Pt 9746: PWD in connectToWifi --> ");
    Serial.println(password); 
    WiFi.begin(ssid, password);
    int attempt = 0;
    // Here we try to connect
    while (WiFi.status() != WL_CONNECTED && attempt < 3) {
      delay(1000);
      Serial.println("Connecting to WiFi...");
      Serial.print("Pt 5475: Attempts --> ");
      Serial.println(attempt);
      attempt++;
    }
    if (WiFi.status() != WL_CONNECTED) {
        WiFi._setStatus(WL_CONNECT_FAILED);
    }
    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("Connected!!!");
    }
}

void InsideNetworking2::setRole(enum role roleToSet) {
    this->role = roleToSet;
}

std::vector<std::pair<std::string, int>> InsideNetworking2::scanAndSort() {
    // WiFi.mode(WIFI_STA);
    int networksFound = WiFi.scanNetworks();
    Serial.print("PT 44444: Number of networks found --> ");
    Serial.println(networksFound);
    std::vector<std::pair<std::string, int>> network_map;
    for (int i = 0; i < networksFound; ++i) {
        std::string ssid_temp = WiFi.SSID(i).c_str();
        network_map.push_back(std::make_pair(ssid_temp, WiFi.RSSI(i)));
        Serial.print("Pt 9747: SSID --> ");
        Serial.println(ssid_temp.c_str());
    }
    auto cmp = [](std::pair<std::string, int> a, std::pair<std::string, int>b) { return a.second > b.second; };

    std::sort(network_map.begin(), network_map.end(), cmp);
    return network_map;
}

bool InsideNetworking2::hasEnding(std::string const &fullString, std::string const &ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

void InsideNetworking2::setSSID(char* ssidToSet) {
    this->ssid = ssidToSet;
}
void InsideNetworking2::setPassword(char* passwordToSet) {
    this->password = passwordToSet;
}

char* InsideNetworking2::getSSID() {
    return this->ssid;
}
char* InsideNetworking2::getPassword() {
    return this->password;
}

// Callback when data is sent
void InsideNetworking2::OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
    Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

// Callback when data is received
void InsideNetworking2::OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len) {
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
