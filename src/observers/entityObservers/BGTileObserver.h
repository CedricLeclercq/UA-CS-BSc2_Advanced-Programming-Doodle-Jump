// // // // // // // // // // // // // //
//                                     //
//         BGTileObserver.h            //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_BGTILEOBSERVER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_BGTILEOBSERVER_H

#include "../Observers.h"

class Observers::BGTileObserver: public Observer {
private:
    /// @brief Latest notified location of the tile
    Coordinates curLocation{};
    /// @brief Should this tile be removed in the next iteration?
    bool remove{};
    /// @brief Was this tile just created in the previous iteration?
    bool create{};
    /**
     * @brief Will notify the observer of changes
     */
    void notifyObserver() override { notified=true;}
    /**
     * @brief Getter for the observers basic notifier
     * @return  notified
     */
    bool getNotified() override {return notified;}
public:
    /**
     * @brief Default constructor
     */
    BGTileObserver()=default;
    /**
     * @brief Default destructor
     */
    ~BGTileObserver() override=default;
    /**
     * @brief Will notify if this tile needs to be removed in the next iteration
     */
    void notifyRemoved() {remove = true;}
    /**
     * @brief Will notify is this tile was just created in the previous iteration
     */
    void notifyCreation() { create = true;}
    /**
     * @brief Getter for if the tile was just asked to be removed
     * @return  remove?
     */
    bool notifiedRemoval() const {return remove;}
    /**
     * @brief Notify the observer of the tiles latest location
     * @param location  latest location
     */
    void notifyCurLocation(Coordinates location) {curLocation = location;}
    /**
     * @brief Getter for the latest notified position
     * @return  latestLocation?
     */
    Coordinates getNotifiedPosition() const {return this->curLocation;}
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_BGTILEOBSERVER_H
