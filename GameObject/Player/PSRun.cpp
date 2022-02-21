//
// Created by hiepd on 1/30/2022.
//

#include "PSRun.h"

PSRun::PSRun(IPlayer *player) {
    m_Player = player;
}

void PSRun::init() {
    m_Animation = new Animation(*DATA->getTexture("Character/Run"), Vector2i (4, 1), 0.2f);
    m_Animation->setScale(m_Player->getFactorScale());
}

void PSRun::update(float deltaTime) {
    m_Animation->update(deltaTime);
    if (Keyboard::isKeyPressed(Keyboard::W)) {

        m_Player->getHitbox()->move(0, -m_Player->getHitbox()->getSpeed().y * deltaTime);
    }
    if (Keyboard::isKeyPressed(Keyboard::S)) {

        m_Player->getHitbox()->move(0, m_Player->getHitbox()->getSpeed().y * deltaTime);
    }
    if (Keyboard::isKeyPressed(Keyboard::A)) {

        m_Player->setCcw(true);
        m_Player->getHitbox()->move(-m_Player->getHitbox()->getSpeed().x * deltaTime, 0);
    }
    if (Keyboard::isKeyPressed(Keyboard::D)) {

        m_Player->setCcw(false);
        m_Player->getHitbox()->move(m_Player->getHitbox()->getSpeed().x * deltaTime, 0);
    }

    //keep player in area
    if (m_Player->getHitbox()->getPosition().x > MConnect->getMap()->getMapSize().x) {
        m_Player->getHitbox()->setPosition(MConnect->getMap()->getMapSize().x, m_Player->getHitbox()->getPosition().y);
    }
    if (m_Player->getHitbox()->getPosition().x < 0) {
        m_Player->getHitbox()->setPosition(0, m_Player->getHitbox()->getPosition().y);
    }
    if (m_Player->getHitbox()->getPosition().y > MConnect->getMap()->getMapSize().y) {
        m_Player->getHitbox()->setPosition(m_Player->getHitbox()->getPosition().x, MConnect->getMap()->getMapSize().y);
    }
    if (m_Player->getHitbox()->getPosition().y < 0) {
        m_Player->getHitbox()->setPosition(m_Player->getHitbox()->getPosition().x, 0);
    }

    if (m_Player->getCcw()) {
        m_Animation->setScale(fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }
    else {
        m_Animation->setScale(-fabs(m_Animation->getScale().x), m_Animation->getScale().y);
    }

    m_Player->getDamageZone()->setPosition(2000.f, 2000.f);

    if (Keyboard::isKeyPressed(Keyboard::Space)) {
        m_Player->changeNextState(ATTACK);
    }

    if (Keyboard::isKeyPressed(Keyboard::Q)) {
        m_Player->setCcw(true);
        m_Player->changeNextState(BLOCK);
    }

    if (Keyboard::isKeyPressed(Keyboard::E)) {
        m_Player->setCcw(false);
        m_Player->changeNextState(BLOCK);
    }

    if (!Keyboard::isKeyPressed(Keyboard::A)
        && !Keyboard::isKeyPressed(Keyboard::S)
        && !Keyboard::isKeyPressed(Keyboard::W)
        && !Keyboard::isKeyPressed(Keyboard::D)
        && !Keyboard::isKeyPressed(Keyboard::Q)
        && !Keyboard::isKeyPressed(Keyboard::W)
        && !Keyboard::isKeyPressed(Keyboard::Space)) {
        m_Player->changeNextState(IDLE);
    }

    if (m_Player->getHealth() <= 0) {
        m_Player->changeNextState(DEATH);
    }

    m_Animation->setPosition(m_Player->getHitbox()->getPosition());
}

void PSRun::render(RenderWindow *window) {

    window->draw(*m_Animation);
}

void PSRun::reset() {
    m_Animation->reset();
}
