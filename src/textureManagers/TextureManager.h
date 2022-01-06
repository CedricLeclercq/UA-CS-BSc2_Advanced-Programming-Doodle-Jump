//
// Created by Cédric Leclercq on 05/01/2022.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_TEXTUREMANAGER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_TEXTUREMANAGER_H

#include "TextureManagers.h"
#include "../utilities/Utilities.h"

using Utils = Utilities::Utils;

class TextureManagers::TextureManager {
public:
    TextureManager()=default;
    virtual void loadTextures() = 0;
    virtual bool texturesFound() = 0;
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_TEXTUREMANAGER_H
