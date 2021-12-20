//
// Created by Cédric Leclercq on 25/11/2021.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_ENTITY_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_ENTITY_H

#include <utility>
#include <memory>

#include "../utilities/Utilities.h"

class Entity {
protected:
    std::shared_ptr<Utilities::Coordinates> position{};
    float length{};
    float height{};
    virtual void moveRight() = 0;
    virtual void moveLeft() = 0;
    void move(float offsetX, float offsetY);
public:
    Entity() {
        this->position = std::make_shared<Utilities::Coordinates>(0,0);
    }
    void setPos(float nX, float nY);
    void setPosX(float nX);
    void setPosY(float nY);
    std::shared_ptr<Utilities::Coordinates> getPos();
    float getPosX();
    float getPosY();

    void setLength(float nLength);
    void setHeight(float nHeight);
    float getLength() const {return this->length; }
    float getHeight() const {return this->height; }
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_ENTITY_H
