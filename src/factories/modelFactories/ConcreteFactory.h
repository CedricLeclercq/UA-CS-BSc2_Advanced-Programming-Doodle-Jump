// // // // // // // // // // // // // //
//                                     //
//         ConcreteFactory.h           //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_CONCRETEFACTORY_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_CONCRETEFACTORY_H

#include "AbstractFactory.h"

/**
 * @class ConcreteFactory: public AbstractFactory (part of Abstract Factory design pattern)
 * @brief A concrete factory for creating our models
 */
class ConcreteFactory: public AbstractFactory {
public:
    /// @brief Default constructor
    ConcreteFactory()=default;
    /// @brief Default destructor
    ~ConcreteFactory()=default;
    /**
     * @brief Concrete factory function to create and return a player
     * @return      Shared pointer to a player
     */
    std::shared_ptr<Entities::Player> createPlayer() override;
    /**
     * @brief Concrete factory function to create and return a background tile
     * @return      Shared pointer to a background tile
     */
    std::shared_ptr<Entities::BGTile> createBGTile() override;
    /**
     * @brief Concrete factory function to create and return a bonus
     * @return      Shared pointer to a bonus
     */
    std::shared_ptr<Entities::Bonus> createBonus() override;
    /**
     * @brief Concrete factory function to create a platform
     * @return      Shared pointer to a platform
     */
    std::shared_ptr<Entities::Platform> createPlatform(PKind kind) override;
    /**
     * @brief Concrete factory function to create a world
     * @param camera    World should be constructed with a camera
     * @return          Shared pointer to a world
     */
    std::shared_ptr<World> createWorld(std::shared_ptr<Camera> camera) override;
    /**
     * @brief Concrete factory function to create a camera
     * @param worldView     Current view of the logic library world
     * @param cameraView    Current view of the graphical library world
     * @return              Unique pointer to a camera
     */
    std::unique_ptr<Camera> createCamera(const Coordinates& worldView, const Coordinates& cameraView) override;
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_CONCRETEFACTORY_H
