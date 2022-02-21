//
// Created by hiepd on 1/28/2022.
//

#ifndef GAME_GSHIGHSCORE_H
#define GAME_GSHIGHSCORE_H

#include "GameStateBase.h"
#include "GameStateMachine.h"


class GSHighScore : public GameStateBase {
public:
    GSHighScore();

    virtual ~GSHighScore();

    void exit();

    void pause();

    void resume();

    void init();

    void update(float deltaTime);

    void render(RenderWindow *window);

private:
    Sprite m_Background;
    list<GameButton *> m_ListBtn;
    list<Text *> m_ListScore;
    Text m_Title;
};


#endif //GAME_GSHIGHSCORE_H
