//
// Created by hiepd on 2/16/2022.
//

#ifndef GAME_FDEATH_H
#define GAME_FDEATH_H

#include "IFState.h"
#include "IFlyingEye.h"
#include "../Component/Animation.h"
#include "../../GameManager/PlayerConnector.h"

class FDeath : public IFState {
public:
    FDeath(IFlyingEye* mushroom);

    void init();

    void update(float deltaTime);

    void render(RenderWindow* window);

    void reset();

private:

    IFlyingEye* m_FlyingEye;

    Animation* m_Animation;
};


#endif //GAME_FDEATH_H
