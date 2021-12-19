//
// Created by Cédric Leclercq on 06/12/2021.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_CONTROLLER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_CONTROLLER_H

#include "Controllers.h"
#include "../entities/Entity.h"

class Controller {
protected:
    /// View that the controller will communicate to
    std::shared_ptr<sf::Sprite> view;
    /**
     * Default constructor
     */
    Controller()=default;
    /**
     * Constructor that defines the model and the view
     * @param nModel
     * @param nView
     */
    Controller(std::shared_ptr<sf::Sprite> nView);
public:
    sf::Sprite& getView();
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_CONTROLLER_H
