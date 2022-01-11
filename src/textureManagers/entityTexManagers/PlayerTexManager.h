// // // // // // // // // // // // // //
//                                     //
//         PlayerTexManager.h          //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYERTEXMANAGER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYERTEXMANAGER_H

#include "../TextureManager.h"

class TextureManagers::PlayerTexManager: public TextureManager {
private:
    /// @brief Path to the normal doodle the Doodler texture
    std::string pathNormal = "recourses/textures/playerPictogram.png";
    /// @brief Path to the rocket texture for the player
    std::string pathRocket = "recourses/textures/bonuses/rsz_rocket1.png";
    /// @brief Texture for the normal doodle the Doodler texture
    sf::Texture normalTex{};
    /// @brief Texture for the rocket texture of the player
    sf::Texture rocketTex{};
    /**
     * @brief Default constructor
     */
    PlayerTexManager()=default;
public:
    /**
     * @brief Default destructor
     */
    ~PlayerTexManager() override =default;
    /**
     * @brief Will return an instance of this class - while respecting the singleton design pattern
     * @return  instance of playerTexManager
     */
    static PlayerTexManager & getInstance();
    /**
     * @brief Will load all the textures of the player
     */
    void loadTextures() override;
    /**
     * @brief Will search all the textures for the player
     * @return  foundAllTextures?
     */
    bool texturesFound() override;
    /**
     * @brief Will set a texture to the player
     * @param sprite        sprite, by reference so change is allowed
     * @param isRocket      is the player currenlty a rocket (other texture)
     */
    void setTexture(sf::Sprite& sprite, bool isRocket=false) const;
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYERTEXMANAGER_H
