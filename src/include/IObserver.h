#ifndef _I_OBSERVER_H_
#define _I_OBSERVER_H_

#include <string.h>

using namespace std;

class IObserver{
  public:
    virtual ~IObserver(){};
    virtual void update(const string &message) = 0;
};

#endif



