// // // // // // // // // // // // // //
//                                     //
//        BGTileController.h           //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_BGTILECONTROLLER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_BGTILECONTROLLER_H

#include "../Controllers.h"
#include "../../models/entities/BGTile.h"

class Controllers::BGTileController: public Controller {
private:
    /// @brief Shared pointer to the BGTile this controller is controlling
    std::shared_ptr<Entities::BGTile> model;
public:
    /// @brief Default constructor
    BGTileController()=default;
    /**
     * @brief Constructor that initialises the view and the model
     * @param nModel    Model it will use for constructing
     */
    explicit BGTileController(std::shared_ptr<Entities::BGTile> nModel);
    /// @brief Getter for the view
    std::shared_ptr<sf::Sprite> getView() const;
    /// @brief Getter for the model
    std::shared_ptr<Entities::BGTile> getModel() const;
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_BGTILECONTROLLER_H