#ifndef OUTSIDENETWORKING_H
#define OUTSIDENETWORKING_H

// Import required libraries
#include <WiFi.h>
// #include <AsyncTCP.h>
#include "ESPAsyncWebServer.h"
#include "SPIFFS.h"
#include "const.h"
#include <ArduinoJson.h>
#include "stripecontroller.h"
#include "mappingeffects.h"
#include "jsonparser.h"
#include "effectmanager.h"
#define FASTLED_INTERRUPT_RETRY_COUNT 5
#define FASTLED_ALLOW_INTERRUPTS 0


class OutSideNetworking {

    public :
        // OutSideNetworking(AsyncWebServer* server, StripeController* stripe_controller, JSONParser* parser);
        OutSideNetworking(AsyncWebServer* server, StripeController* stripe_controller, JSONParser* parser);
        void setup();
    private :
        static String processor(const String& var);
        AsyncWebServer* server;
        StripeController* stripe_controller;
        JSONParser* parser;
        

    private:
        
        
};



#endif