//
// Created by Cédric Leclercq on 27/12/2021.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_SCOREOBSERVER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_SCOREOBSERVER_H

#include "../Observers.h"

class Observers::ScoreObserver: public Observer {
private:
    /// @brief The current overall score in the logic game
    float currentScore{};
    /// @brief A bool that indicates that the score has changed but the value was not yet gotten by any function
    bool scoreChanged{};
    /// @brief Default private constructor, because the class is used as a Singleton
    ScoreObserver()=default;
public:
    /**
     * @brief Will return the instance of the scoreObserver if it exists, else it will create one and return it
     * @return
     */
    static ScoreObserver& getInstance();
    /**
     * @brief Setter for the score in the game
     * @param newScore   New score
     */
    void setScore(float newScore);
    /**
     * @brief Will add a float to the current score
     * @param newScore  New score
     */
    void addScore(float newScore);
    /**
     * @brief Will notify the observer if something has changed (aka the score has changed)
     */
    void notifyObserver() override;
    /**
     * @brief Getter for if the score is changed
     * @return      Will get is the score was changed
     */
    bool getNotified() override;
    /**
     * @brief Will reset the static instance, used for when a new game is started
     */
    void resetObserver() override;
    /**
     * @brief Getter for the score
     * @return
     */
    int getScore();
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_SCOREOBSERVER_H
