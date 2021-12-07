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


Coordinates Camera::projectPlayer(const std::shared_ptr<Player>& player) {
    // Getting the player position from the world
    Coordinates cooPlayer = (*this->world->getPlayer()->getPos());
    // In standard, the player should be 160 points above the lowest point of the camera
    float viewX = cooPlayer.getX() * cameraBordersX.second;
    // If not jumping, place sprite on 20% from the bottom up of the window
    float viewY = this->cameraBordersY.second * (float)0.8;
    float originalPos = player->getPositionBeforeJumpY();
    if (player->getPosY() != player->getPositionBeforeJumpY() + player->getStVelocityY()) {
        // Player is jumping!
        viewY = viewY - (player->getPosY() - originalPos);
    }

    return {viewX,viewY};
}
