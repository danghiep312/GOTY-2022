//
// Created by hiepd on 2/4/2022.
//

#ifndef GAME_BLOCK_H
#define GAME_BLOCK_H

#include "../../GameManager/ResourceManager.h"
#include "../Component/Hitbox.h"

enum BLOCKTYPES {
    WALL,
    GRASS,
};

class Block : public Sprite {
public:
    Block();

    BLOCKTYPES getSpec();

    void setType(BLOCKTYPES type);

    void loadSprite(int id);

    Hitbox* getHitBox();

    static Vector2i getTileSize();

    static Vector2i TileSize;

private:

    BLOCKTYPES m_Type;

    Hitbox* m_Hitbox;


};


#endif //GAME_BLOCK_H
