//
// Created by hiepd on 2/17/2022.
//

#include "HUD.h"

void HUD::init() {
    m_Stop = false;
    m_GameTime = 0.f;
    m_TimeText.setFont(*DATA->getFont("ARCADE"));
    m_TimeText.setFillColor(Color::White);
    m_TimeText.setCharacterSize(40);

    m_Hp.setFont(*DATA->getFont("ARCADE"));
    m_Hp.setCharacterSize(40);
}

void HUD::update(float deltaTime) {
    if (m_Stop) return;
    m_GameTime += deltaTime;
    std::stringstream ssTime;
    ssTime << (int) m_GameTime / 60 << ":" << (int) m_GameTime % 60;
    m_TimeText.setString(ssTime.str());
    m_TimeText.setPosition(470.f, 250.f);

    std::stringstream ssHp;
    ssHp << "HP: " << (int) (PConnect->getPlayer()->getHealth() < 0 ? 0 : PConnect->getPlayer()->getHealth());
    m_Hp.setString(ssHp.str());
<<<<<<< HEAD
    m_Hp.setPosition(130.f, 250.f);
=======
    m_Hp.setPosition(200.f, 250.f);
>>>>>>> 0d36dea484631fa0514253c2c7b1c89161b60273
}

void HUD::render(RenderWindow *window) {
    window->draw(m_TimeText);
    window->draw(m_Hp);
}

float HUD::getGameTime() {
    return m_GameTime;
}

void HUD::setStop(bool stop) {
    m_Stop = stop;
}

bool HUD::getStop() {
    return m_Stop;
}
