// // // // // // // // // // // // // //
//                                     //
//         WorldObserver.cpp           //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#include "WorldObserver.h"

Observers::WorldObserver &Observers::WorldObserver::getInstance() {
    static WorldObserver instance;
    return instance;
}

std::vector<std::shared_ptr<Entities::Platform>> Observers::WorldObserver::getNotifiedPlatforms() {
    std::vector<std::shared_ptr<Entities::Platform>> n;
    for (const auto& item: createPlatforms) {
        n.push_back(item);
    }
    createPlatforms.clear();
    return n;
}

std::vector<std::shared_ptr<Entities::BGTile>> Observers::WorldObserver::getNotifiedTiles() {
    std::vector<std::shared_ptr<Entities::BGTile>> n;
    for (const auto& item: createTiles) {
        n.push_back(item);
    }
    createTiles.clear();
    return n;
}
