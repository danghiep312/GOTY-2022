//
// Created by hiepd on 2/8/2022.
//

#ifndef GAME_SIDLE_H
#define GAME_SIDLE_H

#include "ISState.h"
#include "ISkeleton.h"
#include "../Component/Animation.h"
#include "../../GameManager/PlayerConnector.h"

class SIdle : public ISState {
public:
    SIdle(ISkeleton* skeleton);

    void init();

    void update(float deltaTime);

    void render(RenderWindow* window);

    void reset();

private:

    ISkeleton* m_Skeleton;

    Animation* m_Animation;
};


#endif //GAME_SIDLE_H
