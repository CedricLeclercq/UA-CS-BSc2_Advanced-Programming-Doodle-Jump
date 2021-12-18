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
    //this->createPlatforms(this->getPlayer()->getPosY() - 1200, this->getPlayer()->getPosY() + 1200);
    this->removeOutOfView();
    this->createPlatforms();
    // TODO creating the bonuses
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

/*
void World::createPlatforms(float minY, float maxY) {



    this->removeOutOfView();
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
 */
/*
void World::createPlatforms() {
    // todo find a better location to do this
    if (player->getLength() == 0) {
        this->player->setLength(this->playerLength);
    }

    // Remove all the platforms that fall out of the view of the player from the platforms vector
    this->removeOutOfView();

    // Calculating the difficulty
    // Max difficulty is reached at height 50000
    float difficulty = 1 - (this->m_camera->getWorldView().getY() / 50000);
    int amountOfNewPlatforms = ceil(30*difficulty);
    if (amountOfNewPlatforms < 10) {
        // Setting a minimum of 10 platforms in the world
        amountOfNewPlatforms = 10;
    }
    Coordinates highestPlatform =
    if (static_cast<int>(this->platforms.size()) > 30) {
        // there are enough platforms for now
        return;
    }

    ConcreteFactory factory;
    for (int it = 0; it < amountOfNewPlatforms; it++) {
        this->platforms.push_back(factory.createPlatform()); // todo if extra time, add more moving platforms when possible
    }

    this->placePlatforms();
    this->movePlatforms();
}
*/

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

    std::vector<std::shared_ptr<Platform>> newPlatforms;
    for (const auto &platform: this->platforms) {
        Coordinates adjusted = {platform->getPosX(),platform->getPosY()-100};
        if (this->m_camera->evalInWindow(adjusted)) {
            newPlatforms.push_back(platform);
        }
    }
    this->platforms.clear();
    this->platforms = newPlatforms;

    // Max amount of stars allowed is 150, remove all the others to begin with
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




/*
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
            auto newHeight = (float)Random::randInt(20,300);
            float newX = Random::randFloat(0.f,0.85);
            platform->setPosX(newX);
            platform->setPosY(highest + newHeight);
            //while (!this->m_camera->evalInWindow((*platform->getPos()))) {
               //newHeight = (float)Random::randInt(20,39);
               //platform->setPosY(newHeight + highest);
            //}
            highestPlatform = platform;
        }
    }
}
*/

void World::movePlatforms() {
    for (auto& platform: this->platforms) {
        if (platform->getKind() == PKind::HORIZONTAL) {
            // todo edit this to take into account the length of the platform
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

std::vector<std::shared_ptr<Platform>> World::getPlatforms() {
    return this->platforms;
}
/*
void World::createBackground() {

    // todo remove this and place it in a more convenient place
    if (player->getLength() == 0) {
        this->player->setLength(this->playerLength);
    }

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
*/
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
            auto newHeight = (float)Random::randInt(10,50);
            float newX = Random::randFloat(0.f,0.85);
            tile->setPosX(newX);
            tile->setPosY(highest + newHeight);
            highestTile = tile;
        }
    }

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







