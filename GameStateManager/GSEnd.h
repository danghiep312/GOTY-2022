//
// Created by hiepd on 1/26/2022.
//

#ifndef GAME_GSEND_H
#define GAME_GSEND_H


#include "GameStateBase.h"
#include "GameStateMachine.h"


class GSEnd : public GameStateBase {
public:
    GSEnd();

    virtual ~GSEnd();

    void exit();

    void pause();

    void resume();

    void init();

    void update(float deltaTime);

    void render(RenderWindow *window);

private:
    View m_OriginView;

    float m_CurrentTime;

    Sprite m_Background;
    list<GameButton*> m_ListBtn;
    Text m_Title;
    Text m_CurrentScore;
    Text m_BestScore;
    Text m_BackMenu;
};

#endif //GAME_GSEND_H
