//
// Created by Cédric Leclercq on 18/11/2021.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_PLATFORM_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_PLATFORM_H

#include "../utilities/Utilities.h"
#include "Entity.h"
#include "Bonus.h"

enum PKind {UNDEF,STATIC,HORIZONTAL,VERTICAL,TEMP};


class Platform: public Entity {
private:
    PKind platformKind;
    bool movingRight{};
    void createPlatform();
    void makeStatic();
    void makeHorizontal();
    void makeVertical();
    void makeTemp();
    std::shared_ptr<Bonus> bonus{};
public:
    explicit Platform(PKind kind=UNDEF) {
        this->platformKind = kind;
        this->createPlatform();
    }
    PKind getKind() const;
    void moveRight() override;
    void moveLeft() override;
    void moveUp();
    void moveDown();
    void changeToGround();
    bool getMovingRight();
    void setMovingRight(bool newBool);
    void setBonus(std::shared_ptr<Bonus> nBonus);
    std::shared_ptr<Bonus> getBonus() const;
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_PLATFORM_H
