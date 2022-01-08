// // // // // // // // // // // // // //
//                                     //
//         AbstractFactory.h           //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_ABSTRACTFACTORY_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_ABSTRACTFACTORY_H

#include <memory>
#include "models/entities/Player.h"
#include "models/entities/BGTile.h"
#include "models/entities/Bonus.h"
#include "models/entities/Platform.h"
#include "gameLogic/Score.h"
#include "gameLogic/Camera.h"
class World;

/**
 * @class Abstract factory
 * @brief An abstract factory class for everything in the game (based on the Abstract Factory design pattern)
 */
class AbstractFactory {
protected:
    /**
     * @brief Default constructor
     */
    AbstractFactory()=default;
    /**
     * @brief Default destructor
     */
    ~AbstractFactory()=default;
    /**
     * @brief Pure virtual function to create a player
     * @return      Shared pointer to a player
     */
    virtual std::shared_ptr<Entities::Player> createPlayer() = 0;
    /**
     * @brief Pure virtual function to create a background tile
     * @return      Shared pointer to a background tile
     */
    virtual std::shared_ptr<Entities::BGTile> createBGTile() = 0;
    /**
     * @brief Pure virtual function to create a bonus
     * @return      Shared pointer to a bonus
     */
    virtual std::shared_ptr<Entities::Bonus> createBonus() = 0;
    /**
     * @brief Pure virtual function to create a platform
     * @return      Shared pointer to a platform
     */
    virtual std::shared_ptr<Entities::Platform> createPlatform(PKind kind) = 0;
    /**
     * @brief Pure virtual function to create the world
     * @param camera    World will be made with keeping a camera in mind
     * @return          Shared pointer to a world
     */
    virtual std::shared_ptr<World> createWorld(std::shared_ptr<Camera> camera) = 0;
    /**
     * @brief Pure virtual function to create a camera
     * @param worldView     The view of the logic library world
     * @param cameraView    The view of the graphical library world
     * @return              Unique pointer to a camera (only one pointer will exist)
     */
    virtual std::unique_ptr<Camera> createCamera(const Coordinates& worldView, const Coordinates& cameraView) = 0;
    /**
     * @brief Pure virtual function to create a shared pointer to a score object
     * @return      shared pointer to a score object
     */
    virtual std::shared_ptr<Score> createScore() = 0;
};

#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_ABSTRACTFACTORY_H
