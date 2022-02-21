//
// Created by hiepd on 2/8/2022.
//

#ifndef GAME_ENEMYMANAGER_H
#define GAME_ENEMYMANAGER_H

#include "../GameManager/ResourceManager.h"
#include "Skeleton/Skeleton.h"
#include "Goblin/Goblin.h"
#include "Mushroom/Mushroom.h"
#include "FlyingEye/FlyingEye.h"
#include "Collision/CollisionManager.h"

class EnemyManager {
public:
    EnemyManager();
    ~EnemyManager();
    void init(CollisionManager& collisionManager);

    void update(float deltaTime);

    void render(RenderWindow* window);

    void setTimeTotal(float timeSpawn);

private:
    void spawnSkeleton();

    void spawnGoblin();

    void spawnMushroom();

    void spawnFlyingEye();

    list<Skeleton*> m_ListSkeleton;
    list<Goblin*> m_ListGoblin;
    list<Mushroom*> m_ListMushroom;
    list<FlyingEye*> m_ListFlyingEye;

    int m_EnemyNum;

    float m_TimeSpawn;

    float m_TimeTotal;

    float m_CurrentTime;
};


#endif //GAME_ENEMYMANAGER_H
