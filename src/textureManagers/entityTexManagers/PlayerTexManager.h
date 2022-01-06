//
// Created by Cédric Leclercq on 05/01/2022.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYERTEXMANAGER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYERTEXMANAGER_H

#include "../TextureManager.h"

class TextureManagers::PlayerTexManager: public TextureManager {
private:
    std::string pathNormal = "recourses/textures/playerPictogram.png";
    std::string pathRocket = "recourses/textures/bonuses/rsz_rocket1.png";
    sf::Texture normalTex;
    sf::Texture rocketTex;
    PlayerTexManager()=default;
public:
    static PlayerTexManager & getInstance();
    void loadTextures() override;
    bool texturesFound() override;
    void setTexture(sf::Sprite& sprite, bool isRocket=false) const;
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYERTEXMANAGER_H
