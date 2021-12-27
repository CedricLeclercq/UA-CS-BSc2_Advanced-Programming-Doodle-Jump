// // // // // // // // // // // // // //
//                                     //
//              Game.cpp               //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#include "Game.h"
#include "../observers/entityObservers/ScoreObserver.h"
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <memory>
#include <fstream>

using Coordinates = Utilities::Coordinates;

void Game::initialiseGame() {
    this->createWorld();
    this->createPlayerController();
    this->initiateTextures();
    this->scaleElements();
}

void Game::setup() {
    // Creating new controllers if needed
    this->createPlatformsControllers();
    this->createBGTileControllers();

    // Placing all the elements for the game
    this->placeBackground();
    this->placePlatforms();
    this->placePlayer();
}

void Game::createPlatformsControllers() {

    // Removing all the controllers that are no longer used by the world
    std::vector<std::shared_ptr<Entities::Platform>> worldPlatforms = (*this->mWorld).getPlatforms();
    std::vector<Controllers::PlatformsController> newControllers;
    for (const auto& pController: this->platformsControllers) {
        for (const auto& platform: worldPlatforms) {
            if (pController.getModel() == platform) {
                newControllers.push_back(pController);
            }
        }
    }
    this->platformsControllers.clear();
    this->platformsControllers = newControllers;

    // Adding the platforms that don't yet have a controller
    for (const auto& platform: worldPlatforms) {
        bool found = false;
        for (const auto& controller: this->platformsControllers) {
            if (controller.getModel() == platform) {
                found = true;
            }
        }
        // Platform doesn't have a controller yet, create it!
        if (!found) {
            // Pushing back our new controller to all our controllers
            this->platformsControllers.emplace_back(platform);
        }
    }
}

void Game::createBGTileControllers() {
    // Removing all the controllers that are no longer used by the world
    std::vector<std::shared_ptr<Entities::BGTile>> worldTiles = (*this->mWorld).getBackground();
    std::vector<Controllers::BGTileController> newControllers;
    for (const auto& tController: this->bgTileControllers) {
        for (const auto& tile: worldTiles) {
            if (tController.getModel() == tile) {
                newControllers.push_back(tController);
            }
        }
    }
    this->bgTileControllers.clear();
    this->bgTileControllers = newControllers;

    // Adding the platforms that don't yet have a controller
    for (const auto& tile: worldTiles) {
        bool found = false;
        for (const auto& controller: this->bgTileControllers) {
            if (controller.getModel() == tile) {
                found = true;
            }
        }
        // Platform doesn't have a controller yet, create it!
        if (!found) {
            // Pushing back our new controller to all our controllers
            this->bgTileControllers.emplace_back(tile);
        }
    }
}

void Game::setPlatformTexture(const std::shared_ptr<Entities::Platform>& platform, sf::Sprite& sfPlatform) {
    if (platform->getBonus() == nullptr) {
    if (platform->getKind() == PKind::STATIC)
        sfPlatform.setTexture(this->mStaticPlatformTex);
    else if (platform->getKind() == PKind::HORIZONTAL)
        sfPlatform.setTexture(this->mHorizontalPlatformTex);
    else if (platform->getKind() == PKind::TEMP)
        sfPlatform.setTexture(this->mTempPlatformTex);
    else if (platform->getKind() == PKind::VERTICAL)
        sfPlatform.setTexture(this->mVerticalPlatformTex);
    }

    else if (platform->getBonus() != nullptr and platform->getBonus()->getPowerKind() == BonusPower::SPRING) {
        if (platform->getKind() == PKind::STATIC)
            sfPlatform.setTexture(this->mStaticSpringPlatformTex);
        else if (platform->getKind() == PKind::HORIZONTAL)
            sfPlatform.setTexture(this->mHorizontalSpringPlatformTex);
        else if (platform->getKind() == PKind::TEMP)
            sfPlatform.setTexture(this->mTempSpringPlatformTex);
        else if (platform->getKind() == PKind::VERTICAL)
            sfPlatform.setTexture(this->mVerticalSpringPlatformTex);
    }

    else if (platform->getBonus() != nullptr and platform->getBonus()->getPowerKind() == BonusPower::ROCKET) {
        if (platform->getKind() == PKind::STATIC)
            sfPlatform.setTexture(this->mStaticRocketPlatformTex);
        else if (platform->getKind() == PKind::HORIZONTAL)
            sfPlatform.setTexture(this->mHorizontalRocketPlatformTex);
        else if (platform->getKind() == PKind::TEMP)
            sfPlatform.setTexture(this->mTempRocketPlatformTex);
        else if (platform->getKind() == PKind::VERTICAL)
            sfPlatform.setTexture(this->mVerticalRocketPlatformTex);
    }
}

