//
// Created by hiepd on 1/25/2022.
//

#include "GSIntro.h"

GSIntro::GSIntro() {
    m_CurrentTime = 0.f;
}

GSIntro::~GSIntro() {

}

void GSIntro::exit() {

}

void GSIntro::pause() {

}

void GSIntro::resume() {

}

void GSIntro::init() {

}

void GSIntro::update(float deltaTime) {
    m_CurrentTime += deltaTime;
    if (m_CurrentTime >= 2.f) {
        GSM->changeState(MENU);
    }
}

void GSIntro::render(RenderWindow *window) {

}
