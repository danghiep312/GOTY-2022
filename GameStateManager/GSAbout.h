//
// Created by hiepd on 1/28/2022.
//

#ifndef GAME_GSABOUT_H
#define GAME_GSABOUT_H

#include "GameStateMachine.h"
#include "GameStateBase.h"

class GSAbout : public GameStateBase {
public:
    GSAbout();

    virtual ~GSAbout();

    void exit();

    void pause();

    void resume();

    void init();

    void update(float deltaTime);

    void render(RenderWindow *window);

private:
    Sprite m_Background;

    list<GameButton *> m_ListBtn;

    Text m_Title;

    Text m_About;

    Text m_Tutorial;
};


#endif //GAME_GSABOUT_H
