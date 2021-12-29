//
// Created by Cédric Leclercq on 26/12/2021.
//

#include "PlayerObserver.h"

void Observers::PlayerObserver::notifyObserver() {
    this->playerChanged = true;
}

bool Observers::PlayerObserver::getNotified() {
    return this->playerChanged;
}

void Observers::PlayerObserver::resetObserver() {

}

bool Observers::PlayerObserver::getIsRocket() const {
    return this->isRocket;
}

Observers::PlayerObserver &Observers::PlayerObserver::getInstance() {
    static PlayerObserver instance;
    return instance;
}

void Observers::PlayerObserver::setIsRocket(bool newBool) {
    this->isRocket = newBool;
}
