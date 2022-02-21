//
// Created by hiepd on 1/28/2022.
//

#include "PSAttack.h"

PSAttack::PSAttack(IPlayer *player) {
    m_Player = player;
    //printf("Left attack\n");
}

void PSAttack::init() {
    m_Animation = new Animation(*DATA->getTexture("Character/Attack"), Vector2i(4, 1), 0.1f);
    m_Animation->setScale(m_Player->getFactorScale());
}

void PSAttack::update(float deltaTime) {
    if (m_Player->getCcw()) {
        m_Animation->setScale(fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }
    else {
        m_Animation->setScale(-fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }
    if (m_Animation->play(deltaTime)) {
        if (m_Player->getCcw()) {
            m_Player->getDamageZone()->setPosition(m_Player->getHitbox()->getPosition().x - 10.f, m_Player->getHitbox()->getPosition().y + 10.f);
        }
        else {
            m_Player->getDamageZone()->setPosition(m_Player->getHitbox()->getPosition().x + 10.f, m_Player->getHitbox()->getPosition().y + 10.f);
        }
        m_Player->changeNextState(IDLE);
    }
    m_Animation->setPosition(m_Player->getHitbox()->getPosition());

    if (m_Player->getHealth() <= 0) {
        m_Player->changeNextState(DEATH);
    }
}

void PSAttack::render(RenderWindow *window) {
    window->draw(*m_Animation);

}

void PSAttack::reset() {
    m_Animation->reset();
}
