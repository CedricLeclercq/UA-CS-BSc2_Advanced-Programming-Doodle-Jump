// // // // // // // // // // // // // //
//                                     //
//              Score.h                //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_SCORE_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_SCORE_H


/**
 * @class Score
 * @brief Very simple class for keeping a score
 * @note Will notify an observer if the score changes
 */
class Score {
private:
    /// @brief The current overall score in the logic game
    float currentScore{};
public:
    /**
     * @brief Very basic constructor
     */
    Score(): currentScore(0.f) {}
    /**
     * @brief Default destructor
     */
    ~Score()=default;
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
     * @brief Getter for the score
     * @return
     */
    int getScore() const;
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_SCORE_H
