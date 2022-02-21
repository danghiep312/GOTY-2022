//
// Created by hiepd on 2/16/2022.
//

#include "FlyingEye.h"

FlyingEye::FlyingEye() {
    m_NextState = IFState::SNULL;
    m_IdleState = new FIdle(this);
    m_RunState = new FRun(this);
    m_AttackState = new FAttack(this);
    m_DeathState = new FDeath(this);
    m_CurrentState = m_IdleState;
}

FlyingEye::~FlyingEye() {
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

void FlyingEye::changeNextState(IFState::STATE nextState) {
    m_NextState = nextState;
}

void FlyingEye::init() {
    m_IdleState->init();
    m_RunState->init();
    m_AttackState->init();
    m_DeathState->init();

    m_Hitbox = new Hitbox(Vector2i(15, 15));
    m_Hitbox->setSpeed(Vector2f (100.f, 100.f));
    m_Hitbox->setPosition(10000.f, 10000.f);

    m_AttackZone = new Hitbox(attackZoneSize);
    m_AttackZone->setSpeed(m_Hitbox->getSpeed());
    m_AttackZone->setPosition(m_Hitbox->getPosition());

    m_DamageZone = new Hitbox(Vector2i(10, 10));

    m_DamageZone->setSpeed(m_Hitbox->getSpeed());
    m_DamageZone->setPosition(m_Hitbox->getPosition());

    m_Health = 1;
    m_Ccw = true;
    m_Hitbox->setTag(ENEMY);
    m_Stop = true;
}

void FlyingEye::update(float deltaTime) {
    performStateChange();
    m_CurrentState->update(deltaTime);
}

void FlyingEye::render(RenderWindow *window) {
    if (m_Stop) return;
    m_CurrentState->render(window);
    window->draw(*m_Hitbox);
    window->draw(*m_DamageZone);
    window->draw(*m_AttackZone);
}

Hitbox *FlyingEye::getHitbox() {
    return m_Hitbox;
}

Hitbox *FlyingEye::getDamageZone() {
    return m_DamageZone;
}

Hitbox *FlyingEye::getAttackZone() {
    return m_AttackZone;
}

void FlyingEye::reset() {
    m_Stop = false;
    m_IdleState->reset();
    m_RunState->reset();
    m_AttackState->reset();
    m_DeathState->reset();
    m_Hitbox->setPosition(m_StartPoint);
    m_AttackZone->setPosition(m_StartPoint);
}

void FlyingEye::performStateChange() {
    if (m_NextState != IFState::SNULL) {
        switch (m_NextState) {
            case IFState::IDLE:
                m_CurrentState = m_IdleState;
                break;
            case IFState::RUN:
                m_CurrentState = m_RunState;
                break;
            case IFState::ATTACK:
                m_CurrentState = m_AttackState;
                break;
            case IFState::DEATH:
                m_CurrentState = m_DeathState;
                break;
            default:
                break;
        }
    }
}