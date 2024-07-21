#ifndef PARSERSUBJECTINTERFACE_H
#define PARSERSUBJECTINTERFACE_H

#include "subscriberInterface.h"

class ParserSubjectInterface {
public:
    virtual ~ParserSubjectInterface() {};
    virtual void Add(SubscriberInterface* subscriber) = 0;
    virtual void Remove(SubscriberInterface* subscriber) = 0;
    virtual void Notify(const char* message) = 0;
};



#endif