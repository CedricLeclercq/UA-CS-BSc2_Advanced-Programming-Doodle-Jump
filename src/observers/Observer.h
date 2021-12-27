//
// Created by Cédric Leclercq on 26/12/2021.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_OBSERVER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_OBSERVER_H


class Observer {
public:
    virtual void notifyObserver() = 0;
    virtual bool getNotified() = 0;
    virtual void resetObserver() = 0;
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_OBSERVER_H
