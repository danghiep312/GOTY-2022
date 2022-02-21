//
// Created by hiepd on 1/26/2022.
//

#include "GameButton.h"

GameButton::GameButton() {
    m_IsPressing = false;
}

void GameButton::init(string name) {
    this->setTexture(DATA->getTexture("Button/" + name));
    this->setSize(Vector2f(100.f, 100.f));

}

void GameButton::update(float deltaTime) {
    if (Mouse::isButtonPressed(Mouse::Left)) {
        handleTouchEvent();
    }
}

void GameButton::render(RenderWindow *window) {
    window->draw(*this);
}

void GameButton::handleTouchEvent() {
    m_IsPressing = false;
    if (this->getGlobalBounds().contains((sf::Vector2f) sf::Mouse::getPosition(*WConnect->getWindow()))) {
        m_btnClickFunc();
        m_IsPressing = true;
    }
}

bool GameButton::isPressing() {
    return m_IsPressing;
}

void GameButton::setOnClick(void (*func)()) {
    m_btnClickFunc = func;
}
