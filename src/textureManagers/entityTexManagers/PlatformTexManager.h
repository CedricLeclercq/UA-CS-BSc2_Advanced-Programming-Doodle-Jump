// // // // // // // // // // // // // //
//                                     //
//        PlatformTexManager.h         //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_PLATFORMTEXMANAGER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_PLATFORMTEXMANAGER_H

#include "../TextureManager.h"
#include "../../models/entities/Platform.h"

class TextureManagers::PlatformTexManager: public TextureManager {
private:
    // Normal platforms - path
    /// @brief Normal platform: static type - path
    std::string pathStatic = "recourses/textures/platforms/green_platform.png";
    /// @brief Normal platform: horizontal type - path
    std::string pathHorizontal = "recourses/textures/platforms/light_blue_platform.png";
    /// @brief Normal platform: vertical type - path
    std::string pathVertical = "recourses/textures/platforms/yellow_platform.png";
    /// @brief Normal platform: temporary type - path
    std::string pathTemp = "recourses/textures/platforms/white_platform.png";

    // Spring platforms - path
    /// @brief Spring platform: static type - path
    std::string pathStaticSpring = "recourses/textures/platforms/green_platform_spring1.png";
    /// @brief Spring platform: horizontal type - path
    std::string pathHorizontalSpring = "recourses/textures/platforms/light_blue_platform_spring1.png";
    /// @brief Spring platform: vertical type - path
    std::string pathVerticalSpring = "recourses/textures/platforms/yellow_platform_spring1.png";
    /// @brief Spring platform: temporary type - path
    std::string pathTempSpring = "recourses/textures/platforms/white_platform_spring1.png";

    // Rocket platforms - path
    /// @brief Rocket platform: static type - path
    std::string pathStaticRocket = "recourses/textures/platforms/green_platform_rocket.png";
    /// @brief Rocket platform: horizontal type - path
    std::string pathHorizontalRocket = "recourses/textures/platforms/light_blue_platform_rocket.png";
    /// @brief Rocket platform: vertical type - path
    std::string pathVerticalRocket = "recourses/textures/platforms/yellow_platform_rocket.png";
    /// @brief Rocket platform: temporary type - path
    std::string pathTempRocket = "recourses/textures/platforms/white_platform_rocket.png";

    // Normal platforms - textures
    /// @brief Normal platform: static type - texture
    sf::Texture staticTex{};
    /// @brief Normal platform: horizontal type - texture
    sf::Texture horizontalTex{};
    /// @brief Normal platform: vertical type - texture
    sf::Texture verticalTex{};
    /// @brief Normal platform: temporary type - texture
    sf::Texture tempTex{};

    // Spring platforms - textures
    /// @brief Spring platform: static type - texture
    sf::Texture staticSpringTex{};
    /// @brief Spring platform: horizontal type - texture
    sf::Texture horizontalSpringTex{};
    /// @brief Spring platform: vertical type - texture
    sf::Texture verticalSpringTex{};
    /// @brief Spring platform: temporary type - texture
    sf::Texture tempSpringTex{};

    // Rocket platforms - textures
    /// @brief Rocket platform: static type - texture
    sf::Texture staticRocketTex{};
    /// @brief Rocket platform: horizontal type - texture
    sf::Texture horizontalRocketTex{};
    /// @brief Rocket platform: vertical type - texture
    sf::Texture verticalRocketTex{};
    /// @brief Rocket platform: temporary type - texture
    sf::Texture tempRocketTex{};
    /**
     * @brief Default constructor (private because of singleton)
     */
    PlatformTexManager()=default;
public:
    /**
     * @brief Default destructor
     */
    ~PlatformTexManager() override =default;
    /**
     * @brief Will return an instance of the class regarding the singleton design pattern
     * @return      instance of PlatformTexManager
     */
    static PlatformTexManager& getInstance();
    /**
     * @brief Will load all the textures for the platforms
     */
    void loadTextures() override;
    /**
     * @brief Will define if all the textures are found for the platform
     * @return      allTexturesFound?
     */
    bool texturesFound() override;
    /**
     * @brief Will set a texture to a sprite platform
     * @param sprite    sprite by reference - for changes
     * @param pKind     platform kind       - needed for defining which texture
     * @param bKind     bonus kind          - needed for defining which texture
     */
    void setTexture(sf::Sprite& sprite, PKind pKind, BonusPower bKind) const;
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_PLATFORMTEXMANAGER_H
