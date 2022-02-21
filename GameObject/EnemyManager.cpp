//
// Created by hiepd on 2/8/2022.
//

#include "EnemyManager.h"

EnemyManager::EnemyManager() {
    m_EnemyNum = 1000;
    m_CurrentTime = 0.f;
    m_TimeSpawn = 0.5f;
}

EnemyManager::~EnemyManager() {
    for (auto it: m_ListSkeleton) {
        if (it != nullptr) {
            delete it;
        }
    }

    for (auto it: m_ListGoblin) {
        if (it != nullptr) {
            delete it;
        }
    }

    for (auto it: m_ListMushroom) {
        if (it != nullptr) {
            delete it;
        }
    }

    for (auto it: m_ListFlyingEye) {
        if (it != nullptr) {
            delete it;
        }
    }

    m_ListSkeleton.clear();
    m_ListGoblin.clear();
    m_ListMushroom.clear();
    m_ListFlyingEye.clear();
}

void EnemyManager::init(CollisionManager &collisionManager) {
    for (int i = 0; i < m_EnemyNum; i++) {
        Skeleton *skeleton = new Skeleton();
        skeleton->init();
        skeleton->getHitbox()->setAlive(false);
        m_ListSkeleton.push_back(skeleton);
    }

    for (int i = 0; i < m_EnemyNum; i++) {
        Goblin *goblin = new Goblin();
        goblin->init();
        goblin->getHitbox()->setAlive(false);
        m_ListGoblin.push_back(goblin);
    }

    for (int i = 0; i < m_EnemyNum; i++) {
        Mushroom *mushroom = new Mushroom();
        mushroom->init();
        mushroom->getHitbox()->setAlive(false);
        m_ListMushroom.push_back(mushroom);
    }

    for (int i = 0; i < m_EnemyNum; i++) {
        FlyingEye *flyingEye = new FlyingEye();
        flyingEye->init();
        flyingEye->getHitbox()->setAlive(false);
        m_ListFlyingEye.push_back(flyingEye);
    }
}

void EnemyManager::update(float deltaTime) {

    m_CurrentTime += deltaTime;
    if (m_CurrentTime > m_TimeSpawn) {
        spawnSkeleton();
        spawnGoblin();
        spawnMushroom();
        spawnFlyingEye();
        m_CurrentTime = 0.f;
    }
    for (auto it: m_ListSkeleton) {
        if (PConnect->getPlayer()->getDamageZone()->getGlobalBounds().intersects(it->getHitbox()->getGlobalBounds())) {
            it->takeHit();
        }
        it->update(deltaTime);
    }
    for (auto it: m_ListGoblin) {
        if (PConnect->getPlayer()->getDamageZone()->getGlobalBounds().intersects(it->getHitbox()->getGlobalBounds())) {
            it->takeHit();
        }
        it->update(deltaTime);
    }
    for (auto it: m_ListMushroom) {
        if (PConnect->getPlayer()->getDamageZone()->getGlobalBounds().intersects(it->getHitbox()->getGlobalBounds())) {
            it->takeHit();
        }
        it->update(deltaTime);
    }
    for (auto it: m_ListFlyingEye) {
        if (PConnect->getPlayer()->getDamageZone()->getGlobalBounds().intersects(it->getHitbox()->getGlobalBounds())) {
            it->takeHit();
        }
        it->update(deltaTime);
    }
}

void EnemyManager::render(RenderWindow *window) {

    for (auto it : m_ListMushroom) {
        if (!it->getHitbox()->isAlive()) {
            it->render(window);
        }
    }
    for (auto it : m_ListGoblin) {
        if (!it->getHitbox()->isAlive()) {
            it->render(window);
        }
    }
    for (auto it : m_ListSkeleton) {
        if (!it->getHitbox()->isAlive()) {
            it->render(window);
        }
    }
    for (auto it : m_ListFlyingEye) {
        if (!it->getHitbox()->isAlive()) {
            it->render(window);
        }
    }

    for (auto it : m_ListMushroom) {
        if (it->getHitbox()->isAlive()) {
            it->render(window);
        }
    }
    for (auto it : m_ListGoblin) {
        if (it->getHitbox()->isAlive()) {
            it->render(window);
        }
    }
    for (auto it : m_ListSkeleton) {
        if (it->getHitbox()->isAlive()) {
            it->render(window);
        }
    }
    for (auto it : m_ListFlyingEye) {
        if (it->getHitbox()->isAlive()) {
            it->render(window);
        }
    }
}

void EnemyManager::spawnSkeleton() {
    Skeleton *skeleton = nullptr;
    for (auto it: m_ListSkeleton) {
        if (!it->getHitbox()->isAlive() && it->isStop()) {
            skeleton = it;
            break;
        }
    }
    if (skeleton == nullptr) return;

    skeleton->getHitbox()->setAlive(true);
    skeleton->setStartPoint(
            Vector2f(rand() % MConnect->getMap()->getMapSize().x, rand() % MConnect->getMap()->getMapSize().y));
    skeleton->reset();
}

void EnemyManager::spawnGoblin() {
    Goblin *goblin = nullptr;
    for (auto it: m_ListGoblin) {
        if (!it->getHitbox()->isAlive() && it->isStop()) {
            goblin = it;
            break;
        }
    }
    if (goblin == nullptr) return;
    goblin->getHitbox()->setAlive(true);
    goblin->setStartPoint(
            Vector2f(rand() % MConnect->getMap()->getMapSize().x, rand() % MConnect->getMap()->getMapSize().y));
    goblin->reset();
}

void EnemyManager::spawnMushroom() {
    Mushroom *mushroom = nullptr;
    for (auto it: m_ListMushroom) {
        if (!it->getHitbox()->isAlive() && it->isStop()) {
            mushroom = it;
            break;
        }
    }
    if (mushroom == nullptr) return;

    mushroom->getHitbox()->setAlive(true);
    mushroom->setStartPoint(
            Vector2f(rand() % MConnect->getMap()->getMapSize().x, rand() % MConnect->getMap()->getMapSize().y));
    mushroom->reset();
}

void EnemyManager::spawnFlyingEye() {
    FlyingEye *flyingEye = nullptr;
    for (auto it: m_ListFlyingEye) {
        if (!it->getHitbox()->isAlive() && it->isStop()) {
            flyingEye = it;
            break;
        }
    }
    if (flyingEye == nullptr) return;

    flyingEye->getHitbox()->setAlive(true);
    flyingEye->setStartPoint(
            Vector2f(rand() % MConnect->getMap()->getMapSize().x, rand() % MConnect->getMap()->getMapSize().y));
    flyingEye->reset();
}

void EnemyManager::setTimeTotal(float timeTotal) {
    m_TimeTotal = timeTotal;
}
