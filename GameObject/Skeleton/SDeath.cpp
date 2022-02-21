//
// Created by hiepd on 2/8/2022.
//

#include "SDeath.h"

SDeath::SDeath(ISkeleton *skeleton) {
    m_Skeleton = skeleton;
}

void SDeath::init() {
    m_Animation = new Animation(*DATA->getTexture("Skeleton/Death"), Vector2i(4, 1), 0.1f);
    m_Animation->setModeEndFrame(true);
}

void SDeath::update(float deltaTime) {
    m_Animation->update(deltaTime);
    m_Skeleton->getHitbox()->setAlive(false);
    if (m_Skeleton->getCcw()) {
        m_Animation->setScale(fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }
    else {
        m_Animation->setScale(-fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }

    m_Animation->setPosition(m_Skeleton->getHitbox()->getPosition());
}

void SDeath::render(RenderWindow *window) {
    window->draw(*m_Animation);
}

void SDeath::reset() {
    m_Animation->reset();
}
