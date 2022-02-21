//
// Created by hiepd on 1/25/2022.
//

#include "Engine.h"

void Engine::input() {
    Event event;
    while (m_Window->pollEvent(event)) {
        if (event.type == Event::Closed) {
            m_Window->close();
        }
    }
}