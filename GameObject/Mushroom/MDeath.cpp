//
// Created by hiepd on 2/13/2022.
//

#include "MDeath.h"

MDeath::MDeath(IMushroom *mushroom) {
    m_Mushroom = mushroom;
}

void MDeath::init() {
    m_Animation = new Animation(*DATA->getTexture("Mushroom/Death"), Vector2i (4, 1), 0.1f);
    m_Animation->setModeEndFrame(true);
}

void MDeath::update(float deltaTime) {
    m_Animation->update(deltaTime);
    m_Mushroom->getHitbox()->setAlive(false);
    if (m_Mushroom->getCcw()) {
        m_Animation->setScale(fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }
    else {
        m_Animation->setScale(-fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }

    m_Animation->setPosition(m_Mushroom->getHitbox()->getPosition());
}

void MDeath::render(RenderWindow *window) {
    window->draw(*m_Animation);
}

void MDeath::reset() {
    m_Animation->reset();
}
