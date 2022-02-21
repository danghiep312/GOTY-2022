//
// Created by hiepd on 2/13/2022.
//

#ifndef GAME_IMSTATE_H
#define GAME_IMSTATE_H


#include "../../GameManager/ResourceManager.h"

class IMState {
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



#endif //GAME_IMSTATE_H
