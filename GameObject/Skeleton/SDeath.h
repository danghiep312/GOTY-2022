//
// Created by hiepd on 2/8/2022.
//

#ifndef GAME_SDEATH_H
#define GAME_SDEATH_H


#include "ISState.h"
#include "ISkeleton.h"
#include "../Component/Animation.h"

class SDeath : public ISState {
public:
    SDeath(ISkeleton* skeleton);

    void init();

    void update(float deltaTime);

    void render(RenderWindow* window);

    void reset();

private:

    ISkeleton* m_Skeleton;

    Animation* m_Animation;
};


#endif //GAME_SDEATH_H
