//
// Created by Cédric Leclercq on 18/11/2021.
//

#include "Game.h"
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include "../factories/ConcreteFactory.h"
#include <cmath>

void Game::initialiseGame() {
    this->createWorld();
    this->createControllers();
    this->initiateTextures();
    this->scaleElements();
    // Placing first platforms
    //this->mWorld->createPlatforms(0,this->mWindow->getSize().y);
    //this->setTextures();
}

void Game::setup() {
    this->placeBackground();
    this->placePlatforms();
    this->placeBonus();
    this->placePlayer();
}

void Game::setTexture(const std::shared_ptr<Platform>& platform, sf::Sprite& sfPlatform) {
    if (platform->getKind() == PKind::STATIC)
        sfPlatform.setTexture(this->mStaticPlatformTex);
    else if (platform->getKind() == PKind::HORIZONTAL)
        sfPlatform.setTexture(this->mHorizontalPlatformTex);
    else if (platform->getKind() == PKind::TEMP)
        sfPlatform.setTexture(this->mTempPlatformTex);
    else if (platform->getKind() == PKind::VERTICAL)
        sfPlatform.setTexture(this->mVerticalPlatformTex);
}

void Game::start() {
    while ((*this->mWindow).isOpen()) {
        this->getInput(); // Getting input from the user and moving the player
        this->updateWorld(); // Updating the world based on the user input
        this->setup(); // Setting up the graphics and placing all views
        this->addFPSCounter(); // Adding an FPS counter, can be left out might the user want it
        this->openSFWindow(); // Finally opening the game
    }
}

void Game::getInput() {
    this->playerController.handleInput();
    this->mWorld->getPlayer()->teleportPlayer(0.f,(float)this->mWindow->getSize().x);
    this->jumpingGraphics();
}

void Game::jumpingGraphics() {
    // Adding the jump to the graphics
    if (this->mWorld->getPlayer()->getLookingLeft()) {
        // Mirroring the character if it is looking left
        this->playerController.getView().setScale(-0.4, 0.4);
    } else {
        // But reverse if it is not looking left
        this->playerController.getView().setScale(0.4,0.4);
    }
}

void Game::createWorld() {
    // Creating world
    ConcreteFactory factory;
    std::pair<float,float> borderX = std::make_pair(0,this->mWindow->getSize().x);
    std::pair<float,float> borderY = std::make_pair(0,this->mWindow->getSize().y);
    this->mWorld = factory.createWorld(borderX,borderY);
    // Creating camera
    this->mCamera = factory.createCamera(borderX.second,borderY.second, this->mWorld);
}

void Game::initiateTextures() {
    // Textures for platforms
    this->mVerticalPlatformTex.loadFromFile("recourses/textures/gray_platform.png");
    this->mHorizontalPlatformTex.loadFromFile("recourses/textures/light_blue_platform.png");
    this->mStaticPlatformTex.loadFromFile("recourses/textures/green_platform.png");
    this->mTempPlatformTex.loadFromFile("recourses/textures/yellow_platform.png");

    // Setting texture of main player
    mSpriteTex.loadFromFile("recourses/textures/playerPictogram.png");
    mSpriteTex.setSmooth(true);
    this->playerController.getView().setTexture(mSpriteTex);

    // Setting background texture
    mBackgroundTex.loadFromFile("recourses/textures/background.png");
    mBackground.setTexture(this->mBackgroundTex);
}

void Game::createControllers() {
    // Creating sprite
    std::shared_ptr<sf::Sprite> sprite = std::make_shared<sf::Sprite>();
    // Creating controllers
    this->playerController = Controllers::PlayerController(this->mWorld->getPlayer(),sprite);
    this->platformController = Controllers::PlatformController();
}

void Game::scaleElements() {
    // Scaling main player
    this->playerController.getView().setScale(0.1,0.1);
    this->mBackground.setScale(2, 2);
}

void Game::placePlayer() {
    // Getting and setting position of main player
    this->playerController.getView().setPosition(this->mWorld->getPlayer()->getPosX(), this->mWorld->getPlayer()->getPosY());
    (*this->mWindow).draw(this->playerController.getView());
}

void Game::placePlatforms() {
    std::vector<std::shared_ptr<Platform>> worldPlatforms = (*this->mWorld).getPlatforms();
    for (const auto& platform: worldPlatforms) {
        sf::Sprite newPlatform;
        newPlatform.setPosition(platform->getPosX(), platform->getPosX()); // TODO use camera class here
        this->setTexture(platform,newPlatform);
        (*this->mWindow).draw(newPlatform);
    }
}

void Game::placeBonus() {

}

void Game::placeBackground() {
    (*this->mWindow).draw(mBackground);
}

void Game::addFPSCounter() {
    // FPS print
    sf::Clock clock;
    sf::Text text;
    sf::Font font;
    font.loadFromFile("recourses/arial.ttf");
    text.setFont(font);
    text.setString(std::to_string((int)std::round(1.f /  clock.restart().asSeconds())) + " fps");
    text.setFillColor(sf::Color::Black);
    text.setPosition(700,10);
    text.setCharacterSize(24);
    (*this->mWindow).draw(text);
}

void Game::openSFWindow() {
    sf::Event event{};
    while ((*this->mWindow).pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            (*this->mWindow).close();
    }
    (*this->mWindow).display();
    (*this->mWindow).clear();
}

void Game::updateWorld() {
    this->mWorld->updateWorld();
}





