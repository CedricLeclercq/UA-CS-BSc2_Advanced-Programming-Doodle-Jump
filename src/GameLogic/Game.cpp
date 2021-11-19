//
// Created by Cédric Leclercq on 18/11/2021.
//

#include "Game.h"
#include <SFML/Graphics/Texture.hpp>
#include <iostream>

void Game::setup() {
    mSpriteTex.loadFromFile("recourses/playerPictogram.png");
    mSprite.setTexture(mSpriteTex);
    //mSprite.setTextureRect(sf::IntRect(10, 10, 50, 30));
    mSprite.setPosition(400,1000);
    mSprite.setScale(mSprite.getScale().x * (float)0.1,mSprite.getScale().y * (float)0.1);
    this->mLookLeft = false;
    mWindow.draw(mSprite);
}

void Game::start() {
    sf::Clock clock;

    while (mWindow.isOpen()) {
        // Code about the character
        this->moveCharacter();
        mWindow.draw(mSprite);

        // FPS print
        std::cout << 1.f /  clock.restart().asSeconds()  << std::endl;

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
    this->jumpCharacter();
    if (this->mLookLeft) {
        // Mirroring the character if it is looking left
        this->mSprite.setScale(-1, 1);
    } else {
        // But reverse if it is not looking left
        this->mSprite.setScale(1,1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) or sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        this->mSprite.move(0.f,-0.5);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) or sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        this->mSprite.move(0.f,0.5);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) or sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        this->mSprite.move(0.5,0.f);
        if (this->mLookLeft) {
            this->mSprite.move(-80,0.f);
        }
        this->mLookLeft = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) or sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        mSprite.move(-0.5,0.f);
        if (not this->mLookLeft) {
            this->mSprite.move(80, 0.f);
        }
        this->mLookLeft = true;
    }
}

void Game::jumpCharacter() {
    // TODO change if statement below to <WHEN COLLISION OCCURS>
    if ((int)this->mSprite.getPosition().y >= 1000) { // When we can jump
        this->velocityY = 1;
    } else {
        // Above the ground
        this->velocityY -= 0.002; // Add gravity

        //this->velocityY += this->accelerationY;
        this->mSprite.move(0,-this->velocityY);
    }
}
