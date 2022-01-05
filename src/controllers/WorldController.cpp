//
// Created by Cédric Leclercq on 05/01/2022.
//

#include "WorldController.h"

void WorldController::setLengths(float playerLength, float platformLength) {
    m_world->setPlatformLength(platformLength);
    m_world->setPlayerLength(playerLength);
    m_world->getPlayer()->setLength(playerLength);
}
