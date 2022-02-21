//
// Created by hiepd on 1/31/2022.
//

#include "IPlayer.h"

bool IPlayer::getCcw() {
    return m_Ccw;
}

void IPlayer::setCcw(bool ccw) {
    m_Ccw = ccw;
}

int IPlayer::getHealth() {
    return m_Health;
}

Vector2f IPlayer::getFactorScale() {
    return m_FactorScale;
}

void IPlayer::takeHit() {
    m_Health--;
}