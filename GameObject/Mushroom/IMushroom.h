//
// Created by hiepd on 2/13/2022.
//

#ifndef GAME_IMUSHROOM_H
#define GAME_IMUSHROOM_H

#include "IMState.h"
#include "../Component/Hitbox.h"
#include "../../GameManager/PlayerConnector.h"

class IMushroom {
public:
    virtual void changeNextState(IMState::STATE nextState) = 0;
    virtual Hitbox* getHitbox() = 0;

    virtual Hitbox* getDamageZone() = 0;

    virtual Hitbox* getAttackZone() = 0;

    void setCcw(bool ccw);
    bool getCcw();

    int getHealth();

    void takeHit();

    Vector2f getFactorScale();

    void setStartPoint(Vector2f startPoint);

    bool isStop();

    void setStop(bool mStop);

protected:

    bool m_Ccw;

    Vector2f m_FactorScale;

    int m_Health;

    Vector2f m_StartPoint;

    bool m_Stop;
};


#endif //GAME_IMUSHROOM_H
