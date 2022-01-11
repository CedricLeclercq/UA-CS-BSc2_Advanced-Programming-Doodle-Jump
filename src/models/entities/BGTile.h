// // // // // // // // // // // // // //
//                                     //
//              BGTile.h               //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#ifndef DOODLEJUMP_BGTILE_H
#define DOODLEJUMP_BGTILE_H

#include "../Entities.h"
#include "../../observers/Observers.h"
#include "../../observers/entityObservers/BGTileObserver.h"

/// @brief Enumeration of the possible tile kinds
enum TKind {
    NONE,
    PLANET1,
    PLANET2,
    PLANET3,
    PLANET4,
    PLANET5,
    PLANET6,
    STAR1,
    STAR2,
    MILKYWAY1,
    MILKYWAY2
    };


class Entities::BGTile: public Entity {
private:
    /// @brief Describes the kind of tile this tile is
    TKind kind{};
    /**
     * @brief Will define what kind of tile a tile will be upon constructing
     */
    void defineKind();
public:
    /// @brief Observer
    std::shared_ptr<Observers::BGTileObserver> observer{};
    /**
     * @brief Constructor for the background tile - will use other functions to define the tile kind
     */
    BGTile();
    /**
     * @brief Default destructor
     */
    ~BGTile() override = default;
    /**
     * @brief Getter for the tile kind
     * @return      Tile kind
     */
    TKind getKind() const;
    /**
     * @brief Will move the background tile to the right
     * @note This function is currently not defined and not used (not needed, but is in place if it ever is)
     */
    void moveRight() override {};
    /**
     * @brief Will move the background tile to the left
     * @note This function is currently not defined and not used (not needed, but is in place if it ever is)
     */
    void moveLeft() override {};
};


#endif //DOODLEJUMP_BGTILE_H
