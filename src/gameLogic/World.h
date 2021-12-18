//
// Created by Cédric Leclercq on 18/11/2021.
//

#ifndef DOODLEJUMP_WORLD_H
#define DOODLEJUMP_WORLD_H

#include "../entities/Player.h"
#include "../entities/Platform.h"
#include "../entities/background/BGTile.h"
#include "Camera.h"
#include <memory>


class World {
private:
    /// Shared pointer to our main player
    std::shared_ptr<Player> player;
    /// Vector with shared pointer to all our platforms
    std::vector<std::shared_ptr<Platform>> platforms;
    /// Vector with shared pointer to our background elements
    std::vector<std::shared_ptr<BGTile>> bgTiles;
    /// Shared pointer to the camera view of our world
    std::shared_ptr<Camera> m_camera;
    /// Standard player length
    float playerLength{};
    /// Standard platform length
    float platformLength{};
    void createPlatforms();
    void placeBackground();
    void createBackground();
    Coordinates findHighestStar() const;
    Coordinates findHighestPlatform() const; // todo change to shared poniter
    std::shared_ptr<Platform> findLowestPlatform();
    std::shared_ptr<BGTile> findLowestStar();
    bool newPlatformsNeeded();
    bool newStarsNeeded();
    /**
     * Will remove all elements that fall out of the view of the world
     */
    void removeOutOfView();

    std::vector<std::shared_ptr<Entity>> removeOutOfView(std::vector<std::shared_ptr<Entity>> entities, int maxSize);
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

    void setPlayerLength(float length) {
        this->playerLength = length;
    }

    void setPlatformLength(float length) {
        this->platformLength = length;
    }

    std::vector<std::shared_ptr<BGTile>> getBackground() const {
        return this->bgTiles;
    }

    std::vector<std::shared_ptr<Platform>> getPlatforms();


    void movePlatforms();

};


#endif //DOODLEJUMP_WORLD_H
