//
// Created by Cédric Leclercq on 26/12/2021.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYEROBSERVER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYEROBSERVER_H

#include "../Observers.h"

class Observers::PlayerObserver: public Observer {
private:
    bool playerChanged{};
    bool isRocket{};
    PlayerObserver()=default;
public:
    static PlayerObserver& getInstance();
    void notifyObserver() override;
    bool getNotified() override;
    void resetObserver() override;
    bool getIsRocket() const;
    void setIsRocket(bool newBool);
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYEROBSERVER_H
