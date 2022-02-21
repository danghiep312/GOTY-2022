//
// Created by hiepd on 1/26/2022.
//

#include "GSPlay.h"

GSPlay::GSPlay() {

}

GSPlay::~GSPlay() {
    if (m_Player != nullptr) {
        delete m_Player;
    }
    if (m_MapManager != nullptr) {
        delete m_MapManager;
    }
}

void GSPlay::exit() {

}

void GSPlay::pause() {

}

void GSPlay::resume() {

}

void GSPlay::init() {
    ScoreManager::getInstance()->readFile();

    m_Hud.init();

    m_Player = new Player();
    m_MapManager = new MapManager();
    printf ("Play game");
    PConnect->setPlayer(m_Player);
    MConnect->setMapConnector(m_MapManager);

    m_MapManager->init();
    m_Player->init();
    m_EnemyManager.init(m_CollisionManager);

    m_CollisionManager.addObj(m_Player->getHitbox());
    m_TimePause = 0.f;

    m_MainView.setSize(Vector2f(800.f, 500.f));
    m_HudView.setSize(Vector2f(800.f, 500.f));
}

void GSPlay::update(float deltaTime) {

    m_MainView.setCenter(m_Player->getHitbox()->getPosition());
    m_Player->update(deltaTime);
    m_Hud.update(deltaTime);
    m_EnemyManager.setTimeTotal(m_Hud.getGameTime());

    //cout << m_Player->getHealth() << endl;

    if (m_Player->getHitbox()->isAlive()) {
        m_EnemyManager.update(deltaTime);
    }
    else {
        m_Hud.setStop(true);
        int s = (int) m_Hud.getGameTime();
        //cout << s << endl;
        ScoreManager::getInstance()->setCurrentScore(s);

        m_TimePause += deltaTime;
        if (m_TimePause >= 3.f) {
            ScoreManager::getInstance()->updateHighScore();
            GSM->changeState(StateTypes::END);
        }
    }
}

void GSPlay::render(RenderWindow *window) {
    m_MapManager->render(window);
    m_EnemyManager.render(window);
    window->setView(m_HudView);
    m_Hud.render(window);
    window->setView(m_MainView);

    m_Player->render(window);
}
