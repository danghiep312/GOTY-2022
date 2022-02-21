//
// Created by hiepd on 2/13/2022.
//

#include "MAttack.h"

MAttack::MAttack(IMushroom *mushroom) {
    m_Mushroom = mushroom;
}

void MAttack::init() {
    m_Animation = new Animation(*DATA->getTexture("Mushroom/Attack"), Vector2i(8, 1), 0.1f);
}

void MAttack::update(float deltaTime) {
    if (m_Mushroom->getCcw()) {
        m_Animation->setScale(fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    } else {
        m_Animation->setScale(-fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }
    m_Animation->setPosition(m_Mushroom->getHitbox()->getPosition());

    if (!m_Mushroom->getHealth()) {
        m_Mushroom->changeNextState(DEATH);
    }

    if (m_Animation->play(deltaTime)) {
        m_Mushroom->changeNextState(IDLE);
        if (PConnect->getPlayer()->getHitbox()->getGlobalBounds().intersects(m_Mushroom->getDamageZone()->getGlobalBounds())) {
            if (!PConnect->getPlayer()->isBlocking()) {
                PConnect->getPlayer()->takeHit();
            }
        }
    }


}

void MAttack::render(RenderWindow *window) {
    window->draw(*m_Animation);
}

void MAttack::reset() {
    m_Animation->reset();
}
