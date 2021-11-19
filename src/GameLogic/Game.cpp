//
// Created by Cédric Leclercq on 18/11/2021.
//

#include "Game.h"
#include <SFML/Graphics/Texture.hpp>
#include <iostream>

void Game::setup() {
    sf::Texture texture;
    texture.loadFromFile("recourses/playerPictogram.png");
    mSprite.setTexture(texture);
    //mSprite.setTextureRect(sf::IntRect(10, 10, 50, 30));
    mSprite.setPosition(50,50);
    mSprite.setScale(mSprite.getScale().x * (float)0.01,mSprite.getScale().y * (float)0.01);
    mWindow.draw(mSprite);
}

void Game::start() {
    sf::Clock clock;

    while (mWindow.isOpen()) {
        // Code about the character
        this->moveCharacter();
        this->jumpCharacter();
        mWindow.draw(mSprite);

        // FPS print TODO turn on fps count
        //std::cout << 1.f /  clock.restart().asSeconds() << std::endl;

        // Drawing the game
        sf::Event event{};
        while (mWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                mWindow.close();
        }
        mWindow.display();
        mWindow.clear();
    }
}

void Game::moveCharacter() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) or sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        mSprite.move(0.f,-1.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) or sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        mSprite.move(0.f,1.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) or sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        mSprite.move(1.f,0.f);
        //mSprite.scale(-1.f,1.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) or sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        mSprite.move(-1.f,0.f);
       // mSprite.scale(1.f,-1.f);

    }
}

void Game::jumpCharacter() {
    if ((int)this->mSprite.getPosition().y == 1000) { // When we can jump
        // TODO jump
    }
}
