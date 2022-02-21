//
// Created by hiepd on 2/13/2022.
//

#ifndef GAME_MIDLE_H
#define GAME_MIDLE_H


#include "IMState.h"
#include "IMushroom.h"
#include "../Component/Animation.h"
#include "../../GameManager/PlayerConnector.h"


class MIdle : public IMState {
public:
    MIdle(IMushroom* mushroom);

    void init();

    void update(float deltaTime);

    void render(RenderWindow* window);

    void reset();

private:

    IMushroom* m_Mushroom;

    Animation* m_Animation;
};


#endif //GAME_MIDLE_H
