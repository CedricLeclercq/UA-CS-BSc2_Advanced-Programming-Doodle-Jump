//
// Created by Cédric Leclercq on 25/11/2021.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_UTILITIES_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_UTILITIES_H

namespace Utilities {
    class Random {

    };

    class StopWatch {

    };

    class Utils {

    };

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
        void setX(float nX) {
            this->x = nX;
        }
        void setY(float nY) {
            this->y = nY;
        }
        float getX() const {
            return this->x;
        }
        float getY() const {
            return this->y;
        }
    };
}

#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_UTILITIES_H

