//
// Created by Cédric Leclercq on 04/01/2022.
//

#include "PlatformView.h"
#include "../textureManagers/entityTexManagers/PlatformTexManager.h"

using Utils = Utilities::Utils;

Views::PlatformView::PlatformView(const std::shared_ptr<Entities::Platform> &platform):
    platformKind(platform->getKind()) {
    // Linking observer
    observer = platform->observer;
    // Setting bonus kind
    if (platform->getBonus() == nullptr) bonusKind = BonusPower::NOTDEF;
    else (bonusKind = platform->getBonus()->getPowerKind());
}


void Views::PlatformView::setup() {
    // Loading all the textures if possible
    if (TextureManagers::PlatformTexManager::getInstance().texturesFound() and not texLoaded) {
        TextureManagers::PlatformTexManager::getInstance().loadTextures();
        texLoaded = true;
    } else { std::cerr << "A texture in playerView was not able to be loaded!" << std::endl; }
    TextureManagers::PlatformTexManager::getInstance().setTexture(view,platformKind,bonusKind);
}
