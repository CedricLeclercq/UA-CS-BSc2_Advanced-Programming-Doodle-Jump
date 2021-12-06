//
// Created by Cédric Leclercq on 18/11/2021.
//

#ifndef DOODLEJUMP_BGTILE_H
#define DOODLEJUMP_BGTILE_H

#include "../utilities/Utilities.h"
#include "Entity.h"

// TODO link to entity

class BGTile: public Entity {
public:
    BGTile()=default;
    void moveRight() override {};
    void moveLeft() override {};
    void moveUp();
    void moveDown();
};


#endif //DOODLEJUMP_BGTILE_H
