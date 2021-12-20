// // // // // // // // // // // // // //
//                                     //
//           Controller.cpp            //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#include "Controller.h"
#include <utility>

Controller::Controller(std::shared_ptr<sf::Sprite> nView) {
    //this->model = std::move(nModel);
    this->view = std::move(nView);
}

sf::Sprite &Controller::getView() {
    return (*this->view);
}