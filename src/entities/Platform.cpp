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
}

void Platform::makeVertical() {
    this->platformKind = VERTICAL;
}

void Platform::makeTemp() {
    this->platformKind = TEMP;

}

void Platform::moveUp() {
    this->setPos(this->getPosX(), this->getPosY() - (float)0.5);
}

void Platform::moveDown() {
    this->setPos(this->getPosX(), this->getPosY() + (float)0.5);
}

void Platform::moveRight() {
    this->setPos(this->getPosX() + (float)0.5, this->getPosY());
}

void Platform::moveLeft() {
    this->setPos(this->getPosX() - (float)0.5, this->getPosY());
}

void Platform::changeToGround() {
    this->makeStatic();

}

PKind Platform::getKind() const {
    return this->platformKind;
}
