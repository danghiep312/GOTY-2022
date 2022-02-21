//
// Created by hiepd on 1/24/2022.
//

#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <SFML/Graphics.hpp>
#include "GameConfig.h"
#include "GameManager/ResourceManager.h"
#include "GameStateManager/GameStateMachine.h"
#include "GameStateManager/GameStateBase.h"
#include "GameManager/WindowConnector.h"
#include "GameObject/TileMap/MapManager.h"

using namespace sf;

class Engine {
public:
    Engine();

    ~Engine();

    void run();
private:
    void input();

    void update(float deltaTime);

    void draw();

    RenderWindow* m_Window;

    Time gameTimeTotal;
};


#endif //GAME_ENGINE_H
