//
// Created by hiepd on 2/8/2022.
//

#include "SIdle.h"

SIdle::SIdle(ISkeleton *skeleton) {
    m_Skeleton = skeleton;
}

void SIdle::init() {
    m_Animation = new Animation(*DATA->getTexture("Skeleton/Idle"), Vector2i (4, 1), 0.1f);
}

void SIdle::update(float deltaTime) {
    m_Animation->update(deltaTime);

    if (PConnect->getPlayer()->getHitbox()->getGlobalBounds().intersects(m_Skeleton->getAttackZone()->getGlobalBounds())) {
        m_Skeleton->changeNextState(RUN);
    }
    if (PConnect->getPlayer()->getHitbox()->getGlobalBounds().intersects(m_Skeleton->getDamageZone()->getGlobalBounds())) {
        m_Skeleton->changeNextState(ATTACK);
    }

    if (m_Skeleton->getCcw()) {
        m_Animation->setScale(fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }
    else {
        m_Animation->setScale(-fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }

    if (!m_Skeleton->getHealth()) {
        m_Skeleton->changeNextState(DEATH);
    }

    m_Animation->setPosition(m_Skeleton->getHitbox()->getPosition());
}

void SIdle::render(RenderWindow *window) {
    window->draw(*m_Animation);
}

void SIdle::reset() {
    m_Animation->reset();
}
