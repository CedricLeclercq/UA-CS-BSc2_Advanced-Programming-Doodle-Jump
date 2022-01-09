// // // // // // // // // // // // // //
//                                     //
//             Player.cpp              //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#include "Player.h"



void Entities::Player::moveRight() {
    this->move((static_cast<float>(0.0008) * Utilities::Stopwatch::getInstance().getDeltaTicks()),0.f);
    observer->notifyCurLocation(*this->position);
}

void Entities::Player::moveLeft() {
    this->move((static_cast<float>(-0.0008) * Utilities::Stopwatch::getInstance().getDeltaTicks()),0.f);
    observer->notifyCurLocation(*this->position);
}


void Entities::Player::jump(bool newJump) {
    std::cout << this->position->getX() << " " << this->position->getY() << std::endl;

    if (!this->paralysedY) {
        if (this->position->getY() <= 0 or newJump) {
            this->velocityY = static_cast<float>(1); // * this->deltaTicksSpeedUp;
            this->move(0, this->velocityY * Utilities::Stopwatch::getInstance().getDeltaTicks());
            observer->notifyCurLocation(*this->position);
        } else {
            this->velocityY -= static_cast<float>(0.001875) * Utilities::Stopwatch::getInstance().getDeltaTicks(); //* this->deltaTicksSpeedUp;
            this->move(0, this->velocityY * Utilities::Stopwatch::getInstance().getDeltaTicks());
            observer->notifyCurLocation(*this->position);
        }
    }

    // Removing bonus is it is exhausted
    if (bonus != nullptr) {
        this->bonus->takeEffect(*this);
    }
}

void Entities::Player::teleportPlayer(float minX, float maxX) {
    if (this->getPosX() * maxX < minX)
        this->setPosX(1);
    if (this->getPosX() * maxX > maxX)
        this->setPosX(0);
}

void Entities::Player::setVelocityY(float velocity) {
    this->velocityY = velocity;
}

void Entities::Player::setBonus(std::shared_ptr<Entities::Bonus> nBonus) {
    if (nBonus != nullptr and nBonus->getPowerKind() == BonusPower::ROCKET)
        this->observer->notifyIsRocket(true);
    this->bonus = std::move(nBonus);
}

void Entities::Player::setParalysed(bool paralysed) {
    this->paralysedY = paralysed;
}

Entities::Player::Player(): observer(std::make_shared<Observers::PlayerObserver>()) {
    this->position = std::make_shared<Utilities::Coordinates>(0.5, 0.f);
    this->paralysedY = false;
}

