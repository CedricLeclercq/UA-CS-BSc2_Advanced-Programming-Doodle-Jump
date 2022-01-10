// // // // // // // // // // // // // //
//                                     //
//            BGTileView.h             //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_BGTILEVIEW_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_BGTILEVIEW_H

#include "View.h"
#include "../models/entities/BGTile.h"
#include "../observers/Observers.h"
#include "../observers/entityObservers/BGTileObserver.h"


class Views::BGTileView: public View {
private:
    /// @brief Kind of tile we have
    TKind tileKind{};
    /// @brief Indicator if the textures are loaded
    bool texLoaded = false;
public:
    /// @brief Shared pointer to the observer to link the model and the view
    std::shared_ptr<Observers::BGTileObserver> observer;
    /**
     * @brief Default constructor
     */
    BGTileView()=default;
    /**
     * @brief Default destructor
     */
    ~BGTileView() override =default;
    /**
     * @brief Default constructor that also links the models observer
     * @param tile      model tile
     */
    explicit BGTileView(const std::shared_ptr<Entities::BGTile>& tile);
    /**
     * @brief Will setup the textures for the background tiles
     */
    void setup() override;
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_BGTILEVIEW_H
