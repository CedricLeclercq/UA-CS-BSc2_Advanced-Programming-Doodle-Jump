//
// Created by Cédric Leclercq on 18/11/2021.
//

#ifndef DOODLEJUMP_WORLD_H
#define DOODLEJUMP_WORLD_H

#include "../entities/Player.h"
#include "../entities/Platform.h"
#include "Camera.h"
#include <memory>


class World {
private:
    std::shared_ptr<Player> player;
    std::vector<std::shared_ptr<Platform>> platforms;
    std::shared_ptr<Camera> m_camera;
    void placePlatforms();
    /**
     * Will remove all elements that fall out of the view of the world
     * @param minY
     * @param maxY
     */
    void removeOutOfView(float minY, float maxY);
public:
    /**
     * This function is responsible for applying any change needed to the world after the player moved
     */
    void updateWorld();
    bool collisionCheckPlatform();

    // TODO let the player come from the concrete factory
    World(std::shared_ptr<Camera> camera) : player(new Player()), m_camera(camera) {}

    std::shared_ptr<Player> getPlayer() {
        return this->player;
    }

    std::vector<std::shared_ptr<Platform>> getPlatforms();

    void createPlatforms(float minY, float maxY);

    void movePlatforms();

};


#endif //DOODLEJUMP_WORLD_H
