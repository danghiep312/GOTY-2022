//
// Created by hiepd on 1/28/2022.
//

#include "GSSetting.h"

GSSetting::GSSetting() {

}

GSSetting::~GSSetting() {

}

void GSSetting::exit() {

}

void GSSetting::pause() {

}

void GSSetting::resume() {

}

void GSSetting::init() {
    GameButton *button;
    //Close Button
    button = new GameButton();
    button->init("close_2");
    button->setOrigin(button->getSize() / 2.f);
    button->setSize(sf::Vector2f(50, 50));
    button->setPosition(screenWidth - screenWidth / 20, screenHeight / 8);
    button->setOnClick([]() { GSM->popState(); });
    m_ListBtn.push_back(button);
    //turn on music
    button = new GameButton();
    button->init("misic");
    button->setOrigin(button->getSize() / 2.f);
    button->setSize(sf::Vector2f(100, 100));
    button->setPosition(screenWidth / 2 + screenWidth / 4, screenHeight - screenHeight / 8);
    button->setOnClick([]() { DATA->setAllowSound(true); });
    m_ListBtn.push_back(button);

    //turn off music
    button = new GameButton();
    button->init("music_off");
    button->setOrigin(button->getSize() / 2.f);
    button->setSize(sf::Vector2f(100, 100));
    button->setPosition(screenWidth / 2 - screenWidth / 4, screenHeight - screenHeight / 8);
    button->setOnClick([]() { DATA->setAllowSound(false); });
    m_ListBtn.push_back(button);


    //Tile Game
    m_Title.setString("SETTINGS");
    m_Title.setFont(*DATA->getFont("ARCADE"));
    m_Title.setPosition(screenWidth / 2 - m_Title.getLocalBounds().width / 2, screenHeight / 5);

    //Background
    m_Background.setTexture(*DATA->getTexture("bg"));
}

void GSSetting::update(float deltaTime) {
    for (auto btn: m_ListBtn) {
        btn->update(deltaTime);
    }
}

void GSSetting::render(RenderWindow *window) {
    window->draw(m_Background);
    window->draw(m_Title);
    for (auto btn: m_ListBtn) {
        btn->render(window);
    }
}
