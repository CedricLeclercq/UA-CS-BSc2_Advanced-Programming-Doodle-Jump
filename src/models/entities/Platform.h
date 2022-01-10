// // // // // // // // // // // // // //
//                                     //
//            Platform.h               //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_PLATFORM_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_PLATFORM_H

#include "../../utilities/Utilities.h"
#include "../Entities.h"
#include "Bonus.h"
#include "../../observers/Observers.h"
#include "observers/entityObservers/PlatformObserver.h"

/// @brief Enumeration for the kind of platform we have
enum PKind {UNDEF,STATIC,HORIZONTAL,VERTICAL,TEMP};


class Entities::Platform: public Entity {
private:
    // Member variables
    /// @brief Kind of platform we have
    PKind platformKind{};
    /// @brief Used by a vertical platform - max height it can rise itself to
    float maxHeight{};
    /// @brief Used by a vertical platform - min height it can lower itself to
    float minHeight{};
    /// @brief Used by a horizontal platform - indicates if the platform is moving right
    bool movingRight{};
    /// @brief Used by a vertical platform - indicates if the platform is moving up
    bool movingUp{};
    /// @brief Shared pointer to the bonus that the platform has on it
    std::shared_ptr<Entities::Bonus> bonus{};
    // Member functions
    /**
     * @brief Create a platform - used in construction - will define what kind of platform we have
     */
    void createPlatform();
    /**
     * @brief Will make a platform's kind a static platform
     */
    void makeStatic();
    /**
     * @brief Will make a platform's kind a horizontal platform
     */
    void makeHorizontal();
    /**
     * @brief Will make a platform's kind a vertical platform
     */
    void makeVertical();
    /**
     * @brief Will make a platform's kind a temporary platform
     */
    void makeTemp();
public:
    /// @brief Observer
    std::shared_ptr<Observers::PlatformObserver> observer;
    /**
     * @brief Explicit constructor with default argument - will always be used when a platform is constructed
     * @param kind      Platform kind that the platform needs to be
     * @note            The default argument is not used for now, but can be used if future implementation might need it
     */
    explicit Platform(PKind kind=UNDEF): observer(std::make_shared<Observers::PlatformObserver>()) {
        this->platformKind = kind;
        this->createPlatform();
    }
    /**
     * @brief Default destructor
     */
    ~Platform() override = default;
    /**
     * @brief Getter for the platform kind
     * @return      platform's kind
     */
    PKind getKind() const;
    /**
     * @brief Will move a platform to the right with a fixed value
     */
    void moveRight() override;
    /**
     * @brief Will move a platform to the left with a fixed value
     */
    void moveLeft() override;
    /**
     * @brief Will move a platform up with a fixed value
     */
    void moveUp();
    /**
     * @brief Will move a platform down with a fixed value
     */
    void moveDown();
    /**
     * @brief Getter for if the platform is moving to the right
     * @return      (platformIsMovingRight?)
     */
    bool getMovingRight() const;
    /**
     * @brief Setter for if the platform is moving to the right
     * @param newBool       New moving right
     */
    void setMovingRight(bool newBool);
    /**
     * @brief Getter for if the platform is moving up
     * @return      (platformIsMovingUp?)
     */
    bool getMovingUp() const;
    /**
     * @brief Setter for is the platform is moving up
     * @param newBool       New moving up
     */
    void setMovingUp(bool newBool);
    /**
     * @brief Getter for the maximum height a platform can go
     * @return      Platforms max height
     */
    float getMaxHeight() const;
    /**
     * @brief Setter for the maximum height a platform can go
     * @param newHeight     New maximum height
     */
    void setMaxHeight(float newHeight);
    /**
     * @brief Getter for the minimum height a platform can go
     * @return  Platforms min height
     */
    float getMinHeight() const;
    /**
     * @brief Setter for the minimum height a platform can go
     * @param newHeight     New minimum height
     */
    void setMinHeight(float newHeight);
    /**
      * @brief Getter for the bonus that is on the platform
      * @return      Bonus currently on the platform
      */
    std::shared_ptr<Entities::Bonus> getBonus() const;
    /**
     * @brief Setter for which bonus is on the platform
     * @param nBonus        Shared pointer to a new bonus
     */
    void setBonus(std::shared_ptr<Entities::Bonus> nBonus);
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_PLATFORM_H
