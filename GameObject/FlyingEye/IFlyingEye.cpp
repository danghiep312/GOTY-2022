//
// Created by hiepd on 2/16/2022.
//

#include "IFlyingEye.h"

void IFlyingEye::setCcw(bool ccw) {
    m_Ccw = ccw;
}

bool IFlyingEye::getCcw() {
    return m_Ccw;
}

int IFlyingEye::getHealth() {
    return m_Health;
}

void IFlyingEye::takeHit() {
    m_Health--;
}

Vector2f IFlyingEye::getFactorScale() {
    return m_FactorScale;
}

void IFlyingEye::setStartPoint(Vector2f startPoint) {
    m_StartPoint = startPoint;
}

bool IFlyingEye::isStop() {
    return m_Stop;
}

void IFlyingEye::setStop(bool mStop) {
    m_Stop = mStop;
}