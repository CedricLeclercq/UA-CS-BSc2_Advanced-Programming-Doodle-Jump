// // // // // // // // // // // // // //
//                                     //
//              Game.cpp               //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#include "Game.h"
#include "../observers/entityObservers/ScoreObserver.h"
#include "../observers/entityObservers/PlayerObserver.h"
#include "../observers/entityObservers/PlatformObserver.h"
#include "../observers/entityObservers/BGTileObserver.h"
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <memory>
#include <fstream>

using Coordinates = Utilities::Coordinates;


Game::Game(): mWindow(new sf::RenderWindow(sf::VideoMode(800, 1200),"Doodle jump - Advanced programming")) {
    this->initialiseGame();
    this->setup();
    this->start();
}

void Game::initialiseGame() {
    // Resetting the player and score observer
    //Observers::ScoreObserver::getInstance().resetObserver(); // todo fix
    // Creating world
    ConcreteFactory factory;
    std::pair<float, float> borderX = std::make_pair(0, this->mWindow->getSize().x);
    std::pair<float, float> borderY = std::make_pair(0, this->mWindow->getSize().y);
    // Creating camera
    this->mCamera = factory.createCamera(Coordinates(1, 1200), Coordinates(borderX.second, borderY.second));
    std::shared_ptr<World> world = std::make_shared<World>(mCamera);
    this->controller = WorldController(world);
    this->mWindow->setFramerateLimit(60); // Setting framerate limit
    // Setting up the player view
    playerView = std::make_shared<Views::PlayerView>(world->getPlayer());
    playerView->setup();
    // Loading text for score
    this->scoreFont.loadFromFile("recourses/arial.ttf");
    this->scoreText.setFont(this->scoreFont);
    this->scoreText.setFillColor(sf::Color::White);
    this->scoreText.setCharacterSize(50);
    this->scoreText.setPosition(50,40);
    this->defineLengths();
}

void Game::setup() {
    // Removing any of the removed platform views
    this->removePlatformViews();
    this->removeTileViews();
    // Adding any new views
    this->createNewViews();
    // Placing all the elements for the game
    this->placeBackground();
    this->placePlatforms();
    this->placePlayer();
}

void Game::start() {
    while ((*this->mWindow).isOpen()) {
        //float deltaTicks = Utilities::Stopwatch::getInstance().getDeltaTicks(); // Getting the delta ticks for defining the player speed
        //std::cout << deltaTicks << std::endl; // todo remove debug
        Utilities::Stopwatch::getInstance().startCounter();
        this->getInput(); // Getting input from the user and moving the player
        controller.updateWorld(); // Updating the world based on the user input
        this->setup(); // Setting up the graphics and placing all views
        this->addScore(); // Adding the score to the window
        this->openSFWindow(); // Finally, opening the game
        this->evaluateEndGame(); // Evaluating is the game has ended
        Utilities::Stopwatch::getInstance().stopCounter();
    }
}


void Game::getInput() {
    this->controller.evalOutOfWorld(0.f,(float)this->mWindow->getSize().x);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) or sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        this->controller.movePlayerRight();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) or sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        this->controller.movePlayerLeft();
    }
}

void Game::defineLengths() {
    // Getting platform length
    sf::Sprite testPlatform;
    sf::Texture testPlatformTex;
    testPlatformTex.loadFromFile("recourses/textures/platforms/yellow_platform.png");
    testPlatform.setTexture(testPlatformTex); // todo fix this will be removed
    float platformLength = testPlatform.getLocalBounds().width;
    // Getting player length
    sf::Sprite testPlayer;
    sf::Texture playerFeetTex;
    playerFeetTex.loadFromFile("recourses/textures/playerFeet.png"); // todo try and catch
    testPlayer.setTexture(playerFeetTex);
    float playerLength = testPlayer.getLocalBounds().width * (float)0.4;
    this->controller.setLengths(playerLength / (float)this->mWindow->getSize().x,
                                platformLength / (float)this->mWindow->getSize().x);
}

