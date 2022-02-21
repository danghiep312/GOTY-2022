//
// Created by hiepd on 1/28/2022.
//

#ifndef GAME_PSIDLE_H
#define GAME_PSIDLE_H

#include "IPState.h"
#include "IPlayer.h"
#include "../Component/Animation.h"

class PSIdle : public IPState {
public:
    PSIdle(IPlayer* player);

    void init();

    void update(float deltaTime);

    void render(RenderWindow* window);

    void reset();

private:

    IPlayer* m_Player;

    Animation* m_Animation;
};


#endif //GAME_PSIDLE_H
