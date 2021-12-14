//
// Created by Cédric Leclercq on 18/11/2021.
//

#include "Player.h"



void Player::moveRight() {
    this->move(0.0012,0.f);
    if (this->mLookLeft) {
        this->move(-0.1,0.f);
    }
    this->mLookLeft = false;
}

void Player::moveLeft() {
    this->move(-0.0012,0.f);
    if (not this->mLookLeft) {
        this->move(0.1,0.f);
    }
    this->mLookLeft = true;
}

void Player::jump() {
    if (this->position->getY() <= this->positionBeforeJumpY) {
        this->positionBeforeJumpY = this->position->getY();
        this->velocityY = this->standardVelocityY;
        this->move(0,this->velocityY);
    } else {
        this->velocityY -= 0.0005;
        //std::cout << this->standardVelocityY;
        this->move(0,this->velocityY);
    }
}

void Player::teleportPlayer(float minX, float maxX) {
    if (this->getPosX() * maxX < minX)
        this->setPosX(1);
    if (this->getPosX() * maxX > maxX)
        this->setPosX(0);
}
