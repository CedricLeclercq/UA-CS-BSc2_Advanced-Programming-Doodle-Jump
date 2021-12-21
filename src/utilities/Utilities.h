// // // // // // // // // // // // // //
//                                     //
//            Utilities.h              //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_UTILITIES_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_UTILITIES_H

#include <random>
#include <iostream>
#include <ctime>

/**
 * @brief Namespace for all the utilities and utility classes
 */
namespace Utilities {
    /**
     * @class Utilities::Random
     * @brief Will provide all the random values in the project
     */
    class Random {
    public:
        /**
         * @brief Will return a random integer from x to y
         * @param x     Bounder x
         * @param y     Bounder Y
         * @return      Random integer between x and y
         */
        static int randInt(int x,int y);
        /**
         * @brief Will return a random float from x to y
         * @param x     Bounder x
         * @param y     Bounder y
         * @return      Random float between x and y
         */
        static float randFloat(float x, float y);
    };
    /**
     * @class Utilities::Stopwatch
     * @brief Makes sure that the game logic and the graphical side runs the same on every pc using cpu ticks
     */
     // todo make this one singleton
    class Stopwatch {
    private:
        // Member variables
        /// @brief Indicates how many ticks where recorded at the beginning of the stopwatch
        clock_t beforeRunTicks;
        /// @brief deltaTicks := ticks when stopwatch ended - ticks when stopwatch started
        clock_t deltaTicks;
        ///@brief Default FPS the games runs on
        float fps;
        // Member functions
    public:
        /**
         * @brief Basic constructor for the stopwatch
         */
        Stopwatch() {
            this->beforeRunTicks = 0;
            this->deltaTicks = 1;
            this->fps = 60;
        }
        /**
         * @brief Getter for the delta ticks of the previous run
         * @return
         */
        float getDeltaTicks() const;
        /**
         * @brief Start the stopwatch - record the ticks at this moment
         */
        void startCounter();
        /**
         * @brief Stop the stopwatch - calculate delta ticks
         */
        void stopCounter();
        /**
         * @brief Setter for the fps
         * @param nFPS      New fps
         */
        void setFPS(float nFPS);
        /**
         * @brief Will calculate how much slower/faster the movements in the game need to be
         */
        float calculateSpeedUp() const;
    };
    /**
     * @class Utilities::Coordinates
     * @brief Simple coordinate class with x and y coordinates
     */
    class Coordinates {
    private:
        /// @brief x coordinate
        float x{};
        /// @brief y coordinate
        float y{};
    public:
        /**
         * @brief Very simple default constructor initialising all the values
         */
        Coordinates() {
            x = 0;
            y = 0;
        }
        /**
         * @brief Constructor with given coordinates
         * @param nX    New coordinate x
         * @param nY    New coordinate y
         */
        Coordinates(float nX, float nY) {
            this->x = nX;
            this->y = nY;
        }
        /**
         * @brief Setter for the x coordinate
         * @param nX    New coordinate x
         */
        void setX(float nX);
        /**
         * @brief Setter for the y coordinate
         * @param nY    New coordinate y
         */
        void setY(float nY);
        /**
         * @brief Getter for the x coordinate
         * @return      x coordinate
         */
        float getX() const;
        /**
         * @brief Getter for the y coordinate
         * @return      y coordinate
         */
        float getY() const;
    };
}


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_UTILITIES_H