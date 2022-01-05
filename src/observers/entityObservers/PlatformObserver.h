//
// Created by Cédric Leclercq on 05/01/2022.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_PLATFORMOBSERVER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_PLATFORMOBSERVER_H

#include "../Observers.h"

class Observers::PlatformObserver: public Observer {
private:
    Coordinates curLocation{};
    bool remove{};
    bool create{};
    void notifyObserver() override {}
    bool getNotified() override {return false;}
public:
    PlatformObserver()=default;
    void notifyRemoved() {remove = true;}
    void notifyPlatformCreation() {create = true;}
    bool notifiedCreation() const {return create;}
    bool notifiedRemoval() const {return remove;}
    void resetObserver() override {create = false; remove = false;}
    void notifyCurLocation(Coordinates location) {curLocation = location;}
    Coordinates getNotifiedPosition() const {return this->curLocation;}
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_PLATFORMOBSERVER_H
