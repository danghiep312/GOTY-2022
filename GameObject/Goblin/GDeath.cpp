//
// Created by hiepd on 2/10/2022.
//

#include "GDeath.h"

GDeath::GDeath(IGoblin *goblin) {
    m_Goblin = goblin;
}

void GDeath::init() {
    m_Animation = new Animation(*DATA->getTexture("Goblin/Death"), Vector2i (4, 1), 0.1f);
    m_Animation->setModeEndFrame(true);
}

void GDeath::update(float deltaTime) {
    m_Animation->update(deltaTime);
    m_Goblin->getHitbox()->setAlive(false);
    if (m_Goblin->getCcw()) {
        m_Animation->setScale(fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }
    else {
        m_Animation->setScale(-fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }

    m_Animation->setPosition(m_Goblin->getHitbox()->getPosition());
}

void GDeath::render(RenderWindow *window) {
    window->draw(*m_Animation);
}

void GDeath::reset() {
    m_Animation->reset();
}
