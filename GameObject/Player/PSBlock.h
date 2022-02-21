//
// Created by hiepd on 1/31/2022.
//

#ifndef GAME_PSBLOCK_H
#define GAME_PSBLOCK_H


#include "IPState.h"
#include "IPlayer.h"
#include "../Component/Animation.h"

class PSBlock : public IPState {
public:
    PSBlock(IPlayer* player);

    void init();

    void update(float deltaTime);

    void render(RenderWindow* window);

    void reset();

private:

    IPlayer* m_Player;

    Animation* m_Animation;
};


#endif //GAME_PSBLOCK_H
