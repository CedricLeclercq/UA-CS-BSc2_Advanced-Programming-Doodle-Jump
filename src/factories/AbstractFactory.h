//
// Created by Cédric Leclercq on 02/12/2021.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_ABSTRACTFACTORY_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_ABSTRACTFACTORY_H

#include <memory>
#include "../entities/Player.h"
#include "../entities/BGTile.h"
#include "../entities/Bonus.h"
#include "../entities/Platform.h"
#include "../gameLogic/World.h"


class AbstractFactory {
protected:
    virtual std::shared_ptr<Player> createPlayer() = 0;
    virtual std::shared_ptr<BGTile> createBGTile() = 0;
    virtual std::shared_ptr<Bonus> createBonus() = 0;
    virtual std::shared_ptr<Platform> createPlatform() = 0;
    virtual std::unique_ptr<World> createWorld(std::pair<float,float> borderX, std::pair<float,float> borderY) = 0;
};

#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_ABSTRACTFACTORY_H
