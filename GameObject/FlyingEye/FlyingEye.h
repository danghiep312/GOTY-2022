//
// Created by hiepd on 2/16/2022.
//

#ifndef GAME_FLYINGEYE_H
#define GAME_FLYINGEYE_H

#include "../Component/Animation.h"
#include "IFlyingEye.h"
#include "IFState.h"
#include "FIdle.h"
#include "FAttack.h"
#include "FDeath.h"
#include "FRun.h"

class FlyingEye : public IFlyingEye {
public:
    FlyingEye();
    ~FlyingEye();

    void changeNextState(IFState::STATE nextState);

    void init();

    void update(float deltaTime);

    void render(RenderWindow* window);

    Hitbox* getHitbox();

    Hitbox* getDamageZone();

    Hitbox* getAttackZone();

    void reset();

private:
    void performStateChange();

    Hitbox* m_Hitbox;
    Hitbox* m_DamageZone;
    Hitbox* m_AttackZone;

    IFState::STATE m_NextState;

    IFState* m_CurrentState;
    IFState* m_IdleState;
    IFState* m_RunState;
    IFState* m_AttackState;
    IFState* m_DeathState;
};


#endif //GAME_FLYINGEYE_H
