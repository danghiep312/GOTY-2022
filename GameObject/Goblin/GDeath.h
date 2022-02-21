//
// Created by hiepd on 2/10/2022.
//

#ifndef GAME_GDEATH_H
#define GAME_GDEATH_H


#include "IGState.h"
#include "IGoblin.h"
#include "../Component/Animation.h"

class GDeath : public IGState {
public:
    GDeath(IGoblin* goblin);

    void init();

    void update(float deltaTime);

    void render(RenderWindow* window);

    void reset();

private:

    IGoblin* m_Goblin;

    Animation* m_Animation;
};


#endif //GAME_GDEATH_H
