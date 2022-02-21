//
// Created by hiepd on 2/2/2022.
//

#include "CollisionManager.h"

void CollisionManager::addObj(Hitbox *hitbox) {
    m_ListObj.push_back(hitbox);
}

bool CollisionManager::checkCollision(Hitbox *a, Hitbox *b) {
    return a->getGlobalBounds().intersects(b->getGlobalBounds());
}

void CollisionManager::update() {
    for (auto a : m_ListObj) {
        if (!a->isAlive()) continue;
        for (auto b : m_ListObj) {
            if (!b->isAlive()) continue;

            if (a->getTag() == b->getTag()) continue;
            if (!checkCollision(a, b)) continue;

            if (a->getTag() == PLAYER && b->getTag() == ENEMY) {
                a->setAlive(false);
                b->setAlive(false);
            }
        }
    }
}

Hitbox* CollisionManager::searchPlayer() {
    for (auto it : m_ListObj) {
        if (it->getTag() == PLAYER) {
            return it;
        }
    }
    return nullptr;
}
