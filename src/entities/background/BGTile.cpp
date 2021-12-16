//
// Created by Cédric Leclercq on 18/11/2021.
//

#include "BGTile.h"
#include "../../utilities/Utilities.h"

using Random = Utilities::Random;

void BGTile::defineKind() {
    // Getting a random number
    float random = Random::randFloat(0,100);

    // 90% of the time a STAR1 generates
    if (random <= 90) {
        this->kind = TKind::STAR1;
        return;
    }
    // 5% of the time a STAR2 generates
    if (random <= 95) {
        this->kind = TKind::STAR2;
        return;
    }
    // 4% of the time a PLANETx generates
    if (random <= 99) {
        int randomPlanet = Random::randInt(1,6);
        switch (randomPlanet) {
            case 1:
                this->kind = TKind::PLANET1;
                break;
            case 2:
                this->kind = TKind::PLANET2;
                break;
            case 3:
                this->kind = TKind::PLANET3;
                break;
            case 4:
                this->kind = TKind::PLANET4;
                break;
            case 5:
                this->kind = TKind::PLANET5;
                break;
            case 6:
                this->kind = TKind::PLANET6;
                break;
            default:
                this->kind = TKind::PLANET1;
                break;
        }
    } else {
        // 1% of the time a MILKYWAYx generates
        int randomMilkyWay = Random ::randInt(1,2);
        switch (randomMilkyWay) {
            case 1:
                this->kind = TKind::MILKYWAY1;
                break;
            case 2:
                this->kind = TKind::MILKYWAY2;
                break;
            default:
                this->kind = TKind::MILKYWAY1;
                break;
        }
    }
}
