//
// Created by Cédric Leclercq on 06/12/2021.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_PLATFORMCONTROLLER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_PLATFORMCONTROLLER_H

#include "../Controllers.h"
#include "../../entities/Platform.h"


class Controllers::PlatformController: public Controller {
public:
    static std::vector<sf::Sprite> getViews(const std::vector<std::shared_ptr<Platform>>& platforms);

};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_PLATFORMCONTROLLER_H
