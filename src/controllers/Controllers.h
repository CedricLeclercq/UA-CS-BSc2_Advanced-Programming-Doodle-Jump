//
// Created by Cédric Leclercq on 06/12/2021.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_CONTROLLERS_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_CONTROLLERS_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Controller.h"

/// @brief Namespace for all the controllers
namespace Controllers {
    /**
      * @class Controllers::BGTileController
      * @brief Controller class for a background tile (BGTile) for linking its view and its model
      */
    class BGTileController;
    /**
      * @class Controllers:PlatformsController: public Controller
      * @brief Controller class for a platform for linking its view and its model
      */
    class PlatformsController;
    /**
     * @class Controllers:PlayerController: public Controller
     * @brief Controller class for a player for linking its view and its model
     */
    class PlayerController;
}


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_CONTROLLERS_H