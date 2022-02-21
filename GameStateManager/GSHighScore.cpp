//
// Created by hiepd on 1/28/2022.
//

#include "GSHighScore.h"

GSHighScore::GSHighScore() {

}

GSHighScore::~GSHighScore() {
    for (auto it : m_ListBtn) {
        if (it != nullptr) {
            delete it;
        }
    }
    for (auto it : m_ListScore) {
        if (it != nullptr) {
            delete it;
        }
    }
}

void GSHighScore::exit() {

}

void GSHighScore::pause() {

}

void GSHighScore::resume() {

}

void GSHighScore::init() {
    ScoreManager::getInstance()->readFile();

    GameButton* button;
    //Close Button
    button = new GameButton();
    button->init("close_2");
    button->setOrigin(button->getSize() / 2.f);
    button->setSize(sf::Vector2f(50, 50));
    button->setPosition(screenWidth - screenWidth / 20, screenHeight / 8);
    button->setOnClick([]() {GSM->popState(); });
    m_ListBtn.push_back(button);

    //Title Game
    m_Title.setString("HIGH SCORE");
    m_Title.setFont(*DATA->getFont("ARCADE"));
    m_Title.setPosition(screenWidth / 2 - m_Title.getLocalBounds().width / 2, screenHeight / 5);

    // List Score
    for (int i = 0; i < 5; i++) {
        Text* t = new Text();
        t->setString(std::to_string(i + 1) + ". " + std::to_string(ScoreManager::getInstance()->getHighScore()[i]));
        t->setFont(*DATA->getFont("ARCADE"));
        t->setPosition(screenWidth / 2 - m_Title.getLocalBounds().width / 2, screenHeight / 5 + 50 * (i + 1));
        m_ListScore.push_back(t);
    }

    //Background
    m_Background.setTexture(*DATA->getTexture("bg"));
}

void GSHighScore::update(float deltaTime) {
    for (auto btn : m_ListBtn) {
        btn->update(deltaTime);
    }
}

void GSHighScore::render(RenderWindow *window) {
    window->draw(m_Background);
    window->draw(m_Title);
    for (auto btn : m_ListBtn) {
        btn->render(window);
    }
    for (auto it : m_ListScore) {
        window->draw(*it);
    }
}
