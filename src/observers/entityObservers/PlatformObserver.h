// // // // // // // // // // // // // //
//                                     //
//         PlatformObserver.h          //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_PLATFORMOBSERVER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_PLATFORMOBSERVER_H

#include "../Observers.h"

class Observers::PlatformObserver: public Observer {
private:
    /// @brief Latest notified location of the platform
    Coordinates curLocation{};
    /// @brief Should this platform be removed in the next iteration?
    bool remove{};
    /// @brief Was this platform just created in the previous iteration?
    bool create{};
public:
    /**
     * @brief Default constructor for the game
     */
    PlatformObserver()=default;
    /**
     * @brief Default destructor
     */
    ~PlatformObserver() override=default;
    /**
     * @brief Will notify the observer if this platforms view needs to be removed
     */
    void notifyRemoved() {remove = true;}
    /**
     * @brief Will notify if a platform was created
     */
    void notifyPlatformCreation() {create = true;}
    /**
     * @brief Getter for if a platform was just removed
     * @return  removed?
     */
    bool notifiedRemoval() const {return remove;}
    /**
     * @brief Will reset the observer
     */
    void resetObserver() override {create = false; remove = false;}
    /**
     * @brief Will notify the observer of the platforms latest location
     * @param location
     */
    void notifyCurLocation(Coordinates location) {curLocation = location;}
    /**
     * @brief Getter for the latest notified location of the platforms observer
     * @return  latestLocation?
     */
    Coordinates getNotifiedPosition() const {return this->curLocation;}
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_PLATFORMOBSERVER_H
