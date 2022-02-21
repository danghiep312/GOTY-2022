//
// Created by hiepd on 1/25/2022.
//

#include "Engine.h"

void Engine::draw() {
    m_Window->clear();
    GameStateMachine::getInstance()->getCurrentState()->render(m_Window);
    m_Window->display();
}