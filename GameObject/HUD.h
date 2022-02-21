//
// Created by hiepd on 2/17/2022.
//

#ifndef GAME_HUD_H
#define GAME_HUD_H

#include "SFML/Graphics.hpp"
#include "sstream"
#include "../GameManager/ResourceManager.h"
#include "../GameManager/PlayerConnector.h"

using namespace sf;

class HUD {
public:
    void init();

    void update(float deltaTime);

    void render(RenderWindow* window);

    float getGameTime();

    void setStop(bool stop);

    bool getStop();

private:
    bool m_Stop;

    float m_GameTime;

    Text m_TimeText;

    Text m_Hp;
};


#endif //GAME_HUD_H
