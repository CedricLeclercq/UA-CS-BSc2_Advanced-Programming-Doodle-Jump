//
// Created by Cédric Leclercq on 18/11/2021.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYER_H

#include <utility>
#include <memory>

#include "../utilities/Utilities.h"


class Player {
private:
    std::unique_ptr<Utilities::Coordinates> mPlayerPosition;
    bool mLookLeft;
    float velocityY{};
public:
    Player() : mPlayerPosition(new Utilities::Coordinates(400.f,1000.f)) {
       this->mLookLeft = false;
    }

    void movePlayer(float offsetX, float offsetY);

    void setPlayerPosition(float posX, float posY);

    void moveRight();

    void moveLeft();

    void jump();

};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYER_H
