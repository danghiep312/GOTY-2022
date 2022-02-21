//
// Created by hiepd on 2/8/2022.
//

#ifndef GAME_SATTACK_H
#define GAME_SATTACK_H

#include "ISState.h"
#include "ISkeleton.h"
#include "../Component/Animation.h"

class SAttack : public ISState {
public:
    SAttack(ISkeleton* skeleton);

    void init();

    void update(float deltaTime);

    void render(RenderWindow* window);

    void reset();

private:

    ISkeleton* m_Skeleton;

    Animation* m_Animation;
};


#endif //GAME_SATTACK_H
