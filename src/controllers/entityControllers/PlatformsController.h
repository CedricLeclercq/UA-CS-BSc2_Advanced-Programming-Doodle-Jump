//
// Created by Cédric Leclercq on 06/12/2021.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_PLATFORMSCONTROLLER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_PLATFORMSCONTROLLER_H

#include "../Controllers.h"
#include "../../entities/Platform.h"


class Controllers::PlatformsController: public Controller {
private:
    std::shared_ptr<Platform> model;
public:
    PlatformsController()=default;
    explicit PlatformsController(std::shared_ptr<Platform> nModel);
    void loadNewPlatform(std::shared_ptr<Platform> nPlatform);
    std::shared_ptr<sf::Sprite> getView() const;
    std::shared_ptr<Platform> getModel() const;
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_PLATFORMSCONTROLLER_H
