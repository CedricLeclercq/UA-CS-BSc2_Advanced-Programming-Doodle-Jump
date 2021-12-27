//
// Created by Cédric Leclercq on 27/12/2021.
//

#include "ScoreObserver.h"
#include <cmath>


void Observers::ScoreObserver::setScore(float newScore) {
    this->currentScore = newScore;
}

void Observers::ScoreObserver::addScore(float newScore) {
    this->currentScore += newScore;
    this->notifyObserver();
}

void Observers::ScoreObserver::notifyObserver() {
    this->scoreChanged = true;
}

bool Observers::ScoreObserver::getNotified() {
    return this->scoreChanged;
}

int Observers::ScoreObserver::getScore() {
    this->scoreChanged = false; // Because the score was gotten here
    return std::ceil(this->currentScore);
}

Observers::ScoreObserver &Observers::ScoreObserver::getInstance() {
    static ScoreObserver instance;
    return instance;
}

void Observers::ScoreObserver::resetObserver() {
    this->scoreChanged = false;
    this->currentScore = 0;
}
