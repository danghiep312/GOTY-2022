//
// Created by hiepd on 2/16/2022.
//

#include "FRun.h"

FRun::FRun(IFlyingEye *flyingEye) {
    m_FlyingEye = flyingEye;
}

void FRun::init() {
    m_Animation = new Animation(*DATA->getTexture("FlyingEye/Idle"), Vector2i(8, 1), 0.1f);
}

void FRun::update(float deltaTime) {
    m_Animation->update(deltaTime);
    float factor = PConnect->getPlayer()->getHitbox()->getPosition().y > m_FlyingEye->getHitbox()->getPosition().y ? 1 : -1;
    if (PConnect->getPlayer()->getHitbox()->getPosition().x < m_FlyingEye->getHitbox()->getPosition().x) {
        m_FlyingEye->setCcw(false);
        m_FlyingEye->getHitbox()->move(-min(m_FlyingEye->getHitbox()->getSpeed().x, fabs(m_FlyingEye->getHitbox()->getPosition().x - PConnect->getPlayer()->getHitbox()->getPosition().x)) * deltaTime,
                                      factor * min(m_FlyingEye->getHitbox()->getSpeed().y, fabs(m_FlyingEye->getHitbox()->getPosition().y - PConnect->getPlayer()->getHitbox()->getPosition().y)) * deltaTime);

        m_FlyingEye->getDamageZone()->setPosition(m_FlyingEye->getHitbox()->getPosition() + Vector2f (-m_FlyingEye->getHitbox()->getSize().x / 2, m_FlyingEye->getHitbox()->getSize().y / 4));
    }

    if (PConnect->getPlayer()->getHitbox()->getPosition().x > m_FlyingEye->getHitbox()->getPosition().x) {
        m_FlyingEye->setCcw(true);
        m_FlyingEye->getHitbox()->move(min(m_FlyingEye->getHitbox()->getSpeed().x, fabs(m_FlyingEye->getHitbox()->getPosition().x - PConnect->getPlayer()->getHitbox()->getPosition().x)) * deltaTime,
                                      factor * min(m_FlyingEye->getHitbox()->getSpeed().y, fabs(m_FlyingEye->getHitbox()->getPosition().y - PConnect->getPlayer()->getHitbox()->getPosition().y)) * deltaTime);

        m_FlyingEye->getDamageZone()->setPosition(m_FlyingEye->getHitbox()->getPosition() + Vector2f (m_FlyingEye->getHitbox()->getSize().x / 2, m_FlyingEye->getHitbox()->getSize().y / 4));
    }

    if (m_FlyingEye->getCcw()) {
        m_Animation->setScale(fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }
    else {
        m_Animation->setScale(-fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }

    if (PConnect->getPlayer()->getHitbox()->getGlobalBounds().intersects(m_FlyingEye->getDamageZone()->getGlobalBounds())) {
        m_FlyingEye->changeNextState(ATTACK);
    }

    if (!PConnect->getPlayer()->getHitbox()->getGlobalBounds().intersects(m_FlyingEye->getAttackZone()->getGlobalBounds())) {
        m_FlyingEye->changeNextState(IDLE);
    }

    if (!m_FlyingEye->getHealth()) {
        m_FlyingEye->changeNextState(DEATH);
    }

    m_Animation->setPosition(m_FlyingEye->getHitbox()->getPosition());
    m_FlyingEye->getAttackZone()->setPosition(m_FlyingEye->getHitbox()->getPosition());
}

void FRun::render(RenderWindow *window) {
    window->draw(*m_Animation);
}

void FRun::reset() {
    m_Animation->reset();
}