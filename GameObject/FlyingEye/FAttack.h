//
// Created by hiepd on 2/16/2022.
//

#ifndef GAME_FATTACK_H
#define GAME_FATTACK_H

#include "IFState.h"
#include "IFlyingEye.h"
#include "../Component/Animation.h"
#include "../../GameManager/PlayerConnector.h"

class FAttack : public IFState {
public:
    FAttack(IFlyingEye* mushroom);

    void init();

    void update(float deltaTime);

    void render(RenderWindow* window);

    void reset();

private:

    IFlyingEye* m_FlyingEye;

    Animation* m_Animation;
};
#endif //GAME_FATTACK_H
