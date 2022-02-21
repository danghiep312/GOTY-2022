//
// Created by hiepd on 1/25/2022.
//

#include "Engine.h"

void Engine::update(float deltaTime) {
    if (GameStateMachine::getInstance()->isNeedChangeState()) {
        GameStateMachine::getInstance()->performStateChange();
    }
    GameStateMachine::getInstance()->getCurrentState()->update(deltaTime);
}