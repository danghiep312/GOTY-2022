//
// Created by hiepd on 2/2/2022.
//

#ifndef GAME_COLLISIONMANAGER_H
#define GAME_COLLISIONMANAGER_H

#include "../Component/Hitbox.h"
#include "../Skeleton/Skeleton.h"
#include "../Goblin/Goblin.h"

class CollisionManager {
public:
    void addObj (Hitbox* hitbox);

    bool checkCollision(Hitbox* a, Hitbox* b);

    void update();

    Hitbox* searchPlayer();

private:
    list<Hitbox*> m_ListObj;
    list<Skeleton*> m_ListSkeleton;
    list<Goblin*> m_ListGoblin;
};


#endif //GAME_COLLISIONMANAGER_H
