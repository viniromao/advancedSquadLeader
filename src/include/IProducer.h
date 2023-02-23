#ifndef _I_PRODUCER_H_
#define _I_PRODUCER_H_

#include "include/IObserver.h"

class IProducer {
    public:
        virtual ~IProducer(){};
        virtual void attach(IObserver *observer) = 0;
        virtual void detach(IObserver *observer) = 0;
        virtual void notify() = 0;
};

#endif