// // // // // // // // // // // // // //
//                                     //
//       viewConcreteFactory.h         //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_VIEWCONCRETEFACTORY_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_VIEWCONCRETEFACTORY_H

#include "ViewAbstractFactory.h"

class ViewConcreteFactory: public ViewAbstractFactory {
public:
    /**
     * @brief Default constructor
     */
    ViewConcreteFactory()=default;
    /**
     * @brief Default destructor
     */
    ~ViewConcreteFactory()=default;
    /**
     * @brief Virtual function for creating a player view
     * @param player    Player that a view should be created of
     * @return          shared pointer to the new view
     */
    shared_ptr<PlayerView> createPlayerView(const shared_ptr<Player>& player) override;
    /**
     * @brief Virtual function for creating a platform view
     * @param platform    Platform that a view should be created of
     * @return          shared pointer to the new view
     */
    shared_ptr<PlatformView> createPlatformView(const shared_ptr<Platform>& platform) override;
    /**
     * @brief Virtual function for creating a background tile view
     * @param tile      BGTile that a view should be created of
     * @return          shared pointer to the new view
     */
    shared_ptr<BGTileView> creatBGTileView(const shared_ptr<BGTile>& tile) override;
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_VIEWCONCRETEFACTORY_H
