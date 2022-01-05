//
// Created by Cédric Leclercq on 04/01/2022.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_PLATFORMVIEW_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_PLATFORMVIEW_H

#include "View.h"
#include "../observers/Observers.h"
#include "../observers/entityObservers/PlatformObserver.h"
#include "models/entities/Platform.h"

class Views::PlatformView: public View {
private:
    // Kind of platform
    PKind platformKind{};
    BonusPower bonusKind{};
    bool texLoaded = false;


    // Normal platforms - path
    /// Normal platform: static type - path
    std::string pathStatic = "recourses/textures/platforms/green_platform.png";
    /// Normal platform: horizontal type - path
    std::string pathHorizontal = "recourses/textures/platforms/light_blue_platform.png";
    /// Normal platform: vertical type - path
    std::string pathVertical = "recourses/textures/platforms/yellow_platform.png";
    /// Normal platform: temporary type - path
    std::string pathTemp = "recourses/textures/platforms/white_platform.png";

    // Spring platforms - path
    /// Spring platform: static type - path
    std::string pathStaticSpring = "recourses/textures/platforms/green_platform_spring1.png";
    /// Spring platform: horizontal type - path
    std::string pathHorizontalSpring = "recourses/textures/platforms/light_blue_platform_spring1.png";
    /// Spring platform: vertical type - path
    std::string pathVerticalSpring = "recourses/textures/platforms/yellow_platform_spring1.png";
    /// Spring platform: temporary type - path
    std::string pathTempSpring = "recourses/textures/platforms/white_platform_spring1.png";

    // Rocket platforms - path
    /// Rocket platform: static type - path
    std::string pathStaticRocket = "recourses/textures/platforms/green_platform_rocket.png";
    /// Rocket platform: horizontal type - path
    std::string pathHorizontalRocket = "recourses/textures/platforms/light_blue_platform_rocket.png";
    /// Rocket platform: vertical type - path
    std::string pathVerticalRocket = "recourses/textures/platforms/yellow_platform_rocket.png";
    /// Rocket platform: temporary type - path
    std::string pathTempRocket = "recourses/textures/platforms/white_platform_rocket.png";

    // Normal platforms - textures
    /// Normal platform: static type - texture
    sf::Texture staticTex;
    /// Normal platform: horizontal type - texture
    sf::Texture horizontalTex;
    /// Normal platform: vertical type - texture
    sf::Texture verticalTex;
    /// Normal platform: temporary type - texture
    sf::Texture tempTex;

    // Spring platforms - textures
    /// Spring platform: static type - texture
    sf::Texture staticSpringTex;
    /// Spring platform: horizontal type - texture
    sf::Texture horizontalSpringTex;
    /// Spring platform: vertical type - texture
    sf::Texture verticalSpringTex;
    /// Spring platform: temporary type - texture
    sf::Texture tempSpringTex;

    // Rocket platforms - textures
    /// Rocket platform: static type - texture
    sf::Texture staticRocketTex;
    /// Rocket platform: horizontal type - texture
    sf::Texture horizontalRocketTex;
    /// Rocket platform: vertical type - texture
    sf::Texture verticalRocketTex;
    /// Rocket platform: temporary type - texture
    sf::Texture tempRocketTex;

    void loadTextures() override;
    bool texturesFound() override;

public:
    std::shared_ptr<Observers::PlatformObserver> observer;
    PlatformView()=default;
    explicit PlatformView(const std::shared_ptr<Entities::Platform>& platform);
    void setup() override;
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_PLATFORMVIEW_H
