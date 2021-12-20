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
     * @class Entities::Bonus: public Entity
     * @brief Class for the bonus in the game
     */
    class Bonus;
    /**
     * @class Entities::Platform: public Entity
     * @brief class for the platform in the game
     */
    class Platform;
    /**
     * @class Entities::Player: public Entity
     * @brief class for the player in the game
     */
    class Player;
    /**
     * @class Entities::BGTile: public Entity
     * @brief class for the background tile in the game
     */
    class BGTile;
}


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_ENTITIES_H