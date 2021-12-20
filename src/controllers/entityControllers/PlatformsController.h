// // // // // // // // // // // // // //
//                                     //
//        PlatformController.h         //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_PLATFORMSCONTROLLER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_PLATFORMSCONTROLLER_H

#include "../Controllers.h"
#include "../../entities/Platform.h"

class Controllers::PlatformsController: public Controller {
private:
    /// @brief shared pointer to its model
    std::shared_ptr<Platform> model;
public:
    /// @brief Default constructor
    PlatformsController()=default;
    /**
     * @brief Constructor that will initialise the model and the view
     * @param nModel    Model it will use to initialise
     */
    explicit PlatformsController(std::shared_ptr<Platform> nModel);
    /// @brief Getter for the view
    std::shared_ptr<sf::Sprite> getView() const;
    /// @brief Getter for the model
    std::shared_ptr<Platform> getModel() const;
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_PLATFORMSCONTROLLER_H
