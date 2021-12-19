//
// Created by Cédric Leclercq on 06/12/2021.
//

#include "BGTileController.h"

Controllers::BGTileController::BGTileController(std::shared_ptr<BGTile> nModel) {
    this->model = std::move(nModel);
    this->view = std::make_shared<sf::Sprite>();
}

void Controllers::BGTileController::loadNewPlatform(std::shared_ptr<BGTile> nTile) {
    this->model = std::move(nTile);
}

std::shared_ptr<sf::Sprite> Controllers::BGTileController::getView() const {
    return this->view;
}

std::shared_ptr<BGTile> Controllers::BGTileController::getModel() const {
    return this->model;
}
