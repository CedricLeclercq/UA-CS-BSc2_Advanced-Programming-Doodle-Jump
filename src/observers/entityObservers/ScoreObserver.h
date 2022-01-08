//
// Created by Cédric Leclercq on 27/12/2021.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_SCOREOBSERVER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_SCOREOBSERVER_H

#include "../Observers.h"

class Observers::ScoreObserver: public Observer {
private:
    int currentScore{};
    bool scoreChanged{};
    /// @brief Default private constructor, because the class is used as a Singleton
    ScoreObserver()=default;
    /**
     * @brief Will notify the observer if something has changed (aka the score has changed)
     */
    void notifyObserver() override;
public:
    /**
     * @brief Will return the instance of the scoreObserver if it exists, else it will create one and return it
     * @return
     */
    static ScoreObserver& getInstance();
    /**
     * @brief Getter for if the score is changed
     * @return      Will get is the score was changed
     */
    bool getNotified() override;
    void notifyScore(int nScore);
    int getScore() const {return currentScore;}
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_SCOREOBSERVER_H
