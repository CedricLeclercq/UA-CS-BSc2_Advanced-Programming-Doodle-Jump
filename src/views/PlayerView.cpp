//
// Created by Cédric Leclercq on 04/01/2022.
//

#include "PlayerView.h"
#include <iostream>
#include "../models/entities/Player.h"

using Utils = Utilities::Utils;

Views::PlayerView::PlayerView(const std::shared_ptr<Entities::Player> &player): normalTex(), rocketTex() {
    observer = player->observer;
}

void Views::PlayerView::loadTextures() {
    // Loading normal texture
    normalTex.loadFromFile(pathNormal);
    // Loading rocket texture
    rocketTex.loadFromFile(pathRocket);
    texLoaded = true;
}

void Views::PlayerView::setup() {
    // Loading all the textures
    if (texturesFound() and not texLoaded) {
        loadTextures();
    } else { std::cerr << "A texture in playerView was not able to be loaded!" << std::endl; }
    // Setting the standard texture
    view.setTexture(normalTex);
    // Setting the correct scale for the player
    view.setScale(0.4,0.4);
    // Setting the correct origin for the player
    view.setOrigin(0, view.getLocalBounds().height);
}

bool Views::PlayerView::texturesFound() {
    if (!Utils::pathExists(pathNormal)) return false;
    if (!Utils::pathExists(pathRocket)) return false;
    return true;
}

void Views::PlayerView::setRocketTex() {
    view.setTexture(rocketTex);
}

void Views::PlayerView::setNormalTex() {
    view.setTexture(normalTex);
}





