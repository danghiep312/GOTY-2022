//
// Created by hiepd on 2/13/2022.
//

#include "MapConnector.h"

MapConnector::MapConnector() {
    m_Map = nullptr;
}

void MapConnector::setMapConnector(MapManager *map) {
    m_Map = map;
}

MapManager *MapConnector::getMap() {
    return m_Map;
}
