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
    // Removing everything that is out of view
    this->removeOutOfView();
    // Creating all new elements in the world
    this->createPlatforms();
    this->createBackground();
}

bool World::collisionCheckPlatform() {
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
        bool criteriaMatched = false;
        if (std::ceil(posY) == std::ceil(platform->getPosY())) criteriaMatched = true;
        if (std::ceil(posY) - 1 == std::ceil(platform->getPosY())) criteriaMatched = true;
        if (std::ceil(posY) == std::ceil(platform->getPosY()) - 1) criteriaMatched = true;
        if (criteriaMatched) {
            // Checking leftmost part of the player
            if (leftMostX > platform->getPosX() and leftMostX <= platform->getPosX() + platform->getLength()) {
                if (platform->getBonus() != nullptr) this->player->setBonus(platform->getBonus()); // todo fix duplicate code
                if (platform->getKind() == PKind::TEMP) this->removePlatform(platform);
                return true;
            }
            // Checking rightmost part of the player
            if (rightMostX > platform->getPosX() and rightMostX <= platform->getPosX() + platform->getLength()) {
                if (platform->getBonus() != nullptr) this->player->setBonus(platform->getBonus()); // todo with this code
                if (platform->getKind() == PKind::TEMP) this->removePlatform(platform);
                return true;
            }
        }
    }
    return false;
}

void World::createPlatforms() {
    // todo find better location for this
    if (player->getLength() == 0) {
        this->player->setLength(this->playerLength);
    }
    // Evaluating is we need new platforms
    while (newPlatformsNeeded()) {
        std::shared_ptr<Platform> newPlatform(new Platform);
        newPlatform->setPosX(Random::randFloat(0,0.85)); // todo change y to 1
        newPlatform->setPosY(this->findHighestPlatform().getY() + Random::randFloat(20,150));
        newPlatform->setLength(this->platformLength);
        if (newPlatform->getKind() == PKind::VERTICAL) {
            newPlatform->setMinHeight(newPlatform->getPosY());
            newPlatform->setMaxHeight(newPlatform->getPosY() + 300);
        }
        World::createBonus(newPlatform);
        this->platforms.push_back(newPlatform);
    }
    // Moving all the platforms
    this->movePlatforms();
}

void World::createBackground() {
    // Evaluating is we need new stars
    while (newStarsNeeded()) {
        std::shared_ptr<BGTile> newStar(new BGTile);
        newStar->setPosX(Random::randFloat(0,1));
        newStar->setPosY(this->findHighestStar().getY() + (float)Random::randInt(10,50));
        this->bgTiles.push_back(newStar);
    }
}

void World::createBonus(const std::shared_ptr<Platform>& platform) {
    // Will there be a bonus on this platform: 5% chance
    if (Random::randInt(1,100) <= 5) {
        std::shared_ptr<Bonus> newBonus(new Bonus);
        // Place the bonus somewhere random on the platform
        newBonus->setPosX(Random::randFloat(platform->getPosX(),platform->getPosX()+platform->getLength()));
        newBonus->setPosY(platform->getPosY());
        platform->setBonus(newBonus);
    }
}

void World::removeOutOfView() {
    // Max amount of platforms allowed is 30, remove all the others to begin with
    while (this->platforms.size() > 30) {
        std::vector<std::shared_ptr<Platform>> newPlatforms;
        std::shared_ptr<Platform> lowest = this->findLowestPlatform();
        for (const auto& platform: this->platforms) {
            if (platform != lowest)
                newPlatforms.push_back(platform);
        }
        this->platforms.clear();
        this->platforms = newPlatforms;
    }

    // Max amount of stars allowed is 100, remove all the others to begin with
    while (this->bgTiles.size() > 100) {
        std::vector<std::shared_ptr<BGTile>> newBGTiles;
        std::shared_ptr<BGTile> lowest = this->findLowestStar();
        for (const auto& star: this->bgTiles) {
            if (star != lowest) {
                newBGTiles.push_back(star);
            }
        }
        this->bgTiles.clear();
        this->bgTiles = newBGTiles;
    }
}


