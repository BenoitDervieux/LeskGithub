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



class OutSideNetworking {

    public :
        OutSideNetworking(AsyncWebServer* server, StripeController* stripe_controller);
        void setup();
    private :
        static String processor(const String& var);
        AsyncWebServer* server;
        StripeController* stripe_controller;
        

    private:
        
        
};



#endif