#ifndef _CLICK_EVENT_OBSERVER_H_
#define _CLICK_EVENT_OBSERVER_H_

#include <iostream>
#include <list>
#include <string>

#include "include/IObserver.h"
#include "include/ClickEventProducer.h"

using namespace std;

class ClickEventObserver: public IObserver{
  public:
    ClickEventObserver(ClickEventProducer &subject) : producer(subject) {
      this->producer.attach(this);
      this->number_ = ClickEventObserver::static_number_;
    }

    virtual ~ClickEventObserver() {
      cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
    }

    void update(const string &message_from_subject) override {
      message_from_subject_ = message_from_subject;
      printInfo();
    }
    void RemoveMeFromTheList() {
      producer.detach(this);
      cout << "Observer \"" << number_ << "\" removed from the list.\n";
    }
    void printInfo() {
      cout << "Observer \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << "\n";
    }

  private:
    string message_from_subject_;
    ClickEventProducer &producer;
    static int static_number_;
    int number_;
};

#endif



