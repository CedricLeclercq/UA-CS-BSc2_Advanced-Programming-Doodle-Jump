// // // // // // // // // // // // // //
//                                     //
//               World.h               //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#ifndef DOODLEJUMP_WORLD_H
#define DOODLEJUMP_WORLD_H

#include "../models/entities/Player.h"
#include "../models/entities/Platform.h"
#include "../observers/entityObservers/WorldObserver.h"
#include "../models/entities/BGTile.h"
#include "factories/modelFactories/ConcreteFactory.h"
#include "Camera.h"
#include <memory>
#include <utility>
#include "Score.h"


class World {
private:
    /// @brief Shared pointer to our main player
    std::shared_ptr<Entities::Player> player;
    /// @brief Vector with shared pointer to all our platforms
    std::vector<std::shared_ptr<Entities::Platform>> platforms;
    /// @brief Vector with shared pointer to our background elements
    std::vector<std::shared_ptr<Entities::BGTile>> bgTiles;
    /// @brief Vector with shared pointer to our bonuses
    std::vector<std::shared_ptr<Entities::Bonus>> bonuses;
    /// @brief Shared pointer to the camera view of our world
    std::shared_ptr<Camera> m_camera;
    /// @brief Shared pointer to the previous platform the player jumped on
    std::shared_ptr<Entities::Platform> prevPlatform;
    /// @brief Standard player length
    float playerLength{};
    /// @brief Standard platform length
    float platformLength{};
    /// @brief score of the game
    std::shared_ptr<Score> score;
    /**
     * @brief Create platforms and place them in the world (only if new platforms are needed)
     */
    void createPlatforms();
    /**
     * @brief Create all the background elements and place them in the world (only if new background elem are needed)
     */
    void createBackground();
    /**
     * @brief Decide if a platform will get a bonus, create a bonus and place it on the platform
     * @param platform      Given platform to evaluate
     */
    static void createBonus(const std::shared_ptr<Entities::Platform>& platform);
    /**
     * @brief Finds the highest star in the world
     * @return      Coordinates to the highest star in the world
     */
    Coordinates findHighestStar() const;
    /**
     * @brief Finds the highest platform in the world
     * @return      Coordinates to the highest platform in the world
     */
    Coordinates findHighestPlatform() const;
    /**
     * @brief Finds the lowest platform in the world
     * @return      Shared pointer to the lowest platform in the world
     */
    std::shared_ptr<Entities::Platform> findLowestPlatform();
    /**
     * @brief Finds the lowest star in the world
     * @return      Shared pointer to the lowest star in the world
     */
    std::shared_ptr<Entities::BGTile> findLowestStar();
    /**
     * @brief Finds the lowest bonus in the world
     * @return      Shared pointer to the lowest bonus in the world
     */
    __attribute__((unused)) std::shared_ptr<Entities::Bonus> findLowestBonus();
    /**
     * @brief Defines if new platforms are needed in the world
     * @return      (needNewPlatforms?)
     */
    bool newPlatformsNeeded();
    /**
     * @brief Defines if new stars are needed in the world
     * @return      (needNewStars?)
     */
    bool newStarsNeeded();
    /**
     * @brief Removes a platform from all the platforms in the world
     * @param toRemove      A shared pointer to the platform we need to remove
     */
    void removePlatform(const std::shared_ptr<Entities::Platform>& toRemove);
    /**
     * @brief Remove all the elements that fall out of the world window
     */
    void removeOutOfView();
    /**
     * @brief Adds to the main score a score based on which platform we jumped on
     * @param platform      A shared pointer to the platform we jumped on
     */
    void addPlatformScore(const std::shared_ptr<Entities::Platform>& platform);
    /**
     * @brief Adds to the main score a score based on which bonus was picked up
     * @param bonus         A shared pointer to the bonus we picked up
     */
    void addBonusScore(const std::shared_ptr<Entities::Bonus>& bonus);
    /**
     * @brief Checks if the player collided with a platform
     * @return      (player.collidedWithPlatform?)
     */
    bool collisionCheckPlatform();
    /**
     * @brief Will move the horizontal and vertical platforms
     */
    void movePlatforms();
    /**
     * @brief Will calculate the current difficulty of the game
     * @return // todo
     */
    double calculateDifficulty() const;

    static PKind difficultyPlatformOverride(double diff) ;
public:
    World()=default;
    /**
     * @brief Constructor for the world, will create a player and accept a camera for world view purposes
     * @param camera
     */
    explicit World(std::shared_ptr<Camera> camera);
    /**
     * @brief Update the world after one loop (Update the player, the platforms, the bonuses, ...)
     */
    void updateWorld();
    /**
     * @brief Getter for the player
     * @return      Shared pointer to the player;
     */
    std::shared_ptr<Entities::Player> getPlayer();
    /**
     * @brief Will set the standard length of the player (needed for the collision check)
     * @param length    Player length
     */
    void setPlayerLength(float length);
    /**
     * @brief Will set the standard length of a platform (needed for the collision check)
     * @param length    Platform length
     */
    void setPlatformLength(float length);
    /**
     * @brief Getter for the background in the world
     * @return      Vector with shared pointers to the background tiles
     */
    std::vector<std::shared_ptr<Entities::BGTile>> getBackground();
    /**
     * @brief Getter for the platforms in the world
     * @return      Vector with shared pointers to the platforms
     */
    std::vector<std::shared_ptr<Entities::Platform>> getPlatforms();
    /**
     * @brief Getter for the bonuses in the world
     * @return      Vector with shared pointers to the bonuses
     */
    __attribute__((unused)) std::vector<std::shared_ptr<Entities::Bonus>> getBonuses() const {return this->bonuses; }
    /**
     * @brief Checks is the game is over in the world by comparing Y coordinates with the lowest allowed
     * @return      (gameOver?)
     */
    bool checkGameOver();
};


#endif //DOODLEJUMP_WORLD_H
