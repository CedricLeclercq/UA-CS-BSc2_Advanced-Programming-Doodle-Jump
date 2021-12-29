// // // // // // // // // // // // // //
//                                     //
//           Utilities.cpp             //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#include "Utilities.h"

int Utilities::Random::randInt(int x, int y) {
    if (x == y)
        return x;
    if (x > y)
        std::swap(x,y);
    std::uniform_int_distribution<int> distribution(x,y);
    return distribution(mt);
}

float Utilities::Random::randFloat(float x, float y) {
    if (x == y)
        return x;
    if (x > y)
        std::swap(x,y);
    std::uniform_real_distribution<float> distribution(x,y);
    return distribution(mt);
}

Utilities::Random &Utilities::Random::getInstance() {
    static Random instance;
    return instance;
}

Utilities::Random::Random() {
    this->mt = std::mt19937(this->rd());
}

void Utilities::Stopwatch::startCounter() {
    this->beforeRunTicks = std::chrono::high_resolution_clock::now();
}

void Utilities::Stopwatch::stopCounter() {
    auto currentTicks = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float,std::milli> durationLength = currentTicks - this->beforeRunTicks;
    this->deltaTicks = durationLength.count();
}

float Utilities::Stopwatch::getDeltaTicks() const {
    return static_cast<float>(this->deltaTicks);
}

Utilities::Stopwatch& Utilities::Stopwatch::getInstance() {
    static Stopwatch instance;
    return instance;
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
