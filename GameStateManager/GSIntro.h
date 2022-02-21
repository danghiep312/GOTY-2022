//
// Created by hiepd on 1/25/2022.
//

#ifndef GAME_GSINTRO_H
#define GAME_GSINTRO_H

#include "GameStateBase.h"
#include "GameStateMachine.h"


class GSIntro : public GameStateBase {
public:
    GSIntro();
    virtual ~GSIntro();

    void exit();

    void pause();

    void resume();

    void init();

    void update(float deltaTime);

    void render(RenderWindow* window);

private:
    Sprite m_Sprite;
    float m_CurrentTime;
};


#endif //GAME_GSINTRO_H
