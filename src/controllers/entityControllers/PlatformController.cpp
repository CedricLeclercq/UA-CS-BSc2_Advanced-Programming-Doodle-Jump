//
// Created by Cédric Leclercq on 06/12/2021.
//

#include "PlatformController.h"

std::vector<sf::Sprite> Controllers::PlatformController::getViews(const std::vector<std::shared_ptr<Platform>>& platforms) {
    std::vector<sf::Sprite> result;
    for (const auto& platform: platforms) {
        sf::Sprite newPlatform; // Problem because this is local?
        newPlatform.setPosition(platform->getPosX(),platform->getPosY());

    }

}
