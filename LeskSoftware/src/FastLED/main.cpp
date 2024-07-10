#include <iostream>
#include "stripecontroller.h"
#include "listeffects.h"
#include "XMLparser.h"

StripeController stripe_controller = StripeController();

void setup() {
    XMLDocument doc;
    XMLNodeList list;
    XMLParser::loadXMLDocument(&doc, "Machine.xml", &list);
    Serial.begin(9600);
    stripe_controller.setup(doc, list);
}

void loop() {
    Serial.println("Dans l'attente...");
    delay(5000);
}