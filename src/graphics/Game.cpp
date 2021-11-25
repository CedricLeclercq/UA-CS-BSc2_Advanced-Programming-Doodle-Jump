//
// Created by Cédric Leclercq on 18/11/2021.
//

#include "Game.h"
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <cmath>

void Game::initialiseGame() {
    // Creating world
    this->mWorld = std::make_unique<World>();
    // Setting texture of main player
    mSpriteTex.loadFromFile("recourses/playerPictogram.png");
    mSpriteTex.setSmooth(true);
    mSprite.setTexture(mSpriteTex);
    // Scaling main player
    mSprite.setScale(0.1,0.1);
}

void Game::setup() {
    // Getting and setting position of main player
    //std::cout << "Position: " << this->mWorld->getPlayer()->getPosX() << std::endl;
    mSprite.setPosition(this->mWorld->getPlayer()->getPosX(), this->mWorld->getPlayer()->getPosY());
    // Drawing main character
    (*this->mWindow).draw(mSprite);
}

void Game::start() {
    sf::Clock clock;

    while ((*this->mWindow).isOpen()) {
        // Moving the character and setting up the graphics
        this->moveCharacter();
        this->setup();
        // FPS print todo
        sf::Text text;
        sf::Font font;
        font.loadFromFile("recourses/arial.ttf");
        text.setFont(font);
        text.setString(std::to_string((int)std::round(1.f /  clock.restart().asSeconds())) + " fps");
        text.setFillColor(sf::Color::White);
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

void Game::moveCharacter() {
    this->jumpCharacter();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) or sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        this->mWorld->getPlayer()->moveRight();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) or sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        this->mWorld->getPlayer()->moveLeft();
    }
}

void Game::jumpCharacter() {
    this->mWorld->getPlayer()->jump();
    // Adding the jump to the graphics
    if (this->mWorld->getPlayer()->getLookingLeft()) {
        // Mirroring the character if it is looking left
        this->mSprite.setScale(-1, 1);
    } else {
        // But reverse if it is not looking left
        this->mSprite.setScale(1,1);
    }
}


