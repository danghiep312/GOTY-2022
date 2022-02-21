//
// Created by hiepd on 2/16/2022.
//

#include "FAttack.h"

FAttack::FAttack(IFlyingEye *flyingEye) {
    m_FlyingEye = flyingEye;
}

void FAttack::init() {
    m_Animation = new Animation(*DATA->getTexture("FlyingEye/Attack"), Vector2i (8, 1), 0.1f);

}

void FAttack::update(float deltaTime) {

    if (m_FlyingEye->getCcw()) {
        m_Animation->setScale(fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }
    else {
        m_Animation->setScale(-fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }
    m_Animation->setPosition(m_FlyingEye->getHitbox()->getPosition());

    if (!m_FlyingEye->getHealth()) {
        m_FlyingEye->changeNextState(DEATH);
    }

    if (m_Animation->play(deltaTime)) {
        m_FlyingEye->changeNextState(IDLE);
        if (PConnect->getPlayer()->getHitbox()->getGlobalBounds().intersects(m_FlyingEye->getDamageZone()->getGlobalBounds())) {
            if (!PConnect->getPlayer()->isBlocking()) {
                PConnect->getPlayer()->takeHit();
            }
        }
    }
}

void FAttack::render(RenderWindow *window) {
    window->draw(*m_Animation);
}

void FAttack::reset() {
    m_Animation->reset();
}