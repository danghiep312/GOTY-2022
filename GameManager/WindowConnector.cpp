//
// Created by hiepd on 1/20/2022.
//

#include "WindowConnector.h"

WindowConnector::WindowConnector() {
    m_Window = nullptr;
}

void WindowConnector::setWindow(RenderWindow *window) {
    m_Window = window;
}

RenderWindow *WindowConnector::getWindow() {
    return m_Window;
}
