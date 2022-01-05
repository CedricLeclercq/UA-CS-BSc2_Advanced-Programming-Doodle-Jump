//
// Created by Cédric Leclercq on 26/12/2021.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYEROBSERVER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYEROBSERVER_H

#include "../Observers.h"


class Observers::PlayerObserver: public Observer {
private:
    Coordinates curLocation{};
    bool isRocket{};
    void notifyObserver() override;
    bool getNotified() override;
    void resetObserver() override;
public:
    PlayerObserver()=default;
    bool getNotifiedRocket() const;
    void notifyIsRocket(bool newBool);
    void notifyCurLocation(Coordinates location) {curLocation = location;}
    Coordinates getNotifiedPosition() const {return this->curLocation;}
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYEROBSERVER_H
