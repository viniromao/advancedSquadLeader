#ifndef _CLICK_EVENT_PRODUCER_H_
#define _CLICK_EVENT_PRODUCER_H_

#include <iostream>
#include <list>
#include <string>

#include "include/IProducer.h"

using namespace std;

class ClickEventProducer : public IProducer {
    public:
        virtual ~ClickEventProducer() {}
        
        void attach(IObserver *observer) override {
            list_observer_.push_back(observer);
        }
        void detach(IObserver *observer) override {
            list_observer_.remove(observer);
        }
        void notify() override {
            list<IObserver *>::iterator iterator = list_observer_.begin();
            howManyObserver();
            while (iterator != list_observer_.end()) {
            (*iterator)->update(message_);
            ++iterator;
            }
        }

        void createMessage(string message = "Empty") {
            this->message_ = message;
            notify();
        }
        void howManyObserver() {
            cout << "There are " << list_observer_.size() << " observers in the list.\n";
        }

        /**
         * Usually, the subscription logic is only a fraction of what a Subject can
         * really do. Subjects commonly hold some important business logic, that
         * triggers a notification method whenever something important is about to
         * happen (or after it).
         */
        void someBusinessLogic() {
            this->message_ = "change message message";
            notify();
            cout << "I'm about to do some thing important\n";
        }

    private:
        list<IObserver *> list_observer_;
        string message_;
        
};

#endif