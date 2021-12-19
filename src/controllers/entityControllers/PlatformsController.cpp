//
// Created by Cédric Leclercq on 06/12/2021.
//

#include "PlatformsController.h"

Controllers::PlatformsController::PlatformsController(std::shared_ptr<Platform> nModel) {
    this->model = std::move(nModel);
    this->view = std::make_shared<sf::Sprite>();
}

void Controllers::PlatformsController::loadNewPlatform(std::shared_ptr<Platform> nPlatform) {

}

std::shared_ptr<Platform> Controllers::PlatformsController::getModel() const {
    return this->model;
}

std::shared_ptr<sf::Sprite> Controllers::PlatformsController::getView() const {
    return this->view;
}


