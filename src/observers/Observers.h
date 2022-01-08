// // // // // // // // // // // // // //
//                                     //
//            Observers.h              //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_OBSERVERS_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_OBSERVERS_H

#include "Observer.h"

namespace Observers {
    /**
     * @class Observers::PlayerObserver
     * @public Observer
     * @brief Singleton Observer class for the player
     */
    class PlayerObserver;
    /**
     * @class Observers::ScoreObserver
     * @public Observer
     * @brief Singleton Observer class for the score in the world - also keeps the current score of the game
     */
    class ScoreObserver;
    /**
     * @class Observers::PlatformObserver
     * @public Observer
     * @brief Observer class for a platform in the world - for linking its view and model
     */
    class PlatformObserver;
    /**
     * @class Observers::BGTileObserver
     * @public Observer
     * @brief Observer class for a background tile in the world - for linking its view and model
     */
    class BGTileObserver;
    /**
     * @class Observers::WorldObserver
     * @public Observer
     * @brief Singleton Observer class for linking all the elements in the world with their views
     */
    class WorldObserver;
}

#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_OBSERVERS_H
