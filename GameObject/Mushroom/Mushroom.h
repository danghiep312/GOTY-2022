//
// Created by hiepd on 2/13/2022.
//

#ifndef GAME_MUSHROOM_H
#define GAME_MUSHROOM_H

#include "../Component/Animation.h"
#include "IMState.h"
#include "IMushroom.h"
#include "MIdle.h"
#include "MRun.h"
#include "MAttack.h"
#include "MDeath.h"

class Mushroom : public IMushroom {
public:
    Mushroom();
    ~Mushroom();

    void changeNextState(IMState::STATE nextState);

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

    IMState::STATE m_NextState;

    IMState* m_CurrentState;
    IMState* m_IdleState;
    IMState* m_RunState;
    IMState* m_AttackState;
    IMState* m_DeathState;
};

#endif //GAME_MUSHROOM_H
