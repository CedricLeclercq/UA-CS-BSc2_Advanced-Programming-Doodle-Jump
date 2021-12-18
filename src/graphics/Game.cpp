//
// Created by Cédric Leclercq on 18/11/2021.
//

#include "Game.h"
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include "../factories/ConcreteFactory.h"
#include <cmath>
#include <memory>
using Coordinates = Utilities::Coordinates;

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

void Game::setPlatformTexture(const std::shared_ptr<Platform>& platform, sf::Sprite& sfPlatform) {
    if (platform->getKind() == PKind::STATIC)
        sfPlatform.setTexture(this->mStaticPlatformTex);
    else if (platform->getKind() == PKind::HORIZONTAL)
        sfPlatform.setTexture(this->mHorizontalPlatformTex);
    else if (platform->getKind() == PKind::TEMP)
        sfPlatform.setTexture(this->mTempPlatformTex);
    else if (platform->getKind() == PKind::VERTICAL)
        sfPlatform.setTexture(this->mVerticalPlatformTex);
}

void Game::setTileTexture(const std::shared_ptr<BGTile> &tile, sf::Sprite &sfTile) {
    if (tile->getKind() == TKind::MILKYWAY1) {
        sfTile.setTexture(this->mMilkyWay1Tex);
        sfTile.setScale(1.2,1.2);
    }
    else if (tile->getKind() == TKind::MILKYWAY2) {
        sfTile.setTexture(this->mMilkyWay2Tex);
        sfTile.setScale(1.2,1.2);
    }
    else if (tile->getKind() == TKind::STAR1) {
        sfTile.setTexture(this->mStar1Tex);
        sfTile.setScale(0.2,0.2);
    }
    else if (tile->getKind() == TKind::STAR2) {
        sfTile.setTexture(this->mStar2Tex);
    }
    else if (tile->getKind() == TKind::PLANET1) {
        sfTile.setTexture(this->mPlanet1Tex);
    }
    else if (tile->getKind() == TKind::PLANET2) {
        sfTile.setTexture(this->mPlanet2Tex);
    }
    else if (tile->getKind() == TKind::PLANET3) {
        sfTile.setTexture(this->mPlanet3Tex);
    }
    else if (tile->getKind() == TKind::PLANET4) {
        sfTile.setTexture(this->mPlanet4Tex);
    }
    else if (tile->getKind() == TKind::PLANET5) {
        sfTile.setTexture(this->mPlanet5Tex);
    }
    else if (tile->getKind() == TKind::PLANET6) {
        sfTile.setTexture(this->mPlanet6Tex);
    }
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
    // todo fix looking left
    // Adding the jump to the graphics
    if (this->mWorld->getPlayer()->getLookingLeft()) {
        // Mirroring the character if it is looking left
        //this->playerController.getView().setScale(-0.4, 0.4); // todo look left is disabled
    } else {
        // But reverse if it is not looking left
        //this->playerController.getView().setScale(0.4,0.4); // todo ... also here
    }
    // Scaling the player to its correct size
    this->playerController.getView().setScale(0.4,0.4);
}

void Game::createWorld() {
    // Creating world
    ConcreteFactory factory;
    std::pair<float,float> borderX = std::make_pair(0,this->mWindow->getSize().x);
    std::pair<float,float> borderY = std::make_pair(0,this->mWindow->getSize().y);
    // Creating camera
    this->mCamera = factory.createCamera(Coordinates(1, 1200), Coordinates(borderX.second,borderY.second));
    this->mWorld = factory.createWorld(mCamera);
}

