//
// Created by hiepd on 2/13/2022.
//

#ifndef GAME_MATTACK_H
#define GAME_MATTACK_H

#include "IMushroom.h"
#include "IMState.h"
#include "../Component/Animation.h"

class MAttack : public IMState {
public:
    MAttack(IMushroom* goblin);

    void init();

    void update(float deltaTime);

    void render(RenderWindow* window);

    void reset();

private:

    IMushroom* m_Mushroom;

    Animation* m_Animation;
};


#endif //GAME_MATTACK_H
