//
// Created by hiepd on 2/13/2022.
//

#include "Mushroom.h"

Mushroom::Mushroom() {
    m_NextState = IMState::SNULL;
    m_IdleState = new MIdle(this);
    m_RunState = new MRun(this);
    m_AttackState = new MAttack(this);
    m_DeathState = new MDeath(this);
    m_CurrentState = m_IdleState;
}

Mushroom::~Mushroom() {
    if (m_IdleState != nullptr) {
        delete m_IdleState;
    }
    if (m_RunState != nullptr) {
        delete m_RunState;
    }
    if (m_AttackState != nullptr) {
        delete m_AttackState;
    }
    if (m_DeathState != nullptr) {
        delete m_DeathState;
    }
    m_CurrentState = nullptr;
}

void Mushroom::changeNextState(IMState::STATE nextState) {
    m_NextState = nextState;
}

void Mushroom::init() {
    m_IdleState->init();
    m_RunState->init();
    m_AttackState->init();
    m_DeathState->init();

    m_Hitbox = new Hitbox(Vector2i(15, 25));
    m_Hitbox->setOrigin(m_Hitbox->getOrigin() + Vector2f (0.f, -10.f));
    m_Hitbox->setSpeed(runSpeed);
    m_Hitbox->setPosition(10000.f, 10000.f);

    m_AttackZone = new Hitbox(attackZoneSize);
    m_AttackZone->setSpeed(m_Hitbox->getSpeed());
    m_AttackZone->setPosition(m_Hitbox->getPosition());

    m_DamageZone = new Hitbox(Vector2i(15, 5));
    m_DamageZone->setSpeed(m_Hitbox->getSpeed());
    m_DamageZone->setPosition(m_Hitbox->getPosition());

    m_Health = 3;
    m_Ccw = true;
    m_Hitbox->setTag(ENEMY);
    m_Stop = true;
}

void Mushroom::update(float deltaTime) {
    performStateChange();
    m_CurrentState->update(deltaTime);
}

void Mushroom::render(RenderWindow *window) {
    if (m_Stop) return;
    m_CurrentState->render(window);
    window->draw(*m_Hitbox);
    window->draw(*m_DamageZone);
    window->draw(*m_AttackZone);
}

Hitbox *Mushroom::getHitbox() {
    return m_Hitbox;
}

Hitbox *Mushroom::getDamageZone() {
    return m_DamageZone;
}

Hitbox *Mushroom::getAttackZone() {
    return m_AttackZone;
}

void Mushroom::reset() {
    m_Stop = false;
    m_IdleState->reset();
    m_RunState->reset();
    m_AttackState->reset();
    m_DeathState->reset();
    m_Hitbox->setPosition(m_StartPoint);
    m_AttackZone->setPosition(m_StartPoint);
}

void Mushroom::performStateChange() {
    if (m_NextState != IMState::SNULL) {
        switch (m_NextState) {
            case IMState::IDLE:
                m_CurrentState = m_IdleState;
                break;
            case IMState::RUN:
                m_CurrentState = m_RunState;
                break;
            case IMState::ATTACK:
                m_CurrentState = m_AttackState;
                break;
            case IMState::DEATH:
                m_CurrentState = m_DeathState;
                break;
            default:
                break;
        }
    }
}
