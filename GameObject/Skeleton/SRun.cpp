//
// Created by hiepd on 2/8/2022.
//

#include "SRun.h"

SRun::SRun(ISkeleton *skeleton) {
    m_Skeleton = skeleton;
}

void SRun::init() {
    m_Animation = new Animation(*DATA->getTexture("Skeleton/Run"), Vector2i(4, 1), 0.1f);
}

void SRun::update(float deltaTime) {
    m_Animation->update(deltaTime);
    float factor = PConnect->getPlayer()->getHitbox()->getPosition().y > m_Skeleton->getHitbox()->getPosition().y ? 1 : -1;
    if (PConnect->getPlayer()->getHitbox()->getPosition().x < m_Skeleton->getHitbox()->getPosition().x) {
        m_Skeleton->setCcw(false);
        m_Skeleton->getHitbox()->move(-min(m_Skeleton->getHitbox()->getSpeed().x, fabs(m_Skeleton->getHitbox()->getPosition().x - PConnect->getPlayer()->getHitbox()->getPosition().x)) * deltaTime,
                       factor * min(m_Skeleton->getHitbox()->getSpeed().y, fabs(m_Skeleton->getHitbox()->getPosition().y - PConnect->getPlayer()->getHitbox()->getPosition().y)) * deltaTime);

        m_Skeleton->getDamageZone()->setPosition(m_Skeleton->getHitbox()->getPosition() + Vector2f (- m_Skeleton->getDamageZone()->getSize().x - m_Skeleton->getHitbox()->getSize().x / 2, -m_Skeleton->getDamageZone()->getSize().y / 2));
    }

    if (PConnect->getPlayer()->getHitbox()->getPosition().x > m_Skeleton->getHitbox()->getPosition().x) {
        m_Skeleton->setCcw(true);
        m_Skeleton->getHitbox()->move(min(m_Skeleton->getHitbox()->getSpeed().x, fabs(m_Skeleton->getHitbox()->getPosition().x - PConnect->getPlayer()->getHitbox()->getPosition().x)) * deltaTime,
                       factor * min(m_Skeleton->getHitbox()->getSpeed().y, fabs(m_Skeleton->getHitbox()->getPosition().y - PConnect->getPlayer()->getHitbox()->getPosition().y)) * deltaTime);

        m_Skeleton->getDamageZone()->setPosition(m_Skeleton->getHitbox()->getPosition() + Vector2f (m_Skeleton->getHitbox()->getSize().x / 2, -m_Skeleton->getDamageZone()->getSize().y / 2));
    }

    if (m_Skeleton->getCcw()) {
        m_Animation->setScale(fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }
    else {
        m_Animation->setScale(-fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }

    if (PConnect->getPlayer()->getHitbox()->getGlobalBounds().intersects(m_Skeleton->getDamageZone()->getGlobalBounds())) {
        m_Skeleton->changeNextState(ATTACK);
    }

    if (!PConnect->getPlayer()->getHitbox()->getGlobalBounds().intersects(m_Skeleton->getAttackZone()->getGlobalBounds())) {
        m_Skeleton->changeNextState(IDLE);
    }

    if (!m_Skeleton->getHealth()) {
        m_Skeleton->changeNextState(DEATH);
    }

    m_Animation->setPosition(m_Skeleton->getHitbox()->getPosition());
    m_Skeleton->getAttackZone()->setPosition(m_Skeleton->getHitbox()->getPosition());
}

void SRun::render(RenderWindow *window) {
    window->draw(*m_Animation);
}

void SRun::reset() {
    m_Animation->reset();
}
