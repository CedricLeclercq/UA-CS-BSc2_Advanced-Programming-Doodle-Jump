//
// Created by Cédric Leclercq on 04/01/2022.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_VIEW_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_VIEW_H

#include "Views.h"
#include <memory>
#include "../models/Entity.h"

#include "../textureManagers/TextureManagers.h"

class Views::View {
protected:
    sf::Sprite view{};
    virtual void setup() = 0;
public:
    View()=default;
    explicit View(const std::shared_ptr<Entity>& entity): view{sf::Sprite{}} {};
    ~View()=default;
    void setPosition(float x, float y) {view.setPosition(x,y); }
    sf::Sprite getView() const {return view;}
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_VIEW_H
