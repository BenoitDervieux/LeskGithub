#include "jsonparser.h"

JSONParser::JSONParser() {
    
}

void JSONParser::setupByFile(const char* path) {
    this->path = path;
    // Initialize SPIFFS
    if(!SPIFFS.begin(true)){
        Serial.println("An Error has occurred while mounting SPIFFS");
        return ;
    }
    File filep = SPIFFS.open(path, "r");
    if (!filep) {
        Serial.println("Failed to open file");
        return;
    }

    size_t filesize = filep.size();
    Serial.println("File size: " + String(filesize));
    char* buffer = (char*) malloc(sizeof(char) * filesize + 1);
    char* bufferStart = buffer;
    int size = 0;
    char c;
     while (filep.available()) {
        c = filep.read();
        buffer[size] = c;
        size++;
    }
    buffer[size] = '\0';

    DeserializationError error = deserializeJson(this->doc, buffer);
    if (error) {
        printf("deserializeJson() failed: ");
        return ;
    }

    // Close the file (optional, but a good practice)
    filep.close();
    free(bufferStart);
}

void JSONParser::setupByXML(XMLNodeList* list) {
    // Note that most of those values have not been thought through or tested
    // I add things just to have something to add

    JsonDocument docToCreate;
    docToCreate["activated"] = true;
    docToCreate["effect"] = XMLParser::XMLNode_getWord(list, "function_at_start");
    docToCreate["brightness"] = XMLParser::XMLNode_getWord(list, "brightness_at_start");
    docToCreate["speed"] = XMLParser::XMLNode_getWord(list, "speed_at_start");
 
    docToCreate["color1"] = XMLParser::XMLNode_getWord(list, "color1");
    docToCreate["color2"] = XMLParser::XMLNode_getWord(list, "color2");
    docToCreate["color3"] = XMLParser::XMLNode_getWord(list, "color3");

    // Create a JSON array here
    JsonArray stripes = docToCreate.createNestedArray("stripes");
    for (int i = 0; i < atoi(XMLParser::XMLNode_getWord(list, "line_number")); i++) {
        JsonObject stripe = stripes.createNestedObject();
        stripe["name"] = i + 1;
        stripe["length"] = atoi(XMLParser::XMLNode_getWord(list, "line_length"));
        stripe["direction"] = atoi(XMLParser::XMLNode_getWord(list, "line_direction"));
    }
    docToCreate["palette"] = XMLParser::XMLNode_getWord(list, "palette_at_start");
    docToCreate["transition"] = atoi(XMLParser::XMLNode_getWord(list, "transition_at_start"));
    docToCreate["playlist"] = XMLParser::XMLNode_getWord(list, "playlist_at_start");

    // Here for potential lesk connection to graphs 
    docToCreate.createNestedArray("lesk_connections");

    // Here for the wifi password, maybe we can store several?
    JsonArray router_connection = docToCreate.createNestedArray("router_connection");
    JsonObject router_connection_object = router_connection.createNestedObject();
    router_connection_object["enabled"] = false;
    router_connection_object["wifi_name"] = XMLParser::XMLNode_getWord(list, "wifi_name");
    router_connection_object["wifi_password"] = XMLParser::XMLNode_getWord(list, "wifi_password");

    // Here for the controller collection
    JsonArray controller_connection = docToCreate.createNestedArray("controller_connection");
    JsonObject controller_connection_object = controller_connection.createNestedObject();
    controller_connection_object["enabled"] = false;
    controller_connection_object["controller_name"] = "None";

    // this->doc = docToCreate;

    // this->printDoc();

}   

void JSONParser::printDoc() {
    int size = measureJson(this->doc);
    printf("size of JSON: %d\n", size);
    char* buffer = (char*) malloc(sizeof(char) * size + 1);
    if( buffer == nullptr ) {
        Serial.println("malloc failed");
        return ;
    }

    serializeJson(this->doc, buffer, size + 1);
    buffer[size] = '\0';
    char* bufferStart = buffer;

    while (*buffer != '\0') {
        printf("%c", *buffer);
        buffer++;
    }
    printf("\n");
    free(bufferStart);
}

int JSONParser::getEffectNumber() {
    int effect = this->doc["effect"].as<int>();
    return effect;
}

int JSONParser::getBrightness() {
    int brightness = this->doc["brightness"].as<int>();
    return brightness;
}

int JSONParser::getSpeed() {
    int speed = this->doc["speed"].as<int>();
    return speed;
}
const char* JSONParser::getPalette() {
    const char* palette = this->doc["palette"].as<const char*>();
    return palette;
}
bool JSONParser::getActivated() {
    bool activated = this->doc["activated"].as<bool>();
    return activated;
}
int JSONParser::getTransition() {
    int transition = this->doc["transition"].as<int>();
    return transition;
}
const char* JSONParser::getPlaylist() {
    const char* playlist = this->doc["playlist_playing"].as<const char*>();
    return playlist;
}

bool JSONParser::isRouterConnectionEnabled() {
    JsonObject router_connection = doc["router_connection"];
    bool router_enabled = router_connection["enabled"];
    return router_enabled;
}
const char* JSONParser::getRouterSSID(){
    JsonObject router_connection = doc["router_connection"];
    const char* wifi_name = router_connection["wifi_name"];
    return wifi_name;
}