void Game::placePlayer() {
    // Getting and setting position of main player
    Coordinates viewCoo = mCamera->project(playerView->observer->getNotifiedPosition()); //= this->mCamera->project(*this->mWorld->getPlayer()->getPos()); // todo get player location from observer
    playerView->setPosition(viewCoo.getX(), viewCoo.getY());
    // Load rocket texture if needed
    if (playerView->observer->getNotifiedRocket()) {
        playerView->setRocketTex();
    } else {
        playerView->setNormalTex();
    }
    (*this->mWindow).draw(playerView->getView());
}

void Game::placePlatforms() {
    for (auto& view: this->platformsViews) {
        Utilities::Coordinates coords = this->mCamera->project(view->observer->getNotifiedPosition());
        //std::cout << view->observer->getNotifiedPosition().getX() << " " << view->observer->getNotifiedPosition().getY() << std::endl;
        view->setPosition(coords.getX(),coords.getY());
        view->getView().setOrigin(0,view->getView().getLocalBounds().height);
        (*this->mWindow).draw(view->getView());
    }
    // for (auto& controller: this->platformsControllers) {
    //     Utilities::Coordinates coords = this->mCamera->project(*controller.getModel()->getPos());
    //     controller.getView()->setPosition(coords.getX(),coords.getY());
    //     this->setPlatformTexture(controller.getModel(),*controller.getView());
    //     controller.getView()->setOrigin(0,controller.getView()->getLocalBounds().height);
    //     (*this->mWindow).draw(*controller.getView());
    // }
}

void Game::placeBackground() {
    for (auto& view: this->tilesViews) {
        Utilities::Coordinates coords = this->mCamera->project(view->observer->getNotifiedPosition());
        view->setPosition(coords.getX(),coords.getY());
        view->getView().setOrigin(0,view->getView().getLocalBounds().height);
        (*this->mWindow).draw(view->getView());
    }
    // for (auto& controller: this->view) {
    //     Utilities::Coordinates coords = this->mCamera->project(*controller.getModel()->getPos());
    //     controller.getView()->setPosition(coords.getX(),coords.getY());
    //     this->setTileTexture(controller.getModel(),*controller.getView());
    //     controller.getView()->setOrigin(0,controller.getView()->getLocalBounds().height);
    //     (*this->mWindow).draw(*controller.getView());
    // }
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
    if (controller.isGameOver()) {
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

void Game::removePlatformViews() {
    std::vector<std::shared_ptr<Views::PlatformView>> newViews;
    for (const auto& view: platformsViews) {
        if (!view->observer->notifiedRemoval())
            newViews.push_back(view);
    }
    platformsViews.clear();
    platformsViews = newViews;
}

void Game::removeTileViews() {
    std::vector<std::shared_ptr<Views::BGTileView>> newViews;
    for (const auto& view: tilesViews) {
        if (!view->observer->notifiedRemoval())
            newViews.push_back(view);
    }
    tilesViews.clear();
    tilesViews = newViews;
}

void Game::createNewViews() {
    std::vector<std::shared_ptr<Entities::Platform>> newPlatforms = Observers::WorldObserver::getInstance().getNotifiedPlatforms();
    for (const auto& item: newPlatforms) {
        std::shared_ptr<Views::PlatformView> nView = std::make_shared<Views::PlatformView>(item);
        nView->setup();
        platformsViews.push_back(nView);
    }
    std::vector<std::shared_ptr<Entities::BGTile>> newTiles = Observers::WorldObserver::getInstance().getNotifiedTiles();
    for (const auto& item: newTiles) {
        std::shared_ptr<Views::BGTileView> nView = std::make_shared<Views::BGTileView>(item);
        nView->setup();
        tilesViews.emplace_back(nView);
    }
}
