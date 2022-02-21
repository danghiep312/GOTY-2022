//
// Created by hiepd on 1/28/2022.
//

#ifndef GAME_PSATTACK_H
#define GAME_PSATTACK_H


#include "IPState.h"
#include "IPlayer.h"
#include "../Component/Animation.h"

class PSAttack : public IPState {
public:
    PSAttack(IPlayer* player);

    void init();

    void update(float deltaTime);

    void render(RenderWindow* window);

    void reset();

private:

    IPlayer* m_Player;

    Animation* m_Animation;
};


#endif //GAME_PSATTACK_H
