// // // // // // // // // // // // // //
//                                     //
//        PlayerController.cpp         //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#include "PlayerController.h"
#include <utility>

void Controllers::PlayerController::handleInput() const {
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
    this->model = std::move(nModel);
}
