#include <iostream>
#include "stripecontroller.h"



StripeController stripe_controller = StripeController();
unsigned long startMillis; 
unsigned long currentMillis;
const unsigned long period = 3000;
bool lastBeat = false;

void setup() {
    Serial.begin(9600);
    stripe_controller.setup();
}

void loop() {

    delay(5000);
    Serial.println("Switched colors");
    stripe_controller.setColor(255, 0, 0);
    delay(5000);
    Serial.println("Switched colors");
    stripe_controller.setColor(0, 255, 0);
    delay(5000);
    Serial.println("Switched colors");
    stripe_controller.setColor(0, 0, 255);
}