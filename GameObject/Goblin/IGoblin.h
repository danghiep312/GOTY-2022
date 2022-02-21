//
// Created by hiepd on 2/10/2022.
//

#ifndef GAME_IGOBLIN_H
#define GAME_IGOBLIN_H

#include "IGState.h"
#include "../Component/Hitbox.h"
#include "../../GameManager/PlayerConnector.h"
#include "../../GameConfig.h"

class IGoblin {
public:
    virtual void changeNextState(IGState::STATE nextState) = 0;
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


#endif //GAME_IGOBLIN_H
