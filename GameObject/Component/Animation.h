//
// Created by hiepd on 1/25/2022.
//

#ifndef GAME_ANIMATION_H
#define GAME_ANIMATION_H

#include "SFML/Graphics.hpp"

using namespace sf;

class Animation : public Sprite {
public:
    Animation(sf::Texture &texture, Vector2i frameNum, float frameTime);

    void calculateRectSize();

    void calculateRectUV();

    void applyRect();

    void update(float deltaTime);

    bool play(float deltaTime);

    void reset();

    void setModeEndFrame(bool stop);

    Vector2i getFrameNum();

    Vector2i getCurrentFrame();

protected:
    Vector2i m_FrameNum;

    Vector2i m_CurrentFrame;

    float m_FrameTime;
    float m_CurrentTime;

    Vector2i m_RectUV;
    Vector2i m_RectSize;
    IntRect m_Rect;

    bool m_StopAtLastFrame;
};


#endif //GAME_ANIMATION_H
