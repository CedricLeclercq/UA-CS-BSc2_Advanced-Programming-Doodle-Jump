//
// Created by Cédric Leclercq on 05/01/2022.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_WORLDCONTROLLER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_WORLDCONTROLLER_H

#include <memory>
#include <utility>
#include "../gameLogic/World.h"

/**
 * @class WorldController
 * @brief A controller for providing an interface between the graphical world and the logic one
 */
class WorldController {
private:
    /// @brief A shared pointer to the world
    std::shared_ptr<World> m_world;
public:
    /**
     * @brief Default constructor
     */
    WorldController()=default;
    /**
     * @brief Default destructor
     */
     ~WorldController()=default;
    /**
     * @brief Constructor that also initialises the world
     * @param nWorld    new world to initialise
     */
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
     * @param minX  minimal x coordinate for the player
     * @param maxX  maximal x coordinate for the player
     */
     void evalOutOfWorld(float minX, float maxX) {m_world->getPlayer()->teleportPlayer(minX,maxX);}
    /**
     * @brief Will ask the world to update itself
     */
     void updateWorld() const {m_world->updateWorld();}
    /**
     * @brief Will set the lengths in the world for for example the collision check
     * @param playerLength      length of the player texture
     * @param platformLength    length of the platform texture
     */
     void setLengths(float playerLength, float platformLength);
    /**
     * @grief Will ask the world if the game is over (so if the player has died
     * @return      gameOver?
     */
     bool isGameOver() const {return m_world->checkGameOver();}
    /**
     * @brief Getter for the player
     * @return  world->getPlayer()
     */
     std::shared_ptr<Entities::Player> getPlayer() const {return this->m_world->getPlayer();}
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_WORLDCONTROLLER_H
