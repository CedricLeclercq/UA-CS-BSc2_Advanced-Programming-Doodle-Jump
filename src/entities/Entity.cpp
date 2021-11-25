//
// Created by Cédric Leclercq on 25/11/2021.
//

#include "Entity.h"

std::shared_ptr<Utilities::Coordinates> Entity::getPos() {
    return this->position;
}

float Entity::getPosX() {
    return this->position->getX();
}

float Entity::getPosY() {
    return this->position->getY();
}

void Entity::move(float offsetX, float offsetY) {
    this->position->setX(this->position->getX() + offsetX);
    this->position->setY(this->position->getY() + offsetY);
}

void Entity::setPos(float nX, float nY) {
    this->position->setX(nX);
    this->position->setY(nY);
}

void Entity::setPosX(float nX) {
    this->position->setX(nX);
}

void Entity::setPosY(float nY) {
    this->position->setY(nY);
}
