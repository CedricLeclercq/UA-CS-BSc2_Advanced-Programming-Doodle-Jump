//
// Created by Cédric Leclercq on 19/12/2021.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_STOPWATCH_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_STOPWATCH_H

#include <ctime>

class Stopwatch {
    clock_t beforeRunTicks;

    clock_t deltaTicks;

public:
    Stopwatch() {
        this->beforeRunTicks = 0;
        this->deltaTicks = 1;
    }
    float getDeltaTicks() const;
    void startCounter();
    void stopCounter();
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_STOPWATCH_H
