//
// Created by hiepd on 1/28/2022.
//

#ifndef GAME_GSSETTING_H
#define GAME_GSSETTING_H

#include "GameStateMachine.h"
#include "GameStateBase.h"
#include "../GameObject/GameButton.h"

class GSSetting : public GameStateBase {
public:
    GSSetting();
    virtual ~GSSetting();

    void exit();

    void pause();

    void resume();

    void init();

    void update(float deltaTime);

    void render(RenderWindow* window);

private:
    Sprite m_Background;
    Text m_Title;
    list<GameButton*> m_ListBtn;
};


#endif //GAME_GSSETTING_H
