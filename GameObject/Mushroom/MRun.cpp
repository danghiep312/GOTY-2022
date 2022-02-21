//
// Created by hiepd on 2/13/2022.
//

#include "MRun.h"

MRun::MRun(IMushroom *mushroom) {
    m_Mushroom = mushroom;
}

void MRun::init() {
    m_Animation = new Animation(*DATA->getTexture("Mushroom/Run"), Vector2i(8, 1), 0.1f);
}

void MRun::update(float deltaTime) {
    m_Animation->update(deltaTime);
    float factor = PConnect->getPlayer()->getHitbox()->getPosition().y > m_Mushroom->getHitbox()->getPosition().y ? 1 : -1;
    if (PConnect->getPlayer()->getHitbox()->getPosition().x < m_Mushroom->getHitbox()->getPosition().x) {
        m_Mushroom->setCcw(false);
        m_Mushroom->getHitbox()->move(-min(m_Mushroom->getHitbox()->getSpeed().x, fabs(m_Mushroom->getHitbox()->getPosition().x - PConnect->getPlayer()->getHitbox()->getPosition().x)) * deltaTime,
                                    factor * min(m_Mushroom->getHitbox()->getSpeed().y, fabs(m_Mushroom->getHitbox()->getPosition().y - PConnect->getPlayer()->getHitbox()->getPosition().y)) * deltaTime);

        m_Mushroom->getDamageZone()->setPosition(m_Mushroom->getHitbox()->getPosition() + Vector2f(-m_Mushroom->getHitbox()->getSize().x / 2 - m_Mushroom->getDamageZone()->getSize().x / 2 + 5.f, 10));
    }

    if (PConnect->getPlayer()->getHitbox()->getPosition().x > m_Mushroom->getHitbox()->getPosition().x) {
        m_Mushroom->setCcw(true);
        m_Mushroom->getHitbox()->move(min(m_Mushroom->getHitbox()->getSpeed().x, fabs(m_Mushroom->getHitbox()->getPosition().x - PConnect->getPlayer()->getHitbox()->getPosition().x)) * deltaTime,
                                    factor * min(m_Mushroom->getHitbox()->getSpeed().y, fabs(m_Mushroom->getHitbox()->getPosition().y - PConnect->getPlayer()->getHitbox()->getPosition().y)) * deltaTime);

        m_Mushroom->getDamageZone()->setPosition(m_Mushroom->getHitbox()->getPosition() + Vector2f(m_Mushroom->getHitbox()->getSize().x / 2 + m_Mushroom->getDamageZone()->getSize().x / 2 - 5.f, 10));

    }

    if (m_Mushroom->getCcw()) {
        m_Animation->setScale(fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }
    else {
        m_Animation->setScale(-fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }

    if (PConnect->getPlayer()->getHitbox()->getGlobalBounds().intersects(m_Mushroom->getDamageZone()->getGlobalBounds())) {
        m_Mushroom->changeNextState(ATTACK);
    }

    if (!PConnect->getPlayer()->getHitbox()->getGlobalBounds().intersects(m_Mushroom->getAttackZone()->getGlobalBounds())) {
        m_Mushroom->changeNextState(IDLE);
    }

    if (!m_Mushroom->getHealth()) {
        m_Mushroom->changeNextState(DEATH);
    }

    m_Animation->setPosition(m_Mushroom->getHitbox()->getPosition());
    m_Mushroom->getAttackZone()->setPosition(m_Mushroom->getHitbox()->getPosition());
}

void MRun::render(RenderWindow *window) {
    window->draw(*m_Animation);
}

void MRun::reset() {
    m_Animation->reset();
}