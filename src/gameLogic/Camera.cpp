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

Coordinates Camera::projectPlatform(const std::shared_ptr<Platform> &platform) {
    PKind pType = platform->getKind();
    if (pType == PKind::STATIC or pType == PKind::TEMP or pType == PKind::HORIZONTAL) {
        // Entities that remain static on the Y coordinate
        return this->projectStaticYEntity(platform);
    } else {
        return {4000,4000}; // TODO fix random values
    }
}

Coordinates Camera::projectStaticYEntity(const std::shared_ptr<Entity> &entity) {
    // Getting the coordinates of the entity
    Coordinates cooEntity = (*entity->getPos());
    float viewX = cooEntity.getX() * cameraBordersX.second;
    // Calculating the entity's Y by using our player's Y
    float awayFromPlayerGround = this->world->getPlayer()->getPositionBeforeJumpY() - cooEntity.getY();
    float viewY = this->cameraBordersY.second * (float)0.8 + awayFromPlayerGround;
    return {viewX,viewY};
}
