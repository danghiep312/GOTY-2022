//
// Created by hiepd on 2/5/2022.
//

#include "PSDeath.h"

PSDeath::PSDeath(IPlayer *player) {
    m_Player = player;
}

void PSDeath::init() {
    m_Animation = new Animation(*DATA->getTexture("Character/Death"), Vector2i (4, 1), 0.2f);
    m_Animation->setModeEndFrame(true);
    m_Animation->scale(m_Player->getFactorScale());
}

void PSDeath::update(float deltaTime) {
    m_Animation->update(deltaTime);

    m_Animation->setPosition(m_Player->getHitbox()->getPosition());

    m_Player->getHitbox()->setAlive(false);
}

void PSDeath::render(RenderWindow *window) {
    window->draw(*m_Animation);
}

void PSDeath::reset() {
    m_Animation->reset();
}
