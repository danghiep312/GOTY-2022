//
// Created by hiepd on 1/28/2022.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include "IPlayer.h"
#include "../Component/Hitbox.h"
#include "PSIdle.h"
#include "PSBlock.h"
#include "PSRun.h"
#include "PSAttack.h"
#include "PSDeath.h"

class Player : public IPlayer {
public:
    Player();
    ~Player();

    void changeNextState(IPState::STATE nextState);

    void init();

    void update(float deltaTime);

    void render(RenderWindow* window);

    Hitbox* getHitbox();

    Hitbox* getDamageZone();

    bool isBlocking();

private:
    void performStateChange();

    Hitbox* m_Hitbox;
    Hitbox* m_DamageZone;

    IPState::STATE m_NextState;

    IPState* m_CurrentState;
    IPState* m_IdleState;
    IPState* m_RunState;
    IPState* m_AttackState;
    IPState* m_BlockState;
    IPState* m_DeathState;
};


#endif //GAME_PLAYER_H
