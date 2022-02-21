//
// Created by hiepd on 2/10/2022.
//

#ifndef GAME_GIDLE_H
#define GAME_GIDLE_H

#include "IGState.h"
#include "IGoblin.h"
#include "../Component/Animation.h"
#include "../../GameManager/PlayerConnector.h"


class GIdle : public IGState {
public:
    GIdle(IGoblin* goblin);

    void init();

    void update(float deltaTime);

    void render(RenderWindow* window);

    void reset();

private:

    IGoblin* m_Goblin;

    Animation* m_Animation;
};


#endif //GAME_GIDLE_H
