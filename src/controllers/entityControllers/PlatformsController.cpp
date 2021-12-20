// // // // // // // // // // // // // //
//                                     //
//       PlatformController.cpp        //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#include "PlatformsController.h"

Controllers::PlatformsController::PlatformsController(std::shared_ptr<Platform> nModel) {
    this->model = std::move(nModel);
    this->view = std::make_shared<sf::Sprite>();
}

std::shared_ptr<Platform> Controllers::PlatformsController::getModel() const {
    return this->model;
}

std::shared_ptr<sf::Sprite> Controllers::PlatformsController::getView() const {
    return this->view;
}