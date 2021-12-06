//
// Created by Cédric Leclercq on 18/11/2021.
//

#include "Game.h"
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include "../factories/ConcreteFactory.h"
#include <cmath>

void Game::initialiseGame() {
    // Creating world
    ConcreteFactory factory;
    std::pair<float,float> borderX = std::make_pair(0,this->mWindow->getSize().x);
    std::pair<float,float> borderY = std::make_pair(0,this->mWindow->getSize().y);
    this->mWorld = factory.createWorld(borderX,borderY);


    // Setting texture of main player
    mSpriteTex.loadFromFile("recourses/playerPictogram.png");
    mSpriteTex.setSmooth(true);
    mSprite.setTexture(mSpriteTex);

    // Setting background texture
    mBackgroundTex.loadFromFile("recourses/background.png");
    mBackground.setTexture(this->mBackgroundTex);


    // Scaling main player
    mSprite.setScale(0.5,0.5);
    mBackground.setScale(2, 2);
}

void Game::setup() {
    // Getting and setting position of main player
    mSprite.setPosition(this->mWorld->getPlayer()->getPosX(), this->mWorld->getPlayer()->getPosY());
    (*this->mWindow).draw(mBackground);
    (*this->mWindow).draw(mSprite);
}

void Game::setTextures() {
    // The plaform on which the player is should become the standard height for the player. All other platforms should
    // then go away that fall out of the new range and ofcourse move with the given offset
    std::vector<std::shared_ptr<Platform>> gamePlatforms = this->mWorld->getPlatforms();
    for (auto platform: gamePlatforms) {
        bool found = false;
        for (const auto& pair: this->platforms) {
            if (pair.first == platform) {
                found = true;
            }
        }
        if (not found) {
            sf::Sprite newPlatform;
            // TODO set position of newPlatform with the camera utility
            if (platform->getKind() == PKind::STATIC)
                newPlatform.setTexture(this->mStaticPlatformTex);
            else if (platform->getKind() == PKind::HORIZONTAL)
                newPlatform.setTexture(this->mHorizontalPlatformTex);
            else if (platform->getKind() == PKind::TEMP)
                newPlatform.setTexture(this->mTempPlatformTex);
            else if (platform->getKind() == PKind::VERTICAL)
                newPlatform.setTexture(this->mVerticalPlatformTex);
            this->platforms.emplace_back(platform,newPlatform);
        }
    }
}

void Game::start() {
    sf::Clock clock;

    while ((*this->mWindow).isOpen()) {
        // Moving the character and setting up the graphics
        this->getInput();
        this->setup();

        // FPS print todo
        sf::Text text;
        sf::Font font;
        font.loadFromFile("recourses/arial.ttf");
        text.setFont(font);
        text.setString(std::to_string((int)std::round(1.f /  clock.restart().asSeconds())) + " fps");
        text.setFillColor(sf::Color::Black);
        text.setPosition(700,10);
        text.setCharacterSize(24);
        (*this->mWindow).draw(text);


        //std::cout << 1.f /  clock.restart().asSeconds()  << std::endl;
        // Drawing the game
        sf::Event event{};
        while ((*this->mWindow).pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                (*this->mWindow).close();
        }
        (*this->mWindow).display();
        (*this->mWindow).clear();
    }
}

void Game::getInput() {
    this->jumpCharacter();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) or sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        this->mWorld->getPlayer()->moveRight();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) or sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        this->mWorld->getPlayer()->moveLeft();
    }
    this->mWorld->getPlayer()->teleportPlayer(0.f,(float)this->mWindow->getSize().x);
}

void Game::jumpCharacter() {
    this->mWorld->getPlayer()->jump();
    // Adding the jump to the graphics
    if (this->mWorld->getPlayer()->getLookingLeft()) {
        // Mirroring the character if it is looking left
        this->mSprite.setScale(-0.5, 0.5);
    } else {
        // But reverse if it is not looking left
        this->mSprite.setScale(0.5,0.5);
    }
}




