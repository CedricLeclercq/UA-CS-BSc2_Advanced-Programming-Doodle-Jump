//
// Created by Cédric Leclercq on 04/01/2022.
//

#include "BGTileView.h"

using Utils = Utilities::Utils;

void Views::BGTileView::loadTextures() {
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
    texLoaded = true;
}

void Views::BGTileView::setup() {
   if (texturesFound() and not texLoaded) {
       loadTextures();
   } else { std::cerr << "A texture in BGTileView was not able to be loaded!" << std::endl; }

    if (tileKind == TKind::MILKYWAY1) {
        view.setTexture(mw1Tex);
        view.setScale(1.2,1.2);
    }
    else if (tileKind == TKind::MILKYWAY2) {
        view.setTexture(mw2Tex);
        view.setScale(1.2,1.2);
    }
    else if (tileKind == TKind::STAR1) {
        view.setTexture(star1Tex);
        view.setScale(0.2,0.2);
    }
    else if (tileKind == TKind::STAR2) {
        view.setTexture(star2Tex);
    }
    else if (tileKind == TKind::PLANET1) {
        view.setTexture(planet1Tex);
    }
    else if (tileKind == TKind::PLANET2) {
        view.setTexture(planet2Tex);
    }
    else if (tileKind == TKind::PLANET3) {
        view.setTexture(planet3Tex);
    }
    else if (tileKind == TKind::PLANET4) {
        view.setTexture(planet4Tex);
    }
    else if (tileKind == TKind::PLANET5) {
        view.setTexture(planet5Tex);
    }
    else if (tileKind == TKind::PLANET6) {
        view.setTexture(planet6Tex);
    }
}

bool Views::BGTileView::texturesFound() {
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

Views::BGTileView::BGTileView(const std::shared_ptr<Entities::BGTile> &tile) {
    observer = tile->observer;
    tileKind = tile->getKind();
}
