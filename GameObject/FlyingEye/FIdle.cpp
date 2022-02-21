//
// Created by hiepd on 2/16/2022.
//

#include "FIdle.h"

FIdle::FIdle(IFlyingEye *flyingEye) {
    m_FlyingEye = flyingEye;
}

void FIdle::init() {
    m_Animation = new Animation(*DATA->getTexture("FlyingEye/Idle"), Vector2i (8, 1), 0.1f);
}

void FIdle::update(float deltaTime) {
    m_Animation->update(deltaTime);

    if (PConnect->getPlayer()->getHitbox()->getGlobalBounds().intersects(m_FlyingEye->getAttackZone()->getGlobalBounds())) {
        m_FlyingEye->changeNextState(RUN);
    }
    if (PConnect->getPlayer()->getHitbox()->getGlobalBounds().intersects(m_FlyingEye->getDamageZone()->getGlobalBounds())) {
        m_FlyingEye->changeNextState(ATTACK);
    }

    if (m_FlyingEye->getCcw()) {
        m_Animation->setScale(fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }
    else {
        m_Animation->setScale(-fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }

    if (!m_FlyingEye->getHealth()) {
        m_FlyingEye->changeNextState(DEATH);
    }

    m_Animation->setPosition(m_FlyingEye->getHitbox()->getPosition());
}

void FIdle::render(RenderWindow *window) {
    window->draw(*m_Animation);
}

void FIdle::reset() {
    m_Animation->reset();
}