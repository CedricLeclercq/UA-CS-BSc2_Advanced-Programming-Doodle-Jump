// // // // // // // // // // // // // //
//                                     //
//         ScoreObserver.cpp           //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

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

void Observers::ScoreObserver::notifyScore(int nScore) {
    if (currentScore == nScore) return; // Of course don't notify is the score is the same
    this->currentScore = nScore;
    notifyObserver();
}
