//
// Created by hiepd on 1/25/2022.
//

#ifndef GAME_GAMESTATEBASE_H
#define GAME_GAMESTATEBASE_H

#include "../GameManager/ResourceManager.h"
#include "GameStateMachine.h"
#include "../GameObject/GameButton.h"
#include "../GameManager/PlayerConnector.h"
#include "../GameManager/ScoreManager.h"

using namespace sf;
using namespace std;

class GameStateBase {
public:
    GameStateBase();

    virtual ~GameStateBase();

    virtual void exit() = 0;
    virtual void resume() = 0;
    virtual void pause() = 0;

    virtual void init() = 0;
    virtual void update(float deltaTime) = 0;
    virtual void render(RenderWindow* window) = 0;

    static GameStateBase* createState(StateTypes st);
};


#endif //GAME_GAMESTATEBASE_H
