//
// Created by hiepd on 1/20/2022.
//

#ifndef GAME_WINDOWCONNECTOR_H
#define GAME_WINDOWCONNECTOR_H

#include <SFML/Graphics.hpp>
#include "Singleton.h"
using namespace sf;

#define WConnect WindowConnector::getInstance()

class WindowConnector :public Singleton<WindowConnector> {
public:
    WindowConnector();

    void setWindow(RenderWindow* window);

    RenderWindow* getWindow();

private:
    RenderWindow* m_Window;
};


#endif //GAME_WINDOWCONNECTOR_H
