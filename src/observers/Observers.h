//
// Created by Cédric Leclercq on 26/12/2021.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_OBSERVERS_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_OBSERVERS_H

#include "Observer.h"

namespace Observers {
    /**
     * @class Observers::PlayerObserver
     * @brief Singleton Observer class for the player
     */
    class PlayerObserver;
    /**
     * @class Observers::ScoreObserver
     * @brief Singleton Observer class for the score in the world - also keeps the current score of the game
     */
    class ScoreObserver;

    class PlatformObserver;

    class BGTileObserver;

    class WorldObserver;
}

#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_OBSERVERS_H
