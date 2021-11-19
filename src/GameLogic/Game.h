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
    float mSpriteScaleX;
    float mSpriteScaleY;


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
    Game() : mWindow(sf::VideoMode(800, 1500), "My window"){
        sf::Texture texture;
        texture.loadFromFile("recourses/playerPictogram.png");
        mSprite.setTexture(texture);
        //mSprite.setTextureRect(sf::IntRect(10, 10, 50, 30));
        mSprite.setPosition(400,1000);
        mWindow.draw(mSprite);
        mSpriteScaleX = mSprite.getPosition().x;
        mSpriteScaleY = mSprite.getPosition().y;
        //this->setup();
        this->start();
    };




    /**
     * Start game
     */
    void start();

    void jumpCharacter();




};


#endif //DOODLEJUMP_GAME_H
