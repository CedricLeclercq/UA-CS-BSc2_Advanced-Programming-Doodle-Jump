//
// Created by Cédric Leclercq on 06/12/2021.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_BGTILECONTROLLER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_BGTILECONTROLLER_H

#include "../Controllers.h"
#include "../../entities/background/BGTile.h"

class Controllers::BGTileController: public Controller {
private:
    std::shared_ptr<BGTile> model;
public:
    BGTileController()=default;
    explicit BGTileController(std::shared_ptr<BGTile> nModel);
    void loadNewPlatform(std::shared_ptr<BGTile> nTile);
    std::shared_ptr<sf::Sprite> getView() const;
    std::shared_ptr<BGTile> getModel() const;
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_BGTILECONTROLLER_H
