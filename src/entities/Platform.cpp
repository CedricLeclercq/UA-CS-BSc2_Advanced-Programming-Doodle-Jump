//
// Created by Cédric Leclercq on 18/11/2021.
//

#include "Platform.h"
using Random = Utilities::Random;


void Platform::createPlatform() {
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
    int chance = Random::randInt(1,10);
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

void Platform::makeStatic() {
    this->platformKind = STATIC;
    // Defining location of the platform
}

void Platform::makeHorizontal() {
    this->platformKind = HORIZONTAL;
    this->movingRight = (bool)Random::randInt(0,1);
}

void Platform::makeVertical() {
    this->platformKind = VERTICAL;
    this->movingUp = true;
}

void Platform::makeTemp() {
    this->platformKind = TEMP;

}

void Platform::moveUp() {
    this->setPos(this->getPosX(), this->getPosY() + (float)0.1);
}

void Platform::moveDown() {
    this->setPos(this->getPosX(), this->getPosY() - (float)0.1);
}

void Platform::moveRight() {
    this->setPos(this->getPosX() + (float)0.0003, this->getPosY());
}

void Platform::moveLeft() {
    this->setPos(this->getPosX() - (float)0.0003, this->getPosY());
}

void Platform::changeToGround() {
    this->makeStatic();

}

PKind Platform::getKind() const {
    return this->platformKind;
}

bool Platform::getMovingRight() const {
    return this->movingRight;
}

void Platform::setMovingRight(bool newBool) {
    this->movingRight = newBool;
}

void Platform::setBonus(std::shared_ptr<Bonus> nBonus) {
    this->bonus = std::move(nBonus);
}

std::shared_ptr<Bonus> Platform::getBonus() const {
    return this->bonus;
}

bool Platform::getMovingUp() const {
    return this->movingUp;
}

void Platform::setMovingUp(bool newBool) {
    this->movingUp = newBool;
}

float Platform::getMaxHeight() const {
    return this->maxHeight;
}

void Platform::setMaxHeight(float newHeight) {
    this->maxHeight = newHeight;
}

void Platform::setMinHeight(float newHeight) {
    this->minHeight = newHeight;
}

float Platform::getMinHeight() const {
    return this->minHeight;
}
