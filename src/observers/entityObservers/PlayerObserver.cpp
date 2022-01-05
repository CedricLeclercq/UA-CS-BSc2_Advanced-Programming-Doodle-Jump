//
// Created by Cédric Leclercq on 26/12/2021.
//

#include "PlayerObserver.h"

void Observers::PlayerObserver::notifyObserver() {}

bool Observers::PlayerObserver::getNotified() {return false;}

void Observers::PlayerObserver::resetObserver() {} //todo implement

bool Observers::PlayerObserver::getNotifiedRocket() const {
    return this->isRocket;
}

void Observers::PlayerObserver::notifyIsRocket(bool newBool) {
    this->isRocket = newBool;
}
