// // // // // // // // // // // // // //
//                                     //
//               Game.h                //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#ifndef DOODLEJUMP_GAME_H
#define DOODLEJUMP_GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>
#include "../gameLogic/World.h"
#include "../gameLogic/Camera.h"
#include "../views/PlatformView.h"
#include "../views/PlayerView.h"
#include "../views/BGTileView.h"
#include "../controllers/WorldController.h"


/**
 * @class Game
 * @brief Will manage the graphical side of the game
 */
class Game {
public:
    /**
     * @brief Main function, will start the game and keep thee game running
     */
    void start();
    /**
     * @brief Basic constructor that will create a window with standard dimensions, and start the game
     */
    Game();
    /**
     * @brief Default destructor
     */
    ~Game()=default;
private:
    // Views
    /// @brief View for the player
    std::shared_ptr<Views::PlayerView> playerView{};
    /// @brief Views for all the platforms
    std::vector<std::shared_ptr<Views::PlatformView>> platformsViews{};
    /// @brief Views for all the background tiles
    std::vector<std::shared_ptr<Views::BGTileView>> tilesViews{};

    // Main controller - to communicate with the world
    /// @brief Controller for the world
    WorldController controller{};

    // Member variables (minus the controllers)
    /// @brief Window where everything will be drawn on
    std::unique_ptr<sf::RenderWindow> mWindow{};
    /// @brief Camera used for the projection of elements
    std::shared_ptr<Camera> mCamera{};

    // Fonts and texts
    /// @brief Text for the score
    sf::Text scoreText{};
    /// @brief Font for the score and endscreen to be displayed in
    sf::Font scoreFont{};

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
     * @brief Will open the sfml window
     */
    void openSFWindow();
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
     * @brief Will open the "game over" or "end" screen and keep it open
     * @return      (window.closed?) Will return true when the user asked to close the "end"window
     */
    bool openEndSFScreen();
    /**
     * @brief Will remove all the platform views that are no longer needed
     */
    void removePlatformViews();
    /**
     * @brief Will remove all the background tile views that are no longer needed
     */
    void removeTileViews();
    /**
     * @brief Will create new views if new models where created
     */
    void createNewViews();
};


#endif //DOODLEJUMP_GAME_H
