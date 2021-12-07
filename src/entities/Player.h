//
// Created by Cédric Leclercq on 18/11/2021.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYER_H


#include <memory>

#include "Entity.h"


class Player: public Entity {
private:
    bool mLookLeft;
    float velocityY{};
public:
    Player() {
        this->position = std::make_shared<Utilities::Coordinates>(400.f,800.f);
        this->mLookLeft = false;
    }

    void moveRight() override;

    void moveLeft() override;

    void jump();

    bool getLookingLeft() const {
        return this->mLookLeft;
    }

    void teleportPlayer(float minX, float maxX);


};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYER_H
