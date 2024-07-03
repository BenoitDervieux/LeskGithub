#include <iostream>
#include "stripecontroller.h"
#include "listeffects.h"

StripeController stripe_controller = StripeController();

void setup() {
    Serial.begin(9600);
    stripe_controller.setup();
}

void loop() {

    delay(5000);
    Serial.println("Switched effect");
    stripe_controller.setEffect(FILL);
    delay(5000);
    Serial.println("Switched effect");
    stripe_controller.setEffect(RAINBOW);
    delay(5000);
    Serial.println("Switched effect");
    stripe_controller.setEffect(GRADIENT_RGB);
}