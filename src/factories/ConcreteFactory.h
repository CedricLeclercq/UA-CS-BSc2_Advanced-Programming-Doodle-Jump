//
// Created by Cédric Leclercq on 02/12/2021.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_CONCRETEFACTORY_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_CONCRETEFACTORY_H

#include "AbstractFactory.h"


class ConcreteFactory: public AbstractFactory {
public:
    std::shared_ptr<Player> createPlayer() override;
    std::shared_ptr<BGTile> createBGTile() override;
    std::shared_ptr<Bonus> createBonus() override;
    std::shared_ptr<Platform> createPlatform() override;
    std::shared_ptr<World> createWorld(std::shared_ptr<Camera> camera) override;
    std::unique_ptr<Camera> createCamera(const Coordinates& worldView, const Coordinates& cameraView) override;
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_CONCRETEFACTORY_H
