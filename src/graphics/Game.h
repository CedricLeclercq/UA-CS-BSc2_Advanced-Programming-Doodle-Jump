//
// Created by Cédric Leclercq on 18/11/2021.
//

#ifndef DOODLEJUMP_GAME_H
#define DOODLEJUMP_GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>
#include "../gameLogic/World.h"
#include "../gameLogic/Camera.h"
#include "../controllers/Controllers.h"
#include "../controllers/entityControllers/PlayerController.h"
#include "../controllers/entityControllers/PlatformsController.h"
#include "../controllers/entityControllers/BGTileController.h"
#include "../utilities/Stopwatch.h"


class Game {
private:
    // New elements
    Controllers::PlayerController playerController;
    std::vector<Controllers::PlatformsController> platformsControllers;
    std::vector<Controllers::BGTileController> bgTileControllers;
    // Elements
    /// Window where everything will be drawn on
    std::unique_ptr<sf::RenderWindow> mWindow;
    /// World where all the game logic happens
    std::shared_ptr<World> mWorld;
    /// Camera used for the projection of elements
    std::shared_ptr<Camera> mCamera;
    /// Singleton stopwatch for fps counting
    std::unique_ptr<Stopwatch> mStopwatch;
    /// Background for the game
    sf::Sprite mBackground;

    // Textures
    /// Main player sprite texture
    sf::Texture mSpriteTex;
    /// Static platform texture
    sf::Texture mStaticPlatformTex;
    /// Horizontal platform texture
    sf::Texture mHorizontalPlatformTex;
    /// Vertical platform texture
    sf::Texture mVerticalPlatformTex;
    /// Temporary platform texture
    sf::Texture mTempPlatformTex;
    /// Static spring platform texture
    sf::Texture mStaticSpringPlatformTex;
    /// Horizontal spring platform texture
    sf::Texture mHorizontalSpringPlatformTex;
    /// Vertical spring platform texture
    sf::Texture mVerticalSpringPlatformTex;
    /// Temporary spring platform texture;
    sf::Texture mTempSpringPlatformTex;
    /// Static rocket platform texture
    sf::Texture mStaticRocketPlatformTex;
    /// Horizontal rocket platform texture
    sf::Texture mHorizontalRocketPlatformTex;
    /// Vertical rocket platform texture
    sf::Texture mVerticalRocketPlatformTex;
    /// Temporary rocket platform texture
    sf::Texture mTempRocketPlatformTex;


    /// Background of the game texture
    sf::Texture mBackgroundTex;
    /// Background of the game background element: Planet 1
    sf::Texture mPlanet1Tex;
    /// Background of the game background element: Planet 2
    sf::Texture mPlanet2Tex;
    /// Background of the game background element: Planet 3
    sf::Texture mPlanet3Tex;
    /// Background of the game background element: Planet 4
    sf::Texture mPlanet4Tex;
    /// Background of the game background element: Planet 5
    sf::Texture mPlanet5Tex;
    /// Background of the game background element: Planet 6
    sf::Texture mPlanet6Tex;
    /// Background of the game background element: Star 1
    sf::Texture mStar1Tex;
    /// Background of the game background element: Star 2
    sf::Texture mStar2Tex;
    /// Background of the game background element: Milky way 1
    sf::Texture mMilkyWay1Tex;
    /// Background of the game background element: Milky way 2
    sf::Texture mMilkyWay2Tex;
    /// Background of the game background element: Ground
    sf::Texture mGroundTex;
    /// Texture for the rocket bonus
    sf::Texture mRocketBonusTex;
    /// Will display the score
    sf::Text scoreText;
    /// Font for the score to be displayed in
    sf::Font scoreFont;



    // Functions
public:
    /**
     * Main function, will start the game and initiate everything
     */
    void start();
private:
    /**
     * At the very beginning of the game, right after starting, this
     */
    void initialiseGame();
    /**
     * This function is used every refresh of the game. It will check for changes in the world and make
     * those changes in the view as well
     */
    void setup();
    /**
     * Get input from the user to move the charachter
     */
    void getInput();
    // TODO fix documentation below
    /**
     * Finds and sets the texture for a given platform
     */
    void setPlatformTexture(const std::shared_ptr<Entities::Platform>& platform, sf::Sprite& sfPlatform);
    /**
     * Finds and sets the texture for a given background tile
     * @param tile
     * @param sfTile
     */
    void setTileTexture(const std::shared_ptr<Entities::BGTile>& tile, sf::Sprite& sfTile);
    /**
     * Creates the world
     */
    void createWorld();
    /**
     * Initiates the textures of everything
     */
    void initiateTextures();

    void createPlayerController();

    void scaleElements();

    void placePlayer();

    void placePlatforms();

    void placeBackground();

    void addFPSCounter();

    void openSFWindow();

    void updateWorld();

    void defineLengths();

    void createPlatformsControllers();

    void createBGTileControllers();

    void addScore();

    void drawEndScreen();

    void evaluateEndGame();

    void evaluateAndEditHighScores();

    void updateHighScore();


public:

    /**
     * Basic constructor
     */
    Game() : mWindow(new sf::RenderWindow(sf::VideoMode(800, 1200), "Doodle jump - Alpha")) {
        this->initialiseGame();
        this->setup();
        this->start();
    };

    void jumpingGraphics();

    bool openEndSFScreen();




};


#endif //DOODLEJUMP_GAME_H
