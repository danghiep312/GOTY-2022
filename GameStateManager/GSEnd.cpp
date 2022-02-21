//
// Created by hiepd on 1/26/2022.
//

#include "GSEnd.h"

GSEnd::GSEnd() {

}

GSEnd::~GSEnd() {

}

void GSEnd::exit() {

}

void GSEnd::pause() {

}

void GSEnd::resume() {

}

void GSEnd::init() {
    m_OriginView.setSize(Vector2f(screenWidth, screenHeight));
    m_OriginView.setCenter(Vector2f(screenWidth / 2, screenHeight / 2));
//    //Tile Game
//    m_Title.setString("GAME OVER");
//    m_Title.setFont(*DATA->getFont("ARCADE"));
//    //m_Title.setPosition(screenWidth / 2 - 20.f, screenHeight - 70.f);
//    m_Title.setPosition(PConnect->getPlayer()->getHitbox()->getPosition());
//    m_CurrentTime = 0.f;

    ScoreManager::getInstance()->writeFile();

    //Tile Game
    m_Title.setString("END GAME");
    m_Title.setFont(*DATA->getFont("ARCADE"));
    m_Title.setPosition(screenWidth / 2 - 100, screenHeight / 5);

    //Best Score
    m_BestScore.setString("BEST SCORE: " + std::to_string(ScoreManager::getInstance()->getBestScore()));
    m_BestScore.setFont(*DATA->getFont("ARCADE"));
    m_BestScore.setPosition(screenWidth / 2 - 100, screenHeight / 2);

    //current Score
    m_CurrentScore.setString("YOUR SCORE: " + std::to_string(ScoreManager::getInstance()->getCurrentScore()));
    m_CurrentScore.setFont(*DATA->getFont("ARCADE"));
    m_CurrentScore.setPosition(screenWidth / 2 - 100, screenHeight / 2 + 50);

    //back menu
    m_BackMenu.setString("PRESS ENTER TO RETURN MENU");
    m_BackMenu.setFont(*DATA->getFont("ARCADE"));
    m_BackMenu.setPosition(screenWidth / 2 - 200, screenHeight / 2 + 150);
}

void GSEnd::update(float deltaTime) {
    if (Keyboard::isKeyPressed(Keyboard::Enter)) {
        GSM->changeState(StateTypes::MENU);
    }
}

void GSEnd::render(RenderWindow *window) {
    window->setView(m_OriginView);
    window->draw(m_Title);
    window->draw(m_BestScore);
    window->draw(m_CurrentScore);
    window->draw(m_BackMenu);
}
