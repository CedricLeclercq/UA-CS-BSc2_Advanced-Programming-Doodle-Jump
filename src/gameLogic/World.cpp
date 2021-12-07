//
// Created by Cédric Leclercq on 18/11/2021.
//

#include "World.h"
#include "../factories/ConcreteFactory.h"
using Random = Utilities::Random;


void World::updateWorld() {
    if (this->collisionCheckPlatform()) {
        this->player->jump();
    }
}

bool World::collisionCheckPlatform() {
    for (const auto& platform: this->platforms) {
        if (platform->getPosY() == this->player->getPosY() and platform->getPosX() < this->player->getPosX() + 10
                and this->player->getPosX() - 10 < platform->getPosX()) {
            return true;
        }
    }
    return true;
}


void World::createPlatforms(float minY, float maxY) {
    this->removeOutOfView(minY,maxY);
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
            float newHeight = (float)Random::randInt(20,100);
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





