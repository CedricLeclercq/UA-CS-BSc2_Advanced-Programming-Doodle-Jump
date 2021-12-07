//
// Created by Cédric Leclercq on 02/12/2021.
//

#include "ConcreteFactory.h"

#include <memory>

std::shared_ptr<Player> ConcreteFactory::createPlayer() {
    return std::shared_ptr<Player>(new Player());
}

std::shared_ptr<BGTile> ConcreteFactory::createBGTile() {
    return std::shared_ptr<BGTile>(new BGTile());
}

std::shared_ptr<Bonus> ConcreteFactory::createBonus() {
    return std::shared_ptr<Bonus>(new Bonus());
}

std::shared_ptr<Platform> ConcreteFactory::createPlatform() {
    return std::shared_ptr<Platform>(new Platform());
}

std::shared_ptr<World> ConcreteFactory::createWorld(std::pair<float,float> borderX, std::pair<float,float> borderY) {
    return std::shared_ptr<World>(new World(borderX,borderY));
}

std::unique_ptr<Camera> ConcreteFactory::createCamera(float maxX, float maxY, std::shared_ptr<World> nWorld) {
    return std::make_unique<Camera>(maxX,maxY, nWorld);
}
