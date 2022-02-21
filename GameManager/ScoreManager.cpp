//
// Created by hiepd on 2/17/2022.
//

#include <algorithm>
#include <fstream>
#include "ScoreManager.h"

ScoreManager::ScoreManager() {
    m_Num = 5;
}

void ScoreManager::setCurrentScore(int score) {
    m_CurrentScore = score;
}

void ScoreManager::updateHighScore() {
    int s = m_CurrentScore;

    if (s > m_HighScore[4]) {
        m_HighScore[4] = s;
    }
    std::sort(m_HighScore, m_HighScore + m_Num, std::greater<int>());

}

int ScoreManager::getBestScore() {
    return m_HighScore[0];
}

void ScoreManager::readFile() {
    std::fstream input;
    input.open("Score.data", std::ios::binary | std::ios::in);
    input.read((char*)m_HighScore, sizeof(m_HighScore));
    input.close();

}

void ScoreManager::writeFile() {
    std::fstream output;
    output.open("Score.data", std::ios::binary | std::ios::out);
    output.write((char*)m_HighScore, sizeof(m_HighScore));
    output.close();

}

int *ScoreManager::getHighScore() {
    return m_HighScore;
}

int ScoreManager::getNum() {
    return m_Num;
}

void ScoreManager::printScores() {
    for (int i = 0; i < m_Num; i++) {
        printf ("%d ", m_HighScore[i]);
    }
    printf ("\n");
}

int ScoreManager::getCurrentScore() {
    return m_CurrentScore;
}
