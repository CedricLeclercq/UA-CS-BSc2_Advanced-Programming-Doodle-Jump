// // // // // // // // // // // // // //
//                                     //
//              Player.h               //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYER_H


#include <memory>
#include <utility>
#include "Bonus.h"
#include "../Entities.h"


class Entities::Player: public Entity {
private:
    /// @brief Indicator if the player is looking left
    bool mLookLeft{};
    /// @brief Indicator if the player is able to move up and down on itself - for now only used by bonuses
    bool paralysedY{};
    /// @brief Velocity Y the player is currently moving at
    float velocityY{};
    /// @brief Delta ticks at the beginning of the jump
    float deltaAtJump{};
    /// @brief Shared pointer to the bonus the player is currenlty having an effect from
    std::shared_ptr<Entities::Bonus> bonus{};
public:
    /**
     * @brief Basic constructor for the player
     */
    Player() {
        this->position = std::make_shared<Utilities::Coordinates>(0.5,0.f);
        this->deltaAtJump = 1;
        this->mLookLeft = false;
        this->paralysedY = false;
    }
    /**
     * @brief Will move the player to the right with a fixed value
     */
    void moveRight() override;
    /**
     * @brief Will move the player to the left with a fixed speed
     */
    void moveLeft() override;
    /**
     * @brief Will let the player jump
     * @param newJump       (does the player do a new jump?) else (continue prev. jump)
     */
    void jump(bool newJump=false);
    /**
     * @brief Setter for the velocity Y of the player
     * @param velocity      new velocity Y
     */
    void setVelocityY(float velocity);
    /**
     * @brief Getter for the velocity Y of the player
     * @return      Player current velocity Y
     */
    float getVelocityY() const {
        return this->velocityY;
    }
    /**
     * @brief Getter for if the player is looking left
     * @return      (playerLookingLeft?)
     */
    bool getLookingLeft() const;
    /**
     * @brief Will teleport the player is it goes over the edges of the world
     * @param minX      Min edge X
     * @param maxX      Max edge X
     */
    void teleportPlayer(float minX, float maxX);
    /**
     * @brief Setter for the bonus the player currently is having effect from
     * @param nBonus        New bonus to give to the player
     */
    void setBonus(std::shared_ptr<Entities::Bonus> nBonus);
    /**
     * @brief Getter for the bonus the player currently is having effect from
     * @return      Current bonus
     */
    std::shared_ptr<Entities::Bonus> getBonus() const;
    /**
     * @brief Setter for the is the player is paralysedY (aka not able to move up and down on itself)
     * @param paralysed     new paralysed bool
     */
    void setParalysed(bool paralysed);
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYER_H