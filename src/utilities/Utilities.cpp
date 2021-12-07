//
// Created by Cédric Leclercq on 02/12/2021.
//

#include "Utilities.h"

int Utilities::Random::randInt(int x, int y) {
    if (x == y)
        return x;
    if (x > y)
        std::swap(x,y);
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> distribution(x,y);
    return distribution(mt);
}

float Utilities::Random::randFloat(float x, float y) {
    if (x == y)
        return x;
    if (x > y)
        std::swap(x,y);
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<float> distribution(x,y);
    return distribution(mt);
}

void Utilities::Coordinates::setX(float nX) {
    this->x = nX;
}

void Utilities::Coordinates::setY(float nY) {
    this->y = nY;
}

float Utilities::Coordinates::getX() const {
    return this->x;
}

float Utilities::Coordinates::getY() const {
    return this->y;
}
