//
// Created by Cédric Leclercq on 06/12/2021.
//

#include "PlatformsController.h"

Controllers::PlatformsController::PlatformsController(std::shared_ptr<Platform> nModel) {
    this->model = std::move(nModel);
}

void Controllers::PlatformsController::loadNewPlatform(std::shared_ptr<Platform> nPlatform) {

}

std::shared_ptr<Platform> Controllers::PlatformsController::getModel() const {
    return this->model;
}


