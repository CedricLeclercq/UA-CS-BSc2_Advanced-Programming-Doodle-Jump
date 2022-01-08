//
// Created by Cédric Leclercq on 05/01/2022.
//

#include "Score.h"
#include "../observers/entityObservers/ScoreObserver.h"
#include <cmath>

void Score::setScore(float newScore) {
    this->currentScore = newScore;
    Observers::ScoreObserver::getInstance().notifyScore(static_cast<int>(currentScore));
}

void Score::addScore(float newScore) {
    this->currentScore += newScore;
    Observers::ScoreObserver::getInstance().notifyScore(static_cast<int>(currentScore));
}

int Score::getScore() const {
    return std::ceil(this->currentScore);
}
