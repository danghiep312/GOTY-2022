//
// Created by hiepd on 1/31/2022.
//

#include "PSBlock.h"

PSBlock::PSBlock(IPlayer *player) {
    m_Player = player;
}

void PSBlock::init() {
    m_Animation = new Animation(*DATA->getTexture("Character/Block"), Vector2i (1, 1), 0.1f);
    m_Animation->scale(m_Player->getFactorScale());
}

void PSBlock::update(float deltaTime) {
    m_Animation->update(deltaTime);

    if (m_Player->getCcw()) {
        m_Animation->setScale(fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }
    else {
        m_Animation->setScale(-fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }
    m_Player->getDamageZone()->setPosition(2000.f, 2000.f);
    if (Keyboard::isKeyPressed(Keyboard::Q)) {
        m_Player->setCcw(true);
    }

    if (Keyboard::isKeyPressed(Keyboard::E)) {
        m_Player->setCcw(false);
    }

    if (Keyboard::isKeyPressed(Keyboard::Space)) {
        m_Player->changeNextState(ATTACK);
    }


    if (!Keyboard::isKeyPressed(Keyboard::Q)
        && !Keyboard::isKeyPressed(Keyboard::E)
        && !Keyboard::isKeyPressed(Keyboard::Space)) {
        m_Player->changeNextState(IDLE);
    }

    if (m_Player->getHealth() <= 0) {
        m_Player->changeNextState(DEATH);
    }

    m_Animation->setPosition(m_Player->getHitbox()->getPosition());
}

void PSBlock::render(RenderWindow *window) {
    window->draw(*m_Animation);
}

void PSBlock::reset() {
    m_Animation->reset();
}
