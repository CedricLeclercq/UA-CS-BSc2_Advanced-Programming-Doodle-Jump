//
// Created by Cédric Leclercq on 18/11/2021.
//

#ifndef DOODLEJUMP_WORLD_H
#define DOODLEJUMP_WORLD_H

#include "../entities/Player.h"
#include "../entities/Platform.h"
#include <memory>


class World {
private:
    std::shared_ptr<Player> player;
    std::vector<std::shared_ptr<Platform>> platforms;
    std::pair<float,float> borderX;
    std::pair<float,float> borderY;
    void placePlatforms();
    /**
     * Will remove all elements that fall out of the view of the world
     * @param minY
     * @param maxY
     */
    void removeOutOfView(float minY, float maxY);
public:
    World(std::pair<float,float> nBorderX, std::pair<float,float> nBorderY) : player(new Player()) {
        this->borderX = nBorderX;
        this->borderY = nBorderY;
    }

    std::shared_ptr<Player> getPlayer() {
        return this->player;
    }

    std::vector<std::shared_ptr<Platform>> getPlatforms();

    void createPlatforms(float minY, float maxY);
};


#endif //DOODLEJUMP_WORLD_H
