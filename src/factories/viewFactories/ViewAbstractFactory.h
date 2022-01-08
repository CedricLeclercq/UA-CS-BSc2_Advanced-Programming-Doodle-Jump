//
// Created by Cédric Leclercq on 08/01/2022.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_VIEWABSTRACTFACTORY_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_VIEWABSTRACTFACTORY_H

#include "views/PlayerView.h"
#include "views/PlatformView.h"
#include "views/BGTileView.h"
#include <memory>

using std::shared_ptr;
using namespace Views;
using namespace Entities;

class ViewAbstractFactory {
protected:
    /**
     * @brief Pure virtual function for creating a player view
     * @param player    Player that a view should be created of
     * @return          shared pointer to the new view
     */
    virtual shared_ptr<PlayerView> createPlayerView(const shared_ptr<Player>& player) = 0;
    /**
     * @brief Pure virtual function for creating a platform view
     * @param platform    Platform that a view should be created of
     * @return          shared pointer to the new view
     */
    virtual shared_ptr<PlatformView> createPlatformView(const shared_ptr<Platform>& platform) = 0;
    /**
     * @brief Pure virtual function for creating a background tile view
     * @param tile      BGTile that a view should be created of
     * @return          shared pointer to the new view
     */
    virtual shared_ptr<BGTileView> creatBGTileView(const shared_ptr<BGTile>& tile) = 0;

};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_VIEWABSTRACTFACTORY_H
