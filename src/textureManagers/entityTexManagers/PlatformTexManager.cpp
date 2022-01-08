// // // // // // // // // // // // // //
//                                     //
//       PlatformTexManager.cpp        //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#include "PlatformTexManager.h"

void TextureManagers::PlatformTexManager::loadTextures() {
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
}

void TextureManagers::PlatformTexManager::setTexture(sf::Sprite &sprite, PKind pKind, BonusPower bKind) const {
    // Setting the texture
    if (bKind == BonusPower::NOTDEF) {
        if (pKind == PKind::STATIC)
            sprite.setTexture(staticTex);
        else if (pKind == PKind::HORIZONTAL)
            sprite.setTexture(horizontalTex);
        else if (pKind == PKind::TEMP)
            sprite.setTexture(tempTex);
        else if (pKind == PKind::VERTICAL)
            sprite.setTexture(verticalTex);
    }

    else if (bKind == BonusPower::SPRING) {
        if (pKind == PKind::STATIC)
            sprite.setTexture(staticSpringTex);
        else if (pKind == PKind::HORIZONTAL)
            sprite.setTexture(horizontalSpringTex);
        else if (pKind == PKind::TEMP)
            sprite.setTexture(tempSpringTex);
        else if (pKind == PKind::VERTICAL)
            sprite.setTexture(verticalSpringTex);
    }

    else if (bKind == BonusPower::ROCKET) {
        if (pKind == PKind::STATIC)
            sprite.setTexture(staticRocketTex);
        else if (pKind == PKind::HORIZONTAL)
            sprite.setTexture(horizontalRocketTex);
        else if (pKind == PKind::TEMP)
            sprite.setTexture(tempRocketTex);
        else if (pKind == PKind::VERTICAL)
            sprite.setTexture(verticalRocketTex);
    }
}

bool TextureManagers::PlatformTexManager::texturesFound() {
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

TextureManagers::PlatformTexManager &TextureManagers::PlatformTexManager::getInstance() {
    static PlatformTexManager instance;
    return instance;
}
