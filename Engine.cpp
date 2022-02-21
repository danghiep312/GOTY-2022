//
// Created by hiepd on 1/24/2022.
//

#include "Engine.h"

Engine::Engine() {
    m_Window = new RenderWindow(VideoMode(screenWidth, screenHeight), titleGame, Style::Close);
    m_Window->setFramerateLimit(60);
    m_Window->setVerticalSyncEnabled(false);
    GameStateMachine::getInstance()->changeState(StateTypes::INTRO);
    WConnect->setWindow(m_Window);
    srand((int) time(0));
}

void Engine::run() {
    Clock clock;

    while (m_Window->isOpen()) {
        Time dt = clock.restart();
        gameTimeTotal += dt;

        float deltaTime = dt.asSeconds();

        input();
        update(deltaTime);
        draw();
    }
}

Engine::~Engine() {
    if (m_Window != nullptr) {
        delete m_Window;
    }
}
