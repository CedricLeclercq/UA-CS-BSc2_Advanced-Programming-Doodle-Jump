// // // // // // // // // // // // // //
//                                     //
//        BGTileController.cpp         //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#include "BGTileController.h"

Controllers::BGTileController::BGTileController(std::shared_ptr<BGTile> nModel) {
    this->model = std::move(nModel);
    this->view = std::make_shared<sf::Sprite>();
}

std::shared_ptr<sf::Sprite> Controllers::BGTileController::getView() const {
    return this->view;
}

std::shared_ptr<BGTile> Controllers::BGTileController::getModel() const {
    return this->model;
}