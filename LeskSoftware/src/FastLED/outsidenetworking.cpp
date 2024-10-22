#include "outsidenetworking.h"
#include "listcollections.h"
#include "../../.variables/variables.h"


String ledState;   // Define the variable
EffectManager effectManager;

OutSideNetworking::OutSideNetworking(AsyncWebServer* _server, StripeController* _stripe_controller, JSONParser* _parser) :
         server(_server), stripe_controller(_stripe_controller), parser(_parser) { }

void OutSideNetworking::setup() {

  // Initialize SPIFFS
  if(!SPIFFS.begin(true)){
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

  const char* ssid = SSID; 
  const char* password = SSID_PASSWORD;

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
    server->on("/effects", HTTP_GET, [this](AsyncWebServerRequest *request){
      if (request->args() > 0) {
        for (int i = 0; i < request->args(); i++) {
          // Serial.println(request->arg(i));
          const char * argName = request->arg(i).c_str();
          // Serial.print("Test du const char : ");
          // Serial.println(argName);
          // Serial.print("Test du get function Number : ");
          // Serial.println(getFunctionNumber(argName));
          this->stripe_controller->setEffect(getFunctionNumber(argName));
        }
      }
      request->send(SPIFFS, "/effects.html", "text/html");
    });

    server->on("/effects", HTTP_POST, [this](AsyncWebServerRequest *request){

      // Here we will implement the logic for the subscriber pattern
      if (request->hasParam("effect", true)) {
        String effect = request->getParam("effect", true)->value();
        Serial.println("Point 454: Print the effect");
        Serial.println(effect);
        Serial.println("Point 455: Check effect number");
        Serial.println(getFunctionNumber(effect.c_str()));
        // unsigned long startTime = millis();
        parser->setEffectNumber(getFunctionNumber(effect.c_str()));
        // unsigned long endTime = millis();
        // Serial.print("Time taken to set effect: ");
        // Serial.println(endTime - startTime);
        // Set the effect here
        // Handle the effect change logic here
        request->send(200, "text/plain", "Effect changed to " + effect);
      } else {
        request->send(400, "text/plain", "Bad Request");
      }
    });

    server->on("/setSetting", HTTP_POST, [this](AsyncWebServerRequest *request) {
      // Check if the "setting" and "value" parameters are present in the POST request
      if (request->hasParam("setting", true) && request->hasParam("value", true)) {
          // Correct parameter names: "setting" for the setting name, and "value" for the new value
          String settingName = request->getParam("setting", true)->value(); // Get setting name
          int newValue = request->getParam("value", true)->value().toInt(); // Get new value
          // Serial.print("The setting is: ");
          // Serial.println(settingName);
          // Serial.print("The value is: ");
          // Serial.println(newValue);
          // Call the effect manager to update the setting
          // unsigned long startTime = millis();
          effectManager.setSetting(settingName, newValue); // Update the setting
          // unsigned long endTime = millis();
          // Serial.print("Time taken to set setting: ");
          // Serial.println(endTime - startTime);
          // Respond with a success message
          request->send(200, "text/plain", "Effect changed: " + settingName);
      } else {
          // Respond with a 400 error if required parameters are missing
          request->send(400, "text/plain", "Bad Request: Missing parameters");
      }
  });


    server->on("/api/setEffect", HTTP_GET, [this](AsyncWebServerRequest *request){
      if (request->args() > 0) {
        for (int i = 0; i < request->args(); i++) {
          // Serial.println(request->arg(i));
          const char * argName = request->arg(i).c_str();
          // Serial.print("Pt 987: Test du const char : ");
          // Serial.println(argName);
          // Serial.print("Pt 988: Test du get function Number : ");
          // Serial.println(getFunctionNumber(argName));
          this->stripe_controller->setEffect(getFunctionNumber(argName));
        }
      }
      request->send(200, "application/json");
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

            for (int k = 0; k < sizeof(collections[i].effect[j].settingNames) / sizeof(int); ++k) {
            if (collections[i].effect[j].settingNames[k] == 0) break; // Stop at the end marker
            settingsArray.add(collections[i].effect[j].settingNames[k]);
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
                    // Serial.println(request->getParam("name")->value());
                    // Serial.println(collections[i].name);
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

                        for (int k = 0; k < sizeof(collections[i].effect[j].settingNames) / sizeof(int); ++k) {
                        if (collections[i].effect[j].settingNames[k] == 0) break; // Stop at the end marker
                        settingsArray.add(collections[i].effect[j].settingNames[k]);
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
        // I think it fetches it from the class listeffects
        for (int j = 0; j < sizeof(effects) / sizeof(Effect); ++j) {
            if (effects[j].name == nullptr) break; // Stop at the end marker
            // Then create new Object
            JsonObject effect = effectsArray.createNestedObject();
            effect["name"] = effects[j].name;
            effect["effect"] = effects[j].effect;
            JsonArray settingsArray = effect.createNestedArray("settings");

            for (int k = 0; k < sizeof(effects[j].settingNames) / sizeof(int); ++k) {
            if (effects[j].settingNames[k] == 0) break; // Stop at the end marker
            settingsArray.add(effects[j].settingNames[k]);
            }
        }
        // Convert the JSON document to a string
        // Send 200 OK
        String jsonString;
        serializeJson(doc, jsonString);
        request->send(200, "application/json", jsonString);
    });

    server->on("/api/settings", HTTP_GET, [this](AsyncWebServerRequest *request) {
      DynamicJsonDocument doc(2048); // Adjust size as needed
      JsonArray effectsArray = doc.createNestedArray("Settings");
      int num_effect = parser->getEffectNumber() - 1;
      // Serial.print("Le num de l'effet par controlleur est: ");
      // Serial.println(num_effect);
      // Serial.print("Le num de l'effet par parseur est: ");
      // Serial.println(parser->getEffectNumber());

            if (effects[num_effect].name == nullptr) return; // Stop at the end marker
            // Then create new Object
            JsonObject effect = effectsArray.createNestedObject();
            effect["name"] = effects[num_effect].name;
            effect["effect"] = effects[num_effect].effect;
            JsonArray settingsArray = effect.createNestedArray("settings");

            for (int k = 0; k < effects[num_effect].numSettings; ++k) {
            if (effects[num_effect].settingNames[k] == 0) break; // Stop at the end marker
            JsonObject setting = settingsArray.createNestedObject();
            setting["name"] = effects[num_effect].settingNames[k];
            setting["minValue"] = effects[num_effect].minValues[k];
            setting["maxValue"] = effects[num_effect].maxValues[k];
            setting["realNames"] = effects[num_effect].realNames[k];
            setting["values"] = effects[num_effect].settings[k]();
            // Serial.print("Setting name: ");
            // Serial.println(effects[num_effect].settingNames[k]);
       
            // settingsArray.add(effects[num_effect].settingNames[k]);
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



