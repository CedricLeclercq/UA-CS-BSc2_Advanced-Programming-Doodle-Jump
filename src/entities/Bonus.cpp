//
// Created by Cédric Leclercq on 18/11/2021.
//

#include "Bonus.h"
#include "../utilities/Utilities.h"
#include "Player.h"

using Random = Utilities::Random;

Bonus::Bonus(BonusPower power) {
    this->powerKind = power;
    if (Random::randInt(0,1) == 1) {
        this->powerKind = BonusPower::SPRING;
    }
    this->chargePowers();
}

void Bonus::chargePowers() {
    if (this->powerKind == BonusPower::ROCKET) {
        // Rocket will use power as the amount of Y blocks the player moves up
        this->power = 5000;
        return;
    }
    if (this->powerKind == BonusPower::SPRING) {
        // Spring will use power as the offset it gives to a jump of the player, player will jump 5x higher
        this->power = 1.5;
    }

    // ... more bonuses? todo
}

bool Bonus::exhaustedBonus() const {
    return this->power <= 0;
}

void Bonus::takeEffect(Player& player) {
    if (this->powerKind == BonusPower::SPRING) {
        player.setVelocityY(player.getVelocityY() * this->power);
        // player should no longer have effect of the spring after the velocity has worked out
        player.setBonus(nullptr);
        return;
    }
    if (this->powerKind == BonusPower::ROCKET) {
        player.setParalysed(true);
        player.setPosY(player.getPosY() + 1);
        this->power -= 1;
        if (this->power == 0) {
            player.setParalysed(false);
        }
    }
}

BonusPower Bonus::getPowerKind() const {
    return this->powerKind;
}
