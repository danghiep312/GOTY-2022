 //
// Created by hiepd on 2/17/2022.
//

#ifndef GAME_SCOREMANAGER_H
#define GAME_SCOREMANAGER_H

#include "Singleton.h"

class ScoreManager : public Singleton<ScoreManager> {
public:
    ScoreManager();

    void setCurrentScore(int score);
    int getCurrentScore();

    void updateHighScore();

    int getBestScore();

    void readFile();
    void writeFile();

    int *getHighScore();
    int getNum();

    void printScores();
private:

    int m_CurrentScore;
    int m_HighScore[5] = {};
    int m_Num;
};


#endif //GAME_SCOREMANAGER_H
