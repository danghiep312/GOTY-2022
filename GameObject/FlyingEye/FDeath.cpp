//
// Created by hiepd on 2/16/2022.
//

#include "FDeath.h"

FDeath::FDeath(IFlyingEye *flyingEye) {
    m_FlyingEye = flyingEye;
}

void FDeath::init() {
    m_Animation = new Animation(*DATA->getTexture("FlyingEye/Death"), Vector2i(4, 1), 0.1f);
    m_Animation->setModeEndFrame(true);
}

void FDeath::update(float deltaTime) {
    m_Animation->update(deltaTime);
    m_FlyingEye->getHitbox()->setAlive(false);
    if (m_FlyingEye->getCcw()) {
        m_Animation->setScale(fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }
    else {
        m_Animation->setScale(-fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }

    m_Animation->setPosition(m_FlyingEye->getHitbox()->getPosition());
}

void FDeath::render(RenderWindow *window) {
    window->draw(*m_Animation);
}

void FDeath::reset() {
    m_Animation->reset();
}