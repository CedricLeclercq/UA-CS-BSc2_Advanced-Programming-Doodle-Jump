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
    float standardVelocityY{};
    float positionBeforeJumpY{};
public:
    Player() {
        this->standardVelocityY = 1;
        this->position = std::make_shared<Utilities::Coordinates>(0.5,0.f);
        this->positionBeforeJumpY = this->getPosY();
        this->mLookLeft = false;
    }

    void moveRight() override;

    void moveLeft() override;

    void jump(bool newJump=false);

    bool getLookingLeft() const {
        return this->mLookLeft;
    }

    float getVelocityY() const {
        return this->velocityY;
    }

    void teleportPlayer(float minX, float maxX);


};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYER_H
