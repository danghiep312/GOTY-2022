//
// Created by hiepd on 1/28/2022.
//

#ifndef GAME_IPLAYER_H
#define GAME_IPLAYER_H

#include "IPState.h"
#include "../Component/Hitbox.h"
#include "../../GameManager/MapConnector.h"

class IPlayer {
public:
    virtual void changeNextState(IPState::STATE nextState) = 0;
    virtual Hitbox* getHitbox() = 0;

    virtual Hitbox* getDamageZone() = 0;

    virtual bool isBlocking() = 0;

    void setCcw(bool ccw);
    bool getCcw();

    int getHealth();

    void takeHit();

    Vector2f getFactorScale();

protected:

    bool m_Ccw;

    Vector2f m_FactorScale;

    int m_Health;

    Vector2f m_Position;

};


#endif //GAME_IPLAYER_H
