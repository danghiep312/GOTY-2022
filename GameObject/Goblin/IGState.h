//
// Created by hiepd on 2/10/2022.
//

#ifndef GAME_IGSTATE_H
#define GAME_IGSTATE_H

#include "../../GameManager/ResourceManager.h"

class IGState {
public:
    enum STATE {
        IDLE,
        RUN,
        ATTACK,
        DEATH,
        SNULL,
    };

    virtual void init() = 0;

    virtual void update(float deltaTime) = 0;

    virtual void render(RenderWindow* window) = 0;

    virtual void reset() = 0;
};


#endif //GAME_IGSTATE_H
