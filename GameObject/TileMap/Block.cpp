//
// Created by hiepd on 2/4/2022.
//

#include "Block.h"

Vector2i Block::TileSize = Vector2i(32, 32);

BLOCKTYPES Block::getSpec() {
    return m_Type;
}

void Block::setType(BLOCKTYPES type) {
    m_Type = type;
}

void Block::loadSprite(int id) {
    string filename = "Maps/Map_" + to_string(id);

    this->setTexture(*DATA->getTexture(filename));
}

Block::Block() {
    m_Hitbox = new Hitbox(TileSize);
}

Hitbox *Block::getHitBox() {
    return m_Hitbox;
}

Vector2i Block::getTileSize() {
    return TileSize;
}
