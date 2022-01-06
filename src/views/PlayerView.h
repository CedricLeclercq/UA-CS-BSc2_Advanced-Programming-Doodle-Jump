//
// Created by Cédric Leclercq on 04/01/2022.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYERVIEW_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYERVIEW_H

#include "View.h"
#include "../models/Entities.h"
#include "../observers/Observers.h"
#include "../observers/entityObservers/PlayerObserver.h"

class Views::PlayerView: public View {
private:
    bool texLoaded = false;
public:
    std::shared_ptr<Observers::PlayerObserver> observer;
    PlayerView()=default;
    explicit PlayerView(const std::shared_ptr<Entities::Player>& player);
    void setRocketTex();
    void setup() override;
    void setNormalTex();
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYERVIEW_H
