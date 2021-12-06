//
// Created by Cédric Leclercq on 06/12/2021.
//

#include "Controller.h"

#include <utility>

Controller::Controller(std::shared_ptr<Entity> nModel, std::shared_ptr<sf::Sprite> nView) {
    this->model = std::move(nModel);
    this->view = std::move(nView);
}
