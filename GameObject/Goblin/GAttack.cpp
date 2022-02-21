//
// Created by hiepd on 2/10/2022.
//

#include "GAttack.h"

GAttack::GAttack(IGoblin *goblin) {
    m_Goblin = goblin;
}

void GAttack::init() {
    m_Animation = new Animation(*DATA->getTexture("Goblin/Attack"), Vector2i(8, 1), 0.1f);
}

void GAttack::update(float deltaTime) {
    if (m_Goblin->getCcw()) {
        m_Animation->setScale(fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    } else {
        m_Animation->setScale(-fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }
    m_Animation->setPosition(m_Goblin->getHitbox()->getPosition());

    if (!m_Goblin->getHealth()) {
        m_Goblin->changeNextState(DEATH);
    }

    if (m_Animation->play(deltaTime)) {
        m_Goblin->changeNextState(IDLE);
        if (PConnect->getPlayer()->getHitbox()->getGlobalBounds().intersects(m_Goblin->getDamageZone()->getGlobalBounds())) {
            if (!PConnect->getPlayer()->isBlocking()) {
                PConnect->getPlayer()->takeHit();
            }
        }
    }


}

void GAttack::render(RenderWindow *window) {
    window->draw(*m_Animation);
}

void GAttack::reset() {
    m_Animation->reset();
}
