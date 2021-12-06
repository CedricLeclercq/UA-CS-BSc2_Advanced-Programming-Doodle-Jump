//
// Created by Cédric Leclercq on 18/11/2021.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_PLATFORM_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_PLATFORM_H

#include "../utilities/Utilities.h"
#include "Entity.h"

enum PKind {UNDEF,STATIC,HORIZONTAL,VERTICAL,TEMP};


class Platform: public Entity {
private:
    PKind platformKind;
    void createPlatform();
    void makeStatic();
    void makeHorizontal();
    void makeVertical();
    void makeTemp();
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
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_PLATFORM_H
