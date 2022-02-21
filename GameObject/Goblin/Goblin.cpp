//
// Created by hiepd on 2/10/2022.
//

#include "Goblin.h"

Goblin::Goblin() {
    m_NextState = IGState::SNULL;
    m_IdleState = new GIdle(this);
    m_RunState = new GRun(this);
    m_AttackState = new GAttack(this);
    m_DeathState = new GDeath(this);
    m_CurrentState = m_IdleState;
}

Goblin::~Goblin() {
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

void Goblin::changeNextState(IGState::STATE nextState) {
    m_NextState = nextState;
}

void Goblin::init() {
    m_IdleState->init();
    m_RunState->init();
    m_AttackState->init();
    m_DeathState->init();

    m_Hitbox = new Hitbox(Vector2i(25, 25));
    m_Hitbox->setSpeed(runSpeed);
    m_Hitbox->setPosition(10000.f, 10000.f);

    m_AttackZone = new Hitbox(attackZoneSize);
    m_AttackZone->setSpeed(m_Hitbox->getSpeed());
    m_AttackZone->setPosition(m_Hitbox->getPosition());

    m_DamageZone = new Hitbox(Vector2i(50, 25));
    m_DamageZone->setSpeed(m_Hitbox->getSpeed());
    m_DamageZone->setPosition(m_Hitbox->getPosition());

    m_Health = 5;
    m_Ccw = true;
    m_Hitbox->setTag(ENEMY);
    m_Stop = true;
}

void Goblin::update(float deltaTime) {
    performStateChange();
    m_CurrentState->update(deltaTime);
}

void Goblin::render(RenderWindow *window) {
    if (m_Stop) return;
    m_CurrentState->render(window);
    window->draw(*m_Hitbox);
    window->draw(*m_DamageZone);
    window->draw(*m_AttackZone);
}

Hitbox *Goblin::getHitbox() {
    return m_Hitbox;
}

Hitbox *Goblin::getDamageZone() {
    return m_DamageZone;
}

Hitbox *Goblin::getAttackZone() {
    return m_AttackZone;
}

void Goblin::reset() {
    m_Stop = false;
    m_IdleState->reset();
    m_RunState->reset();
    m_AttackState->reset();
    m_DeathState->reset();
    m_Hitbox->setPosition(m_StartPoint);
    m_AttackZone->setPosition(m_StartPoint);
}

void Goblin::performStateChange() {
    if (m_NextState != IGState::SNULL) {
        switch (m_NextState) {
            case IGState::IDLE:
                m_CurrentState = m_IdleState;
                break;
            case IGState::RUN:
                m_CurrentState = m_RunState;
                break;
            case IGState::ATTACK:
                m_CurrentState = m_AttackState;
                break;
            case IGState::DEATH:
                m_CurrentState = m_DeathState;
                break;
            default:
                break;
        }
    }
}
