//
// Created by hiepd on 2/7/2022.
//

#include "PlayerConnector.h"

PlayerConnector::PlayerConnector() {
    m_Player = nullptr;
}

void PlayerConnector::setPlayer(IPlayer *player) {
    m_Player = player;
}

IPlayer *PlayerConnector::getPlayer() {
    return m_Player;
}
