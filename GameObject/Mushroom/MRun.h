//
// Created by hiepd on 2/13/2022.
//

#ifndef GAME_MRUN_H
#define GAME_MRUN_H


#include "IMState.h"
#include "IMushroom.h"
#include "../Component/Animation.h"

class MRun : public IMState {
public:
    MRun(IMushroom* mushroom);

    void init();

    void update(float deltaTime);

    void render(RenderWindow* window);

    void reset();

private:

    IMushroom* m_Mushroom;

    Animation* m_Animation;
};


#endif //GAME_MRUN_H
