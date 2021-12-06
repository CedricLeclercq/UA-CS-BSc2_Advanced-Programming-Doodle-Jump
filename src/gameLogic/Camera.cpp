//
// Created by Cédric Leclercq on 18/11/2021.
//

#include "Camera.h"
#include <utility>

Camera::Camera(float maxX, float maxY, std::shared_ptr<World> nWorld) {
    this->cameraBordersX = std::make_pair(0.f,maxX);
    this->cameraBordersY = std::make_pair(0.f,maxY);
    this->world = std::move(nWorld);
}


void Camera::projectCoordinates(std::shared_ptr<Entity> entity) {
    // Getting the player position from the world
    std::shared_ptr<Utilities::Coordinates> cooPlayer = this->world->getPlayer()->getPos();
    // In standard, the player should be 160 points above the lowest point of the camera

}
