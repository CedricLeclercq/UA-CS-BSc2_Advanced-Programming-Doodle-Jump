//
// Created by Cédric Leclercq on 06/12/2021.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYERCONTROLLER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYERCONTROLLER_H

#include "../../entities/Player.h"

#include "../Controllers.h"

class Controllers::PlayerController: public Controller {
public:
    std::shared_ptr<Player> model;
    PlayerController()=default;
    /**
     * Constructor that defines the model and the view
     * @param nModel
     * @param nView
     */
    PlayerController(std::shared_ptr<Player> nModel, std::shared_ptr<sf::Sprite> nView);

    void handleInput();

};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYERCONTROLLER_H
