//
// Created by hiepd on 2/5/2022.
//

#ifndef GAME_PSDEATH_H
#define GAME_PSDEATH_H

#include "IPState.h"
#include "IPlayer.h"
#include "../Component/Animation.h"

class PSDeath : public IPState {
public:
    PSDeath(IPlayer* player);

    void init();

    void update(float deltaTime);

    void render(RenderWindow* window);

    void reset();

private:

    IPlayer* m_Player;

    Animation* m_Animation;
};


#endif //GAME_PSDEATH_H
