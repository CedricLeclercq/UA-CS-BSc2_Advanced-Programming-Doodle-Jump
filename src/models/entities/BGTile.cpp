// // // // // // // // // // // // // //
//                                     //
//            BGTile.cpp               //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#include "BGTile.h"

using Random = Utilities::Random;

void Entities::BGTile::defineKind() {
    // Getting a random number
    float random = Random::getInstance().randFloat(0,1000);

    // STAR1 generates
    if (random <= 950) {
        this->kind = TKind::STAR1;
        return;
    }
    // STAR2 generates
    if (random <= 980) {
        this->kind = TKind::STAR2;
        return;
    }
    // PLANETx generates
    if (random <= 998) {
        int randomPlanet = Random::getInstance().randInt(1,6);
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
        // MILKYWAYx generates
        int randomMilkyWay = Random::getInstance().randInt(1,2);
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

Entities::BGTile::BGTile(): observer(std::make_shared<Observers::BGTileObserver>()) {
    this->kind = TKind::NONE;
    this->defineKind();
}

TKind Entities::BGTile::getKind() const {
    return this->kind;
}
