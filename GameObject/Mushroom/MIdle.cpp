//
// Created by hiepd on 2/13/2022.
//

#include "MIdle.h"


MIdle::MIdle(IMushroom *mushroom) {
    m_Mushroom = mushroom;

}

void MIdle::init() {
    m_Animation = new Animation(*DATA->getTexture("Mushroom/Idle"), Vector2i (4, 1), 0.1f);
}

void MIdle::update(float deltaTime) {
    m_Animation->update(deltaTime);

    if (PConnect->getPlayer()->getHitbox()->getGlobalBounds().intersects(m_Mushroom->getAttackZone()->getGlobalBounds())) {
        m_Mushroom->changeNextState(RUN);
    }
    if (PConnect->getPlayer()->getHitbox()->getGlobalBounds().intersects(m_Mushroom->getDamageZone()->getGlobalBounds())) {
        m_Mushroom->changeNextState(ATTACK);
    }

    if (m_Mushroom->getCcw()) {
        m_Animation->setScale(fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }
    else {
        m_Animation->setScale(-fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }

    if (!m_Mushroom->getHealth()) {
        m_Mushroom->changeNextState(DEATH);
    }

    m_Animation->setPosition(m_Mushroom->getHitbox()->getPosition());
}

void MIdle::render(RenderWindow *window) {
    window->draw(*m_Animation);
}

void MIdle::reset() {
    m_Animation->reset();
}