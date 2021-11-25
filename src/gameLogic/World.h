//
// Created by Cédric Leclercq on 18/11/2021.
//

#ifndef DOODLEJUMP_WORLD_H
#define DOODLEJUMP_WORLD_H

#include "../entities/Player.h"
#include <memory>


class World {
private:
    std::unique_ptr<Player> player;
public:
    World()=default;


};


#endif //DOODLEJUMP_WORLD_H
