//
// Created by Cédric Leclercq on 05/01/2022.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_WORLDOBSERVER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_WORLDOBSERVER_H

#include "observers/Observers.h"
#include "../../models/entities/Platform.h"
#include "../../models/entities/BGTile.h"

class Observers::WorldObserver: public Observer {
private:
    std::vector<std::shared_ptr<Entities::Platform>> createPlatforms;
    std::vector<std::shared_ptr<Entities::BGTile>> createTiles;
    WorldObserver()=default;
public:
    static WorldObserver& getInstance();
    void notifyCreatePlatform(const std::shared_ptr<Entities::Platform>& n) {createPlatforms.push_back(n);}
    void notifyCreateTile(const std::shared_ptr<Entities::BGTile>& n) {createTiles.push_back(n);}
    std::vector<std::shared_ptr<Entities::Platform>> getNotifiedPlatforms();
    std::vector<std::shared_ptr<Entities::BGTile>> getNotifiedTiles();
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_WORLDOBSERVER_H
