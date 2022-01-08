//
// Created by Cédric Leclercq on 05/01/2022.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_TEXTUREMANAGERS_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_TEXTUREMANAGERS_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

/**
 * @brief Namespace for all the texture managers
 */
namespace TextureManagers {
    /**
     * @class TextureManagers::TextureManager
     * @brief Super class for all the other texture managers
     */
    class TextureManager;
    /**
     * @class TextureManagers::TextureManager
     * @public TextureManager
     * @brief Manager for all the textures of all the background tile views
     */
    class BGTileTexManager;
    /**
     * @class TextureManagers::TextureManagers
     * @public TextureManager
     * @brief Manager for all the textures of all the platform views
     */
    class PlatformTexManager;
    /**
     * @brief TextureManagers::TextureManagers
     * @public TextureManager
     * @brief Manager for the player view
     */
    class PlayerTexManager;
}

#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_TEXTUREMANAGERS_H
