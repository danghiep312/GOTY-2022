//
// Created by hiepd on 2/13/2022.
//

#ifndef GAME_MAPCONNECTOR_H
#define GAME_MAPCONNECTOR_H

#include "Singleton.h"
#include "ResourceManager.h"
#include "../GameObject/TileMap/MapManager.h"

#define MConnect MapConnector::getInstance()

class MapConnector : public Singleton<MapConnector>{
public:
    MapConnector();

    void setMapConnector(MapManager* map);

    MapManager* getMap();

private:

    MapManager* m_Map;
};


#endif //GAME_MAPCONNECTOR_H
