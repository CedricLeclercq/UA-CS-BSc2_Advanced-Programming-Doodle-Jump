// // // // // // // // // // // // // //
//                                     //
//     viewConcreteFactory.cpp         //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#include "ViewConcreteFactory.h"

shared_ptr<PlayerView> ViewConcreteFactory::createPlayerView(const shared_ptr<Player> &player) {
    return shared_ptr<PlayerView>(new PlayerView(player));
}

shared_ptr<PlatformView> ViewConcreteFactory::createPlatformView(const shared_ptr<Platform> &platform) {
    return shared_ptr<PlatformView>(new PlatformView(platform));
}

shared_ptr<BGTileView> ViewConcreteFactory::creatBGTileView(const shared_ptr<BGTile> &tile) {
    return shared_ptr<BGTileView>(new BGTileView(tile));
}
