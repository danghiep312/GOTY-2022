//
// Created by hiepd on 1/28/2022.
//

#include "PSIdle.h"

PSIdle::PSIdle(IPlayer *player) {
    m_Player = player;
}

void PSIdle::init() {
    m_Animation = new Animation(*DATA->getTexture("Character/Idle"), Vector2i(4, 1), 0.1f);
    m_Animation->setScale(m_Player->getFactorScale());
}

void PSIdle::update(float deltaTime) {
    m_Animation->update(deltaTime);

    if (Keyboard::isKeyPressed(Keyboard::W)) {
        m_Player->changeNextState(RUN);
    }
    if (Keyboard::isKeyPressed(Keyboard::S)) {
        m_Player->changeNextState(RUN);
    }
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        m_Player->changeNextState(RUN);
        m_Player->setCcw(true);
    }
    if (Keyboard::isKeyPressed(Keyboard::D)) {
        m_Player->setCcw(false);
        m_Player->changeNextState(RUN);
    }

    if (Keyboard::isKeyPressed(Keyboard::Q)) {
        m_Player->setCcw(true);
        m_Player->changeNextState(BLOCK);
    }

    if (Keyboard::isKeyPressed(Keyboard::E)) {
        m_Player->setCcw(false);
        m_Player->changeNextState(BLOCK);
    }

    if (Keyboard::isKeyPressed(Keyboard::Space)) {
        m_Player->changeNextState(ATTACK);
    }
    m_Player->getDamageZone()->setPosition(2000.f, 2000.f);
    m_Animation->setPosition(m_Player->getHitbox()->getPosition());
    if (m_Player->getCcw()) {
        m_Animation->setScale(fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }
    else {
        m_Animation->setScale(-fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }

    if (m_Player->getHealth() <= 0) {
        m_Player->changeNextState(DEATH);
    }

}

void PSIdle::render(RenderWindow *window) {
    window->draw(*m_Animation);
}

void PSIdle::reset() {
    m_Animation->reset();
}
