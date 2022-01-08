//
// Created by Cédric Leclercq on 04/01/2022.
//

#include "PlayerView.h"
#include <iostream>
#include "../models/entities/Player.h"
#include "../textureManagers/entityTexManagers/PlayerTexManager.h"

using Utils = Utilities::Utils;

Views::PlayerView::PlayerView(const std::shared_ptr<Entities::Player> &player) {
    observer = player->observer;
}

void Views::PlayerView::setup() {
    // Loading all the textures
    if (TextureManagers::PlayerTexManager::getInstance().texturesFound() and not texLoaded) {
        TextureManagers::PlayerTexManager::getInstance().loadTextures();
        texLoaded = true;
    } else { std::cerr << "A texture in playerView was not able to be loaded!" << std::endl; }
    // Setting the standard texture
    TextureManagers::PlayerTexManager::getInstance().setTexture(*view,false);

}

void Views::PlayerView::setRocketTex() {
    TextureManagers::PlayerTexManager::getInstance().setTexture(*view,true);
}

void Views::PlayerView::setNormalTex() {
    TextureManagers::PlayerTexManager::getInstance().setTexture(*view,false);
}