void Game::initiateTextures() {
    // todo make sure to try all of these and throw an exception if one didn't load!
    try {
        // Textures for platforms
        this->mVerticalPlatformTex.loadFromFile("recourses/textures/gray_platform.png");
        this->mHorizontalPlatformTex.loadFromFile("recourses/textures/light_blue_platform.png");
        this->mStaticPlatformTex.loadFromFile("recourses/textures/green_platform.png");
        this->mTempPlatformTex.loadFromFile("recourses/textures/yellow_platform.png");
        // Textures for background tiles
        this->mPlanet1Tex.loadFromFile("recourses/textures/background/planets/Planet1.png");
        this->mPlanet2Tex.loadFromFile("recourses/textures/background/planets/Planet2.png");
        this->mPlanet3Tex.loadFromFile("recourses/textures/background/planets/Planet3.png");
        this->mPlanet4Tex.loadFromFile("recourses/textures/background/planets/Planet4.png");
        this->mPlanet5Tex.loadFromFile("recourses/textures/background/planets/Planet5.png");
        this->mPlanet6Tex.loadFromFile("recourses/textures/background/planets/Planet6.png");
        this->mMilkyWay1Tex.loadFromFile("recourses/textures/background/milkyways/MilkyWay1.png");
        this->mMilkyWay2Tex.loadFromFile("recourses/textures/background/milkyways/MilkyWay2.png");
        this->mStar1Tex.loadFromFile("recourses/textures/background/stars/Star1.png");
        this->mStar2Tex.loadFromFile("recourses/textures/background/stars/Star2.png");
        this->mGroundTex.loadFromFile("recourses/textures/background/Ground.png");

        // Setting texture of main player
        mSpriteTex.loadFromFile("recourses/textures/playerPictogram.png");
        mSpriteTex.setSmooth(true);
        sf::Sprite &playerView = this->playerController.getView();
        playerView.setTexture(mSpriteTex);
        playerView.setOrigin(0, playerView.getLocalBounds().height); // todo fix better location

        // Setting background texture
        mBackgroundTex.loadFromFile("recourses/textures/background.png");
        mBackground.setTexture(this->mBackgroundTex);

        this->defineLengths();

    } catch (std::exception& exc) {
        // todo fix what to catch here above
        std::cerr << "An exception occurred but caught while loading the textures. ";
        std::cerr << "The exception was the following: " << std::endl << exc.what() << std::endl << std::endl;
        std::cerr << "The graphical interface might not look as expected. Try pulling the game again from GitHub.";
        std::cerr << std::endl << std::endl;
    }
}

void Game::defineLengths() {
    // Getting platform length
    sf::Sprite testPlatform;
    testPlatform.setTexture(this->mHorizontalPlatformTex);
    float platformLength = testPlatform.getLocalBounds().width;
    // Getting player length
    sf::Sprite testPlayer;
    sf::Texture playerFeetTex;
    playerFeetTex.loadFromFile("recourses/textures/playerFeet.png");
    testPlayer.setTexture(playerFeetTex);
    float playerLength = testPlayer.getLocalBounds().width * (float)0.4;
    this->mWorld->setPlatformLength(platformLength / (float)this->mWindow->getSize().x);
    this->mWorld->setPlayerLength(playerLength / (float)this->mWindow->getSize().x);
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
    Coordinates viewCoo = this->mCamera->project(*this->mWorld->getPlayer()->getPos());
    this->playerController.getView().setPosition(viewCoo.getX(), viewCoo.getY());
    (*this->mWindow).draw(this->playerController.getView());
}

void Game::placePlatforms() {
    std::vector<std::shared_ptr<Platform>> worldPlatforms = (*this->mWorld).getPlatforms();
    for (const auto& platform: worldPlatforms) {
        sf::Sprite newPlatform;
        Utilities::Coordinates coords = this->mCamera->project(*platform->getPos());
        newPlatform.setPosition(coords.getX(), coords.getY());
        this->setPlatformTexture(platform, newPlatform);
        newPlatform.setOrigin(0, newPlatform.getLocalBounds().height);//todo fix not here
        (*this->mWindow).draw(newPlatform);
    }
}

void Game::placeBonus() {

}

void Game::placeBackground() {
    std::vector<std::shared_ptr<BGTile>> worldBackground = this->mWorld->getBackground();
    for (const auto& tile: worldBackground) {
        sf::Sprite newTile;
        Coordinates coords = this->mCamera->project(*tile->getPos());
        newTile.setPosition(coords.getX(),coords.getY());
        this->setTileTexture(tile,newTile);
        newTile.setOrigin(0,newTile.getLocalBounds().height);
        (*this->mWindow).draw(newTile);
    }
    //(*this->mWindow).draw(mBackground);
}

void Game::addFPSCounter() {
    // FPS print
    sf::Clock clock;
    sf::Text text;
    sf::Font font;
    font.loadFromFile("recourses/arial.ttf");
    text.setFont(font);
    text.setString(std::to_string((int)std::round(1.f /  clock.restart().asSeconds())) + " fps");
    text.setFillColor(sf::Color::White);
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
    (*this->mWindow).clear(sf::Color(5,5,25));
}

void Game::updateWorld() {
    this->mWorld->updateWorld();
}





