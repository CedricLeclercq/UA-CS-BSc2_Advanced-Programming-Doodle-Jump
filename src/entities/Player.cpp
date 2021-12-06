//
// Created by Cédric Leclercq on 18/11/2021.
//

#include "Player.h"



void Player::moveRight() {
    this->move(0.5,0.f);
    if (this->mLookLeft) {
        this->move(-80,0.f);
    }
    this->mLookLeft = false;
}

void Player::moveLeft() {
    this->move(-0.5,0.f);
    if (not this->mLookLeft) {
        this->move(80,0.f);
    }
    this->mLookLeft = true;
}

void Player::jump() {
    // TODO change if statement below to <WHEN COLLISION OCCURS>
    if (this->position->getY() >= 800.f) {
        this->velocityY = 1;
        this->move(0,-this->velocityY);
    } else {
        this->velocityY -= 0.002;
        this->move(0,-this->velocityY);
    }
}

void Player::teleportPlayer(float minX, float maxX) {
    if (this->getPosX() < minX)
        this->setPosX(maxX);
    if (this->getPosX() > maxX)
        this->setPosX(minX);
}



