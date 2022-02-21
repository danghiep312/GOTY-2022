//
// Created by hiepd on 1/26/2022.
//

#include "GSMenu.h"

GSMenu::GSMenu() {

}

GSMenu::~GSMenu() {

}

void GSMenu::exit() {

}

void GSMenu::pause() {

}

void GSMenu::resume() {

}

void GSMenu::init() {
    GameButton *button;
    //Play Button
    button = new GameButton();
    button->init("play");
    button->setOnClick([]() { GSM->changeState(StateTypes::PLAY); });
    button->setPosition(screenWidth / 2, screenHeight / 2 + screenHeight / 10);
    button->setSize(sf::Vector2f(150, 150));
    button->setOrigin(button->getSize() / 2.f);
    m_ListBtn.push_back(button);

    //Exit Button
    button = new GameButton();
    button->init("close");
    button->setOrigin(button->getSize() / 2.f);
    button->setPosition(screenWidth / 2 + screenWidth / 4, screenHeight - screenHeight / 8);
    button->setOnClick([]() { printf ("close"); WConnect->getWindow()->close(); });
    m_ListBtn.push_back(button);

    //Setting Button
    button = new GameButton();
    button->init("settings");
    button->setOrigin(button->getSize() / 2.f);
    button->setPosition(screenWidth / 2 - screenWidth / 4, screenHeight - screenHeight / 8);
    button->setOnClick([]() { GSM->changeState(StateTypes::SETTING); });
    m_ListBtn.push_back(button);

    //About Button
    button = new GameButton();
    button->init("about");
    button->setOrigin(button->getSize() / 2.f);
    button->setPosition(screenWidth / 2 + screenWidth / 12, screenHeight - screenHeight / 8);
    button->setOnClick([]() { GSM->changeState(StateTypes::ABOUT); });
    m_ListBtn.push_back(button);

    //HighScore Button
    button = new GameButton();
    button->init("prize");
    button->setOrigin(button->getSize() / 2.f);
    button->setPosition(screenWidth / 2 - screenWidth / 12, screenHeight - screenHeight / 8);
    button->setOnClick([]() { GSM->changeState(StateTypes::HIGHSCORE); });
    m_ListBtn.push_back(button);

    //Background
    m_Background.setTexture(*DATA->getTexture("bg"));

    //Game title
    m_GameTitle.setString("GOTY SURVIVORS");
    m_GameTitle.setFont(*DATA->getFont("RETRO"));
    //m_GameTitle.setCharacterSize(100);
    m_GameTitle.setPosition(screenWidth / 2 - m_GameTitle.getLocalBounds().width / 2, screenHeight / 5);
}

void GSMenu::update(float deltaTime) {
    for (auto btn : m_ListBtn) {
        btn->update(deltaTime);
    }
}

void GSMenu::render(RenderWindow *window) {
    window->draw(m_Background);
    window->draw(m_GameTitle);
    for (auto btn : m_ListBtn) {
        btn->render(window);
    }
}


