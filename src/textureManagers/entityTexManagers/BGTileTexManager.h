// // // // // // // // // // // // // //
//                                     //
//         BGTileTexManager.h          //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_BGTILETEXMANAGER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_BGTILETEXMANAGER_H

#include "../TextureManager.h"
#include "../../models/entities/BGTile.h"

class TextureManagers::BGTileTexManager: public TextureManager {
private:
    // All textures
    /// @brief Planet 1 - texture
    sf::Texture planet1Tex{};
    /// @brief Planet 2 - texture
    sf::Texture planet2Tex{};
    /// @brief Planet 3 - texture
    sf::Texture planet3Tex{};
    /// @brief Planet 4 - texture
    sf::Texture planet4Tex{};
    /// @brief Planet 5 - texture
    sf::Texture planet5Tex{};
    /// @brief Planet 6 - texture
    sf::Texture planet6Tex{};
    /// @brief Milky way 1 - texture
    sf::Texture mw1Tex{};
    /// @brief Milky way 2 - texture
    sf::Texture mw2Tex{};
    /// @brief Star 1 - texture
    sf::Texture star1Tex{};
    /// @brief Star 2 - texture
    sf::Texture star2Tex{};

    // All paths to textures
    /// @brief Planet 1 - path
    std::string pathPlanet1 = "recourses/textures/background/planets/Planet1.png";
    /// @brief Planet 2 - path
    std::string pathPlanet2 = "recourses/textures/background/planets/Planet2.png";
    /// @brief Planet 3 - path
    std::string pathPlanet3 = "recourses/textures/background/planets/Planet3.png";
    /// @brief Planet 4 - path
    std::string pathPlanet4 = "recourses/textures/background/planets/Planet4.png";
    /// @brief Planet 5 - path
    std::string pathPlanet5 = "recourses/textures/background/planets/Planet5.png";
    /// @brief Planet 6 - path
    std::string pathPlanet6 = "recourses/textures/background/planets/Planet6.png";
    /// @brief Milky way 1 - path
    std::string pathMw1 = "recourses/textures/background/milkyways/MilkyWay1.png";
    /// @brief Milky way 2 - path
    std::string pathMw2 = "recourses/textures/background/milkyways/MilkyWay2.png";
    /// @brief Star 1 - path
    std::string pathStar1 = "recourses/textures/background/stars/Star1.png";
    /// @brief Star 2 - path
    std::string pathStar2 = "recourses/textures/background/stars/Star2.png";
    /**
     * @brief Default constructor (but private because of the singleton design pattern)
     */
    BGTileTexManager()=default;
public:
    /**
     * @brief Default destructor
     */
    ~BGTileTexManager() override =default;
    /**
     * @brief Will return an instance of the class regarding the singleton design pattern
     * @return  instance of BGTileTexManager
     */
    static BGTileTexManager& getInstance();
    /**
     * @brief Will load the textures for the background tiles
     */
    void loadTextures() override;
    /**
     * @brief Will define if all the texture for the background tiles can be found
     * @return      allTexturesFound?
     */
    bool texturesFound() override;
    /**
     * @brief Will set a texture to a background tile sprite
     * @param sprite    sprite by reference - to give change
     * @param kind      kind of background tile
     */
    void setTexture(sf::Sprite& sprite, TKind kind) const;
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_BGTILETEXMANAGER_H
