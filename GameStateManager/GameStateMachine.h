//
// Created by hiepd on 1/25/2022.
//

#ifndef GAME_GAMESTATEMACHINE_H
#define GAME_GAMESTATEMACHINE_H

#include "../GameManager/Singleton.h"
#include <stack>

using namespace std;
#define GSM GameStateMachine::getInstance()

class GameStateBase;

enum StateTypes {
    INVALID = 0,
    INTRO,
    MENU,
    PLAY,
    SETTING,
    ABOUT,
    HIGHSCORE,
    END,
};

class GameStateMachine : public Singleton<GameStateMachine> {
public:
    GameStateMachine();
    ~GameStateMachine();
    void changeState(GameStateBase* state);
    void changeState(StateTypes st);

    void pushState(StateTypes st);
    void popState();

    void performStateChange();

    GameStateBase* getCurrentState() const;

    GameStateBase* getNextState() const;

    bool isNeedChangeState();

    bool hasState();
private:
    stack<GameStateBase*> m_StateStack;
    GameStateBase* m_CurrentState;
    GameStateBase* m_nextState;
};

#endif //GAME_GAMESTATEMACHINE_H
