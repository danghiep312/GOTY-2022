//
// Created by hiepd on 2/2/2022.
//

#include "Skeleton.h"


void Skeleton::init() {
    m_IdleState->init();
    m_RunState->init();
    m_AttackState->init();
    m_DeathState->init();

    m_Hitbox = new Hitbox(Vector2i(25, 50));
    m_Hitbox->setSpeed(runSpeed);
    m_Hitbox->setPosition(1000.f, 1000.f);

    m_AttackZone = new Hitbox(attackZoneSize);
    m_AttackZone->setSpeed(m_Hitbox->getSpeed());
    m_AttackZone->setPosition(m_Hitbox->getPosition());

    m_DamageZone = new Hitbox(Vector2i(30, 20));
    m_DamageZone->setOrigin(0, 0);
    m_DamageZone->setSpeed(m_Hitbox->getSpeed());
    m_DamageZone->setPosition(m_Hitbox->getPosition() + Vector2f(m_Hitbox->getSize().x / 2, - m_DamageZone->getSize().y / 2));

    m_Health = 5;
    m_Ccw = true;
    m_Hitbox->setTag(ENEMY);
    m_Stop = true;
}

Skeleton::Skeleton() {
    m_NextState = ISState::SNULL;
    m_IdleState = new SIdle(this);
    m_RunState = new SRun(this);
    m_AttackState = new SAttack(this);
    m_DeathState = new SDeath(this);
    m_CurrentState = m_IdleState;
}

Skeleton::~Skeleton() {
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

void Skeleton::changeNextState(ISState::STATE nextState) {
    m_NextState = nextState;
}

void Skeleton::update(float deltaTime) {
    performStateChange();
    m_CurrentState->update(deltaTime);

}

void Skeleton::render(RenderWindow *window) {
    if (m_Stop) return;
    m_CurrentState->render(window);
    window->draw(*m_Hitbox);
    window->draw(*m_DamageZone);
    window->draw(*m_AttackZone);
}

Hitbox *Skeleton::getHitbox() {
    return m_Hitbox;
}

Hitbox *Skeleton::getDamageZone() {
    return m_DamageZone;
}

Hitbox *Skeleton::getAttackZone() {
    return m_AttackZone;
}

void Skeleton::performStateChange() {
    if (m_NextState != ISState::SNULL) {
        switch (m_NextState) {
            case ISState::IDLE:
                m_CurrentState = m_IdleState;
                break;
            case ISState::RUN:
                m_CurrentState = m_RunState;
                break;
            case ISState::ATTACK:
                m_CurrentState = m_AttackState;
                break;
            case ISState::DEATH:
                m_CurrentState = m_DeathState;
                break;
            default:
                break;
        }
    }
}

void Skeleton::reset() {
    m_Stop = false;
    m_IdleState->reset();
    m_RunState->reset();
    m_AttackState->reset();
    m_DeathState->reset();
    m_Hitbox->setPosition(m_StartPoint);
    m_AttackZone->setPosition(m_StartPoint);
}
