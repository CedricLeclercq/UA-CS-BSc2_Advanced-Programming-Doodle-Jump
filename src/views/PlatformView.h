// // // // // // // // // // // // // //
//                                     //
//           PlatformView.h            //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_PLATFORMVIEW_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_PLATFORMVIEW_H

#include "View.h"
#include "../observers/Observers.h"
#include "../observers/entityObservers/PlatformObserver.h"
#include "models/entities/Platform.h"

class Views::PlatformView: public View {
private:
    /// @brief Kind of platform
    PKind platformKind{};
    /// @brief Kind of bonus on the platform
    BonusPower bonusKind{};
    /// @brief Indicator if the textures are all loaded
    bool texLoaded = false;
public:
    /// @brief Shared pointer to the observer for linking the model and the view
    std::shared_ptr<Observers::PlatformObserver> observer;
    /**
     * @brief Default constructor
     */
    PlatformView()=default;
    /**
     * @brief Default destructor
     */
    ~PlatformView()=default;
    /**
     * @brief Explicit constructor that receives and links the model's observer
     * @param platform
     */
    explicit PlatformView(const std::shared_ptr<Entities::Platform>& platform);
    /**
     * @brief Will setup the textures for all the platforms
     */
    void setup() override;
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_PLATFORMVIEW_H
