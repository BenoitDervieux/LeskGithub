#include <iostream>
#include "stripecontroller.h"
#include "XMLparser.h"
#include "outsidenetworking.h"
#include "jsonparser.h"

StripeController stripe_controller = StripeController();
AsyncWebServer server(80);
OutSideNetworking outside_networking = OutSideNetworking(&server, &stripe_controller);


void setup() {
    XMLDocument XMLdoc;
    XMLNodeList XMLlist;
    XMLParser::loadXMLDocument(&XMLdoc, "Machine.xml", &XMLlist);
    // JSONParser parser = JSONParser();
    // outside_networking.setParser(&parser);
    // parser.setupByXML(&XMLlist);
    Serial.begin(9600);
    stripe_controller.setup(XMLdoc, XMLlist);
    outside_networking.setup();
}

void loop() {
    Serial.println("Dans l'attente...");
    delay(5000);
}