//
// Created by Cédric Leclercq on 04/01/2022.
//

#include "PlatformView.h"

using Utils = Utilities::Utils;

Views::PlatformView::PlatformView(const std::shared_ptr<Entities::Platform> &platform):
    platformKind(platform->getKind()) {
    // Linking observer
    observer = platform->observer;
    // Setting bonus kind
    if (platform->getBonus() == nullptr) bonusKind = BonusPower::NOTDEF;
    else (bonusKind = platform->getBonus()->getPowerKind());
}

void Views::PlatformView::loadTextures() {
    // Loading normal platform textures
    staticTex.loadFromFile(pathStatic);
    verticalTex.loadFromFile(pathVertical);
    horizontalTex.loadFromFile(pathHorizontal);
    tempTex.loadFromFile(pathTemp);
    // Loading spring platform textures
    staticSpringTex.loadFromFile(pathStaticSpring);
    verticalSpringTex.loadFromFile(pathVerticalSpring);
    horizontalSpringTex.loadFromFile(pathHorizontalSpring);
    tempSpringTex.loadFromFile(pathStaticSpring);
    // Loading rocket platform textures
    staticRocketTex.loadFromFile(pathStaticRocket);
    verticalRocketTex.loadFromFile(pathVerticalRocket);
    horizontalRocketTex.loadFromFile(pathHorizontalRocket);
    tempRocketTex.loadFromFile(pathTempRocket);
    texLoaded = true;
}

void Views::PlatformView::setup() {
    // Loading all the textures if possible
    if (texturesFound() and not texLoaded) {
        loadTextures();
    } else { std::cerr << "A texture in playerView was not able to be loaded!" << std::endl; }

    // Setting the texture
    if (bonusKind == BonusPower::NOTDEF) {
        if (platformKind == PKind::STATIC)
            view.setTexture(staticTex);
        else if (platformKind == PKind::HORIZONTAL)
            view.setTexture(horizontalTex);
        else if (platformKind == PKind::TEMP)
            view.setTexture(tempTex);
        else if (platformKind == PKind::VERTICAL)
            view.setTexture(verticalTex);
    }

    else if (bonusKind == BonusPower::SPRING) {
        if (platformKind == PKind::STATIC)
            view.setTexture(staticSpringTex);
        else if (platformKind == PKind::HORIZONTAL)
            view.setTexture(horizontalSpringTex);
        else if (platformKind == PKind::TEMP)
            view.setTexture(tempSpringTex);
        else if (platformKind == PKind::VERTICAL)
            view.setTexture(verticalSpringTex);
    }

    else if (bonusKind == BonusPower::ROCKET) {
        if (platformKind == PKind::STATIC)
            view.setTexture(staticRocketTex);
        else if (platformKind == PKind::HORIZONTAL)
            view.setTexture(horizontalRocketTex);
        else if (platformKind == PKind::TEMP)
            view.setTexture(tempRocketTex);
        else if (platformKind == PKind::VERTICAL)
            view.setTexture(verticalRocketTex);
    }
}

bool Views::PlatformView::texturesFound() {
    if (!Utils::pathExists(pathStatic)) return false;
    if (!Utils::pathExists(pathTemp)) return false;
    if (!Utils::pathExists(pathVertical)) return false;
    if (!Utils::pathExists(pathHorizontal)) return false;
    if (!Utils::pathExists(pathStaticSpring)) return false;
    if (!Utils::pathExists(pathTempSpring)) return false;
    if (!Utils::pathExists(pathVerticalSpring)) return false;
    if (!Utils::pathExists(pathHorizontalSpring)) return false;
    if (!Utils::pathExists(pathStaticRocket)) return false;
    if (!Utils::pathExists(pathTempRocket)) return false;
    if (!Utils::pathExists(pathVerticalRocket)) return false;
    if (!Utils::pathExists(pathHorizontalRocket)) return false;
    return true;
}
