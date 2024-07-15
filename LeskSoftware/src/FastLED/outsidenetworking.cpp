#include "outsidenetworking.h"
#include "listcollections.h"

String ledState;   // Define the variable

OutSideNetworking::OutSideNetworking(AsyncWebServer* server) : server(server) {}

void OutSideNetworking::setup() {
  // Serial port for debugging purposes
  // Serial.begin(115200);
  // pinMode(ledPin, OUTPUT);

  // ssid = "Jovanovic"; // Define the variable
  // password = "VUKOVAR333"; // Define the variable

  // Initialize SPIFFS
  if(!SPIFFS.begin(true)){
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

  const char* ssid = "Jovanovic"; 
  const char* password = "vukovar333";

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Print ESP32 Local IP Address
    Serial.println(WiFi.localIP());

    // Route for root / web page
    server->on("/", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send(SPIFFS, "/index.html", "text/html");
    });
    
    // Route to load style.css file
    server->on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send(SPIFFS, "/style.css", "text/css");
    });

    // Here it prints a special collection
    server->on("/collection", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send(SPIFFS, "/collection.html", "text/html");
    });

    // Here it prints a special collection
    server->on("/effects", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send(SPIFFS, "/effects.html", "text/html");
    });

    // Route to serve the collections as JSON
    server->on("/api/collections", HTTP_GET, [](AsyncWebServerRequest *request){
        DynamicJsonDocument doc(2048); // Adjust size as needed
        // Create an object for all the collections, like a degree 1
        JsonArray collectionsArray = doc.createNestedArray("collections"); // Print 1

        // Iterate through all the collections
        for (int i = 0; i < sizeof(collections) / sizeof(collections[0]); ++i) {
        // Create a JSON Object for each collection
        JsonObject collection = collectionsArray.createNestedObject();

        // Add the name of the collections
        collection["name"] = collections[i].name;
        // Serial.print("Je teste la collectionArray: ");
        // Serial.println(collections[i].name);
        // Create another degree/level
        JsonArray effectsArray = collection.createNestedArray("effects");

        // Iterate through all the effects up until there is the end
        for (int j = 0; j < sizeof(collections[i].effect) / sizeof(Effect); ++j) {
            if (collections[i].effect[j].name == nullptr) break; // Stop at the end marker
            // Then create new Object
            JsonObject effect = effectsArray.createNestedObject();
            effect["name"] = collections[i].effect[j].name;
            effect["effects"] = collections[i].effect[j].effect;
            JsonArray settingsArray = effect.createNestedArray("settings");

            for (int k = 0; k < sizeof(collections[i].effect[j].settings) / sizeof(int); ++k) {
            if (collections[i].effect[j].settings[k] == 0) break; // Stop at the end marker
            settingsArray.add(collections[i].effect[j].settings[k]);
            }
        }
        }
        // Convert the JSON document to a string
        // Send 200 OK
        String jsonString;
        serializeJson(doc, jsonString);
        request->send(200, "application/json", jsonString);
    });

    // API endpoint to get collection data
    server->on("/api/collection", HTTP_GET, [](AsyncWebServerRequest *request){
        if (request->hasParam("name")) {
            DynamicJsonDocument doc(2048);
            JsonArray collectionsArray = doc.createNestedArray("collections");
            // Iterate through all the collections
            for (int i = 0; i < sizeof(collections) / sizeof(collections[0]); ++i) {
                if (request->getParam("name")->value() == collections[i].name) {
                    Serial.println(request->getParam("name")->value());
                    Serial.println(collections[i].name);
                    // Create a JSON Object for each collection
                    JsonObject collection = collectionsArray.createNestedObject();

                    // Add the name of the collections
                    collection["name"] = collections[i].name;
                    // Serial.print("Je teste la collectionArray: ");
                    // Serial.println(collections[i].name);
                    // Create another degree/level
                    JsonArray effectsArray = collection.createNestedArray("effects");

                    // Iterate through all the effects up until there is the end
                    for (int j = 0; j < sizeof(collections[i].effect) / sizeof(Effect); ++j) {
                        if (collections[i].effect[j].name == nullptr) break; // Stop at the end marker
                        // Then create new Object
                        JsonObject effect = effectsArray.createNestedObject();
                        effect["name"] = collections[i].effect[j].name;
                        effect["effects"] = collections[i].effect[j].effect;
                        JsonArray settingsArray = effect.createNestedArray("settings");

                        for (int k = 0; k < sizeof(collections[i].effect[j].settings) / sizeof(int); ++k) {
                        if (collections[i].effect[j].settings[k] == 0) break; // Stop at the end marker
                        settingsArray.add(collections[i].effect[j].settings[k]);
                        }
                    }
                }
        }
        // Convert the JSON document to a string
        // Send 200 OK
        String jsonString;
        serializeJson(doc, jsonString);
        request->send(200, "application/json", jsonString);
        } else {
        request->send(400, "application/json", "{\"error\":\"No id provided\"}");
        }
    });

    // API endpoint to get collection data
    server->on("/api/effects", HTTP_GET, [](AsyncWebServerRequest *request){
        DynamicJsonDocument doc(2048); // Adjust size as needed
        JsonArray effectsArray = doc.createNestedArray("effects");

        // Iterate through all the effects up until there is the end
        for (int j = 0; j < sizeof(effects) / sizeof(Effect); ++j) {
            if (effects[j].name == nullptr) break; // Stop at the end marker
            // Then create new Object
            JsonObject effect = effectsArray.createNestedObject();
            effect["name"] = effects[j].name;
            effect["effect"] = effects[j].effect;
            JsonArray settingsArray = effect.createNestedArray("settings");

            for (int k = 0; k < sizeof(effects[j].settings) / sizeof(int); ++k) {
            if (effects[j].settings[k] == 0) break; // Stop at the end marker
            settingsArray.add(effects[j].settings[k]);
            }
        }
        // Convert the JSON document to a string
        // Send 200 OK
        String jsonString;
        serializeJson(doc, jsonString);
        request->send(200, "application/json", jsonString);
    });

    // Start server
    server->begin();
  
}

// Replaces placeholder with LED state value
String OutSideNetworking::processor(const String& var){
  Serial.println(var);
  if(var == "STATE"){
    if(digitalRead(ledPin)){
      ledState = "ON";
    }
    else{
      ledState = "OFF";
    }
    Serial.print(ledState);
    return ledState;
  }
  return String();
}