void World::movePlatforms() {
    for (auto& platform: this->platforms) {
        if (platform->getKind() == PKind::HORIZONTAL) {
            // todo edit this to take into account the length of the platform
            if (platform->getMovingRight() and platform->getPosX() + platform->getLength() < 1) {
                platform->moveRight();
            }
            else if (platform->getMovingRight() and platform->getPosX() + platform->getLength() >= 1) {
                platform->setMovingRight(false);
            }
            else if (!platform->getMovingRight() and platform->getPosX() > 0) {
                platform->moveLeft();
            }
            else if (!platform->getMovingRight() and platform->getPosX() <= 0) {
                platform->setMovingRight(true);
            }
        }
        else if (platform->getKind() == PKind::VERTICAL) {
            if (platform->getMovingUp() and platform->getMaxHeight() - platform->getPosY() <= 0) {
                platform->setMovingUp(false);
            }
            else if (platform->getMovingUp() and platform->getMaxHeight() - platform->getPosY() > 0) {
                platform->moveUp();
            }
            else if (!platform->getMovingUp() and platform->getMinHeight() - platform->getPosY() > 0) {
                platform->setMovingUp(true);
            }
            else if (!platform->getMovingUp() and platform->getMinHeight() - platform->getPosY() <= 0) {
                platform->moveDown();
            }
        }
    }
}

std::vector<std::shared_ptr<Platform>> World::getPlatforms() {
    return this->platforms;
}

bool World::newPlatformsNeeded() {

    // Searching the highest platform
    Coordinates highestPlatform = this->findHighestPlatform();

    // Increasing the height of that platform a bit to check if it then falls out the window
    if (!m_camera->evalInWindow(highestPlatform))
        return false;

    // Else, everything is fine, just generate new platforms
    return true;
}

Coordinates World::findHighestPlatform() const {
    Coordinates highest = {0,0};
    for (const auto& platform: this->platforms) {
        if (highest.getY() < platform->getPosY()) {
            highest = (*platform->getPos());
        }
    }
    return highest;
}

std::shared_ptr<Platform> World::findLowestPlatform() {
    std::shared_ptr<Platform> lowest;
    for (const auto& entity: this->platforms) {
        if (lowest == nullptr or entity->getPosY() < lowest->getPosY()) {
            lowest = entity;
        }
    }
    return lowest;
}

std::shared_ptr<BGTile> World::findLowestStar() {
    std::shared_ptr<BGTile> lowest;
    for (const auto& entity: this->bgTiles) {
        if (lowest == nullptr or entity->getPosY() < lowest->getPosY()) {
            lowest = entity;
        }
    }
    return lowest;
}

Coordinates World::findHighestStar() const {
    Coordinates highest = {0,0};
    for (const auto& star: this->bgTiles) {
        if (highest.getY() < star->getPosY()) {
            highest = (*star->getPos());
        }
    }
    return highest;
}

bool World::newStarsNeeded() {
    // Searching the highest platform
    Coordinates highestStar = this->findHighestStar();

    // Increasing the height of that platform a bit to check if it then falls out the window
    if (!m_camera->evalInWindow(highestStar))
        return false;

    // Else, everything is fine, just generate new platforms
    return true;
}

std::shared_ptr<Bonus> World::findLowestBonus() {
    std::shared_ptr<Bonus> lowest;
    for (const auto& entity: this->bonuses) {
        if (lowest == nullptr or entity->getPosY() < lowest->getPosY()) {
            lowest = entity;
        }
    }
    return lowest;
}

void World::removePlatform(const std::shared_ptr<Platform>& toRemove) {
    std::vector<std::shared_ptr<Platform>> newPlatforms;
    for (const auto& platform: this->platforms) {
        if (platform != toRemove) {
            newPlatforms.push_back(platform);
        }
    }
    this->platforms.clear();
    this->platforms = newPlatforms;
}







