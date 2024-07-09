#include "stripecontroller.h"
#include <iostream>
#include "listeffects.h"
#include "XMLparser.h"
#include "listeffectsmapping.h"
#include "colormapping.h"
#include "const.h"

StripeController::StripeController() {
    
}

void StripeController::setup() {
    // Here we initialize the stripes using the data from the XML file
    // [TODO] Fetch all the data from the XML file
    // [TODO] Check the problem of constants

    // Variables from the XML document
    short int mode, direction, speed;
    uint32_t color1, color2, color3; // Do not need to be a constant
    int nb_stripes, data_pins;
    int ports[2];


    XMLDocument doc;
    XMLNodeList list;
    if(loadXMLDocument(&doc, "../../data/Machine.xml", &list) == 1) {
        // 1st function to retrieve the number of the function at start
        XMLNode* result = getNodeContent(&list, "functionStart");
        if(!strcmp(result->word, "none")) {
            mode = 0;
        } else {
            mode = atoi(result->word);
        }
        // 2nd function to retrieve the name of the function at start
        XMLNode* function_at_start = getNodeContent(&list, "function_at_start");
        mode = getFunctionNumber(function_at_start->word);

        // Here we'll get the colors
        result = getNodeContent(&list, "color1");
        color1 = getColorNumber(result->word);
        result = getNodeContent(&list, "color2");
        color2 = getColorNumber(result->word);
        result = getNodeContent(&list, "color3");
        color3 = getColorNumber(result->word);

        // Get number of stripes
        result = getNodeContent(&list, "number_of_stripes");
        nb_stripes = atoi(result->word);

        // Handle the data pins
        result = getNodeContent(&list, "number_of_data_pins");
        data_pins = atoi(result->word);
        for (int i = 0; i < nb_stripes; i++) {
            char str[10];
            sprintf(str, "%d", i+1);
            char node_title[] = "data_pin_";
            char * placeholder_name_data_pin = strcat(node_title, str);
            result = getNodeContent(&list, placeholder_name_data_pin);
            ports[i] = atoi(result->word);
        }
    }

    for (int i = 0; i < nb_stripes; i++) {
        stripesFA.emplace_back(ports[i], NUM_LEDS, direction,speed, mode, color1, color2, color3);
    }

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