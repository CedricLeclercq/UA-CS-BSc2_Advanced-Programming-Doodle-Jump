// // // // // // // // // // // // // //
//                                     //
//             Entity.h                //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_ENTITY_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_ENTITY_H

#include <utility>
#include <memory>
#include "../utilities/Utilities.h"

/**
 * @class Entity
 * @brief Super class for all the entities
 */
class Entity {
protected:
    /// @brief Position of the entity
    std::shared_ptr<Utilities::Coordinates> position{};
    /// @brief Length of the entity
    float length{};
    /// @brief Indicates how much the entity needs to speed up / slow down its movements
    float deltaTicksSpeedUp{};
    /**
     * @brief Pure virtual function for the entity to move right
     */
    virtual void moveRight() = 0;
    /**
     * @brief Pure virtual function for the entity to move left
     */
    virtual void moveLeft() = 0;
    /**
     * @brief Will Move the player given an offset based on its current position
     * @param offsetX       Offset on the X coordinate
     * @param offsetY       Offset on the Y coordinate
     */
    void move(float offsetX, float offsetY);
public:
    /**
     * @brief Constructor that will initialise only the coordinates
     */
    Entity() {
        this->position = std::make_shared<Utilities::Coordinates>(0,0);
        this->deltaTicksSpeedUp = 1;
    }
    /**
     * @brief Setter for the position of the entity
     * @param nX    New x coordinate
     * @param nY    New y coordinate
     */
    void setPos(float nX, float nY);
    /**
     * @brief Setter for the x coordinate of the entity
     * @param nX    New x coordinate
     */
    void setPosX(float nX);
    /**
     * @brief Setter for the y coordinate of the entity
     * @param nY    New y coordinate
     */
    void setPosY(float nY);
    /**
     * @brief Getter for the position of the entity
     * @return      Coordinates of the entity
     */
    std::shared_ptr<Utilities::Coordinates> getPos();
    /**
     * @brief Getter for the x coordinate of the entity
     * @return      X coordinate of the entity
     */
    float getPosX();
    /**
     * @brief Getter for the y coordinate of the entity
     * @return      Y coordinate of the entity
     */
    float getPosY();
    /**
     * @brief Setter for the length of the entity
     * @param nLength   New length
     */
    void setLength(float nLength);
    /**
     * @brief Getter for the length of the entity
     * @return      Length of the entity
     */
    float getLength() const;
    /**
     * @brief Getter for the delta tick speed of an entity
     * @return      Delta tick speed
     */
    float getDeltaTick() const;
    /**
     * @brief Setter for the delta tick speed of an entity
     * @param deltaTick     New delta tick speed
     */
    void setDeltaTick(float deltaTick);

};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_ENTITY_H
