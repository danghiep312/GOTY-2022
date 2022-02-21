//
// Created by hiepd on 1/25/2022.
//

#include "GameStateMachine.h"
#include "GameStateBase.h"

GameStateMachine::GameStateMachine() {
    m_CurrentState = nullptr;
    m_nextState = nullptr;
}

GameStateMachine::~GameStateMachine() {
    while (!m_StateStack.empty()) {
        delete m_StateStack.top();
        m_StateStack.pop();
    }
}

void GameStateMachine::changeState(GameStateBase *state) {
    m_nextState = state;
}

void GameStateMachine::changeState(StateTypes st) {
    GameStateBase* gs = GameStateBase::createState(st);
    changeState(gs);
}

void GameStateMachine::pushState(StateTypes st) {
    GameStateBase* gs = GameStateBase::createState(st);
    if (!m_StateStack.empty()) {
        m_StateStack.top()->pause();
    }
    m_nextState = gs;
}

void GameStateMachine::popState() {
    if (!m_StateStack.empty()) {
        m_StateStack.top()->exit();
        m_StateStack.pop();
    }
    if (!m_StateStack.empty()) {
        m_StateStack.top()->resume();
    }
    m_CurrentState = m_StateStack.top();
}

void GameStateMachine::performStateChange() {
    if (m_nextState != nullptr) {
        if (!m_StateStack.empty()) {
            m_StateStack.top()->exit();
        }
        m_StateStack.push(m_nextState);
        m_StateStack.top()->init();
        m_CurrentState = m_StateStack.top();
    }
    m_nextState = nullptr;
}

GameStateBase *GameStateMachine::getCurrentState() const {
    return m_CurrentState;
}

GameStateBase *GameStateMachine::getNextState() const {
    return m_nextState;
}

bool GameStateMachine::isNeedChangeState() {
    return m_nextState != nullptr;
}

bool GameStateMachine::hasState() {
    return m_StateStack.size() > 0;
}
