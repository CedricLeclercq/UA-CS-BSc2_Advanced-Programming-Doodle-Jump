//
// Created by Cédric Leclercq on 05/01/2022.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_BGTILEOBSERVER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_BGTILEOBSERVER_H

#include "../Observers.h"

class Observers::BGTileObserver: public Observer {
private:
    Coordinates curLocation{};
    bool remove{};
    bool create{};
    void notifyObserver() override {}
    bool getNotified() override {return false;}
public:
    BGTileObserver()=default;
    void notifyRemoved() {remove = true;}
    void notifyCreation() { create = true;}
    bool notifiedCreation() const {return create;}
    bool notifiedRemoval() const {return remove;}
    void resetObserver() override {create = false; remove = false;}
    void notifyCurLocation(Coordinates location) {curLocation = location;}
    Coordinates getNotifiedPosition() const {return this->curLocation;}
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_BGTILEOBSERVER_H