void Game::setTileTexture(const std::shared_ptr<Entities::BGTile> &tile, sf::Sprite &sfTile) {
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
        float deltaTicks = Utilities::Stopwatch::getInstance().getDeltaTicks(); // Getting the delta ticks for defining the player speed
        std::cout << deltaTicks << std::endl; // todo remove debug
        Utilities::Stopwatch::getInstance().startCounter();
        this->getInput(); // Getting input from the user and moving the player
        this->updateWorld(); // Updating the world based on the user input
        this->setup(); // Setting up the graphics and placing all views
        //Game::addFPSCounter(); // Adding an FPS counter, can be left out might the user want it
        this->addScore(); // Adding the score to the window
        this->openSFWindow(); // Finally, opening the game
        this->evaluateEndGame(); // Evaluating is the game has ended
        Utilities::Stopwatch::getInstance().stopCounter();
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
    // Resetting the player and score observer
    Observers::ScoreObserver::getInstance().resetObserver();
    // todo reset player controller
    // Creating world
    ConcreteFactory factory;
    std::pair<float,float> borderX = std::make_pair(0,this->mWindow->getSize().x);
    std::pair<float,float> borderY = std::make_pair(0,this->mWindow->getSize().y);
    // Creating camera
    this->mCamera = factory.createCamera(Coordinates(1, 1200), Coordinates(borderX.second,borderY.second));
    this->mWorld = factory.createWorld(mCamera);
    this->mWindow->setFramerateLimit(120); // Setting framerate limit // todo fix setting framerate
    //this->mStopwatch->setFPS(20);
}

