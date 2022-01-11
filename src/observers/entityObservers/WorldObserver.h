// // // // // // // // // // // // // //
//                                     //
//          WorldObserver.h            //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_WORLDOBSERVER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_WORLDOBSERVER_H

#include "observers/Observers.h"
#include "../../models/entities/Platform.h"
#include "../../models/entities/BGTile.h"

class Observers::WorldObserver: public Observer {
private:
    /// @brief Vector will all the platforms that need a view
    std::vector<std::shared_ptr<Entities::Platform>> createPlatforms{};
    /// @brief Vector will all the tiles that need a view
    std::vector<std::shared_ptr<Entities::BGTile>> createTiles{};
    /**
     * @brief Private default constructor (because singleton class)
     */
    WorldObserver()=default;
public:
    /**
     * @brief Default destructor
     */
    ~WorldObserver() override=default;
    /**
     * @brief Will return an instance of the class - part of the singleton pattern
     * @note If an instance does not yet exist, it will create one
     * @return  an instance of worldObserver
     */
    static WorldObserver& getInstance();
    /**
     * @brief Will add a platform where a view needs to be created of
     * @param n     new platform
     */
    void notifyCreatePlatform(const std::shared_ptr<Entities::Platform>& n) {createPlatforms.push_back(n);}
    /**
     * @brief Will add a tile where a view needs to be created of
     * @param n     new tile
     */
    void notifyCreateTile(const std::shared_ptr<Entities::BGTile>& n) {createTiles.push_back(n);}
    /**
     * @brief Getter for all the platforms that need a view
     * @return      vector with all the platforms
     */
    std::vector<std::shared_ptr<Entities::Platform>> getNotifiedPlatforms();
    /**
     * @brief Getter for all the tiles that need a view
     * @return      vector with all the tiles
     */
    std::vector<std::shared_ptr<Entities::BGTile>> getNotifiedTiles();
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_WORLDOBSERVER_H
