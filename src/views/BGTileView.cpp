//
// Created by Cédric Leclercq on 04/01/2022.
//

#include "BGTileView.h"
#include "../textureManagers/entityTexManagers/BGTileTexManager.h"

using Utils = Utilities::Utils;


void Views::BGTileView::setup() {
   if (TextureManagers::BGTileTexManager::getInstance().texturesFound() and not texLoaded) {
       TextureManagers::BGTileTexManager::getInstance().loadTextures();
       texLoaded = true;
   } else { std::cerr << "A texture in BGTileView was not able to be loaded!" << std::endl; }
   // Setting the texture based on the tile kind
   TextureManagers::BGTileTexManager::getInstance().setTexture(view,tileKind);
}

Views::BGTileView::BGTileView(const std::shared_ptr<Entities::BGTile> &tile) {
    observer = tile->observer;
    tileKind = tile->getKind();
}