void Game::initiateTextures() {
    // todo make sure to try all of these and throw an exception if one didn't load!
    try {
        // Textures for platforms
        this->mVerticalPlatformTex.loadFromFile("recourses/textures/platforms/yellow_platform.png");
        this->mHorizontalPlatformTex.loadFromFile("recourses/textures/platforms/light_blue_platform.png");
        this->mStaticPlatformTex.loadFromFile("recourses/textures/platforms/green_platform.png");
        this->mTempPlatformTex.loadFromFile("recourses/textures/platforms/white_platform.png");
        // Textures for bonus platforms
        this->mVerticalSpringPlatformTex.loadFromFile("recourses/textures/platforms/yellow_platform_spring1.png");
        this->mHorizontalSpringPlatformTex.loadFromFile("recourses/textures/platforms/light_blue_platform_spring1.png");
        this->mStaticSpringPlatformTex.loadFromFile("recourses/textures/platforms/green_platform_spring1.png");
        this->mTempSpringPlatformTex.loadFromFile("recourses/textures/platforms/white_platform_spring1.png");
        this->mVerticalRocketPlatformTex.loadFromFile("recourses/textures/platforms/yellow_platform_rocket.png");
        this->mHorizontalRocketPlatformTex.loadFromFile("recourses/textures/platforms/light_blue_platform_rocket.png");
        this->mStaticRocketPlatformTex.loadFromFile("recourses/textures/platforms/green_platform_rocket.png");
        this->mTempRocketPlatformTex.loadFromFile("recourses/textures/platforms/white_platform_rocket.png");

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

        // Texture for bonuses
        this->mRocketBonusTex.loadFromFile("recourses/textures/bonuses/rsz_rocket1.png");

        // Loading text for score
        this->scoreFont.loadFromFile("recourses/arial.ttf"); // "recourses/ChrustyRock-ORLA.ttf"
        this->scoreText.setFont(this->scoreFont);
        this->scoreText.setFillColor(sf::Color::White);
        this->scoreText.setCharacterSize(50);
        this->scoreText.setPosition(50,40);


        // Texture for player
        mSpriteTex.loadFromFile("recourses/textures/playerPictogram.png");
        mSpriteTex.setSmooth(true);
        sf::Sprite &playerView = this->playerController.getView();
        playerView.setTexture(mSpriteTex);
        playerView.setOrigin(0, playerView.getLocalBounds().height); // todo fix better location

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
    playerFeetTex.loadFromFile("recourses/textures/playerFeet.png"); // todo try and catch
    testPlayer.setTexture(playerFeetTex);
    float playerLength = testPlayer.getLocalBounds().width * (float)0.4;
    this->mWorld->setPlatformLength(platformLength / (float)this->mWindow->getSize().x);
    this->mWorld->setPlayerLength(playerLength / (float)this->mWindow->getSize().x);
    this->mWorld->getPlayer()->setLength(playerLength / (float)this->mWindow->getSize().x);
}

void Game::createPlayerController() {
    // Creating sprite
    std::shared_ptr<sf::Sprite> sprite = std::make_shared<sf::Sprite>();
    // Creating controllers
    this->playerController = Controllers::PlayerController(this->mWorld->getPlayer(),sprite);
}

void Game::scaleElements() {
    // Scaling main player
    this->playerController.getView().setScale(0.1,0.1);
}

void Game::placePlayer() {
    // Getting and setting position of main player
    Coordinates viewCoo = this->mCamera->project(*this->mWorld->getPlayer()->getPos());
    this->playerController.getView().setPosition(viewCoo.getX(), viewCoo.getY());
    std::shared_ptr<Entities::Bonus> playerBonus = this->mWorld->getPlayer()->getBonus();
    // Load rocket texture
    if (playerBonus != nullptr and playerBonus->getPowerKind() == BonusPower::ROCKET) {
        this->playerController.getView().setTexture(this->mRocketBonusTex);
        //this->playerController.getView().setScale(1,1);
    } else {
        this->playerController.getView().setTexture(this->mSpriteTex);
    }
    (*this->mWindow).draw(this->playerController.getView());
}

void Game::placePlatforms() {
    for (auto& controller: this->platformsControllers) {
        Utilities::Coordinates coords = this->mCamera->project(*controller.getModel()->getPos());
        controller.getView()->setPosition(coords.getX(),coords.getY());
        this->setPlatformTexture(controller.getModel(),*controller.getView());
        controller.getView()->setOrigin(0,controller.getView()->getLocalBounds().height);
        (*this->mWindow).draw(*controller.getView());
    }
}

void Game::placeBackground() {
    for (auto& controller: this->bgTileControllers) {
        Utilities::Coordinates coords = this->mCamera->project(*controller.getModel()->getPos());
        controller.getView()->setPosition(coords.getX(),coords.getY());
        this->setTileTexture(controller.getModel(),*controller.getView());
        controller.getView()->setOrigin(0,controller.getView()->getLocalBounds().height);
        (*this->mWindow).draw(*controller.getView());
    }
}

__attribute__((unused)) void Game::addFPSCounter() {
    // FPS print
    sf::Clock clock;
    sf::Text text;
    sf::Font font;
    //font.loadFromFile("recourses/arial.ttf"); // If enabled again, catch a possible exception!
    text.setFont(font);
    //text.setString(std::to_string((int)std::round(1.f /  clock.restart().asSeconds())) + " fps");
    //text.setString(std::to_string(Stopwatch::getFPS()) + " fps");
    text.setFillColor(sf::Color::White);
    text.setPosition(700,10);
    text.setCharacterSize(24);
    //(*this->mWindow).draw(text);
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
    //this->mWorld->setDeltaTicks(Utilities::Stopwatch::getInstance().calculateSpeedUp());
    this->mWorld->updateWorld();
}

void Game::addScore() {
    // Do not change the score if it's not needed
    if (this->scoreText.getString() == std::to_string(Observers::ScoreObserver::getInstance().getScore())) {
        (*this->mWindow).draw(this->scoreText);
        return;
    }

    // else, change the score
    this->scoreText.setString(std::to_string(Observers::ScoreObserver::getInstance().getScore()));
    (*this->mWindow).draw(this->scoreText);
}

void Game::drawEndScreen() {
    // Drawing "GAME OVER!" text
    sf::Text gameOverText;
    gameOverText.setFont(this->scoreFont);
    gameOverText.setString("Game over!");
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setCharacterSize(40);
    sf::FloatRect textRect = gameOverText.getLocalBounds();
    gameOverText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    gameOverText.setPosition(sf::Vector2f(static_cast<float>(this->mWindow->getSize().x) / 2.0f, 100));

    sf::Text gameOverScore;
    gameOverScore.setCharacterSize(50);
    gameOverScore.setOutlineColor(sf::Color::Red);
    gameOverScore.setFont(this->scoreFont);
    gameOverScore.setString("Current score: " + this->scoreText.getString());
    sf::FloatRect scoreTextRect = gameOverScore.getLocalBounds();
    gameOverScore.setOrigin(scoreTextRect.left + scoreTextRect.width / 2.0f,
                              scoreTextRect.top + scoreTextRect.height / 2.0f);
    gameOverScore.setPosition(
            sf::Vector2f(static_cast<float>(this->mWindow->getSize().x) / 2.0f, 200));

    // Drawing high scores
    std::ifstream file("recourses/game_data.info");
    std::string highscore;
    std::getline(file, highscore);
    file.close();
    // We get a score higher than the one we already had
    if (std::stoi(highscore) < Observers::ScoreObserver::getInstance().getScore()) {
        std::ofstream ofFile;
        ofFile.open("recourses/game_data.info", std::ofstream::out | std::ofstream::trunc);
        ofFile << Observers::ScoreObserver::getInstance().getScore();
        ofFile.close();
    }
    std::ifstream file2("recourses/game_data.info");
    std::getline(file2, highscore);
    file2.close();

    sf::Text highScoreText;
    highScoreText.setFont(this->scoreFont);
    highScoreText.setString("All time Highscore: " + highscore);
    highScoreText.setCharacterSize(40);
    sf::FloatRect highscoreRect = highScoreText.getLocalBounds();
    highScoreText.setOrigin(highscoreRect.left + highscoreRect.width / 2.0f,
                            highscoreRect.top + highscoreRect.height / 2.0f);
    highScoreText.setPosition(sf::Vector2f(static_cast<float>(this->mWindow->getSize().x) / 2.0f, 400));

    sf::Text newGame;
    newGame.setFont(this->scoreFont);
    newGame.setString("Press enter to start a new game");
    newGame.setCharacterSize(30);
    sf::FloatRect newGameRect = newGame.getLocalBounds();
    newGame.setOrigin(newGameRect.left + newGameRect.width / 2.0f, newGameRect.top + newGameRect.height / 2.0f);
    newGame.setPosition(sf::Vector2f(static_cast<float>(this->mWindow->getSize().x) / 2.0f, 600));

    while (not sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        this->mWindow->clear(sf::Color::Black);

        (*this->mWindow).draw(gameOverText);

        // Drawing player score
        (*this->mWindow).draw(gameOverScore);
        // Drawing high score text
        (*this->mWindow).draw(highScoreText);
        // Drawing start new game text
        (*this->mWindow).draw(newGame);
        if(this->openEndSFScreen()) {
            break;
        }
    }

    this->initialiseGame();
    this->setup();
}

void Game::evaluateEndGame() {
    if (this->mWorld->checkGameOver()) {
        Utilities::Stopwatch::getInstance().stopCounter();
        this->drawEndScreen();
        Utilities::Stopwatch::getInstance().startCounter();
    }
}

bool Game::openEndSFScreen() {
    sf::Event event{};
    while ((*this->mWindow).pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            (*this->mWindow).close();
            return true;
        }
    }
    (*this->mWindow).display();
    (*this->mWindow).clear(sf::Color::Black);
    return false;
}