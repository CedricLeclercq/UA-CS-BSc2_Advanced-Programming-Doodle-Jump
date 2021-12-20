// // // // // // // // // // // // // //
//                                     //
//              Bonus.h                //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#ifndef DOODLEJUMP_BONUS_H
#define DOODLEJUMP_BONUS_H

#include "../../utilities/Utilities.h"
#include "../Entities.h"


/// @brief Enumeration for the kind of power a bonus can have (more can easily be added)
enum BonusPower {
    SPRING,
    ROCKET
    };


class Entities::Bonus: public Entity {
private:
    /// @brief Power that the bonus has left to help the player
    float power{};
    /// @brief Kind of bonus we have
    BonusPower powerKind{};
    /**
      * @brief Function that will look at the kind of power a bonus has and give the needed power to the bonus
      */
    void chargePowers();

public:
    /**
     * @brief Basic constructor for a bonus
     * @param power     Default argument for which power kind
     * @note            The default argument is not used for now, but can be used if future implementation might need it
     */
    explicit Bonus(BonusPower power=ROCKET);
    /**
     * @brief Will check if a bonus' power is 0
     * @return      (bonus.noMorePower?)
     */
    bool exhaustedBonus() const;
    /**
     * @brief Will give the effect of the bonus to the player
     * @param player    Reference to the player the effect should be on
     */
    void takeEffect(Entities::Player& player);
    /**
     * @brief Getter for the power kind of the bonus
     * @return      Kind of power
     */
    BonusPower getPowerKind() const;
    /**
     * @brief Will move the bonus to the right
     * @note This function is currently not defined and not used (not needed, but is in place if it ever is)
     */
    void moveRight() override {}
    /**
      * @brief Will move the bonus to the left
      * @note This function is currently not defined and not used (not needed, but is in place if it ever is)
      */
    void moveLeft() override {}
};


#endif //DOODLEJUMP_BONUS_H
