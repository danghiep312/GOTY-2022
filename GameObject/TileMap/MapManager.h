//
// Created by hiepd on 2/4/2022.
//

#ifndef GAME_MAPMANAGER_H
#define GAME_MAPMANAGER_H

#include "SFML/Graphics.hpp"
#include "../../GameManager/Singleton.h"
#include "../../GameManager/ResourceManager.h"
#include "Block.h"

class MapManager {
public:
    MapManager();
    ~MapManager();

    void init();

    void update(float deltaTime);

    void render(RenderWindow* window);

    Vector2f getCenter();

    Vector2i getMapSize();

    Texture getTexture();
private:

    Vector2i m_MapSize;

    Vector2i m_TileNum;

    void loadMap();

    vector<vector<Block*>>* m_Map;

    vector<vector<int>> *m_IntMap;

    Sprite m_SpriteGrass;

    Sprite m_SpriteWall;

    Texture m_TextureGrass;

    Texture m_TextureWall;
};


#endif //GAME_MAPMANAGER_H
