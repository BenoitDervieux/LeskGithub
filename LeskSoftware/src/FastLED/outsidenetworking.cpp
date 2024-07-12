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

  // // Route for root / web page
  // server->on("/", HTTP_GET, [this](AsyncWebServerRequest *request){
  //   request->send(SPIFFS, "/index.html", String(), false, processor);
  // });
  
  // // Route to load style.css file
  // server->on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request){
  //   request->send(SPIFFS, "/style.css", "text/css");
  // });

  // // Route to set GPIO to HIGH
  // server->on("/on", HTTP_GET, [](AsyncWebServerRequest *request){
  //   digitalWrite(ledPin, HIGH);    
  //   request->send(SPIFFS, "/index.html", String(), false, processor);
  // });
  
  // // Route to set GPIO to LOW
  // server->on("/off", HTTP_GET, [](AsyncWebServerRequest *request){
  //   digitalWrite(ledPin, LOW);    
  //   request->send(SPIFFS, "/index.html", String(), false, processor);
  // });

  // // Start server
  // server->begin();

  // Route to serve the collections as JSON
  // Route to serve the collections as JSON
  server->on("/collections", HTTP_GET, [](AsyncWebServerRequest *request){
    DynamicJsonDocument doc(2048); // Adjust size as needed
    JsonArray collectionsArray = doc.createNestedArray("collections");

    for (int i = 0; i < sizeof(collections) / sizeof(collections[0]); ++i) {
      JsonObject collection = collectionsArray.createNestedObject();
      collection["name"] = collections[i].name;
      JsonArray effectsArray = collection.createNestedArray("effects");

      for (int j = 0; j < sizeof(collections[i].effect) / sizeof(Effect); ++j) {
        if (collections[i].effect[j].name == nullptr) break; // Stop at the end marker

        JsonObject effect = effectsArray.createNestedObject();
        effect["name"] = collections[i].effect[j].name;
        effect["effect"] = collections[i].effect[j].effect;
        JsonArray settingsArray = effect.createNestedArray("settings");

        for (int k = 0; k < sizeof(collections[i].effect[j].settings) / sizeof(int); ++k) {
          if (collections[i].effect[j].settings[k] == 0) break; // Stop at the end marker
          settingsArray.add(collections[i].effect[j].settings[k]);
        }
      }
    }

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