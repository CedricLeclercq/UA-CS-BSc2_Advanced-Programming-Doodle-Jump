// // // // // // // // // // // // // //
//                                     //
//            PlayerView.h             //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYERVIEW_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYERVIEW_H

#include "View.h"
#include "../models/Entities.h"
#include "../observers/Observers.h"
#include "../observers/entityObservers/PlayerObserver.h"

class Views::PlayerView: public View {
private:
    /// @brief Indicates if all the textures are loaded
    bool texLoaded = false;
public:
    /// @brief Shared pointer to the observer for linking the model and the view
    std::shared_ptr<Observers::PlayerObserver> observer;
    /**
     * @brief Default constructor
     */
    PlayerView()=default;
    /**
     * @brief Default destructor
     */
    ~PlayerView() override =default;
    /**
     * @brief Constructor with a player object
     * @param player    player of the logic game (model)
     */
    explicit PlayerView(const std::shared_ptr<Entities::Player>& player);
    /**
     * @brief Will set the rocket texture to the player
     */
    void setRocketTex();
    /**
     * @brief Will setup the textures and the class so its ready for use
     */
    void setup() override;
    /**
     * @brief Will set the normal texture to the player
     */
    void setNormalTex();
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYERVIEW_H
