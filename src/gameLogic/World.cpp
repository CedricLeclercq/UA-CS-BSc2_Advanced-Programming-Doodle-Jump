//
// Created by Cédric Leclercq on 18/11/2021.
//

#include "World.h"
#include "../factories/ConcreteFactory.h"
using Random = Utilities::Random;


void World::updateWorld() {
    // Checking if the player collided and letting him jump
    if (this->collisionCheckPlatform()) {
        this->player->jump(true);
    } else {
        this->player->jump();
    }
    // Updating the player height
    m_camera->updateHeight(this->player->getPosY());
    // Creating the platforms
    this->createPlatforms(this->getPlayer()->getPosY() - 1200, this->getPlayer()->getPosY() + 1200);
    // TODO creating the bonusses
    // Creating the background
    this->createBackground();

}

bool World::collisionCheckPlatform() {

    /*
    for (const auto& platform: this->platforms) {
        if ((int)platform->getPosY() == (int)this->player->getPosY() and this->player->getVelocityY() <= 0) { //and platform->getPosX() <= this->player->getPosX()
            if (player->getPosX() > platform->getPosX() and platform->getPosX() + 10 > player->getPosX()) {
                return true;
            }
        }
    }
    return false;
     */
    if (this->player->getVelocityY() > 0) {
        // Player cannot collide with something while moving up
        return false;
    }

    // Getting the position of the player
    float leftMostX = this->player->getPosX();
    float posY = this->player->getPosY();
    float rightMostX = leftMostX + this->player->getLength();

    // Looping over all platforms to check
    for (const auto& platform: this->platforms) {
        if ((int)posY == (int)platform->getPosY()) {
            // Checking leftmost part of the player
            if (leftMostX > platform->getPosX() and leftMostX <= platform->getPosX() + platform->getLength()) {
                return true;
            }
            // Checking rightmost part of the player
            if (rightMostX > platform->getPosX() and rightMostX <= platform->getPosX() + platform->getLength()) {
                return true;
            }
        }
    }
    return false;
}

void World::createPlatforms(float minY, float maxY) {

    // todo find a better location to do this
    if (player->getLength() == 0) {
        this->player->setLength(this->playerLength);
    }

    //this->removeOutOfView(minY,maxY);
    ConcreteFactory factory;
    int stillInView = (int)this->platforms.size();
    int amount = 0;
    if (stillInView == 0) {
        amount = Random::randInt(8,20); // 8 to 15 platforms can be on a screen
    }
    else if (stillInView < 8) {
        // We have less than 8 platforms
        amount = Random::randInt(8-stillInView,15-stillInView);
    }
    else if (stillInView >= 8) {
        amount = Random::randInt(0,std::max(0,15-stillInView));
    }
    for (int it = 0; it < amount; it++) {
        this->platforms.push_back(factory.createPlatform());
    }
    this->placePlatforms();
    this->movePlatforms();
}

void World::placePlatforms() {
    // Find the highest platform that already has coordinates and place all the order above that one
    std::shared_ptr<Platform> highestPlatform;
    for (const auto& platform: this->platforms) {
        // Setting the platform length
        platform->setLength(this->platformLength);


        if (highestPlatform == nullptr) {
            highestPlatform = platform;
        }
        if (platform->getPosY() != 0) {
            // Platform has an assigned position
            if (highestPlatform->getPosY() < platform->getPosY()) {
                highestPlatform = platform;
            }
        }
        else {
            // Platform still needs to get a location
            // This platform can be 1 to 10 higher than the previous one
            float highest = highestPlatform->getPosY();
            float newHeight = (float)Random::randInt(20,300);
            float newX = Random::randFloat(0.f,0.85);
            platform->setPosX(newX);
            platform->setPosY(highest + newHeight);
            highestPlatform = platform;
        }
    }
}

void World::movePlatforms() {
    for (auto& platform: this->platforms) {
        if (platform->getKind() == PKind::HORIZONTAL) {
            if (platform->getMovingRight() and platform->getPosX() < 0.85) {
                platform->moveRight();
            }
            else if (platform->getMovingRight() and platform->getPosX() >= 0.85) {
                platform->setMovingRight(false);
            }
            else if (!platform->getMovingRight() and platform->getPosX() > 0) {
                platform->moveLeft();
            }
            else if (!platform->getMovingRight() and platform->getPosX() <= 0) {
                platform->setMovingRight(true);
            }
        }
    }
}

void World::removeOutOfView(float minY, float maxY) {
    std::vector<std::shared_ptr<Platform>> newPlatforms;
    for (const auto& platform: this->platforms) {
        if (platform->getPosY() < minY or platform->getPosY() > maxY)
            continue;
        else newPlatforms.push_back(platform);
    }
    this->platforms.clear();
    this->platforms = newPlatforms; // TODO does this give an out of memory error?
}

std::vector<std::shared_ptr<Platform>> World::getPlatforms() {
    return this->platforms;
}

void World::createBackground() {

    // todo if time, draw the Ground.png here

    ConcreteFactory factory;
    int stillInView = (int)this->bgTiles.size();

    // There are still enough background tiles in the view
    if (150 - stillInView < 0)
        return;

    for (int i = 0; i < 150-stillInView; i++) {
        this->bgTiles.push_back(factory.createBGTile());
    }
    this->placeBackground();
}

void World::placeBackground() {
    // todo fix that this can become one with our placePlatforms function, they both do pratically the same
    // Finding the highest tile that already has coordinates and place all the other above that one
    std::shared_ptr<BGTile> highestTile;
    for (auto& tile: this->bgTiles) {
        if (highestTile == nullptr) {
            highestTile = tile;
        }
        if (tile->getPosY() != 0) {
            if (highestTile->getPosY() < tile->getPosY()) {
                highestTile = tile;
            }
        }

        else {
            // Platform still needs to get a location
            // This platform can be 1 to 10 higher than the previous one
            float highest = highestTile->getPosY();
            float newHeight = (float)Random::randInt(10,50);
            float newX = Random::randFloat(0.f,0.85);
            tile->setPosX(newX);
            tile->setPosY(highest + newHeight);
            highestTile = tile;
        }
    }

}





