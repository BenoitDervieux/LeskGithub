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
    Serial.println("Ca commence la machine....!!!!");
    XMLParser::loadXMLDocument(&XMLdoc, "Machine.xml", &XMLlist);
    Serial.println("Ca commence la machine2....!!!!");
    // Probleme est ici
    stripe_controller.setup(&XMLlist);
    Serial.println("Ca commence la machine3....!!!!");
    parser.setupByXML(&XMLlist);
    outside_networking.setup();
    parser.Add(&stripe_controller);

}

void loop() {
    stripe_controller.run();

    // Serial.println("Dans l'attente...");
    // delay(5000);
}