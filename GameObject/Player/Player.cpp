//
// Created by hiepd on 1/28/2022.
//

#include "Player.h"

Player::Player() {
    m_NextState = IPState::SNULL;
    m_IdleState = new PSIdle(this);
    m_RunState = new PSRun(this);
    m_AttackState = new PSAttack(this);
    m_BlockState = new PSBlock(this);
    m_DeathState = new PSDeath(this);
    m_CurrentState = m_IdleState;

}

Player::~Player() {
    if (m_IdleState != nullptr) {
        delete m_IdleState;
    }
    if (m_RunState != nullptr) {
        delete m_RunState;
    }
    if (m_AttackState != nullptr) {
        delete m_AttackState;
    }
    if (m_BlockState != nullptr) {
        delete m_BlockState;
    }
    if (m_DeathState != nullptr) {
        delete m_DeathState;
    }
    m_CurrentState = nullptr;
}

void Player::changeNextState(IPState::STATE nextState) {
    m_NextState = nextState;
}

void Player::init() {
    m_Health = 5;
    m_Ccw = true;
    m_FactorScale = Vector2f(2.f, 2.f);

    m_IdleState->init();
    m_RunState->init();
    m_AttackState->init();
    m_BlockState->init();
    m_DeathState->init();

    m_Hitbox = new Hitbox(Vector2i(20.f, 20.f));
    m_Hitbox->setPosition(MConnect->getMap()->getCenter());
    m_Hitbox->setSpeed(Vector2f(200.f, 200.f));
    m_Hitbox->setTag(PLAYER);

    m_DamageZone = new Hitbox(Vector2i(40.f, 40.f));
    m_DamageZone->setPosition(Vector2f(m_Hitbox->getPosition().x + 10.f, m_Hitbox->getPosition().y + 10.f));
    m_DamageZone->setSpeed(m_Hitbox->getSpeed());

}

void Player::update(float deltaTime) {
    performStateChange();
    m_CurrentState->update(deltaTime);
}

void Player::render(RenderWindow *window) {
    m_CurrentState->render(window);
    window->draw(*m_Hitbox);
    window->draw(*m_DamageZone);
}

void Player::performStateChange() {
    if (m_NextState != IPState::SNULL) {
        switch (m_NextState) {
            case IPState::IDLE:
                m_CurrentState = m_IdleState;
                break;
            case IPState::RUN:
                m_CurrentState = m_RunState;
                break;
            case IPState::ATTACK:
                m_CurrentState = m_AttackState;
                break;
            case IPState::BLOCK:
                m_CurrentState = m_BlockState;
                break;
            case IPState::DEATH:
                m_CurrentState = m_DeathState;
                break;
            default:
                break;
        }
        m_NextState = IPState::SNULL;

    }
}

Hitbox *Player::getHitbox() {
    return m_Hitbox;
}

Hitbox *Player::getDamageZone() {
    return m_DamageZone;
}

bool Player::isBlocking() {
    if (m_CurrentState == m_BlockState) {
        return true;
    }
    return false;
}