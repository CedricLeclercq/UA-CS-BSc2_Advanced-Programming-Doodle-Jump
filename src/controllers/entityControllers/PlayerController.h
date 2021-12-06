//
// Created by Cédric Leclercq on 06/12/2021.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYERCONTROLLER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYERCONTROLLER_H

#include "../../entities/Player.h"

#include "../Controllers.h"

class Controllers::PlayerController: public Controller {
public:
    void handleInput();
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYERCONTROLLER_H
