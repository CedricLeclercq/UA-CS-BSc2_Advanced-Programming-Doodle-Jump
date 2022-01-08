//
// Created by Cédric Leclercq on 05/01/2022.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_WORLDCONTROLLER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_WORLDCONTROLLER_H

#include <memory>
#include <utility>
#include "../gameLogic/World.h"

class WorldController {
private:
    std::shared_ptr<World> m_world;
public:
    WorldController()=default;
    explicit WorldController(std::shared_ptr<World> nWorld): m_world(std::move(nWorld)) {}
    /**
     * @brief Handles the sfml input and moves the model based on this input - right
     */
    void movePlayerRight() const {m_world->getPlayer()->moveRight();}
    /**
     * @brief Handles the sfml input and moves the model based on this input - left
     */
    void movePlayerLeft() const {m_world->getPlayer()->moveLeft();}
    /**
     * @brief Will teleport the player if it falls out of the border
     */
     void evalOutOfWorld(float minX, float maxX) {m_world->getPlayer()->teleportPlayer(minX,maxX);}

     void updateWorld() const {m_world->updateWorld();}

     void setLengths(float playerLength, float platformLength);

     bool isGameOver() const {return m_world->checkGameOver();}

     std::shared_ptr<Entities::Player> getPlayer() const {return this->m_world->getPlayer();}
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_WORLDCONTROLLER_H
