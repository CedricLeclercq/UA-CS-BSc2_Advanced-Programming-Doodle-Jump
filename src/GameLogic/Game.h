//
// Created by Cédric Leclercq on 18/11/2021.
//

#ifndef DOODLEJUMP_GAME_H
#define DOODLEJUMP_GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class Game {
private:
    // Member variables
    sf::RenderWindow mWindow;
    sf::Sprite mSprite;
    sf::Texture mSpriteTex;
    bool mLookLeft;

    float velocityY;
    float accelerationY;




    // Setup
    /**
     * When the game is started for the first time, setup is ran for placing all elements is the world
     */
    void setup();

    void moveCharacter();

public:

    /**
     * Basic constructor
     */
    Game() : mWindow(sf::VideoMode(800, 1500), "Doodle jump - Alpha v0.0"){
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
