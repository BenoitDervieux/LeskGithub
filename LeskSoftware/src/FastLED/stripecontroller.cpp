#include "stripecontroller.h"
#include <iostream>
#include "listeffects.h"
#include "XMLparser.h"
#include "listeffectsmapping.h"

StripeController::StripeController() {
    
}

void StripeController::setup() {
    // Here we initialize the stripes using the data from the XML file
    // [TODO] Fetch all the data from the XML file
    // [TODO] Check the problem of constants
    XMLDocument doc;
    XMLNodeList list;
    short int mode = 0;
    if(loadXMLDocument(&doc, "../../data/Machine.xml", &list) == 1) {
        // 1st function to retrieve the number of the function at start
        XMLNode* functionStart = getNodeContent(&list, "functionStart");
        if(!strcmp(functionStart->word, "none")) {
            mode =0;
        } else {
            mode = atoi(functionStart->word);
        }
        // 2nd function to retrieve the name of the function at start
        XMLNode* function_at_start = getNodeContent(&list, "function_at_start");
        mode = getFunctionNumber(function_at_start->word);
    }

    int port = 18; // Should be a constant
    int length = 10; // Should be a constant

    int direction = 1; // Do not need to be a constant
    // [TODO] --> Let's have 3 colors in total
    uint32_t color = 0xFF0000; // Do not need to be a constant

    // Simulate the number of stripes fetched
    int nb_stripes = 1; // Do not need to be a constant

    //*************************************
    for (int i = 0; i < nb_stripes; i++) {
        stripesFA.emplace_back(port, length, direction, mode, color);
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