//
// Created by Cédric Leclercq on 27/12/2021.
//

#include "ScoreObserver.h"


void Observers::ScoreObserver::notifyObserver() {
    this->scoreChanged = true;
}

bool Observers::ScoreObserver::getNotified() {
    return this->scoreChanged;
}

Observers::ScoreObserver &Observers::ScoreObserver::getInstance() {
    static ScoreObserver instance;
    return instance;
}

void Observers::ScoreObserver::notifyScore(float nScore) {
    this->currentScore = nScore;
    notifyObserver();
}
