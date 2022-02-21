//
// Created by hiepd on 1/28/2022.
//

#include "Hitbox.h"

Hitbox::Hitbox(Vector2i size) : RectangleShape((Vector2f) size) {
    this->setOrigin((Vector2f) size / 2.f);
    this->setFillColor(Color(0, 0, 0, 0));
    this->setOutlineThickness(0.f);
    this->setOutlineColor(Color::Red);
    m_Speed = Vector2f (0, 0);
    m_IsAlive = true;
}

TAG Hitbox::getTag() {
    return m_Tag;
}

void Hitbox::setTag(TAG tag) {
    m_Tag = tag;
}

bool Hitbox::isAlive() {
    return m_IsAlive;
}

void Hitbox::setAlive(bool alive) {
    m_IsAlive = alive;
}

Vector2f Hitbox::getSpeed() {
    return m_Speed;
}

void Hitbox::setSpeed(Vector2f speed) {
    m_Speed = speed;
}
