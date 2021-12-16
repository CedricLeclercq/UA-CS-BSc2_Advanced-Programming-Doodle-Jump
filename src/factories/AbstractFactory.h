//
// Created by Cédric Leclercq on 02/12/2021.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_ABSTRACTFACTORY_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_ABSTRACTFACTORY_H

#include <memory>
#include "../entities/Player.h"
#include "../entities/background/BGTile.h"
#include "../entities/Bonus.h"
#include "../entities/Platform.h"
#include "../gameLogic/World.h"
#include "../gameLogic/Camera.h"


class AbstractFactory {
protected:
    virtual std::shared_ptr<Player> createPlayer() = 0;
    virtual std::shared_ptr<BGTile> createBGTile() = 0;
    virtual std::shared_ptr<Bonus> createBonus() = 0;
    virtual std::shared_ptr<Platform> createPlatform() = 0;
    virtual std::shared_ptr<World> createWorld(std::shared_ptr<Camera> camera) = 0;
    virtual std::unique_ptr<Camera> createCamera(const Coordinates& worldView, const Coordinates& cameraView) = 0;
};

#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_ABSTRACTFACTORY_H
