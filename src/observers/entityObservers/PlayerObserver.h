// // // // // // // // // // // // // //
//                                     //
//          PlayerObserver.h           //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYEROBSERVER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYEROBSERVER_H

#include "../Observers.h"


class Observers::PlayerObserver: public Observer {
private:
    /// @brief Last notified location of the player
    Coordinates curLocation{};
    /// @brief Bool to indicate if the player currently has the rocket boost
    bool isRocket{};
    /**
     * @brief Will notify the observer
     */
    void notifyObserver() override { notified = true;}
    /**
     * @brief Will get if the observer has been notified
     * @return  notified
     */
    bool getNotified() override {return notified;}
    /**
     * @brief Will reset the observer
     */
    void resetObserver() override {notified = false;}
public:
    /**
     * @brief Default constructor
     */
    PlayerObserver()=default;
    /**
     * @brief Default destructor
     */
    ~PlayerObserver()=default;
    /**
     * @brief Getter for if the player is currently a rocket
     * @return  isPlayerRocket?
     */
    bool getNotifiedRocket() const {return this->isRocket;}
    /**
     * @brief Will notify that the player is currently a rocket
     * @param newBool   isRocket?
     */
    void notifyIsRocket(bool newBool)  { this->isRocket = newBool;}
    /**
     * @brief Will notify the current location of the player
     * @param location  new location
     */
    void notifyCurLocation(Coordinates location) {curLocation = location;}
    /**
     * @brief Will get the latest notified position of the player
     * @return  latestPositionPlayer
     */
    Coordinates getNotifiedPosition() const {return this->curLocation;}
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYEROBSERVER_H
