#include <iostream>
#include "stripecontroller.h"
#include "listeffects.h"
#include "XMLparser.h"
#include "outsidenetworking.h"
#include "const.h"

StripeController stripe_controller = StripeController();
AsyncWebServer server(80);
OutSideNetworking outside_networking = OutSideNetworking(&server);


void setup() {
    XMLDocument XMLdoc;
    XMLNodeList XMLlist;
    XMLParser::loadXMLDocument(&XMLdoc, "Machine.xml", &XMLlist);
    Serial.begin(9600);
    stripe_controller.setup(XMLdoc, XMLlist);
    outside_networking.setup();
}

void loop() {
    Serial.println("Dans l'attente...");
    delay(5000);
}