const char* JSONParser::getRouterPassword(){
    JsonObject router_connection = doc["router_connection"];
    const char* password = router_connection["password"];
    return password;
}

bool JSONParser::isControllerConnected() {
    JsonObject controller_connection = doc["controller_connection"];
    bool controller_connected = controller_connection["enabled"];
    return controller_connected;
}
const char* JSONParser::getControllerName(){
    JsonObject controller_connection = doc["controller_connection"];
    const char* name = controller_connection["name"];
    return name;
}

int JSONParser::getNumberOfStripes() {
    JsonArray stripes = doc["stripes"];
    int index = 0;
    for(JsonObject stripe : stripes) {
        index++;
    }
    return index;
}

int JSONParser::getNumberOfLeskConnections(){
    JsonArray connections = doc["lesk_connections"];
    int index = 0;
    for(JsonObject c : connections) {
        index++;
    }
    return index;
}


void JSONParser::setEffectNumber(int effectNumber) {
    this->doc["effect"] = effectNumber;
    char dest[20] = "EFF=";
    char effNum[10];
    sprintf(effNum, "%d", effectNumber);
    strncat(dest, effNum, 9);
    Notify(dest);
    // Need to think of the use of this function as we don't necessarily want to
    // write on the file everytime something happen
    // Wich means we might need to make doc static and public
    // writeOnDoc(this->path);
}

void JSONParser::increaseEffectNumber() {
    int effect = getEffectNumber();
    effect = (effect + 1) % 256;
    doc["effect"] = effect + 1;
    Serial.print("The effect is now : ");
    Serial.println(effect);
    // Notify();
    // writeOnDoc(this->path);
}

void JSONParser::decreaseEffectNumber() {
    int effect = getEffectNumber();
    effect--;
    if(effect < 0) effect = 255;
    doc["effect"] = effect;
    Serial.print("The effect is now : ");
    Serial.println(effect);
    // Notify();
    // writeOnDoc(this->path);
}

void JSONParser::setBrightness(int brightness) {
    this->doc["brightness"] = brightness;
    writeOnDoc(this->path);
}

void JSONParser::setSpeed(int speed) {
    this->doc["speed"] = speed;
    writeOnDoc(this->path);
}

void JSONParser::setPalette(const char* palette) {
    this->doc["palette"] = palette;
    writeOnDoc(this->path);
}

void JSONParser::setActivated(bool activated) {
    this->doc["activated"] = activated;
    writeOnDoc(this->path);
}

void JSONParser::setTransition(int transition) {
    this->doc["transition"] = transition;
    writeOnDoc(this->path);
}

void JSONParser::setPlaylist(const char* playlist) {
    this->doc["playlist_playing"] = playlist;
    writeOnDoc(this->path);
}

void JSONParser::setRouterConnectionEnabled(bool enabled) {
    JsonObject router_connection = doc["router_connection"];
    if (router_connection["enabled"] != enabled)
        router_connection["enabled"] = enabled;
    writeOnDoc(this->path);
}

void JSONParser::setRouterSSID(const char* ssid) {
    JsonObject router_connection = doc["router_connection"];
    if (strcmp(router_connection["wifi_name"], ssid) != 0)
        router_connection["wifi_name"] = ssid;
    writeOnDoc(this->path);
}

void JSONParser::setRouterPassword(const char* password) {
    JsonObject router_connection = doc["router_connection"];
    if (strcmp(router_connection["password"], password) != 0)
        router_connection["password"] = password;
    writeOnDoc(this->path);

}

void JSONParser::setControllerConnectionEnabled(bool enabled) {
    JsonObject controller_connection = doc["controller_connection"];
    if (controller_connection["enabled"] != enabled)
        controller_connection["enabled"] = enabled;
    writeOnDoc(this->path);

}
void JSONParser::setControllerName(const char* name) {
    JsonObject controller_connection = doc["controller_connection"];
    if (strcmp(controller_connection["name"], name) != 0)
        controller_connection["name"] = name;
    writeOnDoc(this->path);

}

void JSONParser::writeOnDoc(const char* path) const {

    int size = measureJson(this->doc);
    printf("size of JSON: %d\n", size);
    char* buffer = (char*) malloc(sizeof(char) * size + 1);
    serializeJson(this->doc, buffer, size + 1);
    buffer[size] = '\0';


    FILE* file = fopen(path, "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    fputs(buffer, file);
    fclose(file);
}


// Subscriber pattern here
void JSONParser::Add(SubscriberInterface* sub) {
    Serial.println("Point 888775: Adding subscriber");
            _subs.push_back(sub);
}

void JSONParser::Remove(SubscriberInterface* sub) {
    _subs.remove(sub);
}

void JSONParser::Notify(const char* message) {
    std::cout << "Notifying subscribers" << std::endl;
    if (_subs.empty()) {
        std::cout << "No subscribers" << std::endl;
        return;
    }
    std::list<SubscriberInterface*>::iterator it = _subs.begin();
    while (it != _subs.end()) {
        std::cout << "Notifying just right now" << std::endl;
        (*it)->Update(message);
        it++;
    }
}

// void JSONParser::AdvanceAndUpdateAll() {
//     static int num_updates = 0;
//     char buffer[20];
//     sprintf(buffer, "%d", ++num_updates);
//     std::string str(buffer);
//     _latest_message = "Update Number \"";
//     _latest_message += str;
//     _latest_message += "\" Processed";
//     Notify();
// }