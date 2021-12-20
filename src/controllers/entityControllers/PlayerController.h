// // // // // // // // // // // // // //
//                                     //
//         PlayerController.h          //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYERCONTROLLER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYERCONTROLLER_H

#include "../../models/entities/Player.h"
#include "../Controllers.h"

class Controllers::PlayerController: public Controller {
private:
    /// @brief Shared pointer to the player model
    std::shared_ptr<Entities::Player> model;
public:
    /// @brief Default constructor
    PlayerController()=default;
    /**
     * @brief Constructor that defines the model and the view
     * @param nModel
     * @param nView
     */
    PlayerController(std::shared_ptr<Entities::Player> nModel, std::shared_ptr<sf::Sprite> nView);
    /**
     * @brief Handles the sfml input and moves the model based on this input
     */
    void handleInput() const;
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYERCONTROLLER_H
