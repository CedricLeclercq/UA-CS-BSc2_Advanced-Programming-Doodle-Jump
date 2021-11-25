//
// Created by Cédric Leclercq on 18/11/2021.
//

#ifndef DOODLEJUMP_WORLD_H
#define DOODLEJUMP_WORLD_H

#include "../entities/Player.h"
#include <memory>


class World {
private:
    std::shared_ptr<Player> player;
public:
    World() : player(new Player()) {
        // TODO todo
    }

    std::shared_ptr<Player> getPlayer() {
        return this->player;
    }


};


#endif //DOODLEJUMP_WORLD_H
