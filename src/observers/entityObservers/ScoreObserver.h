//
// Created by Cédric Leclercq on 27/12/2021.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_SCOREOBSERVER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_SCOREOBSERVER_H

#include "../Observers.h"

class Observers::ScoreObserver: public Observer {
private:
    float currentScore{};
    bool scoreChanged{};
    ScoreObserver()=default;
public:
    static ScoreObserver& getInstance();
    void setScore(float newScore);
    void addScore(float newScore);
    void notifyObserver() override;
    bool getNotified() override;
    void resetObserver() override;
    int getScore();
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_SCOREOBSERVER_H
