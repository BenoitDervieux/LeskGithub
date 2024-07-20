#ifndef SUBSCRIBERINTERFACE_H
#define SUBSCRIBERINTERFACE_H

#include <string>
#include <iostream>

class SubscriberInterface {

    public:
        virtual ~SubscriberInterface() {};
        virtual void Update(const std::string& message) = 0;
};

#endif