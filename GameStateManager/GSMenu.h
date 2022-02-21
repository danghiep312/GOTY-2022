//
// Created by hiepd on 1/26/2022.
//

#ifndef GAME_GSMENU_H
#define GAME_GSMENU_H

#include "GameStateBase.h"
#include "../GameObject/GameButton.h"

class GSMenu : public GameStateBase{
public:
    GSMenu();
    ~GSMenu();

    void exit();

    void pause();

    void resume();

    void init();

    void update(float deltaTime);

    void render(RenderWindow* window);

private:
    Sprite m_Background;
    list<GameButton*> m_ListBtn;
    Text m_GameTitle;
};


#endif //GAME_GSMENU_H
