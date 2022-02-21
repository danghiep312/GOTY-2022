//
// Created by hiepd on 1/28/2022.
//

#include "GSAbout.h"

GSAbout::GSAbout() {

}

GSAbout::~GSAbout() {

}

void GSAbout::exit() {

}

void GSAbout::pause() {

}

void GSAbout::resume() {

}

void GSAbout::init() {
    GameButton *button;
    //Close Button
    button = new GameButton();
    button->init("close_2");
    button->setOrigin(button->getSize() / 2.f);
    button->setSize(sf::Vector2f(50, 50));
    button->setPosition(screenWidth - screenWidth / 20, screenHeight / 8);
    button->setOnClick([]() { GSM->popState(); });
    m_ListBtn.push_back(button);


    //Tile Game
    m_Title.setString("ABOUT");
    m_Title.setFont(*DATA->getFont("ARCADE"));
    m_Title.setPosition(screenWidth / 2 - m_Title.getLocalBounds().width / 2, screenHeight / 5);

    //About
    m_About.setString("Made by Dang Hoang Hiep");
    m_About.setFont(*DATA->getFont("ARCADE"));
    m_About.setPosition(screenWidth / 2 - m_About.getLocalBounds().width / 2, screenHeight / 5 + 100);

    m_Tutorial.setString("W, A, S, D:           MOVE\n\nQ, E :                  BLOCK\n\nSPACE:              ATTACK");
    m_Tutorial.setFont(*DATA->getFont("ARCADE"));
    m_Tutorial.setPosition(screenWidth / 2 - m_About.getLocalBounds().width / 2, screenHeight / 2);

    //Background
    m_Background.setTexture(*DATA->getTexture("bg"));
}

void GSAbout::update(float deltaTime) {
    for (auto btn : m_ListBtn) {
        btn->update(deltaTime);
    }
}

void GSAbout::render(RenderWindow *window) {
    window->draw(m_Background);
    window->draw(m_Title);
    window->draw(m_About);
    window->draw(m_Tutorial);
    for (auto btn : m_ListBtn) {
        btn->render(window);
    }
}
