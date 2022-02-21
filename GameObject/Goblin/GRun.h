//
// Created by hiepd on 2/10/2022.
//

#ifndef GAME_GRUN_H
#define GAME_GRUN_H


#include "IGState.h"
#include "IGoblin.h"
#include "../Component/Animation.h"

class GRun : public IGState {
public:
    GRun(IGoblin* goblin);

    void init();

    void update(float deltaTime);

    void render(RenderWindow* window);

    void reset();

private:

    IGoblin* m_Goblin;

    Animation* m_Animation;
};


#endif //GAME_GRUN_H
