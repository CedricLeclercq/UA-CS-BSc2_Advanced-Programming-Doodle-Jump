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
    // Controllers
    /// @brief Player controller
    Controllers::PlayerController playerController;
    /// @brief Vector with all the current platform controllers
    std::vector<Controllers::PlatformsController> platformsControllers;
    /// @brief Vector with all the current background tiles controllers
    std::vector<Controllers::BGTileController> bgTileControllers;

    // Member variables (minus the controllers)
    /// @brief Window where everything will be drawn on
    std::unique_ptr<sf::RenderWindow> mWindow;
    /// @brief  World where all the game logic happens
    std::shared_ptr<World> mWorld;
    /// @brief Camera used for the projection of elements
    std::shared_ptr<Camera> mCamera;
    /// @brief Singleton stopwatch for fps counting
    std::unique_ptr<Stopwatch> mStopwatch;

    // Textures
    /// @brief Main player sprite texture
    sf::Texture mSpriteTex;
    /// @brief Static platform texture
    sf::Texture mStaticPlatformTex;
    /// @brief Horizontal platform texture
    sf::Texture mHorizontalPlatformTex;
    /// @brief Vertical platform texture
    sf::Texture mVerticalPlatformTex;
    /// @brief Temporary platform texture
    sf::Texture mTempPlatformTex;
    /// @brief Static spring platform texture
    sf::Texture mStaticSpringPlatformTex;
    /// @brief Horizontal spring platform texture
    sf::Texture mHorizontalSpringPlatformTex;
    /// @brief Vertical spring platform texture
    sf::Texture mVerticalSpringPlatformTex;
    /// @brief Temporary spring platform texture;
    sf::Texture mTempSpringPlatformTex;
    /// @brief Static rocket platform texture
    sf::Texture mStaticRocketPlatformTex;
    /// @brief Horizontal rocket platform texture
    sf::Texture mHorizontalRocketPlatformTex;
    /// @brief Vertical rocket platform texture
    sf::Texture mVerticalRocketPlatformTex;
    /// @brief Temporary rocket platform texture
    sf::Texture mTempRocketPlatformTex;

    // Background textures
    /// @brief Background of the game texture
    sf::Texture mBackgroundTex;
    /// @brief Background of the game background element: Planet 1
    sf::Texture mPlanet1Tex;
    /// @brief Background of the game background element: Planet 2
    sf::Texture mPlanet2Tex;
    /// @brief Background of the game background element: Planet 3
    sf::Texture mPlanet3Tex;
    /// @brief Background of the game background element: Planet 4
    sf::Texture mPlanet4Tex;
    /// @brief Background of the game background element: Planet 5
    sf::Texture mPlanet5Tex;
    /// @brief Background of the game background element: Planet 6
    sf::Texture mPlanet6Tex;
    /// @brief Background of the game background element: Star 1
    sf::Texture mStar1Tex;
    /// @brief Background of the game background element: Star 2
    sf::Texture mStar2Tex;
    /// @brief Background of the game background element: Milky way 1
    sf::Texture mMilkyWay1Tex;
    /// @brief Background of the game background element: Milky way 2
    sf::Texture mMilkyWay2Tex;
    /// @brief Background of the game background element: Ground
    sf::Texture mGroundTex;
    /// @brief Texture for the rocket bonus
    sf::Texture mRocketBonusTex;

    // Fonts and texts
    /// @brief Text for the score
    sf::Text scoreText;
    /// @brief Font for the score and endscreen to be displayed in
    sf::Font scoreFont;

    // Functions
    /**
     * @brief Will be ran at the beginning of the game and initialise all the elements
     */
    void initialiseGame();
    /**
     * @brief After every loop, this function will setup everything for a new display
     */
    void setup();
    /**
     * @brief Get input from the user to move the character
     */
    void getInput();
    /**
     * @brief Finds and sets the texture for a given platform
     * @param platform      Shared pointer to the platform in the world
     * @param sfPlatform    Sprite reference that is the platform (and will also get the texture)
     */
    void setPlatformTexture(const std::shared_ptr<Entities::Platform>& platform, sf::Sprite& sfPlatform);
    /**
     * @brief Finds and sets the texture for a given background tile
     * @param tile          Shared pointer to the background tile in the world
     * @param sfTile        Sprite reference that is the background tile (and will also get the texture)
     */
    void setTileTexture(const std::shared_ptr<Entities::BGTile>& tile, sf::Sprite& sfTile);
    /**
     * @brief Creates the world when there isn't one yet - is only ran at the beginning of the game
     */
    void createWorld();
    /**
     * @brief Initiates the textures of everything - is only ran at the beginning of the game
     */
    void initiateTextures();
    /**
     * @brief Will create a controller for the player - is only ran when a new player is created
     */
    void createPlayerController();
    /**
     * @brief Will create a controller for the new platforms - is only ran when a new platform is created
     */
    void createPlatformsControllers();
    /**
     * @brief Will create a new controller for the new background tiles - is only ran when a new tile is created
     */
    void createBGTileControllers();
    /**
     * @brief Will scale all the sprites so that everything is sized accordingly
     */
    void scaleElements();
    /**
     * @brief Will place the player in the window
     */
    void placePlayer();
    /**
     * @brief Will place all the platforms in the window
     */
    void placePlatforms();
    /**
     * @brief Will place all the background tiles in the window
     */
    void placeBackground();
    /**
     * @brief Will draw an fps counter with a build in sfml library
     *
     * @note Currently does not work because of performance issues - will be fixed
     */
    __attribute__((unused)) static void addFPSCounter();
    /**
     * @brief Will open the sfml window
     */
    void openSFWindow();
    /**
     * @brief Will ask the world to update everything in it
     */
    void updateWorld();
    /**
     * @brief Will define the lengths of a player and a platform (for the worlds collision check)
     */
    void defineLengths();
    /**
     * @brief Will add a score in the left hand corner of the screen
     */
    void addScore();
    /**
     * @brief Will draw the "end" or "game over" screen is the player has died - will stop when enter is pressed
     */
    void drawEndScreen();
    /**
     * @brief Will ask the world on feedback if the player has died (so game over!)
     */
    void evaluateEndGame();
    /**
     * @brief Will handle certain graphical changes if the player jumps
     */
    void jumpingGraphics();
    /**
     * @brief Will open the "game over" or "end" screen and keep it open
     * @return      (window.closed?) Will return true when the user asked to close the "end"window
     */
    bool openEndSFScreen();

public:
    /**
     * @brief Main function, will start the game and keep thee game running
     */
    void start();
    /**
     * @brief Basic constructor that will create a window with standard dimensions, and start the game
     */
    Game() : mWindow(new sf::RenderWindow(sf::VideoMode(800, 1200), "Doodle jump - Advanced programming")) {
        this->initialiseGame();
        this->setup();
        this->start();
    };
};


#endif //DOODLEJUMP_GAME_H
