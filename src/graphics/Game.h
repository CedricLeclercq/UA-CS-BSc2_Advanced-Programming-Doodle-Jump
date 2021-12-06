//
// Created by Cédric Leclercq on 18/11/2021.
//

#ifndef DOODLEJUMP_GAME_H
#define DOODLEJUMP_GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>
#include "../gameLogic/World.h"


class Game {
private:
    // Elements
    /// Window where everything will be drawn on
    std::unique_ptr<sf::RenderWindow> mWindow;
    /// World where all the game logic happens
    std::unique_ptr<World> mWorld;
    /// Main player sprite
    sf::Sprite mSprite;
    /// Vector with all the platforms
    std::vector<std::pair<std::shared_ptr<Platform>,sf::Sprite>> platforms;
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
    /// Background of the game texture
    sf::Texture mBackgroundTex;

    // Functions
    /**
     * Setup the game after one cycle
     */
    void setup();
    /**
     * At the beginning of the game, set all the elements
     */
    void initialiseGame();
    /**
     * Get input from the user to move the charachter
     */
    void getInput();
    /**
     * Set all the textures for all entities
     */
    void setTextures();

public:

    /**
     * Basic constructor
     */
    Game() : mWindow(new sf::RenderWindow(sf::VideoMode(800, 1500), "Doodle jump - Alpha")) {
        this->initialiseGame();
        this->setup();
        this->start();
    };
    /**
     * Start game
     */
    void start();

    void jumpCharacter();




};


#endif //DOODLEJUMP_GAME_H
