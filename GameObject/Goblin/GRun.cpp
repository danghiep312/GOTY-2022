//
// Created by hiepd on 2/10/2022.
//

#include "GRun.h"

GRun::GRun(IGoblin *goblin) {
    m_Goblin = goblin;
}

void GRun::init() {
    m_Animation = new Animation(*DATA->getTexture("Goblin/Run"), Vector2i(8, 1), 0.1f);
}

void GRun::update(float deltaTime) {
    m_Animation->update(deltaTime);
    float factor = PConnect->getPlayer()->getHitbox()->getPosition().y > m_Goblin->getHitbox()->getPosition().y ? 1 : -1;
    if (PConnect->getPlayer()->getHitbox()->getPosition().x < m_Goblin->getHitbox()->getPosition().x) {
        m_Goblin->setCcw(false);
        m_Goblin->getHitbox()->move(-min(m_Goblin->getHitbox()->getSpeed().x, fabs(m_Goblin->getHitbox()->getPosition().x - PConnect->getPlayer()->getHitbox()->getPosition().x)) * deltaTime,
                                      factor * min(m_Goblin->getHitbox()->getSpeed().y, fabs(m_Goblin->getHitbox()->getPosition().y - PConnect->getPlayer()->getHitbox()->getPosition().y)) * deltaTime);

        m_Goblin->getDamageZone()->setPosition(m_Goblin->getHitbox()->getPosition() + Vector2f(0, 10.f));
    }

    if (PConnect->getPlayer()->getHitbox()->getPosition().x > m_Goblin->getHitbox()->getPosition().x) {
        m_Goblin->setCcw(true);
        m_Goblin->getHitbox()->move(min(m_Goblin->getHitbox()->getSpeed().x, fabs(m_Goblin->getHitbox()->getPosition().x - PConnect->getPlayer()->getHitbox()->getPosition().x)) * deltaTime,
                                      factor * min(m_Goblin->getHitbox()->getSpeed().y, fabs(m_Goblin->getHitbox()->getPosition().y - PConnect->getPlayer()->getHitbox()->getPosition().y)) * deltaTime);

        m_Goblin->getDamageZone()->setPosition(m_Goblin->getHitbox()->getPosition() + Vector2f(0, 10.f));
    }

    if (m_Goblin->getCcw()) {
        m_Animation->setScale(fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }
    else {
        m_Animation->setScale(-fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }

    if (PConnect->getPlayer()->getHitbox()->getGlobalBounds().intersects(m_Goblin->getDamageZone()->getGlobalBounds())) {
        m_Goblin->changeNextState(ATTACK);
    }

    if (!PConnect->getPlayer()->getHitbox()->getGlobalBounds().intersects(m_Goblin->getAttackZone()->getGlobalBounds())) {
        m_Goblin->changeNextState(IDLE);
    }

    if (!m_Goblin->getHealth()) {
        m_Goblin->changeNextState(DEATH);
    }

    m_Animation->setPosition(m_Goblin->getHitbox()->getPosition());
    m_Goblin->getAttackZone()->setPosition(m_Goblin->getHitbox()->getPosition());
}

void GRun::render(RenderWindow *window) {
    window->draw(*m_Animation);
}

void GRun::reset() {
    m_Animation->reset();
}