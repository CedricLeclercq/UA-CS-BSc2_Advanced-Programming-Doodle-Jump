// // // // // // // // // // // // // //
//                                     //
//          ScoreObserver.h            //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_SCOREOBSERVER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_SCOREOBSERVER_H

#include "../Observers.h"

class Observers::ScoreObserver: public Observer {
private:
    /// @brief Last score that the observer was notified of
    int currentScore{};
    /// @brief Bool that indicates if the score has been notified - changed
    bool scoreChanged{};
    /// @brief Default private constructor, because the class is used as a Singleton
    ScoreObserver()=default;
    /**
     * @brief Will notify the observer if something has changed (aka the score has changed)
     */
    void notifyObserver() override;
public:
    /**
     * @brief Default destructor
     */
    ~ScoreObserver()=default;
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
    /**
     * @brief Will notify the observer of a score change
     * @param nScore    newly changed score
     */
    void notifyScore(int nScore);
    /**
     * @brief Getter for the current score
     * @return      this->currentScore
     */
    int getScore() const {return currentScore;}
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_SCOREOBSERVER_H
