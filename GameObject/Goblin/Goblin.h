//
// Created by hiepd on 2/10/2022.
//

#ifndef GAME_GOBLIN_H
#define GAME_GOBLIN_H

#include "../Component/Animation.h"
#include "GIdle.h"
#include "GRun.h"
#include "GAttack.h"
#include "IGoblin.h"
#include "GDeath.h"
#include "IGState.h"

class Goblin : public IGoblin {
public:
    Goblin();
    ~Goblin();

    void changeNextState(IGState::STATE nextState);

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

    IGState::STATE m_NextState;

    IGState* m_CurrentState;
    IGState* m_IdleState;
    IGState* m_RunState;
    IGState* m_AttackState;
    IGState* m_DeathState;
};


#endif //GAME_GOBLIN_H
