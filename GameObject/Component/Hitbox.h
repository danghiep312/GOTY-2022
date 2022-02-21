//
// Created by hiepd on 1/28/2022.
//

#ifndef GAME_HITBOX_H
#define GAME_HITBOX_H

#include "../../GameManager/ResourceManager.h"

enum TAG {
    PLAYER,
    ENEMY,
};

class Hitbox : public RectangleShape {
public:
    Hitbox(Vector2i size);

    Vector2f getSpeed();
    void setSpeed(Vector2f speed);

    TAG getTag();
    void setTag(TAG tag);

    bool isAlive();
    void setAlive(bool alive);

private:
    Vector2f m_Speed;
    bool m_IsAlive;
    TAG m_Tag;
};


#endif //GAME_HITBOX_H
