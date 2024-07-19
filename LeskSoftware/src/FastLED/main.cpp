#include <iostream>
#include "stripecontroller.h"
#include "XMLparser.h"
#include "outsidenetworking.h"
#include "jsonparser.h"

StripeController stripe_controller = StripeController();
AsyncWebServer server(80);
JSONParser parser = JSONParser();
OutSideNetworking outside_networking = OutSideNetworking(&server, &stripe_controller, &parser);



void setup() {
    Serial.begin(9600);
    XMLDocument XMLdoc;
    XMLNodeList XMLlist;
    XMLParser::loadXMLDocument(&XMLdoc, "Machine.xml", &XMLlist);
    parser.setupByXML(&XMLlist);
    stripe_controller.setup(XMLdoc, XMLlist);
    outside_networking.setup();
}

void loop() {
    Serial.println("Dans l'attente...");
    delay(5000);
}