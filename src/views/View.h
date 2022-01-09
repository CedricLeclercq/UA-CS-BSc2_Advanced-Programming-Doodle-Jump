// // // // // // // // // // // // // //
//                                     //
//               View.h                //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_VIEW_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_VIEW_H

#include "Views.h"
#include <memory>
#include "../models/Entity.h"

#include "../textureManagers/TextureManagers.h"

class Views::View {
protected:
    /// @brief Shared pointer to the view
    std::shared_ptr<sf::Sprite> view{};
    /**
     * @brief Pure virtual function for setting up the class after setting the invariant with the constructor
     */
    virtual void setup() = 0;
public:
    /**
     * @brief Basic constructor that creates a shared pointer to a sprite
     */
    View(): view{std::make_shared<sf::Sprite>()} {}
    /**
     * @brief Default destructor
     */
    virtual ~View()=default;
    /**
     * @brief Function to set the position of the view
     * @param x     newX coordinate
     * @param y     newY coordinate
     */
    void setPosition(float x, float y) {view->setPosition(x,y); }
    /**
     * @brief Getter for the view
     * @return      sf::Sprite view
     */
    std::shared_ptr<sf::Sprite> getView() const {return view;}
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_VIEW_H
