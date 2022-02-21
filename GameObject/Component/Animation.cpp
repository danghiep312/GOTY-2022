//
// Created by hiepd on 1/25/2022.
//

#include "Animation.h"

Animation::Animation(Texture &texture, Vector2i frameNum, float frameTime) {
    this->setTexture(texture);
    m_FrameNum = frameNum;
    m_FrameTime = frameTime;
    m_CurrentTime = 0.f;
    m_CurrentFrame = Vector2i (0, 0);
    calculateRectSize();
    calculateRectUV();
    applyRect();
    this->setOrigin((sf::Vector2f)m_RectSize / 2.f);
    m_StopAtLastFrame = false;
}

void Animation::calculateRectSize() {
    m_RectSize = Vector2i (this->getTexture()->getSize().x / m_FrameNum.x, this->getTexture()->getSize().y / m_FrameNum.y);
}

void Animation::calculateRectUV() {
    m_RectUV = Vector2i (m_CurrentFrame.x * m_RectSize.x, m_CurrentFrame.y * m_RectSize.y);
}

void Animation::applyRect() {
    m_Rect = IntRect (m_RectUV, m_RectSize);
    this->setTextureRect(m_Rect);
}

void Animation::update(float deltaTime) {
    if ((m_CurrentFrame.x == m_FrameNum.x - 1) && m_StopAtLastFrame) {
        return;
    }
    m_CurrentTime += deltaTime;
    if (m_CurrentTime >= m_FrameTime) {
        m_CurrentFrame.x++;
        if (m_CurrentFrame.x == m_FrameNum.x) {
            m_CurrentFrame.x = 0;
        }
        calculateRectUV();
        applyRect();
        m_CurrentTime -= m_FrameTime;
    }
}

bool Animation::play(float deltaTime) {
    m_CurrentTime += deltaTime;
    if (m_CurrentTime >= m_FrameTime) {
        m_CurrentFrame.x++;
        if (m_CurrentFrame.x == m_FrameNum.x) {
            m_CurrentFrame.x = 0;
            return true;
        }
        calculateRectUV();
        applyRect();
        m_CurrentTime -= m_FrameTime;
    }
    return false;
}

void Animation::reset() {
    m_CurrentFrame.x = 0;
    m_CurrentTime = 0.f;
}

void Animation::setModeEndFrame(bool stop) {
    m_StopAtLastFrame = stop;
}

Vector2i Animation::getFrameNum() {
    return m_FrameNum;
}

Vector2i Animation::getCurrentFrame() {
    return m_CurrentFrame;
}
