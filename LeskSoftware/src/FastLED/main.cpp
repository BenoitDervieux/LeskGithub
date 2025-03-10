#include <iostream>
#include "stripecontroller.h"
#include "XMLparser.h"
#include "outsidenetworking.h"
#include "jsonparser.h"
#include "insideNetworking2.h"
#define FASTLED_INTERRUPT_RETRY_COUNT 5
#define FASTLED_ALLOW_INTERRUPTS 0


StripeController stripe_controller = StripeController();
AsyncWebServer server(80);
JSONParser parser = JSONParser();
// InsideNetworking inside_networking = InsideNetworking();
InsideNetworking2 inside_networking;
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
    Serial.println("Ca commence la machine 4....!!!!");
    inside_networking.setup();
    outside_networking.setup();
    parser.Add(&stripe_controller);

}

void loop() {
    stripe_controller.run();

    // Serial.println("Dans l'attente...");
    // delay(5000);
}