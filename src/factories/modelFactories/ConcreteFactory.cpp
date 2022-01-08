// // // // // // // // // // // // // //
//                                     //
//         ConcreteFactory.cpp         //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#include "ConcreteFactory.h"
#include <memory>
#include "gameLogic/World.h"

std::shared_ptr<Entities::Player> ConcreteFactory::createPlayer() {
    return std::shared_ptr<Entities::Player>(new Entities::Player());
}

std::shared_ptr<Entities::BGTile> ConcreteFactory::createBGTile() {
    return std::shared_ptr<Entities::BGTile>(new Entities::BGTile());
}

std::shared_ptr<Entities::Bonus> ConcreteFactory::createBonus() {
    return std::shared_ptr<Entities::Bonus>(new Entities::Bonus());
}

std::shared_ptr<Entities::Platform> ConcreteFactory::createPlatform(PKind kind) {
    return std::shared_ptr<Entities::Platform>(new Entities::Platform(kind));
}

std::shared_ptr<World> ConcreteFactory::createWorld(std::shared_ptr<Camera> camera) {
    return std::shared_ptr<World>(new World(camera));
}

std::unique_ptr<Camera> ConcreteFactory::createCamera(const Coordinates& worldView, const Coordinates& cameraView) {
    return std::make_unique<Camera>(worldView,cameraView);
}

std::shared_ptr<Score> ConcreteFactory::createScore() {
    return std::make_shared<Score>();
}
