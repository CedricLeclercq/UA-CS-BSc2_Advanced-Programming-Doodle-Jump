//
// Created by Cédric Leclercq on 18/11/2021.
//

#include "Player.h"



void Entities::Player::moveRight() {
    this->move(0.0005,0.f);
    if (this->mLookLeft) {
        //this->move(-0.1,0.f);
    }
    this->mLookLeft = false;
}

void Entities::Player::moveLeft() {
    this->move(-0.0005,0.f);
    if (not this->mLookLeft) {
        //this->move(0.1,0.f);
    }
    this->mLookLeft = true;
}

void Entities::Player::jump(bool newJump) {

    if (!this->paralysedY) {
        if (this->position->getY() <= 0 or newJump) {
            this->velocityY = 0.6;
            this->move(0, this->velocityY);
        } else {
            this->velocityY -= 0.0005;
            this->move(0, this->velocityY);
        }
    }

    // Removing bonus is it is exhausted
    if (this->bonus != nullptr and this->bonus->exhaustedBonus()) {
        this->paralysedY = false;
        this->bonus = nullptr;
    } else if (this->bonus != nullptr) {
        // else applying the bonus
        this->bonus->takeEffect(*this);
    }
}

void Entities::Player::teleportPlayer(float minX, float maxX) {
    if (this->getPosX() * maxX < minX)
        this->setPosX(1);
    if (this->getPosX() * maxX > maxX)
        this->setPosX(0);
}
