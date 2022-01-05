// // // // // // // // // // // // // //
//                                     //
//            Platform.cpp             //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#include "Platform.h"

using Random = Utilities::Random;

void Entities::Platform::createPlatform() {
    // Check if the platform type was pre-defined at construction
    if (this->platformKind != UNDEF) {
        if (this->platformKind == STATIC)
            this->makeStatic(); // Static platform was pre-defined
        if (this->platformKind == HORIZONTAL)
            this->makeHorizontal(); // Horizontal platform was pre-defined
        if (this->platformKind == VERTICAL)
            this->makeVertical(); // Vertical platform was pre-defined
        if (this->platformKind == TEMP)
            this->makeTemp(); // Temporary platform was pre-defined
    }

    // Else generating platform based on the chance for each one to generate
    int chance = Random::getInstance().randInt(1,10);
    if (chance <= 7) {
        // 70% chance of creating a static platform
        this->makeStatic();
    } else if (chance == 8) {
        // 10% chance of creating a temporary platform
        this->makeTemp();
    } else if (chance == 9) {
        // 10% chance of creating a vertical platform
        this->makeVertical();
    } else if (chance == 10) {
        // 10% chance of creating a horizontal platform
        this->makeHorizontal();
    }
}

void Entities::Platform::makeStatic() {
    this->platformKind = STATIC;
    // Defining location of the platform
}

void Entities::Platform::makeHorizontal() {
    this->platformKind = HORIZONTAL;
    this->movingRight = (bool)Random::getInstance().randInt(0,1);
}

void Entities::Platform::makeVertical() {
    this->platformKind = VERTICAL;
    this->movingUp = true;
}

void Entities::Platform::makeTemp() {
    this->platformKind = TEMP;

}

void Entities::Platform::moveUp() {
    this->setPos(this->getPosX(), this->getPosY() + ((float)0.1 * Utilities::Stopwatch::getInstance().getDeltaTicks()));
    this->observer->notifyCurLocation(*this->position);
}

void Entities::Platform::moveDown() {
    this->setPos(this->getPosX(), this->getPosY() - ((float)0.1 * Utilities::Stopwatch::getInstance().getDeltaTicks()));
    this->observer->notifyCurLocation(*this->position);
}

void Entities::Platform::moveRight() {
    this->setPos(this->getPosX() + ((float)0.0003 * Utilities::Stopwatch::getInstance().getDeltaTicks()), this->getPosY());
    this->observer->notifyCurLocation(*this->position);
}

void Entities::Platform::moveLeft() {
    this->setPos(this->getPosX() - ((float)0.0003 * Utilities::Stopwatch::getInstance().getDeltaTicks()), this->getPosY());
    this->observer->notifyCurLocation(*this->position);
}

PKind Entities::Platform::getKind() const {
    return this->platformKind;
}

bool Entities::Platform::getMovingRight() const {
    return this->movingRight;
}

void Entities::Platform::setMovingRight(bool newBool) {
    this->movingRight = newBool;
}

void Entities::Platform::setBonus(std::shared_ptr<Bonus> nBonus) {
    this->bonus = std::move(nBonus);
}

std::shared_ptr<Entities::Bonus> Entities::Platform::getBonus() const {
    return this->bonus;
}

bool Entities::Platform::getMovingUp() const {
    return this->movingUp;
}

void Entities::Platform::setMovingUp(bool newBool) {
    this->movingUp = newBool;
}

float Entities::Platform::getMaxHeight() const {
    return this->maxHeight;
}

void Entities::Platform::setMaxHeight(float newHeight) {
    this->maxHeight = newHeight;
}

void Entities::Platform::setMinHeight(float newHeight) {
    this->minHeight = newHeight;
}

float Entities::Platform::getMinHeight() const {
    return this->minHeight;
}
