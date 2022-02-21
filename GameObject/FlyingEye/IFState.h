//
// Created by hiepd on 2/16/2022.
//

#ifndef GAME_IFSTATE_H
#define GAME_IFSTATE_H


#include "../../GameManager/ResourceManager.h"

class IFState {
public:
    enum STATE {
        IDLE,
        ATTACK,
        RUN,
        DEATH,
        SNULL,
    };

    virtual void init() = 0;

    virtual void update(float deltaTime) = 0;

    virtual void render(RenderWindow* window) = 0;

    virtual void reset() = 0;
};

#endif //GAME_IFSTATE_H
