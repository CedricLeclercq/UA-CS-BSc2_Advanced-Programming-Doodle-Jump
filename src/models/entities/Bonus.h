//
// Created by Cédric Leclercq on 18/11/2021.
//

#ifndef DOODLEJUMP_BONUS_H
#define DOODLEJUMP_BONUS_H

#include "../../utilities/Utilities.h"
#include "../Entities.h"


enum BonusPower {
    SPRING,
    ROCKET
    };


class Entities::Bonus: public Entity {
private:
    /// Power that the bonus has left to help the player
    float power{};
    /// Kind of bonus we have
    BonusPower powerKind{};
    /**
      * Function that will look at the kind of power a bonus has and give the needed power to the bonus
      */
    void chargePowers();

public:
    /**
     * Basic constructor for a bonus
     * @param power
     */
    explicit Bonus(BonusPower power=ROCKET);
    /**
     * Will check if a bonus' power is 0
     * @return
     */
    bool exhaustedBonus() const;

    void takeEffect(Entities::Player& player);

    BonusPower getPowerKind() const;

    void moveRight() override {}
    void moveLeft() override {}
};


#endif //DOODLEJUMP_BONUS_H
