#ifndef STRIPECONTROLLER_H
#define STRIPECONTROLLER_H
#define FASTLED_INTERRUPT_RETRY_COUNT 5
#define FASTLED_ALLOW_INTERRUPTS 0

#include "stripesFA.h"
#include "XMLParser.h"
#include "subscriberInterface.h"
#include "color_functions.h"
#include "Settings.h"



class StripeController : public SubscriberInterface {

    public:
        StripeController();
        virtual ~StripeController();


        void setup(XMLNodeList* _XMLlist);
        void setColor(uint8_t red, uint8_t green, uint8_t blue);
        void setEffect(uint8_t effect);
        void setBrightness(uint8_t brightness);
        void run();
        void stop();
        int getNumberOfStripes();

        // Feels like we'll need to make some XML operations here, let's see...
        // void checkNode(const char * node);

        std::vector<CRGB> getColors1();
        std::vector<CRGB> getColors2();
        std::vector<CRGB> getColors3();
        std::vector<int> getPorts();
        std::vector<int> getLengths();
        std::vector<int> getDirections();
        std::vector<uint8_t> getEffects();
        int getEffect();

        void Update(const std::string& message) override;
    

    private:
        std::vector<StripesFA> stripesFA;
        XMLNodeList* XMLlist;
        int _unique_id = -1;
        static int _unique_subscribers;

};


#endif