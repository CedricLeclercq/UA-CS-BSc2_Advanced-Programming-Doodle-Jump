// // // // // // // // // // // // // //
//                                     //
//             World.cpp               //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#include "World.h"

using Random = Utilities::Random;

void World::updateWorld() {
    // Don't do anything if game over!
    if (this->checkGameOver()) return;

    // Checking if the player collided and letting him jump
    if (this->collisionCheckPlatform()) {
        this->player->jump(true);
    } else {
        this->player->jump();
    }
    // Calculating score for when the player has gone higher
    auto difference = static_cast<float>(this->m_camera->higherWindowHeight(this->player->getPosY()));
    score->addScore(difference * 1/4); // and adding that score
    // Updating the player height
    m_camera->updateHeight(this->player->getPosY());
    // Creating all new elements in the world
    this->removeOutOfView();
    this->createPlatforms();
    this->createBackground();
}

bool World::collisionCheckPlatform() {
    // Player cannot collide with something while moving up
    if (this->player->getVelocityY() > 0) return false;

    // Getting the position of the player
    float leftMostX = this->player->getPosX(); // leftmost point of the player
    float rightMostX = leftMostX + this->player->getLength(); // rightmost point of the player
    float posY = this->player->getPosY(); // Y position of the player


    // Looping over all platforms to check for collision
    for (const auto& platform: this->platforms) {
        bool criteriaMatched = false;
        // Setting criteria for when a collision occurred on the Y coordinate
        if (std::ceil(posY) - 20 < std::ceil(platform->getPosY())
            and std::ceil(posY) + 20 > std::ceil(platform->getPosY())) {
            criteriaMatched = true;
        }

        if (criteriaMatched) {
            // And now comparing the X coordinate
            bool matched = false;
            // Checking leftmost part of the player
            if (leftMostX > platform->getPosX() and leftMostX <= platform->getPosX() + platform->getLength()) {
                matched = true;
            }
            // Checking rightmost part of the player
            if (rightMostX > platform->getPosX() and rightMostX <= platform->getPosX() + platform->getLength()) {
                matched = true;
            }
            // Checking if we matched a platform
            if (matched) {
                if (platform->getBonus() != nullptr) {
                    // There is a bonus, give it to the player
                    this->player->setBonus(platform->getBonus());
                    // And of course credit the player for catching the bonus
                    World::addBonusScore(platform->getBonus());
                }
                // If we collided with a temporary platform, remove that platform
                if (platform->getKind() == PKind::TEMP) this->removePlatform(platform);
                // Saving the previous platform the player jumped on
                if (this->prevPlatform == nullptr) this->prevPlatform = platform;
                // If the player jumped twice on the same platform, decrease score by 10
                if (this->prevPlatform == platform) {
                    if (score->getScore() - 10 >= 0) {
                        score->addScore(-10); // Decreasing score
                    } else score->setScore(0);
                } else {
                    this->prevPlatform = platform; // Else adding to score
                    World::addPlatformScore(platform);
                }
                return true;
            }
        }
    }
    return false;
}

void World::createPlatforms() {
    // Calculating difficulty of the game
    auto difficulty = static_cast<float>(this->calculateDifficulty());
    // Evaluating is we need new platforms
    while (newPlatformsNeeded()) {
        // Defining the concrete factory
        ConcreteFactory factory;
        std::shared_ptr<Entities::Platform> newPlatform(factory.createPlatform(World::difficultyPlatformOverride(difficulty)));
        newPlatform->setPosX(Random::getInstance().randFloat(0,1 - this->platformLength));
        newPlatform->setPosY(this->findHighestPlatform().getY() + Random::getInstance().randFloat(20 * difficulty,120 * difficulty));
        newPlatform->setLength(this->platformLength);
        if (newPlatform->getKind() == PKind::VERTICAL) {
            newPlatform->setMinHeight(newPlatform->getPosY());
            newPlatform->setMaxHeight(newPlatform->getPosY() + 300);
        }
        World::createBonus(newPlatform);
        this->platforms.push_back(newPlatform);
        Observers::WorldObserver::getInstance().notifyCreatePlatform(newPlatform);
        newPlatform->observer->notifyPlatformCreation();
        newPlatform->observer->notifyCurLocation(*newPlatform->getPos());
        //Observers::PlatformObserver::getInstance().notifyCreation(newPlatform);
    }
    // Moving all the platforms
    this->movePlatforms();
}

void World::createBackground() {
    // Evaluating is we need new stars
    while (newStarsNeeded()) {
        // Defining the concrete factory
        ConcreteFactory factory;
        std::shared_ptr<Entities::BGTile> newStar(factory.createBGTile());
        newStar->setPosX(Random::getInstance().randFloat(0,1));
        newStar->setPosY(this->findHighestStar().getY() + (float)Random::getInstance().randInt(10,50));
        this->bgTiles.push_back(newStar);
        Observers::WorldObserver::getInstance().notifyCreateTile(newStar);
        newStar->observer->notifyCreation();
        newStar->observer->notifyCurLocation(*newStar->getPos());
    }
}

