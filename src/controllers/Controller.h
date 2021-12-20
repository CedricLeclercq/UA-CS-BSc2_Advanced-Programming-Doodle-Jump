// // // // // // // // // // // // // //
//                                     //
//            Controller.h             //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_CONTROLLER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_CONTROLLER_H

#include "Controllers.h"
#include "../models/Entity.h"

/**
 * @class Controller
 * @brief A super class for all the entity controllers
 */
class Controller {
protected:
    /// @brief View that the controller will communicate to
    std::shared_ptr<sf::Sprite> view;
    /// @brief Default constructor
    Controller()=default;
    /**
     * @brief Constructor that defines the model and the view
     * @param nView     The view it will define
     */
    Controller(std::shared_ptr<sf::Sprite> nView);
public:
    /// @brief Getter for the view
    sf::Sprite& getView();
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_CONTROLLER_H
