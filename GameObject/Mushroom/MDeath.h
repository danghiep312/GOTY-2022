//
// Created by hiepd on 2/13/2022.
//

#ifndef GAME_MDEATH_H
#define GAME_MDEATH_H

#include "IMState.h"
#include "IMushroom.h"
#include "../Component/Animation.h"

class MDeath : public IMState {
public:
    MDeath(IMushroom* mushroom);

    void init();

    void update(float deltaTime);

    void render(RenderWindow* window);

    void reset();

private:

    IMushroom* m_Mushroom;

    Animation* m_Animation;
};


#endif //GAME_MDEATH_H
