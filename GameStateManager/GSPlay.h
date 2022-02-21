//
// Created by hiepd on 1/26/2022.
//

#ifndef GAME_GSPLAY_H
#define GAME_GSPLAY_H

#include "GameStateBase.h"
#include "GameStateMachine.h"
#include "../GameObject/HUD.h"
#include "../GameObject/Player/Player.h"
#include "../GameObject/Collision/CollisionManager.h"
#include "../GameObject/TileMap/MapManager.h"
#include "../GameObject/EnemyManager.h"

class GSPlay : public GameStateBase {
public:
    GSPlay();
    virtual ~GSPlay();

    void exit();

    void pause();

    void resume();

    void init();

    void update(float deltaTime);

    void render(RenderWindow* window);

private:
    Player* m_Player;

    CollisionManager m_CollisionManager;

    EnemyManager m_EnemyManager;

    MapManager* m_MapManager;

    float m_TimePause;

    View m_MainView;

    View m_HudView;

    HUD m_Hud;
};


#endif //GAME_GSPLAY_H