void World::createBonus(const std::shared_ptr<Entities::Platform>& platform) {
    // Will there be a bonus on this platform: 5% chance
    if (Random::getInstance().randInt(1,100) <= 5) {
        // Defining the concrete factory
        ConcreteFactory factory;
        std::shared_ptr<Entities::Bonus> newBonus(factory.createBonus());
        // Place the bonus somewhere random on the platform
        newBonus->setPosX(Random::getInstance().randFloat(platform->getPosX(),platform->getPosX()+platform->getLength()));
        newBonus->setPosY(platform->getPosY());
        platform->setBonus(newBonus);
    }
}

void World::removeOutOfView() {
    // Max amount of platforms allowed is 30, remove all the others to begin with
    while (this->platforms.size() > 30) {
        std::vector<std::shared_ptr<Entities::Platform>> newPlatforms;
        std::shared_ptr<Entities::Platform> lowest = this->findLowestPlatform();
        for (const auto& platform: this->platforms) {
            if (platform != lowest)
                newPlatforms.push_back(platform);
        }
        lowest->observer->notifyRemoved();
        this->platforms.clear();
        this->platforms = newPlatforms;
    }

    // Max amount of stars allowed is 50, remove all the others to begin with
    while (this->bgTiles.size() > 80) {
        std::vector<std::shared_ptr<Entities::BGTile>> newBGTiles;
        std::shared_ptr<Entities::BGTile> lowest = this->findLowestStar();
        for (const auto& star: this->bgTiles) {
            if (star != lowest) {
                newBGTiles.push_back(star);
            }
        }
        lowest->observer->notifyRemoved();
        this->bgTiles.clear();
        this->bgTiles = newBGTiles;
    }
}


void World::movePlatforms() {
    for (auto& platform: this->platforms) {
        if (platform->getKind() == PKind::HORIZONTAL) {
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

std::shared_ptr<Entities::Platform> World::findLowestPlatform() {
    std::shared_ptr<Entities::Platform> lowest;
    for (const auto& entity: this->platforms) {
        if (lowest == nullptr or entity->getPosY() < lowest->getPosY()) {
            lowest = entity;
        }
    }
    return lowest;
}

std::shared_ptr<Entities::BGTile> World::findLowestStar() {
    std::shared_ptr<Entities::BGTile> lowest;
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

__attribute__((unused)) std::shared_ptr<Entities::Bonus> World::findLowestBonus() {
    std::shared_ptr<Entities::Bonus> lowest;
    for (const auto& entity: this->bonuses) {
        if (lowest == nullptr or entity->getPosY() < lowest->getPosY()) {
            lowest = entity;
        }
    }
    return lowest;
}

void World::removePlatform(const std::shared_ptr<Entities::Platform>& toRemove) {
    std::vector<std::shared_ptr<Entities::Platform>> newPlatforms;
    for (const auto& platform: this->platforms) {
        if (platform != toRemove) {
            newPlatforms.push_back(platform);
        }
    }
    this->platforms.clear();
    toRemove->observer->notifyRemoved();
    this->platforms = newPlatforms;
}

void World::addPlatformScore(const std::shared_ptr<Entities::Platform>& platform) {
    if (platform->getKind() == PKind::STATIC) {
        score->addScore(10);
        return;
    }
    if (platform->getKind() == PKind::HORIZONTAL) {
        score->addScore(12);
        return;
    }
    if (platform->getKind() == PKind::VERTICAL) {
        score->addScore(14);
        return;
    }
    if (platform->getKind() == PKind::TEMP) {
        score->addScore(16);
        return;
    }
}

void World::addBonusScore(const std::shared_ptr<Entities::Bonus>& bonus) {
    if (bonus->getPowerKind() == BonusPower::ROCKET) {
        score->addScore(30);
        return;
    }
    if (bonus->getPowerKind() == BonusPower::SPRING) {
        score->addScore(20);
        return;
    }
}

bool World::checkGameOver() {
    Coordinates toEval = (*this->player->getPos());
    toEval.setY(toEval.getY() + 20); // Make the game over a bit less strict

    if (!this->m_camera->evalInCamera(toEval) and this->player->getPosY() > 0) {
        // Telling the observers to remove all the elements in the world
        for (const auto& item: platforms) item->observer->notifyRemoved();
        for (const auto& item: bgTiles) item->observer->notifyRemoved();
        return true;
    }
    else return false;
}

World::World(std::shared_ptr<Camera> camera) {
    ConcreteFactory factory;
    this->score = factory.createScore();
    this->player = factory.createPlayer();
    this->m_camera = std::move(camera);
}

std::shared_ptr<Entities::Player> World::getPlayer() {
    return this->player;
}

void World::setPlayerLength(float length) {
    this->playerLength = length;
    this->player->setLength(this->playerLength);
}

void World::setPlatformLength(float length) {
    this->platformLength = length;
}

double World::calculateDifficulty() const {
    // Difficulty increases slowly over a 1000 points
    double difficulty = std::floor(this->player->getPosY() / 1000) / 50;
    return std::min(1 + difficulty,1.8);
}

PKind World::difficultyPlatformOverride(double diff) {
    float random = Utilities::Random::getInstance().randFloat(1,static_cast<float>(diff));
    if (random <= 1.2) {
        return PKind::UNDEF;
    }
    if (random <= 1.6) {
        return PKind::HORIZONTAL;
    } else return PKind::VERTICAL;
}

