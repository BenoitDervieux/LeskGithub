#include "stripecontroller.h"
#include <iostream>
#include "listeffects.h"
#include "mappingeffects.h"
#include "mappingcolor.h"
#include "const.h"
#include "SPIFFS.h"

int StripeController::_unique_subscribers = 0;

StripeController::StripeController() {
    _unique_id = ++_unique_subscribers;
}

StripeController::~StripeController() {

}

void StripeController::setup(XMLNodeList* _XMLlist) {
    
    this->XMLlist = _XMLlist;
    // Variables from the XML document
    short int direction, speed;
    int nb_stripes, data_pins;
    int led_ports[2];

    // 1st function to retrieve the number of the function at start
    Settings::setEffect(getFunctionNumber(XMLParser::XMLNode_getWord(this->XMLlist, "function_at_start")));
    Settings::setEffect(2);
    // Here we'll get the colors
    Settings::setColor(getColorCRGB(XMLParser::XMLNode_getWord(this->XMLlist, "color1")));
    Settings::setColor2(getColorCRGB(XMLParser::XMLNode_getWord(this->XMLlist, "color2")));
    Settings::setColor3(getColorCRGB(XMLParser::XMLNode_getWord(this->XMLlist, "color3")));

    // Get number of stripes
    nb_stripes = atoi(XMLParser::XMLNode_getWord(this->XMLlist, "number_of_stripes"));

    // Handle the data pins
    data_pins = atoi(XMLParser::XMLNode_getWord(this->XMLlist, "number_of_data_pins"));
    for (int i = 0; i < nb_stripes; i++) {
        char str[10];
        sprintf(str, "%d", i+1);
        char node_title[] = "data_pin_";
        char * placeholder_name_data_pin = strcat(node_title, str);
        led_ports[i] = atoi(XMLParser::XMLNode_getWord(this->XMLlist, placeholder_name_data_pin));
    }
    // free(result);

    // Serial.println("Number of data pins: " + String(data_pins));
    // Serial.println("Number of stripes: " + String(nb_stripes));
    // Serial.println("Ports: " + String(led_ports[0]) + " " + String(led_ports[1]));
    // Serial.println("Effect: " + String(effect));

    //          @@         So here we have a buffer overflow, this might be due to the writing function
    //         @  @        from the XMLParser
    //        @    @       
    //       @  @@  @      [TODO] -> Fix that zeubi
    //      @   @@   @     
    //     @    @@    @    
    //    @            @   
    //   @      @+      @  
    //  @@@@@@@@@@@@@@@@@@ 
                
    // // Here it is a code to replace values in the XML file. 
    // // So far it works
    // Serial.println("Test replacing values...");
    // XMLNode* to_replace = XMLParser::getNodeContent(this->XMLlist, "wifi_name");
    // Serial.print("Get node content for wifi_name: ");
    // Serial.println(to_replace->word);
    // if (to_replace == NULL) {
    //     printf("No content\n");
    //     return;
    // }
    // XMLParser::replaceXMLtext("Machine.xml", "V&B", to_replace);
    // Serial.println("Done replacing values...");
    // printf("Content in the node: %s\n", XMLParser::XMLNode_getWord(this->XMLlist,  "wifi_name"));
    // XMLParser::XMLNodeList_free(XMLlist);

    for (int i = 0; i < nb_stripes; i++) {
        stripesFA.emplace_back(led_ports[i], NUM_LEDS, direction, speed, Settings::getEffect(), Settings::getColor(), Settings::getColor2(), Settings::getColor3());
    }

    Serial.println("Setup done");
}
void StripeController::run() {
    for (StripesFA& s: stripesFA) {
        // std::cout << "loop" << std::endl;
        s.setEffect(Settings::effect);
    }

    FastLED.show();
}

void StripeController::setColor(uint8_t red, uint8_t green, uint8_t blue) {
    std::cout << "Inside color function" << std::endl;

    for (auto& s: stripesFA) {
        std::cout << "Setting color inside controller" << std::endl;
        s.setColor(red, green, blue);
    }

}

void StripeController::setEffect(uint8_t _effect) {
    Settings::setEffect(_effect);
    for (auto& s: stripesFA) {
        std::cout << "Setting color inside controller" << std::endl;
        std::cout << "Effect: " << Settings::effect << std::endl;
        s.setEffect(Settings::getEffect());
    }
}

void StripeController::setBrightness(uint8_t brightness) {
    for (auto& s: stripesFA) {
        std::cout << "Setting color inside controller" << std::endl;
        s.setBrightness(brightness);
    }
}

int StripeController::getNumberOfStripes() {
    return stripesFA.size();  
}


std::vector<CRGB> StripeController::getColors1() {
    std::vector<CRGB> colors;
    for (auto& s: stripesFA) {
        colors.push_back(s.getColor1());
    }
    return colors;
}
std::vector<CRGB> StripeController::getColors2() {
    std::vector<CRGB> colors;
    for (auto& s: stripesFA) {
        colors.push_back(s.getColor2());
    }
    return colors;
}
std::vector<CRGB> StripeController::getColors3() {
    std::vector<CRGB> colors;
    for (auto& s: stripesFA) {
        colors.push_back(s.getColor3());
    }
    return colors;
}
std::vector<int> StripeController::getPorts() {
    std::vector<int> ports;
    for (auto& s: stripesFA) {
        ports.push_back(s.getPort());
    }
    return ports;
}
std::vector<int> StripeController::getLengths() {
    std::vector<int> lengths;
    for (auto& s: stripesFA) {
        lengths.push_back(s.getLength());
    }
    return lengths;
}
std::vector<int> StripeController::getDirections() {
    std::vector<int> directions;
    for (auto& s: stripesFA) {
        directions.push_back(s.getDirection());
    }
    return directions;
}
std::vector<uint8_t> StripeController::getEffects() {
    std::vector<uint8_t> effects;
    for (auto& s: stripesFA) {
        effects.push_back(s.getEffect());
    }
    return effects;
}


void StripeController::stop() {
    //[TODO]
    //Here eventually we can think of a constant boolean if it's 1 we can't proceed anyfunction we have
    // And the strip is black
}

// void StripeController::checkNode(const char * node) {

//     XMLDocument doc;
//     XMLNodeList list;
//     if(loadXMLDocument(&doc, "Machine.xml", &list) == 1) {
//             XMLNode* to_replace = getNodeContent(&list, node);
//             Serial.print("Get node content for wifi_name: ");
//             Serial.println(to_replace->word);
//     }


// }

// Pattern subscriber here

void  StripeController::Update(const std::string& message) {
    std::cout << "Update: " << message << std::endl;
    char prefix[10]; // prefix
    char suffixe[10]; // prefix
    int i = 0;
    int j = 0;
    int _s_p_choice = 0;
    while(message[i] != '\0') {
        if (_s_p_choice == 0) {
            prefix[i] = message[i];
            i++;
        } else {
            suffixe[i-j] = message[i];
            i++;
        }
        if (message[i] == '=') {
            prefix[i] = '\0';
            _s_p_choice = 1;
            i++;
            j = i;
        }
    }
    suffixe[i-j] = '\0';

    // printf("%s\n", prefix);
    // printf("%s\n", suffixe);

    switch(getSettingsNumber(prefix)) {
    case 1:
        this->setEffect(atoi(suffixe));
        break;
    default:
        // code block
        std::cout<< "Error" << std::endl;
    }
}