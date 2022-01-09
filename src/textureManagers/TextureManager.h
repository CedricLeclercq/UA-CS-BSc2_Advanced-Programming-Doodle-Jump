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
    /**
     * @brief Default constructor
     */
    TextureManager()=default;
    /**
     * @brief Default destructor
     */
    virtual ~TextureManager()=default;
    /**
     * @brief Pure virtual function to load all the textures
     */
    virtual void loadTextures() = 0;
    /**
     * @brief Pure virtual function to check if textures are found
     * @return  foundAllTextures?
     */
    virtual bool texturesFound() = 0;
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_TEXTUREMANAGER_H
