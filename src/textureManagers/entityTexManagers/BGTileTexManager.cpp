// // // // // // // // // // // // // //
//                                     //
//        BGTileTexManager.cpp         //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#include "BGTileTexManager.h"

void TextureManagers::BGTileTexManager::loadTextures() {
    // Loading planet textures
    planet1Tex.loadFromFile(pathPlanet1);
    planet2Tex.loadFromFile(pathPlanet2);
    planet3Tex.loadFromFile(pathPlanet3);
    planet4Tex.loadFromFile(pathPlanet4);
    planet5Tex.loadFromFile(pathPlanet5);
    planet6Tex.loadFromFile(pathPlanet6);
    // Loading milky way textures
    mw1Tex.loadFromFile(pathMw1);
    mw2Tex.loadFromFile(pathMw2);
    // Loading star textures
    star1Tex.loadFromFile(pathStar1);
    star2Tex.loadFromFile(pathStar2);
}

void TextureManagers::BGTileTexManager::setTexture(sf::Sprite &sprite, TKind kind) const {
    if (kind == TKind::MILKYWAY1) {
        sprite.setTexture(mw1Tex);
        sprite.setScale(1.2,1.2);
    }
    else if (kind == TKind::MILKYWAY2) {
        sprite.setTexture(mw2Tex);
        sprite.setScale(1.2,1.2);
    }
    else if (kind == TKind::STAR1) {
        sprite.setTexture(star1Tex);
        sprite.setScale(0.2,0.2);
    }
    else if (kind == TKind::STAR2) {
        sprite.setTexture(star2Tex);
    }
    else if (kind == TKind::PLANET1) {
        sprite.setTexture(planet1Tex);
    }
    else if (kind == TKind::PLANET2) {
        sprite.setTexture(planet2Tex);
    }
    else if (kind == TKind::PLANET3) {
        sprite.setTexture(planet3Tex);
    }
    else if (kind == TKind::PLANET4) {
        sprite.setTexture(planet4Tex);
    }
    else if (kind == TKind::PLANET5) {
        sprite.setTexture(planet5Tex);
    }
    else if (kind == TKind::PLANET6) {
        sprite.setTexture(planet6Tex);
    }
}

bool TextureManagers::BGTileTexManager::texturesFound() {
    if(!Utils::pathExists(pathMw1)) return false;
    if(!Utils::pathExists(pathMw2)) return false;
    if(!Utils::pathExists(pathPlanet1)) return false;
    if(!Utils::pathExists(pathPlanet2)) return false;
    if(!Utils::pathExists(pathPlanet3)) return false;
    if(!Utils::pathExists(pathPlanet4)) return false;
    if(!Utils::pathExists(pathPlanet5)) return false;
    if(!Utils::pathExists(pathPlanet6)) return false;
    if(!Utils::pathExists(pathStar1)) return false;
    if(!Utils::pathExists(pathStar2)) return false;
    return true;
}

TextureManagers::BGTileTexManager &TextureManagers::BGTileTexManager::getInstance() {
    static BGTileTexManager instance;
    return instance;
}
