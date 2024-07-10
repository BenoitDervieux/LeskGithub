#ifndef STRIPECONTROLLER_H
#define STRIPECONTROLLER_H

#include "stripesFA.h"
#include "XMLParser2.h"


class StripeController {

    public:
        StripeController();
        void setup(XMLDocument _doc, XMLNodeList _list);
        void setColor(uint8_t red, uint8_t green, uint8_t blue);
        void setEffect(uint8_t effect);
        void setBrightness(uint8_t brightness);
        void run();
        void stop();
        int getNumberOfStripes();

        // Feels like we'll need to make some XML operations here, let's see...
        // void checkNode(const char * node);

        std::vector<uint32_t> getColors1();
        std::vector<uint32_t> getColors2();
        std::vector<uint32_t> getColors3();
        std::vector<int> getPorts();
        std::vector<int> getLengths();
        std::vector<int> getDirections();
        std::vector<uint8_t> getEffects();
    

    private:
        std::vector<StripesFA> stripesFA;
        XMLDocument* doc;
        XMLNodeList* list;

        

};


#endif