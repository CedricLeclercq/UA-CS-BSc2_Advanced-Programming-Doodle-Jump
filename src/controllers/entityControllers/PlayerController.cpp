//
// Created by Cédric Leclercq on 06/12/2021.
//

#include "PlayerController.h"

#include <utility>

void Controllers::PlayerController::handleInput() {
    //this->model->jump();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) or sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        this->model->moveRight();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) or sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        this->model->moveLeft();
    }
}



Controllers::PlayerController::PlayerController(std::shared_ptr<Player> nModel, std::shared_ptr<sf::Sprite> nView)
        : Controller(std::move(nView)) {
    this->model = nModel;
}
