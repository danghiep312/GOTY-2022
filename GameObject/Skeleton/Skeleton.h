//
// Created by hiepd on 2/2/2022.
//

#ifndef GAME_SKELETON_H
#define GAME_SKELETON_H

#include "../Component/Animation.h"
#include "SIdle.h"
#include "SRun.h"
#include "SAttack.h"
#include "SDeath.h"
#include "ISkeleton.h"
#include "ISState.h"


class Skeleton : public ISkeleton {
public:
    Skeleton();
    ~Skeleton();

    void changeNextState(ISState::STATE nextState);

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

    ISState::STATE m_NextState;

    ISState* m_CurrentState;
    ISState* m_IdleState;
    ISState* m_RunState;
    ISState* m_AttackState;
    ISState* m_DeathState;
};


#endif //GAME_SKELETON_H
