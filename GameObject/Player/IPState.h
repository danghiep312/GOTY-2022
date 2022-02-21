//
// Created by hiepd on 1/28/2022.
//

#ifndef GAME_IPSTATE_H
#define GAME_IPSTATE_H

#include "../../GameManager/ResourceManager.h"

class IPState {
public:
    enum STATE {
        IDLE,
        RUN,
        ATTACK,
        BLOCK,
        DEATH,
        SNULL,
    };

    virtual void init() = 0;

    virtual void update(float deltaTime) = 0;

    virtual void render(RenderWindow* window) = 0;

    virtual void reset() = 0;
};


#endif //GAME_IPSTATE_H
