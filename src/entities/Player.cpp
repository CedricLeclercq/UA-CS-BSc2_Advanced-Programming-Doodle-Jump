//
// Created by Cédric Leclercq on 18/11/2021.
//

#include "Player.h"

void Player::movePlayer(float offsetX, float offsetY)  {
    this->mPlayerPosition->setX(this->mPlayerPosition->getX() + offsetX);
    this->mPlayerPosition->setY(this->mPlayerPosition->getY() + offsetY);
}

void Player::setPlayerPosition(float posX, float posY) {
    this->mPlayerPosition->setX(posX);
    this->mPlayerPosition->setY(posY);
}

void Player::moveRight() {
    this->movePlayer(0.5,0.f);
    if (this->mLookLeft) {
        this->movePlayer(-80,0.f);
    }
}

void Player::moveLeft() {
    this->movePlayer(-0.5,0.f);
    if (not this->mLookLeft) {
        this->movePlayer(80,0.f);
    }
}

void Player::jump() {
    // TODO change if statement below to <WHEN COLLISION OCCURS>
    if (this->mPlayerPosition->getY() >= 1000.f) {
        this->velocityY = 1;
        this->movePlayer(0,-this->velocityY);
    } else {
        this->velocityY -= 0.002;
        this->movePlayer(0,-this->velocityY);
    }
}



