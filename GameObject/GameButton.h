//
// Created by hiepd on 1/26/2022.
//

#ifndef GAME_GAMEBUTTON_H
#define GAME_GAMEBUTTON_H

#include "SFML/Graphics.hpp"
#include "../GameManager/WindowConnector.h"
#include "../GameManager/ResourceManager.h"

using namespace sf;
using namespace std;

class GameButton : public RectangleShape {
public:
    GameButton();

    void init(string name);
    void update(float deltaTime);
    void render(RenderWindow* window);

    void handleTouchEvent();

    bool isPressing();

    void setOnClick(void (*Func)());

private:
    void (*m_btnClickFunc) ();

    bool m_IsPressing;
};


#endif //GAME_GAMEBUTTON_H
