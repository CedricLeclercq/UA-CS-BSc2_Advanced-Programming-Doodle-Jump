//
// Created by Cédric Leclercq on 19/12/2021.
//

#include "Stopwatch.h"


void Stopwatch::startCounter() {
    this->beforeRunTicks = clock(); // todo maybe use high resolution clock
}

void Stopwatch::stopCounter() {
    this->deltaTicks = clock() - this->beforeRunTicks;
}

float Stopwatch::getDeltaTicks() const {
    return static_cast<float>(this->deltaTicks);
}

