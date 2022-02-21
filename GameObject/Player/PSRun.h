//
// Created by hiepd on 1/30/2022.
//

#ifndef GAME_PSRUN_H
#define GAME_PSRUN_H


#include "IPState.h"
#include "IPlayer.h"
#include "../Component/Animation.h"

class PSRun : public IPState {
public:
    PSRun(IPlayer* player);

    void init();

    void update(float deltaTime);

    void render(RenderWindow* window);

    void reset();

private:

    IPlayer* m_Player;

    Animation* m_Animation;
};


#endif //GAME_PSRUN_H
