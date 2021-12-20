//
// Created by Cédric Leclercq on 18/11/2021.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYER_H


#include <memory>
#include <utility>
#include "Bonus.h"
#include "../Entities.h"


class Entities::Player: public Entity {
private:
    bool mLookLeft{};
    /// Bool that indicates if the player is able to move up and down on itself
    bool paralysedY{};
    float velocityY{};
    float standardVelocityY{};
    float positionBeforeJumpY{};
    std::shared_ptr<Entities::Bonus> bonus{};
public:
    Player() {
        this->standardVelocityY = 1;
        this->position = std::make_shared<Utilities::Coordinates>(0.5,0.f);
        this->positionBeforeJumpY = this->getPosY();
        this->mLookLeft = false;
        this->paralysedY = false;
    }

    void moveRight() override;

    void moveLeft() override;

    void jump(bool newJump=false);

    void setVelocityY(float velocity) {
        this->velocityY = velocity;
    }

    bool getLookingLeft() const {
        return this->mLookLeft;
    }

    float getVelocityY() const {
        return this->velocityY;
    }

    void teleportPlayer(float minX, float maxX);

    void setBonus(std::shared_ptr<Entities::Bonus> nBonus) {this->bonus = std::move(nBonus);}

    std::shared_ptr<Entities::Bonus> getBonus() const { return this->bonus; }


    void setParalysed(bool paralysed) {this->paralysedY = paralysed;}



};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_PLAYER_H
