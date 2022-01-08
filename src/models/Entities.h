// // // // // // // // // // // // // //
//                                     //
//             Entities.h              //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_ENTITIES_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_ENTITIES_H

#include "Entity.h"

/**
 * @brief namespace for all the models in the game
 */
namespace Entities {
    /**
     * @class Entities::Bonus
     * @public Entity
     * @brief Entity class for a bonus in the game
     * @note Makes use of several observers
     */
    class Bonus;
    /**
     * @class Entities::Platform
     * @public Entity
     * @brief Entity class for a platform in the game
     * @note Makes use of several observers
     */
    class Platform;
    /**
     * @class Entities::Player
     * @public Entity
     * @brief Entity class for the player in the game
     * @note Will make use of several observers
     */
    class Player;
    /**
     * @class Entities::BGTile
     * @public Entity
     * @brief Entity class for a background tile in the game
     * @note Makes use of several observers
     */
    class BGTile;
}


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_ENTITIES_H