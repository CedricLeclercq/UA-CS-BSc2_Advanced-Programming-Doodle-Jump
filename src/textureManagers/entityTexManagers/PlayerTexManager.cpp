//
// Created by Cédric Leclercq on 05/01/2022.
//

#include "PlayerTexManager.h"

void TextureManagers::PlayerTexManager::loadTextures() {
    // Loading normal texture
    normalTex.loadFromFile(pathNormal);
    // Loading rocket texture
    rocketTex.loadFromFile(pathRocket);
}

void TextureManagers::PlayerTexManager::setTexture(sf::Sprite &sprite, bool isRocket) const {
    if (isRocket) sprite.setTexture(rocketTex);
    else sprite.setTexture(normalTex);
    // Setting the correct scale for the player
    sprite.setScale(0.4,0.4);
    // Setting the correct origin for the player
    sprite.setOrigin(0, sprite.getLocalBounds().height);
}

bool TextureManagers::PlayerTexManager::texturesFound() {
    if (!Utils::pathExists(pathNormal)) return false;
    if (!Utils::pathExists(pathRocket)) return false;
    return true;
}

TextureManagers::PlayerTexManager &TextureManagers::PlayerTexManager::getInstance() {
    static PlayerTexManager instance;
    return instance;
}
