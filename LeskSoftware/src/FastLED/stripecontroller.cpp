#include "stripecontroller.h"
#include <iostream>
#include "listeffects.h"
#include "mappingeffects.h"
#include "colormapping.h"
#include "const.h"
#include "SPIFFS.h"



StripeController::StripeController() {
    _unique_id = ++_unique_subscribers;
}

void StripeController::setup(XMLNodeList* _XMLlist) {
    
    this->XMLlist = _XMLlist;
    // Variables from the XML document
    short int effect, direction, speed;
    uint32_t color1, color2, color3; // Do not need to be a constant
    int nb_stripes, data_pins;
    int led_ports[2];

    // effect = 0;
    // direction = 1;
    // speed = 100;
    // color1 = 0xFF0000;
    // color2 = 0x00FF00;
    // color3 = 0x0000FF;
    // nb_stripes = 2;
    // data_pins = 2;
    // ports[0] = 23;
    // ports[1] = 18;

    // 1st function to retrieve the number of the function at start
    Serial.println("Point 949");
    Serial.println(XMLParser::XMLNode_getWord(this->XMLlist, "function_at_start"));
    effect = getFunctionNumber(XMLParser::XMLNode_getWord(this->XMLlist, "function_at_start"));
    Serial.println("Point 950");
    // Here we'll get the colors
    color1 = getColorNumber(XMLParser::XMLNode_getWord(this->XMLlist, "color1"));
    color2 = getColorNumber(XMLParser::XMLNode_getWord(this->XMLlist, "color2"));
    color3 = getColorNumber(XMLParser::XMLNode_getWord(this->XMLlist, "color3"));

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

        Serial.println("Number of data pins: " + String(data_pins));
        Serial.println("Number of stripes: " + String(nb_stripes));
        Serial.println("Ports: " + String(led_ports[0]) + " " + String(led_ports[1]));
        Serial.println("Effect: " + String(effect));
        Serial.println("Color 1: " + String(color1));
        Serial.println("Color 2: " + String(color2));
        Serial.println("Color 3: " + String(color3));

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
        stripesFA.emplace_back(led_ports[i], NUM_LEDS, direction, speed, effect, color1, color2, color3);
    }

    Serial.println("Setup done");

}


void StripeController::run() {

    FastLED.show();
}

void StripeController::setColor(uint8_t red, uint8_t green, uint8_t blue) {
    std::cout << "Inside color function" << std::endl;

    for (auto& s: stripesFA) {
        std::cout << "Setting color inside controller" << std::endl;
        s.setColor(red, green, blue);
    }

}

void StripeController::setEffect(uint8_t effect) {
    for (auto& s: stripesFA) {
        std::cout << "Setting color inside controller" << std::endl;
        std::cout << "Effect: " << effect << std::endl;
        s.setEffect(effect);
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


std::vector<uint32_t> StripeController::getColors1() {
    std::vector<uint32_t> colors;
    for (auto& s: stripesFA) {
        colors.push_back(s.getColor1());
    }
    return colors;
}
std::vector<uint32_t> StripeController::getColors2() {
    std::vector<uint32_t> colors;
    for (auto& s: stripesFA) {
        colors.push_back(s.getColor2());
    }
    return colors;
}
std::vector<uint32_t> StripeController::getColors3() {
    std::vector<uint32_t> colors;
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

void Update(const std::string& message) {
    std::cout << "Update: " << message << std::endl;
}