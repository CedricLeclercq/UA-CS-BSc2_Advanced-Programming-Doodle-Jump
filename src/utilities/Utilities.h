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
#include <chrono>

/**
 * @brief Namespace for all the utilities and utility classes
 */
namespace Utilities {
    class Utils {
    public:
        static bool pathExists(const std::string& path);
    };
    /**
     * @class Utilities::Random
     * @brief Will provide all the random values in the project
     */
    class Random {
    private:
        Random();
        ~Random()=default;
        std::random_device rd{};
        std::mt19937 mt;
    public:
        static Random& getInstance();
        /**
         * @brief Will return a random integer from x to y
         * @param x     Bounder x
         * @param y     Bounder Y
         * @return      Random integer between x and y
         */
        int randInt(int x,int y);
        /**
         * @brief Will return a random float from x to y
         * @param x     Bounder x
         * @param y     Bounder y
         * @return      Random float between x and y
         */
        float randFloat(float x, float y);
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
        std::chrono::time_point<std::chrono::high_resolution_clock> beforeRunTicks{};
        /// @brief deltaTicks := ticks when stopwatch ended - ticks when stopwatch started
        float deltaTicks;
        // Member functions
        /**
         * @brief Basic constructor for the stopwatch
         */
        Stopwatch() {
            this->deltaTicks = 1;
        }
    public:
        static Stopwatch& getInstance();
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