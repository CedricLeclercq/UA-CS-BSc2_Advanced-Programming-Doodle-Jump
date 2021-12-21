// // // // // // // // // // // // // //
//                                     //
//             Player.cpp              //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#include "Player.h"



void Entities::Player::moveRight() {
    this->move((static_cast<float>(0.0005) * this->deltaTicksSpeedUp),0.f);
    if (this->mLookLeft) {
        //this->move(-0.1,0.f);
    }
    this->mLookLeft = false;
}

void Entities::Player::moveLeft() {
    this->move((static_cast<float>(-0.0005) * this->deltaTicksSpeedUp),0.f);
    if (not this->mLookLeft) {
        //this->move(0.1,0.f);
    }
    this->mLookLeft = true;
}

void Entities::Player::jump(bool newJump) {

    if (!this->paralysedY) {
        if (this->position->getY() <= 0 or newJump) {
            this->velocityY = static_cast<float>(0.6); // * this->deltaTicksSpeedUp;
            this->move(0, this->velocityY);
        } else {
            this->velocityY -= static_cast<float>(0.0005); //* this->deltaTicksSpeedUp;
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

void Entities::Player::setVelocityY(float velocity) {
    this->velocityY = velocity;
}

bool Entities::Player::getLookingLeft() const {
    return this->mLookLeft;

}

void Entities::Player::setBonus(std::shared_ptr<Entities::Bonus> nBonus) {
    this->bonus = std::move(nBonus);
}

std::shared_ptr<Entities::Bonus> Entities::Player::getBonus() const {
    return this->bonus;
}

void Entities::Player::setParalysed(bool paralysed) {
    this->paralysedY = paralysed;
}
