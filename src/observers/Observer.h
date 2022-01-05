//
// Created by Cédric Leclercq on 26/12/2021.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_OBSERVER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_OBSERVER_H

#include <utility>

#include "utilities/Utilities.h"
using Coordinates = Utilities::Coordinates;

class Observer {
private:
    bool notified{};
public:
    Observer()=default;
    virtual void notifyObserver() {notified = true;}
    virtual bool getNotified() {return notified;}
    virtual void resetObserver() {notified = false;}
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_OBSERVER_H
