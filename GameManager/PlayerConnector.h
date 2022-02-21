//
// Created by hiepd on 2/7/2022.
//

#ifndef GAME_PLAYERCONNECTOR_H
#define GAME_PLAYERCONNECTOR_H

#include "Singleton.h"
#include "ResourceManager.h"
#include "../GameObject/Player/IPlayer.h"

#define PConnect PlayerConnector::getInstance()

class PlayerConnector : public Singleton<PlayerConnector> {
public:
    PlayerConnector();

    void setPlayer(IPlayer* player);

    IPlayer* getPlayer();

private:
    IPlayer* m_Player;
};


#endif //GAME_PLAYERCONNECTOR_H
