// // // // // // // // // // // // // //
//                                     //
//               Views.h               //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_VIEWS_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_VIEWS_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

/**
 * @brief Namespace for all the views in the graphical world
 */
namespace Views {
    /**
     * @class Views::PlayerView
     * @public View
     * @brief Class for the view of the player model
     */
    class PlayerView;
    /**
     * @class Views::PlatformView
     * @public View
     * @brief Class for the view of the platform model
     */
    class PlatformView;
    /**
     * @class Views::BGTileView
     * @public View
     * @brief Class for the view of the background tile model
     */
    class BGTileView;
}

#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_VIEWS_H
