//
// Created by Cédric Leclercq on 25/11/2021.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_UTILITIES_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_UTILITIES_H

#include <random>
#include <iostream>

namespace Utilities {
    class Random {
    public:
        static int randInt(int x,int y);
    };

    class StopWatch {};


    class Coordinates {
    private:
        float x;
        float y;
    public:
        Coordinates()=default;
        Coordinates(float nX, float nY) {
            this->x = nX;
            this->y = nY;
        }
        void setX(float nX);
        void setY(float nY);
        float getX() const;
        float getY() const;
    };
}

#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_UTILITIES_H

