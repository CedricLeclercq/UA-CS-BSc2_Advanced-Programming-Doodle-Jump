// // // // // // // // // // // // // //
//                                     //
//        BGTileController.h           //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_BGTILECONTROLLER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_BGTILECONTROLLER_H

#include "../Controllers.h"
#include "../../entities/background/BGTile.h"

class Controllers::BGTileController: public Controller {
private:
    /// @brief Shared pointer to the BGTile this controller is controlling
    std::shared_ptr<BGTile> model;
public:
    /// @brief Default constructor
    BGTileController()=default;
    /**
     * @brief Constructor that initialises the view and the model
     * @param nModel    Model it will use for constructing
     */
    explicit BGTileController(std::shared_ptr<BGTile> nModel);
    /// @brief Getter for the view
    std::shared_ptr<sf::Sprite> getView() const;
    /// @brief Getter for the model
    std::shared_ptr<BGTile> getModel() const;
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_BGTILECONTROLLER_H