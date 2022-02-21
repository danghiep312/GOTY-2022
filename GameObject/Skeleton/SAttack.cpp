//
// Created by hiepd on 2/8/2022.
//

#include "SAttack.h"

SAttack::SAttack(ISkeleton *skeleton) {
    m_Skeleton = skeleton;
}

void SAttack::init() {
    m_Animation = new Animation(*DATA->getTexture("Skeleton/Attack"), Vector2i (8, 1), 0.1f);

}

void SAttack::update(float deltaTime) {

    if (m_Skeleton->getCcw()) {
        m_Animation->setScale(fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }
    else {
        m_Animation->setScale(-fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }
    m_Animation->setPosition(m_Skeleton->getHitbox()->getPosition());

    if (!m_Skeleton->getHealth()) {
        m_Skeleton->changeNextState(DEATH);
    }

    if (m_Animation->play(deltaTime)) {
        m_Skeleton->changeNextState(IDLE);
        if (PConnect->getPlayer()->getHitbox()->getGlobalBounds().intersects(m_Skeleton->getDamageZone()->getGlobalBounds())) {
            if (!PConnect->getPlayer()->isBlocking()) {
                PConnect->getPlayer()->takeHit();
            }
        }
    }
}

void SAttack::render(RenderWindow *window) {
    window->draw(*m_Animation);
}

void SAttack::reset() {
    m_Animation->reset();
}
