//
// Created by hiepd on 2/10/2022.
//

#include "GIdle.h"

GIdle::GIdle(IGoblin *goblin) {
    m_Goblin = goblin;

}

void GIdle::init() {
    m_Animation = new Animation(*DATA->getTexture("Goblin/Idle"), Vector2i (4, 1), 0.1f);
}

void GIdle::update(float deltaTime) {
    m_Animation->update(deltaTime);

    if (PConnect->getPlayer()->getHitbox()->getGlobalBounds().intersects(m_Goblin->getAttackZone()->getGlobalBounds())) {
        m_Goblin->changeNextState(RUN);
    }
    if (PConnect->getPlayer()->getHitbox()->getGlobalBounds().intersects(m_Goblin->getDamageZone()->getGlobalBounds())) {
        m_Goblin->changeNextState(ATTACK);
    }

    if (m_Goblin->getCcw()) {
        m_Animation->setScale(fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }
    else {
        m_Animation->setScale(-fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }

    if (!m_Goblin->getHealth()) {
        m_Goblin->changeNextState(DEATH);
    }

    m_Animation->setPosition(m_Goblin->getHitbox()->getPosition());
}

void GIdle::render(RenderWindow *window) {
    window->draw(*m_Animation);
}

void GIdle::reset() {
    m_Animation->reset();
}
