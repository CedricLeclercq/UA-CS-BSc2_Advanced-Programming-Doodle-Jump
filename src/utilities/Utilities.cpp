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

void Utilities::Stopwatch::startCounter() {
    this->beforeRunTicks = clock();
}

void Utilities::Stopwatch::stopCounter() {
    this->deltaTicks = clock() - this->beforeRunTicks;
}

float Utilities::Stopwatch::getDeltaTicks() const {
    return static_cast<float>(this->deltaTicks);
}

float Utilities::Stopwatch::calculateSpeedUp() const {
    //std::cout << static_cast<float>(this->deltaTicks) / 1000.f * 60.f << std::endl;
    //return (float)pow((static_cast<float>(this->deltaTicks) / 400),2); // todo possibility 1
    return static_cast<float>(this->deltaTicks) / 1000.f * 60.f; // todo possibility 2
    //return 1; // Just return 1, will make the game run normally without an fps cap on my end
}

void Utilities::Stopwatch::setFPS(float nFPS) {
    this->fps = nFPS;
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
