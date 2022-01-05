//
// Created by Cédric Leclercq on 05/01/2022.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_SCORE_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_SCORE_H


class Score {
private:
    /// @brief The current overall score in the logic game
    float currentScore{};
public:
    Score(): currentScore(0.f) {}
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
