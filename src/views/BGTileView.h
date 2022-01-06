//
// Created by Cédric Leclercq on 04/01/2022.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_BGTILEVIEW_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_BGTILEVIEW_H

#include "View.h"
#include "../models/entities/BGTile.h"
#include "../observers/Observers.h"
#include "../observers/entityObservers/BGTileObserver.h"


class Views::BGTileView: public View {
private:
    // Kind of tile we have
    TKind tileKind{};
    bool texLoaded = false;
public:
    // Observer
    std::shared_ptr<Observers::BGTileObserver> observer;
    explicit BGTileView(const std::shared_ptr<Entities::BGTile>& tile);
    void setup() override;
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_BGTILEVIEW_H
