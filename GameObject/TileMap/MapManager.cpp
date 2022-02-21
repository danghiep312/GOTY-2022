//
// Created by hiepd on 2/4/2022.
//

#include "MapManager.h"

void MapManager::loadMap() {
//    ifstream f;
//    f.open("Data/Map.txt", ios::in);
//    int value;
//
//    for (int i = 0; i < m_TileNum.y; i++)
//    {
//        for (int j = 0; j < m_TileNum.x; j++)
//        {
//            f >> value;
//            (*m_IntMap)[i][j] = value;
//        }
//    }
//
//    f.close();
//    //cout << m_TileNum.y << " " << m_TileNum.x << endl;
//    for (int i = 0; i < m_TileNum.y; i++) {
//        for (int j = 0; j < m_TileNum.x; j++) {
//            (*m_Map)[i][j]->loadSprite((*m_IntMap) [i][j]);
//            (*m_Map)[i][j]->setPosition(i * Block::TileSize.x, j * Block::TileSize.y);
//        }
//        cout << endl;
//    }
}

void MapManager::render(RenderWindow* window) {
//    for (int i = 0; i < m_TileNum.y; i++) {
//        for (int j = 0; j < m_TileNum.x; j++) {
//           window->draw(*(*m_Map)[i][j]);
//        }
//    }
    window->draw(m_SpriteGrass);
    window->draw(m_SpriteWall);
}

MapManager::MapManager() {

}

void MapManager::init() {
//    m_MapSize = Vector2i(512, 512);
//    m_TileNum = Vector2i (m_MapSize.x / Block::TileSize.x, m_MapSize.y / Block::TileSize.y);
//    m_IntMap = new vector<vector<int>> (m_TileNum.y, vector<int> (m_TileNum.x));
//    m_Map = new vector<vector<Block*>> (m_TileNum.y, vector<Block*> (m_TileNum.x));
//    for (int i = 0; i < m_TileNum.y; i++) {
//        for (int j = 0; j < m_TileNum.x; j++) {
//            (*m_Map)[i][j] = new Block();
//        }
//    }
//    loadMap();
    m_TextureGrass.loadFromFile("Data/grass.png");
    m_TextureWall.loadFromFile("Data/wall.png");
    m_SpriteGrass.setTexture(m_TextureGrass);
    m_SpriteWall.setTexture(m_TextureWall);
    m_SpriteWall.setPosition(-32.f, -64.f);
}

void MapManager::update(float deltaTime) {

}

MapManager::~MapManager() {

}

Vector2f MapManager::getCenter() {
    //return Vector2f ((float) m_MapSize.x / 2, m_MapSize.y / 2);
    return Vector2f ((Vector2f) m_TextureGrass.getSize() / 2.f);
}

Vector2i MapManager::getMapSize() {
    //return m_MapSize;

    return (Vector2i) m_TextureGrass.getSize();
}

Texture MapManager::getTexture() {
    return m_TextureGrass;
}
