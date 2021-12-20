//
// Created by Cédric Leclercq on 18/11/2021.
//

#ifndef DOODLEJUMP_BGTILE_H
#define DOODLEJUMP_BGTILE_H

#include "../Entities.h"

/// @brief Enumeration of the possible tile kinds
enum TKind {
    NONE,
    PLANET1,
    PLANET2,
    PLANET3,
    PLANET4,
    PLANET5,
    PLANET6,
    STAR1,
    STAR2,
    MILKYWAY1,
    MILKYWAY2
    };


class Entities::BGTile: public Entity {
private:
    TKind kind;

    void defineKind();
public:
    BGTile() {
        this->kind = TKind::NONE;
        this->defineKind();
    }

    TKind getKind() const {return this->kind; }
    void moveRight() override {};
    void moveLeft() override {};
};


#endif //DOODLEJUMP_BGTILE_H
